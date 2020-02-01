M = int(input())
v = 1
for i in range(128):
    v *= 2
print(v % M)