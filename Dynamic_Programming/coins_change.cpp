#include <bits/stdc++.h>
using namespace std;
int topdownapproach(int n,int dp[],int coins[],int t){
    
   if(n==0)return 0;
   
   if(dp[n]!=0)return dp[n];
   
    int min_denoms=INT_MAX;
    for (int i=0;i<t;i++){
        
        if((n-coins[i])>=0){
            int temp=topdownapproach((n-coins[i]),dp,coins,t)+1;
            min_denoms=min(min_denoms,temp);
        }
        
    }
    dp[n]=min_denoms;
    return dp[n];
}

int bottomup(int n,int dp[],int coins[],int t){
    dp[0]=0;
    int ans=INT_MAX;
    for(int i=0;i<t;i++){
        if((n-coins[i]>=0)){
            int temp=dp[n-coins[i]]+1;
            ans=min(ans,temp);
        }
    }
    return dp[n];
}

int main() {
   int n;
   cin>>n;
   int coins[]={1,4,7};
   int t=sizeof(coins)/sizeof(int);
   int dp[n+1]={0};
   int ans1=topdownapproach(n,dp,coins,t);
   int ans2=bottomup(n,dp,coins,t);
   cout<<ans1<<endl;
   cout<<ans2<<endl;
   
}
