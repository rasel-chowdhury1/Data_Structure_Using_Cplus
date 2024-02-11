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
};

int main()
{
    MinHeap mh;
    mh.Insert(2);
    mh.Insert(4);
    mh.Insert(7);
    mh.Insert(3);
    mh.Insert(10);
    mh.Insert(12);
    mh.Insert(1);
    mh.Insert(20);
    mh.Insert(6);
    mh.printheap();
    cout << mh.getMin() << "\n";
    mh.Delete(1);
    mh.printheap();
    cout << mh.getMin() << "\n";
}