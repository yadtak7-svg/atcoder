#include <bits/stdc++.h>
#define MAXN 1000000
using namespace std;

int cnt[MAXN+10]={0};
int dp[MAXN+10]={0};

int get_dp(int i){
	if(i<0)return 0;
	else return dp[i];
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n, d, a, total=0;
	cin >> n >> d;
	while(n--){
		cin >> a;
		cnt[a]++;
	}
	for(int i=0;i<=MAXN;i++){
		if(d==0){
			total += max(cnt[i]-1, 0);
			continue;
		}
		dp[i] = cnt[i] + min(get_dp(i-d), get_dp(i-d-d));
		if(i+d>MAXN)total += min(get_dp(i), get_dp(i-d));
	}
	cout << total << endl;
	return 0;
}