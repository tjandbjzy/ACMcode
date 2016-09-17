def Sqrt(x, k):
    res, eps = 1, 1 / pow(10, -k)
    while abs(res * res - eps) > eps:
        res = (res + x / res) / 2.0
    return res

a = (int)(input())
b = (int)(input())
ans = Sqrt(a, b)
print(round(ans, b))
