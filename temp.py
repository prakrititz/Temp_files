MOD = 998244353

def mod_inverse(a, m):
    def extended_gcd(a, b):
        if a == 0:
            return b, 0, 1
        gcd, x1, y1 = extended_gcd(b % a, a)
        x = y1 - (b // a) * x1
        y = x1
        return gcd, x, y
    
    _, x, _ = extended_gcd(a, m)
    return (x % m + m) % m

# Precompute factorials and inverses
MAX_N = 500005
fact = [1] * (MAX_N + 1)
inv_fact = [1] * (MAX_N + 1)
for i in range(1, MAX_N + 1):
    fact[i] = fact[i-1] * i % MOD
inv_fact[MAX_N] = mod_inverse(fact[MAX_N], MOD)
for i in range(MAX_N - 1, -1, -1):
    inv_fact[i] = inv_fact[i+1] * (i + 1) % MOD

def solve():
    c = list(map(int, input().split()))
    n = sum(c)
    if n == 0:
        return 1 if n == 0 else 0
    
    odd_positions = (n + 1) // 2
    even_positions = n // 2
    
    # DP to assign letters to odd positions
    dp = [0] * (n + 1)
    dp[0] = 1  # Base case: sum 0 with no letters
    for freq in c:
        if freq == 0:
            continue
        new_dp = [0] * (n + 1)
        for j in range(n + 1):
            if dp[j] == 0:
                continue
            # Assign to even positions (sum unchanged)
            new_dp[j] = (new_dp[j] + dp[j]) % MOD
            # Assign to odd positions (add freq to sum)
            if j + freq <= n:
                new_dp[j + freq] = (new_dp[j + freq] + dp[j]) % MOD
        dp = new_dp
    
    if odd_positions > n or dp[odd_positions] == 0:
        return 0
    
    # For each valid DP result
    result = dp[odd_positions]
    
    # Compute total arrangements
    odd_fact = fact[odd_positions]
    even_fact = fact[even_positions]
    denom = 1
    for freq in c:
        if freq > 0:
            denom = denom * inv_fact[freq] % MOD
    
    result = result * odd_fact % MOD * even_fact % MOD * denom % MOD
    return result

# Process multiple test cases
t = int(input())
for _ in range(t):
    print(solve())