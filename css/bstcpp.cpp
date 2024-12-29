#include <iostream>
using namespace std;

class Tree {
public:
    int data;
    Tree *left, *right;

    // Constructor to create a new node
    Tree(int val) {
        data = val;
        left = right = nullptr;
    }
};

// Function to insert a node into the BST
Tree* insert(Tree *root, int data) {
    if (!root) return new Tree(data);
    if (data < root->data) root->left = insert(root->left, data);
    else root->right = insert(root->right, data);
    return root;
}

// Function to delete a node from the BST
Tree* deleteNode(Tree *root, int data) {
    if (!root) return root;
    if (data < root->data) root->left = deleteNode(root->left, data);
    else if (data > root->data) root->right = deleteNode(root->right, data);
    else {
        if (!root->left) {
            Tree *temp = root->right;
            delete root;
            return temp;
        } else if (!root->right) {
            Tree *temp = root->left;
            delete root;
            return temp;
        }
        Tree *succ = root->right;
        while (succ->left) succ = succ->left;
        root->data = succ->data;
        root->right = deleteNode(root->right, succ->data);
    }
    return root;
}

// Inorder traversal to display the tree
void display(Tree *root) {
    if (root) {
        display(root->left);
        cout << root->data << " ";
        display(root->right);
    }
}

int main() {
    Tree *root = nullptr;
    int choice, data;

    while (true) {
        cout << "\n1-Insert 2-Delete 3-Display 4-Exit\nChoice: ";
        cin >> choice;
        switch (choice) {
            case 1:
                cout << "Enter value to insert: ";
                cin >> data;
                root = insert(root, data);
                break;
            case 2:
                cout << "Enter value to delete: ";
                cin >> data;
                root = deleteNode(root, data);
                break;
            case 3:
                if (!root) cout << "Tree is empty\n";
                else {
                    cout << "Tree: ";
                    display(root);
                    cout << "\n";
                }
                break;
            case 4:
                exit(0);
            default:
                cout << "Invalid choice\n";
        }
    }
    return 0;
}
