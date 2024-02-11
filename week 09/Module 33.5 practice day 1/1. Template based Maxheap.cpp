#include <bits/stdc++.h>
using namespace std;

template <class T>
class MaxHeap
{
public:
    vector<T> nodes;
    MaxHeap()
    {
    }

    void up_heapify(T idx)
    {
        while (idx > 0 && nodes[idx] > nodes[(idx - 1) / 2])
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

    void down_heapify(int idx)
    {
        while (1)
        {

            int largest = idx;
            int left = 2 * idx + 1;
            int right = 2 * idx + 2;
            if (left < nodes.size() && nodes[largest] < nodes[left])
            {
                largest = left;
            }
            if (right < nodes.size() && nodes[largest] < nodes[right])
            {
                largest = right;
            }
            if (largest == idx)
            {
                break;
            }
            swap(nodes[idx], nodes[largest]);
            idx = largest;
        }
    }

    void Delete(int x)
    {
        if (x >= nodes.size())
            return;
        swap(nodes[x], nodes[nodes.size() - 1]);
        nodes.pop_back();
        down_heapify(x);
    }

    T getMax()
    {
        if (nodes.empty())
        {
            cout << "Heap is empty!";
            T a;
            return a;
        }
        return nodes[0];
    }

    void printheap()
    {
        for (int i = 0; i < nodes.size(); i++)
        {
            cout << nodes[i] << " ";
        }
        cout << "\n";
    }

    T ExtractMax()
    {
        if (nodes.empty())
        {
            cout << "Heap is empty!";
            return -1;
        }
        T returnnMax = nodes[0];
        Delete(0);
        return returnnMax;
    }
};
int main()
{
    MaxHeap<int> mh;
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
    

    while (!mh.nodes.empty())
    {
        cout << "Max: " << mh.ExtractMax() << "\n";
    }
}