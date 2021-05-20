#include <iostream>
using namespace std;

struct Node {
     int data;
     Node*left;
     Node*right;
};
Node* root = NULL;
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

bool search(Node* root, int  data) {
    if(root == NULL) {
        return false;
    } 
    else if(root->data == data) {
        return true;
    }
    else if(data <= root->data) {
        return(search(root->left, data));
    }
    else {
        return(search(root->right, data));
    }
}

int main() {
    root = insert(root, 10);
    root = insert(root,12);
    root = insert(root,2);
    root = insert(root,22);
    root = insert(root,8);
    root = insert(root,9);
    int n;
    cin>>n;
    if(search(root,n)) {
        cout<<"yes"<<endl;
    } else {
        cout<<"No"<<endl;
    }
}