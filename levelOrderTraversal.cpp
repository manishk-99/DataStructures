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

void levelOrder(Node* root) {
    if(root == NULL) {
        return;
    }
    queue<Node*>q;
        q.push(root);
        while(!q.empty()) {
            struct Node* current = q.front();
            cout<<current->data<<" ";
            if(current->left != NULL ) {
                q.push(current->left);
            }
            if(current->right != NULL ) {
                q.push(current->right);
            }
            q.pop();
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
    levelOrder(root);
}