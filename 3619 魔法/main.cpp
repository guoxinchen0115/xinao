#include<bits/stdc++.h>
using namespace std;
int main(){
	int z;
	cin>>z;
	for(int l=1;l<=z;l++){
		bool f=0;
		int len=0;
		int x,y;
		int ll=0;
		int cc[300005]={};
		int cnt[100005]={};
		int aa[100005]={},bb[100005]={};
		int aaa[100005]={},bbb[100005]={};
		int a[100005]={},b[100005]={};
		int p[100005]={},q[100005]={};
		long long n,t;
		cin>>n>>t;
		for(int i=1;i<=n;i++){
			cin>>x>>y;
			if(y>=0){
				len++;
				aaa[len]=x;
				bbb[len]=y;
				cnt[x]++;
			}
			else{
				ll++;
				p[ll]=x;
				q[ll]=y;
				cc[x+y+100000]++;
			}
		}
		for(int i=1;i<=100000;i++){
			cnt[i]+=cnt[i-1];
		}
		for(int i=1;i<=len;i++){
			aa[cnt[aaa[i]]]=aaa[i];
			bb[cnt[aaa[i]]]=bbb[i];
			cnt[aaa[i]]--;
		}
		for(int i=1;i<=300000;i++){
			cc[i]+=cc[i-1];
		}
		for(int i=1;i<=ll;i++){
			a[cc[p[i]+q[i]+100000]]=p[i];
			b[cc[p[i]+q[i]+100000]]=q[i];
			cc[p[i]+q[i]+100000]--;
		}
		f=0;
		for(int i=1;i<=len;i++){
			if(t>aa[i]&&t+bb[i]>0){
				t+=bb[i];
			}else{
				f=1;
				cout<<"-1s"<<endl;
			}
		}
		for(int i=ll;i>=1&&f==0;i--){
			if(t>a[i]&&t+b[i]>0){
				t+=b[i];
			}else{
				f=1;
				cout<<"-1s"<<endl;
			}
		}if(f==0){
			cout<<"+1s"<<endl;
		}
	} 
	return 0;
}
