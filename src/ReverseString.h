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
   char * nearIdeaData;
};


StrCompare* stringCompare(char* testStr,char *inputStr);//tested
char* find1stNonSpace(char * name);
int getWordLength(char* name);
char* createWordTolower(char* name , int length);
char* extractWork(char* name);
char* toLower(char * line);
void linkedListAddToHead(LinkedList* linkedList , ListItem* listItem);
void listInit(LinkedList* list);
void linkedListAddToTail(LinkedList * linkedList , ListItem* listItem);
StrCompare* getNameFormDictionaryAndCompare(ListItem * item, char* inputData);//testing
ListItem* searchItemFromDictionary(LinkedList * linkedList, char* inputData);//testing
#endif // _REVERSESTRING_H
