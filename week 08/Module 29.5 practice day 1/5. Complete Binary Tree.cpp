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
        newnode->left = NULL;
        newnode->right = NULL;
        newnode->parent = NULL;
        return newnode;
    }

    void Insert(int id, int value)
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

            cout << "Node " << a->id << ": Parent = " << p << ", Left child = " << l << ", Right child = " << r << "\n";
        }
    }

    void inorder(node *a)
    {
        if (a == NULL)
            return;
        inorder(a->left);
        cout << a->id << " ";
        inorder(a->right);
    }

    void preorder(node *a)
    {
        if (a == NULL)
            return;
        cout << a->id << " ";
        preorder(a->left);
        preorder(a->right);
    }

    void postorder(node *a)
    {
        if (a == NULL)
            return;
        postorder(a->left);
        postorder(a->right);
        cout << a->id << " ";
    }

    int height(node *a)
    {
        if (a == NULL)
            return 0;

        int lheight = height(a->left);
        int rheight = height(a->right);

        if (lheight > rheight)
        {
            return (lheight + 1);
        }
        else
        {
            return (rheight + 1);
        }
    }

    int NodeSize(node *a)
    {
        if (a == NULL)
            return 0;
        return (1 + NodeSize(a->left) + NodeSize(a->right));
    }

    bool isCompleteBT(node *a, int index, int size)
    {
        if (a == NULL)
            return (true);
        if (index >= size)
            return (false);
        return (isCompleteBT(a->left, 2 * index + 1, size) && isCompleteBT(a->right, 2 * index + 1, size));
    }
};
int main()
{
    BinaryTree bt;
    bt.Insert(0, 5);
    bt.Insert(1, 10);
    bt.Insert(2, 23);
    bt.Insert(3, 30);
    bt.Insert(4, 5);
    bt.Insert(5, 10);
    bt.Insert(6, 23);
    bt.Insert(7, 20);

    int nodesize = bt.NodeSize(bt.root);
    int nodelevel = bt.height(bt.root);

    bt.BFS();
    cout << "Node Level: " << nodelevel << "\n";
    cout << "Node Size: " << nodesize << "\n";
    if (bt.isCompleteBT(bt.root, 0, nodesize))
    {
        cout << "Complete Binary Tree.\n";
    }
    else
    {
        cout << "Not Complete Binary Tree.\n";
    }

    return 0;
}