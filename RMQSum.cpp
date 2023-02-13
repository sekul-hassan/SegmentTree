#include<bits/stdc++.h>
#define N '\n'
#define ll long long
using namespace std;;
ll arr[] = {3,2,1,5,2,4,2,4,2,7};
struct Node{
    ll sum;
    ll prop;
    Node(){
        sum=0;
        prop=0;
    }
};
Node tree[40];
void makeTree(ll node,ll st,ll ed)
{
    if(st==ed){
        tree[node].sum=arr[st];
        return;
    }
    ll left = 2*node+1;
    ll right = 2*node+2;
    ll mid = (st+ed)/2;
    makeTree(left,st,mid);
    makeTree(right,mid+1,ed);
    tree[node].sum = tree[left].sum+tree[right].sum;
}

ll query(ll node,ll st,ll ed,ll x,ll y)
{

    if(tree[node].prop!=0){
        tree[node].sum+=(ed-st+1)*tree[node].prop;
        if(st!=ed){
            tree[node*2+1].prop+=tree[node].prop;
            tree[node*2+2].prop+=tree[node].prop;
        }
        tree[node].prop = 0;
    }
    if(x>ed or y<st)
        return 0;

    if(st>=x and ed<=y){
        return tree[node].sum;
    }
    ll mid = (st+ed)/2;
    ll left = node*2+1;
    ll right = node*2+2;
    return query(left,st,mid,x,y)+query(right,mid+1,ed,x,y);
}

void update(ll node,ll st,ll ed,ll x,ll y,ll val)
{

    if(tree[node].prop!=0){
        tree[node].sum+=(ed-st+1)*tree[node].prop;
        if(st!=ed){
            tree[node*2+1].prop+=tree[node].prop;
            tree[node*2+2].prop+=tree[node].prop;
        }
        tree[node].prop = 0;
    }
    if(y<st or x>ed)
        return;

    if(x<=st and y>=ed){
        tree[node].sum+=(ed-st+1)*val;
        tree[node*2+1].prop += val;
        tree[node*2+2].prop += val;
        return;
    }
    ll mid = (st+ed)/2;
    ll left = node*2+1;
    ll right = node*2+2;
    update(left,st,mid,x,y,val);
    update(right,mid+1,ed,x,y,val);
    tree[node].sum = tree[left].sum+tree[right].sum;
}

ll bruteSum(ll x,ll y)
{
    ll sum = 0;
    for(ll i=x;i<=y;i++){
        sum+=arr[i];
    }
    return sum;
}

void brutUpdate(ll x,ll y,ll val)
{
    for(ll i=x;i<=y;i++){
        arr[i]+=val;
    }
}

int main()
{
    ll n = sizeof(arr)/sizeof(arr[0]);
    ll node = 0;
    ll st = 0;
    ll ed = n;
    ll t;
    ll x,y,val;
    makeTree(node,st,ed);
    do{
        cout<<"1 for QUERY\n2 for UPDATE"<<N;
        cin>>t;
        switch(t){
            case 1:
                {
                cout<<"Enter two index ";
                cin>>x>>y;
                ll ansBrute = bruteSum(x-1,y-1);
                ll ans = query(node,st,ed,x-1,y-1);
                cout<<"Segment tree answer is : "<<ans<<N;
                cout<<"Brute answer is : "<<ansBrute<<N;
                assert(ans==ansBrute);
                break;
                }
            case 2:
               {
                cout<<"Enter two index and value ";
                cin>>x>>y>>val;
                brutUpdate(x-1,y-1,val);
                update(node,st,ed,x-1,y-1,val);
                break;
               }
        }
    }while(t!=0);
}
