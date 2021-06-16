#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
    ll t,n,i;
    ll m=1000000007;
    cin>>t;
    vector<pair<ll,ll>>dp(1000001,make_pair(0,0));
    dp[1].first=1;
    dp[1].second=1;
    for(i=2;i<1000001;i++){
        dp[i].first=(2*dp[i-1].first+dp[i-1].second)%m;
        dp[i].second=(dp[i-1].first+dp[i-1].second*4)%m;
    }
    for(i=0;i<t;i++){
        cin>>n;
        cout<<(dp[n].first+dp[n].second)%m<<"\n";
    }
    return 0;
}