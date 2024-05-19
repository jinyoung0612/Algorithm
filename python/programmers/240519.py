# 간단한 논리 연산
# https://school.programmers.co.kr/learn/courses/30/lessons/181917
def solution(x1, x2, x3, x4):    
    return (x1 or x2) and (x3 or x4)

# 주사위 게임 3
# https://school.programmers.co.kr/learn/courses/30/lessons/181916
def solution(a, b, c, d):
    answer = 0
    
    temp = set(list([a,b,c,d]))
    arr = [0,0,0,0,0,0,0]
    arr[a] += 1
    arr[b] += 1
    arr[c] += 1
    arr[d] += 1
    
    if max(arr) == 4:
        answer = 1111 * a
    elif max(arr) == 3:
        for idx, num in enumerate(arr):
            if num == 3:
                p = idx
            if num == 1:
                q = idx
        answer = ((10*p+q)**2)
    elif max(arr) == 2 and len(temp) == 2:
        li = []
        for idx, num in enumerate(arr):
            if num == 2:
                li.append(idx)
        answer = (li[0] + li[1]) * abs(li[0]-li[1])
    elif max(arr) == 2 and len(temp)==3:
        li = []
        for idx, num in enumerate(arr):
            if num == 1:
                li.append(idx)
        answer = li[0] * li[1]
    else:
        answer = min(list([a,b,c,d]))
        
    return answer

# 글자 이어 붙여 문자열 만들기
# https://school.programmers.co.kr/learn/courses/30/lessons/181915
def solution(my_string, index_list):
    answer = ''
    for index in index_list:
        answer += my_string[index]
    return answer


# 9로 나눈 나머지
# https://school.programmers.co.kr/learn/courses/30/lessons/181914
def solution(number):
    answer = 0
    for num in number:
        answer += int(num)
    return answer % 9

# 문자열 여러 번 뒤집기
# https://school.programmers.co.kr/learn/courses/30/lessons/181913
def solution(my_string, queries):
    my_string = list(my_string)
    for start, end in queries:
        reverse = ''.join(reversed(my_string[start:end+1]))
        cnt = 0
        for i in range(start, end+1):
            my_string[i] = reverse[cnt]
            cnt += 1
    return ''.join(my_string)

def solution(my_string, queries):
    my_string = list(my_string)   
    for start, end in queries:
        my_string[start:end+1] = my_string[start:end+1][::-1]
    return ''.join(my_string)