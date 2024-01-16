#include<bits/stdc++.h>
using namespace std;
bool zhi(int p,int q){
	if(p%q==0){
		if(q==1){
			return 0;
		}
		else{
			return 1;
		}
	}else{
		return zhi(q,p%q);
	}
}
int main(){
	long long ans=0;
	long long f[805]={};
	long long dp[805][405]={};
	long long n;
	cin>>n;
	long long a[805]={},b[805]={};
	for(int i=1;i<=n;i++){
		cin>>a[i];
	} 
	for(int i=1;i<=n;i++){
		cin>>b[i];
	}
	for(int i=2;i<=n;i++){
		if(zhi(a[i],a[i-1])==1){
			dp[i][1]=b[i]+b[i-1];
		}
		for(int j=2;j<=n&&j*2<=i;j++){
			if(zhi(a[i],a[i-2*j+1])==1&&dp[i-1][j-1]!=0){
				dp[i][j]=dp[i-1][j-1]+b[i]+b[i-2*j+1];
			}
			else{
				for(int o=1;o<j;o++){
					if(dp[i][o]!=0&&dp[i-2*o][j-o]!=0){
						dp[i][j]=dp[i][o]+dp[i-2*o][j-o];
						break;
					}
				}
			}
		}
	}
	for(int i=1;i<=n;i++){
		f[i]=f[i-1];
		for(int j=1;j<=n&&j*2<=i;j++){
			f[i]=max(dp[i][j]+f[i-2*j],f[i]);
		}
		ans=max(ans,f[i]);
	}cout<<ans;
	return 0;
}
