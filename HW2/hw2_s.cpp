// int fact(int n){
//     return (n == 0)? 4 : (4 * T((n - 1) >> 1) + 8 * n + 3);
//     }
#include <fcntl.h>    // open
#include <unistd.h>   // read, write, close, ftruncate
#include <stdlib.h>   // malloc, free, strtol, exit
#include <stdio.h>    // snprintf
#include <string.h>   // memcpy

extern "C" {
    int fact(int input);
}


int main() {
    int n = 7;
    int result;
    result = fact(n);
    // printf("answer = %d\n",result);
    // std::cout<<result;
    return 0;
}