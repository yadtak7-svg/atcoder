#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> zoo;
vector<long long> cost;
int n, m;
long long ans = 1e18;
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> m;
    zoo.resize(n);
    cost.resize(n);

    for(int i = 0; i < n; i++) cin >> cost[i];
    for(int i = 0; i < m; i++) {
        int k; cin >> k;
        for(int j = 0; j < k; j++) {
            int num; cin >> num;
            num--;
            zoo[num].push_back(i);
        }
    }

    vector<int> pow3(n + 1);
    pow3[0] = 1;
    for(int i = 1; i <= n; i++) pow3[i] = pow3[i - 1] * 3;
    for(int i = 0; i < pow3[n]; i++){
        vector<int> visit(n);
        int tmp = i;
        for(int j = 0; j < n; j++) {
            visit[j] = tmp % 3;
            tmp /= 3;
        }

        vector<int> look(m, 0);
        for(int j = 0; j < n; j++) {
            for(int c : zoo[j]) {
                look[c] += visit[j];
            }
        }

        bool ok = true;
        for(int c : look) {
            if(c < 2) {
                ok = false;
                break;
            }
        }

        if(ok) {
            long long A = 0;
            for(int j = 0; j < n; j++) {
                A += visit[j] * cost[j];
            }
            ans = min(ans, A); 
        }
    }

    cout << ans << endl;

}