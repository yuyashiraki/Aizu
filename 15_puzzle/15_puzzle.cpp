#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <climits>
#include <algorithm>
#include <vector>
#include <utility>
#include <queue>
#include <stack>
#include <map>
#include <string>
#include <sstream>
using namespace std;

#define FLG  INT_MIN
#define GOAL 0

#define N 4

map<string, int> mp;
queue<pair<string, int> > Q;

vector<string> split(const string &str, char sep)
{
    vector<string> v;
    stringstream ss(str);
    string buffer;
    while(getline(ss, buffer, sep) ) {
        v.push_back(buffer);
    }
    return v;
}

vector<int> neighbor(int pos)
{
    vector<int> rt;
    if (pos % N != 0)
        rt.push_back(pos - 1);
    if (pos % N != N - 1)
        rt.push_back(pos + 1);
    if (pos - N >= 0)
        rt.push_back(pos - N);
    if (pos + N < N * N)
        rt.push_back(pos + N);
    return rt;
}

int bfs()
{
    string st;
    int cnt, pos;
    while (!Q.empty()) {
        st = Q.front().first;
        cnt = Q.front().second;
        Q.pop();
        if (mp.count(st)) {
            if (mp[st] == FLG) {
                continue;
            } else if (mp[st] == GOAL) {
                return cnt;
            } else
                printf("ERROR: %d\n", __LINE__);
        }
        mp[st] = FLG;
        vector<string> stv(split(st, ' ')); 
        pos = distance(stv.begin(), find(stv.begin(), stv.end(), "0"));
        vector<int> nb(neighbor(pos));
        for (int i = 0; i < nb.size(); i++) {
            vector<string> tmpv(stv);
            string tmp;
            tmpv[pos] = stv[nb[i]]; tmpv[nb[i]] = stv[pos];
            for (int j = 0; j < tmpv.size(); j++) {
                tmp += tmpv[j];
                if (tmpv.size() - 1 != j) tmp += " ";
            }
            Q.push(make_pair(tmp, cnt + 1));
        }
    }
    return INT_MIN;
}

int main()
{
    string st, gl = "1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 0";
    for (int i = 0; i < N * N; i++) {
        int  j;
        cin >> j;
        st += to_string(j);
        if (N * N - 1 != i) st += " ";
    }
    mp[gl] = GOAL;
    Q.push(make_pair(st, 0));
    cout << bfs() << endl;
    return 0;
}
