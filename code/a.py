t = int(input())
mod = 1e9 + 7

for i in range (t):
    a, b, c, d = map(int, input().split())
    
    x = (a * b) % mod
    y = (c * d) % mod
    
    res = (x - y + mod) % mod
    
    print(int(res))