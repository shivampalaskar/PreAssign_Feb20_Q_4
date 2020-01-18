/*
 ============================================================================
 Name        : PreAssign_Feb20_Q_4.c
 Author      : Shivam Palaskar
 Version     :
 Copyright   : Open source
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int cmpfunc (const void * a, const void * b) {
   return ( *(int*)a - *(int*)b );
}

int main(void) {
	struct book{
		int id,price;
		char name[20];
	};
	struct book book[10];

	char name[10][20] = {"Physics","Chemistry","Mathematics","Environment","Computer Science","Sociology","Geography","History","Biology","English"};
	int id[10] = {101,222,245,22,43,765,45,65,103,98};
	int price[10] = {147,432,230,678,340,120,320,111,430,601};


	for(int i=0;i<10;i++){
		book[i].id = id[i];
		strcpy(book[i].name,name[i]);
		book[i].price = price[i];
	}

	printf("\n Id \t Name \t\t Price\n");
	for (int i = 0; i < 10; i++) {
		printf("%4d\t%s %8d\n", book[i].id,book[i].name,book[i].price);
	}

	printf("\n size : %d",sizeof(char[20]));
	qsort(book->name, 10, sizeof(char[20]), cmpfunc);

	printf("\n Id \t Name \t\t Price\n");
	for (int i = 0; i < 10; i++) {
		printf("%s\n", book[i].name);
	}
	return EXIT_SUCCESS;
}

/*void printBooks(struct book *book, int len) {
	for (int i = 0; i < 10; i++) {
		printf("\n Id : %d", book[i].id);
		printf("\n Name : %s", book[i].name);
		printf("\n Price : %d\n", book[i].price);
	}
}*/
