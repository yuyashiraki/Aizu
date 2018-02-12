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

void bm(string T, string P)
{
    map<char, int> mp;
    int plen = P.length(), tlen = T.length();
    const char *Pchar = P.c_str();
    const char *Tchar = T.c_str();
    for (int i = 0; i < plen - 1; i++) {
        mp[Pchar[i]] = plen - 1 - i;
    }
    for (int i = plen - 1; i < tlen; i++) {
        if (Pchar[plen - 1] == Tchar[i]) {
            bool found = 1;
            for (int j = 0; j < plen - 1; j++) {
                if (Pchar[j] == Tchar[i - plen + 1 + j])
                    continue;
                else
                    found = 0;
                    break;
            }
            if (found)
                cout << i - plen + 1<< endl;
        }
        if (mp[Tchar[i]]) {
            i += mp[Tchar[i]] - 1;
        } else {
            i += plen - 1;
        }
    }
}

void kmp(string T, string P)
{
}

int main()
{
    string T, P;
    cin >> T >> P;
    bm(T, P);
    return 0;
}
