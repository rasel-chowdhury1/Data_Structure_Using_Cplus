// BST stand for Binary Search Tree
//Complexity of Searching in average case: O(logn) and worst case: O(n)
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

    //Complexity O(height)
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

    //Searching node
    bool Search(int value)
    {
        node *cur = root;
        while (cur != NULL)
        {
            if (value > cur->value)
            {
                cur = cur->right;
            }
            else if (value < cur->value)
            {
                cur = cur->left;
            }
            else
            {
                return true;
            }
        }
        return false;
    }
};
int main()
{
    BST bst;
    bst.Insert(6);
    bst.Insert(4);
    bst.Insert(3);
    bst.Insert(5);
    bst.Insert(7);
    bst.Insert(8);
    bst.BFS();

    cout << bst.Search(3) << "\n";
    cout << bst.Search(2) << "\n";
    return 0;
}