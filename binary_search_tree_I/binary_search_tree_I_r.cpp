#include <iostream>
#include <vector>
#include <string>
#include <stdlib.h>
using namespace std;

#define NIL 2000000001
#define MAX 500001

class Node
{ 
    public:
    int key, l = MAX, r = MAX;
};
vector<Node> nodes(MAX);
int p = 0, root = 0;

void insert(int key)
{
    nodes.at(p).key = key;
    if (p == 0) {
        p++;
        return;
    }
    int *cur = &root;
    while (MAX != *cur) {
        if (nodes.at(*cur).key > key) cur = &nodes.at(*cur).l;
        else cur = &nodes.at(*cur).r;
    }
    *cur = p++;
}

void inorder(int cur)
{
    if (MAX == cur) return;
    inorder(nodes.at(cur).l);
    cout << " " << nodes.at(cur).key;
    inorder(nodes.at(cur).r);
}

void preorder(int cur)
{
    if (MAX == cur) return;
    cout << " " << nodes.at(cur).key;
    preorder(nodes.at(cur).l);
    preorder(nodes.at(cur).r);
}

int main()
{
    int n, key;
    string command;
    cin >> n;
    while (n--) {
        cin >> command;
        if ("insert" == command) {
            cin >> key;
            insert(key);
        }
        if ("print" == command) {
            inorder(0);
            cout << endl;
            preorder(0);
//            for (int i = 0; i < p; i++) {
//                cout << " " << nodes.at(i).key;
//            }
            cout << endl;
        }
    }
    return 0;
}
