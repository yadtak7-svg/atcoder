#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;

    vector<vector<int>> ans(n);

    for(int i = 1; i <= n; i++) {
        int k; cin >> k;
        for(int j = 0; j < k; j++) {
            int t; cin >> t;
            ans[t - 1].push_back(i);
        }
    }

    for(vector<int> A : ans) {
        cout << A.size() << " ";
        for(int x : A) {
            cout << x << " ";
        }
        cout << endl;
    }
}