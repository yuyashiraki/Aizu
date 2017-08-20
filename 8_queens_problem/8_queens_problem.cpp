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

bool flg[8] = {};
int  pos[8] = {};

bool chk(int r)
{
    for (int i = 0; i < r; i++)
        if (pos[i] == pos[r] || abs(r - i) == abs(pos[i] - pos[r]))
            return false;
    return true;
}

bool back_track(int r)
{
    if (r == 8) return true;
    for (int c = 0; c < 8; c++) {
        if (flg[r] && c != pos[r])
            continue;
        pos[r] = c;
        if (chk(r) && back_track(r + 1)) return true;
    }
    return false;
}

int main()
{
    int k, r, c, x, y;
    cin >> k;
    while (k--) {
        cin >> r >> c;
        flg[r] = true;
        pos[r] = c;
    }
    back_track(0);
    for (r = 0; r < 8; r++) {
        for (c = 0; c < 8; c++) cout << (pos[r] == c ? 'Q' : '.');
        cout << endl;
    }
    return 0;
}
