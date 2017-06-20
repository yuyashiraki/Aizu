#include <iostream>
#include <vector>
using namespace std;

class Node
{
  public:
  int p = -1, s = -1, l, r, d, h;
};

int getDepth(vector<Node>& nodes, Node& cur, int d)
{
  cur.d = d;
  int hl = 0, hr = 0;
  if (cur.l != -1) hl = getDepth(nodes, nodes.at(cur.l), d + 1) + 1;
  if (cur.r != -1) hr = getDepth(nodes, nodes.at(cur.r), d + 1) + 1;
  return cur.h = hl > hr ? hl : hr;
}

int main()
{
  int n, r;
  cin >> n;
  vector<Node> nodes(n);
  for (int i = 0; i < n; i++) {
    int id, l, r;
    cin >> id >> l >> r;
    nodes.at(id).l = l;
    if (l != (-1)) {
      nodes.at(l).p = id; nodes.at(l).s = r;
    }
    nodes.at(id).r = r;
    if (r != (-1)) {
      nodes.at(r).p = id; nodes.at(r).s = l;
    }
  }
  while(n--) {
    r = nodes.at(n).p == -1 ? n : r;
  }
  getDepth(nodes, nodes.at(r), 0);
  for (auto itr = nodes.begin(); itr != nodes.end(); ++itr) {
    int deg = 0;
    deg += (itr->l != -1) + (itr->r != -1);
    cout << "node " << ++n    << ": "
    << "parent = "  << itr->p << ", "
    << "sibling = " << itr->s << ", "
    << "degree = "  << deg    << ", "
    << "depth = "   << itr->d << ", "
    << "height = "  << itr->h << ", ";
    if (itr->p == -1) cout << "root" << endl;
    else if (itr->h == 0)  cout << "leaf" << endl;
    else cout << "internal node" << endl;
  }
  return 0;
}
