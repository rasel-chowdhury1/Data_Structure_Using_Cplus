#include <bits/stdc++.h>
using namespace std;
/*
Time Complexity: O(1+sz+sz+1+1) = O(sz).
Memory Complexity: O(n).
*/
class Array
{
private:
    int *arr;
    int cap;
    int sz;

    void increase_size()
    {
        cap = cap * 2;
        int *tmp = new int[cap];
        for (int i = 0; i < sz; i++)
        {
            tmp[i] = arr[i];
        }
        delete[] arr;
        arr = tmp;
    }

public:
    Array()
    {
        arr = new int[1];
        cap = 1;
        sz = 0;
    }
    // Time complexity: O(1)
    void Push_back(int x)
    {
        if (cap == sz)
        {
            increase_size();
        }
        arr[sz] = x;
        sz++;
    }
    // Time complexity: O(sz-pos) = O(sz).
    void Insert(int pos, int x)
    {
        if (cap == sz)
        {
            increase_size();
        }
        for (int i = sz - 1; i >= pos; i--)
        {
            arr[i + 1] = arr[i];
        }
        arr[pos] = x;
        sz++;
    }
    // Time complexity: O(sz).
    void Print()
    {
        for (int i = 0; i < sz; i++)
        {
            cout << arr[i] << " ";
        }
        cout << "\n";
    }
    // Time complexity: O(1).
    int getSize()
    {
        return sz;
    }
    // Time complexity: O(1).
    int getElement(int idx)
    {
        if (idx >= sz)
        {
            cout << "ERROR " << idx << " is out of Bound!\n";
            return -1;
        }
        return arr[idx];
    }

    // Dynamic array deletion:
    // Time complexity: O(1).
    void Pop_back()
    {
        if (sz == 0)
        {
            cout << "Current size is 0\n";
            return;
        }
        sz--;
    }
    // Time complexity: O(sz).
    void Erease(int pos)
    {
        if (pos >= sz)
        {
            cout << "Position does not exit\n";
            return;
        }
        for (int i = pos + 1; i < sz; i++)
        {
            arr[i - 1] = arr[i];
            // swap(arr[i-1],arr[i]);
        }
        sz--;
    }
};

int main()
{
    Array a;
    a.Push_back(10);
    a.Push_back(20);
    a.Push_back(30);
    a.Push_back(40);
    a.Push_back(50);
    a.Insert(1, 5);
    a.Print();
    // cout << a.getSize() << "\n";
    //  for (int i = 0; i < a.getSize(); i++)
    //  {
    //      cout << a.getElement(i) << "\n";
    //  }
    a.Pop_back();
    a.Print();
    a.Pop_back();
    a.Print();
    a.Erease(1);
    a.Print();

    return 0;
}