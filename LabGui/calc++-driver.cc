#ifndef CALCDRIVER_CC
#define CALCDRIVER_CC

#include "graphon.h"
#include <QTextEdit>
#include <QTextStream>
#include <QString>
#include <QCursor>

#include "calc++-driver.hh"
#include "calc++-parser.tab.hh"

calcxx_driver::calcxx_driver ()
: trace_scanning (false), trace_parsing (false)
{
variables["one"] = 1;
variables["two"] = 2;
}

calcxx_driver::calcxx_driver (Graphon *gra)
: trace_scanning (false), trace_parsing (false)
{
    variables["one"] = 1;
    variables["two"] = 2;

    g = gra;
}

calcxx_driver::~calcxx_driver ()
{

}
int
calcxx_driver::parse (const std::string &f)
{
file = f;
scan_begin ();
yy::calcxx_parser parser (*this);
parser.set_debug_level (trace_parsing);
int res = parser.parse ();
scan_end ();
return res;
}

void
calcxx_driver::error (const yy::location& l, const std::string& m)
{
std::cerr << l << ": " << m << std::endl;
QString str;
QTextStream st(&str);
st <<  l.begin.line ;
st << ":";
st << l.begin.column;
st << ": " ;
st << QString(m.c_str());
e->insertPlainText(str);
e->insertPlainText("\n");
}
void
calcxx_driver::error (const std::string& m)
{
e->insertPlainText(m.c_str());
e->insertPlainText("\n");
std::cerr << m << std::endl;
}

#endif // CALCDRIVER_CC
