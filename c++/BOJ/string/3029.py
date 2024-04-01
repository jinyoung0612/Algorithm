h1,m1,s1=map(int,input().split(':'))
h2,m2,s2=map(int,input().split(':'))
ans1=ans2=ans3=0

if s2>=s1:
    ans3=s2-s1
else:
    ans3=60+s2-s1
    m2-=1

if m2>=m1:
    ans2=m2-m1
else:
    ans2=60+m2-m1
    h2-=1

if h2>=h1:
    ans1=h2-h1
else:
    ans1=24+h2-h1

if ans1==0 and ans2==0 and ans3==0:
    ans1=24

print("%02d:%02d:%02d" %(ans1,ans2,ans3))