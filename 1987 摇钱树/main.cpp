#include<bits/stdc++.h>
using namespace std;
struct shu{
	int m,b;
};
int main(){	
	int n,k;
	cin>>n>>k;
	while(n!=0||k!=0){
		int dp[1005][1005]={};
		int ans=0;
		int cnt[1005]={};
		shu tree[1001]={};
		shu tre[1001]={};
		for(int i=1;i<=n;i++){
			cin>>tree[i].m;
		}
		for(int i=1;i<=n;i++){
			cin>>tree[i].b;
			cnt[tree[i].b]++;
		}
		for(int i=1;i<=1000;i++){
			cnt[i]+=cnt[i-1];
		}
		for(int i=1;i<=n;i++){
			tre[cnt[tree[i].b]].b=tree[i].b;
			tre[cnt[tree[i].b]].m=tree[i].m;
            cnt[tree[i].b]--;
		}
		for(int i=1;i<=n/2;i++){
			swap(tre[i],tre[n-i+1]);
		}
		for(int i=1;i<=n;i++){
			for(int j=1;j<=k&&j<=i;j++){
				dp[i][j]=max(dp[i-1][j],dp[i-1][j-1]+max(0,tre[i].m-tre[i].b*(j-1)));
				ans=max(dp[i][j],ans);
			}
		}
		cout<<ans<<endl;
		cin>>n>>k;
	}
	return 0;
}
