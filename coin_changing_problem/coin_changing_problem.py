import sys

line = sys.stdin.readline().split(' ')
n    = int(line[0])
m    = int(line[1])
C    = [int(c) for c in sys.stdin.readline().split(' ')]
""" 
Underlying idea:
    T[i][j] = minimum num of coins needed to pay j using 0th ~ ith coins
    T[i][j] = min(T[i - 1][j], T[i][j - C[i]] + 1)
"""

T = [sys.maxint] * (n + 1)
def getTheNumberOfCoin():
    T[0] = 0
    for c in C:
        for j in range(c, n + 1):
            T[j] = min(T[j], T[j - c] + 1)
    return T[n]

print getTheNumberOfCoin()
