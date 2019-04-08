#include<bits/stdc++.h>
using namespace std;

int dp[504][504];
string s,t;
int main(){
	int i,j;
	while(cin >> s >> t){
		for(i=0;i<=s.size();i++){ //initial for table.
			dp[i][0]=-3*i;
		}
		for(i=0;i<=t.size();i++){ 
			dp[0][i]=-3*i;
		}  // end of initial.
		for(i=0;i<s.size();i++){
			for(j=0;j<t.size();j++){
				if(s[i]==t[j]){
					dp[i+1][j+1]=dp[i][j]+8;
				}
				else{
					dp[i+1][j+1]=max(max(dp[i][j]-5,dp[i+1][j]-3),dp[i][j+1]-3);
				}
			}
		} // if match find the best for (i-1,j-1)+8 , (i-1)-3 and (j-1)-3
		// else find the best for (i-1,j-1)-5 , (i-1)-3 and (j-1)-3
		printf("%d\n",dp[s.size()][t.size()]);
	}
}
