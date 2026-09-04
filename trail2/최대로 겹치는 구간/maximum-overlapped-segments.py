n = int(input())
segments = [tuple(map(int, input().split())) for _ in range(n)]

# Please write your code here.
offset = 100
intervals = [0] * 200

for s, e in segments:
    for i in range(s, e):
        intervals[i - offset] += 1
print(max(intervals))