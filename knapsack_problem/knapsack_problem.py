import sys

line = sys.stdin.readline().split(" ")
N = int(line[0])
W = int(line[1])
v = [0] * (N + 1)
w = [0] * (N + 1)
for i in range(N):
    line = sys.stdin.readline().split(" ")
    v[i + 1] = int(line[0])
    w[i + 1] = int(line[1])

"""
Underlying idea:
    C[N + 1][W + 1] = max total value to be in size w knapsack considering 0th ~ ith items
    C[i][w] = max(C[i - 1][w - w[i]] + v[i], C[i - 1][w])
"""

C = [[0 for i in range(W + 1)] for j in range(N + 1)]
def knapsack():
    for i in range(1, N + 1):
        for m in range(1, W + 1):
            if w[i] <= m:
                C[i][m] = max(C[i - 1][m - w[i]] + v[i], C[i - 1][m])
            else:
                C[i][m] = C[i - 1][m]
    return C[N][W]
print knapsack()
