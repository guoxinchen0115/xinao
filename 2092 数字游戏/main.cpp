#include<bits/stdc++.h>
using namespace std;
int main(){
	int k=0;
	int c=1;
	int ans=0;
	int cnt=0;
	long long q;
	cin>>q;
	for(long long i=2;i*i<=q;i+=1){
		while(q%i==0){
		q/=i;
		cnt++;
		c*=i;
		if(cnt==2){
			ans=c;
			c=0;
			if(q!=1){
				cout<<1<<endl;
				cout<<ans;
				return 0;
			}else{
			cout<<2;
			return 0;
		}
		}
	}if(i>=3)i++;
	}
	if(q>1){
		cnt++;
		if(cnt>=3){
			cout<<1<<endl;
			cout<<ans;
			return 0;
		}
	}
	if(cnt==1){
		cout<<1<<endl;
		cout<<0;
	}else{
		cout<<2;
	}
	return 0;
}
