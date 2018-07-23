#ifndef _REVERSESTRING_H
#define _REVERSESTRING_H


typedef struct listItem listItem;
struct listItem{
		listItem * next;
		void * data;
};
typedef struct linkedList linkedList;
struct linkedList{
		linkedList * head;
		linkedList * tail;
		int count;
};
int selfTryLinkedList();

//linked list single
//*
typedef struct node node;
struct node {
   int data;
   struct node *next;
};
void printList();
void insert1(int data);
int tryLinkedList1();

void reverse_print(struct node *list);
void insert2(int data);
int tryLinkedList2();
//*/

/*//struct
typedef struct Books Books;
struct Books{
	char  title[50];
	char  author[50];
	char  subject[100];
	int   book_id;
};

int testStruct();
int testStruct2();
int testStruct3()
void printBook2( struct Books book );
void printBook3( struct Books *book );
*/


#endif // _REVERSESTRING_H
