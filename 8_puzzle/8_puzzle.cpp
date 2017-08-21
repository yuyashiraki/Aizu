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
using namespace std;

#define FLG  INT_MIN
#define GOAL 0

#define N 3

map<string, int> mp;
queue<pair<string, int> > Q;

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
    string st, tmp;
    int cnt, pos;
    while (!Q.empty()) {
        st = Q.front().first;
        cnt = Q.front().second;
        pos = st.find("0");
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
        vector<int> nb(neighbor(pos));
        for (int i = 0; i < nb.size(); i++) {
            tmp = st;
            tmp[pos] = st[nb[i]]; tmp[nb[i]] = st[pos];
            Q.push(make_pair(tmp, cnt + 1));
        }
    }
    return INT_MIN;
}

int main()
{
    string st, gl = "123456780";
    for (int i = 0; i < 9; i++) {
        int  j;
        cin >> j;
        st += to_string(j);
    }
    mp[gl] = GOAL;
    Q.push(make_pair(st, 0));
    cout << bfs() << endl;
    return 0;
}
