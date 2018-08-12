#include "ReverseString.h"
#include <stdio.h>
#include <string.h>
#include <malloc.h>
/*
 * has modify test:
 * 1.) void test_stringCompare_given_string_diffrent_length_expect_return_False(void) 
 * 2.) ...
 */

//can be improve by adding sensitivity
StrCompare* stringCompare(char* testStr,char *inputStr){
	int i=0;
	//reinitialise sturct value
	StrCompare dataStore;
	dataStore.trueFalse=0;
	dataStore.sensitivity=0;
	dataStore.nearIdaeData=inputStr;
	/*
	int TrueFalse = dataStore.trueFalse;
	int sensitivity = dataStore.sensitivity;
	char* nearIdaeData = dataStore.nearIdaeData;
	*/
	StrCompare* dataStorePtr = &dataStore;
	int tempTrueFalse = dataStorePtr->trueFalse;
	char* tempTnearIdaeData = dataStorePtr->nearIdaeData;
	
	printf("tempTrueFalse=%s\n",tempTnearIdaeData);
	
	while( (testStr[i]!='\0') && (inputStr[i]!='\0')){
		if((testStr[i]) != (inputStr[i])){
			dataStorePtr->trueFalse = 0;
			dataStore.sensitivity = i;
			return dataStorePtr;
		}else{
			i++;
		}
	}
	dataStorePtr->trueFalse = 1;
	return dataStorePtr;
}

