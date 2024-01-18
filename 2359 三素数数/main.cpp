#include<bits/stdc++.h>
using namespace std;
int main(){
	long long ans=0;
	long long dp[10001][101]={};
	long long ff[10001]={};
	long long fl=0;
	long long k[10001]={0,2}; 
	long long len=1;
	long long n;
	cin>>n;
	for(int i=3;i<=999;i++){
		bool f=0;
		for(int j=1;k[j]*k[j]<=i&&f==0;j++){
			if(i%k[j]==0){
				f=1;
			}
		}if(f==0){
			if(i>=100){
				fl++;
				ff[fl]=i;
				dp[3][i/10]++;
			}
			len++;
			k[len]=i;
			
		}
	}
	
	for(int i=4;i<=n;i++){
		for(int j=1;j<=fl;j++){
			dp[i][ff[j]/10]+=dp[i-1][ff[j]%100];
			dp[i][ff[j]/10]%=1000000009;
		}
	}
	for(int i=1;i<=99;i++){
		ans+=dp[n][i];
		ans%=1000000009;
	}cout<<ans;
	return 0;
}
