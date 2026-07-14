#include <bits/stdc++.h>
using namespace std;

struct X{
    int row;
    int col;
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, m;
    cin >> n >> m;

    vector<X> A(m);
    vector<bool> row(n, false), col(n, false);

    for(int i = 0; i < m; i++) {
        cin >> A[i].row >> A[i].col;
        A[i].row--, A[i].col--;
    }

    long long ans = 0;

    for(int i = m - 1; i >= 0; i--) {
        if(!row[A[i].row] && !col[A[i].col]) ans++;
        row[A[i].row] = true;
        col[A[i].col] = true;
    }

    cout << ans << endl;
}