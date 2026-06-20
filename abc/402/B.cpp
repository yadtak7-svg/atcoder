#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    queue<int> q;
    int t;
    cin >> t;

    while(t--) {
        int a;
        cin >> a;

        if(a == 1) {
            int num;
            cin >> num;
            q.push(num);
        }
        if(a == 2) {
            cout << q.front() << endl;
            q.pop();
        }
    }
}