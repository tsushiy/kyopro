n = int(input())
h = list(map(int, input().split()))
flag = True
for i in range(n-1, 0, -1):
  if h[i]<h[i-1]:
    h[i-1] -= 1
for i in range(1, n):
  if h[i]<h[i-1]:
    flag = False
if flag:
  print("Yes")
else:
  print("No")