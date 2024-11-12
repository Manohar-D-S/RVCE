#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node* next;
};

typedef struct node* NODE; // NODE now represents struct node*


NODE insert(int data, NODE list){
    NODE newNode = (NODE) malloc(sizeof(struct node));
    newNode->data = data;
    newNode->next = NULL;

    if(list == NULL){
        list = newNode;
    } else {
        NODE temp = list;
        while(temp->next != NULL)
            temp = temp->next;
        
        temp->next = newNode;
    }
    printf("%d has been inserted to Linked List.\n", data);
    return list;
}

NODE headInsert(int data, NODE list){
    NODE newNode = (NODE) malloc(sizeof(struct node));
    newNode->data = data;
    newNode->next = list;
    list = newNode;

    printf("%d has been inserted to Linked List.\n");
    return list;
}

NODE delete(NODE list){
    if(list == NULL){
        printf("Linked List is Empty.\n");
        return list;
    }
    int data;
    if (list->next == NULL){        //if only one node
        data = list->data;
        free(list);
        list = NULL;
    } else {            //for multiple nodes
        NODE current = list;
        while(current->next->next == NULL){
            current = current->next;
        }
        data = current->next->data;
        free(current->next);
        current->next = NULL;
    }
    printf("%d has been deleted.\n", data);
    return list;
}

NODE deleteHead(NODE list){
    if(list == NULL){
        printf("Linked List is Empty.\n");
        return list;
    }
    NODE temp = list;
    list = temp->next;      //or list = list->next;
    printf("%d deleted.\n", temp->data);
    free(temp);
    return list;
}

void display(NODE list) {
    if (list == NULL) {
        printf("Linked List is Empty.\n");
        return;
    }
    NODE temp = list;
    while (temp != NULL) {
        printf("%d --> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

int main(int argc, char const *argv[])
{
    NODE list = NULL;
    int choice, data;

    while (1) {
        printf("\nMenu:\n");
        printf("1. Insert at End\n");
        printf("2. Insert at Head\n");
        printf("3. Delete from End\n");
        printf("4. Delete from Head\n");
        printf("5. Display List\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        system("clear");
        switch (choice) {
            case 1:
                printf("Enter data to insert at end: ");
                scanf("%d", &data);
                list = insert(data, list);
                break;
            case 2:
                printf("Enter data to insert at head: ");
                scanf("%d", &data);
                list = headInsert(data, list);
                break;
            case 3:
                list = delete(list);
                break;
            case 4:
                list = deleteHead(list);
                break;
            case 5:
                display(list);
                break;
            case 6:
                // Free all nodes before exiting
                while (list != NULL) {
                    list = deleteHead(list);
                }
                printf("Exiting program.\n");
                return 0;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
    return 0;
}
