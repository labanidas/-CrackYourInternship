class Solution {
public:
       // Function to reverse a linked list
    Node* reverseList(Node* head) {
        Node* prev = nullptr;
        Node* curr = head;
        while(curr){
            Node* temp = curr->next;
            curr->next = prev;
            prev = curr;
            curr = temp;
        }
        return prev;
    }
    
    // Function to remove leading zeros from a linked list
    Node* removeLeadingZeros(Node* head) {
       while(head && head->data == 0)
        head = head->next;
        
        return head == nullptr ? new Node(0) : head;
    }
    
    // Function to determine which linked list represents a larger number
    // Returns a pair where the first element is the larger and the second is the smaller list
    pair<Node*, Node*> getLargerSmaller(Node* head1, Node* head2) {
        Node* temp1 = head1;
        Node* temp2 = head2;
    
        // Compare lengths
        int len1 = 0, len2 = 0;
        while (temp1 != nullptr) {
            len1++;
            temp1 = temp1->next;
        }
        while (temp2 != nullptr) {
            len2++;
            temp2 = temp2->next;
        }
    
        if (len1 > len2) return {head1, head2};
        if (len2 > len1) return {head2, head1};
    
        // If lengths are the same, compare digit by digit
        temp1 = head1;
        temp2 = head2;
        while (temp1 != nullptr) {
            if (temp1->data > temp2->data) return {head1, head2};
            if (temp2->data > temp1->data) return {head2, head1};
            temp1 = temp1->next;
            temp2 = temp2->next;
        }
    
        return {head1, head2};  // If they are equal, it doesn't matter which is returned first
    }
    
    // Function to subtract two linked lists
    Node* subLinkedList(Node* head1, Node* head2) {
        // Remove leading zeros
        head1 = removeLeadingZeros(head1);
        head2 = removeLeadingZeros(head2);
    
        // Determine larger and smaller linked lists
        pair<Node*, Node*> heads = getLargerSmaller(head1, head2);
        head1 = heads.first;
        head2 = heads.second;
    
        // Reverse both linked lists
        head1 = reverseList(head1);
        head2 = reverseList(head2);
    
        int carry = 0;
        Node* dummy = new Node(0);
        Node* curr = dummy;
    
        while (head1) {
            int n1 = head1->data - carry;
            int n2 = head2 ? head2->data : 0;
    
            if (n1 < n2) {
                carry = 1;
                n1 += 10;
            } else {
                carry = 0;
            }
    
            curr->next = new Node(n1 - n2);
            curr = curr->next;
    
            head1 = head1->next;
            if (head2) head2 = head2->next;
        }
    
        // Reverse the result and remove leading zeros
        Node* result = reverseList(dummy->next);
        result = removeLeadingZeros(result);
    
        return result;
    }

};
