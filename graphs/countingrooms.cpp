#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
void dfs(vector<string>&g,vector<vector<ll>>&vis,ll i,ll j){
    vis[i][j]=1;
    if(i>0 && g[i-1][j]=='.')dfs(g,vis,i-1,j);
    if(j>0 && g[i][j-1]=='.')dfs(g,vis,i,j-1);
    if(i<g.size()-1 && g[i+1][j]=='.')dfs(g,vis,i+1,j);
    if(j<g[0].size()-1 && g[i][j+1]=='.')dfs(g,vis,i,j+1);
}
int main(){
    cin.tie(0)->sync_with_stdio(0);
    ll n,m;
    cin>>n>>m;
    getline();
    vector<string>g(n);
    for(ll i=0;i<n;i++){
        getline(cin,g[i]);
    }
    vector<vector<ll>>vis(n,vector<ll>(m,0));
    ll rooms=0;
    for(ll i=0;i<n;i++){
        for(ll j=0;j<m;j++){
            if(!vis[i][j] && g[i][j]=='.'){
                dfs(g,vis,i,j);
                rooms++;
            }
        }
    }
    cout<<rooms<<endl;
    return 0;
}