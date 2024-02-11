#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    long long n;
    cin>>n;
    vector<int>a;
    a.resize(n);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    long long ans =0;
    sort(a.begin(),a.end());
    for(int i=0;i<n;i++){
        if(a[i]==0){
            ans++;
            continue;
        }
        if(a[i]!=a[i-1]){
            ans++;
        }
    }
    cout<<ans;
}