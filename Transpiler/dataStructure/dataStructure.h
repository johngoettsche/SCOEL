
#include <stdio.h>


/* DATA TYPES */
#define T_NULL 0;
#define T_INTEGER 1;
#define T_LARGEINT 2
#define T_REAL 3;
#define T_FILE 4;
#define T_CHARSTR 5;

#define T_RECORD 6;
#define T_CLASS 7;

#define T_FACT 8;
#define T_QUERY 9;
#define T_RULE 10;
#define T_PATTERN 11;
#define T_PELEM 12;
#define T_FUNC 13;

#define T_METHOD 14;

#define T_SET 15;
#define T_SELEM 16;
#define T_TABLE 17;
#define T_TELEM 18;
#define T_LIST 19;
#define T_LELEM 20;
#define T_SLOTS 21;
#define T_KEYWORD 22;

typedef int word;

/* words */
struct desc_word { /* d-word structure 32 bits */
	unsigned int nFlag:1; 
	unsigned int pFlag:1;
	unsigned int vFlag:1;
	unsigned int tFlag:1;
	unsigned int data-type:(sizeof(word) - 4); 
};

/* Descriptors */
struct descriptor {
	struct desc_word dWord;
	union {
		word integr;
		char *stringPtr;
		union block *blockPtr;
		descriptor *descPtr;
	} vWord;
};

/* Blocks */
union block {
	struct bReal realBlock;
	struct bFile file;
	struct bCharStr charStr;
	
	struct bRecord record;
	struct bClass clas;
	struct bConstruct constructor;
	
	struct bFact fact;
	struct bQuery query;
	struct bRule rule;
	struct bPattern pattern;
	struct bPElem pElem;
	struct bFunction function;
	
	struct bMethod method;
	
	struct bSet set;
	struct bSElem sElem;
	struct bTable table;
	struct bTElem tElem;
	struct bList list;
	struct bLElem lElem;
	struct bSlot slot;
	struct bKeyword keyword;
};

struct bCharStr {
	word title;
	word size;
	unsigned int bits[1];
};

struct bRecord {
	word title;
	word size;
	struct descriptor constructor;
	struct descriptor fields[1];
};

struct bClass {	
	word title;
	word size;
	word store;
	struct descriptor construct;
	word nParents;
	struct descriptor parents[1];;
	word nVars;
	struct descriptor vars[1];
	word nMethods;
	struct descriptor methods[1];
};

struct bConstruct { 
	word title;
	word size;
	struct descriptor constructor;
	struct descriptor *initIPC;
	word args;
	word locIdent;
	word statIdent;
	word firstIdent;
	struct descriptor *clas;
};

struct bFact {
	word title;
	union {
		struct bRecord;
		struct bClass;
	} fact;
	struct descriptor *clas;
};

struct bFact {
	word title;
	union block fact;
	struct descriptor *clas;
};

struct bQuery {
	word title;
	word size;
	struct descriptor *initIPC;
	word args;
	word locIdent;
	word statIdent;
	word firstIdent;
	struct descriptor *clas;
};

struct bRule {
	word title;
	word size;
	struct descriptor *initIPC;
	word args;
	word locIdent;
	word statIdent;
	word firstIdent;
	struct descriptor *clas;
};

struct bPattern {
	word title;
	word size;
	union block *pat;
	struct descriptor *clas;
};

struct bPElem {
	word title;
	word size;
	struct descriptor construct;
	word nParents;
	struct descriptor parents[1];
	word nVars;
	struct descriptor vars[1];
	word nMethods;
	struct descriptor methods[1];
	struct descriptor *clas;
};

struct bFunction {
	word title;
	word size;
	struct descriptor *initIPC;
	word args;
	word locIdent;
	word statIdent;
	word firstIdent;
	struct descriptor *clas;
};

struct bMethod {
	word title;
	word size;
	struct descriptor *initIPC;
	word args;
	word locIdent;
	word statIdent;
	word firstIdent;
	struct descriptor *clas;
};

struct bSet {
	word title;
	word size;
	struct descriptor slot[1];
};

struct bSElem {
	word title;
	word hash;
	union block *next;
	struct descriptor value;
	
};

struct bTable {
	word title;
	word size;
	struct descriptor def;
	struct descriptor slot[1];
};

struct bTElem {
	word title;
	word hash;
	union block *next;
	struct descriptor entry;
	struct descriptor assign;
};

struct bList {
	word title;
	word size;
	word id;
	union block *head;
	union block *tail;
};

struct bLElem {
	word title;
	word blocksize;
	word nslots;
	word first;
	word nused;
	union block *prevelem;
	union block *nextelem;
	struct descriptor slot[1];
};





