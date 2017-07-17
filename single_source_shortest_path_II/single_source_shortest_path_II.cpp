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
        return a.second < b.second ? false : true;
    }
};

void dijkstra(vector<vector<pair<int, int> > > way)
{
    priority_queue<pair<int, int>, vector<pair<int, int> >, comp> PQ;
    pair<int, int> edge;
    int d[way.size()];    // array to store the cost to respective nodes
    bool on[way.size()];  // flags to indicate the minimum cost to its node has been calculated

    // initialize
    for (int i = 0; i < way.size(); i++) {
        d[i] = 0;
        on[i] = false;
    }
    PQ.push(make_pair(0, 0));

    while (!PQ.empty()) {
        edge = PQ.top();
        PQ.pop();
        // if flag is up, continue
        if (on[edge.first]) continue;
        on[edge.first] = true;
        d[edge.first] = edge.second;
        for (auto itr = way.at(edge.first).begin(); itr != way.at(edge.first).end(); ++itr) {
            if (!on[itr->first]) PQ.push(make_pair(itr->first, d[edge.first] + itr->second));
        }
    }
    // print costs
    for (int i = 0; i < way.size(); i++) {
        cout << i << " " << d[i] << endl;
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
    dijkstra(way);
    return 0;
}
