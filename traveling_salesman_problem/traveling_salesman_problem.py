import sys
MAXINT = 15001

line = sys.stdin.readline().split(" ")
N = int(line[0])
M = int(line[1])
d = [[MAXINT for i in range(N)] for j in range(N)]
dp = [[-1 for i in range(N)] for j in range(1 << N)]

def rec(S, v):
    if dp[S][v] >= 0:
        return dp[S][v]
    if (S == ((1 << N) - 1)) and (v == 0):
        dp[S][v] = 0
        return dp[S][v]
    tmp = MAXINT
    for u in range(N):
        if not ((S >> u) & 1):
            tmp = min(tmp, rec(S | (1 << u), u) + d[v][u])
    dp[S][v] = tmp
    return dp[S][v]


for x in range(M):
    line = [int(n) for n in sys.stdin.readline().split(" ")]
    d[line[0]][line[1]] = line[2]
print rec(0, 0)
