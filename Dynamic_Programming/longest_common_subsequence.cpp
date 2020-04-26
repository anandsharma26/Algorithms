#include <bits/stdc++.h>

using namespace std;
int longest_common_subsequence(string s1,string s2){
    int m=s1.length();
    int n=s2.length();
    int dp[m+1][n+1];
    memset(dp,0,sizeof(dp));
    for(int i=1;i<=m;i++){
        for(int j=1;j<=n;j++){
            if(s1[i-1]==s2[j-1]){dp[i][j]=1+dp[i-1][j-1];}
            else{
                dp[i][j]=max(dp[i][j-1],dp[i-1][j]);
            }
        }
    }

    return dp[m][n];
    
    
}


int main() {
    string s1,s2;
    cin>>s1>>s2;

    int ans1=longest_common_subsequence(s1,s2);
    
    
    cout<<ans1<<endl;
   
}
