#include<bits/stdc++.h>
// DIJKSTRA using sets
using namespace std;
typedef long long ll;
int main(){
    ll n,m,a,b,c;
    cin.tie(0)->sync_with_stdio(0);
    // ifstream fin;
    // ofstream fout;
    // fout.open("results.txt");
    // fin.open("test_input.txt");
    cin>>n>>m;

    vector<vector<pair<ll,ll>>>adj(n+1,vector<pair<ll,ll>>());
    vector<ll>cost(n+1,-1);
    for(ll j=0;j<m;j++){
        cin>>a>>b>>c;
        adj[a].push_back({b,c});
    }
    set<pair<ll,ll>>s;
    s.insert({0,1});
    cost[1]=0;
    int t,f;
    while(!s.empty()){
        f=s.begin()->first;
        t=s.begin()->second;
        s.erase(s.begin());
        for(ll j=0;j<adj[t].size();j++){
            if(cost[adj[t][j].first]==-1 || cost[adj[t][j].first]>cost[t]+adj[t][j].second){
                if(s.find({cost[adj[t][j].first],adj[t][j].first})!=s.end())
                s.erase(s.find({cost[adj[t][j].first],adj[t][j].first}));
                cost[adj[t][j].first]=cost[t]+adj[t][j].second;
                s.insert({cost[adj[t][j].first],adj[t][j].first});
            }
        }
    }
    for(ll i=1;i<=n;i++)
        cout<<cost[i]<<" ";
    cout<<endl;
    return 0;
}