T = int(input())



# 테스트 케이스의 수 만큼 반복
for i in range(T):
    # 중심좌표받기
    x1,y1,x2,y2 = map(int,input().split())
    # 진입/이탈 수
    count = 0
    # 행성계의 수 
    n = int(input())
    for j in range(n):
        
        cx, cy, r = map(int,input().split())
        if ((x1-cx)**2 + (y1-cy)**2 < r**2) and ((x2-cx)**2 + (y2-cy)**2 > r**2):
            count+=1 
        elif ((x1-cx)**2 + (y1-cy)**2 > r**2) and ((x2-cx)**2 + (y2-cy)**2 < r**2):
            count+=1
    print(count)

