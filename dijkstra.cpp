#include <iostream>
#include <cstring>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

const double MAX=100000;
static int now=0;

int n,stop;

struct point {
    int num;
    double dis;
    bool visited;
};

struct cmp {
    bool operator() (point a, point b) { //less
        if (a.dis<b.dis || (a.dis==b.dis && a.num < b.num)) return false;
        else    return true;
    }
};
// bool operator>(point a, point b) {
//     if (a.number<b.number)  return true;
//     else    return false;
// }
// bool operator<(point a, point b) {
//     if (a.number>=b.number) return true;
//     else    return false;
// }

double dijkstra(int stop, vector<vector<double>> adj) { // start from point 0
    int sz = adj[0].size();
    vector<double> dist(sz,MAX);
    dist[0]=0;
    vector<bool> visited(sz,false);
    priority_queue<point,vector<point>,cmp> p;
    while (true) {
        int status = -1;
        visited[0]=true;
        for (int i=now+1;i<n;++i) {
            // scanning dist, we should find min dist[i] while visited[i]=false
            // record the first such i and then set i
            dist[i]=min(dist[i],dist[now]+adj[now][i]);
            if (!visited[i]) {
                p.push(point{i, dist[i], visited[i]});
                status=1;
            }
        }
        if (status < 0) return dist[stop-1];
        now = p.top().num;
        visited[now] = true;
        priority_queue<point,vector<point>,cmp> empty;swap(empty,p);
        
    }
    return -1;
}

int main() {
    cin >> n >> stop;
    vector<vector<double>> adj(n, vector<double>(n, MAX));
    for (int i=0;i<n;++i) {
        for (int j=0;j<n;++j) {
            cin >> adj[i][j];
            if (adj[i][j]==-1)  adj[i][j]=MAX;
        }
    }
    cout << dijkstra(stop,adj) << endl;
    return 0;
}
