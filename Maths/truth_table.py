n = 5

def condition(i):
    b = [i & (1 << bit) for bit in range(n-1, -1, -1)]

    return (not (b[0] or b[1])) and (not (b[2] or b[3] or b[4])) or not (b[0] or b[1])

for i in range(2**n):
    for bit in range(n-1, -1, -1):
        print(f"|{"⊤" if i & (1 << bit) else "⊥"}", end = "")
    print(f"|{"⊤" if condition(i) else "⊥"}|")