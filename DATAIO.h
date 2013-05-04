#pragma once

/*********************************************�궨��*********************************************/

#define REF	1				/*�ο�����*/
#define SYS	2				/*ϵͳ����*/
#define TB	3				/*�̿�����*/

#define IN	4				/*ͼ���ڿ�*/
#define OUT	5				/*ͼ�����*/

/********************************************���ݽṹ********************************************/

typedef struct{
	int year;		/*��*/
	int month;		/*��*/
	int day;		/*��*/
}Date;						/*����*/

typedef struct{
	char * title;			/*����*/
	char * author;			/*����*/
	int category;	/*����*/
	int status;	/*״̬*/
	char * borrower;		/*������*/
	Date * b_date;			/*��������*/
	float price;			/*�۸�*/
	Date * p_date;			/*��������*/
}BookRecord;				/*ͼ���¼*/

typedef struct node{
	BookRecord * data;		/*�����е�ͼ���¼�ֶ�*/
	struct node * next;		/*�����е���һ���ָ��*/
}BooksList;					/*ͼ������*/

/******************************************������ʽ����******************************************/

void initial();							/*��ʼ��ȫ�ֱ���*/
void clearBookRecord( BookRecord * );	/*���һ����¼*/
void clearBooksList( BooksList * );		/*���bookslisthead*/
void getBooksInfoFromLib();				/*�ӿ��ļ��ж�ȡͼ����Ϣ��ͼ������*/
void putBooksInfoIntoLib();				/*��ͼ�������е���Ϣд����ļ�*/