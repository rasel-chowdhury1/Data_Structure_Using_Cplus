#include <bits/stdc++.h>
using namespace std;

template <class T>
class MinHeap
{
public:
    vector<T> nodes;
    MinHeap()
    {
    }

    void up_heapify(T idx)
    {
        while (idx > 0 && nodes[idx] < nodes[(idx - 1) / 2])
        {
            swap(nodes[idx], nodes[(idx - 1) / 2]);
            idx = (idx - 1) / 2;
        }
    }

    void Insert(T value)
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

    T getMin()
    {
        if (nodes.empty())
        {
            cout << "Heap is empty!";
            T a;
            return a;
        }
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
};

int main()
{
    MinHeap<int> mh;
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
    mh.Delete(0);
    mh.printheap();
    cout << mh.getMin() << "\n";
}