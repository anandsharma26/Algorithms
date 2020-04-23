#include <bits/stdc++.h>
using namespace std;
int topdownapproach(int n,int dp[]){
    if(n==1){return 0;}    
    
    if(dp[n]!=0){return dp[n];}
    
    int temp1,temp2,temp3;
    temp1=temp2=temp3=INT_MAX;
    if(n%2==0){temp2=1+topdownapproach(n/2,dp);}
    if(n%3==0){temp3=1+topdownapproach(n/3,dp);}
    temp1=1+topdownapproach(n-1,dp);
    dp[n]=min({temp1,temp2,temp3});
    return dp[n];
}

int bottomup(int n,int dp[]){
    dp[1]=0;
    dp[0]=INT_MAX;
    for(int i=2;i<=n;i++){
        int temp1,temp2,temp3;
        temp1=temp2=temp3=INT_MAX;

        temp1=dp[i-1]+1;
        if(i%2==0){temp2=dp[i/2]+1;}
        if(i%3==0){temp3=dp[i/3]+1;}
        dp[i]=min({temp1,temp2,temp3});
    }
    
    return dp[n];
}

int main() {
   int n;
   cin>>n;
   int dp[n+1]={0};
   int ans1=topdownapproach(n,dp);
   int ans2=bottomup(n,dp);
   cout<<ans1<<endl;
   cout<<ans2<<endl;
   
}
