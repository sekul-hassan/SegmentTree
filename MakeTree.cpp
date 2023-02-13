#include<bits/stdc++.h>
using namespace std;
#define mx 10001
#define N '\n'
int arr[] = {4,-9,3,7,1,0,2};
int tree[14];

void makeTree(int start_node,int begin,int end){

    if(begin==end){
        tree[start_node] = arr[begin];
        return ;
    }
    int left_child = 2*start_node+1;
    int right_child = 2*start_node + 2;
    int mid = (begin+end)/2;
    makeTree(left_child,begin,mid);
    makeTree(right_child,mid+1,end);
    tree[start_node] = tree[left_child]+tree[right_child];
}
int main()
{
   int start_node = 0;
   int begin = 0;
   int end = 7;
   makeTree(start_node,begin,end);
   for(int i=0;i<14;i++){
        cout<<tree[i]<<" ";
   }
   return 0;
}