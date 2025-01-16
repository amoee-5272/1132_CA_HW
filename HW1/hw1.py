def T(n):
    # Base cases
    if n == 0:
        return 4
    # Recursive case
    return 4 * T((n - 1) >> 1) + 8 * n + 3

# Compute and print T(n) for n = 0 to 10
results = {n: T(n) for n in range(11)}
for n, value in results.items():
    print(f"T({n}) = {value}")
