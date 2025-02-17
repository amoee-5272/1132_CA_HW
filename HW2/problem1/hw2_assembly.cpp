
#include <fcntl.h>
#include <unistd.h>
#include <cstdio>
#include <cstdlib>

extern "C" {
    int fact(int input);
}

int main() {
    int n = 30;
    int result = fact(n);
    
    char buffer[64];
    int len = snprintf(buffer, sizeof(buffer), "For input = %d, Your answer = %d\n", n, result);
    
    if (len > 0) {
        write(STDOUT_FILENO, buffer, len);
    }
    
    return 0;
}

// n=7
// Total simulation time: 432566000 ticks
// Time enter @main: 416027000 ticks
// Main execution time: 16539000 ticks

//n=30
// Total simulation time: 432721000 ticks
// Time enter @main: 416027000 ticks
// Main execution time: 16694000 ticks
// 476

/*
416027000: system.cpu: T0 : 0x10434 @main    : c_addi16sp sp, -64         : IntAlu :  D=0x000000007ffffe90
416029000: system.cpu: T0 : 0x10436 @main+2    : c_swsp ra, 60(sp)          : MemWrite :  D=0x0000000000010532 A=0x7ffffecc
416033000: system.cpu: T0 : 0x10438 @main+4    : c_swsp s0, 56(sp)          : MemWrite :  D=0x0000000000077b68 A=0x7ffffec8
416037000: system.cpu: T0 : 0x1043a @main+6    : c_addi4spn s0, sp, 64      : IntAlu :  D=0x000000007ffffed0
416039000: system.cpu: T0 : 0x1043c @main+8    : c_li a5, 30                : IntAlu :  D=0x000000000000001e
416136000: system.cpu: T0 : 0x1043e @main+10    : sw a5, -20(s0)             : MemWrite :  D=0x000000000000001e A=0x7ffffebc
416142000: system.cpu: T0 : 0x10442 @main+14    : lw a0, -20(s0)             : MemRead :  D=0x000000000000001e A=0x7ffffebc
416146000: system.cpu: T0 : 0x10446 @main+18    : c_jal 76                   : IntAlu :  D=0x0000000000010448
416241000: system.cpu: T0 : 0x10492 @fact    : c_mv t0, a0                : IntAlu :  D=0x000000000000001e
416243000: system.cpu: T0 : 0x10494 @recursive    : c_addi sp, -16             : IntAlu :  D=0x000000007ffffe80
416245000: system.cpu: T0 : 0x10496 @recursive+2    : c_swsp ra, 8(sp)           : MemWrite :  D=0x0000000000010448 A=0x7ffffe88
416249000: system.cpu: T0 : 0x10498 @recursive+4    : c_swsp t0, 0(sp)           : MemWrite :  D=0x000000000000001e A=0x7ffffe80
416255000: system.cpu: T0 : 0x1049a @recursive+6    : bne t0, zero, 10           : IntAlu : 
416257000: system.cpu: T0 : 0x104a4 @nfact    : c_addi t0, -1              : IntAlu :  D=0x000000000000001d
416261000: system.cpu: T0 : 0x104a6 @nfact+2    : srli t0, t0, 1             : IntAlu :  D=0x000000000000000e
416265000: system.cpu: T0 : 0x104aa @nfact+6    : jal ra, -22                : IntAlu :  D=0x00000000000104ae
416267000: system.cpu: T0 : 0x10494 @recursive    : c_addi sp, -16             : IntAlu :  D=0x000000007ffffe70
416269000: system.cpu: T0 : 0x10496 @recursive+2    : c_swsp ra, 8(sp)           : MemWrite :  D=0x00000000000104ae A=0x7ffffe78
416297000: system.cpu: T0 : 0x10498 @recursive+4    : c_swsp t0, 0(sp)           : MemWrite :  D=0x000000000000000e A=0x7ffffe70
416303000: system.cpu: T0 : 0x1049a @recursive+6    : bne t0, zero, 10           : IntAlu : 
416305000: system.cpu: T0 : 0x104a4 @nfact    : c_addi t0, -1              : IntAlu :  D=0x000000000000000d
416309000: system.cpu: T0 : 0x104a6 @nfact+2    : srli t0, t0, 1             : IntAlu :  D=0x0000000000000006
416313000: system.cpu: T0 : 0x104aa @nfact+6    : jal ra, -22                : IntAlu :  D=0x00000000000104ae
416315000: system.cpu: T0 : 0x10494 @recursive    : c_addi sp, -16             : IntAlu :  D=0x000000007ffffe60
416317000: system.cpu: T0 : 0x10496 @recursive+2    : c_swsp ra, 8(sp)           : MemWrite :  D=0x00000000000104ae A=0x7ffffe68
416321000: system.cpu: T0 : 0x10498 @recursive+4    : c_swsp t0, 0(sp)           : MemWrite :  D=0x0000000000000006 A=0x7ffffe60
416327000: system.cpu: T0 : 0x1049a @recursive+6    : bne t0, zero, 10           : IntAlu : 
416329000: system.cpu: T0 : 0x104a4 @nfact    : c_addi t0, -1              : IntAlu :  D=0x0000000000000005
416333000: system.cpu: T0 : 0x104a6 @nfact+2    : srli t0, t0, 1             : IntAlu :  D=0x0000000000000002
416337000: system.cpu: T0 : 0x104aa @nfact+6    : jal ra, -22                : IntAlu :  D=0x00000000000104ae
416339000: system.cpu: T0 : 0x10494 @recursive    : c_addi sp, -16             : IntAlu :  D=0x000000007ffffe50
416341000: system.cpu: T0 : 0x10496 @recursive+2    : c_swsp ra, 8(sp)           : MemWrite :  D=0x00000000000104ae A=0x7ffffe58
416345000: system.cpu: T0 : 0x10498 @recursive+4    : c_swsp t0, 0(sp)           : MemWrite :  D=0x0000000000000002 A=0x7ffffe50
416351000: system.cpu: T0 : 0x1049a @recursive+6    : bne t0, zero, 10           : IntAlu : 
416353000: system.cpu: T0 : 0x104a4 @nfact    : c_addi t0, -1              : IntAlu :  D=0x0000000000000001
416357000: system.cpu: T0 : 0x104a6 @nfact+2    : srli t0, t0, 1             : IntAlu :  D=0x0000000000000000
416361000: system.cpu: T0 : 0x104aa @nfact+6    : jal ra, -22                : IntAlu :  D=0x00000000000104ae
416363000: system.cpu: T0 : 0x10494 @recursive    : c_addi sp, -16             : IntAlu :  D=0x000000007ffffe40
416365000: system.cpu: T0 : 0x10496 @recursive+2    : c_swsp ra, 8(sp)           : MemWrite :  D=0x00000000000104ae A=0x7ffffe48
416369000: system.cpu: T0 : 0x10498 @recursive+4    : c_swsp t0, 0(sp)           : MemWrite :  D=0x0000000000000000 A=0x7ffffe40
416375000: system.cpu: T0 : 0x1049a @recursive+6    : bne t0, zero, 10           : IntAlu : 
416377000: system.cpu: T0 : 0x1049e @recursive+10    : c_li a0, 4                 : IntAlu :  D=0x0000000000000004
416379000: system.cpu: T0 : 0x104a0 @recursive+12    : c_addi sp, 16              : IntAlu :  D=0x000000007ffffe50
416381000: system.cpu: T0 : 0x104a2 @recursive+14    : c_jr ra                    : IntAlu : 
416383000: system.cpu: T0 : 0x104ae @nfact+10    : c_mv t1, a0                : IntAlu :  D=0x0000000000000004
416385000: system.cpu: T0 : 0x104b0 @nfact+12    : c_slli t1, 2               : IntAlu :  D=0x0000000000000010
416387000: system.cpu: T0 : 0x104b2 @nfact+14    : c_lwsp ra, 8(sp)           : MemRead :  D=0x00000000000104ae A=0x7ffffe58
416391000: system.cpu: T0 : 0x104b4 @nfact+16    : c_lwsp t0, 0(sp)           : MemRead :  D=0x0000000000000002 A=0x7ffffe50
416395000: system.cpu: T0 : 0x104b6 @nfact+18    : c_addi sp, 16              : IntAlu :  D=0x000000007ffffe60
416397000: system.cpu: T0 : 0x104b8 @nfact+20    : slli a2, t0, 3             : IntAlu :  D=0x0000000000000010
416399000: system.cpu: T0 : 0x104bc @nfact+24    : add a0, a2, t1             : IntAlu :  D=0x0000000000000020
416401000: system.cpu: T0 : 0x104c0 @nfact+28    : c_addi a0, 3               : IntAlu :  D=0x0000000000000023
416403000: system.cpu: T0 : 0x104c2 @nfact+30    : c_jr ra                    : IntAlu : 
416405000: system.cpu: T0 : 0x104ae @nfact+10    : c_mv t1, a0                : IntAlu :  D=0x0000000000000023
416407000: system.cpu: T0 : 0x104b0 @nfact+12    : c_slli t1, 2               : IntAlu :  D=0x000000000000008c
416409000: system.cpu: T0 : 0x104b2 @nfact+14    : c_lwsp ra, 8(sp)           : MemRead :  D=0x00000000000104ae A=0x7ffffe68
416413000: system.cpu: T0 : 0x104b4 @nfact+16    : c_lwsp t0, 0(sp)           : MemRead :  D=0x0000000000000006 A=0x7ffffe60
416417000: system.cpu: T0 : 0x104b6 @nfact+18    : c_addi sp, 16              : IntAlu :  D=0x000000007ffffe70
416419000: system.cpu: T0 : 0x104b8 @nfact+20    : slli a2, t0, 3             : IntAlu :  D=0x0000000000000030
416421000: system.cpu: T0 : 0x104bc @nfact+24    : add a0, a2, t1             : IntAlu :  D=0x00000000000000bc
416423000: system.cpu: T0 : 0x104c0 @nfact+28    : c_addi a0, 3               : IntAlu :  D=0x00000000000000bf
416425000: system.cpu: T0 : 0x104c2 @nfact+30    : c_jr ra                    : IntAlu : 
416427000: system.cpu: T0 : 0x104ae @nfact+10    : c_mv t1, a0                : IntAlu :  D=0x00000000000000bf
416429000: system.cpu: T0 : 0x104b0 @nfact+12    : c_slli t1, 2               : IntAlu :  D=0x00000000000002fc
416431000: system.cpu: T0 : 0x104b2 @nfact+14    : c_lwsp ra, 8(sp)           : MemRead :  D=0x00000000000104ae A=0x7ffffe78
416435000: system.cpu: T0 : 0x104b4 @nfact+16    : c_lwsp t0, 0(sp)           : MemRead :  D=0x000000000000000e A=0x7ffffe70
416439000: system.cpu: T0 : 0x104b6 @nfact+18    : c_addi sp, 16              : IntAlu :  D=0x000000007ffffe80
416441000: system.cpu: T0 : 0x104b8 @nfact+20    : slli a2, t0, 3             : IntAlu :  D=0x0000000000000070
416443000: system.cpu: T0 : 0x104bc @nfact+24    : add a0, a2, t1             : IntAlu :  D=0x000000000000036c
416445000: system.cpu: T0 : 0x104c0 @nfact+28    : c_addi a0, 3               : IntAlu :  D=0x000000000000036f
416447000: system.cpu: T0 : 0x104c2 @nfact+30    : c_jr ra                    : IntAlu : 
416449000: system.cpu: T0 : 0x104ae @nfact+10    : c_mv t1, a0                : IntAlu :  D=0x000000000000036f
416451000: system.cpu: T0 : 0x104b0 @nfact+12    : c_slli t1, 2               : IntAlu :  D=0x0000000000000dbc
416453000: system.cpu: T0 : 0x104b2 @nfact+14    : c_lwsp ra, 8(sp)           : MemRead :  D=0x0000000000010448 A=0x7ffffe88
416457000: system.cpu: T0 : 0x104b4 @nfact+16    : c_lwsp t0, 0(sp)           : MemRead :  D=0x000000000000001e A=0x7ffffe80
416461000: system.cpu: T0 : 0x104b6 @nfact+18    : c_addi sp, 16              : IntAlu :  D=0x000000007ffffe90
416463000: system.cpu: T0 : 0x104b8 @nfact+20    : slli a2, t0, 3             : IntAlu :  D=0x00000000000000f0
416465000: system.cpu: T0 : 0x104bc @nfact+24    : add a0, a2, t1             : IntAlu :  D=0x0000000000000eac
416467000: system.cpu: T0 : 0x104c0 @nfact+28    : c_addi a0, 3               : IntAlu :  D=0x0000000000000eaf
416469000: system.cpu: T0 : 0x104c2 @nfact+30    : c_jr ra                    : IntAlu : 
416471000: system.cpu: T0 : 0x10448 @main+20    : c_mv a5, a0                : IntAlu :  D=0x0000000000000eaf
416475000: system.cpu: T0 : 0x1044a @main+22    : sw a5, -24(s0)             : MemWrite :  D=0x0000000000000eaf A=0x7ffffeb8
416481000: system.cpu: T0 : 0x1044e @main+26    : addi a4, s0, -60           : IntAlu :  D=0x000000007ffffe94
416485000: system.cpu: T0 : 0x10452 @main+30    : lw a3, -24(s0)             : MemRead :  D=0x0000000000000eaf A=0x7ffffeb8
416491000: system.cpu: T0 : 0x10456 @main+34    : lui a5, 78                 : IntAlu :  D=0x000000000004e000
416495000: system.cpu: T0 : 0x1045a @main+38    : addi a2, a5, 1916          : IntAlu :  D=0x000000000004e77c
416499000: system.cpu: T0 : 0x1045e @main+42    : addi a1, zero, 32          : IntAlu :  D=0x0000000000000020
416501000: system.cpu: T0 : 0x10462 @main+46    : c_mv a0, a4                : IntAlu :  D=0x000000007ffffe94
416503000: system.cpu: T0 : 0x10464 @main+48    : jal ra, 2134               : IntAlu :  D=0x0000000000010468
*/