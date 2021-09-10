#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
    ll n,m,q,a,b,c;
    cin.tie(0)->sync_with_stdio(0);
    cin>>n>>m>>q;
    vector<vector<ll>>g(n,vector<ll>(n,LLONG_MAX));
    for(ll i=0;i<n;i++)g[i][i]=0;
    for(ll i=0;i<m;i++){
        cin>>a>>b>>c;
        g[a-1][b-1]=min(g[a-1][b-1],c);
        g[b-1][a-1]=min(g[b-1][a-1],c);
    }
    for(ll k=0;k<n;k++){
        for(ll i=0;i<n;i++){
            for(ll j=0;j<n;j++){
                if(g[i][k]!=LLONG_MAX && g[k][j]!=LLONG_MAX && g[i][j]>g[i][k]+g[k][j])
                g[i][j]=g[i][k]+g[k][j];
            }
        }
    }
    for(ll i=0;i<q;i++){
        cin>>a>>b;
        if(g[a-1][b-1]>=LLONG_MAX)cout<<-1<<endl;
        else cout<<g[a-1][b-1]<<endl;

    }
    return 0;
}
