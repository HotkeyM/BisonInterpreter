%{ /* -*- C++ -*- */
# include <cstdlib>
# include <cerrno>
# include <climits>
# include <string>
# include <bis.h>
# include "calc++-driver.hh"
# include "calc++-parser.tab.hh"
/* Work around an incompatibility in flex (at least versions
2.5.31 through 2.5.33): it generates code that does
not conform to C89. See Debian bug 333231
<http://bugs.debian.org/cgi-bin/bugreport.cgi?bug=333231>. */
# undef yywrap
# define yywrap() 1
/* By default yylex returns int, we use token_type.
Unfortunately yyterminate by default returns 0, which is
not of token_type. */

#define yyterminate() return token::END
%}

%option noyywrap nounput batch debug

id [a-zA-Z][a-zA-Z_0-9]*
int [0-9]+
blank [ \t]

INT		int
TRUE	true
FALSE	false
BOOLEAN	boolean
CBOOLEAN cboolean
MAP		map
CINT	cint
ASSIGN	:=
EQUAL	'='
ADD		"+"
SUB		"-"
MUL		"*"
INC		inc
DEC		dec
NOT		not
OR		or
LT		lt
GT		gt
WHILE	while
DO		do
IF		if
ELSE	else
STEP	step
BACK	back
RIGHT	right
LEFT	left
LOOK	look
PROC	proc
BAR		bar
EMP		emp
SET		set
CLR		clr

%{
# define YY_USER_ACTION yylloc->columns (yyleng);
%}
%%
%{
yylloc->step ();
%}
{blank}+ yylloc->step ();
[\n]+ yylloc->lines (yyleng); yylloc->step ();

%{
typedef yy::calcxx_parser::token token;
%}
{ADD} return token::ADD;
{SUB} return token::SUB;
"/" {return token::DIV;}
"=" {return token::EQUAL;}
{MUL} return token::MUL;
":=" return token::ASSIGN;
{INT} return token::INT;
{INC} return token::INC;
{DEC} return token::DEC;
{CINT} return token::CINT;
{CBOOLEAN} return token::CBOOLEAN;
{MAP} return token::MAP;
{WHILE} return token::WHILE;
{DO} return token::DO;
{ELSE} return token::ELSE;
"if" return token::IF;
{STEP} return token::STEP;
{BACK} return token::BACK;
{RIGHT} return token::RIGHT;
{LEFT} return token::LEFT;
{LOOK} return token::LOOK;
{PROC} return token::PROC;
{BAR} return token::BAR;
{EMP} return token::EMP;
{SET} return token::SET;
{CLR} return token::CLR;
{TRUE} {yylval->bval = true;
return token::TRUe;}
{FALSE} {yylval->bval = false;
return token::FALSe;}
{BOOLEAN} return token::BOOLEAN;
{EQUAL} return token::EQUAL;
";" return token::ENDL;
"[" return token::STARTPARAM;
"]" return token::ENDPARAM;
"(" return token::STARTSENT;
")" return token::ENDSENT;
"." return token::EOP;
{int} {
errno = 0;
long n = strtol (yytext, NULL, 10);
if (! (INT_MIN <= n && n <= INT_MAX && errno != ERANGE))
driver.error (*yylloc, "integer is out of range");
yylval->ival = n;
return token::NUMBER;
}
{id} {//yylval->sval = new std::string (yytext); return token::IDENTIFIER;
		Symbol *s;
		if (driver.s.GetSymbol(std::string(yytext))->type == NOTYPE)
		{
		s = new Symbol(true, std::string(yytext));
		driver.s.AddSymbol(s);
		yylval->sym = s;
		return token::ID;
		}
		else
		{
		s = driver.s.GetSymbol(std::string(yytext));
		yylval->sym = driver.s.GetSymbol(std::string(yytext));
		switch (s->type)
		{
			case VAR_INT_TYPE: return token::VARINT;
			case VAR_BOOL_TYPE: return token::VARBOOL;
			//case VAR_MAR_TYPE: return token::VARMAP;
			case CONST_INT_TYPE: return token::CONSTINT;
			case CONST_BOOL_TYPE: return token::CONSTBOOL;
			case PROC_TYPE: return token::PROCID;
			default: return token::ID;
		}
		}
	}
. driver.error (*yylloc, "invalid character");
%%

void
calcxx_driver::scan_begin ()
{
yy_flex_debug = trace_scanning;
if (file == "-")
yyin = stdin;
else if (!(yyin = fopen (file.c_str (), "r")))
{
error (std::string ("cannot open ") + file);
exit (1);
}
}
void
calcxx_driver::scan_end ()
{
fclose (yyin);
}
