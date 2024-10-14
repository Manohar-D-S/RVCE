#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

bool flag = false;  // Use a boolean flag to check if the list is initialized

struct LinkedList {
    int data;
    struct LinkedList *next;
} typedef LL;

LL insert(int data, LL list) {
    if (!flag) {  // If the list is not initialized, create the first node
        list.data = data;
        list.next = NULL;
        flag = true; 
        printf("Data has been inserted to the new node.\n");
        return list;  
    }

    LL *node = &list;
    while (node->next != NULL) {
        node = node->next;
    }

    node->next = (LL*)malloc(sizeof(LL));
    node->next->data = data;
    node->next->next = NULL;
    printf("Data Inserted.\n");

    return list;  
}

LL insertAfter(int data, int after, LL list) {
    if (!flag) {
        printf("List is Empty!!!\n");
        return list;
    }

    LL *node = &list;
    while (node != NULL && node->data != after) {
        node = node->next;
    }

    if (node == NULL) {
        printf("The element that you wanted to append after wasn't found. Do you want to append the data at the end?\n[Y]es\n[N]o\n");
        char opt;
        scanf(" %c", &opt);  // Added space before %c to consume the newline from previous input
        if (opt == 'Y' || opt == 'y') {
            list = insert(data, list);  
        } else {
            printf("Operation Aborted!!\n");
        }
        return list;
    } else {
        LL *newNode = (LL*)malloc(sizeof(LL));
        newNode->data = data;
        newNode->next = node->next;
        node->next = newNode;
        printf("%d inserted after first occurrence of %d\n", data, after);
    }

    return list;
}

void traverse(LL list) {
    if (!flag) {
        printf("List is Empty!!!\n");
        return;
    }

    LL *node = &list;
    while (node != NULL) {
        printf("%d\t", node->data);  
        node = node->next;  
    }
    printf("\n");
}

LL delete(int data, LL list){
	if (!flag) {
        printf("List is Empty!!!\n");
        return list;
    } 

	LL *node = &list;
	if (node->data == data){				//if the deleting data is in the first node
		LL* rtrn = node->next;
		return *rtrn;
	}
	while(node->next != NULL && node->next->data != data){
		node = node->next;
	}

	if(node->next == NULL){
		printf("Element not found.\n");
	} else {
		LL* del = node->next;
		node->next = del->next;
		free(del);
	}
	return list;
}

int main() {
    LL list1 = {0, NULL};  
    int opt = 1;

    while (opt) {
        printf("\nChoose the operation that you want to implement on the Linked List:\n");
        printf("1) Insert\n");
        printf("2) Insert After an element\n");
        printf("3) Display The List\n");
		printf("4) Delete\n");
        printf("5) Exit\n\n");
        printf("Enter the option: ");
        scanf("%d", &opt);
        system("clear");

        switch (opt) {
            int num, after;
            case 1:
                printf("Enter the data you want to Insert: ");
                scanf("%d", &num);
                list1 = insert(num, list1);  
                break;
            case 2:
                printf("Enter the data you want to INSERT: ");
                scanf("%d", &num);
                printf("Enter the data you want to INSERT AFTER: ");
                scanf("%d", &after);
                list1 = insertAfter(num, after, list1);  
                break;
            case 3:
                traverse(list1);  
                break;
			case 4:
				printf("Enter the data you want to DELETE: ");
                scanf("%d", &num);
                list1 = delete(num, list1);  
                break;
            case 5:
                opt = 0;  // Exit the loop
                break;
            default:
                printf("Invalid Option.\n");
        }
    }

    printf("Program Ended.\nThank You\n");

    return 0;
}
