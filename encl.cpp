#include <algorithm>
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);
    int height, width;
    cin >> height >> width;
    vector<string> grid;
    int total_land{}, connected_land{};
    vector<vector<bool>> visited(height, vector<bool>(width));
    for (int h{}; h < height; h++) {
        string s;
        cin >> s;
        total_land += count(s.begin(), s.end(), 'l');
        grid.push_back(s);
    }
    //         row, col
    queue<pair<int, int>> to_visit;
    for (int i{}; i < width; i++) {
        if (grid[0][i] == 'l') {
            to_visit.push({0, i});
        }
    }
    if (height > 1) {
        for (int i{}; i < width; i++) {
            if (grid[height - 1][i] == 'l') {
                to_visit.push({height - 1, i});
            }
        }
    }
    for (int i{1}; i < height - 1; i++) {
        if (grid[i][0] == 'l') {
            to_visit.push({i, 0});
        }
    }
    if (width > 1) {
        for (int i{1}; i < height - 1; i++) {
            if (grid[i][width - 1] == 'l') {
                to_visit.push({i, width - 1});
            }
        }
    }
    while (!to_visit.empty()) {
        auto coords = to_visit.front();
        to_visit.pop();
        auto row = coords.first;
        auto col = coords.second;
        if (visited[row][col]) {
            continue;
        }
        visited[row][col] = true;
        connected_land++;
        if (row < height - 1 && grid[row + 1][col] == 'l') {
            to_visit.push({row + 1, col});
        }
        if (row > 0 && grid[row - 1][col] == 'l') {
            to_visit.push({row - 1, col});
        }
        if (col < width - 1 && grid[row][col + 1] == 'l') {
            to_visit.push({row, col + 1});
        }
        if (col > 0 && grid[row][col - 1] == 'l') {
            to_visit.push({row, col - 1});
        }
    }
    cout << total_land - connected_land;
    return 0;
}
