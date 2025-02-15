#include <queue>
#include <iostream>
#include <algorithm>
using namespace std;
struct point {
    int num;
    int dis;
    bool visited;
};

struct cmp {
    bool operator() (point a, point b) { //less
        if (a.dis<b.dis || (a.dis==b.dis && a.num < b.num)) return false;
        else    return true;
    }
};
priority_queue<point,vector<point>,cmp> p;
int main() {
    p.push(point{1,2,0});
    p.push(point{0,1,0});
    p.push(point{1,1,0});
    cout << p.top().num << p.top().dis << endl;
    return 0;
}