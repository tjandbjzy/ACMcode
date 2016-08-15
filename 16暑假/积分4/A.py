def f():
    a = int(input())
    return a

b = (f(), f(), f());

flag = False
for i in range(0, 3):
    for j in range(0, 3):
        for k in range(0, 3):
            if b[i] == b[j] + b[k]:
                flag = True

if flag:
    print("YES")
else:
    print("NO")
