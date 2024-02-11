#include <bits/stdc++.h>
using namespace std;

class MaxHeap
{
public:
    vector<int> nodes;
    MaxHeap()
    {
    }

    // O(logn)
    void up_heapify(int idx)
    {
        while (idx > 0 && nodes[idx] > nodes[(idx - 1) / 2])
        {
            swap(nodes[idx], nodes[(idx - 1) / 2]);
            idx = (idx - 1) / 2;
        }
    }
    // O(logn)
    void Insert(int value)
    {
        nodes.push_back(value);
        up_heapify(nodes.size() - 1);
    }
    // O(n)
    void printheap()
    {
        for (int i = 0; i < nodes.size(); i++)
        {
            cout << nodes[i] << " ";
        }
        cout << "\n";
    }

    // O(logn)
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

    // O(logn)
    void Delete(int idx)
    {
        if (idx >= nodes.size())
            return;
        swap(nodes[idx], nodes[nodes.size() - 1]);
        nodes.pop_back();
        down_heapify(idx);
    }

    // O(n)
    void build_from_array(vector<int> &a)
    {
        nodes = a;
        int n = nodes.size();
        int last_non_leaf = n / 2 - 1;
        for (int i = last_non_leaf; i >= 0; i--)
        {
            down_heapify(i);
        }
    }

    // O(1)
    int getMax()
    {
        if (nodes.empty())
        {
            cout << "Heap is empty!";
            return -1;
        }
        return nodes[0];
    }
    // O(logn)
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

vector<int> heap_sort(vector<int> &a, int k)
{
    MaxHeap mh;
    mh.build_from_array(a);

    vector<int> ans;
    for (int i = 0; i < a.size(); i++)
    {
        ans.push_back(mh.ExtractMax());
    }
    vector<int> kthlarge;
    for (int i = 0; i < k; i++)
    {
        kthlarge.push_back(ans[i]);
    }
    return kthlarge;
}

int main()
{
    int n, k;
    cin >> n >> k;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    vector<int> sorted_arr = heap_sort(arr, k);

    for (int i = 0; i < sorted_arr.size(); i++)
    {
        cout << sorted_arr[i] << " ";
    }
    cout << "\n";

    return 0;
}

/*
6 3
5 2 9 1 5 6

5 4
7 8 2 3 1

*/