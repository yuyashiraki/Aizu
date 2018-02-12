#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <climits>
#include <cassert>
#include <algorithm>
#include <vector>
#include <utility>
#include <queue>
#include <stack>
#include <map>
#include <string>
using namespace std;

void brute_force(string T, string P)
{
    const char* Tc = T.c_str();
    const char* Pc = P.c_str();
    int i, j;
    for (i = 0; i < (int)T.length() - (int)P.length() + 1; i++) {
        for (j = 0; j < P.length(); j++) {
            if (Tc[i + j] != Pc[j]) break;
            if (j == P.length() - 1) cout << i << endl;
        }
    }
}

int main()
{
    string T, P;
    cin >> T >> P;
    brute_force(T, P);
    return 0;
}
