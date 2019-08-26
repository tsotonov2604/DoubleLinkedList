//DOUBLY LINKED LIST 

#include<stdio.h>
#include<stdlib.h>

struct Node{ 
    int data; 
    struct Node* next; 
    struct Node* prev;
}; 

struct Node* head; //global variable -- pointer to head node 
struct Node* GetNewNode (int x) { 
    // node is created in heap so the node is not removed from memory 
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));  // creation of a node in heap, so it is not removed until told so
    //^ newNode is a pointer variable which allows for access of newly created node
    newNode -> data = x; 
    newNode -> prev = NULL; 
    newNode -> next = NULL; 
    return &newNode; //returns a pointer to new node 
}
int main(){
    head = NULL ; //empty list 
    InsertAtHead(2); Print();ReversePrint();
    InsertAtHead(4); Print();ReversePrint();
    InsertAtHead(6); Print();ReversePrint();
}
void InsertAtHead(x){
   struct Node* newNode = GetNewNode(x);  //newNode is local to insertathead function, so different from other getnewnode function
    if ( head == NULL) { 
        head = newNode; 
        return; 
    }
    head -> prev = newNode; 
    newNode -> next = head; 
    head = newNode; 
}

Print(){
    struct Node* temp = head; // temporary pointer to head 
    printf("Forward: ");
    while(temp != NULL) {
        printf("%d",tmep ->data);
        temp = temp -> next; //go to next node 
    }
    printf("\n");
}

ReversePrint(){
    struct Node* temp = head; 
    if (temp == NULL) return; //empty list, exit 
    //Going to last Node 
    while(temp -> next != NULL) { 
        temp = temp ->next;
    }
    //Traverse backwards using prev pointer 
    printf("Reverse: "); 
    while(temp != NULL){
        printf("%d ", temp -> data); 
        temp = temp -> prev; 
    }
    printf("\n");
}
