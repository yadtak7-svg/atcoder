#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    vector<int> A(9);
    for(int i = 0; i < 9; i++) cin >> A[i];

    vector<tuple<int, int, int>> row{
                                {0, 1, 2}, 
                                {3, 4, 5},
                                {6, 7, 8}, 
                                {0, 3, 6}, 
                                {1, 4, 7}, 
                                {2, 5, 8},
                                {0, 4, 8}, 
                                {2, 4, 6}};
    
    array<int, 9> order;
    iota(begin(order), end(order), 0);
    int good = 0, all = 0; 
    do {
        ++all;
        bool good_flag = false; 
        for (auto &&[a, b, c] : row) 
            if (A[a] == A[b] && order[a] < order[c] && order[b] < order[c])
               good_flag = true;
            else if (A[a] == A[c] && order[a] < order[b] && order[c] < order[b])
                good_flag = true;
            else if (A[b] == A[c] && order[b] < order[a] && order[c] < order[a])
                good_flag = true;
        if (!good_flag)
            good++;
    } while (next_permutation(order.begin(), order.end()));
    cout << setprecision(10);
    cout << (double)good / all << endl;
    return 0;

}