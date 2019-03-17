#include<bits/stdc++.h>
using namespace std;


struct inter{
	int L,R;
};
bool cmp(inter a,inter b){
	return a.R<b.R;
}
int n;
inter a[200200];
void solve(){
	sort(a,a+n,cmp);  // sorting on right point
	int ans=1;
	int temp=a[0].R;   // temp is the first compare thing.
	for(int i=1;i<n;i++){
		if(a[i].L>=temp){   // if left point large than temp ans++ and
			temp=a[i].R;    //   change temp varible
			ans++;          // why? because we sorting on right point 
		}        
	}
	printf("%d\n",ans);
}
void init(){
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		scanf("%d%d",&a[i].L,&a[i].R);
	}
}
int main(){
	int ncase;
	scanf("%d",&ncase);
	while(ncase--){
		init();
		solve();
	}
}
