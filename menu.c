#include<stdio.h>
#include<stdlib.h>
#include<conio.h> 
#include<string.h>
#include "book.h"
#include "account.h"
#include "borrowreturn.h"
#include "menu.h"

void menu(){
	system("cls");
	char i;
	printf("Library System UI\n");
	printf("1:Book overview\n");
	printf("2:Find book\n");
	printf("3:Registration\n");
	printf("------------------------------------------------------\n");
	printf("Students Only\n");
	printf("4:Borrow book\n");
	printf("5.Return book\n");
	printf("------------------------------------------------------\n");
	printf("Administrator Only\n");
	printf("6:Add book\n");
	printf("7:Delete book\n");
	printf("8:Account overview\n");
	printf("------------------------------------------------------\n");
	printf("9:Exit\n");
	printf("Please press 1-9 key\n");
	while(1){
		i=getch();
		switch(i){
			case '1': printbook();
			break;
			case '2': findbook();
			break;
			case '3': regist();
			break;
			case '4': borrow();
			break;
			case '5': returnbook();
			break;
			case '6': addbook();
			break;
			case '7': debook();
			break;
			case '8': printaccount();
			break;
			case '9': exit();
			break;
			default: printf("Invalid.Please press 1-7 key.\n");
			break;
		}
	}
}

void exit(){
	char i;
	print("Sure to exit?\n");
	print("Press 1 to confirm | Press 2 to back menu\n");
	while(1){	
		i=getch();
		if(i=='1'){
			printf("Thanks for using.\n");
			exit(0);
		}
		if(i=='2'){
			menu();
		}
		else{
			printf("Invalid.Please press 1 or 2 key.\n");
	}
}
