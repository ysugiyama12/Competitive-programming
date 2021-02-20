from decimal import *
import math
X,Y,R = input().split()
xd = Decimal(X)
yd = Decimal(Y)
rd = Decimal(R)

lv = int(round(math.floor(xd-rd)))
rv = int(round(math.ceil(xd+rd)))
ans = 0
for i in range(lv, rv+1):
    x = Decimal(str(i))

    val = Decimal(rd * rd - (x - xd) * (x - xd))
    if val < 0.0:
        continue;
    val = Decimal(rd * rd - (x - xd) * (x - xd)).sqrt()
    uv = val + yd
    dv = -val + yd
    ul = int(round(math.floor(uv)))
    dl = int(round(math.ceil(dv)))
    ans += ul - dl + 1
print(ans)
