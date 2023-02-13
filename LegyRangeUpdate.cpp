#include<bits/stdc++.h>
using namespace std;
#define ll long long 
#define N '\n'
#define f first
#define s second

ll arr[200005];
vector<pair<ll,ll>>tree(800005);

void makeTree(ll node,ll st,ll ed)
{
    if(st==ed){
        tree[node].f = arr[st];
        tree[node].s = 0;
        return;
    }
    ll left = node*2+1;
    ll right = node*2+2;
    ll mid = (st+ed)/2;
    makeTree(left,st,mid);
    makeTree(right,mid+1,ed);
    tree[node].f = tree[left].f+tree[right].s;
}

void update(ll node,ll st,ll ed,ll x,ll y,ll val)
{
    if(ed<x or st>y)
        return;
    if(st>=x and ed<=y){
        tree[node].f+=((ed-st+1)*val);
        tree[node].s+=val;
        return;
    }
    ll left = 2*node+1;
    ll right = 2*node+2;
    ll mid = (st+ed)/2;
    update(left,st,mid,x,y,val);
    update(right,mid+1,ed,x,y,val);

    tree[node].f = tree[left].f+tree[right].f+(ed-st+1)*tree[node].s;
}

ll query(ll node,ll st,ll ed,ll pos,ll carry)
{
    if(ed<pos or st>pos)
        return 0ll;
    if(st>=pos and ed<=pos){
        return tree[node].f+carry*(ed-st+1);
    }
    ll left = 2*node+1;
    ll right = 2*node+2;
    ll mid = (st+ed)/2;
    ll x = query(left,st,mid,pos,carry+tree[node].s);
    ll y = query(right,mid+1,ed,pos,carry+tree[node].s);
    return x+y;
}

int main()
{
    ll n,q,i;
    cin>>n>>q;
    for(i=0;i<n;i++){
        cin>>arr[i];
    }
    makeTree(0,0,n-1);

    ll p,a,b,u,k;
    while(q--){
        cin>>p;
        if(p==1){
            cin>>a>>b>>u;
            update(0,0,n-1,a-1,b-1,u);
        }
        else{
            cin>>k;
            ll ans = query(0,0,n-1,k-1,0);
            cout<<ans<<N;
        }
    }
    return 0;
}
