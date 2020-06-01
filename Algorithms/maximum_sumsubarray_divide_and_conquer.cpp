#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
//changing max function for 3 variables 
int max(int a,int b,int c){
    return (max(max(a,b),c));
}

//returning  max of crossings of left and right part
int maximumcrossings(int arr[],int start,int mid,int end){
    int left_sum=INT_MIN;
    int right_sum=INT_MIN;
    int sum=0;
    
    for(int i=mid;i>=start;i--){
        sum+=arr[i];
        if(sum>left_sum){left_sum=sum;}
    }
    
    sum=0;
    for(int i=mid+1;i<=end;i++){
        sum+=arr[i];
        if(sum>right_sum){right_sum=sum;}
    }
    
    return max(right_sum+left_sum,left_sum,right_sum);
    
}

//returning max of left,rigth,crossings(left+right)
int maximumsum(int arr[],int start,int end){
    if(start==end)return arr[start];

        int mid=(start+end)/2;
        return max(maximumsum(arr,start,mid),maximumsum(arr,mid+1,end),maximumcrossings(arr,start,mid,end));
    
    
}

int main() {
	int t;
	cin>>t;
	while(t--){
	    int n;
	    cin>>n;
	    int  arr[n];
	    for(int i=0;i<n;i++)cin>>arr[i];
	    //kadanes algorithm of O(n) time 
	    int max1=0;
	    int max2=INT_MIN;

	    for(int i=0;i<n;i++){
	        max1+=arr[i];
	        if(max1<0)max1=0;
	        if(max1>max2){max2=max1;}
	    }
	    //cout<<max2<<endl;
	    
	    // Maximum subarray sum using divide and conquer approach
	    //Algorithm
	    //maximum_sum will be max of(leftpart,rightpart,crossings)
	    //crossings =max(suffix(left)+prefix(right),prefix(right),suffix(left))
	    
	    int res=maximumsum(arr,0,n-1);
	    cout<<res<<endl;
	    
	}
	return 0;
}
