# 수 조작하기 1
# https://school.programmers.co.kr/learn/courses/30/lessons/181926
def solution(n, control):
    for ch in control:
        if ch == 'w':
            n += 1
        elif ch == 's':
            n -= 1
        elif ch == 'd':
            n += 10
        elif ch == 'a':
            n -= 10
    return n

def solution(n, control):        
    answer = 0
    key = dict(zip(["w", "s", "d", "a"], [1, -1, 10, -10]))
    answer = n + sum(key[ch] for ch in control)
    return answer

# 수 조작하기 2
# https://school.programmers.co.kr/learn/courses/30/lessons/181925
def solution(numLog):
    answer = ''
    key = dict(zip([1, -1, 10, -10], ["w", "s", "d", "a"]))
    
    for idx in range(0, len(numLog)-1):
        num = numLog[idx+1] - numLog[idx] 
        answer += key[num]
        
    return answer

# 수열과 구간 쿼리 3
# https://school.programmers.co.kr/learn/courses/30/lessons/181924
def solution(arr, queries):
    for q in queries:
        temp = arr[q[0]]
        arr[q[0]] = arr[q[1]]
        arr[q[1]] =temp
    
    return arr

def solution(arr, queries):
    for a, b in queries:
        arr[a], arr[b] = arr[b], arr[a]
    return arr

# 수열과 구간 쿼리 2
# https://school.programmers.co.kr/learn/courses/30/lessons/181923
def solution(arr, queries):
    answer = []
    for s, e, k in queries:
        temp = []
        for i in range(s, e+1):
            if arr[i] > k:
                temp.append(arr[i])
        if len(temp) ==0:
            answer.append(-1)
        else:
            answer.append(min(temp))
    return answer
