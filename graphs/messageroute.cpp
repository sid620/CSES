#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
    ll n,m,a,b;
    cin>>n>>m;
    vector<vector<ll>>adj(n+1,vector<ll>());
    vector<ll>cost(n+1,INT_MAX);
    vector<ll>pre(n+1,0);
    cost[1]=0;
    for(ll i=0;i<m;i++){
        cin>>a>>b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    set<pair<int,int>>s;
    s.insert({1,0});
    pair<int,int>p;
    while(!s.empty()){
        p.first=s.begin()->first;
        p.second=s.begin()->second;
        s.erase(s.begin());
        for(int i=0;i<adj[p.first].size();i++){
            if(cost[adj[p.first][i]]>cost[p.first]+1){
                cost[adj[p.first][i]]=cost[p.first]+1;
                pre[adj[p.first][i]]=p.first;
                s.insert({adj[p.first][i],cost[adj[p.first][i]]});
            }
        }
    }
    if(cost[n]==INT_MAX)cout<<"IMPOSSIBLE\n";
    else{
        vector<ll>ans(cost[n]+1);
        cout<<cost[n]+1<<endl;
        ll i=cost[n];
        while(n!=0){
            ans[i]=n;
            i--;
            n=pre[n];
        }
        for(int i=0;i<ans.size();i++)cout<<ans[i]<<" ";
        cout<<endl;
    }
    return 0;
}