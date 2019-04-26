#include<stdio.h>
#include<stdlib.h>
#include<conio.h> 
#include<string.h>
#include<unistd.h> 
#include "book.h"
#include "account.h"
#include "borrowreturn.h"
#include "menu.h"

account loadaccount(){
	FILE *fp;
	int n=0;
	account *head,*p,*p1;
	fp=fopen("account","ab+");
	if(fp==NULL){
		printf("loading is failed\n");
	}
	while(!feof(fp)){
		n++;
		p=(account*)malloc(sizeof(account));
		fread(p,sizeof(account),1,fp);
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

void regist(){
	system("cls");
	char pa,pa1;
	char i;
	account *p,*p1;
	p=(account*)malloc(sizeof(account));
	while(1){
		printf("Please enter your username.\n");
		scanf("%s",%p->usrname);
		getchar();
		printf("Please enter your password.\n");
		scanf("%s",&pa);
		getchar();
		printf("Enter password again to confirm.\n");
		scanf("%s",&pa1);
		getchar();
		if(strcmp(pa,pa1)==0){
			p->password=pa;
			printf("In processing...\n");
			sleep(2);
			*p1=loadaccount();
			while(p1!=NULL){
				if(strcmp(p->usrname,p1->usrname)==0){
					printf("A same user was existed.");
					printf("Press any key to back menu\n");
					getch();
					menu();
				}
				p1=p1->next;
			}
			saveaccount(p);
			printf("Succeed.Soon back to menu\n");
			Sleep(3000);
			menu();
		}
		else{
			printf("Error password.\n");
			printf("Press 1 to retry | Press 2 to back menu\n");
			while(1){
				i=getch();
				if(i=='1'){
					break;
				}
				if(i=='2'){
					menu();
				}
				else{
					printf("Invalid. Please press "1" or "2"\n");
				}
			}
		}
	}
}

void loga(){
	char pa,pa1;
	FILE *fp;
	printf("Please enter password.\n");
	scanf("%s",&pa)
	getchar();
	fp=fopen("administrator","r");
	fread=(char,100,1,fp);
	fclose(fp);
	pa1=fp;
	if(strcmp(pa,pa1)==0){
		printf("Verification passed.\n");
		return;
	}
	else{
		printf("Verification failed.Soon back menu.\n");
		sleep(3);
		menu();
	}
}

void saveaccount(account *p){
	FILE *fp;
	fp=fopen("account","ab");
	if(fp==NULL){
		printf("loading is failed");
	}
	fwrite(p,sizeof(p),1,fp);
	fclose(fp);
}

void printaccount(){
	system("cls");
	account *head,*p;
	head=loadaccount();
	if(head==NULL){
		printf("No user exists.Soon back menu.\n");
		sleep(3);
		menu();
	}
	p=head();
	while(p!=NULL){
		printf("Username:%s \n",p->usrname);
		printf("\n");
	}
	printf("-------------------------------------------------\n");
	printf("Press any key to back menu.\n");
	getch();
	menu();
}
