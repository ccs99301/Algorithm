#include<bits/stdc++.h>
using namespace std;

string s,t;
int dp[504][504];
int main(){
	int i,j,k;
	while(cin >> s >> t){
		memset(dp,0,sizeof(dp));
		for(i=0;i<s.size();i++){
			for(j=0;j<t.size();j++){
				if(s[i]==t[j]) dp[i+1][j+1]=dp[i][j]+1;
				else dp[i+1][j+1]=max(dp[i+1][j],dp[i][j+1]);
			}
		} //find the best for (i-1,j-1)+1 , (i-1) and (j-1) 
		printf("%d\n",dp[s.size()][t.size()]);
	}
}
