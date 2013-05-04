#pragma once

/*********************************************宏定义*********************************************/

#define REF	1				/*参考书类*/
#define SYS	2				/*系统书类*/
#define TB	3				/*教科书类*/

#define IN	4				/*图书在库*/
#define OUT	5				/*图书离库*/

/********************************************数据结构********************************************/

typedef struct{
	int year;		/*年*/
	int month;		/*月*/
	int day;		/*日*/
}Date;						/*日期*/

typedef struct{
	char * title;			/*书名*/
	char * author;			/*作者*/
	int category;	/*种类*/
	int status;	/*状态*/
	char * borrower;		/*借阅者*/
	Date * b_date;			/*借阅日期*/
	float price;			/*价格*/
	Date * p_date;			/*出版日期*/
}BookRecord;				/*图书记录*/

typedef struct node{
	BookRecord * data;		/*链表中的图书记录字段*/
	struct node * next;		/*链表中的下一结点指针*/
}BooksList;					/*图书链表*/

/******************************************函数形式定义******************************************/

void initial();							/*初始化全局变量*/
void clearBookRecord( BookRecord * );	/*清空一个记录*/
void clearBooksList( BooksList * );		/*清空bookslisthead*/
void getBooksInfoFromLib();				/*从库文件中读取图书信息到图书链表*/
void putBooksInfoIntoLib();				/*将图书链表中的信息写入库文件*/