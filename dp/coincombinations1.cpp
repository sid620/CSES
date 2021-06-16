#include<bits/stdc++.h>
using namespace std;
#define MAX 1000000007
typedef long long int LL;
 int main(){
 	LL n,x;
 	cin>>x>>n;
 	vector<LL>dp(1000001,0);
 	vector<LL>c(x,0);
 	for(LL i=0;i<x;i++){
 		cin>>c[i];
 		
 	}
 	sort(c.begin(),c.end());
	dp[c[0]]=0;
 	for(LL i=1;i<=n;i++){
 		for(LL j=0;j<x;j++){
 			if(i>c[j] ){
 				dp[i]+=dp[i-c[j]]%MAX;
 			}
 			if(i==c[j])
 				dp[i]++;
 		}
 	}
 	cout<<dp[n]%MAX<<"\n";
 	return 0;
 }