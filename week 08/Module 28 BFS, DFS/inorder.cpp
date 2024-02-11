// BFS stand for Breadth First Search
// DFS stand for Depth First Search
#include <bits/stdc++.h>
using namespace std;

class node
{
public:
    int id;
    node *left;
    node *right;
    node *parent;
};

class BinaryTree
{
public:
    node *root;
    BinaryTree()
    {
        root = NULL;
    }

    node *CreateNewNode(int id)
    {
        node *newnode = new node;
        newnode->id = id;
        newnode->parent = NULL;
        newnode->left = NULL;
        newnode->right = NULL;
        return newnode;
    }

    void build_binary_tree()
    {
        node *arr[6];
        for (int i = 0; i < 6; i++)
        {
            arr[i] = CreateNewNode(i);
        }

        // arr[0]->left = arr[1];
        // arr[0]->right = arr[2];

        // arr[1]->left = arr[5];
        // arr[1]->parent = arr[0];

        // arr[2]->left = arr[3];
        // arr[2]->right = arr[4];
        // arr[2]->parent = arr[0];

        // arr[3]->parent = arr[2];
        // arr[4]->parent = arr[2];

        arr[20]->left = arr[10];
        arr[20]->right = arr[22];

        arr[10]->left = arr[5];
        arr[10]->right = arr[12];
        arr[10]->parent = arr[20];
        arr[22]->right = arr[25];
        arr[22]->left = arr[21];
        arr[22]->parent = arr[20];

        

        root = arr[0];
    }

    // Inorder = f(left) + root + f(right)
    void Inorder(node *a)
    {
        if (a == NULL)
            return;
        Inorder(a->left);
        cout << a->id << " ";
        Inorder(a->right);
    }

    // Preorder = root + f(left) + f(right)
    void Preorder(node *a)
    {
        if (a == NULL)
            return;
        cout << a->id << " ";
        Preorder(a->left);
        Preorder(a->right);
    }

    // Postorder = f(left) + f(right) + root
    void Postorder(node *a)
    {
        if (a == NULL)
            return;
        Postorder(a->left);
        Postorder(a->right);
        cout << a->id << " ";
    }
};
int main()
{
    BinaryTree bt;
    bt.build_binary_tree();
    cout << "Inorder: ";
    bt.Inorder(bt.root);
    cout << "\n";
    cout << "Preorder: ";
    bt.Preorder(bt.root);
    cout << "\n";
    cout << "Postorder: ";
    bt.Postorder(bt.root);

    return 0;
}