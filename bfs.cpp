#include <iostream>
#include <cstring>
#include <queue>
using namespace std;

int column,row,x_0,y_0;
char chart[20][20];
bool visited[20][20];
int a[4]={0,0,1,-1};
int b[4]={1,-1,0,0};

int bfs(int x, int y) {
    int cnt = 0;
    queue<pair<int, int>> q;
    q.push(make_pair(x, y));
    visited[x][y] = true;
    while (!q.empty()) {
        cnt ++;
        int sz = q.size();
        for (int i = 0; i < sz; ++i) {
            auto [m,n] = q.front();
            q.pop();
            for (int j = 0; j<4; ++j) {
                int x = m + a[j]; int y = n + b[j];
                if(x >= 0 && x < row && y >= 0 && y < column && chart[x][y] == '.' && !visited[x][y]) {
                    if (x == 0 || x == row-1 || y == 0 || y == column-1)    return cnt;
                    q.push({x,y});
                    visited[x][y] = true;
                }
            }
        }
    }
    return -1;

}
int main() {
    cin >> column >> row;
    memset(chart, 0, sizeof(chart));
    memset(visited, 0, sizeof(visited));
    for (int i = 0; i < row; ++i) {
        for (int j = 0; j < column; ++j) {
            cin >> chart[i][j];
            if (chart[i][j] == '@') {
                x_0 = i;
                y_0 = j;
            }
        }
    }
    cout << bfs(x_0, y_0) << endl;
}