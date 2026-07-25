#include <bits/stdc++.h>
#include <atcoder/modint>
using namespace std;
using mint = atcoder::modint998244353;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n; cin >> n;
    vector<vector<int>> A(n, vector<int>(6));
    vector<int> S;

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < 6; j++) {
            cin >> A[i][j];
            S.push_back(A[i][j]);
        }
    }

    sort(S.begin(), S.end());
    S.erase(unique(S.begin(), S.end()), S.end());
    int k = S.size();
    vector<vector<int>> upd(k);
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < 6; j++) {
            int id = lower_bound(S.begin(), S.end(), A[i][j]) - S.begin();
            upd[id].push_back(i);
        }
    }

    mint ans = 0;
    vector<int> B(n);
    mint prod = 1;
    int z_cnt = n;
    for(int i = 0; i < k - 1; i++) {
        for(int j : upd[i]) {
            if(!B[j]) z_cnt--;
            else prod /= B[j];
            ++B[j];
            prod *= B[j];
        }
        ans -= (z_cnt ? 0 : prod) * (S[i + 1] - S[i]);
    }
    ans /= mint(6).pow(n);
    ans += S[k - 1];
    cout << ans.val() << endl;
}