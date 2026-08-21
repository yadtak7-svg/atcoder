#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    string S;
    cin >> S;

    vector<long long> A;
    for(int i = 0; i < 2 * n; i++) if(S[i] == 'A') A.push_back(i);

    long long ans1 = 0, ans2 = 0;

    for(int i = 0; i < n; i++) ans1 += abs(A[i] - 2 * i);
    for(int i = 0; i < n; i++) ans2 += abs(A[i] -(2 * i + 1));

    cout << min(ans1, ans2) << '\n';
}