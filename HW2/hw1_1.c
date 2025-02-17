
// 20250116 version 1 
// Can be run on RIPES
// 2990 cycles
int T(int n){
    return (n == 0)? 4 : (4 * T((n - 1) >> 1) + 8 * n + 3);
    }


int main() {
    int n = 7;
    int result;
    result = T(n);
    //printf("answer = %d\n",result);
    return 0;
}
