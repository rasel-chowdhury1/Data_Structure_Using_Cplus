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

        arr[0]->left = arr[1];
        arr[0]->right = arr[2];

        arr[1]->left = arr[5];
        arr[1]->parent = arr[0];

        arr[2]->left = arr[3];
        arr[2]->right = arr[4];
        arr[2]->parent = arr[0];

        arr[3]->parent = arr[2];
        arr[4]->parent = arr[2];

        root = arr[0];
    }

    void BFS()
    {
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
};
int main()
{
    BinaryTree bt;
    bt.build_binary_tree();

    bt.DFS(bt.root);
    // bt.BFS();

    return 0;
}