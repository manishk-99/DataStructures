#include <bits/stdc++.h>
using namespace std;
struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
};

struct Node* newNode(int data)
{
    struct Node* node = new Node;
    node->data = data;
    node->left = node->right = NULL;
 
    return(node);
}

struct Node* insert(struct Node* root, int x) {
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node*));
    temp->data = x;
    temp->left = NULL;
    temp->right = NULL;
    if(root == NULL) {
        root = temp;
    }
    else if(x <= root->data) {
        root->left = insert(root->left, x);
    } else {
        root->right = insert(root->right, x);
    }
    return root;
}
struct bst {
    bool isBST;
    int size;
    int min;
    int max;
};

bst largestBST(Node* root) {
    if(root == NULL) {
        bst b = {true,0,INT_MAX,INT_MIN};
        return b;
    }
    bst l = largestBST(root->left);
    bst r = largestBST(root->right);
    if(l.isBST && r.isBST && l.max < root->data && r.min > root->data) {
        bst b = {true,1+r.size+l.size,min(l.min,root->data),max(r.max,root->data)};
        return b;
    } else {
        bst b = {false,max(l.size, r.size),-1,-1};
        return b;
    }
}


int main() {
    struct Node *root = newNode(60);
    root->left = newNode(65);
    root->right = newNode(70);
    root->left->left = newNode(50);
    bst ans = largestBST(root);
    cout<<ans.size<<endl;
}