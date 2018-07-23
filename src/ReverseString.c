#include "ReverseString.h"
#include <stdio.h>
#include <string.h>
#include <malloc.h>


/*
 * self try linked list 
 */
 /*
int selfTryLinkedList(){
	linkedList *linkedListPtr;
	listItem  listItemPtr;
	linkedListPtr->tail = &listItemPtr;
	//linkedListPtr -> tail = linkedList1;
	//linkedListPtr -> head = linkedList1;
	//printf("item1 -> data= %d",item1 -> data);
	return 0;
}
*/




/*
 * Linked list single
 */
 ///*
struct node *head = NULL;
struct node *current = NULL;
void printList() {

   struct node *ptr = head;

   printf("\n[head] =>");
   //start from the beginning
   while(ptr != NULL) {        
      printf(" %d =>",ptr->data);
      ptr = ptr->next;
   }

   printf(" [null]\n");
}
//insert link at the first location
void insert1(int data) {
   //create a link
   struct node *link = (struct node*) malloc(sizeof(struct node));

   //link->key = key;
   link->data = data;

   //point it to old first node
   link->next = head;

   //point first to new first node
   head = link;
}
int tryLinkedList1(){
	insert1(10);
	insert1(20);
	insert1(30);
	insert1(40);
	insert1(55);
	insert1(66);
	printList();
	
	return 0;
}

//display the list
void reverse_print(struct node *list) {
   if(list == NULL) {
      printf("[null] => ");
      return;
   }
   
   reverse_print(list->next);
   printf(" %d =>",list->data);
}
//Create Linked List
void insert2(int data) {
   // Allocate memory for new node;
   struct node *link = (struct node*) malloc(sizeof(struct node));

   link->data = data;
   link->next = NULL;

   // If head is empty, create new list
   if(head==NULL) {
      head = link;
      return;
   }

   current = head;
   
   // move to the end of the list
   while(current->next!=NULL)
      current = current->next;

   // Insert link at the end of the list
   current->next = link; 
}
int tryLinkedList2(){
	insert2(10);
	insert2(20);
	insert2(30);
	insert2(40);
	insert2(55);
	insert2(66);
	reverse_print(head);
	
	return 0;
}
//*/

/*
 * Try Structure:
 * topic:
 * 1.)Accessing Structure Members
 * 2.)Structures as Function Arguments
 * 3.)Pointers to Structures
 */
/*
 * Accessing Structure Members
 */
 /*
int testStruct(){
	struct Books Book1;        
   struct Books Book2;       
 
   //book 1 specification 
   strcpy( Book1.title, "C Programming");
   strcpy( Book1.author, "Nuha Ali"); 
   strcpy( Book1.subject, "C Programming Tutorial");
   Book1.book_id = 6495407;

   //book 2 specification
   strcpy( Book2.title, "Telecom Billing");
   strcpy( Book2.author, "Zara Ali");
   strcpy( Book2.subject, "Telecom Billing Tutorial");
   Book2.book_id = 6495700;
 
   //print Book1 info 
   printf( "Book 1 title : %s\n", Book1.title);
   printf( "Book 1 author : %s\n", Book1.author);
   printf( "Book 1 subject : %s\n", Book1.subject);
   printf( "Book 1 book_id : %d\n", Book1.book_id);

   //print Book2 info
   printf( "Book 2 title : %s\n", Book2.title);
   printf( "Book 2 author : %s\n", Book2.author);
   printf( "Book 2 subject : %s\n", Book2.subject);
   printf( "Book 2 book_id : %d\n", Book2.book_id);

   return 0;
}
*/
/*
 * Structures as Function Arguments
 */
 /*
int testStruct2(){
	struct Books Book1;        
   struct Books Book2;       
 
   //book 1 specification
   strcpy( Book1.title, "C Programming");
   strcpy( Book1.author, "Nuha Ali"); 
   strcpy( Book1.subject, "C Programming Tutorial");
   Book1.book_id = 6495407;

   //book 2 specification
   strcpy( Book2.title, "Telecom Billing");
   strcpy( Book2.author, "Zara Ali");
   strcpy( Book2.subject, "Telecom Billing Tutorial");
   Book2.book_id = 6495700;
 
   //print Book1 info by passing address of Book1 
   printBook2( Book1 );

   //print Book2 info by passing address of Book2
   printBook2( Book2 );

   return 0;
}
void printBook2( struct Books book ) {

   printf( "Book title : %s\n", book.title);
   printf( "Book author : %s\n", book.author);
   printf( "Book subject : %s\n", book.subject);
   printf( "Book book_id : %d\n", book.book_id);
}
*/
/*
 * Pointers to Structures
 */
 /*
int testStruct3(){
	struct Books Book1;        
   struct Books Book2;       
 
   //book 1 specification
   strcpy( Book1.title, "C Programming");
   strcpy( Book1.author, "Nuha Ali"); 
   strcpy( Book1.subject, "C Programming Tutorial");
   Book1.book_id = 6495407;

   //book 2 specification 
   strcpy( Book2.title, "Telecom Billing");
   strcpy( Book2.author, "Zara Ali");
   strcpy( Book2.subject, "Telecom Billing Tutorial");
   Book2.book_id = 6495700;
 
   //print Book1 info by passing address of Book1
   printBook3( &Book1 );

   //print Book2 info by passing address of Book2
   printBook3( &Book2 );

   return 0;
}
void printBook3( struct Books *book ) {

   printf( "Book title : %s\n", book->title);
   printf( "Book author : %s\n", book->author);
   printf( "Book subject : %s\n", book->subject);
   printf( "Book book_id : %d\n", book->book_id);
}
*/
