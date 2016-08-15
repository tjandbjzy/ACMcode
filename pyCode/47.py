def f(x):
    b = 1
    for i in range(1 , x + 1):
        b = b * i
    return b

a = input()
ans = 0
for x in range(1 , a + 1):
    ans = ans + f(x)

print(ans)
    
