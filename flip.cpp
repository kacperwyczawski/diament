#include <iostream>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, k;
    string s;
    cin >> n >> k >> s;
    int steps{};
    for (int i{}; i <= n - k; i++) {
        if (s[i] == 'w') {
            continue;
        }
        steps++;
        for (int j{i}; j < k + i; j++) {
            if (s[j] == 'w') {
                s[j] = 'b';
            } else {
                s[j] = 'w';
            }
        }
    }
    for (auto& c : s) {
        if (c == 'b') {
            cout << -1;
            return 0;
        }
    }
    cout << steps;
    return 0;
}
