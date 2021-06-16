#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
    ll n;
    ll m=1000000007;
    cin>>n;
    getchar();
    vector<vector<pair<ll,ll>>>dp(n,vector<pair<ll,ll>>(n,make_pair(0,0)));
    vector<string>a(n,"");
    for(ll i=0;i<n;i++)
        getline(cin,a[i]);
    for(ll i=0;i<n;i++){
        for(ll j=0;j<n;j++)
            dp[i][j].second=a[i][j]=='.'?0:1;
    }
    if(dp[0][0].second==0)
    dp[0][0].first=1;
    else
    dp[0][0].first=0;
    for(ll i=1;i<n;i++){
        if(dp[0][i].second==1)
        dp[0][i].first=0;
        else{
        dp[0][i].first=dp[0][i-1].first;
        dp[0][i].second=dp[0][i-1].second;
        }
    
    }
    for(ll i=1;i<n;i++){
        if(dp[i][0].second!=1)
        dp[i][0].second=dp[i-1][0].second;
        dp[i][0].first=dp[i-1][0].first;
        if(dp[i][0].second==1)
        dp[i][0].first=0;
        for(ll j=1;j<n;j++){
            if(dp[i][j-1].second==0 || dp[i-1][j].second==0)
            dp[i][j].first=(dp[i-1][j].first+dp[i][j-1].first)%m;
            else
            dp[i][j].first=0;
            if(dp[i][j].second==1)
            dp[i][j].first=0;
 
        }
    }
    cout<<dp[n-1][n-1].first<<"\n";
    return 0;
}