a = (eval(input()), eval(input()), eval(input()))
f = True 
for i in range(0, 3):
    for j in range(0, 3):
        for k in range(0, 3):
            if a[i] == a[j] + a[k]:
                f = False 
if f:
    print("NO")
else:
    print("YES")
