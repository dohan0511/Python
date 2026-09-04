n = int(input())
segments = [tuple(map(int, input().split())) for _ in range(n)]

# Please write your code here.
dots = [0] * 100
for x1, x2 in segments:
    for i in range(x1-1, x2):
        dots[i] += 1
print(max(dots))