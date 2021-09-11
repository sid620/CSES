#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
vector<ll>t;
void build(vector<ll>&arr,int v,int tl,int tr){
    if(tl==tr)t[v]=arr[tl];
    else{
        int m=(tl+tr)/2;
        build(arr,v*2,tl,m);
        build(arr,2*v+1,m+1,tr);
        t[v]=min(t[2*v],t[2*v+1]);
    }
}
void update(int v,int tl,int tr,int p,int n){
    if(tl==tr)t[v]=n;
    else{
        int m=(tl+tr)/2;
        if(p<=m)update(2*v,tl,m,p,n);
        else update(2*v+1,m+1,tr,p,n);
        t[v]=min(t[2*v],t[2*v+1]);
    }
}
ll findmin(int v,int tl,int tr,int l,int r){
    if(l>r)return LLONG_MAX;
    if(l==tl && r==tr)return t[v];
    int m=(tl+tr)/2;
    return min(findmin(v*2,tl,m,l,min(r,m)),findmin(v*2+1,m+1,tr,max(l,m+1),r));
}
int main(){
    ll n,q;
    // ifstream fin;
    // fin.open("test_input.txt");
    cin>>n>>q;  
    // ofstream fout;
    // fout.open("dynamicrangesumqueries_results.txt");
    t.assign(4*n,LLONG_MAX);
    vector<ll>arr(n,0);
    for(int i=0;i<n;i++)cin>>arr[i];
    build(arr,1,0,n-1);
    // for(ll j=1;j<t.size();j++)cout<<t[j]<<" ";
    // cout<<endl;
    // cout<<sum(1,0,n-1,1,3)<<endl;
    // cin>>q;
    ll a,b,c;
    for(int i=0;i<q;i++){
        cin>>a>>b>>c;
        if(a==1)update(1,0,n-1,b-1,c);
        else cout<<findmin(1,0,n-1,b-1,c-1)<<endl;
    }
    return 0;
}