#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int mid;
    cin >> mid;
    int Q;
    cin >> Q;

   
    priority_queue<int> L;
    priority_queue<int, vector<int>, greater<int>> R;

    L.push(mid);

    while(Q--) {
        int a, b;
        cin >> a >> b;

        auto add = [&](int x) {
            if(x <= L.top()) L.push(x);
            else R.push(x);

            if(L.size() > R.size() + 1) {
                R.push(L.top());
                L.pop();
            }
            if(R.size() > L.size()) {
                L.push(R.top());
                R.pop();
            }
        };

        add(a);
        add(b);

        cout << L.top() << "\n";
    }
}