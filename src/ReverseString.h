#ifndef _REVERSESTRING_H
#define _REVERSESTRING_H

#include	<stdio.h>
#include	<stdarg.h>
#include	<malloc.h>
#include	<stdlib.h>
#include	<string.h>
#include	<math.h>
#include 	<ctype.h>
#include 	<Exception.h>
#include 	"Exception.h"
#include 	"CException.h"

#define ADD_HEAD 0
#define ADD_TAIL 1

typedef struct ListItem ListItem;
struct ListItem{
	ListItem *next;
	ListItem *pervious;
	void *data;
};

typedef struct LinkedList LinkedList;
struct LinkedList{
	ListItem *head;
	ListItem *tail;
	int count;
};

typedef struct Dictionary Dictionary;
struct Dictionary{
   char *name;
   char *defination;
};
 
typedef struct StrCompare StrCompare;
struct StrCompare{
   int trueFalse;
   int sensitivity;
   char * nearIdaeData;
};


int stringCompare(char* testStr,char *inputStr);

#endif // _REVERSESTRING_H
