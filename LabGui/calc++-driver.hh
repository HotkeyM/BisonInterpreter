#ifndef CALCDRIVER_HH
#define CALCDRIVER_HH

# include <string>
# include <map>
# include "calc++-parser.tab.hh"
#include "bis.h"

class Graphon;
class QTextEdit;

// Tell Flex the lexer’s prototype ...
# define YY_DECL \
yy::calcxx_parser::token_type \
yylex (yy::calcxx_parser::semantic_type* yylval, \
yy::calcxx_parser::location_type* yylloc, \
calcxx_driver& driver)
// ... and declare it for the parser’s sake.
YY_DECL;

// Conducting the whole scanning and parsing of Calc++.
class calcxx_driver
{
public:
calcxx_driver ();
calcxx_driver (Graphon *g);
virtual ~calcxx_driver ();
std::map<std::string, int> variables;
int result;

// Handling the scanner.
void scan_begin ();
void scan_end ();
bool trace_scanning;

// Run the parser. Return 0 on success.
int parse (const std::string& f);
std::string file;
bool trace_parsing;

// Error handling.
void error (const yy::location& l, const std::string& m);
void error (const std::string& m);

SymTable s;

Graphon *g;

QTextEdit *e;

};

#endif // CALCDRIVER_HH
