#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next, *prev;
};
typedef struct node* Node;
short supress_msg = 0;


Node search(Node list, int data, int* position){
    if(position != NULL)
        *position = 0;

    while(list != NULL){
        if(position != NULL)
            (*position)++;

        if(list->data == data)
            return list;
        
        list = list->next;
    }

    if(position != NULL)
        *position = -1;

    return NULL;
}

int len(Node list){
    int len = 0;
    while(list != NULL){
        len++;
        list = list->next;
    }
    return len;
}

Node insert(Node list, int data, int mode){                 //mode argument decides where the node has to be inserted at
    Node newNode = (Node)malloc(sizeof(struct node));
    newNode->data = data;

    if(list == NULL){
        newNode->next = newNode->prev = NULL;
        return newNode;
    }  

    switch (mode) {
    case 0:                                             //to append at start
        newNode->next = list;
        newNode->prev = NULL;
        list->prev = newNode;
        return newNode;
    
    case 1:                                             //to append at end
        Node temp = list;
        while(temp->next != NULL)                       //traverse to the end node
            temp = temp->next;
        
        newNode->prev = temp;
        newNode->next = NULL;
        temp->next = newNode;
        return list;

    case 2:                                             //to append after the first occurence of an element
        int find;
        printf("Enter the element that you want to insert the node after : ");
        scanf("%d", &find);
        Node after = search(list, find, NULL);
        if(after != NULL){
            newNode->prev = after;
            newNode->next = after->next;
            after->next->prev = newNode;
            after->next = newNode;
        } else {                                                            //for invalid mode
        printf("The element that you wanted to insert after not found.\n");
        }
        return  list;

    default:
        printf("Invaid Mode!\n");
        free(newNode);
        return list;
    }
    
}

Node delete(Node list, int mode) {
    if (list == NULL)
    {
        printf("List is Empty\n");
        return NULL;
    }
    
    Node del = list;
    if (list->next == NULL){                    //if there's only one node
        list = NULL;
    } else if(mode == 0){                       //to delete the first node
        list = list->next;
        list->prev = NULL;
    } else if(mode == 1) {                      //to delete the last node
        while(del->next != NULL)
            del = del->next;
        
        del->prev->next = NULL;
    } else if (mode == 2){
        int find;
        printf("Enter the element that you want to delete(First occurence of the element will be deleted) : ");
        scanf("%d", &find);
        Node del = search(list, find, NULL);
        if(del != NULL){
            del->prev->next = del->next;
            del->next->prev = del->prev;
        } else {                                                            //for invalid mode
        printf("The element that you wanted to delelte was not found.\n");
        }
        return  list;
    }
    if(!supress_msg)
        printf("%d deleted\n", del->data);


    free(del);

    return (list) ? list : NULL;
}

void display(Node list){
    if(list == NULL){
        printf("List is Empty!\n");
        return;
    }

    while(list != NULL){
        printf("%d\t", list->data);
        list = list->next;
    }
}


int main(int argc, char const *argv[]) {
    Node list = NULL;
    int choice, data;

    while (1) {
        system("clear"); 
        printf("\nMenu:\n");
        printf("1. Insert\n");
        printf("2. Delete\n");
        printf("3. Display List\n");
        printf("4. Position of Element\n");
        printf("5. Length of List\n");
        printf("6. Exit\n\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        system("clear"); 

        switch (choice) {
            case 1: {
                int mode;
                printf("Enter data to insert: ");
                scanf("%d", &data);
                if(list != NULL) {
                printf("0] At Start\n");
                printf("1] At End\n");
                printf("2] After an element\n");
                printf("How do you want to insert %d : ", data);
                scanf("%d", &mode);
                } else {
                    mode = 0;
                }
                list = insert(list, data, mode);
                break;
            }
            
            case 2: {
                if(list == NULL){
                    printf("List is Empty.\n");
                    break;
                }
                int mode;
                
                if (list->next != NULL) {
                    printf("0] First Node\n");
                    printf("1] Last Node\n");
                    printf("2] A certain element\n\n");
                    printf("Mode: ");
                    scanf("%d", &mode);
                } else {
                    mode = 0;
                }
                list = delete(list, mode);
                break;
            }
            
            case 3:
                display(list);
                printf("\n");
                break;

            case 4: {
                int pos, find;
                printf("Element to find: ");
                scanf("%d", &find);
                Node result = search(list, find, &pos);
                if (result == NULL) {
                    printf("Element not found!!\n");
                } else {
                    printf("Element %d found at position %d of the list.\n", find, pos);
                }
                break;
            }

            case 5:
                printf("Length of the list is %d\n", len(list));
                break;

            case 6:
                // Free all nodes before exiting
                supress_msg = 1;
                while (list != NULL) {
                    list = delete(list, 0);
                }
                printf("Exiting program.\n");
                return 0;

            default:
                printf("Invalid choice. Please try again.\n");
        }
        printf("\nPress Enter to continue...");
        getchar(); getchar(); // Pause for user input
    }
    return 0;
}
