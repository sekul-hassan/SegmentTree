#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define N '\n'
ll arr[300000];
ll tree[800000];
 
void makeTree(ll node,ll st,ll ed)
{
    if(st==ed){
        tree[node]=arr[st];
        return;
    }
    ll left = 2*node+1;
    ll right = 2*node+2;
    ll mid = (st+ed)/2;
    makeTree(left,st,mid);
    makeTree(right,mid+1,ed);
    tree[node]=tree[left]+tree[right];
}
 
ll Query(ll node,ll st,ll ed,ll x,ll y)
{
    if(x<=st and ed<=y){
        return tree[node];
    }
    if(ed<x or st>y)
        return 0;
    ll mid = (st+ed)/2;
    ll left = 2*node+1;
    ll right = 2*node+2;
    return Query(left,st,mid,x,y)+Query(right,mid+1,ed,x,y);
 
}
 
void update(ll node,ll st,ll ed,ll pos,ll val)
{
    if(ed<pos or st>pos)
        return;
    if(st>=pos and ed<=pos){
        tree[node] = val;
        return;
    }
    ll left = 2*node+1;
    ll right = 2*node+2;
    ll mid = (st+ed)/2;
    update(left,st,mid,pos,val);
    update(right,mid+1,ed,pos,val);
    tree[node]=tree[left]+tree[right];
}
 
int main()
{
    ll n,q,i,j;
    cin>>n>>q;
    for(i=0;i<n;i++){
        cin>>arr[i];
    }
    makeTree(0,0,n-1);
    for(i=0;i<q;i++){
        ll p,x,y;
        cin>>p>>x>>y;
        if(p==1){
            update(0,0,n-1,x-1,y);
        }
        else{
            ll ans = Query(0,0,n-1,x-1,y-1);
            cout<<ans<<N;
        }
    }
}