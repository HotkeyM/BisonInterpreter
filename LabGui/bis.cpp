//© Дмитрий Утямишев, 2011

#include "bis.h"
#include "calc++-driver.hh"
#include "graphon.h"
#include <QTextEdit>

#include <QTextStream>
#include <QString>

SyntNode::SyntNode(calcxx_driver *drv, NodeType t, Symbol *varint, Symbol *varmap, SyntNode *n1, SyntNode *n2)
{
       driver = drv;
       this->type = t;
       this->sym = varint;
       this->sym2 = varmap;
       if (n1) children.push_back(n1);
       if (n2) children.push_back(n2);

}

SyntNode::SyntNode(calcxx_driver *drv, NodeType t, Symbol *procname, SyntNode *params)
{
    //конструктор для выполнения процедур
    driver = drv;
    type = ProcExec;

    this->sym = procname;
    this->paramList = params->paramList;
}

SyntNode::SyntNode(calcxx_driver *drv, Symbol *s, SyntNode *node, bool params, bool n)
{
    //конструктор для формирования списка параметров, много параметров
   this->driver = drv;
   this->type = ParamList;
   for (int i = 0; i < node->paramList.size(); ++i)
   paramList.push_back(node->paramList.at(i));
   paramList.push_back(s);
}

SyntNode::SyntNode(calcxx_driver *drv, Symbol *s, bool nothing, bool no)
{
     //конструктор для формирования списка параметров, один параметр
    driver = drv;
    type = ParamList;
    paramList.push_back(s);
}

SyntNode::SyntNode(calcxx_driver *drv, Symbol *procname, SyntNode *params, SyntNode *act)
{
    //конструктор для объявления процедур
    driver = drv;
    type = ProcDecl;

    //тут я ввожу значение в таблицу символов здесь, на этапе семантаки
    procname->type = PROC_TYPE;
    procname->procPointer = act;
    procname->numParam = params->paramList.size();
    //procname->paramNames = vector <string> (params->paramList);
    for (int i = 0; i < params->paramList.size(); ++i)
    {
        procname->paramNames.push_back(params->paramList.at(i)->name);
    }

}

SyntNode::SyntNode(calcxx_driver *drv, Symbol *toAssign, SyntNode *op, bool nothing)
{
    //\\
    this->driver = drv;
    this->type = Assignstmt;

    this->sym = toAssign;
    children.push_back(op);
}

SyntNode::SyntNode(calcxx_driver *drv, NodeType t, SyntNode *op1, SyntNode *op2)
{
    this->driver = drv;
    this->type = t;
    if(op1) children.push_back(op1);
    if (op2) children.push_back(op2);
}

SyntNode::SyntNode(calcxx_driver *drv, Symbol *toInt, SyntNode *op)
{
    cout << "Node creating....";
    this->driver = drv;
    this->type = Intstmt;

    this->sym = toInt;
    children.push_back(op);
    cout << "OK";
}

SyntNode::SyntNode(calcxx_driver *drv, int i)
{
    this->driver = drv;
    this->type = Term;
    this->ival = i;
}

SyntNode::SyntNode(calcxx_driver *drv, bool b)
{
    this->driver = drv;
    this->type = Term;
    if (b) this->ival = 1;
    else this->ival = 0;
}

SyntNode::SyntNode(calcxx_driver *drv, Symbol *s)
{
    this->driver = drv;
    this->type = Termsym;
    this->sym = s;
}

void SyntNode::Do()
{

  //  cout << "Processing node type" << (int)this->type << endl;
  //  cout << "This node have " << this->children.size() << "childs" << endl;

    if ((type != While) && (type != If) && (type != ProcDecl)
        &&(type != ParamList))
    {
        for (int i = 0; i < children.size(); ++i)
        {
            children.at(i)->driver = driver;
        children.at(i)->Do();
        }
    }
    // Если иф или вайл - то там особый случай.


        if (type == Assignstmt)
          {
          //  cout << "|";
           // driver->s.Show();
            //driver->s.Show();
            cout <<sym->name<<endl;

            driver->s.table[sym->name]->SetValue(children.at(0)->ival);
            cout <<"OK"<<endl;
            //sym->SetValue( children.at(0)->ival);
            cout << "Now int " << sym->name << " asigned " << sym->Value() << endl;
        }

        if (type == Intstmt)
        {
            sym->SetValue( children.at(0)->ival);
            cout << "New int" << sym->name << " = " << sym->Value() << endl;
        }

        if (type == If)
        {
            for (int i = 0; i < children.size(); ++i)
            {
                children.at(i)->driver = driver;
            }
            children.at(0)->Do();
            if (this->children.at(0)->ival) children.at(1)->Do();
            else
            {
                if (children.size() == 3) children.at(2)->Do();
            }
        }

        if (type == While)
        {
            for (int i = 0; i < children.size(); ++i)
            {
                children.at(i)->driver = driver;
            }

            children.at(0)->Do();
            while (children.at(0)->ival)
            {
                children.at(1)->Do();
                children.at(0)->Do();
            }
        }



        if (type == Termsym)
        {
            //cout << "|";
            //driver->s.Show();
            //cout << sym->name << " == " << driver->s.table[sym->name]->Value();
            //cout << "|";
            //driver->s.Show();
            //cout << "Requesting" << sym->name << " is " << sym->Value() << endl;
         /////////   if (this->sym->type == VAR_INT_TYPE)
            //    sym->SetValue(driver->s.table[sym->name]->Value());
            driver->s.Show();
            cout <<sym->name<<endl;
            this->ival = driver->s.table[sym->name]->Value();
            cout << "OK"<<endl;
            //cout << "|"<<sym->name<< sym->Value()<<"|"<<endl;
            /////////this->ival = sym->Value();
            //SymLink *l = dynamic_cast<SymLink*> (sym);
            //if (l)
            //{
            //    cout << "Symbol is link ";
            //    cout << l->target->name << endl;
            //}

        }

        if (type == Add)
        {
            ival = children.at(0)->ival + children.at(1)->ival;
        }
        if (type == Sub)
        {
            ival = children.at(0)->ival - children.at(1)->ival;
        }
        if (type == Mul)
        {
            ival = children.at(0)->ival * children.at(1)->ival;
        }
        if (type == Div)
        {
            if (children.at(1)->ival == 0) driver->error("Div by zero");
            else ival = children.at(0)->ival / children.at(1)->ival;
        }

        if (type == Gt)
        {
            if (children.at(0)->ival > children.at(1)->ival) ival = 1;
            else ival = 0;
        }
        if (type == Lt)
        {

            if (children.at(0)->ival < children.at(1)->ival) ival = 1;
            else ival = 0;
        }
        if (type == Not)
        {
            if (children.at(0)) ival = 0;
            else ival = 1;
        }

        if (type == Step)
        {
           this->ival = driver->g->Step();
        }

        if (type == Look)
        {
            driver->g->Look();
        }

        if (type == Left)
        {
            driver->g->Left();
        }

        if (type == Right)
        {
            driver->g->Right();
        }

        if (type == Back)
        {
            driver->g->Back();
        }

        if(type == OpSet)
        {
            this->sym2->m.Set(children.at(0)->ival, children.at(1)->ival, sym->Value());
        }

        if(type == OpEmp)
        {
            sym->SetValue(this->sym2->m.Emp(children.at(0)->ival, children.at(1)->ival));
        }

        if (type == OpBar)
        {
            sym->SetValue(this->sym2->m.Bar(children.at(0)->ival, children.at(1)->ival));
        }

        if (type == OpClr)
        {
            sym->m.Clr(children.at(0)->ival, children.at(1)->ival);
        }
        if (type == ProcDecl)
        {

        }
        if (type == ProcExec)
        {
            if (sym->numParam != this->paramList.size())
            {
                    driver->error("Arguments Error!");
                    return;
            }
            vector <Symbol *> tmp;
           /* for (int i = 0; i < sym->numParam; ++i)
            {
               Symbol *s = new SymLink(this->paramList.at(i), sym->paramNames.at(i));
               tmp.push_back(s);
            }

            driver->s.EnterFunction();
            driver->s.Show();
            //Symbol *s = tmp[0];
            //cout <<"Entering proc. Variables - " << driver->s.table.size() << endl;
            //cout << " First var - " << dynamic_cast<SymLink*>(s)->name <<
            //        " linked with " << dynamic_cast<SymLink*>(s)->target->name
            //        << " its value is " << s->Value();
            for (int i = 0; i < sym->numParam; ++i)
            {
                driver->s.AddSymbol(tmp.at(i));
            }
            */
            ////////////////////////
            // нечестно. ну и ладно
           //////////driver->s.EnterFunction();
            driver->s.EnterFunction();
            for (int i = 0; i < sym->paramNames.size(); ++i)
            {
                Symbol *s;
                s = new Symbol(false, sym->paramNames.at(i));
                driver->s.AddSymbol(s);


                s->SetValue(paramList.at(i)->Value());
                s->m = paramList.at(i)->m;
                s->type = paramList.at(i)->type;

                cout << "||"<<paramList.at(i)->name<<"|"<<paramList.at(i)->Value()
                        <<"|"<<  s->name << s->Value()<<"||"<<endl;
            }

            sym->procPointer->driver = driver;
            sym->procPointer->Do();
            vector <int> v;
            vector <Vmap> mm;
            for (int i = 0; i < sym->paramNames.size(); ++i)
            {
                v.push_back(driver->s.table[sym->paramNames.at(i)]->Value());
            }
            for (int i = 0; i < sym->paramNames.size(); ++i)
            {
                mm.push_back(driver->s.table[sym->paramNames.at(i)]->m);
            }
            /////
            driver->s.ExitFunction();
            for (int i = 0; i < sym->paramNames.size(); ++i)
            {
                paramList.at(i)->SetValue(v.at(i));
                 paramList.at(i)->m = mm.at(i);
            }
        }

}

Symbol::Symbol()
{

}

