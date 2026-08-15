#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string S;
    cin >> S;

    vector<int> idx;

    for (int i = 0; i < (int)S.size(); i++) {
        if (S[i] == 't') {
            idx.push_back(i);
        }
    }

    double ans = 0;

    int n = idx.size();

    for (int i = 0; i < n; i++) {
        for (int k = i + 1; k < n; k++) {
            if(k - i == 1) continue;
            int s = idx[i];
            int g = idx[k];

            int cnt = 2;  

            for (int h = s + 1; h < g; h++) {
                if (S[h] == 't') {
                    cnt++;
                }
            }

            double rate = (double)(cnt - 2) / (g - s - 1);
            ans = max(ans, rate);
        }
    }

    cout << fixed << setprecision(10) << ans << '\n';
}