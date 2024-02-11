// BST stand for Binary Search Tree
//Complexity of Deletion in average case: O(logn) and worst case: O(n)
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

        // if Current is not available in Binary Search Tree.
        if (cur == NULL)
        {
            cout << "Value is not present in BST.\n";
            return;
        }

        // Case 1: If current value has no child
        if (cur->left == NULL && cur->right == NULL)
        {
            if (prv->left != NULL && prv->left->value == cur->value)
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

        // Case 2: if Current has one child.

        if (cur->left == NULL && cur->right != NULL) // if current left child is null but current right has child
        {
            if (prv->left != NULL && prv->left->value == cur->value)
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
        if (cur->left != NULL && cur->right == NULL) // if current left has chil but current right is null
        {
            if (prv->left != NULL && prv->left->value == cur->value)
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

        // Case 3: Current has two child
        node *tmp = cur->right;
        while (tmp->left != NULL)
        {
            tmp = tmp->left;
        }
        int saved = tmp->value;
        Delete(saved);
        cur->value = saved;
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
    bst.Insert(6);
    bst.Insert(4);
    bst.Insert(3);
    bst.Insert(5);
    bst.Insert(7);
    bst.Insert(8);
    bst.Insert(2);

    // Case 1:
    // bst.Delete(8);
    // bst.BFS();

    // Case 2:
    // bst.Delete(7);
    // bst.Delete(3);

    // Case 3:
    bst.Delete(6);
    bst.BFS();

   
}