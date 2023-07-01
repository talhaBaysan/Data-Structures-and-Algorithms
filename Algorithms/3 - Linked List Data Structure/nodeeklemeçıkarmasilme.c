#include<stdio.h>
#include<stdlib.h>

typedef struct node{
	int data;
	struct node *next;
}NODE;

NODE *head=NULL;
NODE *create_node();
void insert_at_begin(int d);
void insert_at_end(int d);
void traverse();
void delete_at_begin();
void delete_at_end();
int main(){
	int data;
	int i=0;
	while(i!=6){
		
		printf("\nenter choice\n\n 1-insert begin\n 2-insert end \n 3-traverse");
		printf("\n 4-delete begin\n 5-delete end \n 6-exit\nChoice:"); 
		scanf("%d", &i);
		
		if(i==1){
			printf("enter data: "); scanf("%d", &data);
			insert_at_begin(data);
		}
		else if(i==2){
			printf("enter data: "); scanf("%d", &data);
			insert_at_end(data);
		}
		else if(i==3){
			traverse();
		}
		else if(i==4){
			delete_at_begin();
		}
		else if(i==5){
			delete_at_end();
		}
	}

	
	head=NULL;
	return 0;
}
void delete_at_begin(){
	NODE *tmp;
	int n;
	
	if(head==NULL){
		printf("\nlist is empty!!");
		return;
	}
	n=head->data;
	tmp=head->next;
	free(head);
	head=tmp;
	printf("\n%d was deleted", n);
	
}

void delete_at_end(){
	NODE *u;
	NODE *tmp;
	int n;
	
	if(head==NULL){
		printf("\nlist is empty!!");
		return;
	}
	if(head->next==NULL){
		n=head->data;
		free(head);
		head=NULL;
		printf("\n%d was deleted", n);
		return;
	}
	tmp=head;
	while(tmp->next!=NULL){
		u=tmp;
		tmp=tmp->next;
	}
	n=tmp->data;
	u->next=NULL;
	free(tmp);
	printf("\n%d was deleted", n);
	
}

void insert_at_begin(int d){
	NODE *tmp=create_node();
	tmp->data=d; // eðer kapatýrsak
	if(head==NULL){
		head=tmp;
		head->next=NULL;
		//head->data=d;
	}
	else{
		tmp->next=head;
		head=tmp;
		//head->data=d;
	}
}

void insert_at_end(int d){
	NODE *n=create_node();
	NODE *tmp;
	n->data=d;
	if(head==NULL){
		head=n;
		head->next=NULL;
		return;
	}
	else{
		tmp=head;
		while(tmp->next!=NULL){
			tmp=tmp->next;
		}
		tmp->next=n;
		n->next=NULL;
	}
}

void traverse(){
	NODE *tmp;
	tmp=head;
	if(tmp==NULL){
		printf("list is empty\n");
		return;
	}
	printf("element in list are listed below\n[");
	while(tmp->next!=NULL){
		printf("%d -> ", tmp->data);
		tmp= tmp->next;
	}
	printf("%d]\n", tmp->data);
}


NODE *create_node(){
	return (NODE *)malloc(sizeof(NODE));
}





















