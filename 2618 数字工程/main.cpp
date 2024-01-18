#include<bits/stdc++.h>
using namespace std;
int main(){
	int dp[1000005]={};
	int len=1;
	int s[1000005]={0,2};
	int n;
	for(int i=2;i<=1000001;i++){
		dp[i]=dp[i-1]+1;
		bool f=0;
		int k=i;
		for(int j=1;s[j]*s[j]<=i;j++){
			if(i%s[j]==0){
				while(k%s[j]==0){
					k/=s[j];
				}
				f=1;
				dp[i]=min(dp[i/s[j]]+1,dp[i]);
			}
		}dp[i]=min(dp[i/k]+1,dp[i]);
		if(f==0){
			len++;
			s[len]=i;
			dp[i]=1;
		}
	}
	while(cin>>n){
		cout<<dp[n]<<endl;
	}
	return 0;
}
