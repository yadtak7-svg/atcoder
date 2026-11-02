#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int k; cin >> k;
    if(k < 10) {
        cout << k << '\n';
        return 0;
    }

    priority_queue<
    long long,
    vector<long long>,
    greater<long long>
    > pq;

    for(int i = 1; i <= 9; i++) pq.push(i);

    vector<long long> A = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    while(!pq.empty()) {
        int x = pq.top(); 
        pq.pop();
        int c = x % 10;
        for(int j = 0; j < c; j++) {
            pq.push(10 * x + j);
            A.push_back(10 * x + j);
        }
    }

    cout << A[k - 1] << '\n';

}