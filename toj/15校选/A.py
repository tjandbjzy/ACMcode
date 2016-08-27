def dp(n, m):
    if n == 0 :
        return 0
    if m == 1:
        return n
    mn = 1 << 30
    for i in range(1, n + 1):
        mx = max(dp(i - 1, m - 1), dp(n - i, m))
        mn = min(mn, mx)
    return mn + 1
for i in range(1, 30):
    print(dp(i, 2))
