#include <stdio.h>
#include <stdlib.h>

//        |-> |====| --> |====| ---> |====| -----|
//        |-------------------------------------|


struct node
{
    int data;
    struct node *next;
}; typedef struct node* Node;

Node insert(int data, Node tail, short mode){
    Node newNode = (Node) malloc(sizeof(struct node));
    newNode->data = data;
    if(tail == NULL){
        newNode->next = newNode;                //point to itself
        return newNode;
    }
    newNode->next = tail->next;                 //point newNode to first element in te list
    tail->next = newNode;                       //and point last node to new first node
    return (mode == 0) ? tail : newNode;
    
}

Node delete(Node tail, short mode){
    Node del;
    if(tail == NULL){                         //if list is empty
        printf("List is Empty!!\n");
        return NULL;
    } else if (tail->next == tail) {          //if only one node
        printf("%d deleted\n", tail->data);
        free(tail);
        return NULL;
    } else if(mode == 0){                    //delete at beginning
        del = tail->next;
        tail->next = del->next;
    } else if(mode == 1){                    //to delete last node
        del = tail->next;                    //del = firs_node

        while (del->next != tail)            //traverse till the preceding element of tail
            del = del->next;
        
        tail = del;
        del = del->next;
        tail->next = del->next; 
    } else {
        perror("INVALID MODE\n");
        return tail;
    }
    printf("Element %d deleted\n", del->data);
    free(del);
    return tail;
}

void display(Node tail){                    //displays all node's data
    if(tail == NULL){
        printf("List is Empty\n");
        return;
    }
    Node node = tail->next;
    do{
        printf("%d\t", node->data);
        node = node->next;
    }while(node != tail->next);
    printf("\n");
}



int main(int argc, char const *argv[])
{
    Node list = NULL;
    int choice, data;
    short mode;

    while (1) {
        printf("\nCircular Linked List Menu\n");
        printf("1. Insert\n");
        printf("2. Delete\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        system("cls");

        switch(choice) {
            case 1:
                printf("Enter data to insert: ");
                scanf("%d", &data);
                printf("Enter mode (0 - insert at the beginning, 1 - insert at the end): ");
                scanf("%hd", &mode);
                list = insert(data, list, mode);
                break;
            case 2:
                printf("Enter mode (0 - delete from the beginning, 1 - delete from the end): ");
                scanf("%hd", &mode);
                list = delete(list, mode);
                break;
            case 3:
                display(list);
                break;
            case 4:
                printf("Exiting...\n");
                exit(0);
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }

    while (list != NULL)
    {
        delete(list, 0);
    }
    
    
    return 0;
}
