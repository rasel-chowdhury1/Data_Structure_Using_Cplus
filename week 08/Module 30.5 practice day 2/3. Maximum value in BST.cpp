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

    void insert(int value)
    {
        node *newnode = CreateNewNode(value);
        if (root == NULL)
        {
            root = newnode;
            return;
        }
        node *cur = root;
        node *prv = NULL;
        while (cur != NULL)
        {
            if (value > cur->value)
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
        {
            prv->right = newnode;
        }
        else
        {
            prv->left = newnode;
        }
    }

    void Delete(int value)
    {
        node *cur = root;
        node *prv = NULL;
        while (cur != NULL)
        {
            if (value > cur->value)
            {
                prv = cur;
                cur = cur->right;
            }
            else if (value < cur->value)
            {
                prv = cur;
                cur = cur->left;
            }
            else
            {
                break;
            }
        }

        if (cur == NULL)
        {
            cout << "Value does not exist in Binary Search Tree.\n";
            return;
        }

        if (cur->left == NULL && cur->right == NULL)
        {
            if (prv->left != NULL && cur->value == value)
            {
                prv->left = NULL;
            }
            else
            {
                prv->right = NULL;
            }
            delete cur;
            return;
        }

        if (cur->left == NULL && cur->right != NULL)
        {
            if (prv->left != NULL && cur->value == value)
            {
                prv->left = cur->right;
            }
            else
            {
                prv->right = cur->right;
            }
            delete cur;
            return;
        }
        if (cur->left != NULL && cur->right == NULL)
        {
            if (prv->left != NULL && cur->value == value)
            {
                prv->left = cur->left;
            }
            else
            {
                prv->right = cur->left;
            }
            delete cur;
            return;
        }

        node *tmp = cur->right;
        while (tmp->left != NULL)
        {
            tmp = tmp->left;
        }
        int saved = tmp->value;
        Delete(saved);
        cur->value = saved;
    }

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

    void BFS()
    {
        if (root == NULL)
        {
            cout << "BST is empty.\n";
            return;
        }
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
            cout << "Node " << a->value << ": left child = " << l << ", right child = " << r << ".\n";
        }
    }

    int maxx(node *cur)
    {
        if (cur == NULL)
        {
            cout << "BST is empty";
            return -1;
        }

        while (cur->right != NULL)
        {
            cur = cur->right;
        }
        return cur->value;
    }
};
int main()
{
    BST bst;
    bst.insert(5);
    bst.insert(3);
    bst.insert(2);
    bst.insert(7);
    bst.insert(6);
    bst.insert(1);

    bst.BFS();

    cout << bst.maxx(bst.root) << "\n";
    return 0;
}
