#include <bits/stdc++.h>
using namespace std;
int topdownapproach(int wines[],int n ,int i,int j,int dp[],int years){
    if(i>j)return 0;
    
    if(dp[n]!=0)return dp[n];
    
    int temp1=wines[i]*years+topdownapproach(wines,n,i+1,j,dp,years+1);
    int temp2=wines[j]*years+topdownapproach(wines,n,i,j-1,dp,years+1);
    return dp[n]=max(temp1,temp2);
   
}

int main() {
   int wines[]={1,4,7,3,2,10,5};
   int n=sizeof(wines)/sizeof(int);
   int dp[n+1]={0};
   int i=0;
   int j=n-1;
   int years=1;
   int ans1=topdownapproach(wines,n,i,j,dp,years);
   cout<<ans1<<endl;

   
}
