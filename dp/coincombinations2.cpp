#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define MAX 1000000007
int main(){
	ll n,x;
	cin>>n>>x;
	vector<ll>a(n,0);
	vector<ll>dp(x+1,0);
	dp[0]=1;
	for(ll i=0;i<n;i++)
	cin>>a[i];
	for(ll i=0;i<n;i++){
		for(ll j=1;j<x+1;j++){
			if(j>=a[i])
				dp[j]+=dp[j-a[i]];
				if(dp[j]>MAX)
					dp[j]-=MAX;
		}
	}
	cout<<dp[x]<<endl;
	return 0;
}