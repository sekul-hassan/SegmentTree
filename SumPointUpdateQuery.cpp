#include<bits/stdc++.h>
using namespace std;
#define N '\n'

int arr[] = {4,-9,3,7,1,0,2};
int tree[14];

void makeTree(int node,int start,int end)
{
    if(start==end){
        tree[node] = arr[start];
        return ;
    }
    int left_node = node*2+1;
    int right_node = node*2+2;
    int mid = (start+end)/2;
    makeTree(left_node,start,mid);
    makeTree(right_node,mid+1,end);
    tree[node] = tree[right_node]+tree[left_node];
}

int sumQuery(int start_node,int start,int end,int i,int j)
{
    if(i>end or j<start){
        return 0;
    }
    if(i<=start and end<=j){
        return tree[start_node];
    }
    int left_node = start_node*2+1;
    int right_node = start_node*2+2;
    int mid = (start+end)/2;
    return sumQuery(left_node,start,mid,i,j)+sumQuery(right_node,mid+1,end,i,j);
}

void update(int start_node,int start,int end,int update_i,int update_value)
{
    if(update_i>end or update_i<start){
        return ;
    }
    if(update_i==start ){
        tree[start_node] = update_value;
        return ;
    }
    int left_node = start_node*2+1;
    int right_node = start_node*2+2;
    int mid = (start+end)/2;
    update(left_node,start,mid,update_i,update_value);
    update(right_node,mid+1,end,update_i,update_value);
}

int main()
{
    int start_node = 0;
    int start = 0;
    int end = 7;
    makeTree(start_node,start,end);
    int i=2;
    int j = 6;
    int sum = sumQuery(start_node,start,end,i-1,j-1);
    cout<<sum<<N;

    int update_i = 2;
    int update_value = 9;
    update(start_node,start,end,update_i-1,update_value);
    sum = sumQuery(start_node,start,end,i-1,j-1);
    cout<<sum;
}