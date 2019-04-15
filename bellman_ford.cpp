#include<bits/stdc++.h>
using namespace std;



struct EDGE{
	int to,w;
};
int n,m,q;
vector<EDGE> edge[5005];
bool rec[5005];
bool check;
void init(){
	scanf("%d%d%d",&n,&m,&q);
	for(int i=0;i<n;i++) edge[i].clear();
	for(int i=0;i<m;i++){
		int a,b,w;
		scanf("%d%d%d",&a,&b,&w);
		edge[a].push_back({b,w});
	}
}
void bellman_ford(int s,int t){
	int dis[n+5];
	int path[n+5];
	memset(dis,0x3f3f3f3f,sizeof(dis));
	memset(path,-1,sizeof(path));
	bool flag=true;
	int temp;
	dis[s]=0;
	for(int k=0;k<n;k++){
		for(int i=0;i<n;i++){
			for(int j=0;j<edge[i].size();j++){
				EDGE x=edge[i][j];
				if(dis[i]+x.w<dis[x.to]){
					if(k==n-1 && (i==t || x.to==t)){
						flag=false;
					}
					dis[x.to]=dis[i]+x.w;
					path[x.to]=i;
				}
			}
		}
	}
	if(!flag || dis[t]==0x3f3f3f3f){
		printf("no\n");
	}
	else{
		printf("%d\n",dis[t]);
	}
}
void solve(){
	while(q--){
		int s,t;
		scanf("%d%d",&s,&t);
		//memset(rec,false,sizeof(rec));
		//check=false;
		bellman_ford(s,t);
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
