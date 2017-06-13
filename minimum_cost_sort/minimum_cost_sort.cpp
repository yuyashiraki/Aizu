#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define MAX_W 10000

class wi {
    public:
    int w, i;
    bool done;
};

bool cmp(wi& wi1, wi& wi2)
{
    if (wi1.w < wi2.w) return true;
    else return false;
}

int solve(vector<wi> w)
{
    int ans = 0, count = 0;
    sort(w.begin(), w.end(), cmp);
    for (vector<wi>::iterator itr = w.begin(); itr != w.end(); ++itr) {
        if (itr->done) continue;
        vector<wi>::iterator cur = itr;
        int an = 0, S = 0;
        while (!cur->done) {
            cur->done = true;
            an++;
            S += cur->w;
            cur = w.begin() + cur->i;
        }
        ans += min(S + (an - 2) * itr->w, itr->w + S + (an + 1) * w.begin()->w);
    }
    return ans;
}

int main()
{
    int i = 0, n;
    cin >> n;
    vector<wi> w(n);
    for (vector<wi>::iterator itr = w.begin(); itr != w.end(); ++itr) {
        cin >> itr->w;
        itr->i = i++;
        itr->done = false;
    }
    int ans = solve(w);
    cout << ans << endl;
    return 0;
}
