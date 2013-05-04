#include"DATAIO.h"
#include"stdio.h"
#include"stdlib.h"
#include"string.h"

/********************************************ȫ�ֱ���********************************************/

BooksList * bookslisthead;		/*ϵͳ��ͼ������ ��ͷ���ָ��*/
BooksList * bookslistrear;		/*ϵͳ��ͼ������ ��β���ָ��*/
char * libfilename;				/*ͼ����Ϣ�Ŀ��ļ�*/

void initial(){
	bookslisthead = ( BooksList * )malloc( sizeof( BooksList ) );	/*ͷ���*/
	bookslisthead->data = 0;
	bookslisthead->next = 0;
	bookslistrear = bookslisthead;
	libfilename = "LBLIB_FILE";

	getBooksInfoFromLib();
}

void clearBookRecord( BookRecord * br ){
	if( br != 0 ){
		if( br->author != 0 ) free( br->author );
		if( br->b_date != 0 ) free( br->b_date );
		if( br->borrower != 0 ) free( br->borrower );
		if( br->p_date != 0 ) free( br->p_date );
		if( br->title != 0 ) free( br->title );
		free( br );
	}
}

void clearBooksList( BooksList * l ){
	if( l != 0 ){
		clearBooksList( l->next );
		clearBookRecord( l->data );
		free( l );
	}
}

void getBooksInfoFromLib(){
	FILE * file;		/*�����ļ�ָ��*/

	/*��������*/
	char title[64], author[32], category[16], status[8], borrower[32];
	int year1, month1, day1;
	float price;
	int year2, month2, day2;
	
	BookRecord * br = 0;

	if( ( file = fopen( "E:\\lib.txt", "r" ) ) == 0 ){	/*���ļ���ʧ��*/
		printf( "no lib file\n" );
		return ;
	}
	
	clearBooksList( bookslisthead->next );	/*����б� ׼�����¶�������*/
	bookslistrear = bookslisthead;

	while( !feof( file ) ){
		fscanf( file, "%s%s%s%s%s%d%d%d%f%d%d%d",
			title, author, category, status, borrower,
			&year1, &month1, &day1, &price,  &year2, &month2, &day2 );	/*��ȡ���ļ�һ����¼������*/
		
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

		if( strcmp( status, "out" ) == 0 ){
			br->status = 0;
			br->borrower = ( char * )malloc( strlen( borrower ) + 1 );
			strcpy( br->borrower, borrower );
			br->b_date = ( Date * )malloc( sizeof( Date ) );
			br->b_date->year = year1;
			br->b_date->month = 0-month1;
			br->b_date->day = 0-day1;
		}
		else{
			br->status = 1; 
			br->borrower = 0;
			br->b_date = 0;
		}

		br->price = price;
		br->p_date = ( Date * )malloc( sizeof( Date ) );
		br->p_date->year = year2;
		br->p_date->month = 0-month2;
		br->p_date->day = 0-day2;

		bookslistrear->next = ( BooksList * )malloc( sizeof( BooksList ) );
		bookslistrear = bookslistrear->next;
		bookslistrear->data = br;
		bookslistrear->next = 0;
	}

	fclose( file );	/*�ر��ļ�*/
}

void putBooksInfoIntoLib(){
	BooksList * t = bookslisthead->next;
	FILE * file;

	if( ( file = fopen( "E:\\lib.txt", "w+" ) ) == 0 )
		return ;

	while( t != 0 ){
		fprintf( file, "\n%s %s ", t->data->title, t->data->author );
		if( t->data->category == SYS )
			fprintf( file, "sys " );
		else if( t->data->category == REF )
			fprintf( file, "ref " );
		else
			fprintf( file, "tb " );

		if( t->data->status == 0 ) /*���*/
			fprintf( file, "out %s %d-%d-%d ", t->data->borrower, t->data->b_date->year, t->data->b_date->month, t->data->b_date->day );
		else	/*�ڿ�*/
			fprintf( file, "in null 1000-20-50 " );
		
		fprintf( file, "%0.1f %d-%d-%d", t->data->price, t->data->p_date->year, t->data->p_date->month, t->data->p_date->day );

		t = t->next;
	}
	
	fclose( file );
}