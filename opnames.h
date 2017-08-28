/* ex: set ro ft=c: -*- mode: c; buffer-read-only: t -*-
 *
 *    opnames.h
 *
 *    Copyright (C) 1999, 2000, 2001, 2002, 2003, 2004, 2005, 2006, 2007,
 *    2008 by Larry Wall and others
 *
 *    You may distribute under the terms of either the GNU General Public
 *    License or the Artistic License, as specified in the README file.
 *
 * !!!!!!!   DO NOT EDIT THIS FILE   !!!!!!!
 * This file is built by regen/opcode.pl from its data.
 * Any changes made here will be lost!
 */

typedef enum opcode {
	OP_NULL		 = 0,
	OP_STUB		 = 1,
	OP_SCALAR	 = 2,
	OP_PUSHMARK	 = 3,
	OP_WANTARRAY	 = 4,
	OP_CONST	 = 5,
	OP_GVSV		 = 6,
	OP_GV		 = 7,
	OP_GELEM	 = 8,
	OP_PADSV	 = 9,
	OP_PADAV	 = 10,
	OP_PADHV	 = 11,
	OP_PADANY	 = 12,
	OP_SASSIGN	 = 13,
	OP_AASSIGN	 = 14,
	OP_OELEM	 = 15,
	OP_OELEMFAST	 = 16,
	OP_CHOP		 = 17,
	OP_SCHOP	 = 18,
	OP_CHOMP	 = 19,
	OP_SCHOMP	 = 20,
	OP_DEFINED	 = 21,
	OP_UNDEF	 = 22,
	OP_STUDY	 = 23,
	OP_POS		 = 24,
	OP_PREINC	 = 25,
	OP_I_PREINC	 = 26,
	OP_PREDEC	 = 27,
	OP_I_PREDEC	 = 28,
	OP_POSTINC	 = 29,
	OP_I_POSTINC	 = 30,
	OP_POSTDEC	 = 31,
	OP_I_POSTDEC	 = 32,
	OP_MULTIPLY	 = 33,
	OP_I_MULTIPLY	 = 34,
	OP_U_MULTIPLY	 = 35,
	OP_DIVIDE	 = 36,
	OP_I_DIVIDE	 = 37,
	OP_MODULO	 = 38,
	OP_I_MODULO	 = 39,
	OP_REPEAT	 = 40,
	OP_ADD		 = 41,
	OP_I_ADD	 = 42,
	OP_U_ADD	 = 43,
	OP_SUBTRACT	 = 44,
	OP_I_SUBTRACT	 = 45,
	OP_U_SUBTRACT	 = 46,
	OP_CONCAT	 = 47,
	OP_MULTICONCAT	 = 48,
	OP_STRINGIFY	 = 49,
	OP_POW		 = 50,
	OP_I_POW	 = 51,
	OP_LEFT_SHIFT	 = 52,
	OP_RIGHT_SHIFT	 = 53,
	OP_LT		 = 54,
	OP_I_LT		 = 55,
	OP_GT		 = 56,
	OP_I_GT		 = 57,
	OP_LE		 = 58,
	OP_I_LE		 = 59,
	OP_GE		 = 60,
	OP_I_GE		 = 61,
	OP_EQ		 = 62,
	OP_I_EQ		 = 63,
	OP_NE		 = 64,
	OP_I_NE		 = 65,
	OP_CMP		 = 66,
	OP_I_CMP	 = 67,
	OP_S_LT		 = 68,
	OP_S_GT		 = 69,
	OP_S_LE		 = 70,
	OP_S_GE		 = 71,
	OP_S_EQ		 = 72,
	OP_S_NE		 = 73,
	OP_S_CMP	 = 74,
	OP_BIT_AND	 = 75,
	OP_BIT_XOR	 = 76,
	OP_BIT_OR	 = 77,
	OP_I_BIT_AND	 = 78,
	OP_I_BIT_XOR	 = 79,
	OP_I_BIT_OR	 = 80,
	OP_S_BIT_AND	 = 81,
	OP_S_BIT_XOR	 = 82,
	OP_S_BIT_OR	 = 83,
	OP_NEGATE	 = 84,
	OP_I_NEGATE	 = 85,
	OP_NOT		 = 86,
	OP_COMPLEMENT	 = 87,
	OP_I_COMPLEMENT	 = 88,
	OP_S_COMPLEMENT	 = 89,
	OP_SMARTMATCH	 = 90,
	OP_ATAN2	 = 91,
	OP_SIN		 = 92,
	OP_COS		 = 93,
	OP_RAND		 = 94,
	OP_SRAND	 = 95,
	OP_EXP		 = 96,
	OP_LOG		 = 97,
	OP_SQRT		 = 98,
	OP_INT		 = 99,
	OP_HEX		 = 100,
	OP_OCT		 = 101,
	OP_ABS		 = 102,
	OP_RV2GV	 = 103,
	OP_RV2SV	 = 104,
	OP_AV2ARYLEN	 = 105,
	OP_RV2CV	 = 106,
	OP_ANONCODE	 = 107,
	OP_PROTOTYPE	 = 108,
	OP_REFGEN	 = 109,
	OP_SREFGEN	 = 110,
	OP_REF		 = 111,
	OP_BLESS	 = 112,
	OP_BACKTICK	 = 113,
	OP_GLOB		 = 114,
	OP_READLINE	 = 115,
	OP_RCATLINE	 = 116,
	OP_REGCMAYBE	 = 117,
	OP_REGCRESET	 = 118,
	OP_REGCOMP	 = 119,
	OP_MATCH	 = 120,
	OP_QR		 = 121,
	OP_SUBST	 = 122,
	OP_SUBSTCONT	 = 123,
	OP_TRANS	 = 124,
	OP_TRANSR	 = 125,
	OP_LENGTH	 = 126,
	OP_SUBSTR	 = 127,
	OP_VEC		 = 128,
	OP_INDEX	 = 129,
	OP_RINDEX	 = 130,
	OP_SPRINTF	 = 131,
	OP_FORMLINE	 = 132,
	OP_ORD		 = 133,
	OP_CHR		 = 134,
	OP_CRYPT	 = 135,
	OP_UCFIRST	 = 136,
	OP_LCFIRST	 = 137,
	OP_UC		 = 138,
	OP_LC		 = 139,
	OP_QUOTEMETA	 = 140,
	OP_RV2AV	 = 141,
	OP_AELEMFAST	 = 142,
	OP_AELEMFAST_LEX = 143,
	OP_AELEM	 = 144,
	OP_I_AELEM	 = 145,
	OP_N_AELEM	 = 146,
	OP_S_AELEM	 = 147,
	OP_AELEMFAST_LEX_U = 148,
	OP_AELEM_U	 = 149,
	OP_I_AELEM_U	 = 150,
	OP_N_AELEM_U	 = 151,
	OP_S_AELEM_U	 = 152,
	OP_ASLICE	 = 153,
	OP_KVASLICE	 = 154,
	OP_AEACH	 = 155,
	OP_AVALUES	 = 156,
	OP_AKEYS	 = 157,
	OP_EACH		 = 158,
	OP_VALUES	 = 159,
	OP_KEYS		 = 160,
	OP_DELETE	 = 161,
	OP_EXISTS	 = 162,
	OP_RV2HV	 = 163,
	OP_HELEM	 = 164,
	OP_HSLICE	 = 165,
	OP_KVHSLICE	 = 166,
	OP_MULTIDEREF	 = 167,
	OP_UNPACK	 = 168,
	OP_PACK		 = 169,
	OP_SPLIT	 = 170,
	OP_JOIN		 = 171,
	OP_LIST		 = 172,
	OP_LSLICE	 = 173,
	OP_ANONLIST	 = 174,
	OP_ANONHASH	 = 175,
	OP_SPLICE	 = 176,
	OP_PUSH		 = 177,
	OP_POP		 = 178,
	OP_SHIFT	 = 179,
	OP_UNSHIFT	 = 180,
	OP_SORT		 = 181,
	OP_REVERSE	 = 182,
	OP_GREPSTART	 = 183,
	OP_GREPWHILE	 = 184,
	OP_MAPSTART	 = 185,
	OP_MAPWHILE	 = 186,
	OP_RANGE	 = 187,
	OP_FLIP		 = 188,
	OP_FLOP		 = 189,
	OP_AND		 = 190,
	OP_OR		 = 191,
	OP_XOR		 = 192,
	OP_DOR		 = 193,
	OP_COND_EXPR	 = 194,
	OP_ANDASSIGN	 = 195,
	OP_ORASSIGN	 = 196,
	OP_DORASSIGN	 = 197,
	OP_ENTERSUB	 = 198,
	OP_ENTERXSSUB	 = 199,
	OP_METHOD	 = 200,
	OP_METHOD_NAMED	 = 201,
	OP_METHOD_SUPER	 = 202,
	OP_METHOD_REDIR	 = 203,
	OP_METHOD_REDIR_SUPER = 204,
	OP_LEAVESUB	 = 205,
	OP_LEAVESUBLV	 = 206,
	OP_SIGNATURE	 = 207,
	OP_CALLER	 = 208,
	OP_WARN		 = 209,
	OP_DIE		 = 210,
	OP_RESET	 = 211,
	OP_LINESEQ	 = 212,
	OP_NEXTSTATE	 = 213,
	OP_SETSTATE	 = 214,
	OP_KEEPSTATE	 = 215,
	OP_DBSTATE	 = 216,
	OP_UNSTACK	 = 217,
	OP_ENTER	 = 218,
	OP_LEAVE	 = 219,
	OP_SCOPE	 = 220,
	OP_ENTERITER	 = 221,
	OP_ITER		 = 222,
	OP_ITER_ARY	 = 223,
	OP_ITER_LAZYIV	 = 224,
	OP_ENTERLOOP	 = 225,
	OP_LEAVELOOP	 = 226,
	OP_RETURN	 = 227,
	OP_LAST		 = 228,
	OP_NEXT		 = 229,
	OP_REDO		 = 230,
	OP_DUMP		 = 231,
	OP_GOTO		 = 232,
	OP_EXIT		 = 233,
	OP_ENTERGIVEN	 = 234,
	OP_LEAVEGIVEN	 = 235,
	OP_ENTERWHEN	 = 236,
	OP_LEAVEWHEN	 = 237,
	OP_BREAK	 = 238,
	OP_CONTINUE	 = 239,
	OP_OPEN		 = 240,
	OP_CLOSE	 = 241,
	OP_PIPE_OP	 = 242,
	OP_FILENO	 = 243,
	OP_UMASK	 = 244,
	OP_BINMODE	 = 245,
	OP_TIE		 = 246,
	OP_UNTIE	 = 247,
	OP_TIED		 = 248,
	OP_DBMOPEN	 = 249,
	OP_DBMCLOSE	 = 250,
	OP_SSELECT	 = 251,
	OP_SELECT	 = 252,
	OP_GETC		 = 253,
	OP_READ		 = 254,
	OP_ENTERWRITE	 = 255,
	OP_LEAVEWRITE	 = 256,
	OP_PRTF		 = 257,
	OP_PRINT	 = 258,
	OP_SAY		 = 259,
	OP_SYSOPEN	 = 260,
	OP_SYSSEEK	 = 261,
	OP_SYSREAD	 = 262,
	OP_SYSWRITE	 = 263,
	OP_EOF		 = 264,
	OP_TELL		 = 265,
	OP_SEEK		 = 266,
	OP_TRUNCATE	 = 267,
	OP_FCNTL	 = 268,
	OP_IOCTL	 = 269,
	OP_FLOCK	 = 270,
	OP_SEND		 = 271,
	OP_RECV		 = 272,
	OP_SOCKET	 = 273,
	OP_SOCKPAIR	 = 274,
	OP_BIND		 = 275,
	OP_CONNECT	 = 276,
	OP_LISTEN	 = 277,
	OP_ACCEPT	 = 278,
	OP_SHUTDOWN	 = 279,
	OP_GSOCKOPT	 = 280,
	OP_SSOCKOPT	 = 281,
	OP_GETSOCKNAME	 = 282,
	OP_GETPEERNAME	 = 283,
	OP_LSTAT	 = 284,
	OP_STAT		 = 285,
	OP_FTRREAD	 = 286,
	OP_FTRWRITE	 = 287,
	OP_FTREXEC	 = 288,
	OP_FTEREAD	 = 289,
	OP_FTEWRITE	 = 290,
	OP_FTEEXEC	 = 291,
	OP_FTIS		 = 292,
	OP_FTSIZE	 = 293,
	OP_FTMTIME	 = 294,
	OP_FTATIME	 = 295,
	OP_FTCTIME	 = 296,
	OP_FTROWNED	 = 297,
	OP_FTEOWNED	 = 298,
	OP_FTZERO	 = 299,
	OP_FTSOCK	 = 300,
	OP_FTCHR	 = 301,
	OP_FTBLK	 = 302,
	OP_FTFILE	 = 303,
	OP_FTDIR	 = 304,
	OP_FTPIPE	 = 305,
	OP_FTSUID	 = 306,
	OP_FTSGID	 = 307,
	OP_FTSVTX	 = 308,
	OP_FTLINK	 = 309,
	OP_FTTTY	 = 310,
	OP_FTTEXT	 = 311,
	OP_FTBINARY	 = 312,
	OP_CHDIR	 = 313,
	OP_CHOWN	 = 314,
	OP_CHROOT	 = 315,
	OP_UNLINK	 = 316,
	OP_CHMOD	 = 317,
	OP_UTIME	 = 318,
	OP_RENAME	 = 319,
	OP_LINK		 = 320,
	OP_SYMLINK	 = 321,
	OP_READLINK	 = 322,
	OP_MKDIR	 = 323,
	OP_RMDIR	 = 324,
	OP_OPEN_DIR	 = 325,
	OP_READDIR	 = 326,
	OP_TELLDIR	 = 327,
	OP_SEEKDIR	 = 328,
	OP_REWINDDIR	 = 329,
	OP_CLOSEDIR	 = 330,
	OP_FORK		 = 331,
	OP_WAIT		 = 332,
	OP_WAITPID	 = 333,
	OP_SYSTEM	 = 334,
	OP_EXEC		 = 335,
	OP_KILL		 = 336,
	OP_GETPPID	 = 337,
	OP_GETPGRP	 = 338,
	OP_SETPGRP	 = 339,
	OP_GETPRIORITY	 = 340,
	OP_SETPRIORITY	 = 341,
	OP_TIME		 = 342,
	OP_TMS		 = 343,
	OP_LOCALTIME	 = 344,
	OP_GMTIME	 = 345,
	OP_ALARM	 = 346,
	OP_SLEEP	 = 347,
	OP_SHMGET	 = 348,
	OP_SHMCTL	 = 349,
	OP_SHMREAD	 = 350,
	OP_SHMWRITE	 = 351,
	OP_MSGGET	 = 352,
	OP_MSGCTL	 = 353,
	OP_MSGSND	 = 354,
	OP_MSGRCV	 = 355,
	OP_SEMOP	 = 356,
	OP_SEMGET	 = 357,
	OP_SEMCTL	 = 358,
	OP_REQUIRE	 = 359,
	OP_DOFILE	 = 360,
	OP_HINTSEVAL	 = 361,
	OP_ENTEREVAL	 = 362,
	OP_LEAVEEVAL	 = 363,
	OP_ENTERTRY	 = 364,
	OP_LEAVETRY	 = 365,
	OP_GHBYNAME	 = 366,
	OP_GHBYADDR	 = 367,
	OP_GHOSTENT	 = 368,
	OP_GNBYNAME	 = 369,
	OP_GNBYADDR	 = 370,
	OP_GNETENT	 = 371,
	OP_GPBYNAME	 = 372,
	OP_GPBYNUMBER	 = 373,
	OP_GPROTOENT	 = 374,
	OP_GSBYNAME	 = 375,
	OP_GSBYPORT	 = 376,
	OP_GSERVENT	 = 377,
	OP_SHOSTENT	 = 378,
	OP_SNETENT	 = 379,
	OP_SPROTOENT	 = 380,
	OP_SSERVENT	 = 381,
	OP_EHOSTENT	 = 382,
	OP_ENETENT	 = 383,
	OP_EPROTOENT	 = 384,
	OP_ESERVENT	 = 385,
	OP_GPWNAM	 = 386,
	OP_GPWUID	 = 387,
	OP_GPWENT	 = 388,
	OP_SPWENT	 = 389,
	OP_EPWENT	 = 390,
	OP_GGRNAM	 = 391,
	OP_GGRGID	 = 392,
	OP_GGRENT	 = 393,
	OP_SGRENT	 = 394,
	OP_EGRENT	 = 395,
	OP_GETLOGIN	 = 396,
	OP_SYSCALL	 = 397,
	OP_LOCK		 = 398,
	OP_ONCE		 = 399,
	OP_CUSTOM	 = 400,
	OP_COREARGS	 = 401,
	OP_AVHVSWITCH	 = 402,
	OP_RUNCV	 = 403,
	OP_FC		 = 404,
	OP_PADCV	 = 405,
	OP_INTROCV	 = 406,
	OP_CLONECV	 = 407,
	OP_PADRANGE	 = 408,
	OP_REFASSIGN	 = 409,
	OP_LVREF	 = 410,
	OP_LVREFSLICE	 = 411,
	OP_LVAVREF	 = 412,
	OP_ANONCONST	 = 413,
	OP_max		
} opcode;

#define MAXO 414
#define OP_FREED MAXO


/* core types */

typedef enum {
    type_none = 0,
    type_int = 1,
    type_uint = 2,
    type_num = 3,
    type_str = 4,
    type_Int = 5,
    type_UInt = 6,
    type_Num = 7,
    type_Str = 8,
    type_Bool = 9,
    type_Numeric = 10,
    type_Scalar = 11,
    type_Ref = 12,
    type_Sub = 13,
    type_Regexp = 14,
    type_Object = 15,
    type_Array = 16,
    type_Hash = 17,
    type_List = 18,
    type_Any = 19,
    type_Void = 255
} core_types_t;

#ifdef PERL_IN_OP_C
static const char* const
core_types_n[] = {
    "",
    "int",
    "uint",
    "num",
    "str",
    "Int",
    "UInt",
    "Num",
    "Str",
    "Bool",
    "Numeric",
    "Scalar",
    "Ref",
    "Sub",
    "Regexp",
    "Object",
    "Array",
    "Hash",
    "List",
    "Any",
    "Void",
};
#endif /* PERL_IN_OP_C */

/* PL_opargs encoding */

/* Lowest 10 bits of PL_opargs */
#define OA_MARK	1
#define OA_FOLDCONST	2
#define OA_RETSCALAR	4
#define OA_TARGET	8
#define OA_TARGLEX	24
#define OA_OTHERINT	32
#define OA_DANGEROUS	64
#define OA_DEFGV	128
#define OA_PURE	256
#define OA_BOXRET	512

/* The next 4 bits (10..13) encode op class information */
#define OCSHIFT 10

/* Each remaining 4bit nybbles of PL_opargs (i.e. bits 14..17, 18..21 etc)
 * encode the type for each arg */
#define OASHIFT 14

/* arg types */
#define OA_SCALAR  1
#define OA_LIST    2
#define OA_AVREF   3
#define OA_HVREF   4
#define OA_CVREF   5
#define OA_FILEREF 6
#define OA_SCALARREF 7
#define OA_OPTIONAL 8

/* 0b0011_1100_0000_0000 / 0xf000 */
#define OA_CLASS_MASK (0xf << OCSHIFT)

#define OA_BASEOP 	(0 << OCSHIFT)
#define OA_UNOP 	(1 << OCSHIFT)
#define OA_BINOP 	(2 << OCSHIFT)
#define OA_LOGOP 	(3 << OCSHIFT)
#define OA_LISTOP 	(4 << OCSHIFT)
#define OA_PMOP 	(5 << OCSHIFT)
#define OA_SVOP 	(6 << OCSHIFT)
#define OA_PVOP_OR_SVOP (7 << OCSHIFT)
#define OA_LOOP 	(8 << OCSHIFT)
#define OA_COP 		(9 << OCSHIFT)
#define OA_BASEOP_OR_UNOP (10 << OCSHIFT)
#define OA_FILESTATOP 	(11 << OCSHIFT)
#define OA_LOOPEXOP 	(12 << OCSHIFT)
#define OA_METHOP 	(13 << OCSHIFT)
#define OA_UNOP_AUX 	(14 << OCSHIFT)


#define OP_HAS_TARGLEX(ot) ((PL_opargs[ot] & OA_TARGLEX) == OA_TARGLEX)

#define OpCLASS(ot)      (PL_opargs[(ot)] & OA_CLASS_MASK)
#define OP_IS_BASEOP(ot) (OpCLASS(ot) == OA_BASEOP || OpCLASS(ot) == OA_BASEOP_OR_UNOP)
#define OP_IS_UNOP(ot)   (OpCLASS(ot) == OA_UNOP || OpCLASS(ot) == OA_BASEOP_OR_UNOP)
#define OP_IS_BINOP(ot)  OpCLASS(ot) == OA_BINOP
#define OP_IS_LOGOP(ot)  OpCLASS(ot) == OA_LOGOP
#define OP_IS_LISTOP(ot) OpCLASS(ot) == OA_LISTOP
#define OP_IS_PMOP(ot)   OpCLASS(ot) == OA_PMOP
#define OP_IS_SVOP(ot)   (OpCLASS(ot) == OA_SVOP || OpCLASS(ot) == OA_PVOP_OR_SVOP)
#ifdef USE_ITHREADS
# define OP_IS_PADOP(ot)  OP_IS_SVOP(ot)
#endif
#define OP_IS_LOOP(ot)   OpCLASS(ot) == OA_LOOP
#define OP_IS_COP(ot)    OpCLASS(ot) == OA_COP
#define OP_IS_FILESTATOP(ot) OpCLASS(ot) == OA_FILESTATOP
#define OP_IS_METHOP(ot) OpCLASS(ot) == OA_METHOP

/* The other OP_IS_* macros are optimized to a simple range check because
   all the member OPs are contiguous in regen/opcodes table.
   regen/opcode.pl verifies the range contiguity, or generates an OR-equals
   expression */

#define OP_HAS_LIST(ot)	\
	((ot) == OP_AASSIGN || \
	 (ot) == OP_ANONHASH || \
	 (ot) == OP_ANONLIST || \
	 (ot) == OP_ASLICE || \
	 (ot) == OP_CHMOD || \
	 (ot) == OP_CHOMP || \
	 (ot) == OP_CHOP || \
	 (ot) == OP_CHOWN || \
	 (ot) == OP_DIE || \
	 (ot) == OP_ENTERSUB || \
	 (ot) == OP_ENTERXSSUB || \
	 (ot) == OP_EXEC || \
	 (ot) == OP_FORMLINE || \
	 (ot) == OP_GREPSTART || \
	 (ot) == OP_HSLICE || \
	 (ot) == OP_JOIN || \
	 (ot) == OP_KILL || \
	 (ot) == OP_KVASLICE || \
	 (ot) == OP_KVHSLICE || \
	 (ot) == OP_LIST || \
	 (ot) == OP_LSLICE || \
	 (ot) == OP_MAPSTART || \
	 (ot) == OP_OPEN || \
	 (ot) == OP_PACK || \
	 (ot) == OP_PRINT || \
	 (ot) == OP_PRTF || \
	 (ot) == OP_PUSH || \
	 (ot) == OP_REFGEN || \
	 (ot) == OP_REPEAT || \
	 (ot) == OP_RETURN || \
	 (ot) == OP_REVERSE || \
	 (ot) == OP_SAY || \
	 (ot) == OP_SORT || \
	 (ot) == OP_SPLICE || \
	 (ot) == OP_SPRINTF || \
	 (ot) == OP_SYSCALL || \
	 (ot) == OP_SYSTEM || \
	 (ot) == OP_TIE || \
	 (ot) == OP_UNLINK || \
	 (ot) == OP_UNSHIFT || \
	 (ot) == OP_UTIME || \
	 (ot) == OP_WARN)

#define OP_IS_SOCKET(ot)	\
	((ot) >= OP_SEND && (ot) <= OP_GETPEERNAME)

#define OP_IS_FILETEST(ot)	\
	((ot) >= OP_FTRREAD && (ot) <= OP_FTBINARY)

#define OP_IS_FILETEST_ACCESS(ot)	\
	((ot) >= OP_FTRREAD && (ot) <= OP_FTEEXEC)

#define OP_IS_NUMCOMPARE(ot)	\
	((ot) >= OP_LT && (ot) <= OP_I_CMP)

#define OP_IS_DIRHOP(ot)	\
	((ot) >= OP_READDIR && (ot) <= OP_CLOSEDIR)

#define OP_IS_INFIX_BIT(ot)	\
	((ot) >= OP_BIT_AND && (ot) <= OP_S_BIT_OR)

#define OP_IS_PADVAR(ot)	\
	((ot) >= OP_PADSV && (ot) <= OP_PADANY)

#define OP_IS_ITER(ot)	\
	((ot) >= OP_ITER && (ot) <= OP_ITER_LAZYIV)

/* backcompat old Perl 5 names: */
#if 1
#define OP_NCMP		 OP_CMP
#define OP_I_NCMP	 OP_I_CMP
#define OP_SLT		 OP_S_LT
#define OP_SGT		 OP_S_GT
#define OP_SLE		 OP_S_LE
#define OP_SGE		 OP_S_GE
#define OP_SEQ		 OP_S_EQ
#define OP_SNE		 OP_S_NE
#define OP_SCMP		 OP_S_CMP
#define OP_NBIT_AND	 OP_I_BIT_AND
#define OP_NBIT_XOR	 OP_I_BIT_XOR
#define OP_NBIT_OR	 OP_I_BIT_OR
#define OP_SBIT_AND	 OP_S_BIT_AND
#define OP_SBIT_XOR	 OP_S_BIT_XOR
#define OP_SBIT_OR	 OP_S_BIT_OR
#define OP_NCOMPLEMENT	 OP_I_COMPLEMENT
#define OP_SCOMPLEMENT	 OP_S_COMPLEMENT

#define Perl_pp_ncmp	 Perl_pp_cmp
#define Perl_pp_i_ncmp	 Perl_pp_i_cmp
#define Perl_pp_slt	 Perl_pp_s_lt
#define Perl_pp_sgt	 Perl_pp_s_gt
#define Perl_pp_sle	 Perl_pp_s_le
#define Perl_pp_sge	 Perl_pp_s_ge
#define Perl_pp_seq	 Perl_pp_s_eq
#define Perl_pp_sne	 Perl_pp_s_ne
#define Perl_pp_scmp	 Perl_pp_s_cmp
#define Perl_pp_nbit_and Perl_pp_i_bit_and
#define Perl_pp_nbit_xor Perl_pp_i_bit_xor
#define Perl_pp_nbit_or	 Perl_pp_i_bit_or
#define Perl_pp_sbit_and Perl_pp_s_bit_and
#define Perl_pp_sbit_xor Perl_pp_s_bit_xor
#define Perl_pp_sbit_or	 Perl_pp_s_bit_or
#define Perl_pp_ncomplement Perl_pp_i_complement
#define Perl_pp_scomplement Perl_pp_s_complement
#endif

/* ex: set ro: */
