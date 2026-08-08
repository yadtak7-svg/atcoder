#include <iostream>
#include <map>
using namespace std;

int main() {
    int N;
    cin >> N;

    map<int, int> counter;

    long long ans = 0;
    for (int i = 0; i < N; ++i) {
        int a;
        cin >> a;
        ans += counter[i - a];
        ++counter[i + a];
    }
    cout << ans << endl;
    return 0;
}
