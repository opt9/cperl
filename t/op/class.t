#!./perl
# mpb -Dx t/op/class.t 2>&1 | grep -A1 Foo::
BEGIN {
    #chdir 't' if -d 't';
    #require './test.pl';
}
local($\, $", $,) = (undef, ' ', '');
print "1..8\n";
my $test = 1;

class Foo {
  # no has syntax yet
  #has $.a = 0;
  my $a = 0;
  method a($v?)              { defined $v ? $a = $v : $a }

  method meth1               { print "ok $test\n"; $test++; $self->a + 1 }
  multi method mul1 (Int $a) { print "ok $test\n"; $test++; $self->a * $a }
  # no multi decl and dispatch yet
  #multi method mul1 (Num $a) { $!a * $a; $test\n"; $test++ }
  #multi method mul1 (Str $a) { $!a . $a; $test\n"; $test++ }

  sub sub1 ($b)              { print "ok $test\n"; $test++; Foo->a - $b }
}

my $c=new Foo;
$c->meth1;
$c->mul1(0);
Foo::sub1(1);
eval "Foo->sub1(1);";      # class sub as method should error
print $@ ? "not ":"", "ok $test\n"; $test++;
eval "Foo::meth1('Foo');"; # class method as sub should error also
print $@ ? "not ":"", "ok $test\n"; $test++;

# allow class as methodname (B), deal with reserved names: method, class, multi
package Baz;
sub class { print "ok $test\n"; $test++ }
package main;
sub Bar::class { print "ok $test\n"; $test++ }
Bar::class();
Baz->class();
Bar->class();