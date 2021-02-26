import os, sys

with open("data.txt", "r") as fp:
    data = fp.readlines()
    res = []
    res2 = []
    for i, d in enumerate(data):
        ds = d.split(" ")
        val = int(ds[1].replace("\n", ""))
        if val == 1:
            res2.append(str(i))
            print(i)
            
        res.append(str(val % int(1e9+7)))
    res = ",".join(res)
    res2 = ",".join(res2)
    with open("res.txt", "w") as f:
        f.write(res)
    with open("res2.txt", "w") as f:
        f.write(res2)


