#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n; cin >> n;
    vector<int> A(n);

    for(int i = 0; i < n; i++) cin >> A[i];


    int A1 = -1, A2 = -1, A3 = -1;
    for(int i = 0; i < 2; i++) {
        if(A1 <= A[i]){
            A3 = A2;
            A2 = A1;
            A1 = A[i];
            continue;
        }
        if(A2 <= A[i]){
            A3 = A2;
            A2 = A[i];
            continue;
        }
        if(A3 <= A[i]){
            A3 = A[i];
            continue;
        }
    }

    for(int i = 2; i < n; i++) {
        bool f = true;
        if(f && A1 <= A[i]){
            A3 = A2;
            A2 = A1;
            A1 = A[i];
            f = false;
        }
        if(f && A2 <= A[i]){
            A3 = A2;
            A2 = A[i];
            f = false;
        }
        if(f && A3 <= A[i]){
            A3 = A[i];
            f = false;
        }

        cout << A3 << '\n';
    }
}