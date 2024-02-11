#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
   
    string str;
    cin>>str;
    int counter = 1;
    int maxx = 1;

    for (int i = 0; i < str.size(); i++)
    {
        if(str[i]==str[i-1]){
            counter++;
        }else{
            counter=1;
        }
        if(counter>maxx){
            maxx = counter;
        }
    }
    cout<<maxx;
    return 0;
}