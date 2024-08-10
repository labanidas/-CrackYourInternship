struct Node
{
    int data;
    struct Node* next;

    Node(int x){
        data = x;
        next = NULL;
    }
};
*/
class Solution {
  public:
    Node* divide(Node* head) {
        vector<int> even;
        vector<int> odd;
        
        Node* ptr = head;
        while(ptr){
            if(ptr->data%2==0)
                even.push_back(ptr->data);
            ptr = ptr->next;
        }
        
         ptr = head;
        while(ptr){
            if(ptr->data%2==1)
                odd.push_back(ptr->data);
            ptr = ptr->next;
        }
        
        ptr= head;
        
        for(int i=0; i<even.size(); i++){
            ptr->data = even[i];
            ptr = ptr->next;
        }
        for(int i=0; i<odd.size(); i++){
            ptr->data = odd[i];
            ptr = ptr->next;
        }
        
       return head;
    }
};
