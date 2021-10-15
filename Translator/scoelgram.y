/*
 * NOTE: these %token declarations are generated
 *  automatically by mktoktab from tokens.txt and 
 *  op.txt.
 */

/* primitive tokens */

%token	IDENT
%token	INTLIT
%token	REALLIT
%token	STRINGLIT
%token	CSETLIT
%token	EOFX

/* reserved words */

%token	BREAK       /* break     */
%token	BY          /* by        */
%token	CASE        /* case      */
%token	CLASS       /* class     */
%token	CREATE      /* create    */
%token	CRITICAL    /* critical  */
%token	DEFAULT     /* default   */
%token	DO          /* do        */
%token	ELSE        /* else      */
%token	END         /* end       */
%token	EVERY       /* every     */
%token	FAIL        /* fail      */
%token	GLOBAL      /* global    */
%token	IF          /* if        */
%token  IMPORT      /* import    */
%token	iconINITIAL /* initial   */
%token	INITIALLY   /* initially */
%token	SUPER   	/* super	 */
%token	LINK        /* link      */
%token	LOCAL       /* local     */
%token	METHOD      /* method    */
%token	NEXT        /* next      */
%token	NOT         /* not       */
%token	OF          /* of        */
%token	PACKAGE     /* package   */
%token	RECORD      /* record    */
%token	REPEAT      /* repeat    */
%token	RETURN      /* return    */
%token	STATIC      /* static    */
%token	SUSPEND     /* suspend   */
%token	THEN        /* then      */
%token	THREAD      /* thread    */
%token	TO          /* to        */
%token	UNTIL       /* until     */
%token	WHILE       /* while     */

/* operators */

%token	BANG        /* !         */
%token	MOD         /* %         */
%token	AUGMOD      /* %:=       */
%token	AND         /* &         */
%token	AUGAND      /* &:=       */
%token	STAR        /* *         */
%token	AUGSTAR     /* *:=       */
%token	INTER       /* **        */
%token	AUGINTER    /* **:=      */
%token	PLUS        /* +         */
%token	AUGPLUS     /* +:=       */
%token	UNION       /* ++        */
%token	AUGUNION    /* ++:=      */
%token	MINUS       /* -         */
%token	AUGMINUS    /* -:=       */
%token	DIFF        /* --        */
%token	AUGDIFF     /* --:=      */
%token	DOT         /* .         */
%token	SLASH       /* /         */
%token	AUGSLASH    /* /:=       */
%token	ASSIGN      /* :=        */
%token  INVASSIGN	/* :- 		*/
%token	SWAP        /* :=:       */
%token	NMLT        /* <         */
%token	AUGNMLT     /* <:=       */
%token	REVASSIGN   /* <-        */
%token	REVSWAP     /* <->       */
%token	NMLE        /* <=        */
%token	AUGNMLE     /* <=:=      */
%token	EQ       	/* =         */
%token	AUGEQ       /* =:=       */
%token	NMGT        /* >         */
%token	AUGNMGT     /* >:=       */
%token	NMGE        /* >=        */
%token	AUGNMGE     /* >=:=      */
%token	QMARK       /* ?         */
%token	AUGQMARK    /* ?:=       */
%token	AT          /* @         */
%token	AUGAT       /* @:=       */
%token	BACKSLASH   /* \         */
%token	CARET       /* ^         */
%token	AUGCARET    /* ^:=       */
%token	BAR         /* |         */
%token	CONCAT      /* ||        */
%token	AUGCONCAT   /* ||:=      */
%token	TILDE       /* ~         */
%token	NMNE        /* ~=        */
%token	AUGNMNE     /* ~=:=      */
%token	LPAREN      /* (         */
%token	RPAREN      /* )         */
%token	PCOLON      /* +:        */
%token	COMMA       /* ,         */
%token	MCOLON      /* -:        */
%token	COLON       /* :         */
%token	COLONCOLON  /* ::        */
%token	SEMICOL     /* ;         */
%token	LBRACK      /* [         */
%token	RBRACK      /* ]         */
%token	LBRACE      /* {         */
%token	RBRACE      /* }         */

%token	DOLLAR      /* $         */
%token	ABSTRACT    /* abstract  */

%token  PCONDASSN	  /* => */
%token  PIMDASSN      /* -> */  
%token  PSETCUR       /* .> */  

%token	SND          /* @>       */
%token	SNDBK        /* @>>      */
%token	RCV          /* @<       */
%token	RCVBK        /* @<<      */

%{

procedure Keyword(x1,x2)
	static keywords
	initial {
		keywords := set(["allocated","clock","collections","column","current",
				"date","now","dateline","digits","e","error",
				"errornumber","errortext","errorvalue","errout","fail",
				"eventcode","eventsource","eventvalue","features",
				"file","host","input","lcase","letters","level",
				"line","main","null","output","phi","pi","pick","pos",
				"progname","random","regions","source","storage",
				"subject","time","trace","dump","ucase","version",
				"errno","window","col","row","x","y","interval",
				"control","shift","meta","lpress","mpress","rpress",
				"lrelease","mrelease","rrelease","ldrag","mdrag",
				"rdrag","resize","ascii","cset"])
	}

	# verify that x2 is a valid keyword
	if not member(keywords, x2.s) then
		yyerror("&" || x2.s ||" is not a valid keyword!")

	children := [x1, x2]
	return node("keyword", children)
end

global set_of_all_fields, dummyrecno
procedure Field(x1,x2,x3)
	initial { set_of_all_fields := set(); dummyrecno := 1 }

	if \iconc then {
		if type(x3) == "token" then {
			nsert(set_of_all_fields, x3.s)
#			write(&errout, "field ", image(x3.s))
		}
	}
	children := [x1, x2, x3]
	return node("field", children)
end

procedure Clone1stToken(n)
	case type(n) of {
		"token": return copy(n)
		"treenode": {
				return Clone1stToken(!n.children)
			}
	}
end

global outline, outcol, outfilename,package_level_syms,package_level_class_syms

procedure Progend(x1)
   
	if *\parsingErrors > 0 then {
		every pe := !parsingErrors do {
			write(&errout, pe.errorMessage)
		}
		istop(*\parsingErrors || " error" ||
				(if *\parsingErrors > 1 then "s" else ""))
	}

	if /x1 then istop("error: empty file")

	package_level_syms := set()
	package_level_class_syms := set()
	set_package_level_syms(x1)
	scopecheck_superclass_decs(x1)

	outline := 1
	outcol := 1
   #
   # export specifications for each class
   #
	native := set()
	every cl := classes.foreach_t() do {
		cl.WriteSpec()
		insert(native, cl)
	}
   #
   # import class specifications, transitively
   #
	repeat {
		added := 0
		every super := ((classes.foreach_t()).foreachsuper() | !imports) do {
			if /classes.lookup(super) then {
				added := 1
				readspec(super)
				cl := classes.lookup(super)
				if /cl then halt("can't inherit class '",super,"'")
				iwrite("  inherits ", super, " from ", cl.linkfile)
				writelink(cl.dir, cl.linkfile)
			}
		}
		if added = 0 then break
	}
  #
  # Compute the transitive closure of the superclass graph. Then
  # resolve inheritance for each class, and use it to apply scoping rules.
  #
	every (classes.foreach_t()).transitive_closure()
	every (classes.foreach_t()).resolve()

	scopecheck_bodies(x1)

	if \thePackage then {
		every thePackage.insertsym(!package_level_syms)
	}

	if \iconc then  {
		iconc_prep_parse_tree(&null, x1)
	}

  #
  # generate output
  #
#  iwrite("Generating code:")
	yyprint(x1)
	write(yyout)

   # generate invocable declarations for identifiers in unevaluated exprs
	if (*\list_of_invocables)>0 then {
		writes(yyout, "invocable ")
		every temp := list_of_invocables[i := 1 to *list_of_invocables] do {
			writes(yyout, image(temp))
			if i < *list_of_invocables then writes(yyout, ",")
		}
		write(yyout)
	}

	if \iconc & (type(set_of_all_fields) == "set") &
			(*set_of_all_fields > 0) then {
		arandomfield := !set_of_all_fields
		writes(yyout, "record __dummyrecord",dummyrecno,"(",arandomfield)
		delete(set_of_all_fields, arandomfield)
		every writes(yyout, ",", !set_of_all_fields)
		write(yyout, ")")
		dummyrecno +:= 1
		set_of_all_fields := set()
	}
end
%}

%%

/* 
 * scoelgram.y -- iYacc grammar for SCOEL
 *
 * This file is the iYacc input for building Icon-based Icon tools.
 */

program	: decls EOFX {	
		children := [$1]
		$$ := program_node(children)
	} 
	;

decls	: { 
		$$ := EmptyNode 
	} 
	| decls decl {
	   #if yynerrs = 0 then iwrites(&errout,".");
	   children := [$1, $2]
	   $$ := decls_node(children)
	} 
	;

decl	: record {	
		children := [$1]
		$$ := decl_node(children)
	}
	| global {	
		children := [$1]
		$$ := decl_node(children)
	}
	| link {	
		children := [$1]
		$$ := decl_node(children)
	}
	| package {	
		children := [$1]
		$$ := decl_node(children)
	}
	| import {	
		children := [$1]
		$$ := decl_node(children)
	}
	| classdef {	
		children := [$1]
		$$ := decl_node(children)
	}
	;

initiallysection: { 
		$$ := EmptyNode 
	}
	| INITIALLY SEMICOL locals initial methbody {
		children := [$1, $2, $3, $4, $5]
		$$ := initially_node(2, children)
	}
	| INITIALLY LPAREN arglist RPAREN SEMICOL locals initial methbody {
		children := [$1, $2, $3, $4, $5, $6, $7, $8]
		$$ := initially_node(4, children)
	}
	;

optsemi : { 
		$$ := optsemi_node() #EmptyNode 
	}  
    | SEMICOL {
		$$ := optsemi_node()
	}
	;

classdef : classhead optsemi locals methods optsemi initiallysection END {
		children := [$1, $3, $4, $6]
		$$ := class_node(children)
	}
	| classhead optsemi END {
		children := [$1, $2, $3]
		$$ := class_node(children)
	}
	;

classhead : CLASS IDENT supers {
		children := [$1,$2,$3]
		$$ := classhead_node(0, children)
	} 
	| CLASS IDENT supers LPAREN arglist RPAREN {
		children := [$1,$2,$3,$4,$5,$6]
		$$ := classhead_node(1, children)
	}
	;

supers: { 
		$$ := EmptyNode 
	} 
	| COLON IDENT supers { 
		children := [$1, $2, $3]
		$$ := supers_node(children) 
	}
	| COLON packageref supers { 
		children := [$1, $2, $3]
		$$ := supers_node(children) 
	}
	;

packageref : IDENT COLONCOLON IDENT { 
		children := [$1,$2,$3]
		$$ := packageref_node(children) 
	} 
	| COLONCOLON IDENT { 
		children := [$1,$2]
		$$ := packageref_node(children) 
	}  
	;

methods: { 
		$$ := EmptyNode 
	}
	| meth methods { 
		children := [$1,$2]
		$$ := methods_node(children) 
	}
	| global methods { 
		children := [$1,$2]
		$$ := methods_node(children) 
	}
	| record methods { 
		children := [$1,$2]
		$$ := methods_node(children) 
	}
	| invocDef methods { 
		children := [$1,$2]
		$$ := methods_node(children) 
	}
	;

package	: PACKAGE lnkfile {
		children := [$1,$2]
		$$ := package_node(children)
	} 
	;

import	: IMPORT lnklist {
		children := [$1,$2]
		$$ := import_node(children)
	} 
	;

link	: LINK lnklist { 
		children := [$1,$2]
		$$ := link_node(children)
	} 
	;

lnklist	: lnkfile {
		children := [$1]
		$$ := linklist_node(children)
	}
	| lnklist COMMA lnkfile { 
		children := [$1,$2,$3]
		$$ := linklist_node(children); 
	} 
	;

lnkfile	: IDENT {
		children := [$1]
		$$ := lnkfile_node(children)
	}
	| STRINGLIT {
		children := [$1]
		$$ := lnkfile_node(children)
	}
	;

global	: GLOBAL idlist { 
		children := [$1,$2]
		$$ := global_node(children) 
	} 
	;

record	: RECORD IDENT LPAREN fldlist RPAREN {
		children := [$1,$2,$3,$4,$5]
		$$ := record_node(children)
	} 
	;
	
invocDef : IDENT INVASSIGN expr { 
		children := [$1,$2,$3]
		$$ := invocDef_node(children)
	}
	;
	
fldlist	: { 
		$$ := EmptyNode 
	}
	| idlist {
		children := [$1]
		$$ := fldlist_node(children)
	}
	;

meth	: ABSTRACT methhead {
		children := [$1,$2]
		$$ := method_node(children)
	} 
	| methhead SEMICOL locals initial methbody END {
		children := [$1,$2,$3,$4,$5,$6]
		$$ := method_node(children)
	} 
	;

methhead: METHOD IDENT LPAREN arglist RPAREN {
		children := [$1,$2,$3,$4,$5]
		$$ := methhead_node(children)
	} 
	;

arglist	: { 
		$$ := EmptyNode 
	}
	| parmlist { 
		children := [$1]
		$$ := arglist_node(children) 
	}
	| parmlist LBRACK RBRACK { 
		children := [$1,$2,$3]
		$$ := arglist_node(children) 
	} 
	;

idlist	: IDENT 
	| idlist COMMA IDENT { 
		children := [$1,$2,$3]
		$$ := idlist_node(children) 
	} 
	;

parmlist: arg
	| parmlist COMMA arg { 
		children := [$1,$2,$3]
		$$ := parmlist_node(children) 
	} 
	;

arg	: IDENT {
		children := [$1]
		$$ := arg_node(1, children)
	}
	| IDENT COLON IDENT { 
		children := [$1, $2, $3]
		$$ := arg_node(2, children) 
	}
	| IDENT COLON literal { 
		children := [$1, $2, $3]
		$$ := arg_node(3, children) 
	}
	| IDENT COLON IDENT COLON literal { 
		children := [$1, $2, $3, $4, $5]
		$$ := arg_node(4, children) 
	} 
	;

locals	: { 
		$$ := EmptyNode
	}
	| locals retention idlist SEMICOL { 
		children := [$1,$2,$3,";"]
		$$ := locals_node(2, children)
	} 
	;

retention: LOCAL 
	| STATIC 
	;

initial	: { 
		$$ := EmptyNode 
	}
	| iconINITIAL expr SEMICOL {
		children := [$1, $2,";"]
		$$ := initial_node(children)
	} 
	;

methbody: { 
		$$ := EmptyNode 
	}
	| nexpr SEMICOL methbody { 
		children := [$1,";",$3]
		$$ := methbody_node(children)
	} 
	;

nexpr	: { 
		$$ := EmptyNode 
	}
	| expr {
		children := [$1]
		$$ := expr_node(children)
	}
	;

expr	: expr1
	| expr AND expr1	{ 
		children := [$1,$2,$3]
		$$ := and_node(children) 
	} 
	;

expr1	: expr2 
	| expr2 SWAP expr1      { 
		children := [$1,$2,$3]
		$$ := swap_node(children)
	}
	| expr2 ASSIGN expr1    { 
		children := [$1,$2,$3]
		$$ := assign_node(children)
	}
	| expr2 REVSWAP expr1   { 
		children := [$1,$2,$3]
		$$ := revswap_node(children)
	}
	| expr2 REVASSIGN expr1 { 
		children := [$1,$2,$3]
		$$ := revassign_node(children)
	}
	| expr2 AUGCONCAT expr1 { 
		children := [$1,$2,$3]
		$$ := augcat_node(children)
	}
	| expr2 AUGDIFF expr1   { 
		children := [$1,$2,$3]
		$$ := Bdiffa_node(children)
	}
	| expr2 AUGUNION expr1  { 
		children := [$1,$2,$3]
		$$ := Buniona_node(children)
	}
	| expr2 AUGPLUS expr1   { 
		children := [$1,$2,$3]
		$$ := Bplusa_node(children)
	}
	| expr2 AUGMINUS expr1  { 
		children := [$1,$2,$3]
		$$ := Bminusa_node(children)
	}
	| expr2 AUGSTAR expr1   { 
		children := [$1,$2,$3]
		$$ := Bstara_node(children)
	}
	| expr2 AUGINTER expr1  { 
		children := [$1,$2,$3]
		$$ := Bintera_node(children)
	}
	| expr2 AUGSLASH expr1  { 
		children := [$1,$2,$3]
		$$ := Bslasha_node(children)
	}
	| expr2 AUGMOD expr1    { 
		children := [$1,$2,$3]
		$$ := Bmoda_node(children)
	}
	| expr2 AUGCARET expr1  { 
		children := [$1,$2,$3]
		$$ := Bcareta_node(children)
	}
	| expr2 AUGEQ expr1   { 
		children := [$1,$2,$3]
		$$ := Baugeq_node(children)
	}
	| expr2 AUGNMGE expr1   { 
		children := [$1,$2,$3]
		$$ := Baugge_node(children)
	}
	| expr2 AUGNMGT expr1   { 
		children := [$1,$2,$3]
		$$ := Bauggt_node(children)
	}
	| expr2 AUGNMLE expr1   { 
		children := [$1,$2,$3]
		$$ := Baugle_node(children)
	}
	| expr2 AUGNMLT expr1   { 
		children := [$1,$2,$3]
		$$ := Bauglt_node(children)
	}
	| expr2 AUGNMNE expr1   { 
		children := [$1,$2,$3]
		$$ := Baugne_node(children)
	}
	| expr2 AUGQMARK expr1  { 
		children := [$1,$2,$3]
		$$ := Baugques_node(children)
	}
	| expr2 AUGAND expr1    { 
		children := [$1,$2,$3]
		$$ := Baugamper_node(children)
	}
	| expr2 AUGAT expr1     { 
		children := [$1,$2,$3]
		$$ := Baugact_node(children)
	} 
	;

expr2	: expr3
	| expr2 TO expr3 { 
		children := [$1,$2,$3]
		$$ := to_node("to", children)
	}
	| expr2 TO expr3 BY expr3 { 
		children := [$1,$2,$3,$4,$5]
		$$ := toby_node(children)
	}
	;

expr3	: expr4 
	| expr4 BAR expr3 {
		children := [$1,$2,$3]
		$$ := bar_node(children)
	} 
	;

expr4	: expr5 
	| expr4 EQ expr5 { 
		children := [$1,$2,$3]
		$$ := Beq_node(children)
	}
	| expr4 NMGE expr5 { 
		children := [$1,$2,$3]
		$$ := Bge_node(children)
	}
	| expr4 NMGT expr5 { 
		children := [$1,$2,$3]
		$$ := Bgt_node(children)
	}
	| expr4 NMLE expr5 { 
		children := [$1,$2,$3]
		$$ := Ble_node(children)
	}
	| expr4 NMLT expr5 { 
		children := [$1,$2,$3]
		$$ := Blt_node(children)
	}
	| expr4 NMNE expr5 { 
		children := [$1,$2,$3]
		$$ := Bne_node(children)
	} 
	;

expr5	: expr6 
	| expr5 CONCAT expr6 { 
		children := [$1,$2,$3]
		$$ := Bcat_node(children)
	} 
	;

expr6	: expr7 
	| expr6 PLUS expr7 { 
		children := [$1,$2,$3]
		$$ := Bplus_node(children)
	}
	| expr6 DIFF expr7 { 
		children := [$1,$2,$3]
		$$ := Bdiff_node(children)
	}
	| expr6 UNION expr7 { 
		children := [$1,$2,$3]
		$$ := Bunion_node(children)
	}
	| expr6 MINUS expr7 { 
		children := [$1,$2,$3]
		$$ := Bminus_node(children)
	} 
	;

expr7	: expr8
	| expr7 STAR expr8 { 
		children := [$1,$2,$3]
		$$ := Bstar_node(children)
	}
	| expr7 INTER expr8 { 
		children := [$1,$2,$3]
		$$ := Binter_node(children)
	}
	| expr7 SLASH expr8 { 
		children := [$1,$2,$3]
		$$ := Bslash_node(children)
	}
	| expr7 MOD expr8 { 
		children := [$1,$2,$3]
		$$ := Bmod_node(children)
	} 
	;

expr8	: expr9
	| expr9 CARET expr8 { 
		children := [$1,$2,$3]
		$$ := Bcaret_node(children)
	} 
	;

expr9	: expr10
	| expr9 BACKSLASH expr10 { 
		children := [$1,$2,$3]
		$$ := limit_node(children)
	}
	| expr9 AT expr10 { 
		children := [$1,$2,$3]
		$$ := at_node(children) 
	}
	| expr9 BANG expr10 { 
		children := [$1,$2,$3]
		$$ := apply_node(children)
	}
	;

expr10	: expr11
	| AT expr10 { 
		children := [$1,$2]
		$$ := uat_node(children)
	}
	| NOT expr10 { 
		children := [$1,$2]
		$$ := unot_node(children)
	}
	| BAR expr10 { 
		children := [$1,$2]
		$$ := ubar_node(children)
	}
	| CONCAT expr10 { 
		children := [$1,$2]
		$$ := uconcat_node(children)
	}
	| DOT expr10 { 
		children := [$1,$2]
		$$ := udot_node(children)
	}
	| BANG expr10 { 
		children := [$1,$2]
		$$ := ubang_node(children)
	}
	| DIFF expr10 { 
		children := [$1,$2]
		$$ := udiff_node(children)
	}
	| PLUS expr10 { 
		children := [$1,$2]
		$$ := uplus_node(children)
	}
	| STAR expr10 { 
		children := [$1,$2]
		$$ := ustar_node(children)
	}
	| SLASH expr10 { 
		children := [$1,$2]
		$$ := uslash_node(children)
	}
	| CARET expr10 { 
		children := [$1,$2]
		$$ := ucaret_node(children)
	}
	| INTER expr10 { 
		children := [$1,$2]
		$$ := uinter_node(children)
	}
	| TILDE expr10 { 
		children := [$1,$2]
		$$ := utilde_node(children)
	}
	| MINUS expr10 { 
		children := [$1,$2]
		$$ := uminus_node(children)
	}
	| EQ expr10 { 
		children := [$1,$2]
		$$ := unumeq_node(children)
	}
	| NMNE expr10 { 
		children := [$1,$2]
		$$ := unumne_node(children)
	}
	| UNION expr10 { 
		children := [$1,$2]
		$$ := uunion_node(children)
	}
	| QMARK expr10 { 
		children := [$1,$2]
		$$ := uqmark_node(children)
	}
	| BACKSLASH expr10 { 
		children := [$1,$2]
		$$ := ubackslash_node(children)
	} 
	;

expr11	: literal
	| section {
		children := [$1]
		$$ := section_node(children)
	}
	| return {
		children := [$1]
		$$ := return_node(children)
	}
	| if {
		children := [$1]
		$$ := if_node(children)
	}
	| case {
		children := [$1]
		$$ := case_node(children)
	}
	| while {
		children := [$1]
		$$ := while_node(children)
	}
	| until {
		children := [$1]
		$$ := until_node(children)
	}
	| every {
		children := [$1]
		$$ := every_node(children)
	}
	| repeat {
		children := [$1]
		$$ := repeat_node(children)
	}
	| CREATE expr { 
		children := [$1,$2]
		$$ := create_node(children)
	}
	| IDENT {
		children := [$1]
		$$ := ident_node(children)
	}
	| NEXT { 
		children := [$1]
		$$ := next_node(children)
	} 
	| BREAK nexpr { 
		children := [$1,$2]
		$$ := Break_node(children)
	}
	| LPAREN exprlist RPAREN { 
		children := [$1, $2, $3]
		$$ := Paren_node(children)
	}
	| LBRACE compound RBRACE { 
		children := [$1, $2, $3]
		$$ := Brace_node(children)
	}
	| LBRACK exprlist RBRACK { 
		children := [$1, $2, $3]
		$$ := Brack_node(children)
	} 
	| expr11 LBRACK exprlist RBRACK { 
		children := [$1, $2, $3, $4]
		$$ := Subscript_node(children)
	}
	| expr11 LBRACE	RBRACE { 
		children := [$1, $2, $3]
		$$ := Pdco_node(0, children)
	}
	| expr11 LBRACE pdcolist RBRACE { 
		children := [$1, $2, $3, $4]
		$$ := Pdco_node(1, children)
	}
	| expr11 LPAREN exprlist RPAREN { 
		children := [$1, $2, $3, $4]
		$$ := invoke_node(children)
	}
	| expr11 DOLLAR INITIALLY LPAREN exprlist RPAREN {
		children := [$1,$2,$3,$4,$5,$6]
		$$ := invocationnode(children)
	} 
	| expr11 DOLLAR IDENT LPAREN exprlist RPAREN {
		children := [$1,$2,$3,$4,$5,$6]
		$$ := invocationnode(children)
	}
	| expr11 DOLLAR IDENT DOT INITIALLY LPAREN exprlist RPAREN {
		children := [$1,$2,$3,$4,$5,$6,$7,$8]
		$$ := invocationnode(children)
	} 
	| expr11 DOLLAR IDENT DOT IDENT LPAREN exprlist RPAREN {
		children := [$1,$2,$3,$4,$5,$6,$7,$8]
		$$ := invocationnode(children)
	} 
	| expr11 DOT IDENT { 
		children := [$1,$2,$3]
		$$ := field_node(children)
	}
	| expr11 DOT packageref { 
		children := [$1,$2,$3]
		$$ := field_node(children)
	}
	| packageref {
		children := [$1]
		$$ := packageref_node(children)
	}
	| expr11 DOT INITIALLY { 
		children := [$1,$2,$3]
		$$ := field_node(children)
	}
	| AND FAIL { 
		children := [$1,$2]
		$$ := keyword_node(children)
	}
	| AND IDENT { 
		children := [$1,$2]
		$$ := keyword_node(children)
	} 
	;

while	: WHILE expr { 
		children := [$1,$2]
		$$ := While_node(0, children)
	}
	| WHILE expr DO expr { 
		children := [$1,$2,$3,$4]
		$$ := While_node(1, children)
	}
	;

until	: UNTIL expr { 
		children := [$1,$2]
		$$ := Until_node(0, children)
	}
	| UNTIL expr DO expr { 
		children := [$1,$2,$3,$4]
		$$ := Until_node(1, children)
	} 
	;

every	: EVERY expr { 
		children := [$1,$2]
		$$ := Every_node(0, children)
	}
	| EVERY expr DO expr { 
		children := [$1,$2,$3,$4]
		$$ := Every_node(1, children)
	} 
	;

repeat	: REPEAT expr { 
		children := [$1,$2]
		$$ := Repeat_node(0, children)
	} 
	;

return	: FAIL
	| RETURN nexpr { 
		children := [$1, $2]
		$$ := Return_node(0, children)
	} 
	| SUSPEND nexpr { 
		children := [$1,$2]
		$$ := Suspend_node(0, children)
	}
	| SUSPEND expr DO expr { 
		children := [$1,$2,$3,$4]
		$$ := Suspend_node(1, children)
	}
	;

if	: IF expr THEN expr { 
		children := [$1,$2,$3,$4]
		$$ := If_node(0, children)
	}
	| IF expr THEN expr ELSE expr { 
		children := [$1,$2,$3,$4,$5,$6]
		$$ := If_node(1, children)
	} 
	;

case	: CASE expr OF LBRACE caselist RBRACE { 
		children := [$1,$2,$3,$4,$5,$6]
		$$ := Case_node(0, children)
	} 
	;

caselist: cclause 
	| caselist SEMICOL cclause { 
		children := [$1,";",$3]
		$$ := caselist_node(children)
	} 
	;

cclause	: DEFAULT COLON expr { 
		children := [$1,$2,$3]
		$$ := cclause_node(0, children)
	}
	| expr COLON expr { 
		children := [$1,$2,$3]
		$$ := cclause_node(0, children)
	} 
	;

exprlist: nexpr {#exprlist_node
		children := [$1]
		$$ := exprlist_node(children)
	}
	| exprlist COMMA nexpr {
		if type($1)=="treenode" & ($1.label=="elst1") then {
			children := [$2, $3]
			$$ := $1; put($$.children, children)
		} else {
			children := [$1,$2,$3]
			$$ := elst_node(1, children)
		}
	} 
	;

pdcolist: nexpr { 
		children := [$1]
		$$ := pdcolist_node(0, children) 
	}
	| pdcolist COMMA nexpr { 
		children := [$1,$2,$3]
		$$ := pdcolist_node(1, children)
	} 
	;

literal	: INTLIT {
		children := [$1]
		$$ := intlit_node(children)
	}
	| REALLIT {
		children := [$1]
		$$ := reallit_node(children)
	}
	| STRINGLIT {
		children := [$1]
		$$ := stringlit_node(children)
	}
	| CSETLIT {
		children := [$1]
		$$ := csetlit_node(children)
	}
	;

section	: expr11 LBRACK expr sectop expr RBRACK { 
		children := [$1,$2,$3,$4,$5,$6]
		$$ := section_node(children)
	} 
	;

sectop	: COLON {
		children := [$1]
		$$ := colon_node(children)
	}
	| PCOLON {
		children := [$1]
		$$ := pcolon_node(children)
	}
	| MCOLON {
		children := [$1]
		$$ := mcolon_node(children)
	}
	;

compound: nexpr {
		children := [$1]
		$$ := compound_node(children)
	}
	| nexpr SEMICOL compound { 
		children := [$1,";",$3]
		$$ := compound_node(children)
	} 
	;

program	: error decls EOFX {
		children := [$1]
		$$ := program_node(children)
	}
	;
	
expr	: error { 
		$$ := error_node(); 
	} 
	;

%%

global tokens

#
# This procedure parenthesizes the right-hand side of an expression,
# apparently to simplify or correct any precedence or semantic issues
# when passing the code on to iconc.
#
procedure parenthesize_assign(nd)
	local rhs

	if /iconc then return nd
	if not (*nd.children = 3) then return nd
	rhs := nd.children[3]
	if (not(type(rhs) == "treenode")) then return nd
	if (not(rhs.label == "invoke")) then return nd
	rhs := node("Paren", "(", rhs, ")")
	nd.children[3] := rhs
	return nd
end

procedure FieldRef(lhs, dot, rhs)
	if /iconc | (type(lhs) ~== "treenode") then return Field(lhs, dot, rhs)

	if (lhs.label == "invoke") then {
		tmpcount +:= 1;
		return node("Paren", "(",
				node("assign", "__" || tmpcount, " := ", lhs, ")", "& "),
				node("invoke", Field("__" || tmpcount, ".", rhs))
			);
	}
	return Field(lhs, dot, rhs)
end

procedure InvocationNode(args[])
	tmpcount +:= 1
	if type(args[1]) == "token" & (args[1].tok = IDENT) then {
		n1 := args[1]
		lparen := copy(args[1])
		lparen.tok := LPAREN
		lparen.s := "("
	} else {
		n1 := node("Paren","(",node("assign","__"||tmpcount,":=",args[1]),")")
		if lparen := Clone1stToken(args[1]) then {
			lparen.tok := LPAREN
			lparen.s := "("
		} else lparen := "("
	}
	if *args = 6 then {
		return node("Paren",lparen,node("invoke",
				# iconc uses no __m business
				(if /iconc then Field(Field(n1, ".", "__m"), "." , args[3]) 
						else Field(n1, ".", args[3])),

				args[4], node("exprlist",
				if n1 === args[1] then args[1] else "__"||tmpcount,
				if args[5] === EmptyNode then EmptyNode else ",",args[5]),args[6])
				,")")
	} else {
		if /iconc then
			return  node("Paren",lparen,node("invoke",Field(Field(
					Field(n1,".", "__m"),
					"." , args[3]),".",args[5]),
					args[6], node("exprlist",
					if n1 === args[1] then args[1] else "__"||tmpcount,
					if args[7] === EmptyNode then EmptyNode else ",",args[7]),args[8])
					,")")
		else return SuperMethodInvok ! args
	}
end

procedure SimpleInvocation(expr11, lparen, args, rparen)
	if /iconc then return node("invoke", expr11, lparen, args, rparen)
	
	if ((type(expr11) == "token") & (expr11.tok = IDENT)) then {
		return node("invoke", expr11, lparen, args, rparen)
	}

	if (type(expr11) == "treenode") then {
		case expr11.label of {
			"field": {
				#
				# need to examine lhs of field-ref to determine
				# whether we need to decompose the expr11 further...
				#
				if (type(expr11.children[1]) == "treenode") then {
					tmpcount +:= 1;
					n1 := node("Paren", "(", node("assign", "__"||tmpcount, ":=",
							expr11.children[1]), ")")
					return node("exprlist", "(", n1, "&",
							node("invoke", Field("__"||tmpcount, ".", expr11.children[3]),
							lparen, args, rparen), ")")
				} else {
					return node("invoke", expr11, lparen, args, rparen)
				}
			}
			default: {
				return node("invoke", expr11, lparen, args, rparen)
			}
		}
	}
   return node("invoke", expr11, lparen, args, rparen)
end

procedure SuperMethodInvok(args[])
	tmpcount +:= 1
	if (type(args[1]) == "token") & (args[1].tok = IDENT) then {
		n1 := args[1]
		lparen := copy(args[1])
		lparen.tok := LPAREN
		lparen.s := "("
	} else {
		n1 := node("Paren","(",node("assign","__"||tmpcount,":=",args[1]),")")
		if lparen := Clone1stToken(args[1]) then {
			lparen.tok := LPAREN
			lparen.s := "("
		} else lparen := "("
	}

	args[3].s := mangle_class_sym(args[3].s)
	args[3].s ||:= "__oprec"
	return node("exprlist", "(", n1, ")", " & ",
			node("Paren", lparen, node("invoke",
			Field(args[3], ".", args[5]),
			args[6], node("exprlist",
			if n1 === args[1] then args[1] else "__" || tmpcount,
			if args[7] === EmptyNode then EmptyNode else ",", args[7]), args[8]),
			")", ))
end

procedure isloco(node, s)
	case type(node) of {
		"treenode": {
			if *node.children > 0 then return isloco(!node.children, s)
		}
		"token" : {
			if (node.tok = IDENT) & (node.s == s) then return
		}
	}
end

procedure buildtab_from_cclause(n, args)
	if type(n) ~== "treenode" then stop("bad table literal")
	comma := copy(n.children[2])
	comma.tok := COMMA
	comma.s := ","
	case n.label of {
		"cclause0": {
			if *args.children > 0 then push(args.children, comma)
			push(args.children, n.children[3])
		}
		"cclause1": {
			if *args.children > 0 then push(args.children, comma)
			push(args.children, n.children[3])
			push(args.children, comma)
			push(args.children, n.children[1])
		}
	}
end

# build a tree equivalent to
# {__tmp :=[]; every put(__tmp, expr); if __tmp>0 then __tmp}
# The enclosing procedure/method also needs to declare this temp var;
# see AppendListCompTemps
#
procedure ListComp(expr)
	local tmp
	tmpcount +:= 1
	tmp := "__" || tmpcount
	return node("ListComp",
			"{", string(tmp), " :=[]; every put(" || tmp || ", ",
			expr,
			"); if *" || tmp || ">0 then " || tmp || "}")
end

#
# AppendListCompTemps(localdecls, methbody) - at the procedure/method
# outermost level, we may need to add some declarations based on whats
# in the methbody. If there are changes to the declared lcls section,
# returns changed locals.
#
procedure AppendListCompTemps(lcls, body)
	# if there is, in the methbody, a list of varnames to declare
	if *\(ltmps := ListCompTemps(body)) > 0 then {
		# make a varlist containing ltmps
		if *ltmps > 1 then {
			vl := token(IDENT, ltmps[1], 0, 0, "lambda.icn")
			every i := 2 to *ltmps do vl := node("varlist3", vl, ",",
					token(IDENT, ltmps[i], 0, 0, "lambda.icn"))
		} else {
			# the varlist will just be an IDENT
			vl := token(IDENT, ltmps[1], 0, 0, "lambda.icn")
		}
		if (lcls === EmptyNode) |
				(type(lcls)==="treenode" & lcls.label==("locals2"|"locals3")) then {
			return node("locals2", lcls, "local", vl, ";")
		} else
			write(&errout, "don't know what to do with ", image(lcls))
	}
end

#
# ListCompTemps(n) - lower level temp. var extraction from proc body.
# returns list of strings containing temp. variables from list comprehension
# L
procedure ListCompTemps(n)
	local LCT
	if type(n) == "treenode" then {
		if n.label=="ListComp" then {
			LCT := [n.children[2]]
			LCT |||:= ListCompTemps(n.children[4])
			return LCT
		} else if LCT := ListCompTemps(n.children[k := 1 to *(n.children)]) then {
			every kk := k+1 to *(n.children) do {
				LCT |||:= ListCompTemps(n.children[kk])
			}
			return LCT
		}
	}
end

procedure tablelit(lb, cl, rb)
local tabid, lp, rp, args
	args := node("elst1")
	write("I am a tablelit, cl is ", image(cl.label))
	while type(cl)=="treenode" & cl.label == "Caselist" do {
		buildtab_from_cclause(cl.children[3], args)
		cl := cl.children[1]
	}
	buildtab_from_cclause(cl, args)
	tabid := copy(lb); tabid.tok := IDENT; tabid.s := "table"
	lp := copy(lb); lp.tok := LPAREN; lp.s := "("
	rp := copy(rb); rp.tok := RPAREN; rp.s := ")"
	return node("invoke", tabid, lp, args, rp)
end
