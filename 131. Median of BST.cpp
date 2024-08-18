vector<float> ans;

void inorder(struct Node *root){
    if(!root) return;
    
    inorder(root->left);
    ans.push_back(root->data);
    inorder(root->right);
    
}

float findMedian(struct Node *root)
{   
    ans.clear();
    inorder(root);
    int n= ans.size();
    if(n==0) return 0.0;
    else if(n%2==0) return (ans[n/2-1] + ans[n/2])/2.0;
    else return ans[n/2];
    
}
