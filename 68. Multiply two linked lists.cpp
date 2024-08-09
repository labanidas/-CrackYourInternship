class solution {
  public:
    long long mod = 1e9+7;
    
    long long findNumber(Node* head){
        long long num = 0;
        
        while(head!=nullptr){
            num = (num*10 + head->data) % mod;
            head=head->next;
        }
        
        return num;
    }
    
    long long multiplyTwoLists(Node *first, Node *second) {
       
       long long n1 = findNumber(first);
       long long n2 = findNumber(second);
       
       long long ans = (n1*n2) % mod;
       
       return ans;
    }
};
