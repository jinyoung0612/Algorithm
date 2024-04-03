# https://school.programmers.co.kr/learn/courses/30/lessons/12906?language=python3
# 시간초과에 주의할 것
# pop과 append를 같이쓰면 시간초과 발생

def solution(arr):
    answer = []
    
    for a in arr:
        if len(answer) == 0 or answer[-1] != a:
            answer.append(a)
            
    return answer

def solution(arr):
    answer = []
    
    for a in arr:
        if answer[-1:] != [a]:
            answer.append(a)
            
    return answer