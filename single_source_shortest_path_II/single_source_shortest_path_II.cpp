#include <iostream>
#include <utility>
#include <vector>
#include <queue>
using namespace std;

static const int MAX_N = 100; 

class comp
{
    public:
    bool operator() (pair<int, int> a, pair<int, int> b)
    {
        return a.second < b.second ? true : false;
    }
};

void dijkstra(vector<vector<pair<int, int> > > way)
{
    priority_queue<pair<int, int>, vector<pair<int, int> >, comp> PQ;
    int d[way.size()];
    bool on[way.size()];
    for (int i = 0; i < way.size(); i++) {
        d[i] = 0;
        on[i] = true;
    }
    PQ.push(make_pair(0, 0));
    while (1) {
        pair<int, int> edge = make_pair(0, INT_MAX);
        while (1) {
            cout << "DEBUG3" << endl;
            edge = PQ.top();
            PQ.pop();
            if (!on[edge.first]) break;
        }
        if (INT_MAX == edge.second) break;
        on[edge.first] = true;
        d[edge.first] = edge.second;
        for (auto itr = way.at(edge.first).begin(); itr != way.at(edge.first).end(); ++itr) {
            if (!on[itr->first]) PQ.push(make_pair(itr->first, d[itr->first] + itr->second));
        }
    }
}

int main()
{
    int n;
    cin >> n;
    vector<vector<pair<int, int> > > way(n);
    int k, c, u, v;
    for (int i = 0; i < n; i++) {
        cin >> u >> k;
        for (int j = 0; j < k; j++) {
            cin >> v >> c;
            way.at(u).push_back(make_pair(v, c));
        }
    }
    cout << "DEBUG1" << endl;
    dijkstra(way);
    return 0;
}
