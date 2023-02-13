#include<bits/stdc++.h>
using namespace std;
#define N '\n'
#define ll long long 
ll mx = 2e5+3;
ll mxx = 8e5+2;
ll arr[300000];
ll tree[800000];

void makeTree(ll node,ll stat,ll ed)
{
    if(stat==ed){
        tree[node]=arr[stat];
        return;
    }
    ll left = 2*node+1;
    ll right = 2*node+2;
    ll mid = (stat+ed)/2;
    makeTree(left,stat,mid);
    makeTree(right,mid+1,ed);
    tree[node] = tree[left]^tree[right];
}

ll XorSum(ll node,ll st,ll ed,ll x,ll y)
{
    if(st>=x and ed<=y)
        return tree[node];
    if(ed<x or st>y)
        return 0;
    ll left = 2*node+1;
    ll right = 2*node+2;
    ll mid = (st+ed)/2;
    return XorSum(left,st,mid,x,y)^XorSum(right,mid+1,ed,x,y);
}

int main()
{
    ll n,q,x,y;
    cin>>n>>q;
    ll i,j;
    for(i=0;i<n;i++){
        cin>>arr[i];
    }
    makeTree(0,0,n-1);
    while(q--){
        cin>>x>>y;
        ll ans = XorSum(0,0,n-1,x-1,y-1);
        cout<<ans<<N;
    }

}