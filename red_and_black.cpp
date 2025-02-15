#include <iostream>
#include <cstring>
using namespace std;
int column,row,x_0,y_0;
int a[4]={0,0,1,-1};
int b[4]={1,-1,0,0};
// max 20x20
// .black, #red
char chart[20][20];
bool visited[20][20];

int dfs(int x, int y) {
    int cnt = 1;
    visited[x][y] = true;
    for (int i = 0; i < 4; i++) {
        int x_new = x + a[i];
        int y_new = y + b[i];
        if (x_new <0 || x_new >= row || y_new < 0 || y_new >= column)
            continue;
        if (visited[x_new][y_new] || chart[x_new][y_new] == '#')
            continue;
        cnt += dfs(x_new, y_new);
    }
    return cnt;
}

int main() {
    memset(chart, 0, sizeof(chart));
    memset(visited, 0, sizeof(visited));
    cin >> column >> row;
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < column; j++) {
            cin >> chart[i][j];
            if (chart[i][j] == '@') {
                x_0 = i;
                y_0 = j;
            }
        }
    }
    cout << dfs(x_0,y_0) << endl;
    return 0;
}