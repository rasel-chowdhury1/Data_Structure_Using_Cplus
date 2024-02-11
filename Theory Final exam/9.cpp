// BST stand for Binary Search Tree
// Complexity of Insertion in average case: O(logn) and worst case: O(n)
#include <bits/stdc++.h>
using namespace std;

class node
{
public:
    int value;
    node *left;
    node *right;
};

class BST
{
public:
    node *root;
    BST()
    {
        root = NULL;
    }

    node *CreateNewNode(int value)
    {
        node *newnode = new node;
        newnode->value = value;
        newnode->left = NULL;
        newnode->right = NULL;
        return newnode;
    }

    void Insert(int value)
    {
        node *newnode = CreateNewNode(value);
        if (root == NULL)
        {
            root = newnode;
            return;
        }
        node *prv = NULL;
        node *cur = root;
        while (cur != NULL)
        {
            if (newnode->value > cur->value)
            {
                prv = cur;
                cur = cur->right;
            }
            else
            {
                prv = cur;
                cur = cur->left;
            }
        }

        if (newnode->value > prv->value)
            prv->right = newnode;
        else
            prv->left = newnode;
    }

    void BFS()
    {
        if (root == NULL)
            return;
        queue<node *> q;
        q.push(root);
        while (!q.empty())
        {
            int l = -1, r = -1;
            node *a = q.front();
            q.pop();
            if (a->left != NULL)
            {
                l = a->left->value;
                q.push(a->left);
            }
            if (a->right != NULL)
            {
                r = a->right->value;
                q.push(a->right);
            }
            cout << "Node Value " << a->value << ": left child = " << l << ", right child = " << r << "\n";
        }
    }
};
int main()
{
    BST bst;
    bst.Insert(20);
    bst.Insert(10);
    bst.Insert(22);
    bst.Insert(5);
    bst.Insert(12);
    bst.Insert(21);
    bst.Insert(25);
    bst.Insert(3);
    bst.Insert(15);
    bst.BFS();
}


