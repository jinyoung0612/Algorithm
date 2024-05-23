def permutation(depth):
  if depth == M:
    for i in range(0, M):
      print(res[i], end=' ')
    print()
    return

  for i in range(1, N+1):
    res[depth] = i
    permutation(depth+1)

N, M = map(int, input().split())
res = [0] * (N+1)
permutation(0)