/* A Bison parser, made by GNU Bison 2.4.2.  */

/* Skeleton implementation for Bison LALR(1) parsers in C++
   
      Copyright (C) 2002-2010 Free Software Foundation, Inc.
   
   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.
   
   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.
   
   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.
   
   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */


/* First part of user declarations.  */


/* Line 310 of lalr1.cc  */
#line 39 "calc++-parser.tab.cc"


#include "calc++-parser.tab.hh"

/* User implementation prologue.  */


/* Line 316 of lalr1.cc  */
#line 48 "calc++-parser.tab.cc"
/* Unqualified %code blocks.  */

/* Line 317 of lalr1.cc  */
#line 37 "calc++-parser.yy"

# include "calc++-driver.hh"



/* Line 317 of lalr1.cc  */
#line 59 "calc++-parser.tab.cc"

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* FIXME: INFRINGES ON USER NAME SPACE */
#   define YY_(msgid) dgettext ("bison-runtime", msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(msgid) msgid
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#define YYUSE(e) ((void) (e))

/* Enable debugging if requested.  */
#if YYDEBUG

/* A pseudo ostream that takes yydebug_ into account.  */
# define YYCDEBUG if (yydebug_) (*yycdebug_)

# define YY_SYMBOL_PRINT(Title, Type, Value, Location)	\
do {							\
  if (yydebug_)						\
    {							\
      *yycdebug_ << Title << ' ';			\
      yy_symbol_print_ ((Type), (Value), (Location));	\
      *yycdebug_ << std::endl;				\
    }							\
} while (false)

# define YY_REDUCE_PRINT(Rule)		\
do {					\
  if (yydebug_)				\
    yy_reduce_print_ (Rule);		\
} while (false)

# define YY_STACK_PRINT()		\
do {					\
  if (yydebug_)				\
    yystack_print_ ();			\
} while (false)

#else /* !YYDEBUG */

# define YYCDEBUG if (false) std::cerr
# define YY_SYMBOL_PRINT(Title, Type, Value, Location)
# define YY_REDUCE_PRINT(Rule)
# define YY_STACK_PRINT()

#endif /* !YYDEBUG */

#define yyerrok		(yyerrstatus_ = 0)
#define yyclearin	(yychar = yyempty_)

#define YYACCEPT	goto yyacceptlab
#define YYABORT		goto yyabortlab
#define YYERROR		goto yyerrorlab
#define YYRECOVERING()  (!!yyerrstatus_)


namespace yy {

/* Line 379 of lalr1.cc  */
#line 125 "calc++-parser.tab.cc"
#if YYERROR_VERBOSE

  /* Return YYSTR after stripping away unnecessary quotes and
     backslashes, so that it's suitable for yyerror.  The heuristic is
     that double-quoting is unnecessary unless the string contains an
     apostrophe, a comma, or backslash (other than backslash-backslash).
     YYSTR is taken from yytname.  */
  std::string
  calcxx_parser::yytnamerr_ (const char *yystr)
  {
    if (*yystr == '"')
      {
        std::string yyr = "";
        char const *yyp = yystr;

        for (;;)
          switch (*++yyp)
            {
            case '\'':
            case ',':
              goto do_not_strip_quotes;

            case '\\':
              if (*++yyp != '\\')
                goto do_not_strip_quotes;
              /* Fall through.  */
            default:
              yyr += *yyp;
              break;

            case '"':
              return yyr;
            }
      do_not_strip_quotes: ;
      }

    return yystr;
  }

#endif

  /// Build a parser object.
  calcxx_parser::calcxx_parser (calcxx_driver& driver_yyarg)
    :
#if YYDEBUG
      yydebug_ (false),
      yycdebug_ (&std::cerr),
#endif
      driver (driver_yyarg)
  {
  }

  calcxx_parser::~calcxx_parser ()
  {
  }

#if YYDEBUG
  /*--------------------------------.
  | Print this symbol on YYOUTPUT.  |
  `--------------------------------*/

  inline void
  calcxx_parser::yy_symbol_value_print_ (int yytype,
			   const semantic_type* yyvaluep, const location_type* yylocationp)
  {
    YYUSE (yylocationp);
    YYUSE (yyvaluep);
    switch (yytype)
      {
        case 4: /* "\"identifier\"" */

/* Line 448 of lalr1.cc  */
#line 77 "calc++-parser.yy"
	{ debug_stream () << *(yyvaluep->sval); };

/* Line 448 of lalr1.cc  */
#line 202 "calc++-parser.tab.cc"
	break;
      case 5: /* "\"number\"" */

/* Line 448 of lalr1.cc  */
#line 79 "calc++-parser.yy"
	{ debug_stream () << (yyvaluep->ival); };

/* Line 448 of lalr1.cc  */
#line 211 "calc++-parser.tab.cc"
	break;
       default:
	  break;
      }
  }


  void
  calcxx_parser::yy_symbol_print_ (int yytype,
			   const semantic_type* yyvaluep, const location_type* yylocationp)
  {
    *yycdebug_ << (yytype < yyntokens_ ? "token" : "nterm")
	       << ' ' << yytname_[yytype] << " ("
	       << *yylocationp << ": ";
    yy_symbol_value_print_ (yytype, yyvaluep, yylocationp);
    *yycdebug_ << ')';
  }
#endif

  void
  calcxx_parser::yydestruct_ (const char* yymsg,
			   int yytype, semantic_type* yyvaluep, location_type* yylocationp)
  {
    YYUSE (yylocationp);
    YYUSE (yymsg);
    YYUSE (yyvaluep);

    YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

    switch (yytype)
      {
        case 4: /* "\"identifier\"" */

/* Line 479 of lalr1.cc  */
#line 78 "calc++-parser.yy"
	{ delete (yyvaluep->sval); };

/* Line 479 of lalr1.cc  */
#line 250 "calc++-parser.tab.cc"
	break;

	default:
	  break;
      }
  }

  void
  calcxx_parser::yypop_ (unsigned int n)
  {
    yystate_stack_.pop (n);
    yysemantic_stack_.pop (n);
    yylocation_stack_.pop (n);
  }

#if YYDEBUG
  std::ostream&
  calcxx_parser::debug_stream () const
  {
    return *yycdebug_;
  }

  void
  calcxx_parser::set_debug_stream (std::ostream& o)
  {
    yycdebug_ = &o;
  }


  calcxx_parser::debug_level_type
  calcxx_parser::debug_level () const
  {
    return yydebug_;
  }

  void
  calcxx_parser::set_debug_level (debug_level_type l)
  {
    yydebug_ = l;
  }
#endif

  int
  calcxx_parser::parse ()
  {
    /// Lookahead and lookahead in internal form.
    int yychar = yyempty_;
    int yytoken = 0;

    /* State.  */
    int yyn;
    int yylen = 0;
    int yystate = 0;

    /* Error handling.  */
    int yynerrs_ = 0;
    int yyerrstatus_ = 0;

    /// Semantic value of the lookahead.
    semantic_type yylval;
    /// Location of the lookahead.
    location_type yylloc;
    /// The locations where the error started and ended.
    location_type yyerror_range[2];

    /// $$.
    semantic_type yyval;
    /// @$.
    location_type yyloc;

    int yyresult;

    YYCDEBUG << "Starting parse" << std::endl;


    /* User initialization code.  */
    
/* Line 552 of lalr1.cc  */
#line 19 "calc++-parser.yy"
{
// Initialize the initial location.
yylloc.begin.filename = yylloc.end.filename = &driver.file;
}

/* Line 552 of lalr1.cc  */
#line 336 "calc++-parser.tab.cc"

    /* Initialize the stacks.  The initial state will be pushed in
       yynewstate, since the latter expects the semantical and the
       location values to have been already stored, initialize these
       stacks with a primary value.  */
    yystate_stack_ = state_stack_type (0);
    yysemantic_stack_ = semantic_stack_type (0);
    yylocation_stack_ = location_stack_type (0);
    yysemantic_stack_.push (yylval);
    yylocation_stack_.push (yylloc);

    /* New state.  */
  yynewstate:
    yystate_stack_.push (yystate);
    YYCDEBUG << "Entering state " << yystate << std::endl;

    /* Accept?  */
    if (yystate == yyfinal_)
      goto yyacceptlab;

    goto yybackup;

    /* Backup.  */
  yybackup:

    /* Try to take a decision without lookahead.  */
    yyn = yypact_[yystate];
    if (yyn == yypact_ninf_)
      goto yydefault;

    /* Read a lookahead token.  */
    if (yychar == yyempty_)
      {
	YYCDEBUG << "Reading a token: ";
	yychar = yylex (&yylval, &yylloc, driver);
      }


    /* Convert token to internal form.  */
    if (yychar <= yyeof_)
      {
	yychar = yytoken = yyeof_;
	YYCDEBUG << "Now at end of input." << std::endl;
      }
    else
      {
	yytoken = yytranslate_ (yychar);
	YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
      }

    /* If the proper action on seeing token YYTOKEN is to reduce or to
       detect an error, take that action.  */
    yyn += yytoken;
    if (yyn < 0 || yylast_ < yyn || yycheck_[yyn] != yytoken)
      goto yydefault;

    /* Reduce or error.  */
    yyn = yytable_[yyn];
    if (yyn <= 0)
      {
	if (yyn == 0 || yyn == yytable_ninf_)
	goto yyerrlab;
	yyn = -yyn;
	goto yyreduce;
      }

    /* Shift the lookahead token.  */
    YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);

    /* Discard the token being shifted.  */
    yychar = yyempty_;

    yysemantic_stack_.push (yylval);
    yylocation_stack_.push (yylloc);

    /* Count tokens shifted since error; after three, turn off error
       status.  */
    if (yyerrstatus_)
      --yyerrstatus_;

    yystate = yyn;
    goto yynewstate;

  /*-----------------------------------------------------------.
  | yydefault -- do the default action for the current state.  |
  `-----------------------------------------------------------*/
  yydefault:
    yyn = yydefact_[yystate];
    if (yyn == 0)
      goto yyerrlab;
    goto yyreduce;

  /*-----------------------------.
  | yyreduce -- Do a reduction.  |
  `-----------------------------*/
  yyreduce:
    yylen = yyr2_[yyn];
    /* If YYLEN is nonzero, implement the default value of the action:
       `$$ = $1'.  Otherwise, use the top of the stack.

       Otherwise, the following line sets YYVAL to garbage.
       This behavior is undocumented and Bison
       users should not rely upon it.  */
    if (yylen)
      yyval = yysemantic_stack_[yylen - 1];
    else
      yyval = yysemantic_stack_[0];

    {
      slice<location_type, location_stack_type> slice (yylocation_stack_, yylen);
      YYLLOC_DEFAULT (yyloc, slice, yylen);
    }
    YY_REDUCE_PRINT (yyn);
    switch (yyn)
      {
	  case 2:

/* Line 677 of lalr1.cc  */
#line 87 "calc++-parser.yy"
    {(yyval.node) = (yysemantic_stack_[(2) - (1)].node); (yyval.node)->Do();}
    break;

  case 3:

/* Line 677 of lalr1.cc  */
#line 89 "calc++-parser.yy"
    {(yyval.node) = (yysemantic_stack_[(1) - (1)].node);}
    break;

  case 4:

/* Line 677 of lalr1.cc  */
#line 90 "calc++-parser.yy"
    {(yyval.node) = SyntNode::CreateNode(&driver, Lines, (yysemantic_stack_[(2) - (1)].node), (yysemantic_stack_[(2) - (2)].node));}
    break;

  case 5:

/* Line 677 of lalr1.cc  */
#line 92 "calc++-parser.yy"
    {(yyval.node) = (yysemantic_stack_[(1) - (1)].node);}
    break;

  case 6:

/* Line 677 of lalr1.cc  */
#line 93 "calc++-parser.yy"
    {(yyval.node) = SyntNode::CreateNode(&driver, Lines, (yysemantic_stack_[(2) - (1)].node), (yysemantic_stack_[(2) - (2)].node));}
    break;

  case 7:

/* Line 677 of lalr1.cc  */
#line 95 "calc++-parser.yy"
    { //$$ = $2 + $3;
					(yyval.node) = SyntNode::CreateNode(&driver, Add, (yysemantic_stack_[(3) - (2)].node), (yysemantic_stack_[(3) - (3)].node));}
    break;

  case 8:

/* Line 677 of lalr1.cc  */
#line 97 "calc++-parser.yy"
    { //$$ = $2 - $3;
				(yyval.node) = SyntNode::CreateNode(&driver, Sub, (yysemantic_stack_[(3) - (2)].node), (yysemantic_stack_[(3) - (3)].node));}
    break;

  case 9:

/* Line 677 of lalr1.cc  */
#line 99 "calc++-parser.yy"
    { //$$ = $2 * $3; 
				(yyval.node) = SyntNode::CreateNode(&driver, Mul, (yysemantic_stack_[(3) - (2)].node), (yysemantic_stack_[(3) - (3)].node));}
    break;

  case 10:

/* Line 677 of lalr1.cc  */
#line 101 "calc++-parser.yy"
    { //$$ = $2 / $3; 
				(yyval.node) = SyntNode::CreateNode(&driver, Div, (yysemantic_stack_[(3) - (2)].node), (yysemantic_stack_[(3) - (3)].node));}
    break;

  case 11:

/* Line 677 of lalr1.cc  */
#line 107 "calc++-parser.yy"
    {
SyntNode *n	 = SyntNode::CreateNode(&driver, Add, (yysemantic_stack_[(3) - (2)].sym), (yysemantic_stack_[(3) - (3)].node));
(yyval.node) = SyntNode::CreateNode(&driver, (yysemantic_stack_[(3) - (2)].sym), n, true);
}
    break;

  case 12:

/* Line 677 of lalr1.cc  */
#line 111 "calc++-parser.yy"
    {
SyntNode *n	 = SyntNode::CreateNode(&driver, Add, (yysemantic_stack_[(3) - (2)].sym), (yysemantic_stack_[(3) - (3)].node));
(yyval.node) = SyntNode::CreateNode(&driver, (yysemantic_stack_[(3) - (2)].sym), n, true);
}
    break;

  case 13:

/* Line 677 of lalr1.cc  */
#line 117 "calc++-parser.yy"
    {(yyval.node) = SyntNode::CreateNode(&driver, Look, (SyntNode*)NULL, (SyntNode*)NULL); }
    break;

  case 14:

/* Line 677 of lalr1.cc  */
#line 118 "calc++-parser.yy"
    {(yyval.node) = SyntNode::CreateNode(&driver, (yysemantic_stack_[(1) - (1)].ival)); }
    break;

  case 15:

/* Line 677 of lalr1.cc  */
#line 119 "calc++-parser.yy"
    { (yyval.node) = SyntNode::CreateNode(&driver, (yysemantic_stack_[(1) - (1)].sym)); }
    break;

  case 16:

/* Line 677 of lalr1.cc  */
#line 120 "calc++-parser.yy"
    {(yyval.node) = SyntNode::CreateNode(&driver, (yysemantic_stack_[(1) - (1)].sym)->value);}
    break;

  case 17:

/* Line 677 of lalr1.cc  */
#line 121 "calc++-parser.yy"
    {//if($1) $$ = 1; else $$ = 0;
(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
}
    break;

  case 18:

/* Line 677 of lalr1.cc  */
#line 133 "calc++-parser.yy"
    {(yyval.node) = SyntNode::CreateNode(&driver, Gt, (yysemantic_stack_[(3) - (2)].node), (yysemantic_stack_[(3) - (3)].node));
//if ($2 > $3) $$ = true; else $$ = false;
 }
    break;

  case 19:

/* Line 677 of lalr1.cc  */
#line 136 "calc++-parser.yy"
    {(yyval.node) = SyntNode::CreateNode(&driver, Lt, (yysemantic_stack_[(3) - (2)].node), (yysemantic_stack_[(3) - (3)].node));
//if ($2 < $3) $$ = true; else $$ = false;
}
    break;

  case 20:

/* Line 677 of lalr1.cc  */
#line 139 "calc++-parser.yy"
    {(yyval.node) = SyntNode::CreateNode(&driver, Equal, (yysemantic_stack_[(3) - (2)].node), (yysemantic_stack_[(3) - (3)].node));
//if ($2 == $3) $$ = true; else $$ = false;
}
    break;

  case 21:

/* Line 677 of lalr1.cc  */
#line 142 "calc++-parser.yy"
    {(yyval.node) = SyntNode::CreateNode(&driver, Or, (yysemantic_stack_[(3) - (2)].node), (yysemantic_stack_[(3) - (3)].node));
//$$ = $2 || $3;
}
    break;

  case 22:

/* Line 677 of lalr1.cc  */
#line 145 "calc++-parser.yy"
    {(yyval.node) = SyntNode::CreateNode(&driver, Not, (yysemantic_stack_[(2) - (2)].node), (yysemantic_stack_[(2) - (2)].node));
//$$ = !$2;
}
    break;

  case 23:

/* Line 677 of lalr1.cc  */
#line 148 "calc++-parser.yy"
    {(yyval.node) = SyntNode::CreateNode(&driver, (yysemantic_stack_[(1) - (1)].sym));
//$$ = $1;
}
    break;

  case 24:

/* Line 677 of lalr1.cc  */
#line 151 "calc++-parser.yy"
    { (yyval.node) = SyntNode::CreateNode(&driver, Step, (SyntNode*)NULL, (SyntNode*)NULL);}
    break;

  case 25:

/* Line 677 of lalr1.cc  */
#line 152 "calc++-parser.yy"
    {(yyval.node) = SyntNode::CreateNode(&driver, (yysemantic_stack_[(1) - (1)].sym)->value);
//$$ = $1;
}
    break;

  case 26:

/* Line 677 of lalr1.cc  */
#line 155 "calc++-parser.yy"
    {(yyval.node) = SyntNode::CreateNode(&driver, 1);
//$$ = true;
}
    break;

  case 27:

/* Line 677 of lalr1.cc  */
#line 158 "calc++-parser.yy"
    {(yyval.node) = SyntNode::CreateNode(&driver, 0);
//$$ = false;
}
    break;

  case 28:

/* Line 677 of lalr1.cc  */
#line 162 "calc++-parser.yy"
    {(yyval.node) = (yysemantic_stack_[(2) - (1)].node);
// $1->Do();
}
    break;

  case 29:

/* Line 677 of lalr1.cc  */
#line 166 "calc++-parser.yy"
    {(yyval.node) = (yysemantic_stack_[(2) - (1)].node); 
//$1->Do(); 
}
    break;

  case 30:

/* Line 677 of lalr1.cc  */
#line 170 "calc++-parser.yy"
    {//$2->type = VAR_INT_TYPE; $2->value = $4; cout << "New int " <<
						//$2->name << " is " << $4 << endl;
						(yysemantic_stack_[(4) - (2)].sym)->type = VAR_INT_TYPE; (yyval.node) = SyntNode::CreateNode(&driver, (yysemantic_stack_[(4) - (2)].sym), (yysemantic_stack_[(4) - (4)].node));}
    break;

  case 31:

/* Line 677 of lalr1.cc  */
#line 173 "calc++-parser.yy"
    {
//$2->type = VAR_BOOL_TYPE; $2->value = $4; cout << "New bool " <<
	//					$2->name << " is " << $4 << endl;
	(yysemantic_stack_[(4) - (2)].sym)->type = VAR_BOOL_TYPE; (yyval.node) = SyntNode::CreateNode(&driver, (yysemantic_stack_[(4) - (2)].sym), (yysemantic_stack_[(4) - (4)].node));
}
    break;

  case 32:

/* Line 677 of lalr1.cc  */
#line 178 "calc++-parser.yy"
    {//$2->type = VAR_MAP_TYPE; cout << "New map " <<
			//			$2->name << endl;
			(yysemantic_stack_[(2) - (2)].sym)->type = VAR_MAP_TYPE; (yyval.node) = SyntNode::CreateNode(&driver, (yysemantic_stack_[(2) - (2)].sym), 0);
			}
    break;

  case 33:

/* Line 677 of lalr1.cc  */
#line 182 "calc++-parser.yy"
    {//$2->type = CONST_INT_TYPE; $2->value = $4; cout << "New const int " <<
					//	$2->name << " is " << $4 << endl;
					(yysemantic_stack_[(4) - (2)].sym)->type = CONST_INT_TYPE; (yyval.node) = SyntNode::CreateNode(&driver, (yysemantic_stack_[(4) - (2)].sym), (yysemantic_stack_[(4) - (4)].node));
					}
    break;

  case 34:

/* Line 677 of lalr1.cc  */
#line 186 "calc++-parser.yy"
    {
//$2->type = CONST_BOOL_TYPE; $2->value = $4; cout << "New const bool " <<
	//					$2->name << " is " << $4 << endl;
	(yysemantic_stack_[(4) - (2)].sym)->type = CONST_BOOL_TYPE; (yyval.node) = SyntNode::CreateNode(&driver, (yysemantic_stack_[(4) - (2)].sym), (yysemantic_stack_[(4) - (4)].node));
	}
    break;

  case 35:

/* Line 677 of lalr1.cc  */
#line 191 "calc++-parser.yy"
    {//$1->value = $3; cout << "assign " <<
						//$1->name << " value " << $3 << endl;
						(yyval.node) = SyntNode::CreateNode(&driver, (yysemantic_stack_[(3) - (1)].sym), (yysemantic_stack_[(3) - (3)].node), true);}
    break;

  case 36:

/* Line 677 of lalr1.cc  */
#line 194 "calc++-parser.yy"
    {
(yyval.node) = SyntNode::CreateNode(&driver, While, (yysemantic_stack_[(4) - (2)].node), (yysemantic_stack_[(4) - (4)].node));
}
    break;

  case 37:

/* Line 677 of lalr1.cc  */
#line 197 "calc++-parser.yy"
    { (yyval.node) = SyntNode::CreateNode(&driver, Back, (SyntNode*)NULL, (SyntNode*)NULL);  }
    break;

  case 38:

/* Line 677 of lalr1.cc  */
#line 198 "calc++-parser.yy"
    { (yyval.node) = SyntNode::CreateNode(&driver, Left, (SyntNode*)NULL, (SyntNode*)NULL);}
    break;

  case 39:

/* Line 677 of lalr1.cc  */
#line 199 "calc++-parser.yy"
    { (yyval.node) = SyntNode::CreateNode(&driver, Right, (SyntNode*)NULL, (SyntNode*)NULL);}
    break;

  case 40:

/* Line 677 of lalr1.cc  */
#line 201 "calc++-parser.yy"
    {
driver.s.EnterFunction();
cout << "Entering new namespace. Variables - " << driver.s.table.size() << endl; 
Symbol * s;
for (int i = 0; i < (yysemantic_stack_[(5) - (4)].node)->paramList.size(); ++i )
{
s = new Symbol(true, (yysemantic_stack_[(5) - (4)].node)->paramList.at(i)->name);
//		driver.s.AddSymbol(s);
//s = new Symbol(false, );
		driver.s.AddSymbol(s);
//		s->name = $4->paramList.at(i)->name;
		s->type = VAR_INT_TYPE;
		cout << "Local variable " << s->name <<". "<< endl;
		}
}
    break;

  case 41:

/* Line 677 of lalr1.cc  */
#line 216 "calc++-parser.yy"
    {(yyval.node) = SyntNode::CreateNode(&driver, (yysemantic_stack_[(7) - (2)].sym), (yysemantic_stack_[(7) - (4)].node), (yysemantic_stack_[(7) - (7)].node));
driver.s.ExitFunction();
}
    break;

  case 42:

/* Line 677 of lalr1.cc  */
#line 219 "calc++-parser.yy"
    {(yyval.node) = SyntNode::CreateNode(&driver, ProcExec, (yysemantic_stack_[(4) - (1)].sym), (yysemantic_stack_[(4) - (3)].node));}
    break;

  case 43:

/* Line 677 of lalr1.cc  */
#line 220 "calc++-parser.yy"
    {(yyval.node) = SyntNode::CreateNode(&driver, OpBar, (yysemantic_stack_[(7) - (3)].sym),(yysemantic_stack_[(7) - (4)].sym),(yysemantic_stack_[(7) - (5)].node),(yysemantic_stack_[(7) - (6)].node));}
    break;

  case 44:

/* Line 677 of lalr1.cc  */
#line 221 "calc++-parser.yy"
    {(yyval.node) = SyntNode::CreateNode(&driver, OpEmp, (yysemantic_stack_[(7) - (3)].sym),(yysemantic_stack_[(7) - (4)].sym),(yysemantic_stack_[(7) - (5)].node),(yysemantic_stack_[(7) - (6)].node));}
    break;

  case 45:

/* Line 677 of lalr1.cc  */
#line 222 "calc++-parser.yy"
    {(yyval.node) = SyntNode::CreateNode(&driver, OpSet, (yysemantic_stack_[(7) - (3)].sym),(yysemantic_stack_[(7) - (4)].sym),(yysemantic_stack_[(7) - (5)].node),(yysemantic_stack_[(7) - (6)].node));}
    break;

  case 46:

/* Line 677 of lalr1.cc  */
#line 223 "calc++-parser.yy"
    {(yyval.node) = SyntNode::CreateNode(&driver, OpClr, (yysemantic_stack_[(6) - (3)].sym),NULL,(yysemantic_stack_[(6) - (4)].node),(yysemantic_stack_[(6) - (5)].node));}
    break;

  case 47:

/* Line 677 of lalr1.cc  */
#line 224 "calc++-parser.yy"
    {(yyval.node) = (yysemantic_stack_[(2) - (2)].node);}
    break;

  case 48:

/* Line 677 of lalr1.cc  */
#line 225 "calc++-parser.yy"
    {cout << "IF exp matched ELSE matched"
									<< endl;
									(yyval.node) = SyntNode::CreateNode(&driver, If, (yysemantic_stack_[(5) - (2)].node), (yysemantic_stack_[(5) - (3)].node));
									(yyval.node)->children.push_back((yysemantic_stack_[(5) - (5)].node));
									}
    break;

  case 49:

/* Line 677 of lalr1.cc  */
#line 231 "calc++-parser.yy"
    {cout << " IF exp matched " << endl;
			(yyval.node) = SyntNode::CreateNode(&driver, If, (yysemantic_stack_[(3) - (2)].node), (yysemantic_stack_[(3) - (3)].node));
			}
    break;

  case 50:

/* Line 677 of lalr1.cc  */
#line 234 "calc++-parser.yy"
    {cout << "IF exp unmatched" << endl;
		  (yyval.node) = SyntNode::CreateNode(&driver, If, (yysemantic_stack_[(3) - (2)].node), (yysemantic_stack_[(3) - (3)].node));}
    break;

  case 51:

/* Line 677 of lalr1.cc  */
#line 236 "calc++-parser.yy"
    {cout << "IF exp matched ELSE un"
											<< endl;
			(yyval.node) = SyntNode::CreateNode(&driver, If, (yysemantic_stack_[(5) - (2)].node), (yysemantic_stack_[(5) - (3)].node));
									(yyval.node)->children.push_back((yysemantic_stack_[(5) - (5)].node));
		}
    break;

  case 52:

/* Line 677 of lalr1.cc  */
#line 243 "calc++-parser.yy"
    { (yyval.node) = (yysemantic_stack_[(1) - (1)].node);}
    break;

  case 53:

/* Line 677 of lalr1.cc  */
#line 244 "calc++-parser.yy"
    {(yyval.node) = (yysemantic_stack_[(1) - (1)].node);}
    break;

  case 54:

/* Line 677 of lalr1.cc  */
#line 247 "calc++-parser.yy"
    { (yyval.node) = SyntNode::CreateNode(&driver, (yysemantic_stack_[(1) - (1)].sym), true, true);}
    break;

  case 55:

/* Line 677 of lalr1.cc  */
#line 248 "calc++-parser.yy"
    { (yyval.node) = SyntNode::CreateNode(&driver, (yysemantic_stack_[(1) - (1)].sym), true, true);}
    break;

  case 56:

/* Line 677 of lalr1.cc  */
#line 249 "calc++-parser.yy"
    {
(yyval.node) = SyntNode::CreateNode(&driver, (yysemantic_stack_[(2) - (2)].sym), (yysemantic_stack_[(2) - (1)].node), true, true);
}
    break;

  case 57:

/* Line 677 of lalr1.cc  */
#line 252 "calc++-parser.yy"
    {
(yyval.node) = SyntNode::CreateNode(&driver, (yysemantic_stack_[(2) - (2)].sym), (yysemantic_stack_[(2) - (1)].node), true, true);
}
    break;

  case 58:

/* Line 677 of lalr1.cc  */
#line 257 "calc++-parser.yy"
    { (yyval.node) = SyntNode::CreateNode(&driver, (yysemantic_stack_[(1) - (1)].sym), true, true);}
    break;

  case 59:

/* Line 677 of lalr1.cc  */
#line 258 "calc++-parser.yy"
    {
(yyval.node) = SyntNode::CreateNode(&driver, (yysemantic_stack_[(2) - (2)].sym), (yysemantic_stack_[(2) - (1)].node), true, true);
}
    break;

  case 60:

/* Line 677 of lalr1.cc  */
#line 262 "calc++-parser.yy"
    {(yyval.node) = (yysemantic_stack_[(1) - (1)].node);}
    break;

  case 61:

/* Line 677 of lalr1.cc  */
#line 263 "calc++-parser.yy"
    {(yyval.node) = (yysemantic_stack_[(3) - (2)].node);}
    break;



/* Line 677 of lalr1.cc  */
#line 962 "calc++-parser.tab.cc"
	default:
          break;
      }
    YY_SYMBOL_PRINT ("-> $$ =", yyr1_[yyn], &yyval, &yyloc);

    yypop_ (yylen);
    yylen = 0;
    YY_STACK_PRINT ();

    yysemantic_stack_.push (yyval);
    yylocation_stack_.push (yyloc);

    /* Shift the result of the reduction.  */
    yyn = yyr1_[yyn];
    yystate = yypgoto_[yyn - yyntokens_] + yystate_stack_[0];
    if (0 <= yystate && yystate <= yylast_
	&& yycheck_[yystate] == yystate_stack_[0])
      yystate = yytable_[yystate];
    else
      yystate = yydefgoto_[yyn - yyntokens_];
    goto yynewstate;

  /*------------------------------------.
  | yyerrlab -- here on detecting error |
  `------------------------------------*/
  yyerrlab:
    /* If not already recovering from an error, report this error.  */
    if (!yyerrstatus_)
      {
	++yynerrs_;
	error (yylloc, yysyntax_error_ (yystate, yytoken));
      }

    yyerror_range[0] = yylloc;
    if (yyerrstatus_ == 3)
      {
	/* If just tried and failed to reuse lookahead token after an
	 error, discard it.  */

	if (yychar <= yyeof_)
	  {
	  /* Return failure if at end of input.  */
	  if (yychar == yyeof_)
	    YYABORT;
	  }
	else
	  {
	    yydestruct_ ("Error: discarding", yytoken, &yylval, &yylloc);
	    yychar = yyempty_;
	  }
      }

    /* Else will try to reuse lookahead token after shifting the error
       token.  */
    goto yyerrlab1;


  /*---------------------------------------------------.
  | yyerrorlab -- error raised explicitly by YYERROR.  |
  `---------------------------------------------------*/
  yyerrorlab:

    /* Pacify compilers like GCC when the user code never invokes
       YYERROR and the label yyerrorlab therefore never appears in user
       code.  */
    if (false)
      goto yyerrorlab;

    yyerror_range[0] = yylocation_stack_[yylen - 1];
    /* Do not reclaim the symbols of the rule which action triggered
       this YYERROR.  */
    yypop_ (yylen);
    yylen = 0;
    yystate = yystate_stack_[0];
    goto yyerrlab1;

  /*-------------------------------------------------------------.
  | yyerrlab1 -- common code for both syntax error and YYERROR.  |
  `-------------------------------------------------------------*/
  yyerrlab1:
    yyerrstatus_ = 3;	/* Each real token shifted decrements this.  */

    for (;;)
      {
	yyn = yypact_[yystate];
	if (yyn != yypact_ninf_)
	{
	  yyn += yyterror_;
	  if (0 <= yyn && yyn <= yylast_ && yycheck_[yyn] == yyterror_)
	    {
	      yyn = yytable_[yyn];
	      if (0 < yyn)
		break;
	    }
	}

	/* Pop the current state because it cannot handle the error token.  */
	if (yystate_stack_.height () == 1)
	YYABORT;

	yyerror_range[0] = yylocation_stack_[0];
	yydestruct_ ("Error: popping",
		     yystos_[yystate],
		     &yysemantic_stack_[0], &yylocation_stack_[0]);
	yypop_ ();
	yystate = yystate_stack_[0];
	YY_STACK_PRINT ();
      }

    yyerror_range[1] = yylloc;
    // Using YYLLOC is tempting, but would change the location of
    // the lookahead.  YYLOC is available though.
    YYLLOC_DEFAULT (yyloc, (yyerror_range - 1), 2);
    yysemantic_stack_.push (yylval);
    yylocation_stack_.push (yyloc);

    /* Shift the error token.  */
    YY_SYMBOL_PRINT ("Shifting", yystos_[yyn],
		     &yysemantic_stack_[0], &yylocation_stack_[0]);

    yystate = yyn;
    goto yynewstate;

    /* Accept.  */
  yyacceptlab:
    yyresult = 0;
    goto yyreturn;

    /* Abort.  */
  yyabortlab:
    yyresult = 1;
    goto yyreturn;

  yyreturn:
    if (yychar != yyempty_)
      yydestruct_ ("Cleanup: discarding lookahead", yytoken, &yylval, &yylloc);

    /* Do not reclaim the symbols of the rule which action triggered
       this YYABORT or YYACCEPT.  */
    yypop_ (yylen);
    while (yystate_stack_.height () != 1)
      {
	yydestruct_ ("Cleanup: popping",
		   yystos_[yystate_stack_[0]],
		   &yysemantic_stack_[0],
		   &yylocation_stack_[0]);
	yypop_ ();
      }

    return yyresult;
  }

  // Generate an error message.
  std::string
  calcxx_parser::yysyntax_error_ (int yystate, int tok)
  {
    std::string res;
    YYUSE (yystate);
#if YYERROR_VERBOSE
    int yyn = yypact_[yystate];
    if (yypact_ninf_ < yyn && yyn <= yylast_)
      {
	/* Start YYX at -YYN if negative to avoid negative indexes in
	   YYCHECK.  */
	int yyxbegin = yyn < 0 ? -yyn : 0;

	/* Stay within bounds of both yycheck and yytname.  */
	int yychecklim = yylast_ - yyn + 1;
	int yyxend = yychecklim < yyntokens_ ? yychecklim : yyntokens_;
	int count = 0;
	for (int x = yyxbegin; x < yyxend; ++x)
	  if (yycheck_[x + yyn] == x && x != yyterror_)
	    ++count;

	// FIXME: This method of building the message is not compatible
	// with internationalization.  It should work like yacc.c does it.
	// That is, first build a string that looks like this:
	// "syntax error, unexpected %s or %s or %s"
	// Then, invoke YY_ on this string.
	// Finally, use the string as a format to output
	// yytname_[tok], etc.
	// Until this gets fixed, this message appears in English only.
	res = "syntax error, unexpected ";
	res += yytnamerr_ (yytname_[tok]);
	if (count < 5)
	  {
	    count = 0;
	    for (int x = yyxbegin; x < yyxend; ++x)
	      if (yycheck_[x + yyn] == x && x != yyterror_)
		{
		  res += (!count++) ? ", expecting " : " or ";
		  res += yytnamerr_ (yytname_[x]);
		}
	  }
      }
    else
#endif
      res = YY_("syntax error");
    return res;
  }


  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
  const signed char calcxx_parser::yypact_ninf_ = -82;
  const short int
  calcxx_parser::yypact_[] =
  {
       185,   -46,   -39,   -38,   -33,   -28,    98,   137,    98,   -82,
     -82,   -82,   -21,    -8,     1,     2,     4,    29,    12,    39,
      -3,   -82,   -82,   -82,    21,    37,    41,   -82,    46,    53,
     -82,   -82,   -82,    17,    32,   -82,    98,   -82,    75,    75,
      98,    98,    98,    98,    98,    98,   -82,   -82,   -82,   -82,
      60,   -82,    98,   209,   -82,   -82,   185,    49,    35,    44,
      45,    42,    98,    -1,   -82,   -82,   -82,   -82,    98,    75,
      98,    75,    98,    98,    98,   -82,    75,    98,    98,    98,
      98,    98,    98,   137,   209,   161,   -82,    54,    73,   -82,
      43,    48,    50,    51,    98,   -82,   -82,   -82,   -82,    55,
       7,   -82,   -82,   -82,   -82,   -82,   -82,   -82,   -82,   -82,
     -82,   -82,   -82,   -82,   -82,   -82,    81,   -82,   -82,   -82,
     185,   -34,    98,    98,    98,    98,   -82,   -82,   -82,   -82,
     209,   -82,   -82,   -82,    98,    98,    98,    62,   137,    64,
      67,    68,   -82,   -82,   -82,   -82,   -82
  };

  /* YYDEFACT[S] -- default rule to reduce with in state S when YYTABLE
     doesn't specify something else to do.  Zero means the default is an
     error.  */
  const unsigned char
  calcxx_parser::yydefact_[] =
  {
         0,     0,     0,     0,     0,     0,     0,     0,     0,    37,
      39,    38,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     5,    52,    53,     0,     0,     0,    32,     0,     0,
      14,    26,    27,     0,     0,    24,     0,    13,     0,     0,
       0,     0,     0,     0,     0,     0,    15,    16,    23,    25,
       0,    17,     0,     0,    60,    47,     0,     0,     0,     0,
       0,     0,     0,     0,     1,     2,     6,    28,     0,     0,
       0,     0,     0,     0,     0,    22,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     3,     0,    49,    50,
       0,     0,     0,     0,     0,    35,    54,    55,    58,     0,
       0,    30,    31,    33,    34,    11,    12,    20,    21,    18,
      19,     7,     8,     9,    10,    36,     0,    61,     4,    29,
       0,     0,     0,     0,     0,     0,    42,    57,    56,    59,
       0,    48,    51,    40,     0,     0,     0,     0,     0,     0,
       0,     0,    46,    41,    43,    44,    45
  };

  /* YYPGOTO[NTERM-NUM].  */
  const signed char
  calcxx_parser::yypgoto_[] =
  {
       -82,   -82,   -82,   -82,    -7,    10,   105,    52,     0,   -82,
     -52,   -82,   -82,    36,   -81
  };

  /* YYDEFGOTO[NTERM-NUM].  */
  const short int
  calcxx_parser::yydefgoto_[] =
  {
        -1,    19,    85,    20,    50,    51,    21,    86,    54,   138,
      23,    24,    99,   100,    55
  };

  /* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule which
     number is the opposite.  If zero, do what YYDEFACT says.  */
  const signed char calcxx_parser::yytable_ninf_ = -1;
  const unsigned char
  calcxx_parser::yytable_[] =
  {
        22,    56,   115,    65,    89,    25,   133,     1,     2,     3,
       4,     5,    26,    27,     6,     7,     8,   129,    28,     9,
      22,    10,    11,    29,    12,    13,    14,    15,    16,    74,
      57,    58,    62,    77,    78,    79,    80,    81,    82,    64,
      59,    60,    17,    61,    96,    84,    97,    18,    75,    76,
      98,    63,   127,    87,   128,    95,    88,   143,   129,    67,
      68,   101,    72,   103,    69,   105,   106,   107,   132,    70,
     109,   110,   111,   112,   113,   114,    71,    73,    83,   102,
      91,   104,    31,    32,   116,    87,   108,   125,    90,    92,
      93,    94,   119,   120,    98,   126,    35,   122,    36,   123,
     124,   130,   142,    30,   144,    31,    32,   145,   146,    38,
      39,    40,    41,    33,    34,   134,   135,   136,   137,    35,
     131,    36,    48,    49,    37,    66,   121,   139,   140,   141,
     131,     0,    38,    39,    40,    41,     0,   118,     0,    42,
      43,    44,    45,    46,    47,    48,    49,     1,     2,     3,
       4,     5,     0,     0,     6,     7,    52,     0,     0,     9,
       0,    10,    11,     0,    12,    13,    14,    15,    16,    53,
       0,     1,     2,     3,     4,     5,     0,     0,     6,     7,
      52,     0,    17,     9,     0,    10,    11,    18,    12,    13,
      14,    15,    16,     0,   117,     1,     2,     3,     4,     5,
       0,     0,     6,     7,     8,     0,    17,     9,     0,    10,
      11,    18,    12,    13,    14,    15,    16,     0,     0,     1,
       2,     3,     4,     5,     0,     0,     6,     7,    52,     0,
      17,     9,     0,    10,    11,    18,    12,    13,    14,    15,
      16,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    17,     0,     0,     0,     0,    18
  };

  /* YYCHECK.  */
  const short int
  calcxx_parser::yycheck_[] =
  {
         0,     8,    83,     6,    56,    51,    40,    10,    11,    12,
      13,    14,    51,    51,    17,    18,    19,    51,    51,    22,
      20,    24,    25,    51,    27,    28,    29,    30,    31,    36,
      51,    39,     3,    40,    41,    42,    43,    44,    45,     0,
      39,    39,    45,    39,    45,    52,    47,    50,    38,    39,
      51,    39,    45,    53,    47,    62,    56,   138,    51,    38,
      23,    68,    45,    70,    23,    72,    73,    74,   120,    23,
      77,    78,    79,    80,    81,    82,    23,    45,    18,    69,
      45,    71,     7,     8,    84,    85,    76,    94,    39,    45,
      45,    49,    38,    20,    51,    40,    21,    49,    23,    49,
      49,    20,    40,     5,    40,     7,     8,    40,    40,    34,
      35,    36,    37,    15,    16,   122,   123,   124,   125,    21,
     120,    23,    47,    48,    26,    20,    90,   134,   135,   136,
     130,    -1,    34,    35,    36,    37,    -1,    85,    -1,    41,
      42,    43,    44,    45,    46,    47,    48,    10,    11,    12,
      13,    14,    -1,    -1,    17,    18,    19,    -1,    -1,    22,
      -1,    24,    25,    -1,    27,    28,    29,    30,    31,    32,
      -1,    10,    11,    12,    13,    14,    -1,    -1,    17,    18,
      19,    -1,    45,    22,    -1,    24,    25,    50,    27,    28,
      29,    30,    31,    -1,    33,    10,    11,    12,    13,    14,
      -1,    -1,    17,    18,    19,    -1,    45,    22,    -1,    24,
      25,    50,    27,    28,    29,    30,    31,    -1,    -1,    10,
      11,    12,    13,    14,    -1,    -1,    17,    18,    19,    -1,
      45,    22,    -1,    24,    25,    50,    27,    28,    29,    30,
      31,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    45,    -1,    -1,    -1,    -1,    50
  };

  /* STOS_[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
  const unsigned char
  calcxx_parser::yystos_[] =
  {
         0,    10,    11,    12,    13,    14,    17,    18,    19,    22,
      24,    25,    27,    28,    29,    30,    31,    45,    50,    53,
      55,    58,    60,    62,    63,    51,    51,    51,    51,    51,
       5,     7,     8,    15,    16,    21,    23,    26,    34,    35,
      36,    37,    41,    42,    43,    44,    45,    46,    47,    48,
      56,    57,    19,    32,    60,    66,    56,    51,    39,    39,
      39,    39,     3,    39,     0,     6,    58,    38,    23,    23,
      23,    23,    45,    45,    56,    57,    57,    56,    56,    56,
      56,    56,    56,    18,    56,    54,    59,    60,    60,    62,
      39,    45,    45,    45,    49,    56,    45,    47,    51,    64,
      65,    56,    57,    56,    57,    56,    56,    56,    57,    56,
      56,    56,    56,    56,    56,    66,    60,    33,    59,    38,
      20,    65,    49,    49,    49,    56,    40,    45,    47,    51,
      20,    60,    62,    40,    56,    56,    56,    56,    61,    56,
      56,    56,    40,    66,    40,    40,    40
  };

#if YYDEBUG
  /* TOKEN_NUMBER_[YYLEX-NUM] -- Internal symbol number corresponding
     to YYLEX-NUM.  */
  const unsigned short int
  calcxx_parser::yytoken_number_[] =
  {
         0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305,   306
  };
#endif

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
  const unsigned char
  calcxx_parser::yyr1_[] =
  {
         0,    52,    53,    54,    54,    55,    55,    56,    56,    56,
      56,    56,    56,    56,    56,    56,    56,    56,    57,    57,
      57,    57,    57,    57,    57,    57,    57,    57,    58,    59,
      60,    60,    60,    60,    60,    60,    60,    60,    60,    60,
      61,    60,    60,    60,    60,    60,    60,    60,    60,    62,
      62,    62,    63,    63,    64,    64,    64,    64,    65,    65,
      66,    66
  };

  /* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
  const unsigned char
  calcxx_parser::yyr2_[] =
  {
         0,     2,     2,     1,     2,     1,     2,     3,     3,     3,
       3,     3,     3,     1,     1,     1,     1,     1,     3,     3,
       3,     3,     2,     1,     1,     1,     1,     1,     2,     2,
       4,     4,     2,     4,     4,     3,     4,     1,     1,     1,
       0,     7,     4,     7,     7,     7,     6,     2,     5,     3,
       3,     5,     1,     1,     1,     1,     2,     2,     1,     2,
       1,     3
  };

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
  /* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
     First, the terminals, then, starting at \a yyntokens_, nonterminals.  */
  const char*
  const calcxx_parser::yytname_[] =
  {
    "\"end of file\"", "error", "$undefined", "\":=\"", "\"identifier\"",
  "\"number\"", "EOP", "TRUe", "FALSe", "THEN", "INT", "BOOLEAN", "MAP",
  "CINT", "CBOOLEAN", "INC", "DEC", "WHILE", "DO", "IF", "ELSE", "STEP",
  "BACK", "EQUAL", "RIGHT", "LEFT", "LOOK", "PROC", "BAR", "EMP", "SET",
  "CLR", "STARTSENT", "ENDSENT", "NOT", "OR", "GT", "LT", "ENDL",
  "STARTPARAM", "ENDPARAM", "ADD", "SUB", "MUL", "DIV", "VARINT",
  "CONSTINT", "VARBOOL", "CONSTBOOL", "VARMAP", "PROCID", "ID", "$accept",
  "unit", "linesm", "lines", "exp", "boolexp", "line", "linem", "matched",
  "$@1", "unmatched", "stmt", "parameterscall", "parameters", "blockm", 0
  };
#endif

#if YYDEBUG
  /* YYRHS -- A `-1'-separated list of the rules' RHS.  */
  const calcxx_parser::rhs_number_type
  calcxx_parser::yyrhs_[] =
  {
        53,     0,    -1,    55,     6,    -1,    59,    -1,    54,    59,
      -1,    58,    -1,    55,    58,    -1,    41,    56,    56,    -1,
      42,    56,    56,    -1,    43,    56,    56,    -1,    44,    56,
      56,    -1,    15,    45,    56,    -1,    16,    45,    56,    -1,
      26,    -1,     5,    -1,    45,    -1,    46,    -1,    57,    -1,
      36,    56,    56,    -1,    37,    56,    56,    -1,    23,    56,
      56,    -1,    35,    57,    57,    -1,    34,    57,    -1,    47,
      -1,    21,    -1,    48,    -1,     7,    -1,     8,    -1,    63,
      38,    -1,    60,    38,    -1,    10,    51,    23,    56,    -1,
      11,    51,    23,    57,    -1,    12,    51,    -1,    13,    51,
      23,    56,    -1,    14,    51,    23,    57,    -1,    45,     3,
      56,    -1,    17,    56,    18,    66,    -1,    22,    -1,    25,
      -1,    24,    -1,    -1,    27,    51,    39,    65,    40,    61,
      66,    -1,    50,    39,    64,    40,    -1,    28,    39,    45,
      49,    56,    56,    40,    -1,    29,    39,    45,    49,    56,
      56,    40,    -1,    30,    39,    45,    49,    56,    56,    40,
      -1,    31,    39,    49,    56,    56,    40,    -1,    18,    66,
      -1,    19,    56,    60,    20,    60,    -1,    19,    56,    60,
      -1,    19,    56,    62,    -1,    19,    56,    60,    20,    62,
      -1,    60,    -1,    62,    -1,    45,    -1,    47,    -1,    65,
      47,    -1,    65,    45,    -1,    51,    -1,    65,    51,    -1,
      60,    -1,    32,    54,    33,    -1
  };

  /* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
     YYRHS.  */
  const unsigned char
  calcxx_parser::yyprhs_[] =
  {
         0,     0,     3,     6,     8,    11,    13,    16,    20,    24,
      28,    32,    36,    40,    42,    44,    46,    48,    50,    54,
      58,    62,    66,    69,    71,    73,    75,    77,    79,    82,
      85,    90,    95,    98,   103,   108,   112,   117,   119,   121,
     123,   124,   132,   137,   145,   153,   161,   168,   171,   177,
     181,   185,   191,   193,   195,   197,   199,   202,   205,   207,
     210,   212
  };

  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
  const unsigned short int
  calcxx_parser::yyrline_[] =
  {
         0,    87,    87,    89,    90,    92,    93,    95,    97,    99,
     101,   107,   111,   117,   118,   119,   120,   121,   133,   136,
     139,   142,   145,   148,   151,   152,   155,   158,   162,   166,
     170,   173,   178,   182,   186,   191,   194,   197,   198,   199,
     201,   200,   219,   220,   221,   222,   223,   224,   225,   231,
     234,   236,   243,   244,   247,   248,   249,   252,   257,   258,
     262,   263
  };

  // Print the state stack on the debug stream.
  void
  calcxx_parser::yystack_print_ ()
  {
    *yycdebug_ << "Stack now";
    for (state_stack_type::const_iterator i = yystate_stack_.begin ();
	 i != yystate_stack_.end (); ++i)
      *yycdebug_ << ' ' << *i;
    *yycdebug_ << std::endl;
  }

  // Report on the debug stream that the rule \a yyrule is going to be reduced.
  void
  calcxx_parser::yy_reduce_print_ (int yyrule)
  {
    unsigned int yylno = yyrline_[yyrule];
    int yynrhs = yyr2_[yyrule];
    /* Print the symbols being reduced, and their result.  */
    *yycdebug_ << "Reducing stack by rule " << yyrule - 1
	       << " (line " << yylno << "):" << std::endl;
    /* The symbols being reduced.  */
    for (int yyi = 0; yyi < yynrhs; yyi++)
      YY_SYMBOL_PRINT ("   $" << yyi + 1 << " =",
		       yyrhs_[yyprhs_[yyrule] + yyi],
		       &(yysemantic_stack_[(yynrhs) - (yyi + 1)]),
		       &(yylocation_stack_[(yynrhs) - (yyi + 1)]));
  }
#endif // YYDEBUG

  /* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
  calcxx_parser::token_number_type
  calcxx_parser::yytranslate_ (int t)
  {
    static
    const token_number_type
    translate_table[] =
    {
           0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51
    };
    if ((unsigned int) t <= yyuser_token_number_max_)
      return translate_table[t];
    else
      return yyundef_token_;
  }

  const int calcxx_parser::yyeof_ = 0;
  const int calcxx_parser::yylast_ = 259;
  const int calcxx_parser::yynnts_ = 15;
  const int calcxx_parser::yyempty_ = -2;
  const int calcxx_parser::yyfinal_ = 64;
  const int calcxx_parser::yyterror_ = 1;
  const int calcxx_parser::yyerrcode_ = 256;
  const int calcxx_parser::yyntokens_ = 52;

  const unsigned int calcxx_parser::yyuser_token_number_max_ = 306;
  const calcxx_parser::token_number_type calcxx_parser::yyundef_token_ = 2;


} // yy

/* Line 1053 of lalr1.cc  */
#line 1522 "calc++-parser.tab.cc"


/* Line 1055 of lalr1.cc  */
#line 269 "calc++-parser.yy"

void
yy::calcxx_parser::error (const yy::calcxx_parser::location_type& l,
const std::string& m)
{
driver.error (l, m);
}

//© Дмитрий Утямишев, 2011
