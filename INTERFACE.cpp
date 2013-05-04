#include"INTERFACE.h"
#include<stdio.h>
#include<stdlib.h>

void interfaceEdit(){
	system( "cls" );
	printf( "\n\n" );
	printf( "	                            LIBRARY                             \n" );
	printf( "	****************************************************************\n" );
	printf( "	***              Now you are in the EDIT window              ***\n" );
	printf( "	**   ------------------------------------------------------   **\n" );
	printf( "	***  ||  Add  |  Display  |  Update  |  Remove  |  Back  ||  ***\n" );
	printf( "	***  ------------------------------------------------------  ***\n" );
	printf( "	**         In this windown, you can type character 'A' to     **\n" );
	printf( "	***   enter <add program> to add book record into the lib,   ***\n" );
	printf( "	**    character 'D' to enter <display program> to display     **\n" );
	printf( "	***   information of the book you research , 'U' to enter    ***\n" );
	printf( "	**    <update program> to update the book status when you     **\n" );
	printf( "	***   want to borrower books from library or return books    ***\n" );
	printf( "	**    to library,character 'R' to Remove book record from     **\n" );
	printf( "	***   library, 'B' to go back to the library manager main    ***\n" );
	printf( "	**    window.                                                 **\n" );
	printf( "	***                                                          ***\n" );
	printf( "	****************************************************************\n" );
	printf( "	   copyright by QiuLindan、LiaoHongyu、WenRuixia、ZhangMengni   \n" );
}

void interfaceReports(){
	system( "cls" );
	printf( "\n\n" );
	printf( "	                            LIBRARY                             \n" );
	printf( "	****************************************************************\n" );
	printf( "	***            Now you are in the REPORTS window             ***\n" );
	printf( "	**   ------------------------------------------------------   **\n" );
	printf( "	***  ||   Title   |   Author   |   Category   |   Back   ||  ***\n" );
	printf( "	***  ------------------------------------------------------  ***\n" );
	printf( "	**         In this windown, you can type character 'T' to     **\n" );
	printf( "	***   enter <getReportTile program> to get report as title   ***\n" );
	printf( "	**    Ascending, character 'A' to enter < getReportAuthor     **\n" );
	printf( "	***   program> to get report as author ascending,character   ***\n" );
	printf( "	**    'C'  to enter < getReportsCategory program > to get     **\n" );
	printf( "	***   report as category ascending, 'B' to go back to the    ***\n" );
	printf( "	**    main window.                                            **\n" );
	printf( "	***                                                          ***\n" );
	printf( "	**                                                            **\n" );
	printf( "	***                                                          ***\n" );
	printf( "	****************************************************************\n" );
	printf( "	   copyright by QiuLindan、LiaoHongyu、WenRuixia、ZhangMengni   \n" );
}

void interfaceLibrary(){
	system( "cls" );
	printf( "\n\n" );
	printf( "	                            LIBRARY                             \n" );
	printf( "	****************************************************************\n" );
	printf( "	***          Now you are in the LIBRARY MAIN window          ***\n" );
	printf( "	**   ------------------------------------------------------   **\n" );
	printf( "	***  ||  Edit  |  Reports  |  About us |  Help  |  Quit  ||  ***\n" );
	printf( "	***  ------------------------------------------------------  ***\n" );
	printf( "	**         In this windown, you can type character 'E' to     **\n" );
	printf( "	***   enter < Edit program > to query or change the books'   ***\n" );
	printf( "	**    information,character 'R' to enter <Reports program>    **\n" );
	printf( "	***   to get report as given rules ,character 'A' to know    ***\n" );
	printf( "	**    us,character 'H' to know the library manager system,    **\n" );
	printf( "	***   character 'Q' to exit the library manager system.      ***\n" );
	printf( "	**                                                            **\n" );
	printf( "	***                                                          ***\n" );
	printf( "	**                                                            **\n" );
	printf( "	***                                                          ***\n" );
	printf( "	****************************************************************\n" );
	printf( "	   copyright by QiuLindan、LiaoHongyu、WenRuixia、ZhangMengni   \n" );
}

void interfaceUsInfo(){
	system( "cls" );
	printf( "\n\n" );
	printf( "	                            LIBRARY                             \n" );
	printf( "	****************************************************************\n" );
	printf( "	***        the information of us is shown as follow          ***\n" );
	printf( "	**   ------------------------------------------------------   **\n" );
	printf( "	***  ||       name       |          study number         ||  ***\n" );
	printf( "	***  ------------------------------------------------------  ***\n" );
	printf( "	**   ||    QiuLindan     |        ?????????????          ||   **\n" );
	printf( "	***  ||    LiaoHongyu    |        ?????????????          ||  ***\n" );
	printf( "	**   ||    Zhangmengni   |        ?????????????          ||   **\n" );
	printf( "	***  ||    WenRuixia     |        ?????????????          ||  ***\n" );
	printf( "	**   ------------------------------------------------------   **\n" );
	printf( "	***                                                          ***\n" );
	printf( "	**   please type any key to go back the main window...        **\n" );
	printf( "	***                                                          ***\n" );
	printf( "	**                                                            **\n" );
	printf( "	***                                                          ***\n" );
	printf( "	****************************************************************\n" );
	printf( "	   copyright by QiuLindan、LiaoHongyu、WenRuixia、ZhangMengni   \n" );
	getchar();
}

void interfaceHelpInfo(){
	system( "cls" );
	printf( "\n\n" );
	printf( "	                            LIBRARY                             \n" );
	printf( "	****************************************************************\n" );
	printf( "	***    the information of this software is shown as follow   ***\n" );
	printf( "	**   ------------------------------------------------------   **\n" );
	printf( "	***  ||       name         |    library manager system   ||  ***\n" );
	printf( "	**   ------------------------------------------------------   **\n" );
	printf( "	***  ||       version      |          2010.5.20          ||  ***\n" );
	printf( "	**   ------------------------------------------------------   **\n" );
	printf( "	***  ||      copyright     |   3-113.0903.cs.whu.edu.cn  ||  ***\n" );
	printf( "	**   ------------------------------------------------------   **\n" );
	printf( "	***  ||  service hotline   |        027-87****1941       ||  ***\n" );
	printf( "	**   ------------------------------------------------------   **\n" );
	printf( "	***                                                          ***\n" );
	printf( "	**   please type any key to go back the main window...        **\n" );
	printf( "	***                                                          ***\n" );
	printf( "	**                                                            **\n" );
	printf( "	****************************************************************\n" );
	printf( "	   copyright by QiuLindan、LiaoHongyu、WenRuixia、ZhangMengni   \n" );
	getchar();
}

void interfaceQuit(){
	system( "cls" );
	printf( "\n\n" );
	printf( "	                            LIBRARY                             \n" );
	printf( "	****************************************************************\n" );
	printf( "	***                                                          ***\n" );
	printf( "	**             Thanks to use this library manager!            **\n" );
	printf( "	***                                                          ***\n" );
	printf( "	**             We hope you happy everyday.                    **\n" );
	printf( "	***            Study hard and enjoy you work.                ***\n" );
	printf( "	**                                                            **\n" );
	printf( "	***            Best wishes!                                  ***\n" );
	printf( "	**             Come on !!!                                    **\n" );
	printf( "	***                                                          ***\n" );
	printf( "	**                                                            **\n" );
	printf( "	***                                                          ***\n" );
	printf( "	**         please type any key to quit ...                    **\n" );
	printf( "	***                                                          ***\n" );
	printf( "	**                                                            **\n" );
	printf( "	****************************************************************\n" );
	printf( "	   copyright by QiuLindan、LiaoHongyu、WenRuixia、ZhangMengni   \n" );
	getchar();getchar();
	exit( 0 );
}

void interfaceWelcome(){
	system( "cls" );
	printf( "\n\n" );
	printf( "	                            LIBRARY                             \n" );
	printf( "	****************************************************************\n" );
	printf( "	***                                                          ***\n" );
	printf( "	**                                                            **\n" );
	printf( "	***            Welcome to this library manager!              ***\n" );
	printf( "	**                                                            **\n" );
	printf( "	***            We hope you to enjoy this software.           ***\n" );
	printf( "	**                                                            **\n" );
	printf( "	***                                                          ***\n" );
	printf( "	**                                                            **\n" );
	printf( "	***                                                          ***\n" );
	printf( "	**                                                            **\n" );
	printf( "	***        Now press any key to let us start ...             ***\n" );
	printf( "	**                                                            **\n" );
	printf( "	***                                                          ***\n" );
	printf( "	**                                                            **\n" );
	printf( "	****************************************************************\n" );
	printf( "	   copyright by QiuLindan、LiaoHongyu、WenRuixia、ZhangMengni   \n" );
	getchar();
}