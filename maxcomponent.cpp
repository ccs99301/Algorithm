#include<bits/stdc++.h>
using namespace std;


int n,m;
vector<int> edge[50004];
int value[50004];
int ans,maxi;
bool visit[50004];
void init(){
	scanf("%d%d",&n,&m);
	for(int i=0;i<n;i++) edge[i].clear();
	for(int i=0;i<n;i++){
		scanf("%d",&value[i]);
	}
	for(int i=0;i<m;i++){
		int a,b;
		scanf("%d%d",&a,&b);
		edge[a].push_back(b);
		edge[b].push_back(a);
	}
}
void dfs(int a){
	if(visit[a]) return ;
	visit[a]=true;
	maxi+=value[a];
	for(int i=0;i<edge[a].size();i++){
		dfs(edge[a][i]);
	}
}
void solve(){
	ans=0;
	memset(visit,false,sizeof(visit));
	for(int i=0;i<n;i++){
		maxi=0;
		dfs(i);
		ans=max(ans,maxi);	
	}
	printf("%d\n",ans);
}
int main(){
	int ncase;
	scanf("%d",&ncase);
	while(ncase--){
		init();
		solve();
	}
}
