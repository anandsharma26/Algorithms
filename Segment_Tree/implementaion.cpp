#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
//BUILD a segment TREE
void build_tree(int arr[],int *tree,int ss,int se,int index){
    
    if(ss==se){tree[index]=arr[ss];return ;}
    
    int mid=(ss+se)/2;
    build_tree(arr,tree,ss,mid,2*index);
    build_tree(arr,tree,mid+1,se,2*index+1);
    tree[index]=min(tree[2*index],tree[2*index+1]);
    return;
}

// Function Query

int query(int *arr,int *tree,int ss,int se,int qs,int qe,int index){
    
    //NO overlapping case
    if(qe<ss||se<qs){return INT_MAX;}
    
    //complete overlapping case
    if(qs<=ss&&se<=qe){return tree[index];}
    
    //partial overlapping case
    
    int mid=ss+(se-ss)/2;
    int left=query(arr,tree,ss,mid,qs,qe,2*index);
    int right=query(arr,tree,mid+1,se,qs,qe,2*index+1);
    return min(left,right);
    
}


//point update function

void point_update(int *tree,int ss,int se,int pos,int new_value,int index){
    //base case for overflow check
    
    if(ss>pos||pos>se)return;
    if(ss==se){tree[index]=new_value;return;}
    
    int mid=(ss+se)/2;
    
    point_update(tree,ss,mid,pos,new_value,2*index);
    point_update(tree,mid+1,se,pos,new_value,2*index+1);
    tree[index]= min(tree[2*index],tree[2*index+1]);
    return;
}

int main() {
 int n,q;
 cin>>n>>q;
 int arr[n];
 for(int i=0;i<n;i++)cin>>arr[i];
 int *tree=new int [4*n+1];
 
 //for(int i=0;i<4*n+1;i++)tree[i]=INT_MAX;
 build_tree(arr,tree,0,n-1,1);
 

 while(q--){
    //   for(int i=0;i<4*n+1;i++)cout<<tree[i]<<" ";
    //     cout<<endl;
     int l,r;
     int decide;
     cin>>decide>>l>>r;
     if(decide==1){
         int res=query(arr,tree,0,n-1,l-1,r-1,1);
         cout<<res<<endl;
     }
     else{
         int new_value=r;
         int pos=l-1;
         point_update(tree,0,n-1,pos,new_value,1);
     }
     
 }
 
 
 
}
