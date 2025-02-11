import numpy as np

base_path = r'C:\Users\wuyiz\Downloads\CA_HW3'

def read_data(file_path):
    with open(file_path, 'r') as f:
        lines = f.readlines()

    num_matrices = int(lines[0].strip())
    matrices = []
    idx = 1

    for _ in range(num_matrices):
        dims = list(map(int, lines[idx].strip().split()))
        rows, cols = dims[0], dims[1]
        idx += 1
        matrix = []
        for _ in range(rows):
            matrix.append(list(map(int, lines[idx].strip().split())))
            idx += 1
        matrices.append(np.array(matrix))
    
    return matrices

def multiply_matrices(matrices):
    result = matrices[0]
    for i in range(1, len(matrices)):
        result = np.dot(result, matrices[i])
    return result

def write_result(file_path, result):
    with open(file_path, 'w') as f:
        for row in result:
            f.write(' '.join(map(str, row)) + '\n')

if __name__ == "__main__":
    data_path = rf'{base_path}\data.txt'
    answer_path = rf'{base_path}\answer.txt'
    golden_path = rf'{base_path}\golden.txt'

    # Read data
    matrices = read_data(data_path)

    # Perform matrix chain multiplication
    result = multiply_matrices(matrices)

    # Write results to answer.txt and golden.txt
    write_result(answer_path, result)
    write_result(golden_path, result)
