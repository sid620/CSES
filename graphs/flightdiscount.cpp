#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
    ll n,m,a,b,c;
    ifstream fin;
    fin.open("test_input.txt");
    ofstream fout;
    fout.open("flightdiscount_result.txt");
    cin.tie(0)->sync_with_stdio(0);
    fin>>n>>m;
    //there are two graps denoted by 0 and 1
    vector<vector<vector<ll>>>adj(n+1,vector<vector<ll>>()),adj1(n+1,vector<vector<ll>>());
    vector<ll>arr(3);
    for(ll i=0;i<m;i++){
        fin>>a>>b>>c;
        arr[0]=b;
        arr[1]=c;
        arr[2]=0;
        adj[a].push_back(arr);
        arr[2]=1;
        adj1[a].push_back(arr);
        arr[1]/=2;
        adj[a].push_back(arr);
    }
    vector<ll>cost(n+1,-1),cost1(n+1,-1);
    set<pair<int,pair<int,int>>>s;
    cost[1]=0;
    s.insert({0,{1,0}});
    while(!s.empty()){
        int c=s.begin()->first;
        int v=(s.begin()->second).first;
        int g=(s.begin()->second).second;
        s.erase(s.begin());
        if(g==0){
            for(int i=0;i<adj[v].size();i++){
                if(adj[v][i][2]==0 && (cost[adj[v][i][0]]<=-1 || cost[adj[v][i][0]]>c+adj[v][i][1])){
                    s.erase({cost[adj[v][i][0]],{adj[v][i][0],adj[v][i][2]}});
                    // if(adj[v][i][2]){
                    // cost1[adj[v][i][0]]=c+adj[v][i][1];
                    // s.insert({cost1[adj[v][i][0]],{adj[v][i][0],adj[v][i][2]}});                    
                    // }
                    // else{
                    cost[adj[v][i][0]]=c+adj[v][i][1];
                    s.insert({cost[adj[v][i][0]],{adj[v][i][0],adj[v][i][2]}});
                    // }
                    // cout<<c<<" "<<v<<" "<<adj[v][i][0]<<" "<<adj[v][i][1]<<" "<<adj[v][i][2]<<endl;
                }
                if(adj[v][i][2] && (cost1[adj[v][i][0]]<=-1 || cost1[adj[v][i][0]]>c+adj[v][i][1])){
                    s.erase({cost1[adj[v][i][0]],{adj[v][i][0],adj[v][i][2]}});                    
                    cost1[adj[v][i][0]]=c+adj[v][i][1];
                    s.insert({cost1[adj[v][i][0]],{adj[v][i][0],adj[v][i][2]}}); 
                }
            }
        }
        else{
            for(int i=0;i<adj1[v].size();i++){
                if(cost1[adj[v][i][0]]<=-1 || cost1[adj1[v][i][0]]>c+adj1[v][i][1]){
                    s.erase({cost1[adj1[v][i][0]],{adj1[v][i][0],adj1[v][i][2]}});
                    cost1[adj1[v][i][0]]=c+adj1[v][i][1];
                    s.insert({cost1[adj1[v][i][0]],{adj1[v][i][0],adj1[v][i][2]}});
                    // cout<<c<<" "<<v<<" "<<adj1[v][i][0]<<" "<<adj1[v][i][1]<<" "<<adj1[v][i][2]<<endl;
                }
            }            
        }
    }
    fout<<min(cost[n],cost1[n])<<endl;
    return 0;
}