n = int(input())
a = list(map(int, input().split()))
s = [0]*(n+1)
for i in range(n):
  s[i+1] += s[i] + a[i]
from collections import Counter
c = Counter(s)
ans = 0
for k, v in c.items():
  ans += v*(v-1)//2
print(ans)