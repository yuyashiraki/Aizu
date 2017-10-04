#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <climits>
#include <cassert>
#include <algorithm>
#include <vector>
#include <utility>
#include <queue>
#include <stack>
#include <map>
#include <string>
using namespace std;

#define N 4
#define N2 16

int MDT[N2][N2]; /* Mahattan Distance Table */

/* down, left, up, right */
int dx[] = {0, -1, 0, 1};
int dy[] = {-1, 0, 1, 0};

class Puzzle
{
    public:
    int pc[N2]; /* number in each piece */
    int MD;     /* Manhattan Distance */
    int space;  /* empty space */
    int dpth;   /* Depth */

    /* override operator for mapping */
    bool operator < (const Puzzle &p) const
    {
        for (int i = 0; i < N2; i++) {
            if (pc[i] == p.pc[i]) continue;
            return pc[i] < p.pc[i];
        }
        return false;
    }
};

class State
{
    public:
    Puzzle pz;
    int cost; /* MD + dpth */

    bool operator < (const State &st) const
    {
        return cost > st.cost;
    }
};

map<Puzzle, bool> mp;
priority_queue<State> pq;

int getAllMD(Puzzle &p)
{
    int sum = 0;
    for (int i = 0; i < N2; i++) {
        if (N2 == p.pc[i]) continue;
        sum += MDT[i][p.pc[i] - 1];
    }
    return sum;
}

int astar(Puzzle &in)
{
    State initial;
    initial.pz = in;
    initial.cost = in.MD + in.dpth;
    mp[in] = true;
    pq.push(initial);
    while (!pq.empty()) {
        State node = pq.top();
        pq.pop();
        if (0 == node.pz.MD) {
            return node.pz.dpth;
        }
        int x, y;
        x = node.pz.space % N;
        y = node.pz.space / N;
        for (int i = 0; i < 4; i++) {
            int tx = x + dx[i], ty = y + dy[i];
            if (tx < 0 || tx >= N || ty < 0 || ty >= N)
                continue;
            Puzzle tp = node.pz;
            tp.space = tx + ty * N;
            swap(tp.pc[tp.space], tp.pc[node.pz.space]);
            if (!mp[tp]) {
                State ts;
                tp.MD -= MDT[tp.space][node.pz.pc[tp.space] - 1];
                tp.MD += MDT[node.pz.space][tp.pc[node.pz.space] - 1];
                tp.dpth++;
                mp[tp] = true;
                ts.pz = tp;
                ts.cost = tp.MD + tp.dpth;
                pq.push(ts);
            }
        }
    }
    return -1;
}

int main()
{
    for (int i = 0; i < N2; i++) {
        for (int j = 0; j < N2; j++) {
            /* |x - x'| + |y - y'| */
            MDT[i][j] = abs(i / N - j / N) + abs(i % N - j % N);
        }
    }

    Puzzle in;
    for (int i = 0; i < N2; i++) {
        cin >> in.pc[i];
        if (!in.pc[i]) {
            in.pc[i] = N2;
            in.space = i;
        }
    }
    in.MD = getAllMD(in);
    in.dpth = 0;

    cout << astar(in) << endl;
    return 0;
}
