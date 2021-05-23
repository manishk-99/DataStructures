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

bool isSubTreeLesser(Node* root, int value) {
    if(root == NULL) {
        return true;
    }
    if(root->data <= value && isSubTreeLesser(root->left, value) && isSubTreeLesser(root->right, value)) {
        return true;
    } else {
        return false;
    }
}

bool isSubTreeGreater(Node* root, int value) {
    if(root == NULL) {
        return true;
    }
    if(root->data > value && isSubTreeGreater(root->left, value) && isSubTreeGreater(root->right, value)) {
        return true;
    } else {
        return false;
    }
}


bool IsBST(Node* root) {
    if(root == NULL) {
        return true;
    }
    if(isSubTreeLesser(root->left, root->data) && isSubTreeGreater(root->right, root->data) && IsBST(root->left) && IsBST(root->right)) {
        return true;
    } else {
        return false;
    }
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