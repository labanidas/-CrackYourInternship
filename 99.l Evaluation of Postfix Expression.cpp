class Solution
{
    public:
    //Function to evaluate a postfix expression.
    int evaluatePostfix(string s)
    {
        stack<int> st;
        
        for(char c: s){
            if(isdigit(c)){
                st.push(c-'0');
            }else{
                int n1 = st.top(); st.pop();
                int n2 = st.top(); st.pop();
                
                switch(c){
                    case '-': st.push(n2-n1); break;
                    case '+': st.push(n2+n1); break;
                    case '*': st.push(n2*n1); break;
                    case '/': st.push(n2/n1); break;
                }
            }
        }
        return st.top();
    }
};
