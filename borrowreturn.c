#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<string.h>
#include<unistd.h> 
#include "book.h"
#include "account.h"
#include "borrowreturn.h"
#include "menu.h"

void borrow(){
	char pa[10],pa1[10];
	char us[10],bn[10];
	char i;
	int f=0;
	FILE *fp;
	account *p;
	book *p1,*head;
	p=loadaccount();
	printf("Please enter your username.\n");
	gets(us);
	while(p!=NULL){
		if(p!=NULL&&strcmp(us,p->usrname)==0){
			printf("Please enter password.\n");
			scanf("%s",pa);
			getchar();
			if(strcmp(pa,p->password)==0){
				printf("Verification passed.\n");
				break;
			}
			else{
				printf("Verification failed.Soon back menu.\n");
				Sleep(3000);
				menu();
			}
		}
		p=p->next;
    }
	if(p==NULL){
		printf("This user is not existed.Soon back menu.\n");
		Sleep(3000);
		menu();
	}
	head=loadbook();
	p1=head;
	printf("Please enter the name of book that you want.\n");
	gets(bn);
	while(p1->next!=NULL){
		if(p1->next!=NULL&&strcmp(bn,p1->name)==0){
			printf("Number:%s Name:%s Author:%s Publisher:%s Status:%d Borrower:%s \n",p1->number,p1->name,p1->author,p1->publisher,p1->l,p1->f);
			if(p1->l==0){
				printf("This book is been borrowed.\n");
				printf("Press any key to back menu.\n");
				getch();
				menu();
			}
			else{
				printf("Press 1 to confirm | Press 2 to continue \n");
			}
			f=1;
			while(1){
				i=getch();
				if(i=='1'){
					p1->l=0;
					strcpy(p1->f,p->usrname);
					fp=fopen("book.txt","w");
					fclose(fp);
					p1=head;
					do{
                        savebook(p1);
                        p1=p1->next;
                    }while(p1->next!=NULL);
                    printf("Succeed.\n");
                    printf("Press any key to back menu.\n");
                    getch();
                    menu();
				}
				if(i=='2'){
					f=0;
					break;
				}
			}
		}
        p1=p1->next;
	}
	if(f==0){
		printf("No more result.Press any key to back menu.\n");
		getch();
		menu();
	}
}

void returnbook(){
	char pa[10],pa1[10];
	char us[10],bn[10];
	char i;
	int f=0;
	FILE *fp;
	account *p;
	book *p1,*head;
	p=loadaccount();
	printf("Please enter your username.\n");
	gets(us);
	while(p!=NULL){
		if(p!=NULL&&strcmp(us,p->usrname)==0){
			printf("Please enter password.\n");
			scanf("%s",pa);
			getchar();
			if(strcmp(pa,p->password)==0){
				printf("Verification passed.\n");
				break;
			}
			else{
				printf("Verification failed.Soon back menu.\n");
				Sleep(3000);
				menu();
			}
		}
		p=p->next;
		if(p==NULL){
			printf("This user is not existed.Soon back menu.\n");
			Sleep(3000);
			menu();
		}
	}
	head=loadbook();
	p1=head;
	printf("Please enter the name of book that you want to return.\n");
	gets(bn);
	while(p1->next!=NULL){
		if(p1->next!=NULL&&strcmp(bn,p1->name)==0){
            f=1;
			printf("Number:%s Name:%s Author:%s Publisher:%s Status:%d Borrower:%s \n",p1->number,p1->name,p1->author,p1->publisher,p1->l,p1->f);
			printf("Press 1 to confirm | Press 2 to continue \n");
			}
        while(1){
            i=getch();
            if(i=='1'){
                if(strcmp(us,p1->f)!=0){
                    printf("You have not borrowed this book.\n");
                    printf("Press any key to back menu.\n");
                    getch();
                    menu();
                }
                p1->l=1;
                strcpy(p1->f,"N");
                fp=fopen("book.txt","w");
                fclose(fp);
                if(fp==NULL){
                    printf("loading is failed");
                }
                p1=head;
                do{
                    savebook(p1);
                    p1=p1->next;
                }while(p1->next!=NULL);
                printf("Succeed.\n");
                printf("Press any key to back menu.\n");
                getch();
                menu();
            }
            if(i=='2'){
                f=0;
                break;
            }
        }
        p1=p1->next;
	}
	if(f==0){
		printf("No more result.Press any key to back menu.\n");
		getch();
		menu();
	}
}
