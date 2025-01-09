def sieve_of_eratosthenes(limit):
    """
    Generate all prime numbers up to a given limit using Sieve of Eratosthenes.
    Returns a list of prime numbers.
    """
    # Create a boolean array of "prime[0..limit]" and initialize
    # all entries as true. A value in prime[i] will
    # finally be false if i is Not a prime, else true.
    sieve = [True] * (limit + 1)
    sieve[0] = sieve[1] = False

    # Use sieve[i] = True if i is prime
    # Start with 2, the smallest prime number
    for i in range(2, int(limit ** 0.5) + 1):
        if sieve[i]:
            # Update all multiples of i starting from i*i
            # They cannot be prime numbers
            for j in range(i * i, limit + 1, i):
                sieve[j] = False

    # Create the list of all prime numbers
    primes = [i for i in range(2, limit + 1) if sieve[i]]
    return primes

# Example usage for 10^6
primes = sieve_of_eratosthenes(10**6)
print(f"Number of primes found: {len(primes)}")
print(f"First few primes: {primes[:10]}")
print(f"Last few primes: {primes[-10:]}")