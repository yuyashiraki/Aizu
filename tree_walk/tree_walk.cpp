#include <iostream>
#include <vector>
using namespace std;

#define NIL -1

class Node
{
  public:
  int p = NIL, l, r;
};


void preorder(vector<Node>& nodes, vector<int>& out, int cur)
{
    if (cur == NIL) return;
    out.push_back(cur);
    preorder(nodes, out, nodes.at(cur).l);
    preorder(nodes, out, nodes.at(cur).r);
}

void inorder(vector<Node>& nodes, vector<int>& out, int cur)
{
    if (cur == NIL) return;
    inorder(nodes, out, nodes.at(cur).l);
    out.push_back(cur);
    inorder(nodes, out, nodes.at(cur).r);
}

void postorder(vector<Node>& nodes, vector<int>& out, int cur)
{
    if (cur == NIL) return;
    postorder(nodes, out, nodes.at(cur).l);
    postorder(nodes, out, nodes.at(cur).r);
    out.push_back(cur);
}

void itr_print(vector<int>& out)
{
    for (auto itr = out.begin(); itr != out.end(); ++itr) {
        cout << " ";
        cout << *itr;
    }
    cout << endl;
}

int main()
{
  int n, r;
  cin >> n;
  vector<Node> nodes(n);
  vector<int> out;
  for (int i = 0; i < n; i++) {
    int id, l, r;
    cin >> id >> l >> r;
    nodes.at(id).l = l;
    if (l != (NIL)) {
      nodes.at(l).p = id;
    }
    nodes.at(id).r = r;
    if (r != (NIL)) {
      nodes.at(r).p = id;
    }
  }
  while(n--) {
    r = nodes.at(n).p == NIL ? n : r;
  }
  cout << "Preorder" << endl;
  preorder(nodes, out, r);
  itr_print(out);
  out.clear();
  cout << "Inorder" << endl;
  inorder(nodes, out, r);
  itr_print(out);
  out.clear();
  cout << "Postorder" << endl;
  postorder(nodes, out, r);
  itr_print(out);
  out.clear();
  return 0;
}
