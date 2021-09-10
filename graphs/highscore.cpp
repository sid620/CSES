#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
void dfs(vector<ll>&vis,int n,vector<ll>&c,int &f,vector<vector<ll>>&adj){
    if(c[n])f=1;
    for(ll i=0;i<adj[n].size();i++){
        if(!vis[adj[n][i]]){
            vis[adj[n][i]]=1;
            dfs(vis,adj[n][i],c,f,adj);
        }
    }
}
int main(){
    ll n,m;
    cin>>n>>m;
    vector<vector<ll>>edges(m,vector<ll>(3,0));
    vector<vector<ll>>adj(n,vector<ll>(n,0));
    for(ll i=0;i<m;i++){
        cin>>edges[i][0]>>edges[i][1]>>edges[i][2];
        adj[edges[i][1]-1].push_back(edges[i][0]-1);
        edges[i][2]*=-1;
    }
    vector<ll>cost(n,INT_MAX);
    cost[0]=0;
    // bool negCycle=true;
    // negative cycles should not be present on path from 1 to n
    // assume 1 has no predecessor since starting point
    for(ll i=0;i<n-1;i++){          //relax all edges n-1 times
        for(ll j=0;j<edges.size();j++){
            // cost[edges[j][1]-1]=min(cost[edges[j][0]-1]+edges[j][2],cost[edges[j][1]-1]);
            if(cost[edges[j][0]-1]!=INT_MAX && cost[edges[j][1]-1]>cost[edges[j][0]-1]+edges[j][2]){
                // pre[edges[j][1]-1]=edges[j][0]-1;
                cost[edges[j][1]-1]=cost[edges[j][0]-1]+edges[j][2];
            }
        }
    }
    int flag=0;
    vector<ll>changed(n,0);
    for(ll i=0;i<1;i++){
            for(ll j=0;j<edges.size();j++){
            // cost[edges[j][1]-1]=min(cost[edges[j][0]-1]+edges[j][2],cost[edges[j][1]-1]);
            if(cost[edges[j][0]-1]!=INT_MAX && cost[edges[j][1]-1]>cost[edges[j][0]-1]+edges[j][2]){
                // pre[edges[j][1]-1]=edges[j][0]-1;
                cost[edges[j][1]-1]=cost[edges[j][0]-1]+edges[j][2];   
                changed[edges[j][1]-1]=1;
            }
        }
    }
    vector<ll>vis(n,0);
    vis[n-1]=1;
    dfs(vis,n-1,changed,flag,adj);
    // for(int i=)
    if(flag || cost[n-1]==INT_MAX)cout<<"-1\n";
    else cout<<-1*cost[n-1]<<endl;
    return 0;
}