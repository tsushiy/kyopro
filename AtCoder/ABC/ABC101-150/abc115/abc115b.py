n = int(input())
p = [int(input()) for i in range(n)]
p.sort()
print(sum(p[:-1])+p[-1]//2)