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
struct Node* Find(Node*root, int data) {
	if(root == NULL) {
	   return NULL; 
	}
	else if(root->data == data) {
	    return root;
	}
	else if(root->data < data) {
	    return Find(root->right,data);
	}
	else {
	    return Find(root->left,data);
	}
}

struct Node* FindMin(Node* root)
{
	while(root->left != NULL) {
	    root = root->left;
	}
	return root;
}

struct Node* GetSuccessor(struct Node* root, int data) {
    struct Node* current = Find(root, data);
    if(current == NULL) {
        return root;
    }
    if(current->right!= NULL) {
        return FindMin(current->right);
    } else {
        struct Node* successor = NULL;
        struct Node* ancestor = root;
        while(ancestor!= current) {
            if(current->data < ancestor->data) {
                successor = ancestor;
                ancestor = ancestor->left;
            } else {
                ancestor = ancestor->right;
            }
        }
        return successor;
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
    root = GetSuccessor(root,'C');
    cout<<root->data<<endl;
}