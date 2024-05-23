def permutation(depth):
  if depth == m:
    for i in range(0, m):
      print(res[i] , end = ' ')
    print()
  
  for i in range(0, n):
    if not visited[i]:
      visited[i] = True
      res[depth] = i + 1
      permutation(depth+1)
      visited[i] = False;

n, m = map(int, input().split())
s = []
res = [0] * (n+1)
for i in range(1,n+1):
  s.append(i)
visited = [False] * (n+1)

permutation(0)

