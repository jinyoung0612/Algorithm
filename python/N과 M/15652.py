def combination(start, depth):
  if depth == M:
    for i in range(0, M):
      print(res[i], end=' ')
    print()
    return
  
  for i in range(start, N+1):
    res[depth] = i
    combination(i, depth+1)

N, M =map(int, input().split())
visited = [False] * (N+1)
res = [0] * (N+1)

combination(1, 0)