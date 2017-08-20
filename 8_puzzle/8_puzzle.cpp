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

vector<int> neighbor(int pos)
{
    vector<int> rt;
    if (pos % N != 0)
        rt.push_back(pos - 1);
    if (pos % N != N - 1)
        rt.push_back(pos + 1);
    if (pos - N > 0)
        rt.push_back(pos - N);
    if (pos + N < N * N)
        rt.push_back(pos + N);
    return rt;
}

/*
 * TODO: 幅優先じゃなくて、深さ優先になってる！！
 */
int bfs(string st)
{
    if (mp.count(st))
        return mp[st];
    int pos = st.find("0"), rt;
    string tmp;
    vector<int> nb(neighbor(pos));
    for (int i = 0; i < nb.size(); i++) {
        tmp = st;
        tmp[pos] = st[nb[i]]; tmp[nb[i]] = st[pos];
        if ((rt =bfs(tmp)) != FLG)
            return rt + 1;
    }
    return FLG;
}

int main()
{
    string st, gl = "123456780";
    for (int i = 0; i < 9; i++) {
        int  j;
        cin >> j;
        st += to_string(j);
    }
    mp[st] = FLG; mp[gl] = GOAL;
    cout << bfs(st) << endl;
    return 0;
}
