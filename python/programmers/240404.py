# https://school.programmers.co.kr/learn/courses/30/lessons/181927
def solution(num_list):
    if num_list[-1] > num_list[-2]:
        num_list.append(num_list[-1]-num_list[-2])
    else:
        num_list.append(num_list[-1]*2)
    return num_list

# https://school.programmers.co.kr/learn/courses/30/lessons/181951
a, b = map(int, input().strip().split(' '))
print('a = ' + str(a))
print('b = ' + str(b))

# https://school.programmers.co.kr/learn/courses/30/lessons/181950
str, n = input().strip().split(' ')
n = int(n)
print(str*n)

# https://school.programmers.co.kr/learn/courses/30/lessons/181949
# 1
str = input()
answer = ''

for s in str:
    if s in 'ABCDEFGHIJKLMNOPQRSTUVWXYZ':
        answer += s.lower()
    else:
        answer += s.upper()
        
print(answer)

# 2
str = input()
print(str.swapcase())

# 3
str = input()
answer = ''

for s in str:
    if s.isupper():
        answer += s.lower()
    else:
        answer += s.upper()
        
print(answer)

# https://school.programmers.co.kr/learn/courses/30/lessons/181948
# 1
print('!@#$%^&*(\\\'\"<>?:;')
# 2
print(r'!@#$%^&*(\'"<>?:;')