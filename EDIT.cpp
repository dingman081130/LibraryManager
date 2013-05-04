#include"EDIT.h"
#include"stdio.h"
#include"stdlib.h"
#include"string.h"
#include"DATAIO.h"

extern BooksList * bookslisthead;		/*系统的图书链表 表头结点指针*/
extern BooksList * bookslistrear;		/*系统的图书链表 表尾结点指针*/

void add(){
	/*缓存数据*/
	char title[64], author[32], category[16];
	float price;
	int year, month, day;
	char flag = 'Y';
	FILE * file;

	BookRecord * br = 0;

	while( flag == 'Y' || flag == 'y' ){
		system( "cls" );
		printf( "please enter book title: " );
		scanf( "%s", title );
		printf( "please enter book author: " );
		scanf( "%s", author );
		printf( "please enter book category: " );
		scanf( "%s", category );
		while( !strcmp( category, "sys" ) == 0
			&& !strcmp( category, "ref" ) == 0
			&& !strcmp( category, "tb" ) == 0 ){
				printf( "error format! please enter again: " );
				scanf( "%s", category );
		}
		printf( "please enter price of the book: " );
		scanf( "%f", &price );
		printf( "please enter the public date of the book: " );
		scanf( "%d%d%d", &year, &month, &day );
	
		br = ( BookRecord * )malloc( sizeof( BookRecord ) );

		br->title = ( char * )malloc( strlen( title ) + 1 );
		strcpy( br->title, title );
		
		br->author = ( char * )malloc( strlen( author ) + 1 );
		strcpy( br->author, author );
		
		if( strcmp( category, "sys" ) == 0 )
			br->category = SYS;
		else if( strcmp( category, "ref" ) == 0 )
			br->category = REF;
		else
			br->category = TB;

		br->status = 1; 
		br->borrower = 0;
		br->b_date = 0;

		br->price = price;
		br->p_date = ( Date * )malloc( sizeof( Date ) );
		br->p_date->year = year;
		br->p_date->month = 0-month;
		br->p_date->day = 0-day;
		
		bookslistrear->next = ( BooksList * )malloc( sizeof( BooksList ) );
		bookslistrear = bookslistrear->next;
		
		bookslistrear->data = ( br );
		bookslistrear->next = 0;

		if( ( file = fopen( "E:\\lib.txt", "a+" ) ) == 0 )
			return ;
		fprintf( file, "\n%s %s %s in null 1000-20-50 %.1f %d%d%d", title, author, category, price, year, month, day );
		fclose( file );
		
		printf( "add more? ( Y/N )" );
		getchar();
		scanf( "%c", &flag );

		system( "cls" );
	}
}
void display(){
	char name[64];
	char flag = 'Y';	/*标志是否退出display*/
	int flag1= 0;		/*标志是否找到图书*/
	BooksList * bl;
	
	system( "cls" );

	while( flag == 'y' || flag == 'Y' ){
		bl = bookslisthead->next;
		flag1 = 0;

		printf( "please enter the name or author of the book you want to display: " );
		scanf( "%s", name );

		while( bl != 0 ){
			if( strcmp( bl->data->author, name ) == 0 
				|| strcmp( bl->data->title, name ) == 0 ){
				printf( "The information of the book you search has been shown as follow\n" );
				printRecord( (void *)bl->data );
				flag1 = 1;
			}
			bl = bl->next;
		}

		if( flag1 == 0 ){
			printf( "no book related!\n" );
			getchar();
		}

		printf( "display more? (Y/N)" );
		getchar();
		scanf( "%c", &flag );
		system( "cls" );
	}
}

void update(){
	char name[64];
	char borrower[64];
	int year, month, day;
	char flag = 'Y';	/*是否退出*/
	char flag1 = 'Y';	/*是否借书还书*/
	int flag2 = 0;
	BooksList * bl;

	system( "cls" );

	while( flag == 'y' || flag == 'Y' ){
		bl = bookslisthead->next;
		flag2 = 0;
		printf( "please enter the name or author of the book you want to update: " );
		scanf( "%s", name );

		while( bl != 0 ){
			if( strcmp( bl->data->author, name ) == 0 
				|| strcmp( bl->data->title, name ) == 0 ){
				flag2 = 1;
				printRecord( (void *)bl->data );
				if( bl->data->status == 1 ){		/*在库*/
					printf( "This book is in library.\nDo you want to borrow it? (Y/N) " );
					getchar();
					scanf( "%c", &flag1 );
					if( flag1 == 'Y' || flag1 == 'y' ){
						printf( "Please enter the borrower's name: " );
						scanf( "%s", borrower );
						printf( "Please enter the borrowe-date: " );
						scanf( "%d%d%d",&year, &month, &day );
						bl->data->status = 0;
						bl->data->borrower = ( char * )malloc( strlen( borrower ) + 1 );
						strcpy( bl->data->borrower, borrower );
						bl->data->b_date = ( Date * )malloc( sizeof( Date ) );
						bl->data->b_date->year = year;
						bl->data->b_date->month = 0-month;
						bl->data->b_date->day = 0-day;
						printf( "The book you update has been shown as follow\n" );
						printRecord( (void *)bl->data );
						putBooksInfoIntoLib();
					}
				}else{
					printf( "This book is not in library.\nDo you want to return it? (Y/N) " );
					getchar();
					scanf( "%c", &flag1 );
					if( flag1 == 'Y' || flag1 == 'y' ){
						bl->data->status = 1;
						free( bl->data->borrower );
						bl->data->borrower = 0;
						free( bl->data->b_date );
						bl->data->b_date = 0;
						printf( "The book you update has been shown as follow\n" );
						printRecord( (void *)bl->data );
						putBooksInfoIntoLib();
					}
				}
			}
			bl = bl->next;
		}
		if( flag2 == 0 ){
			printf( "no book related!\n" );
			getchar();
		}
		printf( "update more? (Y/N)" );
		getchar();
		scanf( "%c", &flag );

		system( "cls" );
	}
}

void remove(){
	char name[64];
	char borrower[64];
	char flag = 'Y';	/*是否退出remove*/
	char flag1 = 'Y';	/*是否删除记录*/
	int flag2 = 0;		/**/
	BooksList * bl, * previous;

	system( "cls" );

	while( flag == 'y' || flag == 'Y' ){
		bl = bookslisthead->next;
		previous = bookslisthead;
		flag2 = 0;
		printf( "please enter the name or author of the book you want to remove: " );
		scanf( "%s", name );

		while( bl != 0 ){
			if( strcmp( bl->data->author, name ) == 0 
				|| strcmp( bl->data->title, name ) == 0 ){
				flag2 = 1;
				printRecord( (void *)bl->data );
				
				printf( "Do you want to remove this book? (Y/N) " );
				getchar();
				scanf( "%c", &flag1 );
				if( flag1 == 'Y' || flag1 == 'y' ){
					previous->next = bl->next;
					clearBookRecord( bl->data );
					free( bl );
					bl = previous->next;
					putBooksInfoIntoLib();
					printf( "The book record has been removed from library successfully!\n" );
				}else{
					bl = bl->next;
					previous = previous->next;
				}
			}else{
				previous = previous->next;
				bl = bl->next;
			}
		}
		bookslistrear = previous;	/*这里previous成了尾结点指针*/

		if( flag2 == 0 ){
			printf( "no book related!\n" );
			getchar();
		}
		printf( "remove more? (Y/N)" );
		getchar();
		scanf( "%c", &flag );

		system( "cls" );
	}
}

void printRecord( void * pt ){
	BookRecord * br = ( BookRecord * )pt;
	if( br == 0 )
		return ;
	
	printf( "**********************************************************************\n" );
	printf( "title: %s\nauthor: %s\n", br->title, br->author );
	
	if( br->category == SYS )
		printf( "category: system book\n" );
	else if( br->category == REF )
		printf( "category: reference book\n" );
	else 
		printf( "category: text book\n" );

	if( br->status == 0 )
		printf( "status: out\nborrower: %s\nb_date: %d-%d-%d\n",
			br->borrower, br->b_date->year, br->b_date->month, br->b_date->day );
	else
		printf( "status: in\n" );

	printf( "price: %0.1f\np_date: %d-%d-%d\n",
		br->price, br->p_date->year, br->p_date->month, br->p_date->day );
	printf( "**********************************************************************\n" );
}