# Test Cases Information

## Constraints:
- **Maximum number of matrices (N)**: 16
- **Maximum dimension of matrices (D)**: 64
- **Maximum value of matrices (V)**: 128

## Public Test Cases:
- **00**: N = 3, D = 3, V = 10
- **01**: N = 3, D = 5, V = 10
- **02**: N = 4, D = 6, V = 16
- **03**: N = 5, D = 10, V = 20
- **04**: N = 6, D = 8, V = 12

## Private Test Cases:
### 05 ~ 08: Correctness Testing (Boundary Cases)
- **05**: N = 2, D = 20, V = 50  
  Testing with only 2 matrices.
- **06**: N = 16, D = 4, V = 4  
  Testing with the maximum matrix number (N = 16).
- **07**: N = 4, D = 64, V = 10  
  Testing with the maximum dimension (D = 64).
- **08**: N = 4, D = 12, V = 128  
  Testing with the maximum value (V = 128).

### 09 ~ 10: Performance Testing
- **09**: Direct computation requires 35,014 multiplications; Dynamic Programming (DP) requires 1,779 multiplications.
- **10**: Direct computation requires 102,211 multiplications; Dynamic Programming (DP) requires 19,950 multiplications.

