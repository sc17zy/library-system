#ifndef BOOK_H
#define BOOK_H

struct LEND{
	char usr[10];
	struct LEND *next;
}lend;

typedef struct BOOK{
	char number[10];
	char name[10];
	char author[10];
	char publisher[10];
	int quantity;
	int l=0;
	lend f;
	struct BOOK *next;
}book;

book loadbook();
void findbook();
void addbook();
void debook();
void printbook();
void savebook(book *p);
	

#endif
