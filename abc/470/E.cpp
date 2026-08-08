#include<bits/stdc++.h>
using namespace std;
#define rep(i,l,r)for(int i=(l);i<(r);i++)

int main(){
	int n, l;
	cin >> n >> l;
	int sum=0;
	rep(i,0,n){
		int t;
		cin >> t;
		sum+=t;
	}
	
	vector<vector<vector<double>>> dp(l+1, vector<vector<double>>(n+1, vector<double>(n+1)));
	
	rep(life,1,l+1)rep(known,0,n+1)dp[life][known][0]=known;
	
	rep(s,1,l+n+1)rep(life,1,l+1)rep(known,0,n+1){
		int unknown=s-life-known;
		if(unknown<=0 || unknown>n || unknown+known>n)continue;
		int tot=known+2*unknown;
		double ret=0;
		double p=(double)known/tot;
		double q=(double)(2*unknown)/tot*1/(tot-1);
		double r=(double)(2*unknown)/tot*known/(tot-1);
		double s=(double)(2*unknown)/tot*(2*unknown-2)/(tot-1);
		
		if(known>0)ret+=p*(1+dp[life][known-1][unknown]);
		if(unknown>0)ret+=q*(1+dp[life][known][unknown-1]);
		if(life>1&&unknown>0)ret+=r*(1+dp[life-1][known][unknown-1]);
		if(life>1&&unknown>1)ret+=s*dp[life-1][known+2][unknown-2];
		dp[life][known][unknown]=ret;
	}
	printf("%.10f\n", (double)sum/n*dp[l][0][n]);
}