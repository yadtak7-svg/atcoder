#include <bits/stdc++.h>
using namespace std;

struct Node {
    int par;
    string add;
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, Q;
    cin >> N >> Q;

    vector<Node> nodes;
    nodes.push_back({-1, ""}); 

    vector<int> pc(N, 0);
    int server = 0;

    while (Q--) {
        int t, p;
        cin >> t >> p;
        --p;

        if (t == 1) {
            pc[p] = server;
        }
        else if (t == 2) {
            string s;
            cin >> s;
            nodes.push_back({pc[p], s});
            pc[p] = (int)nodes.size() - 1;
        }
        else {
            server = pc[p];
        }
    }

    vector<string> parts;
    while (server != 0) {
        parts.push_back(nodes[server].add);
        server = nodes[server].par;
    }

    reverse(parts.begin(), parts.end());

    for (auto &x : parts) cout << x;
    cout << '\n';

    return 0;
}