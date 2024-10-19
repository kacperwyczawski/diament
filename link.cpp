#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    short a_size, b_size;
    cin >> a_size >> b_size;
    vector<short> a(a_size), b(b_size);
    for (short i = 0; i < a_size; i++) {
        cin >> a[i];
    }
    for (short i = 0; i < b_size; i++) {
        cin >> b[i];
    }
    vector<vector<int>> matrix(a_size + 1, vector<int>(b_size + 1, 0));
    for (int i{1}; i <= a_size; i++) {
        for (int j{1}; j <= b_size; j++) {
            if (a[i - 1] == b[j - 1]) {
                matrix[i][j] = matrix[i - 1][j - 1] + 1;
            } else {
                matrix[i][j] = max(matrix[i][j - 1], matrix[i - 1][j]);
            }
        }
    }
    cout << matrix[a_size][b_size];
    return 0;
}

/*
resources:
https://en.wikipedia.org/wiki/Longest_common_subsequence
https://lcs-demo.sourceforge.net/
https://en.wikipedia.org/wiki/Subsequence
*/
