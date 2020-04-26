#include <bits/stdc++.h>

using namespace std;
int longest_increasing_subsequence(int arr[],int n){
    int dp[n];
    for(int i=0;i<n;i++){dp[i]=1;}
    //for(int i=0;i<n;i++){cout<<dp[i]<<" ";}
    int best=-1;
    for(int i=1;i<n;i++){
        
        for(int j=0;j<i;j++){
            if(arr[i]>arr[j]){int temp=1+dp[j];dp[i]=max(dp[i],temp);}
        }
        best=max(best,dp[i]);
    }
    
    //for(int i=0;i<n;i++){cout<<dp[i]<<" ";}
    return best;
}
int longest_decreasing_subsequence(int arr[],int n){
    int dp[n];
    for(int i=0;i<n;i++){dp[i]=1;}
    //for(int i=0;i<n;i++){cout<<dp[i]<<" ";}
    int best=-1;
    for(int i=1;i<n;i++){
        
        for(int j=0;j<i;j++){
            if(arr[i]<arr[j]){int temp=1+dp[j];dp[i]=max(dp[i],temp);}
        }
        best=max(best,dp[i]);
    }
    
    //for(int i=0;i<n;i++){cout<<dp[i]<<" ";}
    return best;
}

int main() {
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++)cin>>arr[i];
    int ans1=longest_increasing_subsequence(arr,n);
    int ans2=longest_decreasing_subsequence(arr,n);
    
    cout<<ans1<<endl;
    cout<<ans2<<endl;
}
