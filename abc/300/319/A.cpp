#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    unordered_map<string, int> mp;

    mp["tourist"] = 3858;
    mp["ksun48"] = 3679;
    mp["Benq"] = 3658;
    mp["Um_nik"] = 3648;
    mp["apiad"] = 3638;
    mp["Stonefeang"] = 3630;
    mp["ecnerwala"] = 3613;
    mp["mnbvmar"] = 3555;
    mp["newbiedmy"] = 3516;
    mp["semiexp"] = 3481;

    string S; cin >> S;
    cout << mp[S] << '\n';
}