n = int(input())
x = []
dir = []
for _ in range(n):
    xi, di = input().split()
    x.append(int(xi))
    dir.append(di)

# Please write your code here.
intervals = {} # (-1)-0: "-1", 0-1: "0", 1-2: "1", ...
cur = 0
for xi, di in zip(x, dir):
    dv = 1 if di == 'R' else -1
    for _ in range(xi):
        idx_to_add = cur if dv > 0 else cur-1
        if idx_to_add in intervals:
            intervals[idx_to_add] += 1
        else:
            intervals[idx_to_add] = 1
        cur += dv
cnts = list(intervals.values())
print(sum(1 for x in cnts if x > 1))
