# 배열 만들기 5
# https://school.programmers.co.kr/learn/courses/30/lessons/181912
def solution(intStrs, k, s, l):
    answer = []
    for Str in intStrs:
        temp = int(Str[s:s+l])
        if temp > k:
            answer.append(temp)
    return answer

# 부분 문자열 이어 붙여 문자열 만들기
# https://school.programmers.co.kr/learn/courses/30/lessons/181911
def solution(my_strings, parts):
    answer = ''
    for idx, st in enumerate(my_strings):
        answer += st[parts[idx][0]:parts[idx][1]+1]
    return answer

# 문자열 뒤의 n글자
# https://school.programmers.co.kr/learn/courses/30/lessons/181910
def solution(my_string, n):
    answer = my_string[-n:]
    return answer

# 접미사 배열
# https://school.programmers.co.kr/learn/courses/30/lessons/181909
def solution(my_string):
    answer = []
    temp = ''
    for st in reversed(my_string):
        temp = st + temp
        answer.append(temp)
    answer.sort()
    return answer

# 접미사인지 확인하기
# https://school.programmers.co.kr/learn/courses/30/lessons/181909
def solution(my_string, is_suffix):
    suffix = []
    for idx in range(0, len(my_string)):
        suffix.append(my_string[idx:])
    return 1 if is_suffix in suffix else 0