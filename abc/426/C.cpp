#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, Q;
    cin >> N >> Q;

    vector<int> cnt(N + 1, 1);

    set<int> st;

    for (int v = 1; v <= N; v++) {
        st.insert(v);
    }

    while (Q--) {
        int X, Y;
        cin >> X >> Y;

        long long ans = 0;

        while (!st.empty()) {
            auto it = st.begin();

            if (*it > X) break;

            int v = *it;

            ans += cnt[v];
            cnt[v] = 0;

            st.erase(it);
        }

        cnt[Y] += ans;
        st.insert(Y);

        cout << ans << '\n';
    }

}