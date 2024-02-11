// BFS stand for Breadth First Search
// DFS stand for Depth First Search
#include <bits/stdc++.h>
using namespace std;

class node
{
public:
    int id;
    int value;
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

    node *CreateNewNode(int id, int value)
    {
        node *newnode = new node;
        newnode->id = id;
        newnode->value = value;
        newnode->parent = NULL;
        newnode->left = NULL;
        newnode->right = NULL;
        return newnode;
    }

    void Insertion(int id, int value)
    {
        node *newnode = CreateNewNode(id, value);
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

    void SearchValue(node *a, int value)
    {
        if (a == NULL)
            return;
        if (a->value == value)
        {
            cout << a->id << " ";
        }
        SearchValue(a->left, value);
        SearchValue(a->right, value);
    }
};
int main()
{
    BinaryTree bt;
    bt.Insertion(0, 5);
    bt.Insertion(1, 10);
    bt.Insertion(2, 10);
    bt.Insertion(5, 9);
    bt.Insertion(3, 5);
    bt.Insertion(4, 7);

    // bt.BFS();
    bt.DFS(bt.root);
    cout << "\n";
    bt.SearchValue(bt.root, 5);

    return 0;
}