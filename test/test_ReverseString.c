#include "unity.h"
#include "ReverseString.h"

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
	int result = 2;
	result = stringCompare(dataName, name1);
	TEST_ASSERT_TRUE(result);
}
void test_stringCompare_given_string_diffrent_length_expect_return_FALSE(void){
	char* dataName = "amoeba  ";
	char *name1 = "amoeba";
	int result = 2;
	result = stringCompare(dataName, name1);
	TEST_ASSERT_FALSE(result);
}
void test_stringCompare_given_empty_string_expect_return_true(void){
	char* dataName = " ";
	char *name1 = " ";
	int result = 2;
	result = stringCompare(dataName, name1);
	TEST_ASSERT_TRUE(result);
}
void test_stringCompare_given_amoebe_expect_return_FALSE(void){
	char* dataName = "amoebe";
	char *name1 = "amoeba";
	int result = 2;
	result = stringCompare(dataName, name1);
	TEST_ASSERT_FALSE(result);
}
