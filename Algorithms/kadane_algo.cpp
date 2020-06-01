#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

int main() {
	ll t;
	cin>>t;
	while(t--){
	    ll n;
	    cin>>n;
	    ll arr[n];
	    for(int i=0;i<n;i++)cin>>arr[i];
	    int max1=0;
	    int max2=INT_MIN;

	    for(int i=0;i<n;i++){
	        max1+=arr[i];
	        if(max1<0)max1=0;
	        if(max1>max2){max2=max1;}
	    }
	    
	    //for(int i=0;i<n;i++){cout<<sum[i]<<" ";}
	    cout<<max2;
	    cout<<endl;
	    
	}
	return 0;
}
