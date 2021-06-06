#include<bits/stdc++.h>
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

void MorrisInOrder (Node* root) {
    struct Node* current = root;
    while(current != NULL) {
        if(current->left == NULL) {
            cout<<current->data<<endl;
            current =  current->right;
        } else {
            struct Node* predecessor = current->left;
            while(predecessor->right!=current && predecessor->right!=NULL) {
                predecessor = predecessor->right;
            }
            if(predecessor->right == NULL) {
                predecessor->right = current;
                current=current->left;
            } else {
                predecessor->right = NULL;
                cout<<current->data<<endl;
                current = current->right;
            }
        }
    }
}

int main() {
    root = insert(root,10);
    root = insert(root,5);
    root = insert(root,30);
    root = insert(root,-2);
    root = insert(root,6);
    root = insert(root,2);
    root = insert(root,-1);
    root = insert(root,8);
    root = insert(root,40);
    MorrisInOrder(root);
}