import sys
readline = sys.stdin.readline


MOD = 1<<32
for N in range(2, 4):
    S = set()
    dp = [0]*(N+2)
    dp[0] = 1
    for br in range(N):
        for i in range(N):
            if i == br:
                dp[i+1] = (dp[i+1]+2*dp[i])%MOD
                dp[i+2] = (dp[i+2]+2*dp[i])%MOD
            else:
                dp[i+1] = (dp[i+1]+dp[i])%MOD
                dp[i+2] = (dp[i+2]+dp[i])%MOD
        S.add(dp[N-1])
    print(N)
    print(S)
    if N != len(S):
        print(N, len(S)) 
                