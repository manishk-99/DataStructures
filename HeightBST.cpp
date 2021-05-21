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

int maxHeight(struct Node* root) {
    if(root == NULL) {
        return -1;
    }
    return max(maxHeight(root->left), maxHeight(root->right))+1;
}


int main() {
    root = insert(root, 15);
    root = insert(root,10);
    root = insert(root,20);
    root = insert(root,8);
    root = insert(root,12);
    root = insert(root,17);
    root = insert(root,25);
    int x = maxHeight(root);
    cout<<x<<endl;
}