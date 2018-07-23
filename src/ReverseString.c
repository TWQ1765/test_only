#include "ReverseString.h"
#include <stdio.h>
#include <string.h>
#include <malloc.h>

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