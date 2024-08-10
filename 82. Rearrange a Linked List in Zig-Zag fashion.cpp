// Online C++ compiler to run C++ program online
#include <bits/stdc++.h> 
using namespace std; 
  
/* Link list Node */
struct Node { 
    int data; 
    struct Node* next; 
}; 

void reorderList(Node* head) {
        if (!head) return;

    // Step 1: Compute the size of the list
    int size = 0;
    Node* ptr = head;
    while (ptr) {
        ptr = ptr->next;
        size++;
    }

    // Step 2: Store the values in an array
    ptr = head;
    int* arr = new int[size];
    int i = 0;
    while (ptr) {
        arr[i++] = ptr->data;
        ptr = ptr->next;
    }

    // Step 3: Sort the array
    sort(arr, arr + size);

    // Step 4: Rearrange in zig-zag fashion
    int i1 = 0, i2 = size - 1;
    ptr = head;
    bool lessThan = true;

    while (ptr) {
        if(lessThan){   
            ptr->data = arr[i1++];
        }else{
            ptr->data = arr[i2--];
        }
        ptr = ptr->next;
        lessThan = !lessThan;
    }
}
/* UTILITY FUNCTIONS */
/* Function to push a Node */
void push(Node** head_ref, int new_data) 
{ 
    /* allocate Node */
    struct Node* new_Node = new Node; 
  
    /* put in the data  */
    new_Node->data = new_data; 
  
    /* link the old list of the new Node */
    new_Node->next = (*head_ref); 
  
    /* move the head to point to the new Node */
    (*head_ref) = new_Node; 
} 
  
/* Function to print linked list */
void printList(struct Node* Node) 
{ 
    while (Node != NULL) { 
        printf("%d->", Node->data); 
        Node = Node->next; 
    } 
    printf("NULL"); 
} 
  
/* Driver program to test above function*/
int main(void) 
{ 
    /* Start with the empty list */
    struct Node* head = NULL; 
  
    // create a list 4 -> 3 -> 7 -> 8 -> 6 -> 2 -> 1 
    // answer should be -> 3  7  4  8  2  6  1 
    push(&head, 1); 
    push(&head, 2); 
    push(&head, 6); 
    push(&head, 8); 
    push(&head, 7); 
    push(&head, 3); 
    push(&head, 4); 
  
    printf("Given linked list \n"); 
    printList(head); 
  
    reorderList(head); 
  
    printf("\nZig Zag Linked list \n"); 
    printList(head); 
  
    return (0); 
} 
  
