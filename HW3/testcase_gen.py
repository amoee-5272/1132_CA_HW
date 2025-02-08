import random
import numpy as np

def dp_matrix_chain_multiplication(dims):
    n = len(dims) - 1
    dp = [[0] * n for _ in range(n)] 

    for length in range(2, n + 1):
        for i in range(n - length + 1):
            j = i + length - 1
            dp[i][j] = float('inf')
            for k in range(i, j):
                q = dp[i][k] + dp[k + 1][j] + dims[i] * dims[k + 1] * dims[j + 1]
                if q < dp[i][j]:
                    dp[i][j] = q

    return dp[0][n - 1]

def direct_matrix_chain_multiplication(dims):
    total_operations = 0
    for i in range(len(dims) - 2):
        total_operations += dims[0] * dims[i + 1] * dims[i + 2]
    return total_operations

def generate_matrix_chain_multiplication_test_case(tb_filename, golden_filename, matrices_num, min_dim, max_dim, min_value, max_value):

    prev_cols = random.randint(min_dim, max_dim)
    result = np.identity(prev_cols)
    dims = [prev_cols]

    with open(tb_filename, 'w') as f:
        f.write(f"{matrices_num}\n")
        
        for _ in range(matrices_num):
            rows = prev_cols
            cols = random.randint(min_dim, max_dim)
            dims.append(cols)
            f.write(f"{rows} {cols}\n")
            
            matrix = np.random.randint(min_value, max_value+1, size=(rows, cols))
            result = np.dot(result, matrix)
            for row in matrix:
                f.write(" ".join(map(str, row)) + "\n")
            
            prev_cols = cols

    result = result.astype(int)
    with open(golden_filename, 'w') as f:
        for row in result:
            f.write(" ".join(map(str, row)) + "\n")

    # print(direct_matrix_chain_multiplication(dims))
    # print(dp_matrix_chain_multiplication(dims))
    # print(np.log2(np.max(result)))

tb_idx = ''
tb_filename = f'testcase/case_{tb_idx}.txt'
golden_filename = f'golden/golden_{tb_idx}.txt'

matrices_num = 6
min_dim = 1
max_dim = 50
min_value = 1
max_value = 4

generate_matrix_chain_multiplication_test_case(tb_filename, golden_filename, matrices_num, min_dim, max_dim, min_value, max_value)

