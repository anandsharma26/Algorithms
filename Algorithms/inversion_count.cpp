#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

int merge(ll arr[],int start,int mid,int end){
    int count=0;
    int n1=mid-start+1;
    int n2=end-mid;
    int L[n1];
    int R[n2];
    for(int i=0;i<n1;i++)L[i]=arr[i+start];
    for(int j=0;j<n2;j++)R[j]=arr[j+mid+1];
    
    int i=0,j=0;
    int k=start;
    while(i<n1&&j<n2){
        if(L[i]<R[j]){arr[k]=L[i];i++;k++;}
        else {arr[k]=R[j];j++;k++;count+=(n1-i);}
    }
    while(i<n1){arr[k]=L[i];i++;k++;}
    while(j<n2){arr[k]=R[j];j++;k++;}
    
    
    return count;
    
}

int mergesort(ll arr[],int start,int end){
    int count=0;
    if(start<end){
    int mid=start+(end-start)/2;
    count+=mergesort(arr,start,mid);
    count+=mergesort(arr,mid+1,end);
    count+=merge(arr,start,mid,end);
    }
    return count;
}
int main() {
	ll t;
	cin>>t;
	while(t--){
	    ll n;
	    cin>>n;
	    ll arr[n];
	    for(int i=0;i<n;i++)cin>>arr[i];
	    //BRUTE FORCE APPROACH O(n2) solution
	    ll res=0;
	    for(int i=0;i<n-1;i++){
	        for(int j=i+1;j<n;j++){
	            if(arr[i]>arr[j])res++;
	        }
	    }
	    //cout<<res<<endl;
	    
	    //EXTENSION OF MERGESORT to DO INVERSION COUNT
	    int count=mergesort(arr,0,n-1);
	    
	    cout<<count<<endl;
	    //for(int i=0;i<n;i++)cout<<arr[i]<<" ";
	}
	return 0;
}
