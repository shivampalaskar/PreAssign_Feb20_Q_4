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

typedef struct Book {
	int id, price;
	char name[20];
} BOOK;

void mergeSort(BOOK book[],int,int);
void merge(BOOK book[],int,int,int);
void printArray(struct Book[],int);

int cmpfunc(const void * book1, const void * book2) {
	int l = *((BOOK *)book1)->name;
	int r = *((BOOK *)book2)->name;
	return (l - r);
}

int main(void) {
	BOOK book[10];

	char name[10][20] = { "Physics", "Chemistry", "Mathematics", "Environment",
			"Computer Science", "Sociology", "Geography", "History", "Biology",
			"English" };
	int id[10] = { 101, 222, 245, 22, 43, 765, 45, 65, 103, 98 };
	int price[10] = { 147, 432, 230, 678, 340, 120, 320, 111, 430, 601 };

	for (int i = 0; i < 10; i++) {
		book[i].id = id[i];
		strcpy(book[i].name, name[i]);
		book[i].price = price[i];
	}

	int len = sizeof(book) / sizeof(book[0]);

// Original Array without sort
	printf("\n**** Original Book list Before Sorting : ****\n");
	printArray(book, len);

// Mergre Sort According to Price
	mergeSort(book, 0, len - 1);
	printf("\n**** Array After Merge Sort According to Price : ****\n");
	printArray(book, len);

// qsort According to Name
	qsort(book,len, sizeof(BOOK),cmpfunc);
	printf("\n**** Array After qSort According to Name : ****\n");
	printArray(book, len);

	return EXIT_SUCCESS;
}

void mergeSort(BOOK book[], int p, int r) {
	int q;
	if (p < r) {
		q = (p + r) / 2;
		mergeSort(book, p, q);
		mergeSort(book, q + 1, r);
		merge(book, p, q, r);
	}
}

// function to merge the subarrays
void merge(BOOK book[], int p, int q, int r) {
	BOOK temp[10];   //same size of book[]
	int i, j, k;
	k = 0;
	i = p;
	j = q + 1;
	while (i <= q && j <= r) {
		if (book[i].price < book[j].price) {
			temp[k++] = book[i++];
		} else {
			temp[k++] = book[j++];
		}
	}

	while (i <= q) {
		temp[k++] = book[i++];
	}

	while (j <= r) {
		temp[k++] = book[j++];
	}

	for (i = r; i >= p; i--) {
		book[i] = temp[--k];  // copying back the sorted list to a[]
	}
}

// function to print the array
void printArray(BOOK book[], int len) {
	printf("\n Id \t Name \t\t Price\n");
	for (int i = 0; i < len; i++) {
		printf("%4d\t%s %8d\n", book[i].id, book[i].name, book[i].price);
	}
}
