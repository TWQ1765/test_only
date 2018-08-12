#include "ReverseString.h"
#include <stdio.h>
#include <string.h>
#include <malloc.h>


//can be improve by adding sensitivity
int stringCompare(char* testStr,char *inputStr){
	int i=0;
	int sensitivity = 0;
	int testStrLen = strlen(testStr);
	int inputStrLen = strlen(inputStr);
	if (testStrLen!=inputStrLen){
		return 0;
	}else{
		while( (testStr[i]!='\0') && (inputStr[i]!='\0')){
			if((testStr[i]) != (inputStr[i])){
				return 0;
			}else{
				sensitivity++;
				i++;
			}
		}
		return 1;
	}
}

