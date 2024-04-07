# 덧셈식 출력하기
# https://school.programmers.co.kr/learn/courses/30/lessons/181947
# 1
a, b = map(int, input().strip().split(' '))
print('{0} + {1} = {2}'.format(a, b, a + b))

# 2
a, b = map(int, input().strip().split(' '))
print(f"{a} + {b} = {a + b}")

# 문자열 붙여서 출력하기
# https://school.programmers.co.kr/learn/courses/30/lessons/181946
str1, str2 = input().strip().split(' ')
print(str1 + str2)

# 문자열 돌리기
# https://school.programmers.co.kr/learn/courses/30/lessons/181945
# 1
str = input()
for s in str:
    print(s)

# 2
str = input()
print('\n'.join(str))

# 홀짝 구분하기
# https://school.programmers.co.kr/learn/courses/30/lessons/181944
# 1
a = int(input())
if a % 2 == 0:
    print(f'{a} is even')
else:
    print(f'{a} is odd')

# 2
a = int(input())
print(f'{a} is even' if a % 2 == 0 else f'{a} is odd')

# 문자열 겹쳐쓰기
# https://school.programmers.co.kr/learn/courses/30/lessons/181943
def solution(my_string, overwrite_string, s):
    answer = my_string[:s] + overwrite_string + my_string[s+len(overwrite_string):]
    return answer



