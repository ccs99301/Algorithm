#include<bits/stdc++.h>
using namespace std;

typedef long long lint;
typedef double db;
struct pack{
	lint v,w;
};
lint n,l,w1,w2,ans;
pack a[22];
void init(){
	scanf("%lld%lld%lld%lld",&n,&l,&w1,&w2);
	for(int i=0;i<n;i++){
		scanf("%lld%lld",&a[i].v,&a[i].w);
	}
}
void knapsack(lint x,lint w,lint sum,lint num){
	if(w>w2) return ;
	if(x==n){
		if(num>=l && w>=w1) ans=max((lint)ceil((db)sum/w),ans);
		return ;
	}
	knapsack(x+1,w+a[x].w,sum+a[x].v,num+1);
	knapsack(x+1,w,sum,num);
}
void solve(){
	knapsack(0,0,0,0);
	printf("%lld\n",ans);
}
int main(){
	while(1){
		init();
		ans=-1;
		solve();
		int x;
		scanf("%d",&x);
		if(x==-1) return 0;
	}
}
