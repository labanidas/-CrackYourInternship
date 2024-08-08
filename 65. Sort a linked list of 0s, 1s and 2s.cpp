// Online C++ compiler to run C++ program online
#include <bits/stdc++.h>
using namespace std;

// A linked list node
class Node {
public:
    int data;
    Node* next;

    // Constructor to initialize a new node with data
    Node(int new_data) {
        data = new_data;
        next = nullptr;
    }
};

void printList(Node* node) {
    while (node != nullptr) {
        cout << " " << node->data;
        node = node->next;
    }
      cout << "\n";
}

void sortList(Node* head){
    int x=0, y=0, z=0;
    Node* curr = head;
    
    while(curr!= nullptr){
        if(curr->data == 0) x++;
        if(curr->data == 1) y++;
        if(curr->data == 2) z++;
        curr = curr->next;
    }
    curr=head;
    
    while(x!=0){ curr->data = 0; x--; curr = curr->next; }
    while(y!=0) { curr->data = 1; y--; curr = curr->next; }
    while(z!=0){ curr->data = 2; z--; curr = curr->next; }
}

int getRandomdataue() {
    return rand() % 3; // Generates a random number between 0 and 2
}

int main() {
    srand(time(0)); // Seed the random number generator
    
    Node* head = new Node(getRandomdataue());
    Node* curr = head;
    
    for(int _=1; _<10; _++){
        Node* temp = new Node(getRandomdataue());
        curr->next = temp;
        curr = temp;
    }

    cout << "Linked List before Sorting:";
    printList(head);

      // Function to sort the linked list
    sortList(head);

    cout << "Linked List after Sorting:";
    printList(head);


    return 0;
}
