%skeleton "lalr1.cc" /* -*- C++ -*- */
%defines
%define parser_class_name "calcxx_parser"
%code requires {
# include <string>
#include <stdio.h>
#include <iostream>
#include "bis.h"
using namespace std;
class calcxx_driver;
}

// The parsing context.
%parse-param { calcxx_driver& driver }
%lex-param { calcxx_driver& driver }

%locations
%initial-action
{
// Initialize the initial location.
@$.begin.filename = @$.end.filename = &driver.file;
};

%debug
%error-verbose

// Symbols.
%union
{
int ival;
std::string *sval;
Symbol *sym;
bool bval;
SyntNode *node;
};

%code {
# include "calc++-driver.hh"
}

%token END 0 "end of file"
%token ASSIGN ":="
%token <sval> IDENTIFIER "identifier"
%token <ival> NUMBER "number"
%type <node> exp
%type <node> boolexp
%type <node> block
%token EOP

%token <bval> TRUe FALSe
%token THEN
%token INT BOOLEAN MAP CINT CBOOLEAN INC DEC WHILE DO IF ELSE STEP BACK EQUAL
%token RIGHT LEFT LOOK PROC BAR EMP SET CLR STARTSENT ENDSENT NOT OR GT LT ENDL
%token STARTPARAM ENDPARAM
%token ADD SUB MUL DIV
%token <sym> VARINT CONSTINT
%token <sym> VARBOOL CONSTBOOL
%token <sym> VARMAP
%token <sym> PROCID
%token <sym> ID

%type <node> line
%type <node> stmt


%type <node> lines
%type <node> linem
%type <node> linesm
%type <node> matched
%type <node> unmatched
%type <node> blockm

%type <node> unit
%type <node> parameters
%type <node> parameterscall

%printer { debug_stream () << *$$; } "identifier"
%destructor { delete $$; } "identifier"
%printer { debug_stream () << $$; } <ival>




%%
%start unit;
//unit: assignments exp { driver.result = $2; printf("%i", $2);};
unit: lines EOP {$$ = $1; $$->Do();};

linesm : linem {$$ = $1;}
| linesm linem {$$ = SyntNode::CreateNode(&driver, Lines, $1, $2);};

lines: line {$$ = $1;}
| lines line {$$ = SyntNode::CreateNode(&driver, Lines, $1, $2);};

exp: ADD exp exp { //$$ = $2 + $3;
					$$ = SyntNode::CreateNode(&driver, Add, $2, $3);}
| SUB exp exp { //$$ = $2 - $3;
				$$ = SyntNode::CreateNode(&driver, Sub, $2, $3);}
| MUL exp exp { //$$ = $2 * $3; 
				$$ = SyntNode::CreateNode(&driver, Mul, $2, $3);}
| DIV exp exp { //$$ = $2 / $3; 
				$$ = SyntNode::CreateNode(&driver, Div, $2, $3);}
/*| GT exp exp {$$ = SyntNode::CreateNode(&driver, Gt, $2, $3);
}
| LT exp exp {$$ = SyntNode::CreateNode(&driver, Lt, $2, $3);}
*/
| INC VARINT exp {
SyntNode *n	 = SyntNode::CreateNode(&driver, Add, $2, $3);
$$ = SyntNode::CreateNode(&driver, $2, n, true);
}
| DEC VARINT exp {
SyntNode *n	 = SyntNode::CreateNode(&driver, Add, $2, $3);
$$ = SyntNode::CreateNode(&driver, $2, n, true);
}
//| INC exp exp {}
//| DEC exp exp {}
| LOOK {$$ = SyntNode::CreateNode(&driver, Look, (SyntNode*)NULL, (SyntNode*)NULL); }
| "number" {$$ = SyntNode::CreateNode(&driver, $1); }
| VARINT { $$ = SyntNode::CreateNode(&driver, $1); }
| CONSTINT {$$ = SyntNode::CreateNode(&driver, $1->value);}
| boolexp {//if($1) $$ = 1; else $$ = 0;
$$ = $1;
}
;

/*
num:  "number" { $$ = $1; }
| VARINT { $$ = $1->value;}
| CONSTINT { $$ = $1->value;}
| boolexp {if($1) $$ = 1; else $$ = 0;};
*/

boolexp: GT exp exp {$$ = SyntNode::CreateNode(&driver, Gt, $2, $3);
//if ($2 > $3) $$ = true; else $$ = false;
 }
| LT exp exp {$$ = SyntNode::CreateNode(&driver, Lt, $2, $3);
//if ($2 < $3) $$ = true; else $$ = false;
}
| EQUAL exp exp {$$ = SyntNode::CreateNode(&driver, Equal, $2, $3);
//if ($2 == $3) $$ = true; else $$ = false;
}
| OR boolexp boolexp {$$ = SyntNode::CreateNode(&driver, Or, $2, $3);
//$$ = $2 || $3;
}
| NOT boolexp {$$ = SyntNode::CreateNode(&driver, Not, $2, $2);
//$$ = !$2;
}
| VARBOOL {$$ = SyntNode::CreateNode(&driver, $1);
//$$ = $1;
}
| STEP { $$ = SyntNode::CreateNode(&driver, Step, (SyntNode*)NULL, (SyntNode*)NULL);}
| CONSTBOOL {$$ = SyntNode::CreateNode(&driver, $1->value);
//$$ = $1;
}
| TRUe {$$ = SyntNode::CreateNode(&driver, 1);
//$$ = true;
}
| FALSe {$$ = SyntNode::CreateNode(&driver, 0);
//$$ = false;
};

line: stmt ENDL {$$ = $1;
// $1->Do();
};

linem : matched ENDL {$$ = $1; 
//$1->Do(); 
};

matched: INT ID EQUAL exp {//$2->type = VAR_INT_TYPE; $2->value = $4; cout << "New int " <<
						//$2->name << " is " << $4 << endl;
						$2->type = VAR_INT_TYPE; $$ = SyntNode::CreateNode(&driver, $2, $4);}
| BOOLEAN ID EQUAL boolexp {
//$2->type = VAR_BOOL_TYPE; $2->value = $4; cout << "New bool " <<
	//					$2->name << " is " << $4 << endl;
	$2->type = VAR_BOOL_TYPE; $$ = SyntNode::CreateNode(&driver, $2, $4);
}
| MAP ID {//$2->type = VAR_MAP_TYPE; cout << "New map " <<
			//			$2->name << endl;
			$2->type = VAR_MAP_TYPE; $$ = SyntNode::CreateNode(&driver, $2, 0);
			}
| CINT ID EQUAL exp {//$2->type = CONST_INT_TYPE; $2->value = $4; cout << "New const int " <<
					//	$2->name << " is " << $4 << endl;
					$2->type = CONST_INT_TYPE; $$ = SyntNode::CreateNode(&driver, $2, $4);
					}
| CBOOLEAN ID EQUAL boolexp {
//$2->type = CONST_BOOL_TYPE; $2->value = $4; cout << "New const bool " <<
	//					$2->name << " is " << $4 << endl;
	$2->type = CONST_BOOL_TYPE; $$ = SyntNode::CreateNode(&driver, $2, $4);
	}
| VARINT ASSIGN exp {//$1->value = $3; cout << "assign " <<
						//$1->name << " value " << $3 << endl;
						$$ = SyntNode::CreateNode(&driver, $1, $3, true);}
| WHILE exp DO blockm {
$$ = SyntNode::CreateNode(&driver, While, $2, $4);
}	
| BACK { $$ = SyntNode::CreateNode(&driver, Back, (SyntNode*)NULL, (SyntNode*)NULL);  }
| LEFT { $$ = SyntNode::CreateNode(&driver, Left, (SyntNode*)NULL, (SyntNode*)NULL);}
| RIGHT { $$ = SyntNode::CreateNode(&driver, Right, (SyntNode*)NULL, (SyntNode*)NULL);}
| PROC ID STARTPARAM parameters ENDPARAM
{
driver.s.EnterFunction();
cout << "Entering new namespace. Variables - " << driver.s.table.size() << endl; 
Symbol * s;
for (int i = 0; i < $4->paramList.size(); ++i )
{
s = new Symbol(true, $4->paramList.at(i)->name);
//		driver.s.AddSymbol(s);
//s = new Symbol(false, );
		driver.s.AddSymbol(s);
//		s->name = $4->paramList.at(i)->name;
		s->type = VAR_INT_TYPE;
		cout << "Local variable " << s->name <<". "<< endl;
		}
}
blockm {$$ = SyntNode::CreateNode(&driver, $2, $4, $7);
driver.s.ExitFunction();
}
| PROCID STARTPARAM parameterscall ENDPARAM {$$ = SyntNode::CreateNode(&driver, ProcExec, $1, $3);} 
| BAR STARTPARAM VARINT VARMAP exp exp ENDPARAM {$$ = SyntNode::CreateNode(&driver, OpBar, $3,$4,$5,$6);}
| EMP STARTPARAM VARINT VARMAP exp exp ENDPARAM {$$ = SyntNode::CreateNode(&driver, OpEmp, $3,$4,$5,$6);}
| SET STARTPARAM VARINT VARMAP exp exp ENDPARAM {$$ = SyntNode::CreateNode(&driver, OpSet, $3,$4,$5,$6);}
| CLR STARTPARAM VARMAP exp exp ENDPARAM {$$ = SyntNode::CreateNode(&driver, OpClr, $3,NULL,$4,$5);}
| DO blockm {$$ = $2;}
| IF exp matched ELSE matched {cout << "IF exp matched ELSE matched"
									<< endl;
									$$ = SyntNode::CreateNode(&driver, If, $2, $3);
									$$->children.push_back($5);
									};

unmatched : IF exp matched {cout << " IF exp matched " << endl;
			$$ = SyntNode::CreateNode(&driver, If, $2, $3);
			}
          | IF exp unmatched {cout << "IF exp unmatched" << endl;
		  $$ = SyntNode::CreateNode(&driver, If, $2, $3);}
          | IF exp matched ELSE unmatched {cout << "IF exp matched ELSE un"
											<< endl;
			$$ = SyntNode::CreateNode(&driver, If, $2, $3);
									$$->children.push_back($5);
		}
          ;

stmt: matched { $$ = $1;}
 | unmatched {$$ = $1;};

parameterscall:
VARINT { $$ = SyntNode::CreateNode(&driver, $1, true, true);}
|VARBOOL { $$ = SyntNode::CreateNode(&driver, $1, true, true);}
| parameters VARBOOL {
$$ = SyntNode::CreateNode(&driver, $2, $1, true, true);
};
| parameters VARINT {
$$ = SyntNode::CreateNode(&driver, $2, $1, true, true);
};
 
parameters:
ID { $$ = SyntNode::CreateNode(&driver, $1, true, true);}
| parameters ID {
$$ = SyntNode::CreateNode(&driver, $2, $1, true, true);
};

blockm: matched {$$ = $1;}
| STARTSENT linesm ENDSENT {$$ = $2;};

block: matched {$$ = $1;}
| STARTSENT lines ENDSENT {$$ = $2;};


%%
void
yy::calcxx_parser::error (const yy::calcxx_parser::location_type& l,
const std::string& m)
{
driver.error (l, m);
}

//© Дмитрий Утямишев, 2011