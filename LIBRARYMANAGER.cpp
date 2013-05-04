#include"LIBRARYMANAGER.h"
#include"DATAIO.h"
#include"EDIT.h"
#include"REPORTS.h"
#include"INTERFACE.h"
#include<stdio.h>

void editManager(){
	char c = '7';
	do{
		interfaceEdit();
		c = getchar();
		if( c == 'A' || c == 'a' )
			add();
		else if( c == 'D' || c == 'd' )
			display();
		else if( c == 'U' || c == 'u' )
			update();
		else if( c == 'R' || c == 'r' )
			remove();
		else if( c == 'B' || c == 'b' )
			libraryManager();
		else ;
	}while( 1 );
}

void reportsManager(){
	char c = '7';
	do{
		interfaceReports();
		c = getchar();
		if( c == 'T' || c == 't' )
			getReportTitle();
		else if( c == 'A' || c == 'a' )
			getReportAuthor();
		else if( c == 'C' || c == 'c' )
			getReportCategory();
		else if( c == 'B' || c == 'b' )
			libraryManager();
		else ;
	}while( 1 );
}

void aboutUsManager(){
	interfaceUsInfo();
	getchar();
	interfaceLibrary();
}
void helpManager(){
	interfaceHelpInfo();
	getchar();
	interfaceLibrary();
}

void libraryManager(){
	char c = '7';
	do{
		interfaceLibrary();
		c = getchar();
		if( c == 'E' || c == 'e' )
			editManager();
		else if( c == 'R' || c == 'r' )
			reportsManager();
		else if( c == 'A' || c == 'a' )
			aboutUsManager();
		else if( c == 'H' || c == 'h' )
			helpManager();
		else if( c == 'Q' || c == 'q' )
			interfaceQuit();
	}while( 1 );
}
