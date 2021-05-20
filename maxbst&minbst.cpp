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

int minbst(struct Node* root) {
    if(root == NULL) {
        return -1;
    } else  if(root->left == NULL) {
        return root->data;
    } 
   return minbst(root->left);
}
int maxbst(struct Node* root) {
    if(root == NULL) {
        return -1;
    } else  if(root->right == NULL) {
        return root->data;
    } 
   return maxbst(root->right);
}


int main() {
    root = insert(root, 10);
    root = insert(root,20);
    root = insert(root,17);
    root = insert(root,12);
    root = insert(root,8);
    root = insert(root,25);
    root = insert(root,15);
    int x = minbst(root);
    cout<<x<<endl;
    int y = maxbst(root);
    cout<<y<<endl;
}