import sys

class BIT:
    def __init__(self, n):
        self.n = n
        self.n2 = 1
        self.bit = [0] * (n+1)
        # while self.n2 * 2 <= n:
        #     self.n2 *= 2
    
    def sum(self, x):
        res = 0
        i = x
        while i > 0:
            res += self.bit[i]
            i -= (i & -i)
        return res

    def sum2(self, lv, rv):
        return self.sum(rv-1) - self.sum(lv-1)

    def add(self, x, v):
        if x == 0:
            return
        i = x
        while i <= self.n:
            self.bit[i] += v
            i += (i & -i)

input = sys.stdin.readline
N = int(input())
A = [int(x) for x in input().split()]
bit = BIT(N+1)
ans = 0
for a in A:
    ans += bit.sum(a)
    bit.add(a, 1)
ans = N*(N-1)//2 - ans
print(ans)
