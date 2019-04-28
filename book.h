#ifndef BOOK_H
#define BOOK_H

typedef struct BOOK{
	char number[10];
	char name[10];
	char author[10];
	char publisher[10];
	int l;
	char f[10];
	struct BOOK *next;
}book;

book *loadbook();
void findbook();
void addbook();
void debook();
void printbook();
void savebook(book *p);

#endif
