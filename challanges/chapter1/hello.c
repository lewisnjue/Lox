#include <stdio.h> 
#include <stdlib.h>
/* to get some practice with pointers, define a
doubly linked list of heap-allocated strings. Write functions to insert,
find, and delete items from it. Test them.*/
struct node
{
    char* data;
    struct node* next;
    struct node* prev;
};

int main(){
    // create a new node 
    struct node* head = (struct node*)malloc(sizeof(struct node)); 
    struct node* second = (struct node*)malloc(sizeof(struct node)); 
    struct  node* third = (struct node*)malloc(sizeof(struct node)); 
    struct node* fourth = (struct node*)malloc(sizeof(struct node)); 
    struct node* fifth = (struct node*)malloc(sizeof(struct node)); 
    head->prev = NULL; 
    head->next = second;
    second->prev = head;
    second->next = third;
    third->prev = second;
    third->next = fourth;
    fourth->prev = third;
    fourth->next = fifth;
    fifth->prev = fourth;
    fifth->next = NULL; 
    head->data = "Hello"; 
    second->data = "World!";
    third->data = "This";   
    fourth->data = "is";
    fifth->data = "Lox!"; 
    // print the list 
    for(struct node* current = head; current != NULL; current = current->next){
        printf("%s ", current->data); 
        printf("\n"); 
    }; 
    // deallocate the list 
    free(head);free(second);free(third);free(fourth);free(fifth);
    

    return 0;
}