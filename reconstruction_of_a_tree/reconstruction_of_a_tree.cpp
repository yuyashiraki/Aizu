#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define NIL -1

vector<int> pre, ino;

class Node
{
  public:
  int p = NIL, l = NIL, r = NIL;
};

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
        if (itr != out.begin()) cout << " ";
        cout << *itr + 1;
    }
    cout << endl;
}

int crt(vector<Node>& nodes, vector<int>::iterator ino_b, vector<int>::iterator ino_e, vector<int>::iterator pre_cur)
{
    if (ino_b == ino_e) return NIL;
    vector<int>::iterator root;
    while(pre_cur != ino.end()) {
        if (ino_e == (root = find(ino_b, ino_e, *pre_cur++))) continue;
        int l = crt(nodes, ino_b, root, pre_cur);
        nodes.at(*root).l = l;
        if (NIL != l) nodes.at(l).p = *root;
        int r = crt(nodes, root + 1, ino_e, pre_cur);
        nodes.at(*root).r = r;
        if (NIL != r) nodes.at(r).p = *root;
        return *root;
    }
    cout << "error" << endl;
    return NIL;
}

int main()
{
    int i, n, r, el;
    cin >> n;
    vector<Node> nodes(n);
    vector<int> out;
    for (i = 0; i < n; i++) {
        cin >> el;
        if (i == 0) r = el - 1;
        pre.push_back(el - 1);
    }
    for (i = 0; i < n; i++) {
        cin >> el;
        ino.push_back(el - 1);
    }

    crt(nodes, ino.begin(), ino.end(), pre.begin());
    postorder(nodes, out, r);
    itr_print(out);
    return 0;
}
