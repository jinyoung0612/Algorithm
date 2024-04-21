# 수열과 구간 쿼리 4
# https://school.programmers.co.kr/learn/courses/30/lessons/181922
def solution(arr, queries):
    answer = []
    for s, e, k in queries:
        for i in range(s, e+1):
            if i % k == 0: 
                arr[i] +=1
    return arr


# 배열 만들기 2
# https://school.programmers.co.kr/learn/courses/30/lessons/181921
def solution(l, r):
    answer = []
    temp = [0, 5, 50, 55, 500, 505, 550, 555, 5000, 5005, 5050, 5055, 5500, 5505, 5550, 5555, 50000, 50005, 50050, 50055, 50500, 50505, 50550, 50555, 55000,55005, 55050, 55055, 55500, 55505, 55550, 55555, 500000, 500005, 500050, 500055, 500500, 500505, 500550, 500555, 505000, 505005, 505050, 505055, 505500, 505505, 505550, 505555, 550000, 550005, 550050, 550055, 550500, 550505, 550550, 550555,555000, 555005, 555050, 555055, 555500, 555505, 555550, 555555]
    for num in temp:
        if num >=l and num <= r:
            answer.append(num)            
    return [-1] if len(answer) == 0 else answer

def solution(l, r):
    answer = []
    for num in range(l,r+1):
        if not set(str(num)) - set(["0","5"]):
            answer.append(num)
    return [-1] if len(answer) == 0 else answer

# 카운트 업
# https://school.programmers.co.kr/learn/courses/30/lessons/181920
def solution(start_num, end_num):
    answer = []
    for i in range(start_num, end_num+1):
        answer.append(i)
    return answer


# 콜라츠 수열 만들기
# https://school.programmers.co.kr/learn/courses/30/lessons/181919
def solution(n):
    answer = []
    while True:
        answer.append(n)
        if n == 1: break
        if n % 2 == 0:
            n = n/2
        else:
            n = 3*n + 1
    return answer 

# 배열 만들기4
# https://school.programmers.co.kr/learn/courses/30/lessons/181918
def solution(arr):
    stk = []
    i = 0
    
    while i < len(arr):
        if len(stk) == 0:
            stk.append(arr[i])
            i += 1
        else:
            if stk[-1] < arr[i]:
                stk.append(arr[i])
                i += 1
            else:
                stk.pop(-1)
    return stk