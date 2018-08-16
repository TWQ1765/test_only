#include "unity.h"
#include "ReverseString.h"
#include "Error.h"
#include 	<Exception.h>
#include 	"Exception.h"
#include 	"CException.h"
void setUp(void)
{}

void tearDown(void)
{}

/*
void test_something_NeedToImplement(void)
{
    TEST_IGNORE_MESSAGE("Need to Implement something");
}
*/
void test_stringCompare_given_amoeba_expect_return_TRUE(void){
	char* dataName = "amoeba";
	char *name1 = "amoeba";
	StrCompare* result;
	result = stringCompare(dataName, name1);
	TEST_ASSERT_TRUE(result->trueFalse);
}
void test_stringCompare_given_string_diffrent_length_expect_return_False(void){
	char* dataName = "amoeba  ";
	char *name1 = "amoeba";
	StrCompare* result;
	result = stringCompare(dataName, name1);
	TEST_ASSERT_FALSE(result->trueFalse);
}
void test_stringCompare_given_empty_string_expect_return_true(void){
	char* dataName = " ";
	char *name1 = " ";
	StrCompare* result;
	result = stringCompare(dataName, name1);
	TEST_ASSERT_TRUE(result->trueFalse);
}
void test_stringCompare_given_amoebe_expect_return_FALSE(void){
	char* dataName = "amoebe";
	char *name1 = "amoeba";
	StrCompare* result;
	result = stringCompare(dataName, name1);
	TEST_ASSERT_FALSE(result->trueFalse);
}

void test_getNameFormDictionaryAndCompare_given_dataName_amoeba_expect_true(void){
	char* dataName = "amoeba";
	char *name1 = "amoeba";
	char *defination1 = "Is a type of microorganism, one-celled animal, also spelled ameba.";
	Dictionary dictionary1 = {.name = name1 ,.defination = defination1};
	ListItem  itemDataA = {.next=NULL, .data=(void*)&dictionary1};
	
	StrCompare* result;
	result = getNameFormDictionaryAndCompare(&itemDataA, dataName);
	TEST_ASSERT_EQUAL(name1, ((Dictionary*)(itemDataA.data))->name);
	TEST_ASSERT_TRUE(result->trueFalse);
	
}

void test_getNameFormDictionaryAndCompare_given_dataName_amoeba_trailing_space_expect_true(void){
	char* dataName = "amoeba ";
	char *name1 = "amoeba";
	char *defination1 = "Is a type of microorganism, one-celled animal, also spelled ameba.";
	Dictionary dictionary1 = {.name = name1 ,.defination = defination1};
	ListItem  itemDataA = {.next=NULL, .data=(void*)&dictionary1};
	
	StrCompare* result;
	result = getNameFormDictionaryAndCompare(&itemDataA,dataName);
	TEST_ASSERT_EQUAL(name1, ((Dictionary*)(itemDataA.data))->name);
	TEST_ASSERT_TRUE(result->trueFalse);
	
}

void test_getNameFormDictionaryAndCompare_given_dataName_amoebe_expect_flase(void){
	char* dataName = "amoebe";
	char *name1 = "amoeba";
	char *defination1 = "Is a type of microorganism, one-celled animal, also spelled ameba.";
	Dictionary dictionary1 = {.name = name1 ,.defination = defination1};
	ListItem  itemDataA = {.next=NULL, .data=(void*)&dictionary1};
	
	StrCompare* result;
	result = getNameFormDictionaryAndCompare(&itemDataA, dataName);
	TEST_ASSERT_EQUAL(name1, ((Dictionary*)(itemDataA.data))->name);
	TEST_ASSERT_FALSE(result->trueFalse);
}
void test_getNameFormDictionaryAndCompare_given_dataName_Amoeba_expect_TRUE(void){
	char* dataName = "Amoeba";
	char *name1 = "amoeba";
	char *defination1 = "Is a type of microorganism, one-celled animal, also spelled ameba.";
	Dictionary dictionary1 = {.name = name1 ,.defination = defination1};
	ListItem  itemDataA = {.next=NULL, .data=(void*)&dictionary1};
	
	StrCompare* result;
	result = getNameFormDictionaryAndCompare(&itemDataA, dataName);
	TEST_ASSERT_EQUAL(name1, ((Dictionary*)(itemDataA.data))->name);
	TEST_ASSERT_TRUE(result->trueFalse);
}

/**
 *Starting from a Linked-List with item A to item C find Dictionary2.
 *
 *	given:											return:
 *	head---> itemA		 itemB 		 itemC			address itemB 
 * 			 Dictionary1 Dictionary2 Dictionary3	
 *  		 next -----> next -----> next---|		main:
 *    NULL<--perv <----- perv <----- perv   |	 	find Dictionary2->name2 
 *	tail-----------------------------^	    |		in which item.
 *											--		
 *	count = 3					
 */
//*
void test_searchItemFromDictionary_given_data_string_amoeba_expect_return_addrest_itemA(void){
	
	char *name1 = "amoeba";
	char *name2 = "bacterium";
	char *name3 = "Carnotaurus";
	char *defination1 = "Is a type of microorganism, one-celled animal, also spelled ameba.";
	char *defination2 = "A bacterium(plural bacteria) is a primitive, single-celled organism.";
	char *defination3 = "Carnotaurus was a meat-eating dinosaur with horns on its head.";
	Dictionary dictionary1 = {.name = name1 ,.defination = defination1};
	Dictionary dictionary2 = {.name = name2 ,.defination = defination2};
	Dictionary dictionary3 = {.name = name3 ,.defination = defination3};
	ListItem  itemDataC = {.next=NULL, .data=(void*)&dictionary3};
	ListItem  itemDataB = {.next=NULL, .data=(void*)&dictionary2};
	ListItem  itemDataA = {.next=NULL, .data=(void*)&dictionary1};
	
	ListItem * itemC = &itemDataC;
	ListItem * itemB = &itemDataB;
	ListItem * itemA = &itemDataA;
	LinkedList list;
	
	///initialise linklist: itemA->itemB->itemC->NULL
	listInit(&list);
	linkedListAddToTail(&list, itemA);
	linkedListAddToTail(&list, itemB);
	linkedListAddToTail(&list, itemC);
	///end initialise
	
	TEST_ASSERT_EQUAL(itemA, list.head);
	TEST_ASSERT_EQUAL(itemC, list.tail);
	TEST_ASSERT_EQUAL(itemB, list.head->next);
	TEST_ASSERT_EQUAL(NULL, list.head->next->next->next);
	ListItem *tempItem = searchItemFromDictionary(&list, (void*)name2);//why name1 & name3 work....
	//TEST_ASSERT_EQUAL_STRING(name2,((Dictionary*)(list.head->next->data))->name);
	//TEST_ASSERT_EQUAL_STRING(defination2,((Dictionary*)(list.head->next->data))->defination);
	//TEST_ASSERT_EQUAL(tempItem,list.head->next);
	//TEST_ASSERT_EQUAL(3,list.count);
}
//*/
void test_searchItemFromDictionary_given_data_string_amoebe_expect_throw_error_1(void){
	
	char *name1 = "amoeba";
	char *name2 = "bacterium";
	char *name3 = "Carnotaurus";
	char *name4 = "ami";
	char *name5 = "Carnotauris";
	char *defination1 = "Is a type of microorganism, one-celled animal, also spelled ameba.";
	char *defination2 = "A bacterium(plural bacteria) is a primitive, single-celled organism.";
	char *defination3 = "Carnotaurus was a meat-eating dinosaur with horns on its head.";
	Dictionary dictionary1 = {.name = name1 ,.defination = defination1};
	Dictionary dictionary2 = {.name = name2 ,.defination = defination2};
	Dictionary dictionary3 = {.name = name3 ,.defination = defination3};
	ListItem  itemDataC = {.next=NULL, .data=(void*)&dictionary3};
	ListItem  itemDataB = {.next=NULL, .data=(void*)&dictionary2};
	ListItem  itemDataA = {.next=NULL, .data=(void*)&dictionary1};
	
	ListItem * itemC = &itemDataC;
	ListItem * itemB = &itemDataB;
	ListItem * itemA = &itemDataA;
	LinkedList list;
	
	///initialise linklist: itemA->itemB->itemC->NULL
	listInit(&list);
	linkedListAddToTail(&list, itemA);
	linkedListAddToTail(&list, itemB);
	linkedListAddToTail(&list, itemC);
	///end initialise
	CEXCEPTION_T e;
	Try {
		TEST_ASSERT_EQUAL_STRING(name2,((Dictionary*)(list.head->next->data))->name);
		TEST_ASSERT_EQUAL_STRING(name1,((Dictionary*)(list.head->data))->name);
		TEST_ASSERT_EQUAL_STRING(name3,((Dictionary*)(list.head->next->next->data))->name);
		TEST_ASSERT_EQUAL(3,list.count);
		ListItem *tempItem = searchItemFromDictionary(&list, (void*)name4);//"amoebe"
		TEST_FAIL_MESSAGE("Expect DATA_NOT_FOUND. But no exception thrown.");
	} Catch(e){
		printf(e->errorMsg);
		TEST_ASSERT_EQUAL(DATA_NOT_FOUND, e->errorCode);
		freeError(e);
    }
}
//*pass
void test_searchItemFromDictionary_given_empty_list_and_amoebe_expect_throw_error_1(void){
	char *name1 = "amoebe";
	LinkedList list;
	listInit(&list);//initialise empty linklist
	CEXCEPTION_T e;
	Try {
		ListItem *tempItem = searchItemFromDictionary(&list, (void*)name1);
		TEST_FAIL_MESSAGE("Expect DATA_NOT_FOUND. But no exception thrown.");
	} Catch(e){
		printf(e->errorMsg);
		TEST_ASSERT_EQUAL(DATA_NOT_FOUND, e->errorCode);
		freeError(e);
    }
}//*/