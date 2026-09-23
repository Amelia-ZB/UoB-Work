n = 3

def condition(i):
    b = [i & (1 << bit) for bit in range(n-1, -1, -1)]

    return b[0] and b[1] and b[2] 

for i in range(2**n):
    for bit in range(n-1, -1, -1):
        print(f"|{"⊤" if i & (1 << bit) else "⊥"}", end = "")
    print(f"|{"⊤" if condition(i) else "⊥"}|")