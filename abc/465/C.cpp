#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    string S;
    cin >> S;

    deque<int> ans;
    int rev = 0;
    for(int i = 1; i <= n; i++) {
        if(rev % 2 == 0) ans.push_back(i);
        else ans.push_front(i);

        if(S[i - 1] == 'o') rev++;
    }

    if(rev % 2 == 0) for(int x : ans) cout << x << ' ';
    else while(!ans.empty()) {
        cout << ans.back() << ' ';
        ans.pop_back();
    }
    cout << endl;
}