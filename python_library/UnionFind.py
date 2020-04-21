import sys
read = sys.stdin.buffer.read
readline = sys.stdin.buffer.readline
readlines = sys.stdin.buffer.readlines

class UnionFind:

    def __init__(self, n):
        self.n = n
        self.parent = [0] * (n+1)
        self.num = [1] * (n+1)
        self.diff_weight = [0] * (n+1)
        for i in range(n):
            self.parent[i] = i
    
    def root(self, x):
        if x == self.parent[x]:
            return x
        else:
            r = self.root(self.parent[x])
            self.diff_weight[r] += self.diff_weight[self.parent[x]]
            self.parent[x] = r
            return r
    
    def unite(self, a, b, w = 0):
        w += self.weight(a) - self.weight(b)
        a = self.root(a)
        b = self.root(b)
        if a == b:
            return
        self.parent[b] = a
        sum_v = self.num[a] + self.num[b]
        self.num[a] = sum_v
        self.num[b] = sum_v
        self.diff_weight[b] = w
        
    def same(self, a, b):
        return (self.root(a) == self.root(b))
    
    def sz(self, x):
        return self.num[self.root(x)]
    
    def weight(self, x):
        self.root(x)
        return self.diff_weight[x]

    def diff(self, a, b):
        return self.weight(b) - self.weight(a)


if __name__ == "__main__":
    N,Q = map(int,readline().split())
    uf = UnionFind(N+1)
    for i in range(Q):
        P, A, B = map(int,readline().split())
        if P == 0:
            uf.unite(A, B)
        else:
            if uf.same(A,B):
                print("Yes")
            else:
                print("No")