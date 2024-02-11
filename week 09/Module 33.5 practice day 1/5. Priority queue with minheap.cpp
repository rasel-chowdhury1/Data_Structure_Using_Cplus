#include <bits/stdc++.h>
using namespace std;
class MinHeap
{
public:
    vector<int> nodes;
    MinHeap()
    {
    }

    void up_heapify(int idx)
    {
        while (idx > 0 && nodes[idx] < nodes[(idx - 1) / 2])
        {
            swap(nodes[idx], nodes[(idx - 1) / 2]);
            idx = (idx - 1) / 2;
        }
    }

    void Insert(int value)
    {
        nodes.push_back(value);
        up_heapify(nodes.size() - 1);
    }

    void printheap()
    {
        for (int i = 0; i < nodes.size(); i++)
        {
            cout << nodes[i] << " ";
        }
        cout << "\n";
    }

    int getMin()
    {
        return nodes[0];
    }

    void down_heapify(int idx)
    {
        while (1)
        {
            int smallest = idx;
            int left = 2 * idx + 1;
            int right = 2 * idx + 2;
            if (left < nodes.size() && nodes[smallest] > nodes[left])
                smallest = left;
            if (right < nodes.size() && nodes[smallest] > nodes[right])
                smallest = right;
            if (smallest == idx)
                break;
            swap(nodes[idx], nodes[smallest]);
            idx = smallest;
        }
    }

    void Delete(int idx)
    {
        if (idx >= nodes.size())
            return;
        swap(nodes[idx], nodes[nodes.size() - 1]);
        nodes.pop_back();
        down_heapify(idx);
    }

    int ExtractMin()
    {
        if (nodes.empty())
        {
            cout << "Heap is empty!";
            return -1;
        }
        int returnnMax = nodes[0];
        Delete(0);
        return returnnMax;
    }

    void build_with_arry(vector<int> a)
    {
        nodes = a;
        int n = nodes.size();
        int non_leaf = n / 2 - 1;
        for (int i = non_leaf; i >= 0; i--)
        {
            down_heapify(i);
        }
    }

    int size()
    {
        return nodes.size();
    }
};

vector<int> heap_sort(vector<int> &a)
{
    MinHeap mh;
    mh.nodes = a;
    // mh.build_with_arry(a);
    vector<int> ans;
    for (int i = 0; i < a.size(); i++)
    {
        ans.push_back(mh.ExtractMin());
    }
    return ans;
}

class PriorityQueue
{
public:
    MinHeap mh;
    PriorityQueue()
    {
    }

    // O(logn)
    void push(int x)
    {
        mh.Insert(-x);
    }

    // O(logn)
    void pop()
    {
        mh.Delete(0);
    }

    // O(1)
    int top()
    {
        return -1 * mh.getMin();
    }

    int size()
    {
        return mh.size();
    }
};

int main()
{
    PriorityQueue qp;
    qp.push(5);
    qp.push(15);
    qp.push(50);
    qp.push(12);
    qp.push(5);

    while (qp.size() != 0)
    {
        cout << qp.top() << " ";
        qp.pop();
    }
}