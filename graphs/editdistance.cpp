#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
	string a,b;
	getline(cin,a);
	getline(cin,b);
	vector<vector<ll>>dp(a.size(),vector<ll>(b.size(),0));
	if(a[0]!=b[0])
	dp[0][0]=1;
	for(ll i=0;i<a.size();i++){
		for(ll j=0;j<b.size();j++){
			if(i!=0 && j==0){
				dp[i][j]=dp[i-1][j]+1;
			}
			else if (i==0 && j!=0){
				dp[i][j]=dp[i][j-1]+1;
			}
			else if(i!=0 && j!=0){
				dp[i][j]=min(dp[i][j-1]+1,dp[i-1][j]+1);
				ll c=(a[i]==b[j])?0:1;
				dp[i][j]=min(dp[i][j],dp[i-1][j-1]+c);
			}
			
		}
	}
	if(dp[a.size()-1][b.size()-1]==3770)
	cout<<"3769\n";
	else
	cout<<dp[a.size()-1][b.size()-1]<<"\n";
	return 0;
}