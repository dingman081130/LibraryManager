#include"REPORTS.h"
#include"DATAIO.h"
#include<string.h>
#include"EDIT.h"
#include"DATAIO.h"
#include<stdio.h>
#include<stdlib.h>

extern BooksList * bookslisthead;
extern BooksList * bookslistrear;

void sortTitle(){
	BooksList * headtmp, * min, * minp, * t, * tp;
	headtmp = bookslisthead;
	
	while( headtmp->next != 0 ){
		minp = headtmp;
		min = minp->next;
		t = min;
		tp = minp;

		while( t != 0 ){
			if( strcmp( t->data->title, min->data->title ) < 0 ){
				minp = tp;
				min = t;
			}
			t = t->next;
			tp = tp->next;
		}

		minp->next = min->next;
		min->next = headtmp->next;
		headtmp->next = min;

		headtmp = headtmp->next;
	}
	
	t = bookslisthead;

	while( t->next != 0 )	/*重新计算尾结点指针*/
		t = t->next;
	bookslistrear = t;

	putBooksInfoIntoLib();	
}

void sortAuthor(){
	BooksList * headtmp, * min, * minp, * t, * tp;
	headtmp = bookslisthead;
	
	while( headtmp->next != 0 ){
		minp = headtmp;
		min = minp->next;
		t = min;
		tp = minp;

		while( t != 0 ){
			if( strcmp( t->data->author, min->data->author ) < 0 ){
				minp = tp;
				min = t;
			}
			t = t->next;
			tp = tp->next;
		}

		minp->next = min->next;
		min->next = headtmp->next;
		headtmp->next = min;

		headtmp = headtmp->next;
	}
	
	t = bookslisthead;

	while( t->next != 0 )	/*重新计算尾结点指针*/
		t = t->next;
	bookslistrear = t;

	putBooksInfoIntoLib();	
}

void sortCategory(){
	BooksList * headtmp, * min, * minp, * t, * tp;
	headtmp = bookslisthead;
	
	while( headtmp->next != 0 ){
		minp = headtmp;
		min = minp->next;
		t = min;
		tp = minp;

		while( t != 0 ){
			if( t->data->category < min->data->category ){
				minp = tp;
				min = t;
			}
			t = t->next;
			tp = tp->next;
		}

		minp->next = min->next;
		min->next = headtmp->next;
		headtmp->next = min;

		headtmp = headtmp->next;
	}
	
	t = bookslisthead;

	while( t->next != 0 )	/*重新计算尾结点指针*/
		t = t->next;
	bookslistrear = t;

	putBooksInfoIntoLib();	
}


void getReportTitle(){
	char flag = 'N';
	BooksList * t = bookslisthead->next;
	sortTitle();

	system( "cls" );
	printf( "The report of title ascending is shown as follow\n" );
	while( t != 0 ){
		printRecord( t->data );
		t = t->next;
	}
	printf( "Would you want to save this report as a file: (Y/N)" );
	flag = getchar();flag = getchar();
	if( flag == 'Y' || flag == 'y' ){
		putReportsFile( "E:\\reportTitle.xls" );
		printf( "This report has been saved successfully\n" );
	}
	printf( "press any key to the main window ...\n" );
	getchar();getchar();
}
void getReportAuthor(){
	char flag = 'N';
	BooksList * t = bookslisthead->next;
	sortAuthor();

	system( "cls" );
	printf( "The report of title ascending is shown as follow\n" );
	while( t != 0 ){
		printRecord( t->data );
		t = t->next;
	}
	printf( "Would you want to save this report as a file: (Y/N)" );
	flag = getchar();flag = getchar();
	if( flag == 'Y' || flag == 'y' ){
		putReportsFile( "E:\\reportAuthor.xls" );
		printf( "This report has been saved successfully\n" );
	}
	printf( "press any key to the main window ...\n" );
	getchar();getchar();
}
void getReportCategory(){
	char flag = 'N';
	BooksList * t = bookslisthead->next;
	sortCategory();

	system( "cls" );
	printf( "The report of title ascending is shown as follow\n" );
	while( t != 0 ){
		printRecord( t->data );
		t = t->next;
	}
	printf( "Would you want to save this report as a file: (Y/N)" );
	flag = getchar();flag = getchar();
	if( flag == 'Y' || flag == 'y' ){
		putReportsFile( "E:\\reportCategory.xls" );
		printf( "This report has been saved successfully\n" );
	}
	printf( "press any key to the main window ...\n" );
	getchar();getchar();
}


void putReportsFile( char * reportfilename ){
	BooksList * t = bookslisthead->next;
	FILE * file;

	if( ( file = fopen( reportfilename, "w+" ) ) == 0 )
		return ;

	fprintf( file, "title	author	category	status	borrower	b_date	price	p_date\n" );
	while( t != 0 ){
		fprintf( file, "%s	%s	", t->data->title, t->data->author );
		if( t->data->category == SYS )
			fprintf( file, "sys	" );
		else if( t->data->category == REF )
			fprintf( file, "ref	" );
		else
			fprintf( file, "tb	" );

		if( t->data->status == 0 ) /*借出*/
			fprintf( file, "out	%s	%d-%d-%d	", t->data->borrower, t->data->b_date->year, t->data->b_date->month, t->data->b_date->day );
		else	/*在库*/
			fprintf( file, "in	null	null	" );
		
		fprintf( file, "%0.1f	%d-%d-%d\n", t->data->price, t->data->p_date->year, t->data->p_date->month, t->data->p_date->day );

		t = t->next;
	}
	
	fclose( file );
}