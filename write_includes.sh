#!/bin/sh

if [ $# -ne 1 ]; then
    exit 1
fi

cat > $(dirname $0)/$1 <<EOF
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

EOF

exit 0
