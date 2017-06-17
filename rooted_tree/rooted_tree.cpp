#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

#define MAX_N 100000
#define MAX_D 20

class Node
{
    public:
    int parent = -1, depth = MAX_D + 1;
    vector<int> childs;
};

void set_depth(Node nodes[], Node *cur, int depth)
{
    cur->depth = depth++;
    for (auto itr = cur->childs.begin(); itr != cur->childs.end(); ++itr) {
        set_depth(nodes, nodes + *itr, depth);
    }
}

void print_nodes(Node nodes[], int n)
{
    int cnt = 0;
    for (int i = 0; cnt < n; i++) {
        if (nodes[i].depth == MAX_D + 1) continue;
        cout << "node " << i << ": "
        << "parent = " << nodes[i].parent << ", "
        << "depth = " << nodes[i].depth << ", "
        << (nodes[i].parent == -1 ? "root" : nodes[i].childs.size() == 0 ? "leaf" : "internal node") << ", ";
        cout << "[";
        for (auto itr = nodes[i].childs.begin(); itr != nodes[i].childs.end(); itr++) {
            if (itr != nodes[i].childs.begin()) cout << ", ";
            cout << *itr;
        }
        cout << "]" << endl;
        cnt++;
    }
}

int main()
{
    int n, id, k;
    Node nodes[MAX_N + 1], *root;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> id >> k;
        int c[k];
        for (int j = 0; j < k; j++) {
            cin >> c[j];
        }
        for (int *p = c; p != c + k; p++) {
            nodes[id].childs.push_back(*p);
            nodes[*p].parent = id;
        }
    }
    root = nodes + id;
    while (root->parent != -1) {
        root = nodes + root->parent;
    }
    set_depth(nodes, root, 0);
    print_nodes(nodes, n);
    return 0;
}
