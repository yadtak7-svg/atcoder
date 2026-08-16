#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int Q;
    long long V;
    cin >> Q >> V;

    priority_queue<
        pair<long long, int>,
        vector<pair<long long, int>>,
        greater<pair<long long, int>>
    > full;

    priority_queue<pair<long long, int>> active;

    vector<bool> removed(Q, false);

    for (int q = 0; q < Q; q++) {
        int type;
        long long t;
        cin >> type >> t;

        if (type == 1) {
            long long w;
            cin >> w;

            long long key = w - t;
            long long fullTime = t + (V - w);

            active.push({key, q});
            full.push({fullTime, q});
        }
        else {
            while (!full.empty() && removed[full.top().second]) {
                full.pop();
            }

            while (!full.empty() && full.top().first <= t) {
                break;
            }

            while (!active.empty() && removed[active.top().second]) {
                active.pop();
            }

            if (!full.empty() && full.top().first <= t) {
                int id = full.top().second;

                removed[id] = true;

                cout << V << '\n';
            }
            else if (!active.empty()) {
                auto [key, id] = active.top();
                active.pop();

                removed[id] = true;

                cout << key + t << '\n';
            }
            else {
                cout << -1 << '\n';
            }
        }
    }
}