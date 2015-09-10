//© Дмитрий Утямишев, 2011

#ifndef BIS_H
#define BIS_H


//#include <math.h>
#include <string.h>
#include <string>
#include <map>
#include <stack>
#include <list>
#include <vector>
#include <iostream>
#include "vmap.h"
//#include "calc++-parser.tab.hh"
using namespace std;




//enum
//{
//CONST, INT, BOOLEAN, MAP, CINT, CBOOLEAN, ASSIGN, ADD, SUB, MUL, DIV, INC, DEC, NOT, OR, GT, LT,
//WHILE, DO, IF, ELSE, STEP, BACK, RIGHT, LEFT, LOOK, PROC, ID, BAR, EMP, SET, CLR, VARID, FID, ENDL,
//STARTSENT, ENDSENT
//};

enum SymType
{
        VAR_INT_TYPE, VAR_BOOL_TYPE, VAR_MAP_TYPE, CONST_INT_TYPE, CONST_BOOL_TYPE, PROC_TYPE, NOTYPE
};

//enum NodeType
//{
//    CONST, EXP, ASSIGN, INT, IDENT
//};

enum NodeOperator
{
    ADD_OP, SUB_OP, MUL_OP, DIV_OP
};

enum MapCell
{
    UNKNOWN, FREE, WALL
};

class SyntNode;

class Symbol
{
public:
        Symbol();
        Symbol(std::string str)
        {
            type = VAR_INT_TYPE;
            name = str;
        }
        Symbol(bool err, string str)
        {
            if (err == true)
            {
                this->type = NOTYPE;
                this->name = str;
            }
            else
            {
                type = VAR_INT_TYPE;
                name = str;
            }
        }

        Symbol(SymType t, string str)
        {

                this->type = t;
                this->name = str;

        }

        virtual int Value()
        {
            return value;
        }
        virtual void SetValue(int v)
        {
            value = v;
        }

        SymType type;
        string name;
        SyntNode *procPointer;
        //void *(procPointer)(int t);
        int value;
        bool error;

        int numParam;

        Vmap m;
        vector <string> paramNames;
private:
};

class SymLink : public Symbol
{
public:
   SymLink(Symbol *s, string n)
   {
       target = s;
       name = n;
       type = s->type;
   }
   virtual int Value()
   {
       return target->Value();
   }

   virtual void SetValue (int v)
   {
       target->SetValue(v);
   }

    Symbol *target;
private:

};

class SymTable
{
public:
        SymTable()
        {

        }
        Symbol *GetSymbol(string symname)
        {
        if (table.find(symname) != table.end())
            {
            return table[symname];
            }
        else
        {
            return new Symbol(true, symname);
             while((table.find(symname) != table.end()) && st.empty())
            {
            sttmp.push(table);
            table = st.top();
            st.pop();
            }

             if (table.find(symname) != table.end())
             {
                 //found
                 return table[symname];
             }
             else
             {
                 Symbol* ccc = new Symbol(true, symname);
                 return ccc;
             }
             while (!sttmp.empty())
             {
                 st.push(table);
                 table = sttmp.top();
                 sttmp.pop();
             }

        }
        }
        void EnterFunction()
        {
        st.push(table);
        map <string, Symbol*> *ttt = new map <string, Symbol*> ();
        table.swap(*ttt);
        }
        void ExitFunction()
        {
        table = st.top();
        st.pop();
        }


        SymType GetType(string s)
        {
            Symbol *sym = this->GetSymbol(s);
            return sym->type;
        }

        static Symbol *CreateSymbol()
        {
                Symbol *s = new Symbol();
                lst.push_back(s);
                return s;
        }
        static Symbol *CreateSymbol(string str)
        {
            Symbol *s = new Symbol(str);
            lst.push_back(s);
            return s;
        }

        static Symbol *CreateSymbol(bool err, string str)
        {
                Symbol *s = new Symbol(err,str);
               // lst.push_back(s);
                return s;
            }
        void AddSymbol(Symbol *s)
        {
            table[s->name] = s;
        }

        static Symbol *CreateSymbol(SymType t, string str)
        {
                Symbol *s = new Symbol(t,str);
                lst.push_back(s);
                return s;
         }
        map <string, Symbol*> table;

        void Show(void)
        {
            cout << endl;
            for (map<string, Symbol*>::const_iterator i = table.begin(); i != table.end();
                                ++i)
            {
                cout << (*i).first << "-----" << (*i).second->name <<
                        (*i).second->Value();
                SymLink *l = dynamic_cast <SymLink*> ((*i).second);
                if (l)
                {
                    cout <<"---Connected with---"<<l->target->name <<"---"
                            <<l->target->Value();
                }
                cout << endl;
            }
        }

private:

        vector <Symbol> paramvars;

        stack <map<string, Symbol*> > st;

        stack <map<string, Symbol*> > sttmp;
        static     list <Symbol*> lst;
};


enum NodeType {Assignstmt = 0, Intstmt = 1, Add = 2, Sub, Mul, Div, Term, Termsym
           , Lines = 8, While, If, Lt, Gt, Equal, Or, Not, ProcDecl, ParamList,
           ProcExec, OpBar, OpEmp, OpSet, Back, Left, Right, Look, Step, OpClr};

class calcxx_driver;

class SyntNode
{
public:
    SyntNode();
    SyntNode(calcxx_driver *drv, int i);
    SyntNode(calcxx_driver *drv, bool b);
    SyntNode(calcxx_driver *drv, Symbol *s);
    SyntNode(calcxx_driver *drv, Symbol *toInt, SyntNode *op);
    SyntNode(calcxx_driver *drv, Symbol *toAssign, SyntNode *op, bool nothing);
    SyntNode(calcxx_driver *drv ,NodeType t, SyntNode *op1, SyntNode *op2);
    SyntNode(calcxx_driver *drv, Symbol *procname, SyntNode *params, SyntNode *act);
    SyntNode(calcxx_driver *drv , Symbol *s, bool params);
    SyntNode(calcxx_driver *drv, Symbol *s, SyntNode *node, bool params, bool n);
    SyntNode(calcxx_driver *drv, Symbol *s, bool nothing, bool no);
     SyntNode(calcxx_driver *drv, NodeType t, Symbol *procname, SyntNode *params);
     SyntNode(calcxx_driver *drv, NodeType t, Symbol *varint, Symbol *varmap, SyntNode *n1, SyntNode *n2);


     static SyntNode * CreateNode(calcxx_driver *drv, NodeType t, Symbol *varint, Symbol *varmap, SyntNode *n1, SyntNode *n2)
     {
         SyntNode *node = new SyntNode (drv, t, varint, varmap, n1,n2);
         return node;
     }

    static SyntNode * CreateNode(calcxx_driver *drv, NodeType t, Symbol *procname, SyntNode *params)
    {
        SyntNode *node = new SyntNode (drv, ProcExec, procname,  params);
        return node;
    }

    static SyntNode * CreateNode(calcxx_driver *drv, Symbol *s, bool nothing, bool no)
    {
        SyntNode *node = new SyntNode (drv,s, true, true);
        return node;
    }

    static SyntNode * CreateNode(calcxx_driver *drv, Symbol *s, SyntNode *p, bool n, bool n2)
    {
        SyntNode *node = new SyntNode(drv, s, p, true, true);
        return node;
    }

    static SyntNode * CreateNode(calcxx_driver *drv, Symbol *procname, SyntNode *params, SyntNode *act)
    {
        SyntNode *node = new SyntNode(drv, procname, params, act);
        return node;
    }

    static SyntNode * CreateNode(calcxx_driver *drv, Symbol *s, SyntNode *n,
                                 bool nothing)
    {
        SyntNode *node = new SyntNode(drv ,s, n, nothing);
        return node;
    }

    static SyntNode * CreateNode(calcxx_driver *drv, Symbol *s, SyntNode *n)
    {
        SyntNode *node = new SyntNode(drv ,s, n);
        return node;
    }

    static SyntNode * CreateNode(calcxx_driver *drv,NodeType t, SyntNode *op1, SyntNode *op2 = 0)
    {
        SyntNode *node = new SyntNode(drv ,t, op1, op2);
        return node;
    }

    static SyntNode * CreateNode(calcxx_driver *drv, int i)
    {
        SyntNode *node = new SyntNode(drv, i);
        return node;
    }

    static SyntNode * CreateNode(calcxx_driver *drv, bool b)
    {
        SyntNode *node = new SyntNode(drv, b);
        return node;
    }

    static SyntNode * CreateNode(calcxx_driver *drv, Symbol *s)
    {
        SyntNode *node = new SyntNode(drv, s);
        return node;
    }

    static std::list <SyntNode *> program;

    void Do();

    NodeOperator op;
    NodeType type;
    std::vector <SyntNode *> children;

    vector <Symbol *> paramList;

    calcxx_driver *driver;
    int ival;
    bool bval;
    Symbol *sym;
    Symbol *sym2;
};


#endif

