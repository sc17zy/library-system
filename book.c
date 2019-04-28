#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<string.h>
#include<unistd.h> 
#include "book.h"
#include "account.h"
#include "borrowreturn.h"
#include "menu.h"

book *loadbook(){
	FILE *fp;
	int n=0;
	book *head=NULL;
	book *p,*p1=NULL;
	fp=fopen("book.txt","ab+");
	if(fp==NULL){
		printf("loading is failed");
	}
	while(!feof(fp)){
		n++;
		p=(book*)malloc(sizeof(book));
		fread(p,sizeof(book),1,fp);
		if(n==1){
			head=p;
			p1=p;
		}
		else{
			p1->next=p;
			p1=p;
		}
	}
	p1->next=NULL;
	fclose(fp);
	return head;
}

void addbook(){
	loga();
	while(1){
		system("cls");
		book *p;
		p=(book*)malloc(sizeof(book));
		printf("Input number of book\n");
		scanf("%s",p->number);
		getchar();
		printf("Input name of book\n");
		scanf("%s",p->name);
		getchar();
		printf("Input author of book\n");
		scanf("%s",p->author);
		getchar();
		printf("Input publisher of book\n");
		scanf("%s",p->publisher);
		getchar();
        p->l=1;
        strcpy(p->f,"N");
		printf("saving...\n");
		savebook(p);
		printf("Successed\n");
		printf("continue?...\n (press 1 to continue | press 2 to back menu)\n");
		char i;
		while(1){
			i=getch();
			if(i=='1'){
				break;
			}
			if(i=='2'){
				menu();
			}
			else{
				printf("Invalid. Please press 1 or 2\n");
			}
		}
	}
}

void findbook(){
	system("cls");
	char i,k;
	int f=0;
	book *head,*p;
	head=loadbook();
	char info[10];
	printf("Please enter some information of book.\n");
	gets(info);
	p=head;
	while(p->next!=NULL){
		if(p->next!=NULL&&(strcmp(p->number,info)==0||strcmp(p->name,info)==0||strcmp(p->author,info)==0||strcmp(p->publisher,info)==0)){
			f=1;
			printf("Number:%s Name:%s Author:%s Publisher:%s Status:%d Borrower:%s \n",p->number,p->name,p->author,p->publisher,p->l,p->f);
			printf("Is this book that you want?\n");
			printf("Press 1 to confirm | Press 2 to continue\n");
			while(1){
				i=getch();
				if(i=='1'){
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
		p=p->next;
	}
	if(f==0){
		printf("Can't find book.\n");
		printf("Press any key to back menu\n");
        getch();
        menu();
	}
}

void debook(){
	loga();
	while(1){
		system("cls");
		char j;
		FILE *fp;
		book *head,*p,*p1;
		int i=0,f=1,k=0;
		head=loadbook();
		char nam[10];
		printf("Enter the name of book\n");
		scanf("%s",nam);
		p=head;
		p1=head;
		while(p->next!=NULL){
			if(p->next!=NULL&&strcmp(p->name,nam)==0){
				printf("Number:%s Name:%s Author:%s Publisher:%s \n",p->number,p->name,p->author,p->publisher);
				printf("Are you sure to delete this book?\n");
				printf("Press 1 to confirm | Press 2 to continue\n");
				while(1){
					j=getch();
					if(j=='1'){
                        fp=fopen("book.txt","w");
                        fclose(fp);
                        do{
                            if(p1!=p){
                                savebook(p1);
                            }
                            p1=p1->next;
                        }while(p1->next!=NULL);
                        printf("Succeed.\n");
                        printf("Press any key to back menu.\n");
                        getch();
                        menu();
					}
                    if(j=='2'){
                        break;
                    }
                    else{
                        printf("Invalid. Please press 1 or 2\n");
                    }
                }
			}
            p=p->next;
            if(p->next==NULL){
                f=0;
            }
            if(f==0){
                printf("Can't find book.\n");
                printf("Press any key to back menu\n");
                getch();
                menu();
            }
        }
    }
}

void printbook(){
	system("cls");
	book *head,*p,*h;
	int sum=0;
	head=loadbook();
	if(head->next==NULL){
		printf("No book in this library.Soon back menu.\n");
		Sleep(3000);
		menu();
	}
	p=head;
	while(p->next!=NULL){
		printf("Number:%s Name:%s Author:%s Publisher:%s Status:%d Borrower:%s \n",p->number,p->name,p->author,p->publisher,p->l,p->f);
		sum=sum+1;
		printf("\n");
		p=p->next;
	}
	printf(" The total number of books is %d \n",sum);
	printf("--------------------------------------------------\n");
	printf(" Press any key to back menu.\n");
	getch();
	menu();
}

void savebook(book *p){
	FILE *fp;
	fp=fopen("book.txt","ab");
	if(fp==NULL){
		printf("loading is failed");
	}
	fwrite(p,sizeof(book),1,fp);
	fclose(fp);
}

