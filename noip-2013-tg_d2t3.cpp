#include <iostream>
#include <cstring>
#include <cstdio>
#include <queue>

using namespace std;

const int MAX = 50;

int n, m, q;
int blank_x, blank_y;
int start_x, start_y, end_x, end_y;
int lat[MAX][MAX];
int visited[MAX][MAX][MAX][MAX];

int dx[4] = { 1, 0, 0, -1 };
int dy[4] = { 0, -1, 1, 0 };

struct Status {
    int x, y;
    int sx, sy;
    int last;
    Status() : x(0), y(0), sx(0), sy(0), last(0) {}
    Status(int x, int y, int sx, int sy, int last) : x(x), y(y), sx(sx), sy(sy), last(last) {}
};

int bfs(int bx, int by, int sx, int sy) {
    int cnt = 0;
    queue<Status> que;
    que.push(Status(bx, by, sx, sy,4));
    visited[bx][by][sx][sy] = 1;
    
    while (!que.empty()) {
        int levelSize = que.size();
        cnt++;

        for (int i = 0; i < levelSize; ++i) {
            Status cur = que.front();
            que.pop();
            for (int j = 0; j < 4; ++j) {
                if (cur.last + j == 3)   continue;
                int x = cur.x + dx[j];
                int y = cur.y + dy[j];
                // switching (cur.x,cur.y) with (x,y)
                if (x < 1 || x > n || y <1 || y > m || lat[x][y] == 0)    continue;
                Status now;
                if (x == cur.sx && y == cur.sy)
                    now = Status(x, y, cur.x, cur.y,0);
                else
                    now = Status(x, y, cur.sx, cur.sy,0);
                if (visited[now.x][now.y][now.sx][now.sy]==1)    continue;
                now.last = j;
                visited[now.x][now.y][now.sx][now.sy]=1;
                que.push(now);
                if (now.sx == end_x && now.sy == end_y) return cnt;
            }   
        }
    }
    return -1;
}

int main() {
    // ios::sync_with_stdio(false),cin.tie(nullptr),cout.tie(nullptr);
    cin >> n >> m >> q;
    memset(lat, 0, sizeof(lat));
    memset(visited, 0, sizeof(visited));

    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            // cin >> lat[i][j];
            scanf("%d",&lat[i][j]);
        }
    }
    
    for (int i = 0; i < q; ++i) {
        cin >> blank_x >> blank_y >> start_x >> start_y >> end_x >> end_y;
        cout << bfs(blank_x, blank_y, start_x, start_y) << endl;
        // scanf("%d %d %d %d %d %d", &blank_x, &blank_y, &start_x, &start_y, &end_x, &end_y);
        // printf("%d\n", bfs(blank_x, blank_y, start_x, start_y));
        memset(visited, 0, sizeof(visited));
    }
    
    return 0;
}