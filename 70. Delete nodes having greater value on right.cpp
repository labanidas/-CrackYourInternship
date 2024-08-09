class Solution
{
    public:
    
    Node* reverse(Node* head){
        Node* temp;
        Node* prev = nullptr;
        Node* curr = head;
        while(curr!= nullptr){
            temp = curr->next;
            curr->next = prev;
            prev= curr;
            curr = temp;
        }
        return prev;
    }
    
    Node *compute(Node *head)
    {
        head = reverse(head);
        Node* curr = head->next;
        Node* prev = head;
        int mx = head->data;
        
        while(curr!=nullptr){
            if(curr->data < mx){
                prev->next = curr->next;
                curr = curr->next;
            }else{
                mx = curr->data;
                prev = curr;
                curr= curr->next;
            }
        }
        return reverse(head);
    }
    
};
