#include<bits/stdc++.h>
using namespace std;

int main(){
	ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, H, M; cin >> n >> H >> M;
    vector<int> dp(H + 1);
	for(int i = 1; i <= n; i++){
		int h, m;
        cin >> h >> m;
		for(int i = H; i >= 0; i--){
			if(i >= h){
				dp[i] = min(dp[i] + m, dp[i-h]);
			}else {
				dp[i] += m;
			}
		}
		if(dp[H] > M){
			cout << i-1 << endl;  
			return 0;
		}
	}
	cout << n << endl;
	return 0;
}
