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

%token  ABSTRACT	/* abstract  */
%token	BREAK       /* break     */
%token	BY          /* by        */
%token	CASE        /* case      */
%token	CLASS       /* class     */
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
%token	CONSTRUCTOR /* constructor */
%token	LINK        /* link      */
%token	PRIVATE       /* private     */
%token	METHOD      /* method    */
%token	NEXT        /* next      */
%token	OF          /* of        */
%token  PUBLIC		/* public    */
%token  READ		/* read      */
%token	RECORD     /* record   */
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
%token  INVASSIGN	/* :- 		 */
%token	LTH         /* <         */
%token	AUGLTH      /* <:=       */
%token	LTHE        /* <=        */
%token	AUGLTHE     /* <=:=      */
%token	EQ       	/* =         */
%token	GTH         /* >         */
%token	AUGGTH      /* >:=       */
%token	GTHE        /* >=        */
%token	AUGGTHE     /* >=:=      */
%token	QMARK       /* ?         */
%token	AUGQMARK    /* ?:=       */
%token	BACKSLASH   /* \         */
%token	CARET       /* ^         */
%token	AUGCARET    /* ^:=       */
%token	BAR         /* |         */
%token	TILDE       /* ~         */
%token	NE          /* ~=        */
%token	AUGNE       /* ~=:=      */
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

%token	SND          /* @>       */
%token	SNDBK        /* @>>      */
%token	RCV          /* @<       */
%token	RCVBK        /* @<<      */

%token CONST		/* const 	*/
%token TOPIC		/* topic	*/

%token FUNK			/* 	f 	*/
%token CONASSIGN	/* :>	*/
%token STORE		/* store	*/

%token AT 			/*	@	*/
%token CREATE		/*	create	*/

%{

procedure Keyword(x1,x2)
	static 
		keywords
	
	local
		children
		
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
#	initial { set_of_all_fields := set(); dummyrecno := 1 }

#	if \iconc then {
#		if type(x3) == "token" then {
#			nsert(set_of_all_fields, x3.s)
#			write(&errout, "field ", image(x3.s))
#		}
#	}
#	children := [x1, x2, x3]
#	return node("field", children)
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
	# pe  istop set_package_level_syms
	local 
		pe
   
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
# idlist
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

decls : { 
		$$ := EmptyNode 
	} 
	| decls decl semiOptional {
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
	| import {	
		children := [$1]
		$$ := decl_node(children)
	}
	| classdef {	
		children := [$1]
		$$ := decl_node(children)
	}
	| invocDef { 
		children := [$1]
		$$ := methods_node(children) 
	}
	;

constructor: { 
		$$ := EmptyNode 
	}
	| CONSTRUCTOR locals methbody {
		children := [$1, $2, $3]
		$$ := constructor_node(2, children)
	}
	| CONSTRUCTOR LPAREN arglist RPAREN locals methbody {
		children := [$1, $2, $3, $4, $5, $6]
		$$ := constructor_node(4, children)
	}
	;

classdef : classhead locals methods constructor END {
		children := [$1, $2, $3, $4, $5]
		$$ := class_node(children)
	}
	;

classhead : storeFlag CLASS IDENT supers LPAREN arglist RPAREN {
		children := [$1,$2,$3, $4, "(",$6,")"]
		$$ := classhead_node(children)
	} 
	| storeFlag CLASS IDENT supers {
		children := [$1,$2,$3, $4]
		$$ := classhead_node(children)
	} 
	;

supers: { 
		$$ := EmptyNode 
	} 
	| COLON IDENT supers { 
		children := [":", $2, $3]
		$$ := supers_node(children) 
	}
	| COLON packageref supers { 
		children := [":", $2, $3]
		$$ := supers_node(children) 
	}
	;

packageref : IDENT COLONCOLON IDENT { 
		children := [$1,"::",$3]
		$$ := packageref_node(children) 
	} 
	| COLONCOLON expr { 
		children := ["::",$2]
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
	| locals SEMICOL methods { 
		children := [$1,$2,$3]
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
	| fact methods { 
		children := [$1,$2]
		$$ := methods_node(children) 
	}
	;
	
semiOptional : {
		$$ := semiOptional_node()
	}
	| SEMICOL {
		$$ := semiOptional_node()
	}
	;

import : IMPORT lnklist {
		children := [$1,$2]
		$$ := import_node(children)
	} 
	;

link : LINK lnklist { 
		children := [$1,$2]
		$$ := link_node(children)
	} 
	;

lnklist	: lnkfile {
		children := [$1]
		$$ := linklist_node(children)
	}
	| lnklist COMMA lnkfile { 
		children := [$1,",",$3]
		$$ := linklist_node(children)
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

global	: GLOBAL staticOption idlist { 
		children := [$1,$2]
		$$ := global_node(children) 
	} 
	| CONST constlist { 
		children := [$1,$2]
		$$ := const_node(children) 
	} 
	| PRIVATE staticOption idlist { 
		children := [$1,$2]
		$$ := topic_node(children) 
	} 
	;

constlist : constdef {
		children := [$1]
		$$ := constlist_node(children)
	}
	| constlist COMMA constdef {
		children := [$1, ",", $3]
		$$ := constlist_node(children)
	}
	;
	
constdef : IDENT ASSIGN literal {
		children := [$1, $2, $3]
		$$ := constdef_node(children)
	}
	;
	
record	: storeFlag RECORD IDENT LPAREN fldlist RPAREN {
		children := [$1,$2,$3,$4,$5]
		$$ := record_node(children)
	} 
	;
	
storeFlag : { 
		$$ := EmptyNode 
	}
	| STORE {
		children := [$1]
		$$ := store_node(children)
	}
	;

invocDef : IDENT INVASSIGN query {
		children := [$1,":-",$3]
		$$ := queryDef_node(children)
	}
	| IDENT INVASSIGN IDENT LPAREN exprlist RPAREN { 
		children := [$1,":-",$3, "(", $5, ")"]
		$$ := fact_node(children)
	}
	| IDENT INVASSIGN LBRACK expr RBRACK {
		children := [$1, $2]
		$$ := functionDef_node(children)
	}
	| IDENT INVASSIGN patternList semiOptional {
		children := [$1, ":-", "{", $4, "}"]
		$$ := patternDef_node(children)
	}
	;
	
query : LPAREN arglist RPAREN LBRACE exprlist RBRACE {
		children := ["(", $2, ")", ";", "{", $6, "}"]
		$$ := query_node(children)
	}
	| LPAREN arglist RPAREN IDENT LBRACE exprlist RBRACE {
		children := ["(", $2, ")", ";", $5, "(", $7, ")"]
		$$ := query_node(children)
	}
	;

patternList : {
		$$ := EmptyNode
	}
	| patternList expr : {
		children := [$1, $2]
		$$ := patternList_node(children)
	}
	;

fldlist : { 
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
	| methhead locals methbody END {
		children := [$1,$2,$3,$4]
		$$ := method_node(children)
	} 
	;

methhead: METHOD IDENT LPAREN arglist RPAREN {
		children := [$1,$2,"(",$4,")"]
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

idlist	: IDENT {
		children := [$1]
		$$ := idlist_node(children)
	}
	| idlist COMMA IDENT { 
		children := [$1,",",$3]
		$$ := idlist_node(children) 
	} 
	;

parmlist: arg {
		children := [$1]
		$$ := parmlist_node(children) 
	}
	| parmlist COMMA arg { 
		children := [$1,",",$3]
		$$ := parmlist_node(children) 
	} 
	;

arg	: IDENT {
		children := [$1]
		$$ := arg_node(1, children)
	}
	| IDENT COLON IDENT { 
		children := [$1, ":", $3]
		$$ := arg_node(2, children) 
	}
	| IDENT COLON literal { 
		children := [$1, ":", $3]
		$$ := arg_node(3, children) 
	}
	| IDENT COLON IDENT COLON literal { 
		children := [$1, ":", $3, ":", $5]
		$$ := arg_node(4, children) 
	} 
	;
	
locals	: { 
		$$ := EmptyNode
	}
	| locals retentions idlist semiOptional { 
		children := [$1,$2,$3,";"]
		$$ := locals_node(2, children)
	} 
	;

retentions: PRIVATE staticOption { 
		children := [$1, $2]
		$$ := local_node(children[1].string, children)
	} 
	| PUBLIC staticOption { 
		children := [$1, $2]
		$$ := local_node(children[1].string, children)
	} 

	| READ staticOption { 
		children := [$1, $2]
		$$ := local_node(children[1].string, children)
	} 
	;
	
staticOption : {
	$$ := EmptyNode
	}
	| STATIC { 
		children := [$1]
		$$ := static_node(children[1].string, children)
	}

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
	| expr2 ASSIGN expr1    { 
		children := [$1,$2,$3]
		$$ := assign_node(children)
	}
	| invocDef {
		children := [$1]
		$$ := invocAssign_node(children)
	}
	| expr2 CONASSIGN expr1 {
		children := [$1,$2,$3]
		$$ := condAssign_node(children)
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
	| expr2 AUGGTHE expr1   { 
		children := [$1,$2,$3]
		$$ := Baugge_node(children)
	}
	| expr2 AUGGTH expr1   { 
		children := [$1,$2,$3]
		$$ := Bauggt_node(children)
	}
	| expr2 AUGLTHE expr1   { 
		children := [$1,$2,$3]
		$$ := Baugle_node(children)
	}
	| expr2 AUGLTH expr1   { 
		children := [$1,$2,$3]
		$$ := Bauglt_node(children)
	}
	| expr2 AUGNE expr1   { 
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
	| expr4 GTHE expr5 { 
		children := [$1,$2,$3]
		$$ := Bge_node(children)
	}
	| expr4 GTH expr5 { 
		children := [$1,$2,$3]
		$$ := Bgt_node(children)
	}
	| expr4 LTHE expr5 { 
		children := [$1,$2,$3]
		$$ := Ble_node(children)
	}
	| expr4 LTH expr5 { 
		children := [$1,$2,$3]
		$$ := Blt_node(children)
	}
	| expr4 NE expr5 { 
		children := [$1,$2,$3]
		$$ := Bne_node(children)
	} 
	;

expr5	: expr7 
	| expr5 PLUS expr7 { 
		children := [$1,$2,$3]
		$$ := Bplus_node(children)
	}
	| expr5 DIFF expr7 { 
		children := [$1,$2,$3]
		$$ := Bdiff_node(children)
	}
	| expr5 UNION expr7 { 
		children := [$1,$2,$3]
		$$ := Bunion_node(children)
	}
	| expr5 MINUS expr7 { 
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
	| BAR expr10 { 
		children := [$1,$2]
		$$ := ubar_node(children)
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
	| NE expr10 { 
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
		children := [$1, "(", $3, ")"]
		$$ := invoke_node(children)
	}
	| expr11 COLON LPAREN exprlist RPAREN {
		children := [$1,":", "(", $4, ")"]
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
	| expr11 DOT CONSTRUCTOR { 
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
		children := [$1,":",$3]
		$$ := cclause_node(0, children)
	}
	| expr COLON expr { 
		children := [$1,":",$3]
		$$ := cclause_node(0, children)
	} 
	;

exprlist: nexpr {
		children := [$1]
		$$ := exprlist_node(children)
	}
	| exprlist COMMA nexpr {
		children := [$1,",",$3]
		$$ := exprlist_node(children)
	} 
	;

pdcolist: nexpr { 
		children := [$1]
		$$ := pdcolist_node(0, children) 
	}
	| pdcolist COMMA nexpr { 
		children := [$1,",",$3]
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

#procedure FieldRef(lhs, dot, rhs)
#	if /iconc | (type(lhs) ~== "treenode") then return Field(lhs, dot, rhs)

#	if (lhs.label == "invoke") then {
#		tmpcount +:= 1;
#		return node("Paren", "(",
#				node("assign", "__" || tmpcount, " := ", lhs, ")", "& "),
#				node("invoke", Field("__" || tmpcount, ".", rhs))
#			);
#	}
#	return Field(lhs, dot, rhs)
#end

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
