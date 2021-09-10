#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
vector<ll>ans;
void findPath(vector<vector<ll>>&adj,vector<ll>&vis,int i,int p,stack<int>&s,int &f,int &a){
    // cout<<"y\n";
    // if(s.empty() || !(s.top()==f && s.size()>1)){
        // s.push(i);
        // cout<<"y";
        for(ll j=0;j<adj[i].size();j++){
            if(!vis[adj[i][j]]){
                vis[adj[i][j]]=1;
                s.push(adj[i][j]);
                // cout<<adj[i][j]<<" "<<p<<endl;
                findPath(adj,vis,adj[i][j],i,s,f,a);
                s.pop();
            }
            else if(adj[i][j]!=p && adj[i][j]==f && !a){
                // cout<<adj[i][j]<<" "<<p<<" "<<f<<" end"<<endl;
                a=1;
                s.push(f);
                int fc=0;
                while(fc!=2){
                    ans.push_back(s.top());
                    if(s.top()==f)fc++;
                    s.pop();
                }
                cout<<ans.size()<<endl;
                for(int i=ans.size()-1;i>=0;i--){
                    cout<<ans[i]<<" ";
                    if(i>0)s.push(ans[i]);
                }
                cout<<endl;
                // cout<<s.size()<<endl;
                // cout<<"y\n";
                // break;
            }
        }
    // }
}
void dfs(vector<vector<ll>>&adj,vector<ll>&vis,int &f,int i,int p){
    vis[i]=1;
    for(ll j=0;j<adj[i].size();j++){
        if(!vis[adj[i][j]]){
            dfs(adj,vis,f,adj[i][j],i);
        }
        else if(adj[i][j]!=p && f==0){
            f=adj[i][j];
        }
    }
}
int main(){
    ll n,m,a,b;
    cin.tie(0)->sync_with_stdio(0);
    cin>>n>>m;
    vector<vector<ll>>adj(n+1,vector<ll>());
    for(ll i=0;i<m;i++){
        cin>>a>>b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    vector<ll>vis(n+1,0);
    stack<int>s;
    int flag=0;
    for(ll i=1;i<=n;i++){
        if(!vis[i]){
            while(!s.empty())s.pop();
            dfs(adj,vis,flag,i,i);
        }
    }
    // cout<<flag<<endl;
    if(flag==0)cout<<"IMPOSSIBLE\n";
    else{
        while(!s.empty())s.pop();
        vis.assign(n+1,0);
        vis[flag]=1;
        s.push(1);
        int a=0;
        findPath(adj,vis,flag,flag,s,flag,a);
    }
}