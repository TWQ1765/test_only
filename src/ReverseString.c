#include "ReverseString.h"
#include <stdio.h>
#include <string.h>
#include <malloc.h>
/*
 * has modify test:
 * 1.) void test_stringCompare_given_string_diffrent_length_expect_return_False(void) 
 * 2.) void test_getNameFormDictionaryAndCompare...
 * 3.) adding new function findHighest sensitivity work.
 * 4.) test_stringCompare_given_string_diffrent_length_expect_return_TRUE
 */

//can be improve by adding sensitivity
StrCompare* stringCompare(char* testStr,char *inputStr){
	int i=0;
	//reinitialise sturct value
	StrCompare dataStore;
	dataStore.trueFalse=0;
	dataStore.sensitivity=0;
	dataStore.nearIdeaData=NULL;

	StrCompare* dataStorePtr = &dataStore;
	int tempTrueFalse = dataStorePtr->trueFalse;
	//char* tempNearIdaeData = dataStorePtr->nearIdaeData;
	//printf("tempNearIdaeData=%s\n",tempNearIdaeData);
	
	while((testStr[i]!='\0') || (inputStr[i]!='\0')){
		if((testStr[i]) != (inputStr[i])){
			dataStorePtr->trueFalse = 0;
			dataStorePtr->sensitivity = i;
			dataStore.nearIdeaData=testStr;
			return dataStorePtr;
		}else{
			i++;
		}
	}
	dataStorePtr->trueFalse = 1;
	return dataStorePtr;
}

/* true  = 1 , compare result same string.
 * flase = 0 , compare result not same string.
 * function needed:
 * 1.) extractWork
 * 2.) toLower
 * 3.) stringCompare
 */
StrCompare* getNameFormDictionaryAndCompare(ListItem * item, char* inputData){
	char * tempData1 = ((Dictionary*)(item->data))->name;//get data from item
	char * tempData2 = extractWork(tempData1);
	char * tempDataResult = toLower(tempData2);
	char * inputData1 = extractWork(inputData);
	char * inputDataResult = toLower(inputData1);
	StrCompare* result = stringCompare(tempDataResult,inputDataResult);
	return result;
}
/* data search for linkedList which void* data point to structure type
 * return the item address.
 * function needed:
 * 1.) getNameFormDictionaryAndCompare;
 */
ListItem* searchItemFromDictionary(LinkedList * linkedList, char* inputData){
	char* error = inputData;
	LinkedList* tempList = linkedList;
	
	if (linkedList->head == NULL){
		throwError(1,"ERROR %d: '%s' is not found in the Dictionary.",1,(error));
	}else{
		ListItem* tempItem = tempList->head;
		StrCompare* strCompare = getNameFormDictionaryAndCompare(tempItem,inputData);
		char* myIdeaData = ((Dictionary*)(tempList->head->data))->name;//
		int sensitivityPerv = (strCompare->sensitivity);//1st compare
		while(((strCompare->trueFalse)!=1) && (tempItem!=(tempList->tail))){//check until tail
		
			printf("sensitivityPerv=%d\n",sensitivityPerv);//5
			tempItem = tempItem->next;
			strCompare = getNameFormDictionaryAndCompare(tempItem,inputData);
			
			//char* nearIdea = ((Dictionary*)(tempItem->data))->name;
			
			printf("strCompare=%d\n",strCompare->sensitivity);//0
			
			if((sensitivityPerv > (strCompare->sensitivity)) && (sensitivityPerv != (strCompare->sensitivity))){// is(5>0)? yes
				sensitivityPerv = sensitivityPerv;
				printf("sensitivityPerv2=%d\n",sensitivityPerv);
				myIdeaData = myIdeaData;//strCompare->nearIdeaData;
				
				
			}else{
				sensitivityPerv = (strCompare->sensitivity); 
				printf("sensitivityPerv3=%d\n",sensitivityPerv);//5
				myIdeaData = strCompare->nearIdeaData;
			}
		}
		//sensitivityPerv = get mostIdeaData;
		strCompare = getNameFormDictionaryAndCompare(tempItem,inputData);//check tail
		if((strCompare->trueFalse)!=1){
			throwError(1,"ERROR %d: '%s' is not found in the Dictionary. Do you mean %s?",1,(error),myIdeaData);
		}else{
			return tempItem;
		}
	}
}

char* findNearIdeaData(StrCompare* strCompare){
	
	
}

char* find1stNonSpace(char * name){//no cahnge
	char * namePtr = name;
	int i = 0;
	while((namePtr[i] == ' ') && (namePtr[i] != '\0')){
		i++;
	}
	return namePtr = namePtr + i;
}
int getWordLength(char* name){//no cahnge
	char * namePtr = find1stNonSpace(name);
	int i = 0;
	while((namePtr[i] != ' ') && (namePtr[i] != '\0')){
		i++;
	}
	return i;
}
char* createWordTolower(char* name , int length){//no cahnge
	int i = 0;
	char * work = (char *)malloc(length+1);
	while ((name[i] != ' ') && (name[i] != '\0')){
		work[i] = (tolower(name[i]));
		i++;
	}
	work[i]='\0';
	return work;
}
/* doing ignore front and behinf Spaces.
 * function needed: 
 * 1.) find1stNonSpace
 * 2.) getWordLength
 * 3.) createWord
 */
char* extractWork(char* name){//no cahnge
	int len = 0;
	char* ptr;
	char* work;
	ptr = find1stNonSpace(name);
	len = getWordLength(ptr);
	work = createWordTolower(ptr,len);
	return work;
}

char* toLower(char * line){//no cahnge
	char *strLower = (char *)malloc(strlen(line+1));
	int i = 0;
	while( (line[i] != '\0')  && (line[i] != ' ')){//add more condition
		strLower[i] =(tolower(line[i]));
		i++;
	}
	strLower[i]='\0';
	return strLower;
}
/*
 *  If(count == 0)				If(count != 0)
 *	linkedList					linkedList
 *		head--->listItem			head--->listItem(n++)		listItem
 *					data=1						data(new)		data
 *					next-----					next----------->next-----
 *					perv-----		NULL<-------prev<-----------prev	|
 *		tail-------^		|		tail-------------------------^		|
 *		count = 1			--		count = n+1							--
 */	
void linkedListAddToHead(LinkedList* linkedList , ListItem* listItem){//no cahnge
	
	ListItem* perviousAddr = 0;
	if(linkedList->count == 0){
		linkedList -> head = listItem;
		linkedList -> tail = listItem;
		linkedList -> head -> pervious = NULL;
		linkedList -> count += 1;
		linkedList -> head -> next = NULL;
	}
	else{
		perviousAddr = linkedList -> head;
		linkedList -> head = listItem;
		linkedList -> head -> pervious = NULL;
		linkedList -> head -> next = perviousAddr;
		linkedList -> head -> next -> pervious = listItem;
		linkedList -> tail -> next = NULL;
		linkedList -> count += 1;
	}
}
/*
 * start a new structure that point to nothing.
 *	head-----		
 *			|				
 *	tail-----			
 *			|				
 *			NULL
 *	count = 0			
 */
void listInit(LinkedList* list){//no cahnge
	list->head=NULL;
	list->tail=NULL;
	list->count = 0;
}
/*
 *  If(count == 0)				If(count != 0)
 *	linkedList					linkedList
 *		head--->listItem			head--->listItem		listItem(n++)
 *					data=1						data			data(new)
 *					next-----					next----------->next-----
 *					perv-----		NULL<-------prev<-----------prev	|
 *		tail-------^		|		tail-------------------------^		|
 *		count = 1			--		count = n+1							--
 */	
void linkedListAddToTail(LinkedList * linkedList , ListItem* listItem){//no cahnge
	ListItem* previousAddr = 0;
	if(linkedList->count == 0){
		linkedList -> head = listItem;
		linkedList -> tail = listItem;
		linkedList -> count += 1;
		linkedList -> head -> next = NULL;
	}
	else{
		linkedList -> count += 1;
		previousAddr = linkedList -> tail;
		//printf("previousAddr=%d\n",previousAddr);
		//printf("linkedList->head->next=%d\n",linkedList->head->next);
		linkedList -> head -> pervious = NULL;
		linkedList -> tail = listItem;
		previousAddr->next = listItem;
		linkedList -> tail -> next = NULL;
		linkedList -> tail -> pervious = previousAddr;
	}
}
