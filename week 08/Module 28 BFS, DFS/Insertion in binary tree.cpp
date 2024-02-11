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

    void Insertion(int id)
    {
        node *newnode = CreateNewNode(id);
        if (root == NULL)
        {
            root = newnode;
            return;
        }

        queue<node *> q;
        q.push(root);
        while (!q.empty())
        {
            node *a = q.front();
            q.pop();
            if (a->left != NULL)
            {
                q.push(a->left);
            }
            else
            {
                // instert in left child of node a
                a->left = newnode;
                newnode->parent = a;
                return;
            }
            if (a->right != NULL)
            {
                q.push(a->right);
            }
            else
            {
                // instert in right child of node a
                a->right = newnode;
                newnode->parent = a;
                return;
            }
        }
    }

    void BFS()
    {
        if (root == NULL)
            return;
        queue<node *> q;
        q.push(root);

        while (!q.empty())
        {
            int l = -1, r = -1, p = -1;
            node *a = q.front();
            q.pop();
            if (a->parent != NULL)
            {
                p = a->parent->id;
            }
            if (a->left != NULL)
            {
                l = a->left->id;
                q.push(a->left);
            }
            if (a->right != NULL)
            {
                r = a->right->id;
                q.push(a->right);
            }

            cout << "Node " << a->id << ": Left = " << l << ", Right = " << r << ", Parent = " << p << ".\n";
        }
    }

    void DFS(node *a)
    {
        if (a == NULL)
            return;

        cout << a->id << " ";
        DFS(a->left);
        DFS(a->right);
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
    bt.Insertion(20);
    bt.Insertion(10);
    bt.Insertion(22);
    bt.Insertion(5);
    bt.Insertion(12);
    bt.Insertion(21);
    bt.Insertion(25);
    bt.Insertion(3);
    bt.Insertion(15);

    cout << "Inorder: ";
    bt.Inorder(bt.root);
    cout << "\n";
    cout << "Preorder: ";
    bt.Preorder(bt.root);
    cout << "\n";
    cout << "Postorder: ";
    bt.Postorder(bt.root);

    // bt.BFS();
    // bt.DFS(bt.root);

    return 0;
}