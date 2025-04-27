#include<stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node* next;
};

struct node* createNode(int data){
    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    newNode->data = data;
    newNode->next = NULL;
    
    return newNode;
}

void insert(struct node** head,int val){
    struct node* newNode = createNode(val);

    if(*head == NULL){
        *head = newNode;
        return;
    }
    struct node* temp = NULL;
    temp = *head;
    while(temp->next != NULL){
        temp = temp->next;
    }
    temp->next = newNode;
}

void printList(struct node* head){
    struct node* temp = NULL;
    temp = head;
    while(temp != NULL){
        printf("%d-> ",temp->data);
        temp = temp->next;
    }
    printf("null\n");
}

void deleteFromBeginning(struct node** head){
    if(*head == NULL){
        return;
    }
    struct node* temp = *head;
    *head = (*head)->next;
    free(temp);
}

void deleteFromEnd(struct node** head){
    struct node* temp = *head;
    while(temp->next->next != NULL){
        temp = temp->next;
    }
    free(temp->next);
    temp->next = NULL;
}

void deleteAtPosition(struct node** head, int pos){ 
    if(*head == NULL && pos < 1){
        return;
    }
    struct node* temp = *head;
    if(pos == 1){
        *head = (*head)->next;
        free(temp);
        return;
    }
    for(int i=1;i<pos-1 && temp != NULL;i++){
        temp = temp->next;
    }

    if(temp == NULL || temp->next == NULL){
        return;
    }
    struct node* deleted = temp->next;
    temp->next = temp->next->next;
    free(deleted);
}

void deleteByValue(struct node** head, int val){
    struct node* temp = *head;
    struct node* prev = NULL;
    while( temp != NULL && temp->data != val){
        prev = temp;
        temp = temp->next;
    }
    if(temp == NULL){
        return;
    }
    if(prev == NULL){
        *head = temp->next;
    }else{
        prev->next = temp->next;
    }
    free (temp);
}

void removeDuplicatesSorted(struct node* head){
    struct node* temp = head;
    while(temp != NULL && temp->next != NULL){
        if(temp->data == temp->next->data){
            struct node* tobedelte = temp->next;
            temp->next = tobedelte->next;
            free(tobedelte);
        }else{
            temp = temp->next;
        }
    }
}

void removeDuplicatesUnsorted(struct node* head){
  struct node* temp = head, *prev = NULL, *curr = NULL;
  while(temp != NULL){
    prev = temp;
    curr = temp->next;
    while(curr != NULL){
        if(curr->data == temp->data){
            prev->next = curr->next;
            struct node* tobedelted = curr;
            free(tobedelted);
        }else{
            prev = curr;
            curr = curr->next;
        }
    }
    temp = temp->next;
  }
}

int main(){

    struct node* head = NULL;

    insert(&head,10);
    insert(&head,20);
    insert(&head,30);
    insert(&head,40);
    insert(&head,50);
    insert(&head,60);
    insert(&head,70);
    printf("Original List: \n");
    printList(head);

    // Delete from the beginning
    deleteFromBeginning(&head);
    printf("\nAfter deleting from beginning: \n");
    printList(head);

    // Delete from the end
    deleteFromEnd(&head);
    printf("\nAfter deleting from end: \n");
    printList(head);

    // Delete at position 2
    deleteAtPosition(&head, 2);
    printf("\nAfter deleting at position 2: \n");
    printList(head);

    // Delete by value (value = 30)
    deleteByValue(&head, 30);
    printf("\nAfter deleting value 30: \n");
    printList(head);

    // Remove duplicates from sorted list
    removeDuplicatesSorted(head);
    printf("\nAfter removing duplicates (sorted): \n");
    printList(head);

    // Insert more elements for unsorted list removal
    insert(&head, 20);
    insert(&head, 50);
    insert  (&head, 20);

    printf("\nAfter inserting more elements: ");
    printList(head);

    // Remove duplicates from unsorted list
    removeDuplicatesUnsorted(head);
    printf("\nAfter removing duplicates (unsorted): ");
    printList(head);

    // // Delete the entire list
    // deleteEntireList(&head);
    // printf("\nAfter deleting entire list: ");
    // printList(head);

    return 0;
}