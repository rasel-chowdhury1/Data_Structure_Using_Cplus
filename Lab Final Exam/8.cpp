#include <bits/stdc++.h>
using namespace std;
class MaxHeap
{
public:
    vector<int> nodes;
    MaxHeap()
    {
    }

    void up_heapify(int idx)
    {
        while (idx > 0 && nodes[idx] > nodes[(idx - 1) / 2])
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

    void down_heapify(int idx)
    {
        while (1)
        {
            int largest = idx;
            int l = 2 * idx + 1;
            int r = 2 * idx + 2;
            if (l < nodes.size() && nodes[largest] < nodes[l])
            {
                largest = l;
            }
            if (r < nodes.size() && nodes[largest] < nodes[r])
            {
                largest = r;
            }
            if (largest == idx)
            {
                break;
            }
            swap(nodes[idx], nodes[largest]);
            idx = largest;
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

    int getMax()
    {
        if (nodes.empty())
        {
            cout << "Heap is empty!";
            return -1;
        }
        return nodes[0];
    }

    int ExtractMax()
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
};

class MinHeap
{
public:
    MaxHeap mx;
    void insert(int x)
    {
        mx.Insert(-x);
    }
    void Delete(int idx)
    {
        mx.Delete(idx);
    }
    int getMin()
    {
        return -mx.getMax();
    }
};

int main()
{
    MinHeap mh;
    mh.insert(2);
    mh.insert(4);
    mh.insert(7);
    mh.insert(3);
    mh.insert(10);
    mh.insert(12);
    mh.insert(1);
    mh.insert(20);
    mh.insert(6);

    cout << mh.getMin() << "\n";
    mh.Delete(0);
    cout << mh.getMin() << "\n";
    mh.Delete(0);
    cout << mh.getMin() << "\n";

    return 0;
}