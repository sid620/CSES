#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
    ll n,q,c,b;
    cin.tie(0)->sync_with_stdio(0);
    cin>>n>>q;
    vector<ll>a(n,0);
    for(int i=0;i<n;i++){
        cin>>a[i];
        i>0?a[i]^=a[i-1]:0;
    }
    for(int i=0;i<q;i++){
        cin>>c>>b;
        if(c>1)cout<<(a[c-2]^a[b-1])<<endl;
        else cout<<a[b-1]<<endl;
    }
    return 0;
}