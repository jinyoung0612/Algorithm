# https://school.programmers.co.kr/learn/courses/30/lessons/181939
def solution(a, b):
    ab = int(str(a)+str(b))
    ba = int(str(b)+str(a))
    return max(ab, ba)
