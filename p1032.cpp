#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

string a,b,tmp1,tmp2;

struct Node {
    string domain;
    string value;
    Node(const string &d, const string &v) : domain(d), value(v) {}
};

vector<Node> vec;

void bfs(string str1, string str2, vector<Node> v) {
    int cnt = 0;
    queue<pair<string, int> > q;
    q.push(make_pair(str1,0));
    while (!q.empty()) {
        cnt++;
        int sz = q.size();
        // cout << "Now count " << cnt << endl;
        for (int i = 0; i < sz; ++i) {
            auto ft = q.front();
            q.pop();
            if (ft.second > 10) continue;
            for (auto iter = v.begin(); iter!=v.end(); ++iter) { // apply all rules
                int j = 0;
                while (true) {
                    auto copy = ft.first;
                    j = copy.find(iter->domain, j);
                    if (j == string::npos)    break;
                    auto st = copy.replace(j, iter->domain.length(), iter->value);
                    q.push(make_pair(st, cnt));
                    // cout << "Used rule " << iter-v.begin() << endl;
                    // cout << "Replacing " << iter->domain <<" to " << iter->value << endl;
                    // cout << st << " " << q.back().first << endl;
                    if (st == str2) {
                        cout << cnt << endl;
                        return;
                    }
                    j++;
                }
            }
        }
    }
    cout << "NO ANSWER!" << endl;
    return;
}

int main() {
    string a, b, tmp1, tmp2;
    // int n;
    // cin >> a >> b >> n;
    // for (int i = 0; i < n; ++i) {
    //     cin >> tmp1 >> tmp2;
    //     vec.push_back(Node(tmp1,tmp2));
    // }
    cin >> a >> b;
    while (cin >> tmp1 >> tmp2)
        vec.push_back(Node(tmp1,tmp2));
    bfs(a, b, vec);
    return 0;
}