# 코드 처리하기
# https://school.programmers.co.kr/learn/courses/30/lessons/181932
def solution(code):
    ret = ''
    mode = "0"
    for idx, c in enumerate(code):
        if mode == "0":
            if c != "1" and idx % 2 == 0:
                ret += c
            elif c == "1":
                mode = "1"
        elif mode == "1":
            if c != "1" and idx % 2 != 0:
                ret += c
            elif c == "1":
                mode = "0"
    return 'EMPTY' if ret == '' else ret

# 등차수열의 특정한 항만 더하기
# https://school.programmers.co.kr/learn/courses/30/lessons/181931
def solution(a, d, included):
    answer = 0
    temp = a
    
    for inc in included:
        if inc == True:
            answer += temp
        temp += d
    
    return answer

# 주사위 게임 2
# https://school.programmers.co.kr/learn/courses/30/lessons/181930
def solution(a, b, c):
    if a == b and b == c:
        return (a + b + c) * (a**2 + b**2 + c**2) * (a**3 + b**3 + c**3)
    elif a != b and b != c and a != c:
        return a + b + c
    else:
        return (a + b + c) * (a**2 + b**2 + c**2)

# 원소들의 곱과 합
# https://school.programmers.co.kr/learn/courses/30/lessons/181929
def solution(num_list):
    gob = 1
    hab = 0
    for num in num_list:
        gob *= num
        hab += num
    return 1 if gob < hab**2 else 0

# 이어 붙인 수
# https://school.programmers.co.kr/learn/courses/30/lessons/181928
def solution(num_list):
    even = ''
    odd = ''
    for num in num_list:
        if num %2 == 0:
            even += str(num)
        else:
            odd += str(num)
    return int(even) + int (odd)