#include<bits/stdc++.h>
using namespace std;


struct inter{
	int L,R;
};
bool cmp(inter a,inter b){
	if(a.L==b.L) return a.R>b.R;
	return a.L<b.L;
}
inter a[200200];
int n;
void init(){
	char s[25];
	int i=0;
	while(1){
		if(fgets(s,20,stdin)==NULL){
			n=i;
			return ;
		}
		if(s[0]=='\0' || s[0]=='\n' || s[0]=='\r'){
			n=i;
			return ;
		}
		sscanf(s,"%d%d",&a[i].L,&a[i].R);
		if(a[i].L>a[i].R) swap(a[i].L,a[i].R);
		i++;
	}
}
void solve(){
	sort(a,a+n,cmp); // sorting by left point
	int temp=-1,maxi=-1,ans=0;  
	for(int i=0;i<n;i++){
		if(a[i].L<=temp+1){  // find the best right point that left point 
			if(a[i].R>maxi) maxi=a[i].R;   // on 0 to temp+1. 
		}
		else{        // end find
			temp=maxi;
			maxi=a[i].R;
			ans++;      // if we found ans++.
		}
		if(maxi==199) break;
	}
	printf("%d\n",ans+1);
}
int main(){
	int ncase;
	char line[25];
	fgets(line,20,stdin);
	ncase=atoi(line);
	fgets(line,20,stdin);
	while(ncase--){
		init();
		solve();
	}
}
