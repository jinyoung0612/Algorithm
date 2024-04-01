# https://school.programmers.co.kr/learn/courses/30/lessons/181936
def solution(number, n, m):
    if number % n or number % m:
        return 0
    return 1