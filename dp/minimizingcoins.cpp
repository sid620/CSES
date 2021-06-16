#include<bits/stdc++.h>
using namespace std;
typedef long long int LL;
 int main(){
 	LL n,x;
 	cin>>x>>n;
 	vector<LL>dp(1000001,-1);
 	vector<LL>c(x,0);
 	for(LL i=0;i<x;i++){
 		cin>>c[i];
 		dp[c[i]]=1;
 	}
 	sort(c.begin(),c.end());
 	for(LL i=1;i<=n;i++){
 		for(LL j=0;j<x;j++){
 			if(i>=c[j] && dp[i-c[j]]!=-1){
 				if(dp[i]==-1 || dp[i]>dp[i-c[j]]+1)
 					dp[i]=dp[i-c[j]]+1;
 				 			}
 		}
 	}
 	cout<<dp[n]<<"\n";
 	return 0;
 }  