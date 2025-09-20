import sys

input = sys.stdin.read
data = input().split()

t = int(data[0])
index = 1

for _ in range(t):
    k = int(data[index])
    x = int(data[index + 1])
    index += 2
    
    S = 1 << (k + 1)
    half = 1 << k
    
    c = x
    seq = []
    
    while c != half:
        if c < half:
            seq.append(1)
            c = 2 * c
        else:
            seq.append(2)
            c = 2 * c - S
    
    seq = seq[::-1]
    n = len(seq)
    
    print(n)
    if n > 0:
        print(' '.join(map(str, seq)))