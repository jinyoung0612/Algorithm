# https://school.programmers.co.kr/learn/courses/30/lessons/181878
def solution(myString, pat):
    myString = myString.lower()
    pat = pat.lower()
    
    while len(myString) >= len(pat):
        if myString[0:len(pat)] == pat:
            return 1
        myString = myString[1:]
    
    return 0