#include<bits/stdc++.h>
#define  MAX 1000000007
using namespace std;
typedef long long int ll;
int main(){
	ll n;
	cin>>n;
	vector<ll>dp(n+1,0);
	dp[1]=1;
	ll t=2;
 
	while(t<=n){
		ll j=t;
		ll c=1;
		while(c!=7){
			if(j-c>0){
				dp[t]+=dp[j-c]%MAX;
			}
			c++;
		}
		if(t<7)
			dp[t]++;
		t++;
	}
	cout<<dp[n]%MAX<<endl;
	return 0;
}