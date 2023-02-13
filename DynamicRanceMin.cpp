#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define N '\n'
ll arr[200005];
ll tree[800000];

void makeTree(ll node,ll st,ll ed)
{
    if(st==ed){
        tree[node] = arr[st];
        return;
    }
    ll left = 2*node+1;
    ll right = 2*node+2;
    ll mid = (st+ed)/2;
    makeTree(left,st,mid);
    makeTree(right,mid+1,ed);
    tree[node] = min(tree[left],tree[right]);
}

void update(ll node,ll st,ll ed,ll pos,ll val)
{
    if(st>=pos and ed<=pos){
        tree[node] = val;
        return;
    }
    if(st>pos or ed<pos)
        return;
    ll left = 2*node+1;
    ll right = 2*node+2;
    ll mid = (st+ed)/2;
    update(left,st,mid,pos,val);
    update(right,mid+1,ed,pos,val);
    tree[node]=min(tree[left],tree[right]);
}

ll MinRange(ll node,ll st,ll ed,ll x,ll y)
{
    if(ed<x or st>y)
        return INT_MAX;
    if(st>=x and ed<=y)
        return tree[node];
    ll left = 2*node+1;
    ll right = 2*node+2;
    ll mid = (st+ed)/2;
    return min(MinRange(left,st,mid,x,y),MinRange(right,mid+1,ed,x,y));
}

int main()
{
    ll n,q,i,j;
    cin>>n>>q;
    for(i=0;i<n;i++){
        cin>>arr[i];
    }
    makeTree(0,0,n-1);
    ll x,y;
    for(i=0;i<q;i++){
        cin>>j>>x>>y;
        if(j==1)
            update(0,0,n-1,x-1,y);
        else
            cout<<MinRange(0,0,n-1,x-1,y-1)<<N;
    }
    return 0;
}


//8 100
//3 2 4 5 1 1 5 3
//2 1 4
//2 5 6
//1 2 3
//2 1 4

