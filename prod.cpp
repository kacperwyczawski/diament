#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int a_size, b_size;
    cin >> a_size >> b_size;
    vector<int> a(a_size), b(b_size);
    for (int i{}; i < a_size; i++) {
        cin >> a[i];
    }
    for (int i{}; i < b_size; i++) {
        cin >> b[i];
    }
    vector<vector<int>> g(a.size());
    for (size_t row{}; row < a.size(); row++) {
        g[row].resize(b.size());
        for (size_t col{}; col < b.size(); col++) {
            auto x = b[col] * a[row];
            if (row == 0 && col == 0) {
                g[row][col] = x;
            } else if (row == 0) {
                g[row][col] = max(g[row][col - 1], x);
            } else if (col == 0) {
                g[row][col] = max(g[row - 1][col], x);
            } else if (x > 0) {
                g[row][col] = max({x + g[row - 1][col - 1], x, g[row - 1][col], g[row][col - 1]});
            } else {
                g[row][col] = max(g[row - 1][col], g[row][col - 1]);
            }
        }
    }
    cout << g[a.size() - 1][b.size() - 1];
    return 0;
}

/*
resources:
dynamic programming/tabulation
https://www.youtube.com/watch?v=oBt53YbR9Kk&t=11453s
*/
