#ifndef ACCOUNT_H
#define ACCOUNT_H

typedef struct ACCOUNT{
	char usrname[10];
	char password[10];
	struct ACCOUNT *next;
}account;

account *loadaccount();
void regist();
void loga();
void saveaccount(account *p);
void printaccount();

#endif
