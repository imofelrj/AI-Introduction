#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>

using namespace std;

// constexpr int a[3][3]= {
//     {1,2,3},
//     {8,0,4},
//     {7,6,5}
// };

constexpr int dis[9][2] = {{1,1},{0,0},{0,1},{0,2},{1,2},{2,2},{2,1},{2,0},{1,0}};

constexpr int dx[4] = {1,-1,0,0};
constexpr int dy[4] = {0,0,1,-1};

int in[3][3];
int zero_x,zero_y,lim,status=0;

int manhattan_distance(int grid[3][3]) {
    int ret = 0;
    for (int i=0;i<3;++i) {
        for (int j=0;j<3;++j) {
            // number grid[i][j] at position i,j
            // the correct coordinate should be dis[grid[i][j]][0,1]
            int g = grid[i][j];
            if (g)  ret += abs(dis[g][0]-i) + abs(dis[g][1]-j);
        }
    }
    return ret;
}

void dfs(int gd[3][3], int zx, int zy, int step) { // zx,zy is the position of the ZERO
    if (status || step + manhattan_distance(gd) > lim)   return;
    if (manhattan_distance(gd)==0) {
        status = 1;
        return;
    }

    for (int j=0;j<4;++j) {
        int x = zx + dx[j];
        int y = zy + dy[j];
        // trying to switch x,y and zx,zy
        if (x < 0 || x > 2 || y < 0 || y > 2)   continue;

        int new_gd[3][3];
        for (int i = 0; i < 3; ++i)
            for (int j = 0; j < 3; ++j)
                new_gd[i][j] = gd[i][j];

        new_gd[x][y] = 0;
        new_gd[zx][zy] = gd[x][y];
        dfs(new_gd,x,y,step+1);
        // if (manhattan_distance(gd)-manhattan_distance(new_gd) > 0)
        //     {dfs(new_gd,x,y,step+1);}
    }
}

int main() {
    // memset(in,0,sizeof(in));
    for (int i=0;i<3;++i) {
        for (int j=0;j<3;++j) {
            char c = getchar();
            in[i][j] = c - '0';
            if (!in[i][j]) {
                zero_x = i;
                zero_y = j;
            }
        }
    }
    for (lim=0;;++lim) {
        dfs(in,zero_x,zero_y,0);
        if (status) break;
    }
    cout << lim << endl;
    return 0;
}