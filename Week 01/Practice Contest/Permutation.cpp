#include <bits/stdc++.h>
using namespace std;
int main()
{
   ios_base::sync_with_stdio(0);
   cin.tie(0);

   long long int n;
   cin>>n;

   if(n==1){
    cout<<n;
   }else if(n<=3){
    cout<<"NO SOLUTION\n";
   }else{
    for (int i = 2; i <= n; i+=2)
    {
        cout<<i<<' ';
    }
    for (int i = 1; i <= n; i+=2)
    {
        cout<<i<<' ';
    }  
   }
    
    return 0;
}