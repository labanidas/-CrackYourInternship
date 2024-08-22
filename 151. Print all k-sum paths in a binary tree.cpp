
// C++ program to print all paths with sum k.
#include <bits/stdc++.h>
using namespace std;
 
// binary tree node
struct Node {
    int data;
    Node *left, *right;
    Node(int x)
    {
        data = x;
        left = right = NULL;
    }
};

// utility function to print contents of
// a vector from index i to it's end
void printVector(const vector<int>& v, int i)
{
    for (int j = i; j < v.size(); j++)
        cout << v[j] << " ";
    cout << endl;
}

void printKPathUtil(Node* root, vector<int>& path, int k){
    if(!root) return;
    
    path.push_back(root->data);
    printKPathUtil(root->left, path, k);
    printKPathUtil(root->right, path, k);
    
    int sum = 0;
    for(int i=path.size()-1; i>=0; i--){
        sum += path[i];
        
        if(sum  == k){ printVector(path, i);}
    }
    
    path.pop_back();
}


// A wrapper over printKPathUtil()
void printKPath(Node* root, int k)
{
    vector<int> path;
    printKPathUtil(root, path, k);
}

// Driver code
int main()
{
    Node* root = new Node(1);
    root->left = new Node(3);
    root->left->left = new Node(2);
    root->left->right = new Node(1);
    root->left->right->left = new Node(1);
    root->right = new Node(-1);
    root->right->left = new Node(4);
    root->right->left->left = new Node(1);
    root->right->left->right = new Node(2);
    root->right->right = new Node(5);
    root->right->right->right = new Node(2);
 
    int k = 5;
    printKPath(root, k);
 
    return 0;
}
