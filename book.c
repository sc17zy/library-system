#include<stdio.h>
#include<stdlib.h>
#include<conio.h> 
#include<string.h>
#include<unistd.h> 

book loadbook(){
	FILE *fp;
	int n=0;
	book *head,*p,*p1;
	fp=fopen("book","ab+");
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
		scanf("%s",&p->number);
		getchar();
		printf("Input name of book\n");
		scanf("%s",&p->name);
		getchar();
		printf("Input author of book\n");
		scanf("%s",&p->author);
		getchar();
		printf("Input publisher of book\n");
		scanf("%s",&p->publisher);
		getchar();
		printf("Input the quantity of book\n");
		scanf("%d",&p->quantity);
		getchar();
		printf("saving...\n");
		savebook(p)
		printf("successed\n");
		printf("continue?...\n (press "1" to continue | press "2" to back menu)\n");
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
				printf("Invalid. Please press "1" or "2"\n");
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
	while(p!=NULL){
		if(p!=NULL&&(strcmp(p->number,info)==0||strcmp(p->name,info)==0||strcmp(p->author,info)==0||strcmp(p->publisher,info)==0)){
			f=1;
			printf("Number:%s Name:%s Author:%s Publisher:%s Quantity:%d Left:%d \n",p->number,p->name,p->author,p->publisher,p->quantity,p->quantity-p->l);
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
	if(f=0){
		printf("No more result.\n");
		printf("Press 1 to retry | Press 2 to back menu\n");
		while(1){
			k=getch();
			if(k=='1'){
				break.
			}
			if(k=='2'){
				menu();
			}
			else{
				printf("Invalid. Please press "1" or "2"\n");
			}
		}
	}	
}

void debook(){
	loga();
	while(1){
		system("cls");
		char j,o;
		FILE *fp
		book *head,*p,*p1;
		int i=0,f=0,k=0;
		head=loadbook();
		char nam[10];
		printf("Enter the name of book\n");
		scanf("%s",nam);
		p=head;
		p1=p;
		while(p!=NULL){
			if(p!=NULL&&strcmp(p->name,nam)==0){
				f=1;
				printf("Number:%s Name:%s Author:%s Publisher:%s \n",p->number,p->name,p->author,p->publisher);
				printf("Are you sure to delete this book?\n");
				printf("Press 1 to confirm | Press 2 to continue\n");
				while(1){
					j=getch();
					if(j=='1'){
						for(k=0;k<i-1;j++){
							p1=p1->next;
						}
						if(p->next!=NULL){
							p1->next=p->next;
						}
						if(p->next==NULL){
							p1->next=NULL;
						}
						free(p);
						fp=fopen("book","wb");
						if(fp==NULL){
							printf("loading is failed");
						}
						fwrite(head,sizeof(head),1,fp);
						fclose(fp);
						p=head;
						if(head!=NULL){
							fp=fopen("book","ab");
							if(fp==NULL){
								printf("loading is failed");
							}
							while(p!=NULL){
								p=p->next;
								fwrite(p,sizeof(p),1,fp);
							}
							fclose(fp);
						}
						printf("Succeed.\n");
						sleep(1.5);
						menu();
					}
					if(j='2'){
						f=0;
						break;
					}
					else{
						printf("Invalid. Please press "1" or "2"\n");
					}
				}
			p=p->next;
			i++;
		}
		if(f=0){
			printf("No more result.Press 1 to retry | Press 2 to back menu\n");
		}
		while(1){
			o=getch();
			if(o=='1'){
				break;
			}
			if(o=='2'){
				menu();
			}
			else{
				printf("Invalid. Please press "1" or "2"\n");
			}
		}
	}
}

void printbook(){
	system("cls");
	book *head,*p,*h;
	int sum=0;
	head=loadbook();
	if(head==NULL){
		printf("No book in this library.Soon back menu.\n");
		sleep(3);
		menu();
	}
	p=head;
	while(p!=NULL){
		printf("Number:%s Name:%s Author:%s Publisher:%s Quantity:%d Left:%d \n",p->number,p->name,p->author,p->publisher,p->quantity,p->quantity-p->l);
		sum=sum+p->quantity;
		h=borrowinfo();
		while(h!=NULL){
			printf("Borrower: User: %s \n",h->usr);
			h=h->next;
		}
		printf("\n");
	}
	printf(" The total number of books is %d \n",sum);
	printf("--------------------------------------------------\n");
	printf(" Press any key to back menu.\n");
	getch();
	menu();
}

void savebook(book *p){
	FILE *fp;
	fp=fopen("book","ab");
	if(fp==NULL){
		printf("loading is failed");
	}
	fwrite(p,sizeof(p),1,fp);
	fclose(fp);
}


