#!./perl

# This tests (?[...]).  XXX These are just basic tests, as full ones would be
# best done with an infrastructure change to allow getting out the inversion
# list of the constructed set and then comparing it character by character
# with the expected result.

BEGIN {
    chdir 't' if -d 't';
    @INC = ('../lib','.','../ext/re');
    require './test.pl';
    require './charset_tools.pl';
    require './loc_tools.pl';
    skip_all_without_unicode_tables();
}

use strict;
use warnings;

$| = 1;

use utf8;
no warnings 'experimental::regex_sets';

like("a", qr/(?[ [a]      # This is a comment
                    ])/, 'Can ignore a comment');
like("a", qr/(?[ [a]      # [[:notaclass:]]
                    ])/, 'A comment isn\'t parsed');
unlike(uni_to_native("\x85"), qr/(?[ \t ])/, 'NEL is white space');
unlike(uni_to_native("\x85"), qr/(?[ [\t] ])/, '... including within nested []');
like(uni_to_native("\x85"), qr/(?[ \t + \ ])/, 'can escape NEL to match');
like(uni_to_native("\x85"), qr/(?[ [\] ])/, '... including within nested []');
like("\t", qr/(?[ \t + \ ])/, 'can do basic union');
like("\cK", qr/(?[ \s ])/, '\s matches \cK');
unlike("\cK", qr/(?[ \s - \cK ])/, 'can do basic subtraction');
like(" ", qr/(?[ \s - \cK ])/, 'can do basic subtraction');
like(":", qr/(?[ [:] ])/, '[:] is not a posix class');
unlike("\t", qr/(?[ ! \t ])/, 'can do basic complement');
like("\t", qr/(?[ ! [ ^ \t ] ])/, 'can do basic complement');
unlike("\r", qr/(?[ \t ])/, '\r doesn\'t match \t ');
like("\r", qr/(?[ ! \t ])/, 'can do basic complement');
like("0", qr/(?[ [:word:] & [:digit:] ])/, 'can do basic intersection');
unlike("A", qr/(?[ [:word:] & [:digit:] ])/, 'can do basic intersection');
like("0", qr/(?[[:word:]&[:digit:]])/, 'spaces around internal [] aren\'t required');

like("a", qr/(?[ [a] | [b] ])/, '| means union');
like("b", qr/(?[ [a] | [b] ])/, '| means union');
unlike("c", qr/(?[ [a] | [b] ])/, '| means union');

like("a", qr/(?[ [ab] ^ [bc] ])/, 'basic symmetric difference works');
unlike("b", qr/(?[ [ab] ^ [bc] ])/, 'basic symmetric difference works');
like("c", qr/(?[ [ab] ^ [bc] ])/, 'basic symmetric difference works');

like("2", qr/(?[ ( ( \pN & ( [a] + [2] ) ) ) ])/, 'Nesting parens and grouping');
unlike("a", qr/(?[ ( ( \pN & ( [a] + [2] ) ) ) ])/, 'Nesting parens and grouping');

unlike("\x{17f}", qr/(?[ [k] + \p{Blk=ASCII} ])/i, '/i doesn\'t affect \p{}');
like("\N{KELVIN SIGN}", qr/(?[ [k] + \p{Blk=ASCII} ])/i, '/i does affect literals');

my $thai_or_lao = qr/(?[ \p{Thai} + \p{Lao} ])/;
my $thai_or_lao_digit = qr/(?[ \p{Digit} & $thai_or_lao ])/;
like("\N{THAI DIGIT ZERO}", $thai_or_lao_digit, 'embedded qr/(?[ ])/ works');
unlike(chr(ord("\N{THAI DIGIT ZERO}") - 1), $thai_or_lao_digit, 'embedded qr/(?[ ])/ works');
like("\N{THAI DIGIT NINE}", $thai_or_lao_digit, 'embedded qr/(?[ ])/ works');
unlike(chr(ord("\N{THAI DIGIT NINE}") + 1), $thai_or_lao_digit, 'embedded qr/(?[ ])/ works');
like("\N{LAO DIGIT ZERO}", $thai_or_lao_digit, 'embedded qr/(?[ ])/ works');
unlike(chr(ord("\N{LAO DIGIT ZERO}") - 1), $thai_or_lao_digit, 'embedded qr/(?[ ])/ works');
like("\N{LAO DIGIT NINE}", $thai_or_lao_digit, 'embedded qr/(?[ ])/ works');
unlike(chr(ord("\N{LAO DIGIT NINE}") + 1), $thai_or_lao_digit, 'embedded qr/(?[ ])/ works');

my $ascii_word = qr/(?[ \w ])/a;
my $ascii_digits_plus_all_of_arabic = qr/(?[ \p{Arabic} + \p{Digit} & $ascii_word ])/;
like("9", $ascii_digits_plus_all_of_arabic, "/a, then interpolating and intersection works for ASCII in the set");
unlike("A", $ascii_digits_plus_all_of_arabic, "/a, then interpolating and intersection works for ASCII not in the set");
unlike("\N{BENGALI DIGIT ZERO}", $ascii_digits_plus_all_of_arabic, "/a, then interpolating and intersection works for non-ASCII not in either set");
unlike("\N{BENGALI LETTER A}", $ascii_digits_plus_all_of_arabic, "/a, then interpolating and intersection works for non-ASCII in one set");
like("\N{ARABIC LETTER HAMZA}", $ascii_digits_plus_all_of_arabic, "intersection has higher precedence than union");
like("\N{EXTENDED ARABIC-INDIC DIGIT ZERO}", $ascii_digits_plus_all_of_arabic, "intersection has higher precedence than union");

like("\r", qr/(?[ \p{lb=cr} ])/, '\r matches \p{lb=cr}');
unlike("\r", qr/(?[ ! \p{lb=cr} ])/, '\r doesnt match ! \p{lb=cr}');
like("\r", qr/(?[ ! ! \p{lb=cr} ])/, 'Two ! ! are the original');
unlike("\r", qr/(?[ ! ! ! \p{lb=cr} ])/, 'Three ! ! ! are the complement');
# left associatve

my $kelvin = qr/(?[ \N{KELVIN SIGN} ])/;
my $fold = qr/(?[ $kelvin ])/i;
like("\N{KELVIN SIGN}", $kelvin, '"\N{KELVIN SIGN}" matches compiled qr/(?[ \N{KELVIN SIGN} ])/');
unlike("K", $fold, "/i on outer (?[ ]) doesn't leak to interpolated one");
unlike("k", $fold, "/i on outer (?[ ]) doesn't leak to interpolated one");

my $kelvin_fold = qr/(?[ \N{KELVIN SIGN} ])/i;
my $still_fold = qr/(?[ $kelvin_fold ])/;
like("K", $still_fold, "/i on interpolated (?[ ]) is retained in outer without /i");
like("k", $still_fold, "/i on interpolated (?[ ]) is retained in outer without /i");

eval 'my $x = qr/(?[ [a] ])/; qr/(?[ $x ])/';
is($@, "", 'qr/(?[ [a] ])/ can be interpolated');

if (! is_miniperl() && locales_enabled('LC_CTYPE')) {
    my $utf8_locale = find_utf8_ctype_locale;
    SKIP: {
        skip("No utf8 locale available on this platform", 8) unless $utf8_locale;

        setlocale(&POSIX::LC_ALL, "C");
        use locale;

        $kelvin_fold = qr/(?[ \N{KELVIN SIGN} ])/i;
        my $single_char_class = qr/(?[ \: ])/;

        setlocale(&POSIX::LC_ALL, $utf8_locale);

        like("\N{KELVIN SIGN}", $kelvin_fold,
             '(?[ \N{KELVIN SIGN} ]) matches itself under /i in UTF8-locale');
        like("K", $kelvin_fold,
                '(?[ \N{KELVIN SIGN} ]) matches "K" under /i in UTF8-locale');
        like("k", $kelvin_fold,
                '(?[ \N{KELVIN SIGN} ]) matches "k" under /i in UTF8-locale');
        like(":", $single_char_class,
             '(?[ : ]) matches itself in UTF8-locale (a single character class)');

        setlocale(&POSIX::LC_ALL, "C");

        # These should generate warnings (the above 4 shouldn't), but like()
        # suppresses them, so the warnings tests are in t/lib/warnings/regexec
        like("\N{KELVIN SIGN}", $kelvin_fold,
             '(?[ \N{KELVIN SIGN} ]) matches itself under /i in C locale');
        like("K", $kelvin_fold,
                '(?[ \N{KELVIN SIGN} ]) matches "K" under /i in C locale');
        like("k", $kelvin_fold,
                '(?[ \N{KELVIN SIGN} ]) matches "k" under /i in C locale');
        like(":", $single_char_class,
             '(?[ : ]) matches itself in C locale (a single character class)');
    }
}


done_testing();

1;
