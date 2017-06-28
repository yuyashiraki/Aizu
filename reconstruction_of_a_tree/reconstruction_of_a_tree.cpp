#include <iostream>
#include <vector>
using namespace std;

#define NIL -1

class Node
{
  public:
  int p = NIL, l = NIL, r = NIL, ino;
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
        cout << " ";
        cout << *itr + 1;
    }
    cout << endl;
}

int find(vector<int>& ino, int cur)
{
    for (int i = 1; i <= ino.size(); i++) {
        if (ino.at(i) == cur) return i;
    }
    return NIL;
}

void create_nodes(vector<Node>& nodes, vector<int>& pre)
{
    for (int i = 2; i < nodes.size(); i++) {
        int bfr = i - 1;
        for (int cur = bfr; cur != NIL; cur = nodes.at(pre.at(cur)).p) {
//            cout << "i " << i << " cur " << cur << " bfr " << bfr << endl;
            if (nodes.at(pre.at(i)).ino < nodes.at(pre.at(bfr)).ino) {
                if (cur == bfr) {
                    nodes.at(pre.at(bfr)).l = pre.at(i);
                }
                else
                    nodes.at(pre.at(bfr)).r = pre.at(i);
                nodes.at(pre.at(i)).p = pre.at(bfr);
                break;
            }
            bfr = cur;
        }
    }
}

int main()
{
    int n, r, el;
    cin >> n;
    vector<int> out, pre(n + 1);
    out.push_back(NIL);
    vector<Node> nodes(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> el;
        if (i == 1) r = el;
        pre.at(i) = el;
    }
    for (int i = 1; i <= n; i++) {
        cin >> el;
        nodes.at(el).ino = i;
    }
    create_nodes(nodes, pre);
    int i = 1;
//    for (auto itr = nodes.begin(); itr != nodes.end(); itr++) {
//        cout << i++ << " " << itr->p << " " << itr->l << " " << itr->r << endl; 
//    }
    postorder(nodes, out, r);
    itr_print(out);
    return 0;
}
