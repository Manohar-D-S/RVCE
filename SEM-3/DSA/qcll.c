#include <stdio.h>
#include <stdlib.h>
#define MAX 6

struct Node{
	int data;
	struct Node* next;
};

typedef Node* NODE;



NODE enqueue(NODE list, int data){
	NODE newNode = (NODE) malloc(sizeof(NODE));
	newNode->data = data;
	if(count == -1){
		list = newNode;
		newNode->next = list;
		return list;
	} else if(count = MAX - 1) {
		printf("Queue is Full\n");
		return list;
	} else {
		newNode->next = list->next;
		list->next = newNode;
		count++;
	}
	return newNode;
}


void dequeue(NODE list){
	if(count == -1){
		printf("List is empty\n");
		return;
	} else if(list->next == list){
		printf("%d dequeued\n", list->data);
		free(list);
		list = NULL;
		count--;
		return;
	} 

	NODE del = list->next;
	while(del->next != list)
		del = del->next;
	list = del;
	del = list->next;
	list->next = del->next;
	printf("%d dequeued\n", del->data);
	free(del);
	count--;
}

void display(NODE list){
	if(count == -1){
		printf("Queue is Empty\n");
	} else{
		NODE temp = list->next;
		printf("%d\t");
		while(temp->next != list->next){
			temp = temp->next;
			printf("%d\t");
		}
	}
}

	int count;

int main(){
	NODE cll = NULL;
	int opt = 0;
	count = -1;

	while(1){
		printf("Choose the function you want to perform on the Queue : \n");
		printf("1] Enqueue\n2] Dequeue\n3] Display\n4] EXIT\n");
		printf("Enter the option : ");
		scanf("%d", opt);
		
		switch(opt){
			case 1:
    			int ele;
				printf("Enter the data to enqueue : ");
				scanf("%d", &ele);
				cll = enqueue(cll, ele);
				break;
			case 2:
				dequeue(cll);
				break;
			case 3:
				display(cll);
				break;
			case 4:
				printf("Bye..Bye...\n\n");
				exit(0);
				break;
			default:
				printf("Invalid option!! Try again\n\n");
		};
	}
}
