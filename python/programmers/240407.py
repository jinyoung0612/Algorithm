# 문자열 섞기
# https://school.programmers.co.kr/learn/courses/30/lessons/181942
def solution(str1, str2):
    answer = ''
    for idx, s1 in enumerate(str1):
        answer+=s1
        answer+=str2[idx]
    return answer

def solution(str1, str2):
    answer = ''
    for i in range(0, len(str1)):
        answer += str1[i] + str2[i]
    return answer

# 문자 리스트를 문자열로 변환하기
# https://school.programmers.co.kr/learn/courses/30/lessons/181941
def solution(arr):
    answer = ''
    for a in arr:
        answer += a
    return answer

def solution(arr):
    return ''.join(arr)

# 문자열 곱하기
# https://school.programmers.co.kr/learn/courses/30/lessons/181940
def solution(my_string, k):
    return my_string * k

# 두 수의 연산값 비교하기
# https://school.programmers.co.kr/learn/courses/30/lessons/181938
def solution(a, b):
    answer = max(int(str(a)+str(b)), 2*a*b)
    return answer