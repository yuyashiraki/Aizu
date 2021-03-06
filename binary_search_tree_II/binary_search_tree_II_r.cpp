#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <utility>
#include <queue>
#include <stack>
#include <string>
#include <climits>
using namespace std;

#define MAX_N 500001

class Node
{
    public:
    int k, l = MAX_N, r = MAX_N;
};
vector<Node> nodes(MAX_N);
int p, n, r = 0;

void insert(int k)
{
    nodes[p].k = k;
    if (0 == p) { p++; return; }
    int *cur = &r;
    while (MAX_N != *cur) {
        if (k < nodes[*cur].k) cur = &nodes[*cur].l;
        else cur = &nodes[*cur].r;
    }
    *cur = p++;
}

int find(int cur, int k)
{
    if (cur == MAX_N) return 0;
    if (nodes[cur].k == k) return 1;
    return k < nodes[cur].k ? find(nodes[cur].l, k) : find(nodes[cur].r, k);
}

void preorder(int cur)
{
    if (MAX_N == cur) return;
    cout << " " << nodes[cur].k;
    preorder(nodes[cur].l);
    preorder(nodes[cur].r);
}

void inorder(int cur)
{
    if (MAX_N == cur) return;
    inorder(nodes[cur].l);
    cout << " " << nodes[cur].k;
    inorder(nodes[cur].r);
}

int main()
{
    cin >> n;
    p = 0;
    while (n--) {
        string command;
        int k;
        cin >> command;
        if (command == "insert") {
            cin >> k;
            insert(k);
        } else if (command == "find") {
            cin >> k;
            cout << (find (r, k) ? "yes" : "no") << endl;
        } else {
            inorder(r);
            cout << endl;
            preorder(r);
            cout << endl;
        }
    }
    return 0;
}
