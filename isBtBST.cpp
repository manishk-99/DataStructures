#include<bits/stdc++.h>
using namespace std;

struct Node {
     char data;
     Node*left;
     Node*right;
};
Node* root = NULL;
struct Node* insert(struct Node* root, char x) {
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

bool isBstUtil(Node* root, int minValue, int maxValue) {
    if(root == NULL) {
        return true;
    }
    if(root->data > minValue && root->data < maxValue && isBstUtil(root->left, minValue, root->data) && isBstUtil(root->right, root->data, maxValue)) {
        return true;
    }
    else {
        return false;
    }
}

bool IsBST(Node* root) {
    return (isBstUtil(root, INT_MIN, INT_MAX));
}

int main() {
    root = insert(root,'F');
    root = insert(root,'D');
    root = insert(root,'J');
    root = insert(root,'B');
    root = insert(root,'E');
    root = insert(root,'A');
    root = insert(root,'C');
    root = insert(root,'G');
    root = insert(root,'K');
    root = insert(root,'I');
    root = insert(root,'H');
    if(IsBST(root))  {
        cout<<"Yes"<<endl;
    } else {
        cout<<"No"<<endl;
    }
}