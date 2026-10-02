#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, d; cin >> n >> d;
    vector<pair<int, int>> A(n);
    for(int i = 0; i < n; i++) {
        A[i].second = i;
        cin >> A[i].first;
    }

    sort(A.begin(), A.end());

    vector<int> ans;
    int cnt = 0;
    for(int i = 0; i < n; i++) {
        bool ok = true;
        if(i > 0 && abs(A[i].first - A[i - 1].first) < d) ok = false;
        if(i < n - 1 && abs(A[i].first - A[i + 1].first) < d) ok = false;
        
        if(ok){
            ans.push_back(A[i].second + 1);
            cnt++;
        } 
    }

    sort(ans.begin(), ans.end());
    cout << cnt << '\n';
    for(int i : ans) cout << i << ' ';
    cout << '\n';

}