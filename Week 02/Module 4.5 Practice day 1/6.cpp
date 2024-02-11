#include <bits/stdc++.h>
using namespace std;
class Cuboid
{
private:
    int length;
    int width;
    int height;

public:
    Cuboid()
    {
        length = 0;
        width = 0;
        height = 0;
    }
    Cuboid(int len, int wid, int hig)
    {
        length = len;
        width = wid;
        height = hig;
    }
    int getVolume()
    {
        int volume = length * width * height;
        return volume;
    }
    int getSurfaceArea()
    {
        int SurfaceArea = 2 * length * width + 2 * length * height + 2 * width * height;
        return SurfaceArea;
    }
};
bool sort_volume(Cuboid a, Cuboid b)
{
    return a.getVolume() < b.getVolume();
}
bool sort_surface(Cuboid x, Cuboid y)
{
    return x.getSurfaceArea() < y.getSurfaceArea();
}

int main()
{

    // Cuboid ans(3, 4, 5);
    // cout << ans.getVolume() << " " << ans.getSurfaceArea() << "\n";

    vector<Cuboid> arr(5);
    for (int i = 0; i < 5; i++)
    {
        int l, w, h;
        cin >> l >> w >> h;
        arr[i] = Cuboid(l, w, h);
    }
    cout << "Before sort:\n";
    for (int i = 0; i < 5; i++)
    {
        cout << arr[i].getVolume() << " " << arr[i].getSurfaceArea() << "\n";
    }
    sort(arr.begin(), arr.end(), sort_volume);
    sort(arr.begin(), arr.end(), sort_surface);

    cout << "After sort:\n";

    for (int i = 0; i < 5; i++)
    {
        cout << arr[i].getVolume() << " " << arr[i].getSurfaceArea() << "\n";
    }
}

/*
3 4 5
4 5 6
2 4 6
5 6 7
4 6 8

*/

