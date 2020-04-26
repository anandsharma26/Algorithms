#include <bits/stdc++.h>

using namespace std;

int topdownapproach(int n,int k,int dp[]){
    dp[0]=1;
    //for(int i=0;i<100;i++)cout<<dp[i]<<" ";
    if(n==0)return 1;
    
    if(dp[n]!=0)return dp[n];
    int ways=0;
    for (int  i=1;i<=k;i++){
        if(n-i>=0)
        ways+=topdownapproach(n-i,k,dp);
        //cout<<ways<<endl;
    }
    return (dp[n]=ways);
}

int bottomupapproach(int n,int k){
    int dp[100]={0};
    dp[0]=1;
   
    for(int j=1;j<=n;j++){
        for(int i=1;i<=k;i++){
            if(j-i>=0)
            dp[j]+=dp[j-i];
            //cout<<dp[j]<<" ";
            else continue;
        }
    }
    return dp[n];
    
}

int optimized_ladder(int n,int k){
    
    int dp[100]={0};
    dp[0]=1;
    dp[1]=1;
    for(int i=2;i<=k;i++){dp[i]=2*dp[i-1];}
    
    for(int i=k+1;i<=n;i++){
        dp[i]=2*dp[i-1]-dp[i-k-1];
    }
    return dp[n];

}
int main() {
    int n,k;
    cin>>n>>k;
    int dp[100]={0};
    int ans1=topdownapproach(n,k,dp);
    int ans2=bottomupapproach(n,k);
    int ans3=optimized_ladder(n,k);
    cout<<ans1<<endl;
    cout<<ans2<<endl;
    cout<<ans3<<endl;
}
