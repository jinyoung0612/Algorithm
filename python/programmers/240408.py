# n의 배수
# https://school.programmers.co.kr/learn/courses/30/lessons/181937
def solution(num, n):
    answer = 1 if num % n == 0 else 0
    return answer

# 홀짝에 따라 다른 값 반환하기
# https://school.programmers.co.kr/learn/courses/30/lessons/181935
def solution(n):
    answer = 0
    if n % 2 == 0:
        while n > 0:
            answer += n*n
            n-=2
    else:
        while n > 0:
            answer += n
            n-=2
        
    return answer

def solution(n):
    answer = 0
    if n % 2 == 0:
        for i in range(2,n+1,2):
            answer += i*i
    else:
        for i in range(1,n+1,2):
            answer += i
        
    return answer

# 조건 문자열
# https://school.programmers.co.kr/learn/courses/30/lessons/181934
def solution(ineq, eq, n, m):
    if ineq == ">":
        if eq == "=":
            return int(n >= m)
        elif eq == "!":
            return int(n > m)
    elif ineq =="<":
        if eq == "=":
            return int(n <= m)
        elif eq == "!":
            return int(n < m)
        
# flag에 따라 다른 값 반환하기
# https://school.programmers.co.kr/learn/courses/30/lessons/181933
def solution(a, b, flag):
    return a + b if flag else a - b


