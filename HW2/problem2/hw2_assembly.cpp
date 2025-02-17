
#include <unistd.h>
#include <cstdio>

extern "C" {
    int LIS(int n, int* arr, int* dp);
}

int main() {
    int arr[] = {4, 5, 1, 8, 3, 6, 9, 2};  
    int n = sizeof(arr) / sizeof(arr[0]);
    int dp[n] = {0};  
    int result;

    result = LIS(n, arr, dp);
    
    char buffer[1024];
    int len = snprintf(buffer, sizeof(buffer), "Your answer = %d\n", result);
    
    if (len > 0) {
        write(STDOUT_FILENO, buffer, len);
    }
    
    return 0;
}


// LIS 執行時間: 419434 - 417672 = 1762
// main 執行時間: 419458 - 416671 = 2787

/*
416671000: system.cpu: T0 : 0x10434 @main    : addi sp, sp, -1104         : IntAlu :  D=0x000000007ffffa80
416673000: system.cpu: T0 : 0x10438 @main+4    : sw ra, 1100(sp)            : MemWrite :  D=0x0000000000010660 A=0x7ffffecc
416677000: system.cpu: T0 : 0x1043c @main+8    : sw s0, 1096(sp)            : MemWrite :  D=0x0000000000077b68 A=0x7ffffec8
416774000: system.cpu: T0 : 0x10440 @main+12    : sw s1, 1092(sp)            : MemWrite :  D=0x0000000000000002 A=0x7ffffec4
416778000: system.cpu: T0 : 0x10444 @main+16    : sw s2, 1088(sp)            : MemWrite :  D=0x0000000000000001 A=0x7ffffec0
416782000: system.cpu: T0 : 0x10448 @main+20    : addi s0, sp, 1104          : IntAlu :  D=0x000000007ffffed0
416784000: system.cpu: T0 : 0x1044c @main+24    : c_mv a5, sp                : IntAlu :  D=0x000000007ffffa80
416786000: system.cpu: T0 : 0x1044e @main+26    : c_mv s2, a5                : IntAlu :  D=0x000000007ffffa80
416788000: system.cpu: T0 : 0x10450 @main+28    : lui a5, 79                 : IntAlu :  D=0x000000000004f000
416790000: system.cpu: T0 : 0x10454 @main+32    : addi a5, a5, -1856         : IntAlu :  D=0x000000000004e8c0
416792000: system.cpu: T0 : 0x10458 @main+36    : c_lw s1, 0(a5)             : MemRead :  D=0x0000000000000004 A=0x4e8c0
416905000: system.cpu: T0 : 0x1045a @main+38    : lw t0, 4(a5)               : MemRead :  D=0x0000000000000005 A=0x4e8c4
416911000: system.cpu: T0 : 0x1045e @main+42    : lw t6, 8(a5)               : MemRead :  D=0x0000000000000001 A=0x4e8c8
416917000: system.cpu: T0 : 0x10462 @main+46    : lw t5, 12(a5)              : MemRead :  D=0x0000000000000008 A=0x4e8cc
416923000: system.cpu: T0 : 0x10466 @main+50    : lw t4, 16(a5)              : MemRead :  D=0x0000000000000003 A=0x4e8d0
416929000: system.cpu: T0 : 0x1046a @main+54    : lw t3, 20(a5)              : MemRead :  D=0x0000000000000006 A=0x4e8d4
416933000: system.cpu: T0 : 0x1046e @main+58    : c_lw a4, 24(a5)            : MemRead :  D=0x0000000000000009 A=0x4e8d8
416937000: system.cpu: T0 : 0x10470 @main+60    : c_lw a5, 28(a5)            : MemRead :  D=0x0000000000000002 A=0x4e8dc
416943000: system.cpu: T0 : 0x10472 @main+62    : sw s1, -68(s0)             : MemWrite :  D=0x0000000000000004 A=0x7ffffe8c
416949000: system.cpu: T0 : 0x10476 @main+66    : sw t0, -64(s0)             : MemWrite :  D=0x0000000000000005 A=0x7ffffe90
416955000: system.cpu: T0 : 0x1047a @main+70    : sw t6, -60(s0)             : MemWrite :  D=0x0000000000000001 A=0x7ffffe94
417054000: system.cpu: T0 : 0x1047e @main+74    : sw t5, -56(s0)             : MemWrite :  D=0x0000000000000008 A=0x7ffffe98
417060000: system.cpu: T0 : 0x10482 @main+78    : sw t4, -52(s0)             : MemWrite :  D=0x0000000000000003 A=0x7ffffe9c
417066000: system.cpu: T0 : 0x10486 @main+82    : sw t3, -48(s0)             : MemWrite :  D=0x0000000000000006 A=0x7ffffea0
417072000: system.cpu: T0 : 0x1048a @main+86    : sw a4, -44(s0)             : MemWrite :  D=0x0000000000000009 A=0x7ffffea4
417078000: system.cpu: T0 : 0x1048e @main+90    : sw a5, -40(s0)             : MemWrite :  D=0x0000000000000002 A=0x7ffffea8
417082000: system.cpu: T0 : 0x10492 @main+94    : c_li a5, 8                 : IntAlu :  D=0x0000000000000008
417084000: system.cpu: T0 : 0x10494 @main+96    : sw a5, -20(s0)             : MemWrite :  D=0x0000000000000008 A=0x7ffffebc
417088000: system.cpu: T0 : 0x10498 @main+100    : lw a5, -20(s0)             : MemRead :  D=0x0000000000000008 A=0x7ffffebc
417092000: system.cpu: T0 : 0x1049c @main+104    : addi a4, a5, -1            : IntAlu :  D=0x0000000000000007
417094000: system.cpu: T0 : 0x104a0 @main+108    : sw a4, -24(s0)             : MemWrite :  D=0x0000000000000007 A=0x7ffffeb8
417098000: system.cpu: T0 : 0x104a4 @main+112    : c_mv a4, a5                : IntAlu :  D=0x0000000000000008
417100000: system.cpu: T0 : 0x104a6 @main+114    : c_mv t1, a4                : IntAlu :  D=0x0000000000000008
417102000: system.cpu: T0 : 0x104a8 @main+116    : c_li t2, 0                 : IntAlu :  D=0x0000000000000000
417106000: system.cpu: T0 : 0x104aa @main+118    : srli a4, t1, 27            : IntAlu :  D=0x0000000000000000
417110000: system.cpu: T0 : 0x104ae @main+122    : slli a1, t2, 5             : IntAlu :  D=0x0000000000000000
417112000: system.cpu: T0 : 0x104b2 @main+126    : c_or a1, a4                : IntAlu :  D=0x0000000000000000
417114000: system.cpu: T0 : 0x104b4 @main+128    : slli a0, t1, 5             : IntAlu :  D=0x0000000000000100
417116000: system.cpu: T0 : 0x104b8 @main+132    : c_mv a4, a5                : IntAlu :  D=0x0000000000000008
417118000: system.cpu: T0 : 0x104ba @main+134    : c_mv a6, a4                : IntAlu :  D=0x0000000000000008
417120000: system.cpu: T0 : 0x104bc @main+136    : c_li a7, 0                 : IntAlu :  D=0x0000000000000000
417217000: system.cpu: T0 : 0x104be @main+138    : srli a4, a6, 27            : IntAlu :  D=0x0000000000000000
417221000: system.cpu: T0 : 0x104c2 @main+142    : slli a3, a7, 5             : IntAlu :  D=0x0000000000000000
417223000: system.cpu: T0 : 0x104c6 @main+146    : c_or a3, a4                : IntAlu :  D=0x0000000000000000
417225000: system.cpu: T0 : 0x104c8 @main+148    : slli a2, a6, 5             : IntAlu :  D=0x0000000000000100
417227000: system.cpu: T0 : 0x104cc @main+152    : c_mv a4, a5                : IntAlu :  D=0x0000000000000008
417229000: system.cpu: T0 : 0x104ce @main+154    : c_slli a4, 2               : IntAlu :  D=0x0000000000000020
417231000: system.cpu: T0 : 0x104d0 @main+156    : c_addi a4, 15              : IntAlu :  D=0x000000000000002f
417233000: system.cpu: T0 : 0x104d2 @main+158    : c_srli a4, 4               : IntAlu :  D=0x0000000000000002
417235000: system.cpu: T0 : 0x104d4 @main+160    : c_slli a4, 4               : IntAlu :  D=0x0000000000000020
417239000: system.cpu: T0 : 0x104d6 @main+162    : sub sp, sp, a4             : IntAlu :  D=0x000000007ffffa60
417241000: system.cpu: T0 : 0x104da @main+166    : c_mv a4, sp                : IntAlu :  D=0x000000007ffffa60
417243000: system.cpu: T0 : 0x104dc @main+168    : c_addi a4, 3               : IntAlu :  D=0x000000007ffffa63
417245000: system.cpu: T0 : 0x104de @main+170    : c_srli a4, 2               : IntAlu :  D=0x000000001ffffe98
417247000: system.cpu: T0 : 0x104e0 @main+172    : c_slli a4, 2               : IntAlu :  D=0x000000007ffffa60
417251000: system.cpu: T0 : 0x104e2 @main+174    : sw a4, -28(s0)             : MemWrite :  D=0x000000007ffffa60 A=0x7ffffeb4
417257000: system.cpu: T0 : 0x104e6 @main+178    : lw a4, -28(s0)             : MemRead :  D=0x000000007ffffa60 A=0x7ffffeb4
417261000: system.cpu: T0 : 0x104ea @main+182    : c_addi a5, -1              : IntAlu :  D=0x0000000000000007
417263000: system.cpu: T0 : 0x104ec @main+184    : sw zero, 0(a4)             : MemWrite :  D=0x0000000000000000 A=0x7ffffa60
417360000: system.cpu: T0 : 0x104f0 @main+188    : c_addi a4, 4               : IntAlu :  D=0x000000007ffffa64
417362000: system.cpu: T0 : 0x104f2 @main+190    : c_addi a5, -1              : IntAlu :  D=0x0000000000000006
417364000: system.cpu: T0 : 0x104f4 @main+192    : c_j 10                     : IntAlu : 
417461000: system.cpu: T0 : 0x104fe @main+202    : bge a5, zero, -8           : IntAlu : 
417465000: system.cpu: T0 : 0x104f6 @main+194    : sw zero, 0(a4)             : MemWrite :  D=0x0000000000000000 A=0x7ffffa64
417469000: system.cpu: T0 : 0x104fa @main+198    : c_addi a5, -1              : IntAlu :  D=0x0000000000000005
417471000: system.cpu: T0 : 0x104fc @main+200    : c_addi a4, 4               : IntAlu :  D=0x000000007ffffa68
417475000: system.cpu: T0 : 0x104fe @main+202    : bge a5, zero, -8           : IntAlu : 
417479000: system.cpu: T0 : 0x104f6 @main+194    : sw zero, 0(a4)             : MemWrite :  D=0x0000000000000000 A=0x7ffffa68
417483000: system.cpu: T0 : 0x104fa @main+198    : c_addi a5, -1              : IntAlu :  D=0x0000000000000004
417485000: system.cpu: T0 : 0x104fc @main+200    : c_addi a4, 4               : IntAlu :  D=0x000000007ffffa6c
417489000: system.cpu: T0 : 0x104fe @main+202    : bge a5, zero, -8           : IntAlu : 
417493000: system.cpu: T0 : 0x104f6 @main+194    : sw zero, 0(a4)             : MemWrite :  D=0x0000000000000000 A=0x7ffffa6c
417497000: system.cpu: T0 : 0x104fa @main+198    : c_addi a5, -1              : IntAlu :  D=0x0000000000000003
417499000: system.cpu: T0 : 0x104fc @main+200    : c_addi a4, 4               : IntAlu :  D=0x000000007ffffa70
417503000: system.cpu: T0 : 0x104fe @main+202    : bge a5, zero, -8           : IntAlu : 
417507000: system.cpu: T0 : 0x104f6 @main+194    : sw zero, 0(a4)             : MemWrite :  D=0x0000000000000000 A=0x7ffffa70
417511000: system.cpu: T0 : 0x104fa @main+198    : c_addi a5, -1              : IntAlu :  D=0x0000000000000002
417513000: system.cpu: T0 : 0x104fc @main+200    : c_addi a4, 4               : IntAlu :  D=0x000000007ffffa74
417517000: system.cpu: T0 : 0x104fe @main+202    : bge a5, zero, -8           : IntAlu : 
417521000: system.cpu: T0 : 0x104f6 @main+194    : sw zero, 0(a4)             : MemWrite :  D=0x0000000000000000 A=0x7ffffa74
417525000: system.cpu: T0 : 0x104fa @main+198    : c_addi a5, -1              : IntAlu :  D=0x0000000000000001
417527000: system.cpu: T0 : 0x104fc @main+200    : c_addi a4, 4               : IntAlu :  D=0x000000007ffffa78
417531000: system.cpu: T0 : 0x104fe @main+202    : bge a5, zero, -8           : IntAlu : 
417535000: system.cpu: T0 : 0x104f6 @main+194    : sw zero, 0(a4)             : MemWrite :  D=0x0000000000000000 A=0x7ffffa78
417539000: system.cpu: T0 : 0x104fa @main+198    : c_addi a5, -1              : IntAlu :  D=0x0000000000000000
417541000: system.cpu: T0 : 0x104fc @main+200    : c_addi a4, 4               : IntAlu :  D=0x000000007ffffa7c
417545000: system.cpu: T0 : 0x104fe @main+202    : bge a5, zero, -8           : IntAlu : 
417549000: system.cpu: T0 : 0x104f6 @main+194    : sw zero, 0(a4)             : MemWrite :  D=0x0000000000000000 A=0x7ffffa7c
417553000: system.cpu: T0 : 0x104fa @main+198    : c_addi a5, -1              : IntAlu :  D=0xffffffffffffffff
417555000: system.cpu: T0 : 0x104fc @main+200    : c_addi a4, 4               : IntAlu :  D=0x000000007ffffa80
417559000: system.cpu: T0 : 0x104fe @main+202    : bge a5, zero, -8           : IntAlu : 
417563000: system.cpu: T0 : 0x10502 @main+206    : addi a5, s0, -68           : IntAlu :  D=0x000000007ffffe8c
417567000: system.cpu: T0 : 0x10506 @main+210    : lw a2, -28(s0)             : MemRead :  D=0x000000007ffffa60 A=0x7ffffeb4
417571000: system.cpu: T0 : 0x1050a @main+214    : c_mv a1, a5                : IntAlu :  D=0x000000007ffffe8c
417573000: system.cpu: T0 : 0x1050c @main+216    : lw a0, -20(s0)             : MemRead :  D=0x0000000000000008 A=0x7ffffebc
417577000: system.cpu: T0 : 0x10510 @main+220    : c_jal 96                   : IntAlu :  D=0x0000000000010512
417672000: system.cpu: T0 : 0x10570 @LIS    : c_mv t5, a2                : IntAlu :  D=0x000000007ffffa60
417674000: system.cpu: T0 : 0x10572 @LIS+2    : c_mv t4, a1                : IntAlu :  D=0x000000007ffffe8c
417676000: system.cpu: T0 : 0x10574 @LIS+4    : c_li t3, 0                 : IntAlu :  D=0x0000000000000000
417678000: system.cpu: T0 : 0x10576 @LIS+6    : c_li t2, 1                 : IntAlu :  D=0x0000000000000001
417680000: system.cpu: T0 : 0x10578 @init_dp    : slli a3, t3, 2             : IntAlu :  D=0x0000000000000000
417682000: system.cpu: T0 : 0x1057c @init_dp+4    : c_add a3, t5               : IntAlu :  D=0x000000007ffffa60
417779000: system.cpu: T0 : 0x1057e @init_dp+6    : sw t2, 0(a3)               : MemWrite :  D=0x0000000000000001 A=0x7ffffa60
417783000: system.cpu: T0 : 0x10582 @init_dp+10    : c_addi t3, 1               : IntAlu :  D=0x0000000000000001
417785000: system.cpu: T0 : 0x10584 @init_dp+12    : bne t3, a0, -12            : IntAlu : 
417787000: system.cpu: T0 : 0x10578 @init_dp    : slli a3, t3, 2             : IntAlu :  D=0x0000000000000004
417789000: system.cpu: T0 : 0x1057c @init_dp+4    : c_add a3, t5               : IntAlu :  D=0x000000007ffffa64
417793000: system.cpu: T0 : 0x1057e @init_dp+6    : sw t2, 0(a3)               : MemWrite :  D=0x0000000000000001 A=0x7ffffa64
417797000: system.cpu: T0 : 0x10582 @init_dp+10    : c_addi t3, 1               : IntAlu :  D=0x0000000000000002
417799000: system.cpu: T0 : 0x10584 @init_dp+12    : bne t3, a0, -12            : IntAlu : 
417801000: system.cpu: T0 : 0x10578 @init_dp    : slli a3, t3, 2             : IntAlu :  D=0x0000000000000008
417803000: system.cpu: T0 : 0x1057c @init_dp+4    : c_add a3, t5               : IntAlu :  D=0x000000007ffffa68
417807000: system.cpu: T0 : 0x1057e @init_dp+6    : sw t2, 0(a3)               : MemWrite :  D=0x0000000000000001 A=0x7ffffa68
417811000: system.cpu: T0 : 0x10582 @init_dp+10    : c_addi t3, 1               : IntAlu :  D=0x0000000000000003
417813000: system.cpu: T0 : 0x10584 @init_dp+12    : bne t3, a0, -12            : IntAlu : 
417815000: system.cpu: T0 : 0x10578 @init_dp    : slli a3, t3, 2             : IntAlu :  D=0x000000000000000c
417817000: system.cpu: T0 : 0x1057c @init_dp+4    : c_add a3, t5               : IntAlu :  D=0x000000007ffffa6c
417821000: system.cpu: T0 : 0x1057e @init_dp+6    : sw t2, 0(a3)               : MemWrite :  D=0x0000000000000001 A=0x7ffffa6c
417825000: system.cpu: T0 : 0x10582 @init_dp+10    : c_addi t3, 1               : IntAlu :  D=0x0000000000000004
417827000: system.cpu: T0 : 0x10584 @init_dp+12    : bne t3, a0, -12            : IntAlu : 
417829000: system.cpu: T0 : 0x10578 @init_dp    : slli a3, t3, 2             : IntAlu :  D=0x0000000000000010
417831000: system.cpu: T0 : 0x1057c @init_dp+4    : c_add a3, t5               : IntAlu :  D=0x000000007ffffa70
417835000: system.cpu: T0 : 0x1057e @init_dp+6    : sw t2, 0(a3)               : MemWrite :  D=0x0000000000000001 A=0x7ffffa70
417839000: system.cpu: T0 : 0x10582 @init_dp+10    : c_addi t3, 1               : IntAlu :  D=0x0000000000000005
417841000: system.cpu: T0 : 0x10584 @init_dp+12    : bne t3, a0, -12            : IntAlu : 
417843000: system.cpu: T0 : 0x10578 @init_dp    : slli a3, t3, 2             : IntAlu :  D=0x0000000000000014
417845000: system.cpu: T0 : 0x1057c @init_dp+4    : c_add a3, t5               : IntAlu :  D=0x000000007ffffa74
417849000: system.cpu: T0 : 0x1057e @init_dp+6    : sw t2, 0(a3)               : MemWrite :  D=0x0000000000000001 A=0x7ffffa74
417853000: system.cpu: T0 : 0x10582 @init_dp+10    : c_addi t3, 1               : IntAlu :  D=0x0000000000000006
417855000: system.cpu: T0 : 0x10584 @init_dp+12    : bne t3, a0, -12            : IntAlu : 
417857000: system.cpu: T0 : 0x10578 @init_dp    : slli a3, t3, 2             : IntAlu :  D=0x0000000000000018
417859000: system.cpu: T0 : 0x1057c @init_dp+4    : c_add a3, t5               : IntAlu :  D=0x000000007ffffa78
417863000: system.cpu: T0 : 0x1057e @init_dp+6    : sw t2, 0(a3)               : MemWrite :  D=0x0000000000000001 A=0x7ffffa78
417867000: system.cpu: T0 : 0x10582 @init_dp+10    : c_addi t3, 1               : IntAlu :  D=0x0000000000000007
417869000: system.cpu: T0 : 0x10584 @init_dp+12    : bne t3, a0, -12            : IntAlu : 
417871000: system.cpu: T0 : 0x10578 @init_dp    : slli a3, t3, 2             : IntAlu :  D=0x000000000000001c
417873000: system.cpu: T0 : 0x1057c @init_dp+4    : c_add a3, t5               : IntAlu :  D=0x000000007ffffa7c
417877000: system.cpu: T0 : 0x1057e @init_dp+6    : sw t2, 0(a3)               : MemWrite :  D=0x0000000000000001 A=0x7ffffa7c
417881000: system.cpu: T0 : 0x10582 @init_dp+10    : c_addi t3, 1               : IntAlu :  D=0x0000000000000008
417883000: system.cpu: T0 : 0x10584 @init_dp+12    : bne t3, a0, -12            : IntAlu : 
417885000: system.cpu: T0 : 0x10588 @init_dp+16    : c_li t3, 0                 : IntAlu :  D=0x0000000000000000
417889000: system.cpu: T0 : 0x1058a @outer_loop    : beq t3, a0, 70             : IntAlu : 
417891000: system.cpu: T0 : 0x1058e @outer_loop+4    : c_li t6, 0                 : IntAlu :  D=0x0000000000000000
417893000: system.cpu: T0 : 0x10590 @inner_loop    : beq t6, t3, 60             : IntAlu : 
417988000: system.cpu: T0 : 0x105cc @next_i    : c_addi t3, 1               : IntAlu :  D=0x0000000000000001
417990000: system.cpu: T0 : 0x105ce @next_i+2    : c_j -68                    : IntAlu : 
417994000: system.cpu: T0 : 0x1058a @outer_loop    : beq t3, a0, 70             : IntAlu : 
417996000: system.cpu: T0 : 0x1058e @outer_loop+4    : c_li t6, 0                 : IntAlu :  D=0x0000000000000000
417998000: system.cpu: T0 : 0x10590 @inner_loop    : beq t6, t3, 60             : IntAlu : 
418000000: system.cpu: T0 : 0x10594 @inner_loop+4    : slli a3, t3, 2             : IntAlu :  D=0x0000000000000004
418002000: system.cpu: T0 : 0x10598 @inner_loop+8    : c_add a3, t4               : IntAlu :  D=0x000000007ffffe90
418004000: system.cpu: T0 : 0x1059a @inner_loop+10    : c_lw a2, 0(a3)             : MemRead :  D=0x0000000000000005 A=0x7ffffe90
418008000: system.cpu: T0 : 0x1059c @inner_loop+12    : slli a5, t6, 2             : IntAlu :  D=0x0000000000000000
418010000: system.cpu: T0 : 0x105a0 @inner_loop+16    : c_add a5, t4               : IntAlu :  D=0x000000007ffffe8c
418012000: system.cpu: T0 : 0x105a2 @inner_loop+18    : c_lw a4, 0(a5)             : MemRead :  D=0x0000000000000004 A=0x7ffffe8c
418016000: system.cpu: T0 : 0x105a4 @inner_loop+20    : bge a4, a2, 30             : IntAlu : 
418018000: system.cpu: T0 : 0x105a8 @inner_loop+24    : slli a5, t6, 2             : IntAlu :  D=0x0000000000000000
418020000: system.cpu: T0 : 0x105ac @inner_loop+28    : c_add a5, t5               : IntAlu :  D=0x000000007ffffa60
418024000: system.cpu: T0 : 0x105ae @inner_loop+30    : lw a6, 0(a5)               : MemRead :  D=0x0000000000000001 A=0x7ffffa60
418028000: system.cpu: T0 : 0x105b2 @inner_loop+34    : c_addi a6, 1               : IntAlu :  D=0x0000000000000002
418030000: system.cpu: T0 : 0x105b4 @inner_loop+36    : slli a3, t3, 2             : IntAlu :  D=0x0000000000000004
418032000: system.cpu: T0 : 0x105b8 @inner_loop+40    : c_add a3, t5               : IntAlu :  D=0x000000007ffffa64
418036000: system.cpu: T0 : 0x105ba @inner_loop+42    : lw a7, 0(a3)               : MemRead :  D=0x0000000000000001 A=0x7ffffa64
418042000: system.cpu: T0 : 0x105be @inner_loop+46    : blt a7, a6, 8              : IntAlu : 
418046000: system.cpu: T0 : 0x105c6 @update_dp    : sw a6, 0(a3)               : MemWrite :  D=0x0000000000000002 A=0x7ffffa64
418050000: system.cpu: T0 : 0x105ca @update_dp+4    : c_j -8                     : IntAlu : 
418052000: system.cpu: T0 : 0x105c2 @skip_dp_update    : c_addi t6, 1               : IntAlu :  D=0x0000000000000001
418054000: system.cpu: T0 : 0x105c4 @skip_dp_update+2    : c_j -52                    : IntAlu : 
418056000: system.cpu: T0 : 0x10590 @inner_loop    : beq t6, t3, 60             : IntAlu : 
418058000: system.cpu: T0 : 0x105cc @next_i    : c_addi t3, 1               : IntAlu :  D=0x0000000000000002
418060000: system.cpu: T0 : 0x105ce @next_i+2    : c_j -68                    : IntAlu : 
418064000: system.cpu: T0 : 0x1058a @outer_loop    : beq t3, a0, 70             : IntAlu : 
418066000: system.cpu: T0 : 0x1058e @outer_loop+4    : c_li t6, 0                 : IntAlu :  D=0x0000000000000000
418068000: system.cpu: T0 : 0x10590 @inner_loop    : beq t6, t3, 60             : IntAlu : 
418070000: system.cpu: T0 : 0x10594 @inner_loop+4    : slli a3, t3, 2             : IntAlu :  D=0x0000000000000008
418072000: system.cpu: T0 : 0x10598 @inner_loop+8    : c_add a3, t4               : IntAlu :  D=0x000000007ffffe94
418074000: system.cpu: T0 : 0x1059a @inner_loop+10    : c_lw a2, 0(a3)             : MemRead :  D=0x0000000000000001 A=0x7ffffe94
418078000: system.cpu: T0 : 0x1059c @inner_loop+12    : slli a5, t6, 2             : IntAlu :  D=0x0000000000000000
418080000: system.cpu: T0 : 0x105a0 @inner_loop+16    : c_add a5, t4               : IntAlu :  D=0x000000007ffffe8c
418082000: system.cpu: T0 : 0x105a2 @inner_loop+18    : c_lw a4, 0(a5)             : MemRead :  D=0x0000000000000004 A=0x7ffffe8c
418086000: system.cpu: T0 : 0x105a4 @inner_loop+20    : bge a4, a2, 30             : IntAlu : 
418088000: system.cpu: T0 : 0x105c2 @skip_dp_update    : c_addi t6, 1               : IntAlu :  D=0x0000000000000001
418090000: system.cpu: T0 : 0x105c4 @skip_dp_update+2    : c_j -52                    : IntAlu : 
418092000: system.cpu: T0 : 0x10590 @inner_loop    : beq t6, t3, 60             : IntAlu : 
418094000: system.cpu: T0 : 0x10594 @inner_loop+4    : slli a3, t3, 2             : IntAlu :  D=0x0000000000000008
418096000: system.cpu: T0 : 0x10598 @inner_loop+8    : c_add a3, t4               : IntAlu :  D=0x000000007ffffe94
418098000: system.cpu: T0 : 0x1059a @inner_loop+10    : c_lw a2, 0(a3)             : MemRead :  D=0x0000000000000001 A=0x7ffffe94
418102000: system.cpu: T0 : 0x1059c @inner_loop+12    : slli a5, t6, 2             : IntAlu :  D=0x0000000000000004
418104000: system.cpu: T0 : 0x105a0 @inner_loop+16    : c_add a5, t4               : IntAlu :  D=0x000000007ffffe90
418106000: system.cpu: T0 : 0x105a2 @inner_loop+18    : c_lw a4, 0(a5)             : MemRead :  D=0x0000000000000005 A=0x7ffffe90
418110000: system.cpu: T0 : 0x105a4 @inner_loop+20    : bge a4, a2, 30             : IntAlu : 
418112000: system.cpu: T0 : 0x105c2 @skip_dp_update    : c_addi t6, 1               : IntAlu :  D=0x0000000000000002
418114000: system.cpu: T0 : 0x105c4 @skip_dp_update+2    : c_j -52                    : IntAlu : 
418116000: system.cpu: T0 : 0x10590 @inner_loop    : beq t6, t3, 60             : IntAlu : 
418118000: system.cpu: T0 : 0x105cc @next_i    : c_addi t3, 1               : IntAlu :  D=0x0000000000000003
418120000: system.cpu: T0 : 0x105ce @next_i+2    : c_j -68                    : IntAlu : 
418124000: system.cpu: T0 : 0x1058a @outer_loop    : beq t3, a0, 70             : IntAlu : 
418126000: system.cpu: T0 : 0x1058e @outer_loop+4    : c_li t6, 0                 : IntAlu :  D=0x0000000000000000
418128000: system.cpu: T0 : 0x10590 @inner_loop    : beq t6, t3, 60             : IntAlu : 
418130000: system.cpu: T0 : 0x10594 @inner_loop+4    : slli a3, t3, 2             : IntAlu :  D=0x000000000000000c
418132000: system.cpu: T0 : 0x10598 @inner_loop+8    : c_add a3, t4               : IntAlu :  D=0x000000007ffffe98
418134000: system.cpu: T0 : 0x1059a @inner_loop+10    : c_lw a2, 0(a3)             : MemRead :  D=0x0000000000000008 A=0x7ffffe98
418138000: system.cpu: T0 : 0x1059c @inner_loop+12    : slli a5, t6, 2             : IntAlu :  D=0x0000000000000000
418140000: system.cpu: T0 : 0x105a0 @inner_loop+16    : c_add a5, t4               : IntAlu :  D=0x000000007ffffe8c
418142000: system.cpu: T0 : 0x105a2 @inner_loop+18    : c_lw a4, 0(a5)             : MemRead :  D=0x0000000000000004 A=0x7ffffe8c
418146000: system.cpu: T0 : 0x105a4 @inner_loop+20    : bge a4, a2, 30             : IntAlu : 
418148000: system.cpu: T0 : 0x105a8 @inner_loop+24    : slli a5, t6, 2             : IntAlu :  D=0x0000000000000000
418150000: system.cpu: T0 : 0x105ac @inner_loop+28    : c_add a5, t5               : IntAlu :  D=0x000000007ffffa60
418154000: system.cpu: T0 : 0x105ae @inner_loop+30    : lw a6, 0(a5)               : MemRead :  D=0x0000000000000001 A=0x7ffffa60
418158000: system.cpu: T0 : 0x105b2 @inner_loop+34    : c_addi a6, 1               : IntAlu :  D=0x0000000000000002
418160000: system.cpu: T0 : 0x105b4 @inner_loop+36    : slli a3, t3, 2             : IntAlu :  D=0x000000000000000c
418162000: system.cpu: T0 : 0x105b8 @inner_loop+40    : c_add a3, t5               : IntAlu :  D=0x000000007ffffa6c
418166000: system.cpu: T0 : 0x105ba @inner_loop+42    : lw a7, 0(a3)               : MemRead :  D=0x0000000000000001 A=0x7ffffa6c
418172000: system.cpu: T0 : 0x105be @inner_loop+46    : blt a7, a6, 8              : IntAlu : 
418176000: system.cpu: T0 : 0x105c6 @update_dp    : sw a6, 0(a3)               : MemWrite :  D=0x0000000000000002 A=0x7ffffa6c
418180000: system.cpu: T0 : 0x105ca @update_dp+4    : c_j -8                     : IntAlu : 
418182000: system.cpu: T0 : 0x105c2 @skip_dp_update    : c_addi t6, 1               : IntAlu :  D=0x0000000000000001
418184000: system.cpu: T0 : 0x105c4 @skip_dp_update+2    : c_j -52                    : IntAlu : 
418186000: system.cpu: T0 : 0x10590 @inner_loop    : beq t6, t3, 60             : IntAlu : 
418188000: system.cpu: T0 : 0x10594 @inner_loop+4    : slli a3, t3, 2             : IntAlu :  D=0x000000000000000c
418190000: system.cpu: T0 : 0x10598 @inner_loop+8    : c_add a3, t4               : IntAlu :  D=0x000000007ffffe98
418192000: system.cpu: T0 : 0x1059a @inner_loop+10    : c_lw a2, 0(a3)             : MemRead :  D=0x0000000000000008 A=0x7ffffe98
418196000: system.cpu: T0 : 0x1059c @inner_loop+12    : slli a5, t6, 2             : IntAlu :  D=0x0000000000000004
418198000: system.cpu: T0 : 0x105a0 @inner_loop+16    : c_add a5, t4               : IntAlu :  D=0x000000007ffffe90
418200000: system.cpu: T0 : 0x105a2 @inner_loop+18    : c_lw a4, 0(a5)             : MemRead :  D=0x0000000000000005 A=0x7ffffe90
418204000: system.cpu: T0 : 0x105a4 @inner_loop+20    : bge a4, a2, 30             : IntAlu : 
418206000: system.cpu: T0 : 0x105a8 @inner_loop+24    : slli a5, t6, 2             : IntAlu :  D=0x0000000000000004
418208000: system.cpu: T0 : 0x105ac @inner_loop+28    : c_add a5, t5               : IntAlu :  D=0x000000007ffffa64
418212000: system.cpu: T0 : 0x105ae @inner_loop+30    : lw a6, 0(a5)               : MemRead :  D=0x0000000000000002 A=0x7ffffa64
418216000: system.cpu: T0 : 0x105b2 @inner_loop+34    : c_addi a6, 1               : IntAlu :  D=0x0000000000000003
418218000: system.cpu: T0 : 0x105b4 @inner_loop+36    : slli a3, t3, 2             : IntAlu :  D=0x000000000000000c
418220000: system.cpu: T0 : 0x105b8 @inner_loop+40    : c_add a3, t5               : IntAlu :  D=0x000000007ffffa6c
418224000: system.cpu: T0 : 0x105ba @inner_loop+42    : lw a7, 0(a3)               : MemRead :  D=0x0000000000000002 A=0x7ffffa6c
418230000: system.cpu: T0 : 0x105be @inner_loop+46    : blt a7, a6, 8              : IntAlu : 
418234000: system.cpu: T0 : 0x105c6 @update_dp    : sw a6, 0(a3)               : MemWrite :  D=0x0000000000000003 A=0x7ffffa6c
418238000: system.cpu: T0 : 0x105ca @update_dp+4    : c_j -8                     : IntAlu : 
418240000: system.cpu: T0 : 0x105c2 @skip_dp_update    : c_addi t6, 1               : IntAlu :  D=0x0000000000000002
418242000: system.cpu: T0 : 0x105c4 @skip_dp_update+2    : c_j -52                    : IntAlu : 
418244000: system.cpu: T0 : 0x10590 @inner_loop    : beq t6, t3, 60             : IntAlu : 
418246000: system.cpu: T0 : 0x10594 @inner_loop+4    : slli a3, t3, 2             : IntAlu :  D=0x000000000000000c
418248000: system.cpu: T0 : 0x10598 @inner_loop+8    : c_add a3, t4               : IntAlu :  D=0x000000007ffffe98
418250000: system.cpu: T0 : 0x1059a @inner_loop+10    : c_lw a2, 0(a3)             : MemRead :  D=0x0000000000000008 A=0x7ffffe98
418254000: system.cpu: T0 : 0x1059c @inner_loop+12    : slli a5, t6, 2             : IntAlu :  D=0x0000000000000008
418256000: system.cpu: T0 : 0x105a0 @inner_loop+16    : c_add a5, t4               : IntAlu :  D=0x000000007ffffe94
418258000: system.cpu: T0 : 0x105a2 @inner_loop+18    : c_lw a4, 0(a5)             : MemRead :  D=0x0000000000000001 A=0x7ffffe94
418262000: system.cpu: T0 : 0x105a4 @inner_loop+20    : bge a4, a2, 30             : IntAlu : 
418264000: system.cpu: T0 : 0x105a8 @inner_loop+24    : slli a5, t6, 2             : IntAlu :  D=0x0000000000000008
418266000: system.cpu: T0 : 0x105ac @inner_loop+28    : c_add a5, t5               : IntAlu :  D=0x000000007ffffa68
418270000: system.cpu: T0 : 0x105ae @inner_loop+30    : lw a6, 0(a5)               : MemRead :  D=0x0000000000000001 A=0x7ffffa68
418274000: system.cpu: T0 : 0x105b2 @inner_loop+34    : c_addi a6, 1               : IntAlu :  D=0x0000000000000002
418276000: system.cpu: T0 : 0x105b4 @inner_loop+36    : slli a3, t3, 2             : IntAlu :  D=0x000000000000000c
418278000: system.cpu: T0 : 0x105b8 @inner_loop+40    : c_add a3, t5               : IntAlu :  D=0x000000007ffffa6c
418282000: system.cpu: T0 : 0x105ba @inner_loop+42    : lw a7, 0(a3)               : MemRead :  D=0x0000000000000003 A=0x7ffffa6c
418288000: system.cpu: T0 : 0x105be @inner_loop+46    : blt a7, a6, 8              : IntAlu : 
418290000: system.cpu: T0 : 0x105c2 @skip_dp_update    : c_addi t6, 1               : IntAlu :  D=0x0000000000000003
418292000: system.cpu: T0 : 0x105c4 @skip_dp_update+2    : c_j -52                    : IntAlu : 
418294000: system.cpu: T0 : 0x10590 @inner_loop    : beq t6, t3, 60             : IntAlu : 
418296000: system.cpu: T0 : 0x105cc @next_i    : c_addi t3, 1               : IntAlu :  D=0x0000000000000004
418298000: system.cpu: T0 : 0x105ce @next_i+2    : c_j -68                    : IntAlu : 
418302000: system.cpu: T0 : 0x1058a @outer_loop    : beq t3, a0, 70             : IntAlu : 
418304000: system.cpu: T0 : 0x1058e @outer_loop+4    : c_li t6, 0                 : IntAlu :  D=0x0000000000000000
418306000: system.cpu: T0 : 0x10590 @inner_loop    : beq t6, t3, 60             : IntAlu : 
418308000: system.cpu: T0 : 0x10594 @inner_loop+4    : slli a3, t3, 2             : IntAlu :  D=0x0000000000000010
418310000: system.cpu: T0 : 0x10598 @inner_loop+8    : c_add a3, t4               : IntAlu :  D=0x000000007ffffe9c
418312000: system.cpu: T0 : 0x1059a @inner_loop+10    : c_lw a2, 0(a3)             : MemRead :  D=0x0000000000000003 A=0x7ffffe9c
418316000: system.cpu: T0 : 0x1059c @inner_loop+12    : slli a5, t6, 2             : IntAlu :  D=0x0000000000000000
418318000: system.cpu: T0 : 0x105a0 @inner_loop+16    : c_add a5, t4               : IntAlu :  D=0x000000007ffffe8c
418320000: system.cpu: T0 : 0x105a2 @inner_loop+18    : c_lw a4, 0(a5)             : MemRead :  D=0x0000000000000004 A=0x7ffffe8c
418324000: system.cpu: T0 : 0x105a4 @inner_loop+20    : bge a4, a2, 30             : IntAlu : 
418326000: system.cpu: T0 : 0x105c2 @skip_dp_update    : c_addi t6, 1               : IntAlu :  D=0x0000000000000001
418328000: system.cpu: T0 : 0x105c4 @skip_dp_update+2    : c_j -52                    : IntAlu : 
418330000: system.cpu: T0 : 0x10590 @inner_loop    : beq t6, t3, 60             : IntAlu : 
418332000: system.cpu: T0 : 0x10594 @inner_loop+4    : slli a3, t3, 2             : IntAlu :  D=0x0000000000000010
418334000: system.cpu: T0 : 0x10598 @inner_loop+8    : c_add a3, t4               : IntAlu :  D=0x000000007ffffe9c
418336000: system.cpu: T0 : 0x1059a @inner_loop+10    : c_lw a2, 0(a3)             : MemRead :  D=0x0000000000000003 A=0x7ffffe9c
418340000: system.cpu: T0 : 0x1059c @inner_loop+12    : slli a5, t6, 2             : IntAlu :  D=0x0000000000000004
418342000: system.cpu: T0 : 0x105a0 @inner_loop+16    : c_add a5, t4               : IntAlu :  D=0x000000007ffffe90
418344000: system.cpu: T0 : 0x105a2 @inner_loop+18    : c_lw a4, 0(a5)             : MemRead :  D=0x0000000000000005 A=0x7ffffe90
418348000: system.cpu: T0 : 0x105a4 @inner_loop+20    : bge a4, a2, 30             : IntAlu : 
418350000: system.cpu: T0 : 0x105c2 @skip_dp_update    : c_addi t6, 1               : IntAlu :  D=0x0000000000000002
418352000: system.cpu: T0 : 0x105c4 @skip_dp_update+2    : c_j -52                    : IntAlu : 
418354000: system.cpu: T0 : 0x10590 @inner_loop    : beq t6, t3, 60             : IntAlu : 
418356000: system.cpu: T0 : 0x10594 @inner_loop+4    : slli a3, t3, 2             : IntAlu :  D=0x0000000000000010
418358000: system.cpu: T0 : 0x10598 @inner_loop+8    : c_add a3, t4               : IntAlu :  D=0x000000007ffffe9c
418360000: system.cpu: T0 : 0x1059a @inner_loop+10    : c_lw a2, 0(a3)             : MemRead :  D=0x0000000000000003 A=0x7ffffe9c
418364000: system.cpu: T0 : 0x1059c @inner_loop+12    : slli a5, t6, 2             : IntAlu :  D=0x0000000000000008
418366000: system.cpu: T0 : 0x105a0 @inner_loop+16    : c_add a5, t4               : IntAlu :  D=0x000000007ffffe94
418368000: system.cpu: T0 : 0x105a2 @inner_loop+18    : c_lw a4, 0(a5)             : MemRead :  D=0x0000000000000001 A=0x7ffffe94
418372000: system.cpu: T0 : 0x105a4 @inner_loop+20    : bge a4, a2, 30             : IntAlu : 
418374000: system.cpu: T0 : 0x105a8 @inner_loop+24    : slli a5, t6, 2             : IntAlu :  D=0x0000000000000008
418376000: system.cpu: T0 : 0x105ac @inner_loop+28    : c_add a5, t5               : IntAlu :  D=0x000000007ffffa68
418380000: system.cpu: T0 : 0x105ae @inner_loop+30    : lw a6, 0(a5)               : MemRead :  D=0x0000000000000001 A=0x7ffffa68
418384000: system.cpu: T0 : 0x105b2 @inner_loop+34    : c_addi a6, 1               : IntAlu :  D=0x0000000000000002
418386000: system.cpu: T0 : 0x105b4 @inner_loop+36    : slli a3, t3, 2             : IntAlu :  D=0x0000000000000010
418388000: system.cpu: T0 : 0x105b8 @inner_loop+40    : c_add a3, t5               : IntAlu :  D=0x000000007ffffa70
418392000: system.cpu: T0 : 0x105ba @inner_loop+42    : lw a7, 0(a3)               : MemRead :  D=0x0000000000000001 A=0x7ffffa70
418398000: system.cpu: T0 : 0x105be @inner_loop+46    : blt a7, a6, 8              : IntAlu : 
418402000: system.cpu: T0 : 0x105c6 @update_dp    : sw a6, 0(a3)               : MemWrite :  D=0x0000000000000002 A=0x7ffffa70
418406000: system.cpu: T0 : 0x105ca @update_dp+4    : c_j -8                     : IntAlu : 
418408000: system.cpu: T0 : 0x105c2 @skip_dp_update    : c_addi t6, 1               : IntAlu :  D=0x0000000000000003
418410000: system.cpu: T0 : 0x105c4 @skip_dp_update+2    : c_j -52                    : IntAlu : 
418412000: system.cpu: T0 : 0x10590 @inner_loop    : beq t6, t3, 60             : IntAlu : 
418414000: system.cpu: T0 : 0x10594 @inner_loop+4    : slli a3, t3, 2             : IntAlu :  D=0x0000000000000010
418416000: system.cpu: T0 : 0x10598 @inner_loop+8    : c_add a3, t4               : IntAlu :  D=0x000000007ffffe9c
418418000: system.cpu: T0 : 0x1059a @inner_loop+10    : c_lw a2, 0(a3)             : MemRead :  D=0x0000000000000003 A=0x7ffffe9c
418422000: system.cpu: T0 : 0x1059c @inner_loop+12    : slli a5, t6, 2             : IntAlu :  D=0x000000000000000c
418424000: system.cpu: T0 : 0x105a0 @inner_loop+16    : c_add a5, t4               : IntAlu :  D=0x000000007ffffe98
418426000: system.cpu: T0 : 0x105a2 @inner_loop+18    : c_lw a4, 0(a5)             : MemRead :  D=0x0000000000000008 A=0x7ffffe98
418430000: system.cpu: T0 : 0x105a4 @inner_loop+20    : bge a4, a2, 30             : IntAlu : 
418432000: system.cpu: T0 : 0x105c2 @skip_dp_update    : c_addi t6, 1               : IntAlu :  D=0x0000000000000004
418434000: system.cpu: T0 : 0x105c4 @skip_dp_update+2    : c_j -52                    : IntAlu : 
418436000: system.cpu: T0 : 0x10590 @inner_loop    : beq t6, t3, 60             : IntAlu : 
418438000: system.cpu: T0 : 0x105cc @next_i    : c_addi t3, 1               : IntAlu :  D=0x0000000000000005
418440000: system.cpu: T0 : 0x105ce @next_i+2    : c_j -68                    : IntAlu : 
418444000: system.cpu: T0 : 0x1058a @outer_loop    : beq t3, a0, 70             : IntAlu : 
418446000: system.cpu: T0 : 0x1058e @outer_loop+4    : c_li t6, 0                 : IntAlu :  D=0x0000000000000000
418448000: system.cpu: T0 : 0x10590 @inner_loop    : beq t6, t3, 60             : IntAlu : 
418450000: system.cpu: T0 : 0x10594 @inner_loop+4    : slli a3, t3, 2             : IntAlu :  D=0x0000000000000014
418452000: system.cpu: T0 : 0x10598 @inner_loop+8    : c_add a3, t4               : IntAlu :  D=0x000000007ffffea0
418454000: system.cpu: T0 : 0x1059a @inner_loop+10    : c_lw a2, 0(a3)             : MemRead :  D=0x0000000000000006 A=0x7ffffea0
418458000: system.cpu: T0 : 0x1059c @inner_loop+12    : slli a5, t6, 2             : IntAlu :  D=0x0000000000000000
418460000: system.cpu: T0 : 0x105a0 @inner_loop+16    : c_add a5, t4               : IntAlu :  D=0x000000007ffffe8c
418462000: system.cpu: T0 : 0x105a2 @inner_loop+18    : c_lw a4, 0(a5)             : MemRead :  D=0x0000000000000004 A=0x7ffffe8c
418466000: system.cpu: T0 : 0x105a4 @inner_loop+20    : bge a4, a2, 30             : IntAlu : 
418468000: system.cpu: T0 : 0x105a8 @inner_loop+24    : slli a5, t6, 2             : IntAlu :  D=0x0000000000000000
418470000: system.cpu: T0 : 0x105ac @inner_loop+28    : c_add a5, t5               : IntAlu :  D=0x000000007ffffa60
418474000: system.cpu: T0 : 0x105ae @inner_loop+30    : lw a6, 0(a5)               : MemRead :  D=0x0000000000000001 A=0x7ffffa60
418478000: system.cpu: T0 : 0x105b2 @inner_loop+34    : c_addi a6, 1               : IntAlu :  D=0x0000000000000002
418480000: system.cpu: T0 : 0x105b4 @inner_loop+36    : slli a3, t3, 2             : IntAlu :  D=0x0000000000000014
418482000: system.cpu: T0 : 0x105b8 @inner_loop+40    : c_add a3, t5               : IntAlu :  D=0x000000007ffffa74
418486000: system.cpu: T0 : 0x105ba @inner_loop+42    : lw a7, 0(a3)               : MemRead :  D=0x0000000000000001 A=0x7ffffa74
418492000: system.cpu: T0 : 0x105be @inner_loop+46    : blt a7, a6, 8              : IntAlu : 
418496000: system.cpu: T0 : 0x105c6 @update_dp    : sw a6, 0(a3)               : MemWrite :  D=0x0000000000000002 A=0x7ffffa74
418500000: system.cpu: T0 : 0x105ca @update_dp+4    : c_j -8                     : IntAlu : 
418502000: system.cpu: T0 : 0x105c2 @skip_dp_update    : c_addi t6, 1               : IntAlu :  D=0x0000000000000001
418504000: system.cpu: T0 : 0x105c4 @skip_dp_update+2    : c_j -52                    : IntAlu : 
418506000: system.cpu: T0 : 0x10590 @inner_loop    : beq t6, t3, 60             : IntAlu : 
418508000: system.cpu: T0 : 0x10594 @inner_loop+4    : slli a3, t3, 2             : IntAlu :  D=0x0000000000000014
418510000: system.cpu: T0 : 0x10598 @inner_loop+8    : c_add a3, t4               : IntAlu :  D=0x000000007ffffea0
418512000: system.cpu: T0 : 0x1059a @inner_loop+10    : c_lw a2, 0(a3)             : MemRead :  D=0x0000000000000006 A=0x7ffffea0
418516000: system.cpu: T0 : 0x1059c @inner_loop+12    : slli a5, t6, 2             : IntAlu :  D=0x0000000000000004
418518000: system.cpu: T0 : 0x105a0 @inner_loop+16    : c_add a5, t4               : IntAlu :  D=0x000000007ffffe90
418520000: system.cpu: T0 : 0x105a2 @inner_loop+18    : c_lw a4, 0(a5)             : MemRead :  D=0x0000000000000005 A=0x7ffffe90
418524000: system.cpu: T0 : 0x105a4 @inner_loop+20    : bge a4, a2, 30             : IntAlu : 
418526000: system.cpu: T0 : 0x105a8 @inner_loop+24    : slli a5, t6, 2             : IntAlu :  D=0x0000000000000004
418528000: system.cpu: T0 : 0x105ac @inner_loop+28    : c_add a5, t5               : IntAlu :  D=0x000000007ffffa64
418532000: system.cpu: T0 : 0x105ae @inner_loop+30    : lw a6, 0(a5)               : MemRead :  D=0x0000000000000002 A=0x7ffffa64
418536000: system.cpu: T0 : 0x105b2 @inner_loop+34    : c_addi a6, 1               : IntAlu :  D=0x0000000000000003
418538000: system.cpu: T0 : 0x105b4 @inner_loop+36    : slli a3, t3, 2             : IntAlu :  D=0x0000000000000014
418540000: system.cpu: T0 : 0x105b8 @inner_loop+40    : c_add a3, t5               : IntAlu :  D=0x000000007ffffa74
418544000: system.cpu: T0 : 0x105ba @inner_loop+42    : lw a7, 0(a3)               : MemRead :  D=0x0000000000000002 A=0x7ffffa74
418550000: system.cpu: T0 : 0x105be @inner_loop+46    : blt a7, a6, 8              : IntAlu : 
418554000: system.cpu: T0 : 0x105c6 @update_dp    : sw a6, 0(a3)               : MemWrite :  D=0x0000000000000003 A=0x7ffffa74
418558000: system.cpu: T0 : 0x105ca @update_dp+4    : c_j -8                     : IntAlu : 
418560000: system.cpu: T0 : 0x105c2 @skip_dp_update    : c_addi t6, 1               : IntAlu :  D=0x0000000000000002
418562000: system.cpu: T0 : 0x105c4 @skip_dp_update+2    : c_j -52                    : IntAlu : 
418564000: system.cpu: T0 : 0x10590 @inner_loop    : beq t6, t3, 60             : IntAlu : 
418566000: system.cpu: T0 : 0x10594 @inner_loop+4    : slli a3, t3, 2             : IntAlu :  D=0x0000000000000014
418568000: system.cpu: T0 : 0x10598 @inner_loop+8    : c_add a3, t4               : IntAlu :  D=0x000000007ffffea0
418570000: system.cpu: T0 : 0x1059a @inner_loop+10    : c_lw a2, 0(a3)             : MemRead :  D=0x0000000000000006 A=0x7ffffea0
418574000: system.cpu: T0 : 0x1059c @inner_loop+12    : slli a5, t6, 2             : IntAlu :  D=0x0000000000000008
418576000: system.cpu: T0 : 0x105a0 @inner_loop+16    : c_add a5, t4               : IntAlu :  D=0x000000007ffffe94
418578000: system.cpu: T0 : 0x105a2 @inner_loop+18    : c_lw a4, 0(a5)             : MemRead :  D=0x0000000000000001 A=0x7ffffe94
418582000: system.cpu: T0 : 0x105a4 @inner_loop+20    : bge a4, a2, 30             : IntAlu : 
418584000: system.cpu: T0 : 0x105a8 @inner_loop+24    : slli a5, t6, 2             : IntAlu :  D=0x0000000000000008
418586000: system.cpu: T0 : 0x105ac @inner_loop+28    : c_add a5, t5               : IntAlu :  D=0x000000007ffffa68
418590000: system.cpu: T0 : 0x105ae @inner_loop+30    : lw a6, 0(a5)               : MemRead :  D=0x0000000000000001 A=0x7ffffa68
418594000: system.cpu: T0 : 0x105b2 @inner_loop+34    : c_addi a6, 1               : IntAlu :  D=0x0000000000000002
418596000: system.cpu: T0 : 0x105b4 @inner_loop+36    : slli a3, t3, 2             : IntAlu :  D=0x0000000000000014
418598000: system.cpu: T0 : 0x105b8 @inner_loop+40    : c_add a3, t5               : IntAlu :  D=0x000000007ffffa74
418602000: system.cpu: T0 : 0x105ba @inner_loop+42    : lw a7, 0(a3)               : MemRead :  D=0x0000000000000003 A=0x7ffffa74
418608000: system.cpu: T0 : 0x105be @inner_loop+46    : blt a7, a6, 8              : IntAlu : 
418610000: system.cpu: T0 : 0x105c2 @skip_dp_update    : c_addi t6, 1               : IntAlu :  D=0x0000000000000003
418612000: system.cpu: T0 : 0x105c4 @skip_dp_update+2    : c_j -52                    : IntAlu : 
418614000: system.cpu: T0 : 0x10590 @inner_loop    : beq t6, t3, 60             : IntAlu : 
418616000: system.cpu: T0 : 0x10594 @inner_loop+4    : slli a3, t3, 2             : IntAlu :  D=0x0000000000000014
418618000: system.cpu: T0 : 0x10598 @inner_loop+8    : c_add a3, t4               : IntAlu :  D=0x000000007ffffea0
418620000: system.cpu: T0 : 0x1059a @inner_loop+10    : c_lw a2, 0(a3)             : MemRead :  D=0x0000000000000006 A=0x7ffffea0
418624000: system.cpu: T0 : 0x1059c @inner_loop+12    : slli a5, t6, 2             : IntAlu :  D=0x000000000000000c
418626000: system.cpu: T0 : 0x105a0 @inner_loop+16    : c_add a5, t4               : IntAlu :  D=0x000000007ffffe98
418628000: system.cpu: T0 : 0x105a2 @inner_loop+18    : c_lw a4, 0(a5)             : MemRead :  D=0x0000000000000008 A=0x7ffffe98
418632000: system.cpu: T0 : 0x105a4 @inner_loop+20    : bge a4, a2, 30             : IntAlu : 
418634000: system.cpu: T0 : 0x105c2 @skip_dp_update    : c_addi t6, 1               : IntAlu :  D=0x0000000000000004
418636000: system.cpu: T0 : 0x105c4 @skip_dp_update+2    : c_j -52                    : IntAlu : 
418638000: system.cpu: T0 : 0x10590 @inner_loop    : beq t6, t3, 60             : IntAlu : 
418640000: system.cpu: T0 : 0x10594 @inner_loop+4    : slli a3, t3, 2             : IntAlu :  D=0x0000000000000014
418642000: system.cpu: T0 : 0x10598 @inner_loop+8    : c_add a3, t4               : IntAlu :  D=0x000000007ffffea0
418644000: system.cpu: T0 : 0x1059a @inner_loop+10    : c_lw a2, 0(a3)             : MemRead :  D=0x0000000000000006 A=0x7ffffea0
418648000: system.cpu: T0 : 0x1059c @inner_loop+12    : slli a5, t6, 2             : IntAlu :  D=0x0000000000000010
418650000: system.cpu: T0 : 0x105a0 @inner_loop+16    : c_add a5, t4               : IntAlu :  D=0x000000007ffffe9c
418652000: system.cpu: T0 : 0x105a2 @inner_loop+18    : c_lw a4, 0(a5)             : MemRead :  D=0x0000000000000003 A=0x7ffffe9c
418656000: system.cpu: T0 : 0x105a4 @inner_loop+20    : bge a4, a2, 30             : IntAlu : 
418658000: system.cpu: T0 : 0x105a8 @inner_loop+24    : slli a5, t6, 2             : IntAlu :  D=0x0000000000000010
418660000: system.cpu: T0 : 0x105ac @inner_loop+28    : c_add a5, t5               : IntAlu :  D=0x000000007ffffa70
418664000: system.cpu: T0 : 0x105ae @inner_loop+30    : lw a6, 0(a5)               : MemRead :  D=0x0000000000000002 A=0x7ffffa70
418668000: system.cpu: T0 : 0x105b2 @inner_loop+34    : c_addi a6, 1               : IntAlu :  D=0x0000000000000003
418670000: system.cpu: T0 : 0x105b4 @inner_loop+36    : slli a3, t3, 2             : IntAlu :  D=0x0000000000000014
418672000: system.cpu: T0 : 0x105b8 @inner_loop+40    : c_add a3, t5               : IntAlu :  D=0x000000007ffffa74
418676000: system.cpu: T0 : 0x105ba @inner_loop+42    : lw a7, 0(a3)               : MemRead :  D=0x0000000000000003 A=0x7ffffa74
418682000: system.cpu: T0 : 0x105be @inner_loop+46    : blt a7, a6, 8              : IntAlu : 
418684000: system.cpu: T0 : 0x105c2 @skip_dp_update    : c_addi t6, 1               : IntAlu :  D=0x0000000000000005
418686000: system.cpu: T0 : 0x105c4 @skip_dp_update+2    : c_j -52                    : IntAlu : 
418688000: system.cpu: T0 : 0x10590 @inner_loop    : beq t6, t3, 60             : IntAlu : 
418690000: system.cpu: T0 : 0x105cc @next_i    : c_addi t3, 1               : IntAlu :  D=0x0000000000000006
418692000: system.cpu: T0 : 0x105ce @next_i+2    : c_j -68                    : IntAlu : 
418696000: system.cpu: T0 : 0x1058a @outer_loop    : beq t3, a0, 70             : IntAlu : 
418698000: system.cpu: T0 : 0x1058e @outer_loop+4    : c_li t6, 0                 : IntAlu :  D=0x0000000000000000
418700000: system.cpu: T0 : 0x10590 @inner_loop    : beq t6, t3, 60             : IntAlu : 
418702000: system.cpu: T0 : 0x10594 @inner_loop+4    : slli a3, t3, 2             : IntAlu :  D=0x0000000000000018
418704000: system.cpu: T0 : 0x10598 @inner_loop+8    : c_add a3, t4               : IntAlu :  D=0x000000007ffffea4
418706000: system.cpu: T0 : 0x1059a @inner_loop+10    : c_lw a2, 0(a3)             : MemRead :  D=0x0000000000000009 A=0x7ffffea4
418710000: system.cpu: T0 : 0x1059c @inner_loop+12    : slli a5, t6, 2             : IntAlu :  D=0x0000000000000000
418712000: system.cpu: T0 : 0x105a0 @inner_loop+16    : c_add a5, t4               : IntAlu :  D=0x000000007ffffe8c
418714000: system.cpu: T0 : 0x105a2 @inner_loop+18    : c_lw a4, 0(a5)             : MemRead :  D=0x0000000000000004 A=0x7ffffe8c
418718000: system.cpu: T0 : 0x105a4 @inner_loop+20    : bge a4, a2, 30             : IntAlu : 
418720000: system.cpu: T0 : 0x105a8 @inner_loop+24    : slli a5, t6, 2             : IntAlu :  D=0x0000000000000000
418722000: system.cpu: T0 : 0x105ac @inner_loop+28    : c_add a5, t5               : IntAlu :  D=0x000000007ffffa60
418726000: system.cpu: T0 : 0x105ae @inner_loop+30    : lw a6, 0(a5)               : MemRead :  D=0x0000000000000001 A=0x7ffffa60
418730000: system.cpu: T0 : 0x105b2 @inner_loop+34    : c_addi a6, 1               : IntAlu :  D=0x0000000000000002
418732000: system.cpu: T0 : 0x105b4 @inner_loop+36    : slli a3, t3, 2             : IntAlu :  D=0x0000000000000018
418734000: system.cpu: T0 : 0x105b8 @inner_loop+40    : c_add a3, t5               : IntAlu :  D=0x000000007ffffa78
418738000: system.cpu: T0 : 0x105ba @inner_loop+42    : lw a7, 0(a3)               : MemRead :  D=0x0000000000000001 A=0x7ffffa78
418744000: system.cpu: T0 : 0x105be @inner_loop+46    : blt a7, a6, 8              : IntAlu : 
418748000: system.cpu: T0 : 0x105c6 @update_dp    : sw a6, 0(a3)               : MemWrite :  D=0x0000000000000002 A=0x7ffffa78
418752000: system.cpu: T0 : 0x105ca @update_dp+4    : c_j -8                     : IntAlu : 
418754000: system.cpu: T0 : 0x105c2 @skip_dp_update    : c_addi t6, 1               : IntAlu :  D=0x0000000000000001
418756000: system.cpu: T0 : 0x105c4 @skip_dp_update+2    : c_j -52                    : IntAlu : 
418758000: system.cpu: T0 : 0x10590 @inner_loop    : beq t6, t3, 60             : IntAlu : 
418760000: system.cpu: T0 : 0x10594 @inner_loop+4    : slli a3, t3, 2             : IntAlu :  D=0x0000000000000018
418762000: system.cpu: T0 : 0x10598 @inner_loop+8    : c_add a3, t4               : IntAlu :  D=0x000000007ffffea4
418764000: system.cpu: T0 : 0x1059a @inner_loop+10    : c_lw a2, 0(a3)             : MemRead :  D=0x0000000000000009 A=0x7ffffea4
418768000: system.cpu: T0 : 0x1059c @inner_loop+12    : slli a5, t6, 2             : IntAlu :  D=0x0000000000000004
418770000: system.cpu: T0 : 0x105a0 @inner_loop+16    : c_add a5, t4               : IntAlu :  D=0x000000007ffffe90
418772000: system.cpu: T0 : 0x105a2 @inner_loop+18    : c_lw a4, 0(a5)             : MemRead :  D=0x0000000000000005 A=0x7ffffe90
418776000: system.cpu: T0 : 0x105a4 @inner_loop+20    : bge a4, a2, 30             : IntAlu : 
418778000: system.cpu: T0 : 0x105a8 @inner_loop+24    : slli a5, t6, 2             : IntAlu :  D=0x0000000000000004
418780000: system.cpu: T0 : 0x105ac @inner_loop+28    : c_add a5, t5               : IntAlu :  D=0x000000007ffffa64
418784000: system.cpu: T0 : 0x105ae @inner_loop+30    : lw a6, 0(a5)               : MemRead :  D=0x0000000000000002 A=0x7ffffa64
418788000: system.cpu: T0 : 0x105b2 @inner_loop+34    : c_addi a6, 1               : IntAlu :  D=0x0000000000000003
418790000: system.cpu: T0 : 0x105b4 @inner_loop+36    : slli a3, t3, 2             : IntAlu :  D=0x0000000000000018
418792000: system.cpu: T0 : 0x105b8 @inner_loop+40    : c_add a3, t5               : IntAlu :  D=0x000000007ffffa78
418796000: system.cpu: T0 : 0x105ba @inner_loop+42    : lw a7, 0(a3)               : MemRead :  D=0x0000000000000002 A=0x7ffffa78
418802000: system.cpu: T0 : 0x105be @inner_loop+46    : blt a7, a6, 8              : IntAlu : 
418806000: system.cpu: T0 : 0x105c6 @update_dp    : sw a6, 0(a3)               : MemWrite :  D=0x0000000000000003 A=0x7ffffa78
418810000: system.cpu: T0 : 0x105ca @update_dp+4    : c_j -8                     : IntAlu : 
418812000: system.cpu: T0 : 0x105c2 @skip_dp_update    : c_addi t6, 1               : IntAlu :  D=0x0000000000000002
418814000: system.cpu: T0 : 0x105c4 @skip_dp_update+2    : c_j -52                    : IntAlu : 
418816000: system.cpu: T0 : 0x10590 @inner_loop    : beq t6, t3, 60             : IntAlu : 
418818000: system.cpu: T0 : 0x10594 @inner_loop+4    : slli a3, t3, 2             : IntAlu :  D=0x0000000000000018
418820000: system.cpu: T0 : 0x10598 @inner_loop+8    : c_add a3, t4               : IntAlu :  D=0x000000007ffffea4
418822000: system.cpu: T0 : 0x1059a @inner_loop+10    : c_lw a2, 0(a3)             : MemRead :  D=0x0000000000000009 A=0x7ffffea4
418826000: system.cpu: T0 : 0x1059c @inner_loop+12    : slli a5, t6, 2             : IntAlu :  D=0x0000000000000008
418828000: system.cpu: T0 : 0x105a0 @inner_loop+16    : c_add a5, t4               : IntAlu :  D=0x000000007ffffe94
418830000: system.cpu: T0 : 0x105a2 @inner_loop+18    : c_lw a4, 0(a5)             : MemRead :  D=0x0000000000000001 A=0x7ffffe94
418834000: system.cpu: T0 : 0x105a4 @inner_loop+20    : bge a4, a2, 30             : IntAlu : 
418836000: system.cpu: T0 : 0x105a8 @inner_loop+24    : slli a5, t6, 2             : IntAlu :  D=0x0000000000000008
418838000: system.cpu: T0 : 0x105ac @inner_loop+28    : c_add a5, t5               : IntAlu :  D=0x000000007ffffa68
418842000: system.cpu: T0 : 0x105ae @inner_loop+30    : lw a6, 0(a5)               : MemRead :  D=0x0000000000000001 A=0x7ffffa68
418846000: system.cpu: T0 : 0x105b2 @inner_loop+34    : c_addi a6, 1               : IntAlu :  D=0x0000000000000002
418848000: system.cpu: T0 : 0x105b4 @inner_loop+36    : slli a3, t3, 2             : IntAlu :  D=0x0000000000000018
418850000: system.cpu: T0 : 0x105b8 @inner_loop+40    : c_add a3, t5               : IntAlu :  D=0x000000007ffffa78
418854000: system.cpu: T0 : 0x105ba @inner_loop+42    : lw a7, 0(a3)               : MemRead :  D=0x0000000000000003 A=0x7ffffa78
418860000: system.cpu: T0 : 0x105be @inner_loop+46    : blt a7, a6, 8              : IntAlu : 
418862000: system.cpu: T0 : 0x105c2 @skip_dp_update    : c_addi t6, 1               : IntAlu :  D=0x0000000000000003
418864000: system.cpu: T0 : 0x105c4 @skip_dp_update+2    : c_j -52                    : IntAlu : 
418866000: system.cpu: T0 : 0x10590 @inner_loop    : beq t6, t3, 60             : IntAlu : 
418868000: system.cpu: T0 : 0x10594 @inner_loop+4    : slli a3, t3, 2             : IntAlu :  D=0x0000000000000018
418870000: system.cpu: T0 : 0x10598 @inner_loop+8    : c_add a3, t4               : IntAlu :  D=0x000000007ffffea4
418872000: system.cpu: T0 : 0x1059a @inner_loop+10    : c_lw a2, 0(a3)             : MemRead :  D=0x0000000000000009 A=0x7ffffea4
418876000: system.cpu: T0 : 0x1059c @inner_loop+12    : slli a5, t6, 2             : IntAlu :  D=0x000000000000000c
418878000: system.cpu: T0 : 0x105a0 @inner_loop+16    : c_add a5, t4               : IntAlu :  D=0x000000007ffffe98
418880000: system.cpu: T0 : 0x105a2 @inner_loop+18    : c_lw a4, 0(a5)             : MemRead :  D=0x0000000000000008 A=0x7ffffe98
418884000: system.cpu: T0 : 0x105a4 @inner_loop+20    : bge a4, a2, 30             : IntAlu : 
418886000: system.cpu: T0 : 0x105a8 @inner_loop+24    : slli a5, t6, 2             : IntAlu :  D=0x000000000000000c
418888000: system.cpu: T0 : 0x105ac @inner_loop+28    : c_add a5, t5               : IntAlu :  D=0x000000007ffffa6c
418892000: system.cpu: T0 : 0x105ae @inner_loop+30    : lw a6, 0(a5)               : MemRead :  D=0x0000000000000003 A=0x7ffffa6c
418896000: system.cpu: T0 : 0x105b2 @inner_loop+34    : c_addi a6, 1               : IntAlu :  D=0x0000000000000004
418898000: system.cpu: T0 : 0x105b4 @inner_loop+36    : slli a3, t3, 2             : IntAlu :  D=0x0000000000000018
418900000: system.cpu: T0 : 0x105b8 @inner_loop+40    : c_add a3, t5               : IntAlu :  D=0x000000007ffffa78
418904000: system.cpu: T0 : 0x105ba @inner_loop+42    : lw a7, 0(a3)               : MemRead :  D=0x0000000000000003 A=0x7ffffa78
418910000: system.cpu: T0 : 0x105be @inner_loop+46    : blt a7, a6, 8              : IntAlu : 
418914000: system.cpu: T0 : 0x105c6 @update_dp    : sw a6, 0(a3)               : MemWrite :  D=0x0000000000000004 A=0x7ffffa78
418918000: system.cpu: T0 : 0x105ca @update_dp+4    : c_j -8                     : IntAlu : 
418920000: system.cpu: T0 : 0x105c2 @skip_dp_update    : c_addi t6, 1               : IntAlu :  D=0x0000000000000004
418922000: system.cpu: T0 : 0x105c4 @skip_dp_update+2    : c_j -52                    : IntAlu : 
418924000: system.cpu: T0 : 0x10590 @inner_loop    : beq t6, t3, 60             : IntAlu : 
418926000: system.cpu: T0 : 0x10594 @inner_loop+4    : slli a3, t3, 2             : IntAlu :  D=0x0000000000000018
418928000: system.cpu: T0 : 0x10598 @inner_loop+8    : c_add a3, t4               : IntAlu :  D=0x000000007ffffea4
418930000: system.cpu: T0 : 0x1059a @inner_loop+10    : c_lw a2, 0(a3)             : MemRead :  D=0x0000000000000009 A=0x7ffffea4
418934000: system.cpu: T0 : 0x1059c @inner_loop+12    : slli a5, t6, 2             : IntAlu :  D=0x0000000000000010
418936000: system.cpu: T0 : 0x105a0 @inner_loop+16    : c_add a5, t4               : IntAlu :  D=0x000000007ffffe9c
418938000: system.cpu: T0 : 0x105a2 @inner_loop+18    : c_lw a4, 0(a5)             : MemRead :  D=0x0000000000000003 A=0x7ffffe9c
418942000: system.cpu: T0 : 0x105a4 @inner_loop+20    : bge a4, a2, 30             : IntAlu : 
418944000: system.cpu: T0 : 0x105a8 @inner_loop+24    : slli a5, t6, 2             : IntAlu :  D=0x0000000000000010
418946000: system.cpu: T0 : 0x105ac @inner_loop+28    : c_add a5, t5               : IntAlu :  D=0x000000007ffffa70
418950000: system.cpu: T0 : 0x105ae @inner_loop+30    : lw a6, 0(a5)               : MemRead :  D=0x0000000000000002 A=0x7ffffa70
418954000: system.cpu: T0 : 0x105b2 @inner_loop+34    : c_addi a6, 1               : IntAlu :  D=0x0000000000000003
418956000: system.cpu: T0 : 0x105b4 @inner_loop+36    : slli a3, t3, 2             : IntAlu :  D=0x0000000000000018
418958000: system.cpu: T0 : 0x105b8 @inner_loop+40    : c_add a3, t5               : IntAlu :  D=0x000000007ffffa78
418962000: system.cpu: T0 : 0x105ba @inner_loop+42    : lw a7, 0(a3)               : MemRead :  D=0x0000000000000004 A=0x7ffffa78
418968000: system.cpu: T0 : 0x105be @inner_loop+46    : blt a7, a6, 8              : IntAlu : 
418970000: system.cpu: T0 : 0x105c2 @skip_dp_update    : c_addi t6, 1               : IntAlu :  D=0x0000000000000005
418972000: system.cpu: T0 : 0x105c4 @skip_dp_update+2    : c_j -52                    : IntAlu : 
418974000: system.cpu: T0 : 0x10590 @inner_loop    : beq t6, t3, 60             : IntAlu : 
418976000: system.cpu: T0 : 0x10594 @inner_loop+4    : slli a3, t3, 2             : IntAlu :  D=0x0000000000000018
418978000: system.cpu: T0 : 0x10598 @inner_loop+8    : c_add a3, t4               : IntAlu :  D=0x000000007ffffea4
418980000: system.cpu: T0 : 0x1059a @inner_loop+10    : c_lw a2, 0(a3)             : MemRead :  D=0x0000000000000009 A=0x7ffffea4
418984000: system.cpu: T0 : 0x1059c @inner_loop+12    : slli a5, t6, 2             : IntAlu :  D=0x0000000000000014
418986000: system.cpu: T0 : 0x105a0 @inner_loop+16    : c_add a5, t4               : IntAlu :  D=0x000000007ffffea0
418988000: system.cpu: T0 : 0x105a2 @inner_loop+18    : c_lw a4, 0(a5)             : MemRead :  D=0x0000000000000006 A=0x7ffffea0
418992000: system.cpu: T0 : 0x105a4 @inner_loop+20    : bge a4, a2, 30             : IntAlu : 
418994000: system.cpu: T0 : 0x105a8 @inner_loop+24    : slli a5, t6, 2             : IntAlu :  D=0x0000000000000014
418996000: system.cpu: T0 : 0x105ac @inner_loop+28    : c_add a5, t5               : IntAlu :  D=0x000000007ffffa74
419000000: system.cpu: T0 : 0x105ae @inner_loop+30    : lw a6, 0(a5)               : MemRead :  D=0x0000000000000003 A=0x7ffffa74
419004000: system.cpu: T0 : 0x105b2 @inner_loop+34    : c_addi a6, 1               : IntAlu :  D=0x0000000000000004
419006000: system.cpu: T0 : 0x105b4 @inner_loop+36    : slli a3, t3, 2             : IntAlu :  D=0x0000000000000018
419008000: system.cpu: T0 : 0x105b8 @inner_loop+40    : c_add a3, t5               : IntAlu :  D=0x000000007ffffa78
419012000: system.cpu: T0 : 0x105ba @inner_loop+42    : lw a7, 0(a3)               : MemRead :  D=0x0000000000000004 A=0x7ffffa78
419018000: system.cpu: T0 : 0x105be @inner_loop+46    : blt a7, a6, 8              : IntAlu : 
419020000: system.cpu: T0 : 0x105c2 @skip_dp_update    : c_addi t6, 1               : IntAlu :  D=0x0000000000000006
419022000: system.cpu: T0 : 0x105c4 @skip_dp_update+2    : c_j -52                    : IntAlu : 
419024000: system.cpu: T0 : 0x10590 @inner_loop    : beq t6, t3, 60             : IntAlu : 
419026000: system.cpu: T0 : 0x105cc @next_i    : c_addi t3, 1               : IntAlu :  D=0x0000000000000007
419028000: system.cpu: T0 : 0x105ce @next_i+2    : c_j -68                    : IntAlu : 
419032000: system.cpu: T0 : 0x1058a @outer_loop    : beq t3, a0, 70             : IntAlu : 
419034000: system.cpu: T0 : 0x1058e @outer_loop+4    : c_li t6, 0                 : IntAlu :  D=0x0000000000000000
419036000: system.cpu: T0 : 0x10590 @inner_loop    : beq t6, t3, 60             : IntAlu : 
419038000: system.cpu: T0 : 0x10594 @inner_loop+4    : slli a3, t3, 2             : IntAlu :  D=0x000000000000001c
419040000: system.cpu: T0 : 0x10598 @inner_loop+8    : c_add a3, t4               : IntAlu :  D=0x000000007ffffea8
419042000: system.cpu: T0 : 0x1059a @inner_loop+10    : c_lw a2, 0(a3)             : MemRead :  D=0x0000000000000002 A=0x7ffffea8
419046000: system.cpu: T0 : 0x1059c @inner_loop+12    : slli a5, t6, 2             : IntAlu :  D=0x0000000000000000
419048000: system.cpu: T0 : 0x105a0 @inner_loop+16    : c_add a5, t4               : IntAlu :  D=0x000000007ffffe8c
419050000: system.cpu: T0 : 0x105a2 @inner_loop+18    : c_lw a4, 0(a5)             : MemRead :  D=0x0000000000000004 A=0x7ffffe8c
419054000: system.cpu: T0 : 0x105a4 @inner_loop+20    : bge a4, a2, 30             : IntAlu : 
419056000: system.cpu: T0 : 0x105c2 @skip_dp_update    : c_addi t6, 1               : IntAlu :  D=0x0000000000000001
419058000: system.cpu: T0 : 0x105c4 @skip_dp_update+2    : c_j -52                    : IntAlu : 
419060000: system.cpu: T0 : 0x10590 @inner_loop    : beq t6, t3, 60             : IntAlu : 
419062000: system.cpu: T0 : 0x10594 @inner_loop+4    : slli a3, t3, 2             : IntAlu :  D=0x000000000000001c
419064000: system.cpu: T0 : 0x10598 @inner_loop+8    : c_add a3, t4               : IntAlu :  D=0x000000007ffffea8
419066000: system.cpu: T0 : 0x1059a @inner_loop+10    : c_lw a2, 0(a3)             : MemRead :  D=0x0000000000000002 A=0x7ffffea8
419070000: system.cpu: T0 : 0x1059c @inner_loop+12    : slli a5, t6, 2             : IntAlu :  D=0x0000000000000004
419072000: system.cpu: T0 : 0x105a0 @inner_loop+16    : c_add a5, t4               : IntAlu :  D=0x000000007ffffe90
419074000: system.cpu: T0 : 0x105a2 @inner_loop+18    : c_lw a4, 0(a5)             : MemRead :  D=0x0000000000000005 A=0x7ffffe90
419078000: system.cpu: T0 : 0x105a4 @inner_loop+20    : bge a4, a2, 30             : IntAlu : 
419080000: system.cpu: T0 : 0x105c2 @skip_dp_update    : c_addi t6, 1               : IntAlu :  D=0x0000000000000002
419082000: system.cpu: T0 : 0x105c4 @skip_dp_update+2    : c_j -52                    : IntAlu : 
419084000: system.cpu: T0 : 0x10590 @inner_loop    : beq t6, t3, 60             : IntAlu : 
419086000: system.cpu: T0 : 0x10594 @inner_loop+4    : slli a3, t3, 2             : IntAlu :  D=0x000000000000001c
419088000: system.cpu: T0 : 0x10598 @inner_loop+8    : c_add a3, t4               : IntAlu :  D=0x000000007ffffea8
419090000: system.cpu: T0 : 0x1059a @inner_loop+10    : c_lw a2, 0(a3)             : MemRead :  D=0x0000000000000002 A=0x7ffffea8
419094000: system.cpu: T0 : 0x1059c @inner_loop+12    : slli a5, t6, 2             : IntAlu :  D=0x0000000000000008
419096000: system.cpu: T0 : 0x105a0 @inner_loop+16    : c_add a5, t4               : IntAlu :  D=0x000000007ffffe94
419098000: system.cpu: T0 : 0x105a2 @inner_loop+18    : c_lw a4, 0(a5)             : MemRead :  D=0x0000000000000001 A=0x7ffffe94
419102000: system.cpu: T0 : 0x105a4 @inner_loop+20    : bge a4, a2, 30             : IntAlu : 
419104000: system.cpu: T0 : 0x105a8 @inner_loop+24    : slli a5, t6, 2             : IntAlu :  D=0x0000000000000008
419106000: system.cpu: T0 : 0x105ac @inner_loop+28    : c_add a5, t5               : IntAlu :  D=0x000000007ffffa68
419110000: system.cpu: T0 : 0x105ae @inner_loop+30    : lw a6, 0(a5)               : MemRead :  D=0x0000000000000001 A=0x7ffffa68
419114000: system.cpu: T0 : 0x105b2 @inner_loop+34    : c_addi a6, 1               : IntAlu :  D=0x0000000000000002
419116000: system.cpu: T0 : 0x105b4 @inner_loop+36    : slli a3, t3, 2             : IntAlu :  D=0x000000000000001c
419118000: system.cpu: T0 : 0x105b8 @inner_loop+40    : c_add a3, t5               : IntAlu :  D=0x000000007ffffa7c
419122000: system.cpu: T0 : 0x105ba @inner_loop+42    : lw a7, 0(a3)               : MemRead :  D=0x0000000000000001 A=0x7ffffa7c
419128000: system.cpu: T0 : 0x105be @inner_loop+46    : blt a7, a6, 8              : IntAlu : 
419132000: system.cpu: T0 : 0x105c6 @update_dp    : sw a6, 0(a3)               : MemWrite :  D=0x0000000000000002 A=0x7ffffa7c
419136000: system.cpu: T0 : 0x105ca @update_dp+4    : c_j -8                     : IntAlu : 
419138000: system.cpu: T0 : 0x105c2 @skip_dp_update    : c_addi t6, 1               : IntAlu :  D=0x0000000000000003
419140000: system.cpu: T0 : 0x105c4 @skip_dp_update+2    : c_j -52                    : IntAlu : 
419142000: system.cpu: T0 : 0x10590 @inner_loop    : beq t6, t3, 60             : IntAlu : 
419144000: system.cpu: T0 : 0x10594 @inner_loop+4    : slli a3, t3, 2             : IntAlu :  D=0x000000000000001c
419146000: system.cpu: T0 : 0x10598 @inner_loop+8    : c_add a3, t4               : IntAlu :  D=0x000000007ffffea8
419148000: system.cpu: T0 : 0x1059a @inner_loop+10    : c_lw a2, 0(a3)             : MemRead :  D=0x0000000000000002 A=0x7ffffea8
419152000: system.cpu: T0 : 0x1059c @inner_loop+12    : slli a5, t6, 2             : IntAlu :  D=0x000000000000000c
419154000: system.cpu: T0 : 0x105a0 @inner_loop+16    : c_add a5, t4               : IntAlu :  D=0x000000007ffffe98
419156000: system.cpu: T0 : 0x105a2 @inner_loop+18    : c_lw a4, 0(a5)             : MemRead :  D=0x0000000000000008 A=0x7ffffe98
419160000: system.cpu: T0 : 0x105a4 @inner_loop+20    : bge a4, a2, 30             : IntAlu : 
419162000: system.cpu: T0 : 0x105c2 @skip_dp_update    : c_addi t6, 1               : IntAlu :  D=0x0000000000000004
419164000: system.cpu: T0 : 0x105c4 @skip_dp_update+2    : c_j -52                    : IntAlu : 
419166000: system.cpu: T0 : 0x10590 @inner_loop    : beq t6, t3, 60             : IntAlu : 
419168000: system.cpu: T0 : 0x10594 @inner_loop+4    : slli a3, t3, 2             : IntAlu :  D=0x000000000000001c
419170000: system.cpu: T0 : 0x10598 @inner_loop+8    : c_add a3, t4               : IntAlu :  D=0x000000007ffffea8
419172000: system.cpu: T0 : 0x1059a @inner_loop+10    : c_lw a2, 0(a3)             : MemRead :  D=0x0000000000000002 A=0x7ffffea8
419176000: system.cpu: T0 : 0x1059c @inner_loop+12    : slli a5, t6, 2             : IntAlu :  D=0x0000000000000010
419178000: system.cpu: T0 : 0x105a0 @inner_loop+16    : c_add a5, t4               : IntAlu :  D=0x000000007ffffe9c
419180000: system.cpu: T0 : 0x105a2 @inner_loop+18    : c_lw a4, 0(a5)             : MemRead :  D=0x0000000000000003 A=0x7ffffe9c
419184000: system.cpu: T0 : 0x105a4 @inner_loop+20    : bge a4, a2, 30             : IntAlu : 
419186000: system.cpu: T0 : 0x105c2 @skip_dp_update    : c_addi t6, 1               : IntAlu :  D=0x0000000000000005
419188000: system.cpu: T0 : 0x105c4 @skip_dp_update+2    : c_j -52                    : IntAlu : 
419190000: system.cpu: T0 : 0x10590 @inner_loop    : beq t6, t3, 60             : IntAlu : 
419192000: system.cpu: T0 : 0x10594 @inner_loop+4    : slli a3, t3, 2             : IntAlu :  D=0x000000000000001c
419194000: system.cpu: T0 : 0x10598 @inner_loop+8    : c_add a3, t4               : IntAlu :  D=0x000000007ffffea8
419196000: system.cpu: T0 : 0x1059a @inner_loop+10    : c_lw a2, 0(a3)             : MemRead :  D=0x0000000000000002 A=0x7ffffea8
419200000: system.cpu: T0 : 0x1059c @inner_loop+12    : slli a5, t6, 2             : IntAlu :  D=0x0000000000000014
419202000: system.cpu: T0 : 0x105a0 @inner_loop+16    : c_add a5, t4               : IntAlu :  D=0x000000007ffffea0
419204000: system.cpu: T0 : 0x105a2 @inner_loop+18    : c_lw a4, 0(a5)             : MemRead :  D=0x0000000000000006 A=0x7ffffea0
419208000: system.cpu: T0 : 0x105a4 @inner_loop+20    : bge a4, a2, 30             : IntAlu : 
419210000: system.cpu: T0 : 0x105c2 @skip_dp_update    : c_addi t6, 1               : IntAlu :  D=0x0000000000000006
419212000: system.cpu: T0 : 0x105c4 @skip_dp_update+2    : c_j -52                    : IntAlu : 
419214000: system.cpu: T0 : 0x10590 @inner_loop    : beq t6, t3, 60             : IntAlu : 
419216000: system.cpu: T0 : 0x10594 @inner_loop+4    : slli a3, t3, 2             : IntAlu :  D=0x000000000000001c
419218000: system.cpu: T0 : 0x10598 @inner_loop+8    : c_add a3, t4               : IntAlu :  D=0x000000007ffffea8
419220000: system.cpu: T0 : 0x1059a @inner_loop+10    : c_lw a2, 0(a3)             : MemRead :  D=0x0000000000000002 A=0x7ffffea8
419224000: system.cpu: T0 : 0x1059c @inner_loop+12    : slli a5, t6, 2             : IntAlu :  D=0x0000000000000018
419226000: system.cpu: T0 : 0x105a0 @inner_loop+16    : c_add a5, t4               : IntAlu :  D=0x000000007ffffea4
419228000: system.cpu: T0 : 0x105a2 @inner_loop+18    : c_lw a4, 0(a5)             : MemRead :  D=0x0000000000000009 A=0x7ffffea4
419232000: system.cpu: T0 : 0x105a4 @inner_loop+20    : bge a4, a2, 30             : IntAlu : 
419234000: system.cpu: T0 : 0x105c2 @skip_dp_update    : c_addi t6, 1               : IntAlu :  D=0x0000000000000007
419236000: system.cpu: T0 : 0x105c4 @skip_dp_update+2    : c_j -52                    : IntAlu : 
419238000: system.cpu: T0 : 0x10590 @inner_loop    : beq t6, t3, 60             : IntAlu : 
419240000: system.cpu: T0 : 0x105cc @next_i    : c_addi t3, 1               : IntAlu :  D=0x0000000000000008
419242000: system.cpu: T0 : 0x105ce @next_i+2    : c_j -68                    : IntAlu : 
419246000: system.cpu: T0 : 0x1058a @outer_loop    : beq t3, a0, 70             : IntAlu : 
419248000: system.cpu: T0 : 0x105d0 @find_max_dp    : c_li t3, 0                 : IntAlu :  D=0x0000000000000000
419250000: system.cpu: T0 : 0x105d2 @find_max_dp+2    : c_mv t6, a0                : IntAlu :  D=0x0000000000000008
419252000: system.cpu: T0 : 0x105d4 @find_max_dp+4    : lw a0, 0(t5)               : MemRead :  D=0x0000000000000001 A=0x7ffffa60
419256000: system.cpu: T0 : 0x105d8 @find_max_loop    : beq t3, t6, 24             : IntAlu : 
419258000: system.cpu: T0 : 0x105dc @find_max_loop+4    : slli a3, t3, 2             : IntAlu :  D=0x0000000000000000
419260000: system.cpu: T0 : 0x105e0 @find_max_loop+8    : c_add a3, t5               : IntAlu :  D=0x000000007ffffa60
419262000: system.cpu: T0 : 0x105e2 @find_max_loop+10    : c_lw a4, 0(a3)             : MemRead :  D=0x0000000000000001 A=0x7ffffa60
419266000: system.cpu: T0 : 0x105e4 @find_max_loop+12    : blt a0, a4, 8              : IntAlu : 
419268000: system.cpu: T0 : 0x105e8 @find_max_loop+16    : c_addi t3, 1               : IntAlu :  D=0x0000000000000001
419270000: system.cpu: T0 : 0x105ea @find_max_loop+18    : c_j -18                    : IntAlu : 
419272000: system.cpu: T0 : 0x105d8 @find_max_loop    : beq t3, t6, 24             : IntAlu : 
419274000: system.cpu: T0 : 0x105dc @find_max_loop+4    : slli a3, t3, 2             : IntAlu :  D=0x0000000000000004
419276000: system.cpu: T0 : 0x105e0 @find_max_loop+8    : c_add a3, t5               : IntAlu :  D=0x000000007ffffa64
419278000: system.cpu: T0 : 0x105e2 @find_max_loop+10    : c_lw a4, 0(a3)             : MemRead :  D=0x0000000000000002 A=0x7ffffa64
419282000: system.cpu: T0 : 0x105e4 @find_max_loop+12    : blt a0, a4, 8              : IntAlu : 
419284000: system.cpu: T0 : 0x105ec @update_max    : c_mv a0, a4                : IntAlu :  D=0x0000000000000002
419286000: system.cpu: T0 : 0x105ee @update_max+2    : c_j -22                    : IntAlu : 
419288000: system.cpu: T0 : 0x105d8 @find_max_loop    : beq t3, t6, 24             : IntAlu : 
419290000: system.cpu: T0 : 0x105dc @find_max_loop+4    : slli a3, t3, 2             : IntAlu :  D=0x0000000000000004
419292000: system.cpu: T0 : 0x105e0 @find_max_loop+8    : c_add a3, t5               : IntAlu :  D=0x000000007ffffa64
419294000: system.cpu: T0 : 0x105e2 @find_max_loop+10    : c_lw a4, 0(a3)             : MemRead :  D=0x0000000000000002 A=0x7ffffa64
419298000: system.cpu: T0 : 0x105e4 @find_max_loop+12    : blt a0, a4, 8              : IntAlu : 
419300000: system.cpu: T0 : 0x105e8 @find_max_loop+16    : c_addi t3, 1               : IntAlu :  D=0x0000000000000002
419302000: system.cpu: T0 : 0x105ea @find_max_loop+18    : c_j -18                    : IntAlu : 
419304000: system.cpu: T0 : 0x105d8 @find_max_loop    : beq t3, t6, 24             : IntAlu : 
419306000: system.cpu: T0 : 0x105dc @find_max_loop+4    : slli a3, t3, 2             : IntAlu :  D=0x0000000000000008
419308000: system.cpu: T0 : 0x105e0 @find_max_loop+8    : c_add a3, t5               : IntAlu :  D=0x000000007ffffa68
419310000: system.cpu: T0 : 0x105e2 @find_max_loop+10    : c_lw a4, 0(a3)             : MemRead :  D=0x0000000000000001 A=0x7ffffa68
419314000: system.cpu: T0 : 0x105e4 @find_max_loop+12    : blt a0, a4, 8              : IntAlu : 
419316000: system.cpu: T0 : 0x105e8 @find_max_loop+16    : c_addi t3, 1               : IntAlu :  D=0x0000000000000003
419318000: system.cpu: T0 : 0x105ea @find_max_loop+18    : c_j -18                    : IntAlu : 
419320000: system.cpu: T0 : 0x105d8 @find_max_loop    : beq t3, t6, 24             : IntAlu : 
419322000: system.cpu: T0 : 0x105dc @find_max_loop+4    : slli a3, t3, 2             : IntAlu :  D=0x000000000000000c
419324000: system.cpu: T0 : 0x105e0 @find_max_loop+8    : c_add a3, t5               : IntAlu :  D=0x000000007ffffa6c
419326000: system.cpu: T0 : 0x105e2 @find_max_loop+10    : c_lw a4, 0(a3)             : MemRead :  D=0x0000000000000003 A=0x7ffffa6c
419330000: system.cpu: T0 : 0x105e4 @find_max_loop+12    : blt a0, a4, 8              : IntAlu : 
419332000: system.cpu: T0 : 0x105ec @update_max    : c_mv a0, a4                : IntAlu :  D=0x0000000000000003
419334000: system.cpu: T0 : 0x105ee @update_max+2    : c_j -22                    : IntAlu : 
419336000: system.cpu: T0 : 0x105d8 @find_max_loop    : beq t3, t6, 24             : IntAlu : 
419338000: system.cpu: T0 : 0x105dc @find_max_loop+4    : slli a3, t3, 2             : IntAlu :  D=0x000000000000000c
419340000: system.cpu: T0 : 0x105e0 @find_max_loop+8    : c_add a3, t5               : IntAlu :  D=0x000000007ffffa6c
419342000: system.cpu: T0 : 0x105e2 @find_max_loop+10    : c_lw a4, 0(a3)             : MemRead :  D=0x0000000000000003 A=0x7ffffa6c
419346000: system.cpu: T0 : 0x105e4 @find_max_loop+12    : blt a0, a4, 8              : IntAlu : 
419348000: system.cpu: T0 : 0x105e8 @find_max_loop+16    : c_addi t3, 1               : IntAlu :  D=0x0000000000000004
419350000: system.cpu: T0 : 0x105ea @find_max_loop+18    : c_j -18                    : IntAlu : 
419352000: system.cpu: T0 : 0x105d8 @find_max_loop    : beq t3, t6, 24             : IntAlu : 
419354000: system.cpu: T0 : 0x105dc @find_max_loop+4    : slli a3, t3, 2             : IntAlu :  D=0x0000000000000010
419356000: system.cpu: T0 : 0x105e0 @find_max_loop+8    : c_add a3, t5               : IntAlu :  D=0x000000007ffffa70
419358000: system.cpu: T0 : 0x105e2 @find_max_loop+10    : c_lw a4, 0(a3)             : MemRead :  D=0x0000000000000002 A=0x7ffffa70
419362000: system.cpu: T0 : 0x105e4 @find_max_loop+12    : blt a0, a4, 8              : IntAlu : 
419364000: system.cpu: T0 : 0x105e8 @find_max_loop+16    : c_addi t3, 1               : IntAlu :  D=0x0000000000000005
419366000: system.cpu: T0 : 0x105ea @find_max_loop+18    : c_j -18                    : IntAlu : 
419368000: system.cpu: T0 : 0x105d8 @find_max_loop    : beq t3, t6, 24             : IntAlu : 
419370000: system.cpu: T0 : 0x105dc @find_max_loop+4    : slli a3, t3, 2             : IntAlu :  D=0x0000000000000014
419372000: system.cpu: T0 : 0x105e0 @find_max_loop+8    : c_add a3, t5               : IntAlu :  D=0x000000007ffffa74
419374000: system.cpu: T0 : 0x105e2 @find_max_loop+10    : c_lw a4, 0(a3)             : MemRead :  D=0x0000000000000003 A=0x7ffffa74
419378000: system.cpu: T0 : 0x105e4 @find_max_loop+12    : blt a0, a4, 8              : IntAlu : 
419380000: system.cpu: T0 : 0x105e8 @find_max_loop+16    : c_addi t3, 1               : IntAlu :  D=0x0000000000000006
419382000: system.cpu: T0 : 0x105ea @find_max_loop+18    : c_j -18                    : IntAlu : 
419384000: system.cpu: T0 : 0x105d8 @find_max_loop    : beq t3, t6, 24             : IntAlu : 
419386000: system.cpu: T0 : 0x105dc @find_max_loop+4    : slli a3, t3, 2             : IntAlu :  D=0x0000000000000018
419388000: system.cpu: T0 : 0x105e0 @find_max_loop+8    : c_add a3, t5               : IntAlu :  D=0x000000007ffffa78
419390000: system.cpu: T0 : 0x105e2 @find_max_loop+10    : c_lw a4, 0(a3)             : MemRead :  D=0x0000000000000004 A=0x7ffffa78
419394000: system.cpu: T0 : 0x105e4 @find_max_loop+12    : blt a0, a4, 8              : IntAlu : 
419396000: system.cpu: T0 : 0x105ec @update_max    : c_mv a0, a4                : IntAlu :  D=0x0000000000000004
419398000: system.cpu: T0 : 0x105ee @update_max+2    : c_j -22                    : IntAlu : 
419400000: system.cpu: T0 : 0x105d8 @find_max_loop    : beq t3, t6, 24             : IntAlu : 
419402000: system.cpu: T0 : 0x105dc @find_max_loop+4    : slli a3, t3, 2             : IntAlu :  D=0x0000000000000018
419404000: system.cpu: T0 : 0x105e0 @find_max_loop+8    : c_add a3, t5               : IntAlu :  D=0x000000007ffffa78
419406000: system.cpu: T0 : 0x105e2 @find_max_loop+10    : c_lw a4, 0(a3)             : MemRead :  D=0x0000000000000004 A=0x7ffffa78
419410000: system.cpu: T0 : 0x105e4 @find_max_loop+12    : blt a0, a4, 8              : IntAlu : 
419412000: system.cpu: T0 : 0x105e8 @find_max_loop+16    : c_addi t3, 1               : IntAlu :  D=0x0000000000000007
419414000: system.cpu: T0 : 0x105ea @find_max_loop+18    : c_j -18                    : IntAlu : 
419416000: system.cpu: T0 : 0x105d8 @find_max_loop    : beq t3, t6, 24             : IntAlu : 
419418000: system.cpu: T0 : 0x105dc @find_max_loop+4    : slli a3, t3, 2             : IntAlu :  D=0x000000000000001c
419420000: system.cpu: T0 : 0x105e0 @find_max_loop+8    : c_add a3, t5               : IntAlu :  D=0x000000007ffffa7c
419422000: system.cpu: T0 : 0x105e2 @find_max_loop+10    : c_lw a4, 0(a3)             : MemRead :  D=0x0000000000000002 A=0x7ffffa7c
419426000: system.cpu: T0 : 0x105e4 @find_max_loop+12    : blt a0, a4, 8              : IntAlu : 
419428000: system.cpu: T0 : 0x105e8 @find_max_loop+16    : c_addi t3, 1               : IntAlu :  D=0x0000000000000008
419430000: system.cpu: T0 : 0x105ea @find_max_loop+18    : c_j -18                    : IntAlu : 
419432000: system.cpu: T0 : 0x105d8 @find_max_loop    : beq t3, t6, 24             : IntAlu : 
419434000: system.cpu: T0 : 0x105f0 @exit    : c_jr ra                    : IntAlu : 
419436000: system.cpu: T0 : 0x10512 @main+222    : c_mv a5, a0                : IntAlu :  D=0x0000000000000004
419438000: system.cpu: T0 : 0x10514 @main+224    : sw a5, -32(s0)             : MemWrite :  D=0x0000000000000004 A=0x7ffffeb0
419442000: system.cpu: T0 : 0x10518 @main+228    : addi a4, s0, -1092         : IntAlu :  D=0x000000007ffffa8c
419444000: system.cpu: T0 : 0x1051c @main+232    : lw a3, -32(s0)             : MemRead :  D=0x0000000000000004 A=0x7ffffeb0
419448000: system.cpu: T0 : 0x10520 @main+236    : lui a5, 79                 : IntAlu :  D=0x000000000004f000
419450000: system.cpu: T0 : 0x10524 @main+240    : addi a2, a5, -1876         : IntAlu :  D=0x000000000004e8ac
419452000: system.cpu: T0 : 0x10528 @main+244    : addi a1, zero, 1024        : IntAlu :  D=0x0000000000000400
419454000: system.cpu: T0 : 0x1052c @main+248    : c_mv a0, a4                : IntAlu :  D=0x000000007ffffa8c
419458000: system.cpu: T0 : 0x1052e @main+250    : jal ra, 2232               : IntAlu :  D=0x0000000000010532
*/