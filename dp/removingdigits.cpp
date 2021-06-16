#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
    ll n;
    cin>>n;
    vector<ll>dp(1000001,0);
    ll max;
    for(ll i=1;i<=n;i++){
        ll j=i;
        max=0;
        while(j!=0){
            if(j%10>max)
                max=j%10;
            j/=10;
        }
        dp[i]=dp[i-max]+1;
    }
    cout<<dp[n]<<"\n";
    return 0;
}