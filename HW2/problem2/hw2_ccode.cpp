
#include <unistd.h>
#include <cstdio>


int LIS(int n, int* arr, int* dp) {
    if (n == 0) return 0;  // Return 0 for an empty array

    int maxLength = 1;  // The longest increasing subsequence is at least 1 (single element)
    
    // Initialize dp array: each element can form an LIS of at least length 1
    for (int i = 0; i < n; i++) {
        dp[i] = 1;
    }

    // Compute LIS
    for (int i = 1; i < n; i++) {
        for (int j = 0; j < i; j++) {
            if (arr[i] > arr[j]) {  // Only update if arr[i] > arr[j]
                // Manually compute max(dp[i], dp[j] + 1)
                int newLength = dp[j] + 1;
                if (newLength > dp[i]) {
                    dp[i] = newLength;
                }
            }
        }
        // Update maxLength to keep track of the maximum LIS found so far
        if (dp[i] > maxLength) {
            maxLength = dp[i];
        }
    }

    return maxLength;
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

// 5177

/*
417155000: system.cpu: T0 : 0x10550 @main    : addi sp, sp, -1104         : IntAlu :  D=0x000000007ffffa80
417157000: system.cpu: T0 : 0x10554 @main+4    : sw ra, 1100(sp)            : MemWrite :  D=0x00000000000106f8 A=0x7ffffecc
417161000: system.cpu: T0 : 0x10558 @main+8    : sw s0, 1096(sp)            : MemWrite :  D=0x0000000000077b68 A=0x7ffffec8
417165000: system.cpu: T0 : 0x1055c @main+12    : sw s1, 1092(sp)            : MemWrite :  D=0x0000000000000002 A=0x7ffffec4
417169000: system.cpu: T0 : 0x10560 @main+16    : sw s2, 1088(sp)            : MemWrite :  D=0x0000000000000001 A=0x7ffffec0
417173000: system.cpu: T0 : 0x10564 @main+20    : addi s0, sp, 1104          : IntAlu :  D=0x000000007ffffed0
417175000: system.cpu: T0 : 0x10568 @main+24    : c_mv a5, sp                : IntAlu :  D=0x000000007ffffa80
417177000: system.cpu: T0 : 0x1056a @main+26    : c_mv s2, a5                : IntAlu :  D=0x000000007ffffa80
417179000: system.cpu: T0 : 0x1056c @main+28    : lui a5, 79                 : IntAlu :  D=0x000000000004f000
417181000: system.cpu: T0 : 0x10570 @main+32    : addi a5, a5, -1712         : IntAlu :  D=0x000000000004e950
417183000: system.cpu: T0 : 0x10574 @main+36    : c_lw s1, 0(a5)             : MemRead :  D=0x0000000000000004 A=0x4e950
417296000: system.cpu: T0 : 0x10576 @main+38    : lw t0, 4(a5)               : MemRead :  D=0x0000000000000005 A=0x4e954
417302000: system.cpu: T0 : 0x1057a @main+42    : lw t6, 8(a5)               : MemRead :  D=0x0000000000000001 A=0x4e958
417401000: system.cpu: T0 : 0x1057e @main+46    : lw t5, 12(a5)              : MemRead :  D=0x0000000000000008 A=0x4e95c
417407000: system.cpu: T0 : 0x10582 @main+50    : lw t4, 16(a5)              : MemRead :  D=0x0000000000000003 A=0x4e960
417413000: system.cpu: T0 : 0x10586 @main+54    : lw t3, 20(a5)              : MemRead :  D=0x0000000000000006 A=0x4e964
417417000: system.cpu: T0 : 0x1058a @main+58    : c_lw a4, 24(a5)            : MemRead :  D=0x0000000000000009 A=0x4e968
417421000: system.cpu: T0 : 0x1058c @main+60    : c_lw a5, 28(a5)            : MemRead :  D=0x0000000000000002 A=0x4e96c
417427000: system.cpu: T0 : 0x1058e @main+62    : sw s1, -68(s0)             : MemWrite :  D=0x0000000000000004 A=0x7ffffe8c
417433000: system.cpu: T0 : 0x10592 @main+66    : sw t0, -64(s0)             : MemWrite :  D=0x0000000000000005 A=0x7ffffe90
417439000: system.cpu: T0 : 0x10596 @main+70    : sw t6, -60(s0)             : MemWrite :  D=0x0000000000000001 A=0x7ffffe94
417445000: system.cpu: T0 : 0x1059a @main+74    : sw t5, -56(s0)             : MemWrite :  D=0x0000000000000008 A=0x7ffffe98
417451000: system.cpu: T0 : 0x1059e @main+78    : sw t4, -52(s0)             : MemWrite :  D=0x0000000000000003 A=0x7ffffe9c
417457000: system.cpu: T0 : 0x105a2 @main+82    : sw t3, -48(s0)             : MemWrite :  D=0x0000000000000006 A=0x7ffffea0
417463000: system.cpu: T0 : 0x105a6 @main+86    : sw a4, -44(s0)             : MemWrite :  D=0x0000000000000009 A=0x7ffffea4
417469000: system.cpu: T0 : 0x105aa @main+90    : sw a5, -40(s0)             : MemWrite :  D=0x0000000000000002 A=0x7ffffea8
417473000: system.cpu: T0 : 0x105ae @main+94    : c_li a5, 8                 : IntAlu :  D=0x0000000000000008
417475000: system.cpu: T0 : 0x105b0 @main+96    : sw a5, -20(s0)             : MemWrite :  D=0x0000000000000008 A=0x7ffffebc
417479000: system.cpu: T0 : 0x105b4 @main+100    : lw a5, -20(s0)             : MemRead :  D=0x0000000000000008 A=0x7ffffebc
417483000: system.cpu: T0 : 0x105b8 @main+104    : addi a4, a5, -1            : IntAlu :  D=0x0000000000000007
417485000: system.cpu: T0 : 0x105bc @main+108    : sw a4, -24(s0)             : MemWrite :  D=0x0000000000000007 A=0x7ffffeb8
417582000: system.cpu: T0 : 0x105c0 @main+112    : c_mv a4, a5                : IntAlu :  D=0x0000000000000008
417584000: system.cpu: T0 : 0x105c2 @main+114    : c_mv t1, a4                : IntAlu :  D=0x0000000000000008
417586000: system.cpu: T0 : 0x105c4 @main+116    : c_li t2, 0                 : IntAlu :  D=0x0000000000000000
417590000: system.cpu: T0 : 0x105c6 @main+118    : srli a4, t1, 27            : IntAlu :  D=0x0000000000000000
417594000: system.cpu: T0 : 0x105ca @main+122    : slli a1, t2, 5             : IntAlu :  D=0x0000000000000000
417596000: system.cpu: T0 : 0x105ce @main+126    : c_or a1, a4                : IntAlu :  D=0x0000000000000000
417598000: system.cpu: T0 : 0x105d0 @main+128    : slli a0, t1, 5             : IntAlu :  D=0x0000000000000100
417600000: system.cpu: T0 : 0x105d4 @main+132    : c_mv a4, a5                : IntAlu :  D=0x0000000000000008
417602000: system.cpu: T0 : 0x105d6 @main+134    : c_mv a6, a4                : IntAlu :  D=0x0000000000000008
417604000: system.cpu: T0 : 0x105d8 @main+136    : c_li a7, 0                 : IntAlu :  D=0x0000000000000000
417608000: system.cpu: T0 : 0x105da @main+138    : srli a4, a6, 27            : IntAlu :  D=0x0000000000000000
417612000: system.cpu: T0 : 0x105de @main+142    : slli a3, a7, 5             : IntAlu :  D=0x0000000000000000
417614000: system.cpu: T0 : 0x105e2 @main+146    : c_or a3, a4                : IntAlu :  D=0x0000000000000000
417616000: system.cpu: T0 : 0x105e4 @main+148    : slli a2, a6, 5             : IntAlu :  D=0x0000000000000100
417618000: system.cpu: T0 : 0x105e8 @main+152    : c_mv a4, a5                : IntAlu :  D=0x0000000000000008
417620000: system.cpu: T0 : 0x105ea @main+154    : c_slli a4, 2               : IntAlu :  D=0x0000000000000020
417622000: system.cpu: T0 : 0x105ec @main+156    : c_addi a4, 15              : IntAlu :  D=0x000000000000002f
417624000: system.cpu: T0 : 0x105ee @main+158    : c_srli a4, 4               : IntAlu :  D=0x0000000000000002
417626000: system.cpu: T0 : 0x105f0 @main+160    : c_slli a4, 4               : IntAlu :  D=0x0000000000000020
417630000: system.cpu: T0 : 0x105f2 @main+162    : sub sp, sp, a4             : IntAlu :  D=0x000000007ffffa60
417632000: system.cpu: T0 : 0x105f6 @main+166    : c_mv a4, sp                : IntAlu :  D=0x000000007ffffa60
417634000: system.cpu: T0 : 0x105f8 @main+168    : c_addi a4, 3               : IntAlu :  D=0x000000007ffffa63
417636000: system.cpu: T0 : 0x105fa @main+170    : c_srli a4, 2               : IntAlu :  D=0x000000001ffffe98
417638000: system.cpu: T0 : 0x105fc @main+172    : c_slli a4, 2               : IntAlu :  D=0x000000007ffffa60
417735000: system.cpu: T0 : 0x105fe @main+174    : sw a4, -28(s0)             : MemWrite :  D=0x000000007ffffa60 A=0x7ffffeb4
417741000: system.cpu: T0 : 0x10602 @main+178    : lw a4, -28(s0)             : MemRead :  D=0x000000007ffffa60 A=0x7ffffeb4
417745000: system.cpu: T0 : 0x10606 @main+182    : c_addi a5, -1              : IntAlu :  D=0x0000000000000007
417747000: system.cpu: T0 : 0x10608 @main+184    : sw zero, 0(a4)             : MemWrite :  D=0x0000000000000000 A=0x7ffffa60
417844000: system.cpu: T0 : 0x1060c @main+188    : c_addi a4, 4               : IntAlu :  D=0x000000007ffffa64
417846000: system.cpu: T0 : 0x1060e @main+190    : c_addi a5, -1              : IntAlu :  D=0x0000000000000006
417848000: system.cpu: T0 : 0x10610 @main+192    : c_j 10                     : IntAlu : 
417852000: system.cpu: T0 : 0x1061a @main+202    : bge a5, zero, -8           : IntAlu : 
417856000: system.cpu: T0 : 0x10612 @main+194    : sw zero, 0(a4)             : MemWrite :  D=0x0000000000000000 A=0x7ffffa64
417860000: system.cpu: T0 : 0x10616 @main+198    : c_addi a5, -1              : IntAlu :  D=0x0000000000000005
417862000: system.cpu: T0 : 0x10618 @main+200    : c_addi a4, 4               : IntAlu :  D=0x000000007ffffa68
417866000: system.cpu: T0 : 0x1061a @main+202    : bge a5, zero, -8           : IntAlu : 
417870000: system.cpu: T0 : 0x10612 @main+194    : sw zero, 0(a4)             : MemWrite :  D=0x0000000000000000 A=0x7ffffa68
417874000: system.cpu: T0 : 0x10616 @main+198    : c_addi a5, -1              : IntAlu :  D=0x0000000000000004
417876000: system.cpu: T0 : 0x10618 @main+200    : c_addi a4, 4               : IntAlu :  D=0x000000007ffffa6c
417880000: system.cpu: T0 : 0x1061a @main+202    : bge a5, zero, -8           : IntAlu : 
417884000: system.cpu: T0 : 0x10612 @main+194    : sw zero, 0(a4)             : MemWrite :  D=0x0000000000000000 A=0x7ffffa6c
417888000: system.cpu: T0 : 0x10616 @main+198    : c_addi a5, -1              : IntAlu :  D=0x0000000000000003
417890000: system.cpu: T0 : 0x10618 @main+200    : c_addi a4, 4               : IntAlu :  D=0x000000007ffffa70
417894000: system.cpu: T0 : 0x1061a @main+202    : bge a5, zero, -8           : IntAlu : 
417898000: system.cpu: T0 : 0x10612 @main+194    : sw zero, 0(a4)             : MemWrite :  D=0x0000000000000000 A=0x7ffffa70
417902000: system.cpu: T0 : 0x10616 @main+198    : c_addi a5, -1              : IntAlu :  D=0x0000000000000002
417904000: system.cpu: T0 : 0x10618 @main+200    : c_addi a4, 4               : IntAlu :  D=0x000000007ffffa74
417908000: system.cpu: T0 : 0x1061a @main+202    : bge a5, zero, -8           : IntAlu : 
417912000: system.cpu: T0 : 0x10612 @main+194    : sw zero, 0(a4)             : MemWrite :  D=0x0000000000000000 A=0x7ffffa74
417916000: system.cpu: T0 : 0x10616 @main+198    : c_addi a5, -1              : IntAlu :  D=0x0000000000000001
417918000: system.cpu: T0 : 0x10618 @main+200    : c_addi a4, 4               : IntAlu :  D=0x000000007ffffa78
417922000: system.cpu: T0 : 0x1061a @main+202    : bge a5, zero, -8           : IntAlu : 
417926000: system.cpu: T0 : 0x10612 @main+194    : sw zero, 0(a4)             : MemWrite :  D=0x0000000000000000 A=0x7ffffa78
417930000: system.cpu: T0 : 0x10616 @main+198    : c_addi a5, -1              : IntAlu :  D=0x0000000000000000
417932000: system.cpu: T0 : 0x10618 @main+200    : c_addi a4, 4               : IntAlu :  D=0x000000007ffffa7c
417936000: system.cpu: T0 : 0x1061a @main+202    : bge a5, zero, -8           : IntAlu : 
417940000: system.cpu: T0 : 0x10612 @main+194    : sw zero, 0(a4)             : MemWrite :  D=0x0000000000000000 A=0x7ffffa7c
417944000: system.cpu: T0 : 0x10616 @main+198    : c_addi a5, -1              : IntAlu :  D=0xffffffffffffffff
417946000: system.cpu: T0 : 0x10618 @main+200    : c_addi a4, 4               : IntAlu :  D=0x000000007ffffa80
417950000: system.cpu: T0 : 0x1061a @main+202    : bge a5, zero, -8           : IntAlu : 
417954000: system.cpu: T0 : 0x1061e @main+206    : addi a5, s0, -68           : IntAlu :  D=0x000000007ffffe8c
417958000: system.cpu: T0 : 0x10622 @main+210    : lw a2, -28(s0)             : MemRead :  D=0x000000007ffffa60 A=0x7ffffeb4
417962000: system.cpu: T0 : 0x10626 @main+214    : c_mv a1, a5                : IntAlu :  D=0x000000007ffffe8c
417964000: system.cpu: T0 : 0x10628 @main+216    : lw a0, -20(s0)             : MemRead :  D=0x0000000000000008 A=0x7ffffebc
417968000: system.cpu: T0 : 0x1062c @main+220    : c_jal -504                 : IntAlu :  D=0x000000000001062e
417970000: system.cpu: T0 : 0x10434 @_Z3LISiPiS_    : c_addi16sp sp, -64         : IntAlu :  D=0x000000007ffffa20
417972000: system.cpu: T0 : 0x10436 @_Z3LISiPiS_+2    : c_swsp ra, 60(sp)          : MemWrite :  D=0x000000000001062e A=0x7ffffa5c
417976000: system.cpu: T0 : 0x10438 @_Z3LISiPiS_+4    : c_swsp s0, 56(sp)          : MemWrite :  D=0x000000007ffffed0 A=0x7ffffa58
417980000: system.cpu: T0 : 0x1043a @_Z3LISiPiS_+6    : c_addi4spn s0, sp, 64      : IntAlu :  D=0x000000007ffffa60
417982000: system.cpu: T0 : 0x1043c @_Z3LISiPiS_+8    : sw a0, -52(s0)             : MemWrite :  D=0x0000000000000008 A=0x7ffffa2c
418172000: system.cpu: T0 : 0x10440 @_Z3LISiPiS_+12    : sw a1, -56(s0)             : MemWrite :  D=0x000000007ffffe8c A=0x7ffffa28
418176000: system.cpu: T0 : 0x10444 @_Z3LISiPiS_+16    : sw a2, -60(s0)             : MemWrite :  D=0x000000007ffffa60 A=0x7ffffa24
418180000: system.cpu: T0 : 0x10448 @_Z3LISiPiS_+20    : lw a5, -52(s0)             : MemRead :  D=0x0000000000000008 A=0x7ffffa2c
418184000: system.cpu: T0 : 0x1044c @_Z3LISiPiS_+24    : c_bnez a5, 6               : IntAlu : 
418186000: system.cpu: T0 : 0x10452 @_Z3LISiPiS_+30    : c_li a5, 1                 : IntAlu :  D=0x0000000000000001
418188000: system.cpu: T0 : 0x10454 @_Z3LISiPiS_+32    : sw a5, -20(s0)             : MemWrite :  D=0x0000000000000001 A=0x7ffffa4c
418192000: system.cpu: T0 : 0x10458 @_Z3LISiPiS_+36    : sw zero, -24(s0)           : MemWrite :  D=0x0000000000000000 A=0x7ffffa48
418196000: system.cpu: T0 : 0x1045c @_Z3LISiPiS_+40    : c_j 28                     : IntAlu : 
418198000: system.cpu: T0 : 0x10478 @_Z3LISiPiS_+68    : lw a4, -24(s0)             : MemRead :  D=0x0000000000000000 A=0x7ffffa48
418202000: system.cpu: T0 : 0x1047c @_Z3LISiPiS_+72    : lw a5, -52(s0)             : MemRead :  D=0x0000000000000008 A=0x7ffffa2c
418299000: system.cpu: T0 : 0x10480 @_Z3LISiPiS_+76    : blt a4, a5, -34            : IntAlu : 
418303000: system.cpu: T0 : 0x1045e @_Z3LISiPiS_+42    : lw a5, -24(s0)             : MemRead :  D=0x0000000000000000 A=0x7ffffa48
418307000: system.cpu: T0 : 0x10462 @_Z3LISiPiS_+46    : c_slli a5, 2               : IntAlu :  D=0x0000000000000000
418309000: system.cpu: T0 : 0x10464 @_Z3LISiPiS_+48    : lw a4, -60(s0)             : MemRead :  D=0x000000007ffffa60 A=0x7ffffa24
418313000: system.cpu: T0 : 0x10468 @_Z3LISiPiS_+52    : c_add a5, a4               : IntAlu :  D=0x000000007ffffa60
418315000: system.cpu: T0 : 0x1046a @_Z3LISiPiS_+54    : c_li a4, 1                 : IntAlu :  D=0x0000000000000001
418317000: system.cpu: T0 : 0x1046c @_Z3LISiPiS_+56    : c_sw a4, 0(a5)             : MemWrite :  D=0x0000000000000001 A=0x7ffffa60
418323000: system.cpu: T0 : 0x1046e @_Z3LISiPiS_+58    : lw a5, -24(s0)             : MemRead :  D=0x0000000000000000 A=0x7ffffa48
418327000: system.cpu: T0 : 0x10472 @_Z3LISiPiS_+62    : c_addi a5, 1               : IntAlu :  D=0x0000000000000001
418329000: system.cpu: T0 : 0x10474 @_Z3LISiPiS_+64    : sw a5, -24(s0)             : MemWrite :  D=0x0000000000000001 A=0x7ffffa48
418333000: system.cpu: T0 : 0x10478 @_Z3LISiPiS_+68    : lw a4, -24(s0)             : MemRead :  D=0x0000000000000001 A=0x7ffffa48
418337000: system.cpu: T0 : 0x1047c @_Z3LISiPiS_+72    : lw a5, -52(s0)             : MemRead :  D=0x0000000000000008 A=0x7ffffa2c
418341000: system.cpu: T0 : 0x10480 @_Z3LISiPiS_+76    : blt a4, a5, -34            : IntAlu : 
418345000: system.cpu: T0 : 0x1045e @_Z3LISiPiS_+42    : lw a5, -24(s0)             : MemRead :  D=0x0000000000000001 A=0x7ffffa48
418349000: system.cpu: T0 : 0x10462 @_Z3LISiPiS_+46    : c_slli a5, 2               : IntAlu :  D=0x0000000000000004
418351000: system.cpu: T0 : 0x10464 @_Z3LISiPiS_+48    : lw a4, -60(s0)             : MemRead :  D=0x000000007ffffa60 A=0x7ffffa24
418355000: system.cpu: T0 : 0x10468 @_Z3LISiPiS_+52    : c_add a5, a4               : IntAlu :  D=0x000000007ffffa64
418357000: system.cpu: T0 : 0x1046a @_Z3LISiPiS_+54    : c_li a4, 1                 : IntAlu :  D=0x0000000000000001
418359000: system.cpu: T0 : 0x1046c @_Z3LISiPiS_+56    : c_sw a4, 0(a5)             : MemWrite :  D=0x0000000000000001 A=0x7ffffa64
418365000: system.cpu: T0 : 0x1046e @_Z3LISiPiS_+58    : lw a5, -24(s0)             : MemRead :  D=0x0000000000000001 A=0x7ffffa48
418369000: system.cpu: T0 : 0x10472 @_Z3LISiPiS_+62    : c_addi a5, 1               : IntAlu :  D=0x0000000000000002
418371000: system.cpu: T0 : 0x10474 @_Z3LISiPiS_+64    : sw a5, -24(s0)             : MemWrite :  D=0x0000000000000002 A=0x7ffffa48
418375000: system.cpu: T0 : 0x10478 @_Z3LISiPiS_+68    : lw a4, -24(s0)             : MemRead :  D=0x0000000000000002 A=0x7ffffa48
418379000: system.cpu: T0 : 0x1047c @_Z3LISiPiS_+72    : lw a5, -52(s0)             : MemRead :  D=0x0000000000000008 A=0x7ffffa2c
418383000: system.cpu: T0 : 0x10480 @_Z3LISiPiS_+76    : blt a4, a5, -34            : IntAlu : 
418387000: system.cpu: T0 : 0x1045e @_Z3LISiPiS_+42    : lw a5, -24(s0)             : MemRead :  D=0x0000000000000002 A=0x7ffffa48
418391000: system.cpu: T0 : 0x10462 @_Z3LISiPiS_+46    : c_slli a5, 2               : IntAlu :  D=0x0000000000000008
418393000: system.cpu: T0 : 0x10464 @_Z3LISiPiS_+48    : lw a4, -60(s0)             : MemRead :  D=0x000000007ffffa60 A=0x7ffffa24
418397000: system.cpu: T0 : 0x10468 @_Z3LISiPiS_+52    : c_add a5, a4               : IntAlu :  D=0x000000007ffffa68
418399000: system.cpu: T0 : 0x1046a @_Z3LISiPiS_+54    : c_li a4, 1                 : IntAlu :  D=0x0000000000000001
418401000: system.cpu: T0 : 0x1046c @_Z3LISiPiS_+56    : c_sw a4, 0(a5)             : MemWrite :  D=0x0000000000000001 A=0x7ffffa68
418407000: system.cpu: T0 : 0x1046e @_Z3LISiPiS_+58    : lw a5, -24(s0)             : MemRead :  D=0x0000000000000002 A=0x7ffffa48
418411000: system.cpu: T0 : 0x10472 @_Z3LISiPiS_+62    : c_addi a5, 1               : IntAlu :  D=0x0000000000000003
418413000: system.cpu: T0 : 0x10474 @_Z3LISiPiS_+64    : sw a5, -24(s0)             : MemWrite :  D=0x0000000000000003 A=0x7ffffa48
418417000: system.cpu: T0 : 0x10478 @_Z3LISiPiS_+68    : lw a4, -24(s0)             : MemRead :  D=0x0000000000000003 A=0x7ffffa48
418421000: system.cpu: T0 : 0x1047c @_Z3LISiPiS_+72    : lw a5, -52(s0)             : MemRead :  D=0x0000000000000008 A=0x7ffffa2c
418425000: system.cpu: T0 : 0x10480 @_Z3LISiPiS_+76    : blt a4, a5, -34            : IntAlu : 
418429000: system.cpu: T0 : 0x1045e @_Z3LISiPiS_+42    : lw a5, -24(s0)             : MemRead :  D=0x0000000000000003 A=0x7ffffa48
418433000: system.cpu: T0 : 0x10462 @_Z3LISiPiS_+46    : c_slli a5, 2               : IntAlu :  D=0x000000000000000c
418435000: system.cpu: T0 : 0x10464 @_Z3LISiPiS_+48    : lw a4, -60(s0)             : MemRead :  D=0x000000007ffffa60 A=0x7ffffa24
418439000: system.cpu: T0 : 0x10468 @_Z3LISiPiS_+52    : c_add a5, a4               : IntAlu :  D=0x000000007ffffa6c
418441000: system.cpu: T0 : 0x1046a @_Z3LISiPiS_+54    : c_li a4, 1                 : IntAlu :  D=0x0000000000000001
418443000: system.cpu: T0 : 0x1046c @_Z3LISiPiS_+56    : c_sw a4, 0(a5)             : MemWrite :  D=0x0000000000000001 A=0x7ffffa6c
418449000: system.cpu: T0 : 0x1046e @_Z3LISiPiS_+58    : lw a5, -24(s0)             : MemRead :  D=0x0000000000000003 A=0x7ffffa48
418453000: system.cpu: T0 : 0x10472 @_Z3LISiPiS_+62    : c_addi a5, 1               : IntAlu :  D=0x0000000000000004
418455000: system.cpu: T0 : 0x10474 @_Z3LISiPiS_+64    : sw a5, -24(s0)             : MemWrite :  D=0x0000000000000004 A=0x7ffffa48
418459000: system.cpu: T0 : 0x10478 @_Z3LISiPiS_+68    : lw a4, -24(s0)             : MemRead :  D=0x0000000000000004 A=0x7ffffa48
418463000: system.cpu: T0 : 0x1047c @_Z3LISiPiS_+72    : lw a5, -52(s0)             : MemRead :  D=0x0000000000000008 A=0x7ffffa2c
418467000: system.cpu: T0 : 0x10480 @_Z3LISiPiS_+76    : blt a4, a5, -34            : IntAlu : 
418471000: system.cpu: T0 : 0x1045e @_Z3LISiPiS_+42    : lw a5, -24(s0)             : MemRead :  D=0x0000000000000004 A=0x7ffffa48
418475000: system.cpu: T0 : 0x10462 @_Z3LISiPiS_+46    : c_slli a5, 2               : IntAlu :  D=0x0000000000000010
418477000: system.cpu: T0 : 0x10464 @_Z3LISiPiS_+48    : lw a4, -60(s0)             : MemRead :  D=0x000000007ffffa60 A=0x7ffffa24
418481000: system.cpu: T0 : 0x10468 @_Z3LISiPiS_+52    : c_add a5, a4               : IntAlu :  D=0x000000007ffffa70
418483000: system.cpu: T0 : 0x1046a @_Z3LISiPiS_+54    : c_li a4, 1                 : IntAlu :  D=0x0000000000000001
418485000: system.cpu: T0 : 0x1046c @_Z3LISiPiS_+56    : c_sw a4, 0(a5)             : MemWrite :  D=0x0000000000000001 A=0x7ffffa70
418491000: system.cpu: T0 : 0x1046e @_Z3LISiPiS_+58    : lw a5, -24(s0)             : MemRead :  D=0x0000000000000004 A=0x7ffffa48
418495000: system.cpu: T0 : 0x10472 @_Z3LISiPiS_+62    : c_addi a5, 1               : IntAlu :  D=0x0000000000000005
418497000: system.cpu: T0 : 0x10474 @_Z3LISiPiS_+64    : sw a5, -24(s0)             : MemWrite :  D=0x0000000000000005 A=0x7ffffa48
418501000: system.cpu: T0 : 0x10478 @_Z3LISiPiS_+68    : lw a4, -24(s0)             : MemRead :  D=0x0000000000000005 A=0x7ffffa48
418505000: system.cpu: T0 : 0x1047c @_Z3LISiPiS_+72    : lw a5, -52(s0)             : MemRead :  D=0x0000000000000008 A=0x7ffffa2c
418509000: system.cpu: T0 : 0x10480 @_Z3LISiPiS_+76    : blt a4, a5, -34            : IntAlu : 
418513000: system.cpu: T0 : 0x1045e @_Z3LISiPiS_+42    : lw a5, -24(s0)             : MemRead :  D=0x0000000000000005 A=0x7ffffa48
418517000: system.cpu: T0 : 0x10462 @_Z3LISiPiS_+46    : c_slli a5, 2               : IntAlu :  D=0x0000000000000014
418519000: system.cpu: T0 : 0x10464 @_Z3LISiPiS_+48    : lw a4, -60(s0)             : MemRead :  D=0x000000007ffffa60 A=0x7ffffa24
418523000: system.cpu: T0 : 0x10468 @_Z3LISiPiS_+52    : c_add a5, a4               : IntAlu :  D=0x000000007ffffa74
418525000: system.cpu: T0 : 0x1046a @_Z3LISiPiS_+54    : c_li a4, 1                 : IntAlu :  D=0x0000000000000001
418527000: system.cpu: T0 : 0x1046c @_Z3LISiPiS_+56    : c_sw a4, 0(a5)             : MemWrite :  D=0x0000000000000001 A=0x7ffffa74
418533000: system.cpu: T0 : 0x1046e @_Z3LISiPiS_+58    : lw a5, -24(s0)             : MemRead :  D=0x0000000000000005 A=0x7ffffa48
418537000: system.cpu: T0 : 0x10472 @_Z3LISiPiS_+62    : c_addi a5, 1               : IntAlu :  D=0x0000000000000006
418539000: system.cpu: T0 : 0x10474 @_Z3LISiPiS_+64    : sw a5, -24(s0)             : MemWrite :  D=0x0000000000000006 A=0x7ffffa48
418543000: system.cpu: T0 : 0x10478 @_Z3LISiPiS_+68    : lw a4, -24(s0)             : MemRead :  D=0x0000000000000006 A=0x7ffffa48
418547000: system.cpu: T0 : 0x1047c @_Z3LISiPiS_+72    : lw a5, -52(s0)             : MemRead :  D=0x0000000000000008 A=0x7ffffa2c
418551000: system.cpu: T0 : 0x10480 @_Z3LISiPiS_+76    : blt a4, a5, -34            : IntAlu : 
418555000: system.cpu: T0 : 0x1045e @_Z3LISiPiS_+42    : lw a5, -24(s0)             : MemRead :  D=0x0000000000000006 A=0x7ffffa48
418559000: system.cpu: T0 : 0x10462 @_Z3LISiPiS_+46    : c_slli a5, 2               : IntAlu :  D=0x0000000000000018
418561000: system.cpu: T0 : 0x10464 @_Z3LISiPiS_+48    : lw a4, -60(s0)             : MemRead :  D=0x000000007ffffa60 A=0x7ffffa24
418565000: system.cpu: T0 : 0x10468 @_Z3LISiPiS_+52    : c_add a5, a4               : IntAlu :  D=0x000000007ffffa78
418567000: system.cpu: T0 : 0x1046a @_Z3LISiPiS_+54    : c_li a4, 1                 : IntAlu :  D=0x0000000000000001
418569000: system.cpu: T0 : 0x1046c @_Z3LISiPiS_+56    : c_sw a4, 0(a5)             : MemWrite :  D=0x0000000000000001 A=0x7ffffa78
418575000: system.cpu: T0 : 0x1046e @_Z3LISiPiS_+58    : lw a5, -24(s0)             : MemRead :  D=0x0000000000000006 A=0x7ffffa48
418579000: system.cpu: T0 : 0x10472 @_Z3LISiPiS_+62    : c_addi a5, 1               : IntAlu :  D=0x0000000000000007
418581000: system.cpu: T0 : 0x10474 @_Z3LISiPiS_+64    : sw a5, -24(s0)             : MemWrite :  D=0x0000000000000007 A=0x7ffffa48
418585000: system.cpu: T0 : 0x10478 @_Z3LISiPiS_+68    : lw a4, -24(s0)             : MemRead :  D=0x0000000000000007 A=0x7ffffa48
418589000: system.cpu: T0 : 0x1047c @_Z3LISiPiS_+72    : lw a5, -52(s0)             : MemRead :  D=0x0000000000000008 A=0x7ffffa2c
418593000: system.cpu: T0 : 0x10480 @_Z3LISiPiS_+76    : blt a4, a5, -34            : IntAlu : 
418597000: system.cpu: T0 : 0x1045e @_Z3LISiPiS_+42    : lw a5, -24(s0)             : MemRead :  D=0x0000000000000007 A=0x7ffffa48
418601000: system.cpu: T0 : 0x10462 @_Z3LISiPiS_+46    : c_slli a5, 2               : IntAlu :  D=0x000000000000001c
418603000: system.cpu: T0 : 0x10464 @_Z3LISiPiS_+48    : lw a4, -60(s0)             : MemRead :  D=0x000000007ffffa60 A=0x7ffffa24
418607000: system.cpu: T0 : 0x10468 @_Z3LISiPiS_+52    : c_add a5, a4               : IntAlu :  D=0x000000007ffffa7c
418609000: system.cpu: T0 : 0x1046a @_Z3LISiPiS_+54    : c_li a4, 1                 : IntAlu :  D=0x0000000000000001
418611000: system.cpu: T0 : 0x1046c @_Z3LISiPiS_+56    : c_sw a4, 0(a5)             : MemWrite :  D=0x0000000000000001 A=0x7ffffa7c
418617000: system.cpu: T0 : 0x1046e @_Z3LISiPiS_+58    : lw a5, -24(s0)             : MemRead :  D=0x0000000000000007 A=0x7ffffa48
418621000: system.cpu: T0 : 0x10472 @_Z3LISiPiS_+62    : c_addi a5, 1               : IntAlu :  D=0x0000000000000008
418623000: system.cpu: T0 : 0x10474 @_Z3LISiPiS_+64    : sw a5, -24(s0)             : MemWrite :  D=0x0000000000000008 A=0x7ffffa48
418627000: system.cpu: T0 : 0x10478 @_Z3LISiPiS_+68    : lw a4, -24(s0)             : MemRead :  D=0x0000000000000008 A=0x7ffffa48
418631000: system.cpu: T0 : 0x1047c @_Z3LISiPiS_+72    : lw a5, -52(s0)             : MemRead :  D=0x0000000000000008 A=0x7ffffa2c
418635000: system.cpu: T0 : 0x10480 @_Z3LISiPiS_+76    : blt a4, a5, -34            : IntAlu : 
418637000: system.cpu: T0 : 0x10484 @_Z3LISiPiS_+80    : c_li a5, 1                 : IntAlu :  D=0x0000000000000001
418641000: system.cpu: T0 : 0x10486 @_Z3LISiPiS_+82    : sw a5, -28(s0)             : MemWrite :  D=0x0000000000000001 A=0x7ffffa44
418645000: system.cpu: T0 : 0x1048a @_Z3LISiPiS_+86    : c_j 172                    : IntAlu : 
418742000: system.cpu: T0 : 0x10536 @_Z3LISiPiS_+258    : lw a4, -28(s0)             : MemRead :  D=0x0000000000000001 A=0x7ffffa44
418748000: system.cpu: T0 : 0x1053a @_Z3LISiPiS_+262    : lw a5, -52(s0)             : MemRead :  D=0x0000000000000008 A=0x7ffffa2c
418754000: system.cpu: T0 : 0x1053e @_Z3LISiPiS_+266    : blt a4, a5, -178           : IntAlu : 
418756000: system.cpu: T0 : 0x1048c @_Z3LISiPiS_+88    : sw zero, -32(s0)           : MemWrite :  D=0x0000000000000000 A=0x7ffffa40
418760000: system.cpu: T0 : 0x10490 @_Z3LISiPiS_+92    : c_j 104                    : IntAlu : 
418855000: system.cpu: T0 : 0x104f8 @_Z3LISiPiS_+196    : lw a4, -32(s0)             : MemRead :  D=0x0000000000000000 A=0x7ffffa40
418859000: system.cpu: T0 : 0x104fc @_Z3LISiPiS_+200    : lw a5, -28(s0)             : MemRead :  D=0x0000000000000001 A=0x7ffffa44
418863000: system.cpu: T0 : 0x10500 @_Z3LISiPiS_+204    : blt a4, a5, -110           : IntAlu : 
418867000: system.cpu: T0 : 0x10492 @_Z3LISiPiS_+94    : lw a5, -28(s0)             : MemRead :  D=0x0000000000000001 A=0x7ffffa44
418871000: system.cpu: T0 : 0x10496 @_Z3LISiPiS_+98    : c_slli a5, 2               : IntAlu :  D=0x0000000000000004
418873000: system.cpu: T0 : 0x10498 @_Z3LISiPiS_+100    : lw a4, -56(s0)             : MemRead :  D=0x000000007ffffe8c A=0x7ffffa28
418877000: system.cpu: T0 : 0x1049c @_Z3LISiPiS_+104    : c_add a5, a4               : IntAlu :  D=0x000000007ffffe90
418879000: system.cpu: T0 : 0x1049e @_Z3LISiPiS_+106    : c_lw a4, 0(a5)             : MemRead :  D=0x0000000000000005 A=0x7ffffe90
418883000: system.cpu: T0 : 0x104a0 @_Z3LISiPiS_+108    : lw a5, -32(s0)             : MemRead :  D=0x0000000000000000 A=0x7ffffa40
418887000: system.cpu: T0 : 0x104a4 @_Z3LISiPiS_+112    : c_slli a5, 2               : IntAlu :  D=0x0000000000000000
418891000: system.cpu: T0 : 0x104a6 @_Z3LISiPiS_+114    : lw a3, -56(s0)             : MemRead :  D=0x000000007ffffe8c A=0x7ffffa28
418895000: system.cpu: T0 : 0x104aa @_Z3LISiPiS_+118    : c_add a5, a3               : IntAlu :  D=0x000000007ffffe8c
418897000: system.cpu: T0 : 0x104ac @_Z3LISiPiS_+120    : c_lw a5, 0(a5)             : MemRead :  D=0x0000000000000004 A=0x7ffffe8c
418903000: system.cpu: T0 : 0x104ae @_Z3LISiPiS_+122    : bge a5, a4, 64             : IntAlu : 
418907000: system.cpu: T0 : 0x104b2 @_Z3LISiPiS_+126    : lw a5, -32(s0)             : MemRead :  D=0x0000000000000000 A=0x7ffffa40
418911000: system.cpu: T0 : 0x104b6 @_Z3LISiPiS_+130    : c_slli a5, 2               : IntAlu :  D=0x0000000000000000
418913000: system.cpu: T0 : 0x104b8 @_Z3LISiPiS_+132    : lw a4, -60(s0)             : MemRead :  D=0x000000007ffffa60 A=0x7ffffa24
418917000: system.cpu: T0 : 0x104bc @_Z3LISiPiS_+136    : c_add a5, a4               : IntAlu :  D=0x000000007ffffa60
418919000: system.cpu: T0 : 0x104be @_Z3LISiPiS_+138    : c_lw a5, 0(a5)             : MemRead :  D=0x0000000000000001 A=0x7ffffa60
418923000: system.cpu: T0 : 0x104c0 @_Z3LISiPiS_+140    : c_addi a5, 1               : IntAlu :  D=0x0000000000000002
418927000: system.cpu: T0 : 0x104c2 @_Z3LISiPiS_+142    : sw a5, -36(s0)             : MemWrite :  D=0x0000000000000002 A=0x7ffffa3c
418933000: system.cpu: T0 : 0x104c6 @_Z3LISiPiS_+146    : lw a5, -28(s0)             : MemRead :  D=0x0000000000000001 A=0x7ffffa44
418937000: system.cpu: T0 : 0x104ca @_Z3LISiPiS_+150    : c_slli a5, 2               : IntAlu :  D=0x0000000000000004
418939000: system.cpu: T0 : 0x104cc @_Z3LISiPiS_+152    : lw a4, -60(s0)             : MemRead :  D=0x000000007ffffa60 A=0x7ffffa24
418943000: system.cpu: T0 : 0x104d0 @_Z3LISiPiS_+156    : c_add a5, a4               : IntAlu :  D=0x000000007ffffa64
418945000: system.cpu: T0 : 0x104d2 @_Z3LISiPiS_+158    : c_lw a5, 0(a5)             : MemRead :  D=0x0000000000000001 A=0x7ffffa64
418949000: system.cpu: T0 : 0x104d4 @_Z3LISiPiS_+160    : lw a4, -36(s0)             : MemRead :  D=0x0000000000000002 A=0x7ffffa3c
418953000: system.cpu: T0 : 0x104d8 @_Z3LISiPiS_+164    : bge a5, a4, 22             : IntAlu : 
418955000: system.cpu: T0 : 0x104dc @_Z3LISiPiS_+168    : lw a5, -28(s0)             : MemRead :  D=0x0000000000000001 A=0x7ffffa44
418959000: system.cpu: T0 : 0x104e0 @_Z3LISiPiS_+172    : c_slli a5, 2               : IntAlu :  D=0x0000000000000004
418963000: system.cpu: T0 : 0x104e2 @_Z3LISiPiS_+174    : lw a4, -60(s0)             : MemRead :  D=0x000000007ffffa60 A=0x7ffffa24
418967000: system.cpu: T0 : 0x104e6 @_Z3LISiPiS_+178    : c_add a5, a4               : IntAlu :  D=0x000000007ffffa64
418969000: system.cpu: T0 : 0x104e8 @_Z3LISiPiS_+180    : lw a4, -36(s0)             : MemRead :  D=0x0000000000000002 A=0x7ffffa3c
418973000: system.cpu: T0 : 0x104ec @_Z3LISiPiS_+184    : c_sw a4, 0(a5)             : MemWrite :  D=0x0000000000000002 A=0x7ffffa64
418979000: system.cpu: T0 : 0x104ee @_Z3LISiPiS_+186    : lw a5, -32(s0)             : MemRead :  D=0x0000000000000000 A=0x7ffffa40
418983000: system.cpu: T0 : 0x104f2 @_Z3LISiPiS_+190    : c_addi a5, 1               : IntAlu :  D=0x0000000000000001
418985000: system.cpu: T0 : 0x104f4 @_Z3LISiPiS_+192    : sw a5, -32(s0)             : MemWrite :  D=0x0000000000000001 A=0x7ffffa40
418989000: system.cpu: T0 : 0x104f8 @_Z3LISiPiS_+196    : lw a4, -32(s0)             : MemRead :  D=0x0000000000000001 A=0x7ffffa40
418993000: system.cpu: T0 : 0x104fc @_Z3LISiPiS_+200    : lw a5, -28(s0)             : MemRead :  D=0x0000000000000001 A=0x7ffffa44
418997000: system.cpu: T0 : 0x10500 @_Z3LISiPiS_+204    : blt a4, a5, -110           : IntAlu : 
418999000: system.cpu: T0 : 0x10504 @_Z3LISiPiS_+208    : lw a5, -28(s0)             : MemRead :  D=0x0000000000000001 A=0x7ffffa44
419003000: system.cpu: T0 : 0x10508 @_Z3LISiPiS_+212    : c_slli a5, 2               : IntAlu :  D=0x0000000000000004
419007000: system.cpu: T0 : 0x1050a @_Z3LISiPiS_+214    : lw a4, -60(s0)             : MemRead :  D=0x000000007ffffa60 A=0x7ffffa24
419011000: system.cpu: T0 : 0x1050e @_Z3LISiPiS_+218    : c_add a5, a4               : IntAlu :  D=0x000000007ffffa64
419013000: system.cpu: T0 : 0x10510 @_Z3LISiPiS_+220    : c_lw a5, 0(a5)             : MemRead :  D=0x0000000000000002 A=0x7ffffa64
419019000: system.cpu: T0 : 0x10512 @_Z3LISiPiS_+222    : lw a4, -20(s0)             : MemRead :  D=0x0000000000000001 A=0x7ffffa4c
419025000: system.cpu: T0 : 0x10516 @_Z3LISiPiS_+226    : bge a4, a5, 22             : IntAlu : 
419029000: system.cpu: T0 : 0x1051a @_Z3LISiPiS_+230    : lw a5, -28(s0)             : MemRead :  D=0x0000000000000001 A=0x7ffffa44
419033000: system.cpu: T0 : 0x1051e @_Z3LISiPiS_+234    : c_slli a5, 2               : IntAlu :  D=0x0000000000000004
419035000: system.cpu: T0 : 0x10520 @_Z3LISiPiS_+236    : lw a4, -60(s0)             : MemRead :  D=0x000000007ffffa60 A=0x7ffffa24
419039000: system.cpu: T0 : 0x10524 @_Z3LISiPiS_+240    : c_add a5, a4               : IntAlu :  D=0x000000007ffffa64
419041000: system.cpu: T0 : 0x10526 @_Z3LISiPiS_+242    : c_lw a5, 0(a5)             : MemRead :  D=0x0000000000000002 A=0x7ffffa64
419045000: system.cpu: T0 : 0x10528 @_Z3LISiPiS_+244    : sw a5, -20(s0)             : MemWrite :  D=0x0000000000000002 A=0x7ffffa4c
419049000: system.cpu: T0 : 0x1052c @_Z3LISiPiS_+248    : lw a5, -28(s0)             : MemRead :  D=0x0000000000000001 A=0x7ffffa44
419053000: system.cpu: T0 : 0x10530 @_Z3LISiPiS_+252    : c_addi a5, 1               : IntAlu :  D=0x0000000000000002
419057000: system.cpu: T0 : 0x10532 @_Z3LISiPiS_+254    : sw a5, -28(s0)             : MemWrite :  D=0x0000000000000002 A=0x7ffffa44
419063000: system.cpu: T0 : 0x10536 @_Z3LISiPiS_+258    : lw a4, -28(s0)             : MemRead :  D=0x0000000000000002 A=0x7ffffa44
419069000: system.cpu: T0 : 0x1053a @_Z3LISiPiS_+262    : lw a5, -52(s0)             : MemRead :  D=0x0000000000000008 A=0x7ffffa2c
419075000: system.cpu: T0 : 0x1053e @_Z3LISiPiS_+266    : blt a4, a5, -178           : IntAlu : 
419077000: system.cpu: T0 : 0x1048c @_Z3LISiPiS_+88    : sw zero, -32(s0)           : MemWrite :  D=0x0000000000000000 A=0x7ffffa40
419081000: system.cpu: T0 : 0x10490 @_Z3LISiPiS_+92    : c_j 104                    : IntAlu : 
419083000: system.cpu: T0 : 0x104f8 @_Z3LISiPiS_+196    : lw a4, -32(s0)             : MemRead :  D=0x0000000000000000 A=0x7ffffa40
419087000: system.cpu: T0 : 0x104fc @_Z3LISiPiS_+200    : lw a5, -28(s0)             : MemRead :  D=0x0000000000000002 A=0x7ffffa44
419091000: system.cpu: T0 : 0x10500 @_Z3LISiPiS_+204    : blt a4, a5, -110           : IntAlu : 
419095000: system.cpu: T0 : 0x10492 @_Z3LISiPiS_+94    : lw a5, -28(s0)             : MemRead :  D=0x0000000000000002 A=0x7ffffa44
419099000: system.cpu: T0 : 0x10496 @_Z3LISiPiS_+98    : c_slli a5, 2               : IntAlu :  D=0x0000000000000008
419101000: system.cpu: T0 : 0x10498 @_Z3LISiPiS_+100    : lw a4, -56(s0)             : MemRead :  D=0x000000007ffffe8c A=0x7ffffa28
419105000: system.cpu: T0 : 0x1049c @_Z3LISiPiS_+104    : c_add a5, a4               : IntAlu :  D=0x000000007ffffe94
419107000: system.cpu: T0 : 0x1049e @_Z3LISiPiS_+106    : c_lw a4, 0(a5)             : MemRead :  D=0x0000000000000001 A=0x7ffffe94
419111000: system.cpu: T0 : 0x104a0 @_Z3LISiPiS_+108    : lw a5, -32(s0)             : MemRead :  D=0x0000000000000000 A=0x7ffffa40
419115000: system.cpu: T0 : 0x104a4 @_Z3LISiPiS_+112    : c_slli a5, 2               : IntAlu :  D=0x0000000000000000
419119000: system.cpu: T0 : 0x104a6 @_Z3LISiPiS_+114    : lw a3, -56(s0)             : MemRead :  D=0x000000007ffffe8c A=0x7ffffa28
419123000: system.cpu: T0 : 0x104aa @_Z3LISiPiS_+118    : c_add a5, a3               : IntAlu :  D=0x000000007ffffe8c
419125000: system.cpu: T0 : 0x104ac @_Z3LISiPiS_+120    : c_lw a5, 0(a5)             : MemRead :  D=0x0000000000000004 A=0x7ffffe8c
419131000: system.cpu: T0 : 0x104ae @_Z3LISiPiS_+122    : bge a5, a4, 64             : IntAlu : 
419135000: system.cpu: T0 : 0x104ee @_Z3LISiPiS_+186    : lw a5, -32(s0)             : MemRead :  D=0x0000000000000000 A=0x7ffffa40
419139000: system.cpu: T0 : 0x104f2 @_Z3LISiPiS_+190    : c_addi a5, 1               : IntAlu :  D=0x0000000000000001
419141000: system.cpu: T0 : 0x104f4 @_Z3LISiPiS_+192    : sw a5, -32(s0)             : MemWrite :  D=0x0000000000000001 A=0x7ffffa40
419145000: system.cpu: T0 : 0x104f8 @_Z3LISiPiS_+196    : lw a4, -32(s0)             : MemRead :  D=0x0000000000000001 A=0x7ffffa40
419149000: system.cpu: T0 : 0x104fc @_Z3LISiPiS_+200    : lw a5, -28(s0)             : MemRead :  D=0x0000000000000002 A=0x7ffffa44
419153000: system.cpu: T0 : 0x10500 @_Z3LISiPiS_+204    : blt a4, a5, -110           : IntAlu : 
419157000: system.cpu: T0 : 0x10492 @_Z3LISiPiS_+94    : lw a5, -28(s0)             : MemRead :  D=0x0000000000000002 A=0x7ffffa44
419161000: system.cpu: T0 : 0x10496 @_Z3LISiPiS_+98    : c_slli a5, 2               : IntAlu :  D=0x0000000000000008
419163000: system.cpu: T0 : 0x10498 @_Z3LISiPiS_+100    : lw a4, -56(s0)             : MemRead :  D=0x000000007ffffe8c A=0x7ffffa28
419167000: system.cpu: T0 : 0x1049c @_Z3LISiPiS_+104    : c_add a5, a4               : IntAlu :  D=0x000000007ffffe94
419169000: system.cpu: T0 : 0x1049e @_Z3LISiPiS_+106    : c_lw a4, 0(a5)             : MemRead :  D=0x0000000000000001 A=0x7ffffe94
419173000: system.cpu: T0 : 0x104a0 @_Z3LISiPiS_+108    : lw a5, -32(s0)             : MemRead :  D=0x0000000000000001 A=0x7ffffa40
419177000: system.cpu: T0 : 0x104a4 @_Z3LISiPiS_+112    : c_slli a5, 2               : IntAlu :  D=0x0000000000000004
419181000: system.cpu: T0 : 0x104a6 @_Z3LISiPiS_+114    : lw a3, -56(s0)             : MemRead :  D=0x000000007ffffe8c A=0x7ffffa28
419185000: system.cpu: T0 : 0x104aa @_Z3LISiPiS_+118    : c_add a5, a3               : IntAlu :  D=0x000000007ffffe90
419187000: system.cpu: T0 : 0x104ac @_Z3LISiPiS_+120    : c_lw a5, 0(a5)             : MemRead :  D=0x0000000000000005 A=0x7ffffe90
419193000: system.cpu: T0 : 0x104ae @_Z3LISiPiS_+122    : bge a5, a4, 64             : IntAlu : 
419197000: system.cpu: T0 : 0x104ee @_Z3LISiPiS_+186    : lw a5, -32(s0)             : MemRead :  D=0x0000000000000001 A=0x7ffffa40
419201000: system.cpu: T0 : 0x104f2 @_Z3LISiPiS_+190    : c_addi a5, 1               : IntAlu :  D=0x0000000000000002
419203000: system.cpu: T0 : 0x104f4 @_Z3LISiPiS_+192    : sw a5, -32(s0)             : MemWrite :  D=0x0000000000000002 A=0x7ffffa40
419207000: system.cpu: T0 : 0x104f8 @_Z3LISiPiS_+196    : lw a4, -32(s0)             : MemRead :  D=0x0000000000000002 A=0x7ffffa40
419211000: system.cpu: T0 : 0x104fc @_Z3LISiPiS_+200    : lw a5, -28(s0)             : MemRead :  D=0x0000000000000002 A=0x7ffffa44
419215000: system.cpu: T0 : 0x10500 @_Z3LISiPiS_+204    : blt a4, a5, -110           : IntAlu : 
419217000: system.cpu: T0 : 0x10504 @_Z3LISiPiS_+208    : lw a5, -28(s0)             : MemRead :  D=0x0000000000000002 A=0x7ffffa44
419221000: system.cpu: T0 : 0x10508 @_Z3LISiPiS_+212    : c_slli a5, 2               : IntAlu :  D=0x0000000000000008
419225000: system.cpu: T0 : 0x1050a @_Z3LISiPiS_+214    : lw a4, -60(s0)             : MemRead :  D=0x000000007ffffa60 A=0x7ffffa24
419229000: system.cpu: T0 : 0x1050e @_Z3LISiPiS_+218    : c_add a5, a4               : IntAlu :  D=0x000000007ffffa68
419231000: system.cpu: T0 : 0x10510 @_Z3LISiPiS_+220    : c_lw a5, 0(a5)             : MemRead :  D=0x0000000000000001 A=0x7ffffa68
419237000: system.cpu: T0 : 0x10512 @_Z3LISiPiS_+222    : lw a4, -20(s0)             : MemRead :  D=0x0000000000000002 A=0x7ffffa4c
419243000: system.cpu: T0 : 0x10516 @_Z3LISiPiS_+226    : bge a4, a5, 22             : IntAlu : 
419245000: system.cpu: T0 : 0x1052c @_Z3LISiPiS_+248    : lw a5, -28(s0)             : MemRead :  D=0x0000000000000002 A=0x7ffffa44
419249000: system.cpu: T0 : 0x10530 @_Z3LISiPiS_+252    : c_addi a5, 1               : IntAlu :  D=0x0000000000000003
419253000: system.cpu: T0 : 0x10532 @_Z3LISiPiS_+254    : sw a5, -28(s0)             : MemWrite :  D=0x0000000000000003 A=0x7ffffa44
419259000: system.cpu: T0 : 0x10536 @_Z3LISiPiS_+258    : lw a4, -28(s0)             : MemRead :  D=0x0000000000000003 A=0x7ffffa44
419265000: system.cpu: T0 : 0x1053a @_Z3LISiPiS_+262    : lw a5, -52(s0)             : MemRead :  D=0x0000000000000008 A=0x7ffffa2c
419271000: system.cpu: T0 : 0x1053e @_Z3LISiPiS_+266    : blt a4, a5, -178           : IntAlu : 
419273000: system.cpu: T0 : 0x1048c @_Z3LISiPiS_+88    : sw zero, -32(s0)           : MemWrite :  D=0x0000000000000000 A=0x7ffffa40
419277000: system.cpu: T0 : 0x10490 @_Z3LISiPiS_+92    : c_j 104                    : IntAlu : 
419279000: system.cpu: T0 : 0x104f8 @_Z3LISiPiS_+196    : lw a4, -32(s0)             : MemRead :  D=0x0000000000000000 A=0x7ffffa40
419283000: system.cpu: T0 : 0x104fc @_Z3LISiPiS_+200    : lw a5, -28(s0)             : MemRead :  D=0x0000000000000003 A=0x7ffffa44
419287000: system.cpu: T0 : 0x10500 @_Z3LISiPiS_+204    : blt a4, a5, -110           : IntAlu : 
419291000: system.cpu: T0 : 0x10492 @_Z3LISiPiS_+94    : lw a5, -28(s0)             : MemRead :  D=0x0000000000000003 A=0x7ffffa44
419295000: system.cpu: T0 : 0x10496 @_Z3LISiPiS_+98    : c_slli a5, 2               : IntAlu :  D=0x000000000000000c
419297000: system.cpu: T0 : 0x10498 @_Z3LISiPiS_+100    : lw a4, -56(s0)             : MemRead :  D=0x000000007ffffe8c A=0x7ffffa28
419301000: system.cpu: T0 : 0x1049c @_Z3LISiPiS_+104    : c_add a5, a4               : IntAlu :  D=0x000000007ffffe98
419303000: system.cpu: T0 : 0x1049e @_Z3LISiPiS_+106    : c_lw a4, 0(a5)             : MemRead :  D=0x0000000000000008 A=0x7ffffe98
419307000: system.cpu: T0 : 0x104a0 @_Z3LISiPiS_+108    : lw a5, -32(s0)             : MemRead :  D=0x0000000000000000 A=0x7ffffa40
419311000: system.cpu: T0 : 0x104a4 @_Z3LISiPiS_+112    : c_slli a5, 2               : IntAlu :  D=0x0000000000000000
419315000: system.cpu: T0 : 0x104a6 @_Z3LISiPiS_+114    : lw a3, -56(s0)             : MemRead :  D=0x000000007ffffe8c A=0x7ffffa28
419319000: system.cpu: T0 : 0x104aa @_Z3LISiPiS_+118    : c_add a5, a3               : IntAlu :  D=0x000000007ffffe8c
419321000: system.cpu: T0 : 0x104ac @_Z3LISiPiS_+120    : c_lw a5, 0(a5)             : MemRead :  D=0x0000000000000004 A=0x7ffffe8c
419327000: system.cpu: T0 : 0x104ae @_Z3LISiPiS_+122    : bge a5, a4, 64             : IntAlu : 
419331000: system.cpu: T0 : 0x104b2 @_Z3LISiPiS_+126    : lw a5, -32(s0)             : MemRead :  D=0x0000000000000000 A=0x7ffffa40
419335000: system.cpu: T0 : 0x104b6 @_Z3LISiPiS_+130    : c_slli a5, 2               : IntAlu :  D=0x0000000000000000
419337000: system.cpu: T0 : 0x104b8 @_Z3LISiPiS_+132    : lw a4, -60(s0)             : MemRead :  D=0x000000007ffffa60 A=0x7ffffa24
419341000: system.cpu: T0 : 0x104bc @_Z3LISiPiS_+136    : c_add a5, a4               : IntAlu :  D=0x000000007ffffa60
419343000: system.cpu: T0 : 0x104be @_Z3LISiPiS_+138    : c_lw a5, 0(a5)             : MemRead :  D=0x0000000000000001 A=0x7ffffa60
419347000: system.cpu: T0 : 0x104c0 @_Z3LISiPiS_+140    : c_addi a5, 1               : IntAlu :  D=0x0000000000000002
419351000: system.cpu: T0 : 0x104c2 @_Z3LISiPiS_+142    : sw a5, -36(s0)             : MemWrite :  D=0x0000000000000002 A=0x7ffffa3c
419357000: system.cpu: T0 : 0x104c6 @_Z3LISiPiS_+146    : lw a5, -28(s0)             : MemRead :  D=0x0000000000000003 A=0x7ffffa44
419361000: system.cpu: T0 : 0x104ca @_Z3LISiPiS_+150    : c_slli a5, 2               : IntAlu :  D=0x000000000000000c
419363000: system.cpu: T0 : 0x104cc @_Z3LISiPiS_+152    : lw a4, -60(s0)             : MemRead :  D=0x000000007ffffa60 A=0x7ffffa24
419367000: system.cpu: T0 : 0x104d0 @_Z3LISiPiS_+156    : c_add a5, a4               : IntAlu :  D=0x000000007ffffa6c
419369000: system.cpu: T0 : 0x104d2 @_Z3LISiPiS_+158    : c_lw a5, 0(a5)             : MemRead :  D=0x0000000000000001 A=0x7ffffa6c
419373000: system.cpu: T0 : 0x104d4 @_Z3LISiPiS_+160    : lw a4, -36(s0)             : MemRead :  D=0x0000000000000002 A=0x7ffffa3c
419377000: system.cpu: T0 : 0x104d8 @_Z3LISiPiS_+164    : bge a5, a4, 22             : IntAlu : 
419379000: system.cpu: T0 : 0x104dc @_Z3LISiPiS_+168    : lw a5, -28(s0)             : MemRead :  D=0x0000000000000003 A=0x7ffffa44
419383000: system.cpu: T0 : 0x104e0 @_Z3LISiPiS_+172    : c_slli a5, 2               : IntAlu :  D=0x000000000000000c
419387000: system.cpu: T0 : 0x104e2 @_Z3LISiPiS_+174    : lw a4, -60(s0)             : MemRead :  D=0x000000007ffffa60 A=0x7ffffa24
419391000: system.cpu: T0 : 0x104e6 @_Z3LISiPiS_+178    : c_add a5, a4               : IntAlu :  D=0x000000007ffffa6c
419393000: system.cpu: T0 : 0x104e8 @_Z3LISiPiS_+180    : lw a4, -36(s0)             : MemRead :  D=0x0000000000000002 A=0x7ffffa3c
419397000: system.cpu: T0 : 0x104ec @_Z3LISiPiS_+184    : c_sw a4, 0(a5)             : MemWrite :  D=0x0000000000000002 A=0x7ffffa6c
419403000: system.cpu: T0 : 0x104ee @_Z3LISiPiS_+186    : lw a5, -32(s0)             : MemRead :  D=0x0000000000000000 A=0x7ffffa40
419407000: system.cpu: T0 : 0x104f2 @_Z3LISiPiS_+190    : c_addi a5, 1               : IntAlu :  D=0x0000000000000001
419409000: system.cpu: T0 : 0x104f4 @_Z3LISiPiS_+192    : sw a5, -32(s0)             : MemWrite :  D=0x0000000000000001 A=0x7ffffa40
419413000: system.cpu: T0 : 0x104f8 @_Z3LISiPiS_+196    : lw a4, -32(s0)             : MemRead :  D=0x0000000000000001 A=0x7ffffa40
419417000: system.cpu: T0 : 0x104fc @_Z3LISiPiS_+200    : lw a5, -28(s0)             : MemRead :  D=0x0000000000000003 A=0x7ffffa44
419421000: system.cpu: T0 : 0x10500 @_Z3LISiPiS_+204    : blt a4, a5, -110           : IntAlu : 
419425000: system.cpu: T0 : 0x10492 @_Z3LISiPiS_+94    : lw a5, -28(s0)             : MemRead :  D=0x0000000000000003 A=0x7ffffa44
419429000: system.cpu: T0 : 0x10496 @_Z3LISiPiS_+98    : c_slli a5, 2               : IntAlu :  D=0x000000000000000c
419431000: system.cpu: T0 : 0x10498 @_Z3LISiPiS_+100    : lw a4, -56(s0)             : MemRead :  D=0x000000007ffffe8c A=0x7ffffa28
419435000: system.cpu: T0 : 0x1049c @_Z3LISiPiS_+104    : c_add a5, a4               : IntAlu :  D=0x000000007ffffe98
419437000: system.cpu: T0 : 0x1049e @_Z3LISiPiS_+106    : c_lw a4, 0(a5)             : MemRead :  D=0x0000000000000008 A=0x7ffffe98
419441000: system.cpu: T0 : 0x104a0 @_Z3LISiPiS_+108    : lw a5, -32(s0)             : MemRead :  D=0x0000000000000001 A=0x7ffffa40
419445000: system.cpu: T0 : 0x104a4 @_Z3LISiPiS_+112    : c_slli a5, 2               : IntAlu :  D=0x0000000000000004
419449000: system.cpu: T0 : 0x104a6 @_Z3LISiPiS_+114    : lw a3, -56(s0)             : MemRead :  D=0x000000007ffffe8c A=0x7ffffa28
419453000: system.cpu: T0 : 0x104aa @_Z3LISiPiS_+118    : c_add a5, a3               : IntAlu :  D=0x000000007ffffe90
419455000: system.cpu: T0 : 0x104ac @_Z3LISiPiS_+120    : c_lw a5, 0(a5)             : MemRead :  D=0x0000000000000005 A=0x7ffffe90
419461000: system.cpu: T0 : 0x104ae @_Z3LISiPiS_+122    : bge a5, a4, 64             : IntAlu : 
419465000: system.cpu: T0 : 0x104b2 @_Z3LISiPiS_+126    : lw a5, -32(s0)             : MemRead :  D=0x0000000000000001 A=0x7ffffa40
419469000: system.cpu: T0 : 0x104b6 @_Z3LISiPiS_+130    : c_slli a5, 2               : IntAlu :  D=0x0000000000000004
419471000: system.cpu: T0 : 0x104b8 @_Z3LISiPiS_+132    : lw a4, -60(s0)             : MemRead :  D=0x000000007ffffa60 A=0x7ffffa24
419475000: system.cpu: T0 : 0x104bc @_Z3LISiPiS_+136    : c_add a5, a4               : IntAlu :  D=0x000000007ffffa64
419477000: system.cpu: T0 : 0x104be @_Z3LISiPiS_+138    : c_lw a5, 0(a5)             : MemRead :  D=0x0000000000000002 A=0x7ffffa64
419481000: system.cpu: T0 : 0x104c0 @_Z3LISiPiS_+140    : c_addi a5, 1               : IntAlu :  D=0x0000000000000003
419485000: system.cpu: T0 : 0x104c2 @_Z3LISiPiS_+142    : sw a5, -36(s0)             : MemWrite :  D=0x0000000000000003 A=0x7ffffa3c
419491000: system.cpu: T0 : 0x104c6 @_Z3LISiPiS_+146    : lw a5, -28(s0)             : MemRead :  D=0x0000000000000003 A=0x7ffffa44
419495000: system.cpu: T0 : 0x104ca @_Z3LISiPiS_+150    : c_slli a5, 2               : IntAlu :  D=0x000000000000000c
419497000: system.cpu: T0 : 0x104cc @_Z3LISiPiS_+152    : lw a4, -60(s0)             : MemRead :  D=0x000000007ffffa60 A=0x7ffffa24
419501000: system.cpu: T0 : 0x104d0 @_Z3LISiPiS_+156    : c_add a5, a4               : IntAlu :  D=0x000000007ffffa6c
419503000: system.cpu: T0 : 0x104d2 @_Z3LISiPiS_+158    : c_lw a5, 0(a5)             : MemRead :  D=0x0000000000000002 A=0x7ffffa6c
419507000: system.cpu: T0 : 0x104d4 @_Z3LISiPiS_+160    : lw a4, -36(s0)             : MemRead :  D=0x0000000000000003 A=0x7ffffa3c
419511000: system.cpu: T0 : 0x104d8 @_Z3LISiPiS_+164    : bge a5, a4, 22             : IntAlu : 
419513000: system.cpu: T0 : 0x104dc @_Z3LISiPiS_+168    : lw a5, -28(s0)             : MemRead :  D=0x0000000000000003 A=0x7ffffa44
419517000: system.cpu: T0 : 0x104e0 @_Z3LISiPiS_+172    : c_slli a5, 2               : IntAlu :  D=0x000000000000000c
419521000: system.cpu: T0 : 0x104e2 @_Z3LISiPiS_+174    : lw a4, -60(s0)             : MemRead :  D=0x000000007ffffa60 A=0x7ffffa24
419525000: system.cpu: T0 : 0x104e6 @_Z3LISiPiS_+178    : c_add a5, a4               : IntAlu :  D=0x000000007ffffa6c
419527000: system.cpu: T0 : 0x104e8 @_Z3LISiPiS_+180    : lw a4, -36(s0)             : MemRead :  D=0x0000000000000003 A=0x7ffffa3c
419531000: system.cpu: T0 : 0x104ec @_Z3LISiPiS_+184    : c_sw a4, 0(a5)             : MemWrite :  D=0x0000000000000003 A=0x7ffffa6c
419537000: system.cpu: T0 : 0x104ee @_Z3LISiPiS_+186    : lw a5, -32(s0)             : MemRead :  D=0x0000000000000001 A=0x7ffffa40
419541000: system.cpu: T0 : 0x104f2 @_Z3LISiPiS_+190    : c_addi a5, 1               : IntAlu :  D=0x0000000000000002
419543000: system.cpu: T0 : 0x104f4 @_Z3LISiPiS_+192    : sw a5, -32(s0)             : MemWrite :  D=0x0000000000000002 A=0x7ffffa40
419547000: system.cpu: T0 : 0x104f8 @_Z3LISiPiS_+196    : lw a4, -32(s0)             : MemRead :  D=0x0000000000000002 A=0x7ffffa40
419551000: system.cpu: T0 : 0x104fc @_Z3LISiPiS_+200    : lw a5, -28(s0)             : MemRead :  D=0x0000000000000003 A=0x7ffffa44
419555000: system.cpu: T0 : 0x10500 @_Z3LISiPiS_+204    : blt a4, a5, -110           : IntAlu : 
419559000: system.cpu: T0 : 0x10492 @_Z3LISiPiS_+94    : lw a5, -28(s0)             : MemRead :  D=0x0000000000000003 A=0x7ffffa44
419563000: system.cpu: T0 : 0x10496 @_Z3LISiPiS_+98    : c_slli a5, 2               : IntAlu :  D=0x000000000000000c
419565000: system.cpu: T0 : 0x10498 @_Z3LISiPiS_+100    : lw a4, -56(s0)             : MemRead :  D=0x000000007ffffe8c A=0x7ffffa28
419569000: system.cpu: T0 : 0x1049c @_Z3LISiPiS_+104    : c_add a5, a4               : IntAlu :  D=0x000000007ffffe98
419571000: system.cpu: T0 : 0x1049e @_Z3LISiPiS_+106    : c_lw a4, 0(a5)             : MemRead :  D=0x0000000000000008 A=0x7ffffe98
419575000: system.cpu: T0 : 0x104a0 @_Z3LISiPiS_+108    : lw a5, -32(s0)             : MemRead :  D=0x0000000000000002 A=0x7ffffa40
419579000: system.cpu: T0 : 0x104a4 @_Z3LISiPiS_+112    : c_slli a5, 2               : IntAlu :  D=0x0000000000000008
419583000: system.cpu: T0 : 0x104a6 @_Z3LISiPiS_+114    : lw a3, -56(s0)             : MemRead :  D=0x000000007ffffe8c A=0x7ffffa28
419587000: system.cpu: T0 : 0x104aa @_Z3LISiPiS_+118    : c_add a5, a3               : IntAlu :  D=0x000000007ffffe94
419589000: system.cpu: T0 : 0x104ac @_Z3LISiPiS_+120    : c_lw a5, 0(a5)             : MemRead :  D=0x0000000000000001 A=0x7ffffe94
419595000: system.cpu: T0 : 0x104ae @_Z3LISiPiS_+122    : bge a5, a4, 64             : IntAlu : 
419599000: system.cpu: T0 : 0x104b2 @_Z3LISiPiS_+126    : lw a5, -32(s0)             : MemRead :  D=0x0000000000000002 A=0x7ffffa40
419603000: system.cpu: T0 : 0x104b6 @_Z3LISiPiS_+130    : c_slli a5, 2               : IntAlu :  D=0x0000000000000008
419605000: system.cpu: T0 : 0x104b8 @_Z3LISiPiS_+132    : lw a4, -60(s0)             : MemRead :  D=0x000000007ffffa60 A=0x7ffffa24
419609000: system.cpu: T0 : 0x104bc @_Z3LISiPiS_+136    : c_add a5, a4               : IntAlu :  D=0x000000007ffffa68
419611000: system.cpu: T0 : 0x104be @_Z3LISiPiS_+138    : c_lw a5, 0(a5)             : MemRead :  D=0x0000000000000001 A=0x7ffffa68
419615000: system.cpu: T0 : 0x104c0 @_Z3LISiPiS_+140    : c_addi a5, 1               : IntAlu :  D=0x0000000000000002
419619000: system.cpu: T0 : 0x104c2 @_Z3LISiPiS_+142    : sw a5, -36(s0)             : MemWrite :  D=0x0000000000000002 A=0x7ffffa3c
419625000: system.cpu: T0 : 0x104c6 @_Z3LISiPiS_+146    : lw a5, -28(s0)             : MemRead :  D=0x0000000000000003 A=0x7ffffa44
419629000: system.cpu: T0 : 0x104ca @_Z3LISiPiS_+150    : c_slli a5, 2               : IntAlu :  D=0x000000000000000c
419631000: system.cpu: T0 : 0x104cc @_Z3LISiPiS_+152    : lw a4, -60(s0)             : MemRead :  D=0x000000007ffffa60 A=0x7ffffa24
419635000: system.cpu: T0 : 0x104d0 @_Z3LISiPiS_+156    : c_add a5, a4               : IntAlu :  D=0x000000007ffffa6c
419637000: system.cpu: T0 : 0x104d2 @_Z3LISiPiS_+158    : c_lw a5, 0(a5)             : MemRead :  D=0x0000000000000003 A=0x7ffffa6c
419641000: system.cpu: T0 : 0x104d4 @_Z3LISiPiS_+160    : lw a4, -36(s0)             : MemRead :  D=0x0000000000000002 A=0x7ffffa3c
419645000: system.cpu: T0 : 0x104d8 @_Z3LISiPiS_+164    : bge a5, a4, 22             : IntAlu : 
419649000: system.cpu: T0 : 0x104ee @_Z3LISiPiS_+186    : lw a5, -32(s0)             : MemRead :  D=0x0000000000000002 A=0x7ffffa40
419653000: system.cpu: T0 : 0x104f2 @_Z3LISiPiS_+190    : c_addi a5, 1               : IntAlu :  D=0x0000000000000003
419655000: system.cpu: T0 : 0x104f4 @_Z3LISiPiS_+192    : sw a5, -32(s0)             : MemWrite :  D=0x0000000000000003 A=0x7ffffa40
419659000: system.cpu: T0 : 0x104f8 @_Z3LISiPiS_+196    : lw a4, -32(s0)             : MemRead :  D=0x0000000000000003 A=0x7ffffa40
419663000: system.cpu: T0 : 0x104fc @_Z3LISiPiS_+200    : lw a5, -28(s0)             : MemRead :  D=0x0000000000000003 A=0x7ffffa44
419667000: system.cpu: T0 : 0x10500 @_Z3LISiPiS_+204    : blt a4, a5, -110           : IntAlu : 
419669000: system.cpu: T0 : 0x10504 @_Z3LISiPiS_+208    : lw a5, -28(s0)             : MemRead :  D=0x0000000000000003 A=0x7ffffa44
419673000: system.cpu: T0 : 0x10508 @_Z3LISiPiS_+212    : c_slli a5, 2               : IntAlu :  D=0x000000000000000c
419677000: system.cpu: T0 : 0x1050a @_Z3LISiPiS_+214    : lw a4, -60(s0)             : MemRead :  D=0x000000007ffffa60 A=0x7ffffa24
419681000: system.cpu: T0 : 0x1050e @_Z3LISiPiS_+218    : c_add a5, a4               : IntAlu :  D=0x000000007ffffa6c
419683000: system.cpu: T0 : 0x10510 @_Z3LISiPiS_+220    : c_lw a5, 0(a5)             : MemRead :  D=0x0000000000000003 A=0x7ffffa6c
419689000: system.cpu: T0 : 0x10512 @_Z3LISiPiS_+222    : lw a4, -20(s0)             : MemRead :  D=0x0000000000000002 A=0x7ffffa4c
419695000: system.cpu: T0 : 0x10516 @_Z3LISiPiS_+226    : bge a4, a5, 22             : IntAlu : 
419699000: system.cpu: T0 : 0x1051a @_Z3LISiPiS_+230    : lw a5, -28(s0)             : MemRead :  D=0x0000000000000003 A=0x7ffffa44
419703000: system.cpu: T0 : 0x1051e @_Z3LISiPiS_+234    : c_slli a5, 2               : IntAlu :  D=0x000000000000000c
419705000: system.cpu: T0 : 0x10520 @_Z3LISiPiS_+236    : lw a4, -60(s0)             : MemRead :  D=0x000000007ffffa60 A=0x7ffffa24
419709000: system.cpu: T0 : 0x10524 @_Z3LISiPiS_+240    : c_add a5, a4               : IntAlu :  D=0x000000007ffffa6c
419711000: system.cpu: T0 : 0x10526 @_Z3LISiPiS_+242    : c_lw a5, 0(a5)             : MemRead :  D=0x0000000000000003 A=0x7ffffa6c
419715000: system.cpu: T0 : 0x10528 @_Z3LISiPiS_+244    : sw a5, -20(s0)             : MemWrite :  D=0x0000000000000003 A=0x7ffffa4c
419719000: system.cpu: T0 : 0x1052c @_Z3LISiPiS_+248    : lw a5, -28(s0)             : MemRead :  D=0x0000000000000003 A=0x7ffffa44
419723000: system.cpu: T0 : 0x10530 @_Z3LISiPiS_+252    : c_addi a5, 1               : IntAlu :  D=0x0000000000000004
419727000: system.cpu: T0 : 0x10532 @_Z3LISiPiS_+254    : sw a5, -28(s0)             : MemWrite :  D=0x0000000000000004 A=0x7ffffa44
419733000: system.cpu: T0 : 0x10536 @_Z3LISiPiS_+258    : lw a4, -28(s0)             : MemRead :  D=0x0000000000000004 A=0x7ffffa44
419739000: system.cpu: T0 : 0x1053a @_Z3LISiPiS_+262    : lw a5, -52(s0)             : MemRead :  D=0x0000000000000008 A=0x7ffffa2c
419745000: system.cpu: T0 : 0x1053e @_Z3LISiPiS_+266    : blt a4, a5, -178           : IntAlu : 
419747000: system.cpu: T0 : 0x1048c @_Z3LISiPiS_+88    : sw zero, -32(s0)           : MemWrite :  D=0x0000000000000000 A=0x7ffffa40
419751000: system.cpu: T0 : 0x10490 @_Z3LISiPiS_+92    : c_j 104                    : IntAlu : 
419753000: system.cpu: T0 : 0x104f8 @_Z3LISiPiS_+196    : lw a4, -32(s0)             : MemRead :  D=0x0000000000000000 A=0x7ffffa40
419757000: system.cpu: T0 : 0x104fc @_Z3LISiPiS_+200    : lw a5, -28(s0)             : MemRead :  D=0x0000000000000004 A=0x7ffffa44
419761000: system.cpu: T0 : 0x10500 @_Z3LISiPiS_+204    : blt a4, a5, -110           : IntAlu : 
419765000: system.cpu: T0 : 0x10492 @_Z3LISiPiS_+94    : lw a5, -28(s0)             : MemRead :  D=0x0000000000000004 A=0x7ffffa44
419769000: system.cpu: T0 : 0x10496 @_Z3LISiPiS_+98    : c_slli a5, 2               : IntAlu :  D=0x0000000000000010
419771000: system.cpu: T0 : 0x10498 @_Z3LISiPiS_+100    : lw a4, -56(s0)             : MemRead :  D=0x000000007ffffe8c A=0x7ffffa28
419775000: system.cpu: T0 : 0x1049c @_Z3LISiPiS_+104    : c_add a5, a4               : IntAlu :  D=0x000000007ffffe9c
419777000: system.cpu: T0 : 0x1049e @_Z3LISiPiS_+106    : c_lw a4, 0(a5)             : MemRead :  D=0x0000000000000003 A=0x7ffffe9c
419781000: system.cpu: T0 : 0x104a0 @_Z3LISiPiS_+108    : lw a5, -32(s0)             : MemRead :  D=0x0000000000000000 A=0x7ffffa40
419785000: system.cpu: T0 : 0x104a4 @_Z3LISiPiS_+112    : c_slli a5, 2               : IntAlu :  D=0x0000000000000000
419789000: system.cpu: T0 : 0x104a6 @_Z3LISiPiS_+114    : lw a3, -56(s0)             : MemRead :  D=0x000000007ffffe8c A=0x7ffffa28
419793000: system.cpu: T0 : 0x104aa @_Z3LISiPiS_+118    : c_add a5, a3               : IntAlu :  D=0x000000007ffffe8c
419795000: system.cpu: T0 : 0x104ac @_Z3LISiPiS_+120    : c_lw a5, 0(a5)             : MemRead :  D=0x0000000000000004 A=0x7ffffe8c
419801000: system.cpu: T0 : 0x104ae @_Z3LISiPiS_+122    : bge a5, a4, 64             : IntAlu : 
419805000: system.cpu: T0 : 0x104ee @_Z3LISiPiS_+186    : lw a5, -32(s0)             : MemRead :  D=0x0000000000000000 A=0x7ffffa40
419809000: system.cpu: T0 : 0x104f2 @_Z3LISiPiS_+190    : c_addi a5, 1               : IntAlu :  D=0x0000000000000001
419811000: system.cpu: T0 : 0x104f4 @_Z3LISiPiS_+192    : sw a5, -32(s0)             : MemWrite :  D=0x0000000000000001 A=0x7ffffa40
419815000: system.cpu: T0 : 0x104f8 @_Z3LISiPiS_+196    : lw a4, -32(s0)             : MemRead :  D=0x0000000000000001 A=0x7ffffa40
419819000: system.cpu: T0 : 0x104fc @_Z3LISiPiS_+200    : lw a5, -28(s0)             : MemRead :  D=0x0000000000000004 A=0x7ffffa44
419823000: system.cpu: T0 : 0x10500 @_Z3LISiPiS_+204    : blt a4, a5, -110           : IntAlu : 
419827000: system.cpu: T0 : 0x10492 @_Z3LISiPiS_+94    : lw a5, -28(s0)             : MemRead :  D=0x0000000000000004 A=0x7ffffa44
419831000: system.cpu: T0 : 0x10496 @_Z3LISiPiS_+98    : c_slli a5, 2               : IntAlu :  D=0x0000000000000010
419833000: system.cpu: T0 : 0x10498 @_Z3LISiPiS_+100    : lw a4, -56(s0)             : MemRead :  D=0x000000007ffffe8c A=0x7ffffa28
419837000: system.cpu: T0 : 0x1049c @_Z3LISiPiS_+104    : c_add a5, a4               : IntAlu :  D=0x000000007ffffe9c
419839000: system.cpu: T0 : 0x1049e @_Z3LISiPiS_+106    : c_lw a4, 0(a5)             : MemRead :  D=0x0000000000000003 A=0x7ffffe9c
419843000: system.cpu: T0 : 0x104a0 @_Z3LISiPiS_+108    : lw a5, -32(s0)             : MemRead :  D=0x0000000000000001 A=0x7ffffa40
419847000: system.cpu: T0 : 0x104a4 @_Z3LISiPiS_+112    : c_slli a5, 2               : IntAlu :  D=0x0000000000000004
419851000: system.cpu: T0 : 0x104a6 @_Z3LISiPiS_+114    : lw a3, -56(s0)             : MemRead :  D=0x000000007ffffe8c A=0x7ffffa28
419855000: system.cpu: T0 : 0x104aa @_Z3LISiPiS_+118    : c_add a5, a3               : IntAlu :  D=0x000000007ffffe90
419857000: system.cpu: T0 : 0x104ac @_Z3LISiPiS_+120    : c_lw a5, 0(a5)             : MemRead :  D=0x0000000000000005 A=0x7ffffe90
419863000: system.cpu: T0 : 0x104ae @_Z3LISiPiS_+122    : bge a5, a4, 64             : IntAlu : 
419867000: system.cpu: T0 : 0x104ee @_Z3LISiPiS_+186    : lw a5, -32(s0)             : MemRead :  D=0x0000000000000001 A=0x7ffffa40
419871000: system.cpu: T0 : 0x104f2 @_Z3LISiPiS_+190    : c_addi a5, 1               : IntAlu :  D=0x0000000000000002
419873000: system.cpu: T0 : 0x104f4 @_Z3LISiPiS_+192    : sw a5, -32(s0)             : MemWrite :  D=0x0000000000000002 A=0x7ffffa40
419877000: system.cpu: T0 : 0x104f8 @_Z3LISiPiS_+196    : lw a4, -32(s0)             : MemRead :  D=0x0000000000000002 A=0x7ffffa40
419881000: system.cpu: T0 : 0x104fc @_Z3LISiPiS_+200    : lw a5, -28(s0)             : MemRead :  D=0x0000000000000004 A=0x7ffffa44
419885000: system.cpu: T0 : 0x10500 @_Z3LISiPiS_+204    : blt a4, a5, -110           : IntAlu : 
419889000: system.cpu: T0 : 0x10492 @_Z3LISiPiS_+94    : lw a5, -28(s0)             : MemRead :  D=0x0000000000000004 A=0x7ffffa44
419893000: system.cpu: T0 : 0x10496 @_Z3LISiPiS_+98    : c_slli a5, 2               : IntAlu :  D=0x0000000000000010
419895000: system.cpu: T0 : 0x10498 @_Z3LISiPiS_+100    : lw a4, -56(s0)             : MemRead :  D=0x000000007ffffe8c A=0x7ffffa28
419899000: system.cpu: T0 : 0x1049c @_Z3LISiPiS_+104    : c_add a5, a4               : IntAlu :  D=0x000000007ffffe9c
419901000: system.cpu: T0 : 0x1049e @_Z3LISiPiS_+106    : c_lw a4, 0(a5)             : MemRead :  D=0x0000000000000003 A=0x7ffffe9c
419905000: system.cpu: T0 : 0x104a0 @_Z3LISiPiS_+108    : lw a5, -32(s0)             : MemRead :  D=0x0000000000000002 A=0x7ffffa40
419909000: system.cpu: T0 : 0x104a4 @_Z3LISiPiS_+112    : c_slli a5, 2               : IntAlu :  D=0x0000000000000008
419913000: system.cpu: T0 : 0x104a6 @_Z3LISiPiS_+114    : lw a3, -56(s0)             : MemRead :  D=0x000000007ffffe8c A=0x7ffffa28
419917000: system.cpu: T0 : 0x104aa @_Z3LISiPiS_+118    : c_add a5, a3               : IntAlu :  D=0x000000007ffffe94
419919000: system.cpu: T0 : 0x104ac @_Z3LISiPiS_+120    : c_lw a5, 0(a5)             : MemRead :  D=0x0000000000000001 A=0x7ffffe94
419925000: system.cpu: T0 : 0x104ae @_Z3LISiPiS_+122    : bge a5, a4, 64             : IntAlu : 
419929000: system.cpu: T0 : 0x104b2 @_Z3LISiPiS_+126    : lw a5, -32(s0)             : MemRead :  D=0x0000000000000002 A=0x7ffffa40
419933000: system.cpu: T0 : 0x104b6 @_Z3LISiPiS_+130    : c_slli a5, 2               : IntAlu :  D=0x0000000000000008
419935000: system.cpu: T0 : 0x104b8 @_Z3LISiPiS_+132    : lw a4, -60(s0)             : MemRead :  D=0x000000007ffffa60 A=0x7ffffa24
419939000: system.cpu: T0 : 0x104bc @_Z3LISiPiS_+136    : c_add a5, a4               : IntAlu :  D=0x000000007ffffa68
419941000: system.cpu: T0 : 0x104be @_Z3LISiPiS_+138    : c_lw a5, 0(a5)             : MemRead :  D=0x0000000000000001 A=0x7ffffa68
419945000: system.cpu: T0 : 0x104c0 @_Z3LISiPiS_+140    : c_addi a5, 1               : IntAlu :  D=0x0000000000000002
419949000: system.cpu: T0 : 0x104c2 @_Z3LISiPiS_+142    : sw a5, -36(s0)             : MemWrite :  D=0x0000000000000002 A=0x7ffffa3c
419955000: system.cpu: T0 : 0x104c6 @_Z3LISiPiS_+146    : lw a5, -28(s0)             : MemRead :  D=0x0000000000000004 A=0x7ffffa44
419959000: system.cpu: T0 : 0x104ca @_Z3LISiPiS_+150    : c_slli a5, 2               : IntAlu :  D=0x0000000000000010
419961000: system.cpu: T0 : 0x104cc @_Z3LISiPiS_+152    : lw a4, -60(s0)             : MemRead :  D=0x000000007ffffa60 A=0x7ffffa24
419965000: system.cpu: T0 : 0x104d0 @_Z3LISiPiS_+156    : c_add a5, a4               : IntAlu :  D=0x000000007ffffa70
419967000: system.cpu: T0 : 0x104d2 @_Z3LISiPiS_+158    : c_lw a5, 0(a5)             : MemRead :  D=0x0000000000000001 A=0x7ffffa70
419971000: system.cpu: T0 : 0x104d4 @_Z3LISiPiS_+160    : lw a4, -36(s0)             : MemRead :  D=0x0000000000000002 A=0x7ffffa3c
419975000: system.cpu: T0 : 0x104d8 @_Z3LISiPiS_+164    : bge a5, a4, 22             : IntAlu : 
419977000: system.cpu: T0 : 0x104dc @_Z3LISiPiS_+168    : lw a5, -28(s0)             : MemRead :  D=0x0000000000000004 A=0x7ffffa44
419981000: system.cpu: T0 : 0x104e0 @_Z3LISiPiS_+172    : c_slli a5, 2               : IntAlu :  D=0x0000000000000010
419985000: system.cpu: T0 : 0x104e2 @_Z3LISiPiS_+174    : lw a4, -60(s0)             : MemRead :  D=0x000000007ffffa60 A=0x7ffffa24
419989000: system.cpu: T0 : 0x104e6 @_Z3LISiPiS_+178    : c_add a5, a4               : IntAlu :  D=0x000000007ffffa70
419991000: system.cpu: T0 : 0x104e8 @_Z3LISiPiS_+180    : lw a4, -36(s0)             : MemRead :  D=0x0000000000000002 A=0x7ffffa3c
419995000: system.cpu: T0 : 0x104ec @_Z3LISiPiS_+184    : c_sw a4, 0(a5)             : MemWrite :  D=0x0000000000000002 A=0x7ffffa70
420001000: system.cpu: T0 : 0x104ee @_Z3LISiPiS_+186    : lw a5, -32(s0)             : MemRead :  D=0x0000000000000002 A=0x7ffffa40
420005000: system.cpu: T0 : 0x104f2 @_Z3LISiPiS_+190    : c_addi a5, 1               : IntAlu :  D=0x0000000000000003
420007000: system.cpu: T0 : 0x104f4 @_Z3LISiPiS_+192    : sw a5, -32(s0)             : MemWrite :  D=0x0000000000000003 A=0x7ffffa40
420011000: system.cpu: T0 : 0x104f8 @_Z3LISiPiS_+196    : lw a4, -32(s0)             : MemRead :  D=0x0000000000000003 A=0x7ffffa40
420015000: system.cpu: T0 : 0x104fc @_Z3LISiPiS_+200    : lw a5, -28(s0)             : MemRead :  D=0x0000000000000004 A=0x7ffffa44
420019000: system.cpu: T0 : 0x10500 @_Z3LISiPiS_+204    : blt a4, a5, -110           : IntAlu : 
420023000: system.cpu: T0 : 0x10492 @_Z3LISiPiS_+94    : lw a5, -28(s0)             : MemRead :  D=0x0000000000000004 A=0x7ffffa44
420027000: system.cpu: T0 : 0x10496 @_Z3LISiPiS_+98    : c_slli a5, 2               : IntAlu :  D=0x0000000000000010
420029000: system.cpu: T0 : 0x10498 @_Z3LISiPiS_+100    : lw a4, -56(s0)             : MemRead :  D=0x000000007ffffe8c A=0x7ffffa28
420033000: system.cpu: T0 : 0x1049c @_Z3LISiPiS_+104    : c_add a5, a4               : IntAlu :  D=0x000000007ffffe9c
420035000: system.cpu: T0 : 0x1049e @_Z3LISiPiS_+106    : c_lw a4, 0(a5)             : MemRead :  D=0x0000000000000003 A=0x7ffffe9c
420039000: system.cpu: T0 : 0x104a0 @_Z3LISiPiS_+108    : lw a5, -32(s0)             : MemRead :  D=0x0000000000000003 A=0x7ffffa40
420043000: system.cpu: T0 : 0x104a4 @_Z3LISiPiS_+112    : c_slli a5, 2               : IntAlu :  D=0x000000000000000c
420047000: system.cpu: T0 : 0x104a6 @_Z3LISiPiS_+114    : lw a3, -56(s0)             : MemRead :  D=0x000000007ffffe8c A=0x7ffffa28
420051000: system.cpu: T0 : 0x104aa @_Z3LISiPiS_+118    : c_add a5, a3               : IntAlu :  D=0x000000007ffffe98
420053000: system.cpu: T0 : 0x104ac @_Z3LISiPiS_+120    : c_lw a5, 0(a5)             : MemRead :  D=0x0000000000000008 A=0x7ffffe98
420059000: system.cpu: T0 : 0x104ae @_Z3LISiPiS_+122    : bge a5, a4, 64             : IntAlu : 
420063000: system.cpu: T0 : 0x104ee @_Z3LISiPiS_+186    : lw a5, -32(s0)             : MemRead :  D=0x0000000000000003 A=0x7ffffa40
420067000: system.cpu: T0 : 0x104f2 @_Z3LISiPiS_+190    : c_addi a5, 1               : IntAlu :  D=0x0000000000000004
420069000: system.cpu: T0 : 0x104f4 @_Z3LISiPiS_+192    : sw a5, -32(s0)             : MemWrite :  D=0x0000000000000004 A=0x7ffffa40
420073000: system.cpu: T0 : 0x104f8 @_Z3LISiPiS_+196    : lw a4, -32(s0)             : MemRead :  D=0x0000000000000004 A=0x7ffffa40
420077000: system.cpu: T0 : 0x104fc @_Z3LISiPiS_+200    : lw a5, -28(s0)             : MemRead :  D=0x0000000000000004 A=0x7ffffa44
420081000: system.cpu: T0 : 0x10500 @_Z3LISiPiS_+204    : blt a4, a5, -110           : IntAlu : 
420083000: system.cpu: T0 : 0x10504 @_Z3LISiPiS_+208    : lw a5, -28(s0)             : MemRead :  D=0x0000000000000004 A=0x7ffffa44
420087000: system.cpu: T0 : 0x10508 @_Z3LISiPiS_+212    : c_slli a5, 2               : IntAlu :  D=0x0000000000000010
420091000: system.cpu: T0 : 0x1050a @_Z3LISiPiS_+214    : lw a4, -60(s0)             : MemRead :  D=0x000000007ffffa60 A=0x7ffffa24
420095000: system.cpu: T0 : 0x1050e @_Z3LISiPiS_+218    : c_add a5, a4               : IntAlu :  D=0x000000007ffffa70
420097000: system.cpu: T0 : 0x10510 @_Z3LISiPiS_+220    : c_lw a5, 0(a5)             : MemRead :  D=0x0000000000000002 A=0x7ffffa70
420103000: system.cpu: T0 : 0x10512 @_Z3LISiPiS_+222    : lw a4, -20(s0)             : MemRead :  D=0x0000000000000003 A=0x7ffffa4c
420109000: system.cpu: T0 : 0x10516 @_Z3LISiPiS_+226    : bge a4, a5, 22             : IntAlu : 
420111000: system.cpu: T0 : 0x1052c @_Z3LISiPiS_+248    : lw a5, -28(s0)             : MemRead :  D=0x0000000000000004 A=0x7ffffa44
420115000: system.cpu: T0 : 0x10530 @_Z3LISiPiS_+252    : c_addi a5, 1               : IntAlu :  D=0x0000000000000005
420119000: system.cpu: T0 : 0x10532 @_Z3LISiPiS_+254    : sw a5, -28(s0)             : MemWrite :  D=0x0000000000000005 A=0x7ffffa44
420125000: system.cpu: T0 : 0x10536 @_Z3LISiPiS_+258    : lw a4, -28(s0)             : MemRead :  D=0x0000000000000005 A=0x7ffffa44
420131000: system.cpu: T0 : 0x1053a @_Z3LISiPiS_+262    : lw a5, -52(s0)             : MemRead :  D=0x0000000000000008 A=0x7ffffa2c
420137000: system.cpu: T0 : 0x1053e @_Z3LISiPiS_+266    : blt a4, a5, -178           : IntAlu : 
420139000: system.cpu: T0 : 0x1048c @_Z3LISiPiS_+88    : sw zero, -32(s0)           : MemWrite :  D=0x0000000000000000 A=0x7ffffa40
420143000: system.cpu: T0 : 0x10490 @_Z3LISiPiS_+92    : c_j 104                    : IntAlu : 
420145000: system.cpu: T0 : 0x104f8 @_Z3LISiPiS_+196    : lw a4, -32(s0)             : MemRead :  D=0x0000000000000000 A=0x7ffffa40
420149000: system.cpu: T0 : 0x104fc @_Z3LISiPiS_+200    : lw a5, -28(s0)             : MemRead :  D=0x0000000000000005 A=0x7ffffa44
420153000: system.cpu: T0 : 0x10500 @_Z3LISiPiS_+204    : blt a4, a5, -110           : IntAlu : 
420157000: system.cpu: T0 : 0x10492 @_Z3LISiPiS_+94    : lw a5, -28(s0)             : MemRead :  D=0x0000000000000005 A=0x7ffffa44
420161000: system.cpu: T0 : 0x10496 @_Z3LISiPiS_+98    : c_slli a5, 2               : IntAlu :  D=0x0000000000000014
420163000: system.cpu: T0 : 0x10498 @_Z3LISiPiS_+100    : lw a4, -56(s0)             : MemRead :  D=0x000000007ffffe8c A=0x7ffffa28
420167000: system.cpu: T0 : 0x1049c @_Z3LISiPiS_+104    : c_add a5, a4               : IntAlu :  D=0x000000007ffffea0
420169000: system.cpu: T0 : 0x1049e @_Z3LISiPiS_+106    : c_lw a4, 0(a5)             : MemRead :  D=0x0000000000000006 A=0x7ffffea0
420173000: system.cpu: T0 : 0x104a0 @_Z3LISiPiS_+108    : lw a5, -32(s0)             : MemRead :  D=0x0000000000000000 A=0x7ffffa40
420177000: system.cpu: T0 : 0x104a4 @_Z3LISiPiS_+112    : c_slli a5, 2               : IntAlu :  D=0x0000000000000000
420181000: system.cpu: T0 : 0x104a6 @_Z3LISiPiS_+114    : lw a3, -56(s0)             : MemRead :  D=0x000000007ffffe8c A=0x7ffffa28
420185000: system.cpu: T0 : 0x104aa @_Z3LISiPiS_+118    : c_add a5, a3               : IntAlu :  D=0x000000007ffffe8c
420187000: system.cpu: T0 : 0x104ac @_Z3LISiPiS_+120    : c_lw a5, 0(a5)             : MemRead :  D=0x0000000000000004 A=0x7ffffe8c
420193000: system.cpu: T0 : 0x104ae @_Z3LISiPiS_+122    : bge a5, a4, 64             : IntAlu : 
420197000: system.cpu: T0 : 0x104b2 @_Z3LISiPiS_+126    : lw a5, -32(s0)             : MemRead :  D=0x0000000000000000 A=0x7ffffa40
420201000: system.cpu: T0 : 0x104b6 @_Z3LISiPiS_+130    : c_slli a5, 2               : IntAlu :  D=0x0000000000000000
420203000: system.cpu: T0 : 0x104b8 @_Z3LISiPiS_+132    : lw a4, -60(s0)             : MemRead :  D=0x000000007ffffa60 A=0x7ffffa24
420207000: system.cpu: T0 : 0x104bc @_Z3LISiPiS_+136    : c_add a5, a4               : IntAlu :  D=0x000000007ffffa60
420209000: system.cpu: T0 : 0x104be @_Z3LISiPiS_+138    : c_lw a5, 0(a5)             : MemRead :  D=0x0000000000000001 A=0x7ffffa60
420213000: system.cpu: T0 : 0x104c0 @_Z3LISiPiS_+140    : c_addi a5, 1               : IntAlu :  D=0x0000000000000002
420217000: system.cpu: T0 : 0x104c2 @_Z3LISiPiS_+142    : sw a5, -36(s0)             : MemWrite :  D=0x0000000000000002 A=0x7ffffa3c
420223000: system.cpu: T0 : 0x104c6 @_Z3LISiPiS_+146    : lw a5, -28(s0)             : MemRead :  D=0x0000000000000005 A=0x7ffffa44
420227000: system.cpu: T0 : 0x104ca @_Z3LISiPiS_+150    : c_slli a5, 2               : IntAlu :  D=0x0000000000000014
420229000: system.cpu: T0 : 0x104cc @_Z3LISiPiS_+152    : lw a4, -60(s0)             : MemRead :  D=0x000000007ffffa60 A=0x7ffffa24
420233000: system.cpu: T0 : 0x104d0 @_Z3LISiPiS_+156    : c_add a5, a4               : IntAlu :  D=0x000000007ffffa74
420235000: system.cpu: T0 : 0x104d2 @_Z3LISiPiS_+158    : c_lw a5, 0(a5)             : MemRead :  D=0x0000000000000001 A=0x7ffffa74
420239000: system.cpu: T0 : 0x104d4 @_Z3LISiPiS_+160    : lw a4, -36(s0)             : MemRead :  D=0x0000000000000002 A=0x7ffffa3c
420243000: system.cpu: T0 : 0x104d8 @_Z3LISiPiS_+164    : bge a5, a4, 22             : IntAlu : 
420245000: system.cpu: T0 : 0x104dc @_Z3LISiPiS_+168    : lw a5, -28(s0)             : MemRead :  D=0x0000000000000005 A=0x7ffffa44
420249000: system.cpu: T0 : 0x104e0 @_Z3LISiPiS_+172    : c_slli a5, 2               : IntAlu :  D=0x0000000000000014
420253000: system.cpu: T0 : 0x104e2 @_Z3LISiPiS_+174    : lw a4, -60(s0)             : MemRead :  D=0x000000007ffffa60 A=0x7ffffa24
420257000: system.cpu: T0 : 0x104e6 @_Z3LISiPiS_+178    : c_add a5, a4               : IntAlu :  D=0x000000007ffffa74
420259000: system.cpu: T0 : 0x104e8 @_Z3LISiPiS_+180    : lw a4, -36(s0)             : MemRead :  D=0x0000000000000002 A=0x7ffffa3c
420263000: system.cpu: T0 : 0x104ec @_Z3LISiPiS_+184    : c_sw a4, 0(a5)             : MemWrite :  D=0x0000000000000002 A=0x7ffffa74
420269000: system.cpu: T0 : 0x104ee @_Z3LISiPiS_+186    : lw a5, -32(s0)             : MemRead :  D=0x0000000000000000 A=0x7ffffa40
420273000: system.cpu: T0 : 0x104f2 @_Z3LISiPiS_+190    : c_addi a5, 1               : IntAlu :  D=0x0000000000000001
420275000: system.cpu: T0 : 0x104f4 @_Z3LISiPiS_+192    : sw a5, -32(s0)             : MemWrite :  D=0x0000000000000001 A=0x7ffffa40
420279000: system.cpu: T0 : 0x104f8 @_Z3LISiPiS_+196    : lw a4, -32(s0)             : MemRead :  D=0x0000000000000001 A=0x7ffffa40
420283000: system.cpu: T0 : 0x104fc @_Z3LISiPiS_+200    : lw a5, -28(s0)             : MemRead :  D=0x0000000000000005 A=0x7ffffa44
420287000: system.cpu: T0 : 0x10500 @_Z3LISiPiS_+204    : blt a4, a5, -110           : IntAlu : 
420291000: system.cpu: T0 : 0x10492 @_Z3LISiPiS_+94    : lw a5, -28(s0)             : MemRead :  D=0x0000000000000005 A=0x7ffffa44
420295000: system.cpu: T0 : 0x10496 @_Z3LISiPiS_+98    : c_slli a5, 2               : IntAlu :  D=0x0000000000000014
420297000: system.cpu: T0 : 0x10498 @_Z3LISiPiS_+100    : lw a4, -56(s0)             : MemRead :  D=0x000000007ffffe8c A=0x7ffffa28
420301000: system.cpu: T0 : 0x1049c @_Z3LISiPiS_+104    : c_add a5, a4               : IntAlu :  D=0x000000007ffffea0
420303000: system.cpu: T0 : 0x1049e @_Z3LISiPiS_+106    : c_lw a4, 0(a5)             : MemRead :  D=0x0000000000000006 A=0x7ffffea0
420307000: system.cpu: T0 : 0x104a0 @_Z3LISiPiS_+108    : lw a5, -32(s0)             : MemRead :  D=0x0000000000000001 A=0x7ffffa40
420311000: system.cpu: T0 : 0x104a4 @_Z3LISiPiS_+112    : c_slli a5, 2               : IntAlu :  D=0x0000000000000004
420315000: system.cpu: T0 : 0x104a6 @_Z3LISiPiS_+114    : lw a3, -56(s0)             : MemRead :  D=0x000000007ffffe8c A=0x7ffffa28
420319000: system.cpu: T0 : 0x104aa @_Z3LISiPiS_+118    : c_add a5, a3               : IntAlu :  D=0x000000007ffffe90
420321000: system.cpu: T0 : 0x104ac @_Z3LISiPiS_+120    : c_lw a5, 0(a5)             : MemRead :  D=0x0000000000000005 A=0x7ffffe90
420327000: system.cpu: T0 : 0x104ae @_Z3LISiPiS_+122    : bge a5, a4, 64             : IntAlu : 
420331000: system.cpu: T0 : 0x104b2 @_Z3LISiPiS_+126    : lw a5, -32(s0)             : MemRead :  D=0x0000000000000001 A=0x7ffffa40
420335000: system.cpu: T0 : 0x104b6 @_Z3LISiPiS_+130    : c_slli a5, 2               : IntAlu :  D=0x0000000000000004
420337000: system.cpu: T0 : 0x104b8 @_Z3LISiPiS_+132    : lw a4, -60(s0)             : MemRead :  D=0x000000007ffffa60 A=0x7ffffa24
420341000: system.cpu: T0 : 0x104bc @_Z3LISiPiS_+136    : c_add a5, a4               : IntAlu :  D=0x000000007ffffa64
420343000: system.cpu: T0 : 0x104be @_Z3LISiPiS_+138    : c_lw a5, 0(a5)             : MemRead :  D=0x0000000000000002 A=0x7ffffa64
420347000: system.cpu: T0 : 0x104c0 @_Z3LISiPiS_+140    : c_addi a5, 1               : IntAlu :  D=0x0000000000000003
420351000: system.cpu: T0 : 0x104c2 @_Z3LISiPiS_+142    : sw a5, -36(s0)             : MemWrite :  D=0x0000000000000003 A=0x7ffffa3c
420357000: system.cpu: T0 : 0x104c6 @_Z3LISiPiS_+146    : lw a5, -28(s0)             : MemRead :  D=0x0000000000000005 A=0x7ffffa44
420361000: system.cpu: T0 : 0x104ca @_Z3LISiPiS_+150    : c_slli a5, 2               : IntAlu :  D=0x0000000000000014
420363000: system.cpu: T0 : 0x104cc @_Z3LISiPiS_+152    : lw a4, -60(s0)             : MemRead :  D=0x000000007ffffa60 A=0x7ffffa24
420367000: system.cpu: T0 : 0x104d0 @_Z3LISiPiS_+156    : c_add a5, a4               : IntAlu :  D=0x000000007ffffa74
420369000: system.cpu: T0 : 0x104d2 @_Z3LISiPiS_+158    : c_lw a5, 0(a5)             : MemRead :  D=0x0000000000000002 A=0x7ffffa74
420373000: system.cpu: T0 : 0x104d4 @_Z3LISiPiS_+160    : lw a4, -36(s0)             : MemRead :  D=0x0000000000000003 A=0x7ffffa3c
420377000: system.cpu: T0 : 0x104d8 @_Z3LISiPiS_+164    : bge a5, a4, 22             : IntAlu : 
420379000: system.cpu: T0 : 0x104dc @_Z3LISiPiS_+168    : lw a5, -28(s0)             : MemRead :  D=0x0000000000000005 A=0x7ffffa44
420383000: system.cpu: T0 : 0x104e0 @_Z3LISiPiS_+172    : c_slli a5, 2               : IntAlu :  D=0x0000000000000014
420387000: system.cpu: T0 : 0x104e2 @_Z3LISiPiS_+174    : lw a4, -60(s0)             : MemRead :  D=0x000000007ffffa60 A=0x7ffffa24
420391000: system.cpu: T0 : 0x104e6 @_Z3LISiPiS_+178    : c_add a5, a4               : IntAlu :  D=0x000000007ffffa74
420393000: system.cpu: T0 : 0x104e8 @_Z3LISiPiS_+180    : lw a4, -36(s0)             : MemRead :  D=0x0000000000000003 A=0x7ffffa3c
420397000: system.cpu: T0 : 0x104ec @_Z3LISiPiS_+184    : c_sw a4, 0(a5)             : MemWrite :  D=0x0000000000000003 A=0x7ffffa74
420403000: system.cpu: T0 : 0x104ee @_Z3LISiPiS_+186    : lw a5, -32(s0)             : MemRead :  D=0x0000000000000001 A=0x7ffffa40
420407000: system.cpu: T0 : 0x104f2 @_Z3LISiPiS_+190    : c_addi a5, 1               : IntAlu :  D=0x0000000000000002
420409000: system.cpu: T0 : 0x104f4 @_Z3LISiPiS_+192    : sw a5, -32(s0)             : MemWrite :  D=0x0000000000000002 A=0x7ffffa40
420413000: system.cpu: T0 : 0x104f8 @_Z3LISiPiS_+196    : lw a4, -32(s0)             : MemRead :  D=0x0000000000000002 A=0x7ffffa40
420417000: system.cpu: T0 : 0x104fc @_Z3LISiPiS_+200    : lw a5, -28(s0)             : MemRead :  D=0x0000000000000005 A=0x7ffffa44
420421000: system.cpu: T0 : 0x10500 @_Z3LISiPiS_+204    : blt a4, a5, -110           : IntAlu : 
420425000: system.cpu: T0 : 0x10492 @_Z3LISiPiS_+94    : lw a5, -28(s0)             : MemRead :  D=0x0000000000000005 A=0x7ffffa44
420429000: system.cpu: T0 : 0x10496 @_Z3LISiPiS_+98    : c_slli a5, 2               : IntAlu :  D=0x0000000000000014
420431000: system.cpu: T0 : 0x10498 @_Z3LISiPiS_+100    : lw a4, -56(s0)             : MemRead :  D=0x000000007ffffe8c A=0x7ffffa28
420435000: system.cpu: T0 : 0x1049c @_Z3LISiPiS_+104    : c_add a5, a4               : IntAlu :  D=0x000000007ffffea0
420437000: system.cpu: T0 : 0x1049e @_Z3LISiPiS_+106    : c_lw a4, 0(a5)             : MemRead :  D=0x0000000000000006 A=0x7ffffea0
420441000: system.cpu: T0 : 0x104a0 @_Z3LISiPiS_+108    : lw a5, -32(s0)             : MemRead :  D=0x0000000000000002 A=0x7ffffa40
420445000: system.cpu: T0 : 0x104a4 @_Z3LISiPiS_+112    : c_slli a5, 2               : IntAlu :  D=0x0000000000000008
420449000: system.cpu: T0 : 0x104a6 @_Z3LISiPiS_+114    : lw a3, -56(s0)             : MemRead :  D=0x000000007ffffe8c A=0x7ffffa28
420453000: system.cpu: T0 : 0x104aa @_Z3LISiPiS_+118    : c_add a5, a3               : IntAlu :  D=0x000000007ffffe94
420455000: system.cpu: T0 : 0x104ac @_Z3LISiPiS_+120    : c_lw a5, 0(a5)             : MemRead :  D=0x0000000000000001 A=0x7ffffe94
420461000: system.cpu: T0 : 0x104ae @_Z3LISiPiS_+122    : bge a5, a4, 64             : IntAlu : 
420465000: system.cpu: T0 : 0x104b2 @_Z3LISiPiS_+126    : lw a5, -32(s0)             : MemRead :  D=0x0000000000000002 A=0x7ffffa40
420469000: system.cpu: T0 : 0x104b6 @_Z3LISiPiS_+130    : c_slli a5, 2               : IntAlu :  D=0x0000000000000008
420471000: system.cpu: T0 : 0x104b8 @_Z3LISiPiS_+132    : lw a4, -60(s0)             : MemRead :  D=0x000000007ffffa60 A=0x7ffffa24
420475000: system.cpu: T0 : 0x104bc @_Z3LISiPiS_+136    : c_add a5, a4               : IntAlu :  D=0x000000007ffffa68
420477000: system.cpu: T0 : 0x104be @_Z3LISiPiS_+138    : c_lw a5, 0(a5)             : MemRead :  D=0x0000000000000001 A=0x7ffffa68
420481000: system.cpu: T0 : 0x104c0 @_Z3LISiPiS_+140    : c_addi a5, 1               : IntAlu :  D=0x0000000000000002
420485000: system.cpu: T0 : 0x104c2 @_Z3LISiPiS_+142    : sw a5, -36(s0)             : MemWrite :  D=0x0000000000000002 A=0x7ffffa3c
420491000: system.cpu: T0 : 0x104c6 @_Z3LISiPiS_+146    : lw a5, -28(s0)             : MemRead :  D=0x0000000000000005 A=0x7ffffa44
420495000: system.cpu: T0 : 0x104ca @_Z3LISiPiS_+150    : c_slli a5, 2               : IntAlu :  D=0x0000000000000014
420497000: system.cpu: T0 : 0x104cc @_Z3LISiPiS_+152    : lw a4, -60(s0)             : MemRead :  D=0x000000007ffffa60 A=0x7ffffa24
420501000: system.cpu: T0 : 0x104d0 @_Z3LISiPiS_+156    : c_add a5, a4               : IntAlu :  D=0x000000007ffffa74
420503000: system.cpu: T0 : 0x104d2 @_Z3LISiPiS_+158    : c_lw a5, 0(a5)             : MemRead :  D=0x0000000000000003 A=0x7ffffa74
420507000: system.cpu: T0 : 0x104d4 @_Z3LISiPiS_+160    : lw a4, -36(s0)             : MemRead :  D=0x0000000000000002 A=0x7ffffa3c
420511000: system.cpu: T0 : 0x104d8 @_Z3LISiPiS_+164    : bge a5, a4, 22             : IntAlu : 
420515000: system.cpu: T0 : 0x104ee @_Z3LISiPiS_+186    : lw a5, -32(s0)             : MemRead :  D=0x0000000000000002 A=0x7ffffa40
420519000: system.cpu: T0 : 0x104f2 @_Z3LISiPiS_+190    : c_addi a5, 1               : IntAlu :  D=0x0000000000000003
420521000: system.cpu: T0 : 0x104f4 @_Z3LISiPiS_+192    : sw a5, -32(s0)             : MemWrite :  D=0x0000000000000003 A=0x7ffffa40
420525000: system.cpu: T0 : 0x104f8 @_Z3LISiPiS_+196    : lw a4, -32(s0)             : MemRead :  D=0x0000000000000003 A=0x7ffffa40
420529000: system.cpu: T0 : 0x104fc @_Z3LISiPiS_+200    : lw a5, -28(s0)             : MemRead :  D=0x0000000000000005 A=0x7ffffa44
420533000: system.cpu: T0 : 0x10500 @_Z3LISiPiS_+204    : blt a4, a5, -110           : IntAlu : 
420537000: system.cpu: T0 : 0x10492 @_Z3LISiPiS_+94    : lw a5, -28(s0)             : MemRead :  D=0x0000000000000005 A=0x7ffffa44
420541000: system.cpu: T0 : 0x10496 @_Z3LISiPiS_+98    : c_slli a5, 2               : IntAlu :  D=0x0000000000000014
420543000: system.cpu: T0 : 0x10498 @_Z3LISiPiS_+100    : lw a4, -56(s0)             : MemRead :  D=0x000000007ffffe8c A=0x7ffffa28
420547000: system.cpu: T0 : 0x1049c @_Z3LISiPiS_+104    : c_add a5, a4               : IntAlu :  D=0x000000007ffffea0
420549000: system.cpu: T0 : 0x1049e @_Z3LISiPiS_+106    : c_lw a4, 0(a5)             : MemRead :  D=0x0000000000000006 A=0x7ffffea0
420553000: system.cpu: T0 : 0x104a0 @_Z3LISiPiS_+108    : lw a5, -32(s0)             : MemRead :  D=0x0000000000000003 A=0x7ffffa40
420557000: system.cpu: T0 : 0x104a4 @_Z3LISiPiS_+112    : c_slli a5, 2               : IntAlu :  D=0x000000000000000c
420561000: system.cpu: T0 : 0x104a6 @_Z3LISiPiS_+114    : lw a3, -56(s0)             : MemRead :  D=0x000000007ffffe8c A=0x7ffffa28
420565000: system.cpu: T0 : 0x104aa @_Z3LISiPiS_+118    : c_add a5, a3               : IntAlu :  D=0x000000007ffffe98
420567000: system.cpu: T0 : 0x104ac @_Z3LISiPiS_+120    : c_lw a5, 0(a5)             : MemRead :  D=0x0000000000000008 A=0x7ffffe98
420573000: system.cpu: T0 : 0x104ae @_Z3LISiPiS_+122    : bge a5, a4, 64             : IntAlu : 
420577000: system.cpu: T0 : 0x104ee @_Z3LISiPiS_+186    : lw a5, -32(s0)             : MemRead :  D=0x0000000000000003 A=0x7ffffa40
420581000: system.cpu: T0 : 0x104f2 @_Z3LISiPiS_+190    : c_addi a5, 1               : IntAlu :  D=0x0000000000000004
420583000: system.cpu: T0 : 0x104f4 @_Z3LISiPiS_+192    : sw a5, -32(s0)             : MemWrite :  D=0x0000000000000004 A=0x7ffffa40
420587000: system.cpu: T0 : 0x104f8 @_Z3LISiPiS_+196    : lw a4, -32(s0)             : MemRead :  D=0x0000000000000004 A=0x7ffffa40
420591000: system.cpu: T0 : 0x104fc @_Z3LISiPiS_+200    : lw a5, -28(s0)             : MemRead :  D=0x0000000000000005 A=0x7ffffa44
420595000: system.cpu: T0 : 0x10500 @_Z3LISiPiS_+204    : blt a4, a5, -110           : IntAlu : 
420599000: system.cpu: T0 : 0x10492 @_Z3LISiPiS_+94    : lw a5, -28(s0)             : MemRead :  D=0x0000000000000005 A=0x7ffffa44
420603000: system.cpu: T0 : 0x10496 @_Z3LISiPiS_+98    : c_slli a5, 2               : IntAlu :  D=0x0000000000000014
420605000: system.cpu: T0 : 0x10498 @_Z3LISiPiS_+100    : lw a4, -56(s0)             : MemRead :  D=0x000000007ffffe8c A=0x7ffffa28
420609000: system.cpu: T0 : 0x1049c @_Z3LISiPiS_+104    : c_add a5, a4               : IntAlu :  D=0x000000007ffffea0
420611000: system.cpu: T0 : 0x1049e @_Z3LISiPiS_+106    : c_lw a4, 0(a5)             : MemRead :  D=0x0000000000000006 A=0x7ffffea0
420615000: system.cpu: T0 : 0x104a0 @_Z3LISiPiS_+108    : lw a5, -32(s0)             : MemRead :  D=0x0000000000000004 A=0x7ffffa40
420619000: system.cpu: T0 : 0x104a4 @_Z3LISiPiS_+112    : c_slli a5, 2               : IntAlu :  D=0x0000000000000010
420623000: system.cpu: T0 : 0x104a6 @_Z3LISiPiS_+114    : lw a3, -56(s0)             : MemRead :  D=0x000000007ffffe8c A=0x7ffffa28
420627000: system.cpu: T0 : 0x104aa @_Z3LISiPiS_+118    : c_add a5, a3               : IntAlu :  D=0x000000007ffffe9c
420629000: system.cpu: T0 : 0x104ac @_Z3LISiPiS_+120    : c_lw a5, 0(a5)             : MemRead :  D=0x0000000000000003 A=0x7ffffe9c
420635000: system.cpu: T0 : 0x104ae @_Z3LISiPiS_+122    : bge a5, a4, 64             : IntAlu : 
420639000: system.cpu: T0 : 0x104b2 @_Z3LISiPiS_+126    : lw a5, -32(s0)             : MemRead :  D=0x0000000000000004 A=0x7ffffa40
420643000: system.cpu: T0 : 0x104b6 @_Z3LISiPiS_+130    : c_slli a5, 2               : IntAlu :  D=0x0000000000000010
420645000: system.cpu: T0 : 0x104b8 @_Z3LISiPiS_+132    : lw a4, -60(s0)             : MemRead :  D=0x000000007ffffa60 A=0x7ffffa24
420649000: system.cpu: T0 : 0x104bc @_Z3LISiPiS_+136    : c_add a5, a4               : IntAlu :  D=0x000000007ffffa70
420651000: system.cpu: T0 : 0x104be @_Z3LISiPiS_+138    : c_lw a5, 0(a5)             : MemRead :  D=0x0000000000000002 A=0x7ffffa70
420655000: system.cpu: T0 : 0x104c0 @_Z3LISiPiS_+140    : c_addi a5, 1               : IntAlu :  D=0x0000000000000003
420659000: system.cpu: T0 : 0x104c2 @_Z3LISiPiS_+142    : sw a5, -36(s0)             : MemWrite :  D=0x0000000000000003 A=0x7ffffa3c
420665000: system.cpu: T0 : 0x104c6 @_Z3LISiPiS_+146    : lw a5, -28(s0)             : MemRead :  D=0x0000000000000005 A=0x7ffffa44
420669000: system.cpu: T0 : 0x104ca @_Z3LISiPiS_+150    : c_slli a5, 2               : IntAlu :  D=0x0000000000000014
420671000: system.cpu: T0 : 0x104cc @_Z3LISiPiS_+152    : lw a4, -60(s0)             : MemRead :  D=0x000000007ffffa60 A=0x7ffffa24
420675000: system.cpu: T0 : 0x104d0 @_Z3LISiPiS_+156    : c_add a5, a4               : IntAlu :  D=0x000000007ffffa74
420677000: system.cpu: T0 : 0x104d2 @_Z3LISiPiS_+158    : c_lw a5, 0(a5)             : MemRead :  D=0x0000000000000003 A=0x7ffffa74
420681000: system.cpu: T0 : 0x104d4 @_Z3LISiPiS_+160    : lw a4, -36(s0)             : MemRead :  D=0x0000000000000003 A=0x7ffffa3c
420685000: system.cpu: T0 : 0x104d8 @_Z3LISiPiS_+164    : bge a5, a4, 22             : IntAlu : 
420689000: system.cpu: T0 : 0x104ee @_Z3LISiPiS_+186    : lw a5, -32(s0)             : MemRead :  D=0x0000000000000004 A=0x7ffffa40
420693000: system.cpu: T0 : 0x104f2 @_Z3LISiPiS_+190    : c_addi a5, 1               : IntAlu :  D=0x0000000000000005
420695000: system.cpu: T0 : 0x104f4 @_Z3LISiPiS_+192    : sw a5, -32(s0)             : MemWrite :  D=0x0000000000000005 A=0x7ffffa40
420699000: system.cpu: T0 : 0x104f8 @_Z3LISiPiS_+196    : lw a4, -32(s0)             : MemRead :  D=0x0000000000000005 A=0x7ffffa40
420703000: system.cpu: T0 : 0x104fc @_Z3LISiPiS_+200    : lw a5, -28(s0)             : MemRead :  D=0x0000000000000005 A=0x7ffffa44
420707000: system.cpu: T0 : 0x10500 @_Z3LISiPiS_+204    : blt a4, a5, -110           : IntAlu : 
420709000: system.cpu: T0 : 0x10504 @_Z3LISiPiS_+208    : lw a5, -28(s0)             : MemRead :  D=0x0000000000000005 A=0x7ffffa44
420713000: system.cpu: T0 : 0x10508 @_Z3LISiPiS_+212    : c_slli a5, 2               : IntAlu :  D=0x0000000000000014
420717000: system.cpu: T0 : 0x1050a @_Z3LISiPiS_+214    : lw a4, -60(s0)             : MemRead :  D=0x000000007ffffa60 A=0x7ffffa24
420721000: system.cpu: T0 : 0x1050e @_Z3LISiPiS_+218    : c_add a5, a4               : IntAlu :  D=0x000000007ffffa74
420723000: system.cpu: T0 : 0x10510 @_Z3LISiPiS_+220    : c_lw a5, 0(a5)             : MemRead :  D=0x0000000000000003 A=0x7ffffa74
420729000: system.cpu: T0 : 0x10512 @_Z3LISiPiS_+222    : lw a4, -20(s0)             : MemRead :  D=0x0000000000000003 A=0x7ffffa4c
420735000: system.cpu: T0 : 0x10516 @_Z3LISiPiS_+226    : bge a4, a5, 22             : IntAlu : 
420737000: system.cpu: T0 : 0x1052c @_Z3LISiPiS_+248    : lw a5, -28(s0)             : MemRead :  D=0x0000000000000005 A=0x7ffffa44
420741000: system.cpu: T0 : 0x10530 @_Z3LISiPiS_+252    : c_addi a5, 1               : IntAlu :  D=0x0000000000000006
420745000: system.cpu: T0 : 0x10532 @_Z3LISiPiS_+254    : sw a5, -28(s0)             : MemWrite :  D=0x0000000000000006 A=0x7ffffa44
420751000: system.cpu: T0 : 0x10536 @_Z3LISiPiS_+258    : lw a4, -28(s0)             : MemRead :  D=0x0000000000000006 A=0x7ffffa44
420757000: system.cpu: T0 : 0x1053a @_Z3LISiPiS_+262    : lw a5, -52(s0)             : MemRead :  D=0x0000000000000008 A=0x7ffffa2c
420763000: system.cpu: T0 : 0x1053e @_Z3LISiPiS_+266    : blt a4, a5, -178           : IntAlu : 
420765000: system.cpu: T0 : 0x1048c @_Z3LISiPiS_+88    : sw zero, -32(s0)           : MemWrite :  D=0x0000000000000000 A=0x7ffffa40
420769000: system.cpu: T0 : 0x10490 @_Z3LISiPiS_+92    : c_j 104                    : IntAlu : 
420771000: system.cpu: T0 : 0x104f8 @_Z3LISiPiS_+196    : lw a4, -32(s0)             : MemRead :  D=0x0000000000000000 A=0x7ffffa40
420775000: system.cpu: T0 : 0x104fc @_Z3LISiPiS_+200    : lw a5, -28(s0)             : MemRead :  D=0x0000000000000006 A=0x7ffffa44
420779000: system.cpu: T0 : 0x10500 @_Z3LISiPiS_+204    : blt a4, a5, -110           : IntAlu : 
420783000: system.cpu: T0 : 0x10492 @_Z3LISiPiS_+94    : lw a5, -28(s0)             : MemRead :  D=0x0000000000000006 A=0x7ffffa44
420787000: system.cpu: T0 : 0x10496 @_Z3LISiPiS_+98    : c_slli a5, 2               : IntAlu :  D=0x0000000000000018
420789000: system.cpu: T0 : 0x10498 @_Z3LISiPiS_+100    : lw a4, -56(s0)             : MemRead :  D=0x000000007ffffe8c A=0x7ffffa28
420793000: system.cpu: T0 : 0x1049c @_Z3LISiPiS_+104    : c_add a5, a4               : IntAlu :  D=0x000000007ffffea4
420795000: system.cpu: T0 : 0x1049e @_Z3LISiPiS_+106    : c_lw a4, 0(a5)             : MemRead :  D=0x0000000000000009 A=0x7ffffea4
420799000: system.cpu: T0 : 0x104a0 @_Z3LISiPiS_+108    : lw a5, -32(s0)             : MemRead :  D=0x0000000000000000 A=0x7ffffa40
420803000: system.cpu: T0 : 0x104a4 @_Z3LISiPiS_+112    : c_slli a5, 2               : IntAlu :  D=0x0000000000000000
420807000: system.cpu: T0 : 0x104a6 @_Z3LISiPiS_+114    : lw a3, -56(s0)             : MemRead :  D=0x000000007ffffe8c A=0x7ffffa28
420811000: system.cpu: T0 : 0x104aa @_Z3LISiPiS_+118    : c_add a5, a3               : IntAlu :  D=0x000000007ffffe8c
420813000: system.cpu: T0 : 0x104ac @_Z3LISiPiS_+120    : c_lw a5, 0(a5)             : MemRead :  D=0x0000000000000004 A=0x7ffffe8c
420819000: system.cpu: T0 : 0x104ae @_Z3LISiPiS_+122    : bge a5, a4, 64             : IntAlu : 
420823000: system.cpu: T0 : 0x104b2 @_Z3LISiPiS_+126    : lw a5, -32(s0)             : MemRead :  D=0x0000000000000000 A=0x7ffffa40
420827000: system.cpu: T0 : 0x104b6 @_Z3LISiPiS_+130    : c_slli a5, 2               : IntAlu :  D=0x0000000000000000
420829000: system.cpu: T0 : 0x104b8 @_Z3LISiPiS_+132    : lw a4, -60(s0)             : MemRead :  D=0x000000007ffffa60 A=0x7ffffa24
420833000: system.cpu: T0 : 0x104bc @_Z3LISiPiS_+136    : c_add a5, a4               : IntAlu :  D=0x000000007ffffa60
420835000: system.cpu: T0 : 0x104be @_Z3LISiPiS_+138    : c_lw a5, 0(a5)             : MemRead :  D=0x0000000000000001 A=0x7ffffa60
420839000: system.cpu: T0 : 0x104c0 @_Z3LISiPiS_+140    : c_addi a5, 1               : IntAlu :  D=0x0000000000000002
420843000: system.cpu: T0 : 0x104c2 @_Z3LISiPiS_+142    : sw a5, -36(s0)             : MemWrite :  D=0x0000000000000002 A=0x7ffffa3c
420849000: system.cpu: T0 : 0x104c6 @_Z3LISiPiS_+146    : lw a5, -28(s0)             : MemRead :  D=0x0000000000000006 A=0x7ffffa44
420853000: system.cpu: T0 : 0x104ca @_Z3LISiPiS_+150    : c_slli a5, 2               : IntAlu :  D=0x0000000000000018
420855000: system.cpu: T0 : 0x104cc @_Z3LISiPiS_+152    : lw a4, -60(s0)             : MemRead :  D=0x000000007ffffa60 A=0x7ffffa24
420859000: system.cpu: T0 : 0x104d0 @_Z3LISiPiS_+156    : c_add a5, a4               : IntAlu :  D=0x000000007ffffa78
420861000: system.cpu: T0 : 0x104d2 @_Z3LISiPiS_+158    : c_lw a5, 0(a5)             : MemRead :  D=0x0000000000000001 A=0x7ffffa78
420865000: system.cpu: T0 : 0x104d4 @_Z3LISiPiS_+160    : lw a4, -36(s0)             : MemRead :  D=0x0000000000000002 A=0x7ffffa3c
420869000: system.cpu: T0 : 0x104d8 @_Z3LISiPiS_+164    : bge a5, a4, 22             : IntAlu : 
420871000: system.cpu: T0 : 0x104dc @_Z3LISiPiS_+168    : lw a5, -28(s0)             : MemRead :  D=0x0000000000000006 A=0x7ffffa44
420875000: system.cpu: T0 : 0x104e0 @_Z3LISiPiS_+172    : c_slli a5, 2               : IntAlu :  D=0x0000000000000018
420879000: system.cpu: T0 : 0x104e2 @_Z3LISiPiS_+174    : lw a4, -60(s0)             : MemRead :  D=0x000000007ffffa60 A=0x7ffffa24
420883000: system.cpu: T0 : 0x104e6 @_Z3LISiPiS_+178    : c_add a5, a4               : IntAlu :  D=0x000000007ffffa78
420885000: system.cpu: T0 : 0x104e8 @_Z3LISiPiS_+180    : lw a4, -36(s0)             : MemRead :  D=0x0000000000000002 A=0x7ffffa3c
420889000: system.cpu: T0 : 0x104ec @_Z3LISiPiS_+184    : c_sw a4, 0(a5)             : MemWrite :  D=0x0000000000000002 A=0x7ffffa78
420895000: system.cpu: T0 : 0x104ee @_Z3LISiPiS_+186    : lw a5, -32(s0)             : MemRead :  D=0x0000000000000000 A=0x7ffffa40
420899000: system.cpu: T0 : 0x104f2 @_Z3LISiPiS_+190    : c_addi a5, 1               : IntAlu :  D=0x0000000000000001
420901000: system.cpu: T0 : 0x104f4 @_Z3LISiPiS_+192    : sw a5, -32(s0)             : MemWrite :  D=0x0000000000000001 A=0x7ffffa40
420905000: system.cpu: T0 : 0x104f8 @_Z3LISiPiS_+196    : lw a4, -32(s0)             : MemRead :  D=0x0000000000000001 A=0x7ffffa40
420909000: system.cpu: T0 : 0x104fc @_Z3LISiPiS_+200    : lw a5, -28(s0)             : MemRead :  D=0x0000000000000006 A=0x7ffffa44
420913000: system.cpu: T0 : 0x10500 @_Z3LISiPiS_+204    : blt a4, a5, -110           : IntAlu : 
420917000: system.cpu: T0 : 0x10492 @_Z3LISiPiS_+94    : lw a5, -28(s0)             : MemRead :  D=0x0000000000000006 A=0x7ffffa44
420921000: system.cpu: T0 : 0x10496 @_Z3LISiPiS_+98    : c_slli a5, 2               : IntAlu :  D=0x0000000000000018
420923000: system.cpu: T0 : 0x10498 @_Z3LISiPiS_+100    : lw a4, -56(s0)             : MemRead :  D=0x000000007ffffe8c A=0x7ffffa28
420927000: system.cpu: T0 : 0x1049c @_Z3LISiPiS_+104    : c_add a5, a4               : IntAlu :  D=0x000000007ffffea4
420929000: system.cpu: T0 : 0x1049e @_Z3LISiPiS_+106    : c_lw a4, 0(a5)             : MemRead :  D=0x0000000000000009 A=0x7ffffea4
420933000: system.cpu: T0 : 0x104a0 @_Z3LISiPiS_+108    : lw a5, -32(s0)             : MemRead :  D=0x0000000000000001 A=0x7ffffa40
420937000: system.cpu: T0 : 0x104a4 @_Z3LISiPiS_+112    : c_slli a5, 2               : IntAlu :  D=0x0000000000000004
420941000: system.cpu: T0 : 0x104a6 @_Z3LISiPiS_+114    : lw a3, -56(s0)             : MemRead :  D=0x000000007ffffe8c A=0x7ffffa28
420945000: system.cpu: T0 : 0x104aa @_Z3LISiPiS_+118    : c_add a5, a3               : IntAlu :  D=0x000000007ffffe90
420947000: system.cpu: T0 : 0x104ac @_Z3LISiPiS_+120    : c_lw a5, 0(a5)             : MemRead :  D=0x0000000000000005 A=0x7ffffe90
420953000: system.cpu: T0 : 0x104ae @_Z3LISiPiS_+122    : bge a5, a4, 64             : IntAlu : 
420957000: system.cpu: T0 : 0x104b2 @_Z3LISiPiS_+126    : lw a5, -32(s0)             : MemRead :  D=0x0000000000000001 A=0x7ffffa40
420961000: system.cpu: T0 : 0x104b6 @_Z3LISiPiS_+130    : c_slli a5, 2               : IntAlu :  D=0x0000000000000004
420963000: system.cpu: T0 : 0x104b8 @_Z3LISiPiS_+132    : lw a4, -60(s0)             : MemRead :  D=0x000000007ffffa60 A=0x7ffffa24
420967000: system.cpu: T0 : 0x104bc @_Z3LISiPiS_+136    : c_add a5, a4               : IntAlu :  D=0x000000007ffffa64
420969000: system.cpu: T0 : 0x104be @_Z3LISiPiS_+138    : c_lw a5, 0(a5)             : MemRead :  D=0x0000000000000002 A=0x7ffffa64
420973000: system.cpu: T0 : 0x104c0 @_Z3LISiPiS_+140    : c_addi a5, 1               : IntAlu :  D=0x0000000000000003
420977000: system.cpu: T0 : 0x104c2 @_Z3LISiPiS_+142    : sw a5, -36(s0)             : MemWrite :  D=0x0000000000000003 A=0x7ffffa3c
420983000: system.cpu: T0 : 0x104c6 @_Z3LISiPiS_+146    : lw a5, -28(s0)             : MemRead :  D=0x0000000000000006 A=0x7ffffa44
420987000: system.cpu: T0 : 0x104ca @_Z3LISiPiS_+150    : c_slli a5, 2               : IntAlu :  D=0x0000000000000018
420989000: system.cpu: T0 : 0x104cc @_Z3LISiPiS_+152    : lw a4, -60(s0)             : MemRead :  D=0x000000007ffffa60 A=0x7ffffa24
420993000: system.cpu: T0 : 0x104d0 @_Z3LISiPiS_+156    : c_add a5, a4               : IntAlu :  D=0x000000007ffffa78
420995000: system.cpu: T0 : 0x104d2 @_Z3LISiPiS_+158    : c_lw a5, 0(a5)             : MemRead :  D=0x0000000000000002 A=0x7ffffa78
420999000: system.cpu: T0 : 0x104d4 @_Z3LISiPiS_+160    : lw a4, -36(s0)             : MemRead :  D=0x0000000000000003 A=0x7ffffa3c
421003000: system.cpu: T0 : 0x104d8 @_Z3LISiPiS_+164    : bge a5, a4, 22             : IntAlu : 
421005000: system.cpu: T0 : 0x104dc @_Z3LISiPiS_+168    : lw a5, -28(s0)             : MemRead :  D=0x0000000000000006 A=0x7ffffa44
421009000: system.cpu: T0 : 0x104e0 @_Z3LISiPiS_+172    : c_slli a5, 2               : IntAlu :  D=0x0000000000000018
421013000: system.cpu: T0 : 0x104e2 @_Z3LISiPiS_+174    : lw a4, -60(s0)             : MemRead :  D=0x000000007ffffa60 A=0x7ffffa24
421017000: system.cpu: T0 : 0x104e6 @_Z3LISiPiS_+178    : c_add a5, a4               : IntAlu :  D=0x000000007ffffa78
421019000: system.cpu: T0 : 0x104e8 @_Z3LISiPiS_+180    : lw a4, -36(s0)             : MemRead :  D=0x0000000000000003 A=0x7ffffa3c
421023000: system.cpu: T0 : 0x104ec @_Z3LISiPiS_+184    : c_sw a4, 0(a5)             : MemWrite :  D=0x0000000000000003 A=0x7ffffa78
421029000: system.cpu: T0 : 0x104ee @_Z3LISiPiS_+186    : lw a5, -32(s0)             : MemRead :  D=0x0000000000000001 A=0x7ffffa40
421033000: system.cpu: T0 : 0x104f2 @_Z3LISiPiS_+190    : c_addi a5, 1               : IntAlu :  D=0x0000000000000002
421035000: system.cpu: T0 : 0x104f4 @_Z3LISiPiS_+192    : sw a5, -32(s0)             : MemWrite :  D=0x0000000000000002 A=0x7ffffa40
421039000: system.cpu: T0 : 0x104f8 @_Z3LISiPiS_+196    : lw a4, -32(s0)             : MemRead :  D=0x0000000000000002 A=0x7ffffa40
421043000: system.cpu: T0 : 0x104fc @_Z3LISiPiS_+200    : lw a5, -28(s0)             : MemRead :  D=0x0000000000000006 A=0x7ffffa44
421047000: system.cpu: T0 : 0x10500 @_Z3LISiPiS_+204    : blt a4, a5, -110           : IntAlu : 
421051000: system.cpu: T0 : 0x10492 @_Z3LISiPiS_+94    : lw a5, -28(s0)             : MemRead :  D=0x0000000000000006 A=0x7ffffa44
421055000: system.cpu: T0 : 0x10496 @_Z3LISiPiS_+98    : c_slli a5, 2               : IntAlu :  D=0x0000000000000018
421057000: system.cpu: T0 : 0x10498 @_Z3LISiPiS_+100    : lw a4, -56(s0)             : MemRead :  D=0x000000007ffffe8c A=0x7ffffa28
421061000: system.cpu: T0 : 0x1049c @_Z3LISiPiS_+104    : c_add a5, a4               : IntAlu :  D=0x000000007ffffea4
421063000: system.cpu: T0 : 0x1049e @_Z3LISiPiS_+106    : c_lw a4, 0(a5)             : MemRead :  D=0x0000000000000009 A=0x7ffffea4
421067000: system.cpu: T0 : 0x104a0 @_Z3LISiPiS_+108    : lw a5, -32(s0)             : MemRead :  D=0x0000000000000002 A=0x7ffffa40
421071000: system.cpu: T0 : 0x104a4 @_Z3LISiPiS_+112    : c_slli a5, 2               : IntAlu :  D=0x0000000000000008
421075000: system.cpu: T0 : 0x104a6 @_Z3LISiPiS_+114    : lw a3, -56(s0)             : MemRead :  D=0x000000007ffffe8c A=0x7ffffa28
421079000: system.cpu: T0 : 0x104aa @_Z3LISiPiS_+118    : c_add a5, a3               : IntAlu :  D=0x000000007ffffe94
421081000: system.cpu: T0 : 0x104ac @_Z3LISiPiS_+120    : c_lw a5, 0(a5)             : MemRead :  D=0x0000000000000001 A=0x7ffffe94
421087000: system.cpu: T0 : 0x104ae @_Z3LISiPiS_+122    : bge a5, a4, 64             : IntAlu : 
421091000: system.cpu: T0 : 0x104b2 @_Z3LISiPiS_+126    : lw a5, -32(s0)             : MemRead :  D=0x0000000000000002 A=0x7ffffa40
421095000: system.cpu: T0 : 0x104b6 @_Z3LISiPiS_+130    : c_slli a5, 2               : IntAlu :  D=0x0000000000000008
421097000: system.cpu: T0 : 0x104b8 @_Z3LISiPiS_+132    : lw a4, -60(s0)             : MemRead :  D=0x000000007ffffa60 A=0x7ffffa24
421101000: system.cpu: T0 : 0x104bc @_Z3LISiPiS_+136    : c_add a5, a4               : IntAlu :  D=0x000000007ffffa68
421103000: system.cpu: T0 : 0x104be @_Z3LISiPiS_+138    : c_lw a5, 0(a5)             : MemRead :  D=0x0000000000000001 A=0x7ffffa68
421107000: system.cpu: T0 : 0x104c0 @_Z3LISiPiS_+140    : c_addi a5, 1               : IntAlu :  D=0x0000000000000002
421111000: system.cpu: T0 : 0x104c2 @_Z3LISiPiS_+142    : sw a5, -36(s0)             : MemWrite :  D=0x0000000000000002 A=0x7ffffa3c
421117000: system.cpu: T0 : 0x104c6 @_Z3LISiPiS_+146    : lw a5, -28(s0)             : MemRead :  D=0x0000000000000006 A=0x7ffffa44
421121000: system.cpu: T0 : 0x104ca @_Z3LISiPiS_+150    : c_slli a5, 2               : IntAlu :  D=0x0000000000000018
421123000: system.cpu: T0 : 0x104cc @_Z3LISiPiS_+152    : lw a4, -60(s0)             : MemRead :  D=0x000000007ffffa60 A=0x7ffffa24
421127000: system.cpu: T0 : 0x104d0 @_Z3LISiPiS_+156    : c_add a5, a4               : IntAlu :  D=0x000000007ffffa78
421129000: system.cpu: T0 : 0x104d2 @_Z3LISiPiS_+158    : c_lw a5, 0(a5)             : MemRead :  D=0x0000000000000003 A=0x7ffffa78
421133000: system.cpu: T0 : 0x104d4 @_Z3LISiPiS_+160    : lw a4, -36(s0)             : MemRead :  D=0x0000000000000002 A=0x7ffffa3c
421137000: system.cpu: T0 : 0x104d8 @_Z3LISiPiS_+164    : bge a5, a4, 22             : IntAlu : 
421141000: system.cpu: T0 : 0x104ee @_Z3LISiPiS_+186    : lw a5, -32(s0)             : MemRead :  D=0x0000000000000002 A=0x7ffffa40
421145000: system.cpu: T0 : 0x104f2 @_Z3LISiPiS_+190    : c_addi a5, 1               : IntAlu :  D=0x0000000000000003
421147000: system.cpu: T0 : 0x104f4 @_Z3LISiPiS_+192    : sw a5, -32(s0)             : MemWrite :  D=0x0000000000000003 A=0x7ffffa40
421151000: system.cpu: T0 : 0x104f8 @_Z3LISiPiS_+196    : lw a4, -32(s0)             : MemRead :  D=0x0000000000000003 A=0x7ffffa40
421155000: system.cpu: T0 : 0x104fc @_Z3LISiPiS_+200    : lw a5, -28(s0)             : MemRead :  D=0x0000000000000006 A=0x7ffffa44
421159000: system.cpu: T0 : 0x10500 @_Z3LISiPiS_+204    : blt a4, a5, -110           : IntAlu : 
421163000: system.cpu: T0 : 0x10492 @_Z3LISiPiS_+94    : lw a5, -28(s0)             : MemRead :  D=0x0000000000000006 A=0x7ffffa44
421167000: system.cpu: T0 : 0x10496 @_Z3LISiPiS_+98    : c_slli a5, 2               : IntAlu :  D=0x0000000000000018
421169000: system.cpu: T0 : 0x10498 @_Z3LISiPiS_+100    : lw a4, -56(s0)             : MemRead :  D=0x000000007ffffe8c A=0x7ffffa28
421173000: system.cpu: T0 : 0x1049c @_Z3LISiPiS_+104    : c_add a5, a4               : IntAlu :  D=0x000000007ffffea4
421175000: system.cpu: T0 : 0x1049e @_Z3LISiPiS_+106    : c_lw a4, 0(a5)             : MemRead :  D=0x0000000000000009 A=0x7ffffea4
421179000: system.cpu: T0 : 0x104a0 @_Z3LISiPiS_+108    : lw a5, -32(s0)             : MemRead :  D=0x0000000000000003 A=0x7ffffa40
421183000: system.cpu: T0 : 0x104a4 @_Z3LISiPiS_+112    : c_slli a5, 2               : IntAlu :  D=0x000000000000000c
421187000: system.cpu: T0 : 0x104a6 @_Z3LISiPiS_+114    : lw a3, -56(s0)             : MemRead :  D=0x000000007ffffe8c A=0x7ffffa28
421191000: system.cpu: T0 : 0x104aa @_Z3LISiPiS_+118    : c_add a5, a3               : IntAlu :  D=0x000000007ffffe98
421193000: system.cpu: T0 : 0x104ac @_Z3LISiPiS_+120    : c_lw a5, 0(a5)             : MemRead :  D=0x0000000000000008 A=0x7ffffe98
421199000: system.cpu: T0 : 0x104ae @_Z3LISiPiS_+122    : bge a5, a4, 64             : IntAlu : 
421203000: system.cpu: T0 : 0x104b2 @_Z3LISiPiS_+126    : lw a5, -32(s0)             : MemRead :  D=0x0000000000000003 A=0x7ffffa40
421207000: system.cpu: T0 : 0x104b6 @_Z3LISiPiS_+130    : c_slli a5, 2               : IntAlu :  D=0x000000000000000c
421209000: system.cpu: T0 : 0x104b8 @_Z3LISiPiS_+132    : lw a4, -60(s0)             : MemRead :  D=0x000000007ffffa60 A=0x7ffffa24
421213000: system.cpu: T0 : 0x104bc @_Z3LISiPiS_+136    : c_add a5, a4               : IntAlu :  D=0x000000007ffffa6c
421215000: system.cpu: T0 : 0x104be @_Z3LISiPiS_+138    : c_lw a5, 0(a5)             : MemRead :  D=0x0000000000000003 A=0x7ffffa6c
421219000: system.cpu: T0 : 0x104c0 @_Z3LISiPiS_+140    : c_addi a5, 1               : IntAlu :  D=0x0000000000000004
421223000: system.cpu: T0 : 0x104c2 @_Z3LISiPiS_+142    : sw a5, -36(s0)             : MemWrite :  D=0x0000000000000004 A=0x7ffffa3c
421229000: system.cpu: T0 : 0x104c6 @_Z3LISiPiS_+146    : lw a5, -28(s0)             : MemRead :  D=0x0000000000000006 A=0x7ffffa44
421233000: system.cpu: T0 : 0x104ca @_Z3LISiPiS_+150    : c_slli a5, 2               : IntAlu :  D=0x0000000000000018
421235000: system.cpu: T0 : 0x104cc @_Z3LISiPiS_+152    : lw a4, -60(s0)             : MemRead :  D=0x000000007ffffa60 A=0x7ffffa24
421239000: system.cpu: T0 : 0x104d0 @_Z3LISiPiS_+156    : c_add a5, a4               : IntAlu :  D=0x000000007ffffa78
421241000: system.cpu: T0 : 0x104d2 @_Z3LISiPiS_+158    : c_lw a5, 0(a5)             : MemRead :  D=0x0000000000000003 A=0x7ffffa78
421245000: system.cpu: T0 : 0x104d4 @_Z3LISiPiS_+160    : lw a4, -36(s0)             : MemRead :  D=0x0000000000000004 A=0x7ffffa3c
421249000: system.cpu: T0 : 0x104d8 @_Z3LISiPiS_+164    : bge a5, a4, 22             : IntAlu : 
421251000: system.cpu: T0 : 0x104dc @_Z3LISiPiS_+168    : lw a5, -28(s0)             : MemRead :  D=0x0000000000000006 A=0x7ffffa44
421255000: system.cpu: T0 : 0x104e0 @_Z3LISiPiS_+172    : c_slli a5, 2               : IntAlu :  D=0x0000000000000018
421259000: system.cpu: T0 : 0x104e2 @_Z3LISiPiS_+174    : lw a4, -60(s0)             : MemRead :  D=0x000000007ffffa60 A=0x7ffffa24
421263000: system.cpu: T0 : 0x104e6 @_Z3LISiPiS_+178    : c_add a5, a4               : IntAlu :  D=0x000000007ffffa78
421265000: system.cpu: T0 : 0x104e8 @_Z3LISiPiS_+180    : lw a4, -36(s0)             : MemRead :  D=0x0000000000000004 A=0x7ffffa3c
421269000: system.cpu: T0 : 0x104ec @_Z3LISiPiS_+184    : c_sw a4, 0(a5)             : MemWrite :  D=0x0000000000000004 A=0x7ffffa78
421275000: system.cpu: T0 : 0x104ee @_Z3LISiPiS_+186    : lw a5, -32(s0)             : MemRead :  D=0x0000000000000003 A=0x7ffffa40
421279000: system.cpu: T0 : 0x104f2 @_Z3LISiPiS_+190    : c_addi a5, 1               : IntAlu :  D=0x0000000000000004
421281000: system.cpu: T0 : 0x104f4 @_Z3LISiPiS_+192    : sw a5, -32(s0)             : MemWrite :  D=0x0000000000000004 A=0x7ffffa40
421285000: system.cpu: T0 : 0x104f8 @_Z3LISiPiS_+196    : lw a4, -32(s0)             : MemRead :  D=0x0000000000000004 A=0x7ffffa40
421289000: system.cpu: T0 : 0x104fc @_Z3LISiPiS_+200    : lw a5, -28(s0)             : MemRead :  D=0x0000000000000006 A=0x7ffffa44
421293000: system.cpu: T0 : 0x10500 @_Z3LISiPiS_+204    : blt a4, a5, -110           : IntAlu : 
421297000: system.cpu: T0 : 0x10492 @_Z3LISiPiS_+94    : lw a5, -28(s0)             : MemRead :  D=0x0000000000000006 A=0x7ffffa44
421301000: system.cpu: T0 : 0x10496 @_Z3LISiPiS_+98    : c_slli a5, 2               : IntAlu :  D=0x0000000000000018
421303000: system.cpu: T0 : 0x10498 @_Z3LISiPiS_+100    : lw a4, -56(s0)             : MemRead :  D=0x000000007ffffe8c A=0x7ffffa28
421307000: system.cpu: T0 : 0x1049c @_Z3LISiPiS_+104    : c_add a5, a4               : IntAlu :  D=0x000000007ffffea4
421309000: system.cpu: T0 : 0x1049e @_Z3LISiPiS_+106    : c_lw a4, 0(a5)             : MemRead :  D=0x0000000000000009 A=0x7ffffea4
421313000: system.cpu: T0 : 0x104a0 @_Z3LISiPiS_+108    : lw a5, -32(s0)             : MemRead :  D=0x0000000000000004 A=0x7ffffa40
421317000: system.cpu: T0 : 0x104a4 @_Z3LISiPiS_+112    : c_slli a5, 2               : IntAlu :  D=0x0000000000000010
421321000: system.cpu: T0 : 0x104a6 @_Z3LISiPiS_+114    : lw a3, -56(s0)             : MemRead :  D=0x000000007ffffe8c A=0x7ffffa28
421325000: system.cpu: T0 : 0x104aa @_Z3LISiPiS_+118    : c_add a5, a3               : IntAlu :  D=0x000000007ffffe9c
421327000: system.cpu: T0 : 0x104ac @_Z3LISiPiS_+120    : c_lw a5, 0(a5)             : MemRead :  D=0x0000000000000003 A=0x7ffffe9c
421333000: system.cpu: T0 : 0x104ae @_Z3LISiPiS_+122    : bge a5, a4, 64             : IntAlu : 
421337000: system.cpu: T0 : 0x104b2 @_Z3LISiPiS_+126    : lw a5, -32(s0)             : MemRead :  D=0x0000000000000004 A=0x7ffffa40
421341000: system.cpu: T0 : 0x104b6 @_Z3LISiPiS_+130    : c_slli a5, 2               : IntAlu :  D=0x0000000000000010
421343000: system.cpu: T0 : 0x104b8 @_Z3LISiPiS_+132    : lw a4, -60(s0)             : MemRead :  D=0x000000007ffffa60 A=0x7ffffa24
421347000: system.cpu: T0 : 0x104bc @_Z3LISiPiS_+136    : c_add a5, a4               : IntAlu :  D=0x000000007ffffa70
421349000: system.cpu: T0 : 0x104be @_Z3LISiPiS_+138    : c_lw a5, 0(a5)             : MemRead :  D=0x0000000000000002 A=0x7ffffa70
421353000: system.cpu: T0 : 0x104c0 @_Z3LISiPiS_+140    : c_addi a5, 1               : IntAlu :  D=0x0000000000000003
421357000: system.cpu: T0 : 0x104c2 @_Z3LISiPiS_+142    : sw a5, -36(s0)             : MemWrite :  D=0x0000000000000003 A=0x7ffffa3c
421363000: system.cpu: T0 : 0x104c6 @_Z3LISiPiS_+146    : lw a5, -28(s0)             : MemRead :  D=0x0000000000000006 A=0x7ffffa44
421367000: system.cpu: T0 : 0x104ca @_Z3LISiPiS_+150    : c_slli a5, 2               : IntAlu :  D=0x0000000000000018
421369000: system.cpu: T0 : 0x104cc @_Z3LISiPiS_+152    : lw a4, -60(s0)             : MemRead :  D=0x000000007ffffa60 A=0x7ffffa24
421373000: system.cpu: T0 : 0x104d0 @_Z3LISiPiS_+156    : c_add a5, a4               : IntAlu :  D=0x000000007ffffa78
421375000: system.cpu: T0 : 0x104d2 @_Z3LISiPiS_+158    : c_lw a5, 0(a5)             : MemRead :  D=0x0000000000000004 A=0x7ffffa78
421379000: system.cpu: T0 : 0x104d4 @_Z3LISiPiS_+160    : lw a4, -36(s0)             : MemRead :  D=0x0000000000000003 A=0x7ffffa3c
421383000: system.cpu: T0 : 0x104d8 @_Z3LISiPiS_+164    : bge a5, a4, 22             : IntAlu : 
421387000: system.cpu: T0 : 0x104ee @_Z3LISiPiS_+186    : lw a5, -32(s0)             : MemRead :  D=0x0000000000000004 A=0x7ffffa40
421391000: system.cpu: T0 : 0x104f2 @_Z3LISiPiS_+190    : c_addi a5, 1               : IntAlu :  D=0x0000000000000005
421393000: system.cpu: T0 : 0x104f4 @_Z3LISiPiS_+192    : sw a5, -32(s0)             : MemWrite :  D=0x0000000000000005 A=0x7ffffa40
421397000: system.cpu: T0 : 0x104f8 @_Z3LISiPiS_+196    : lw a4, -32(s0)             : MemRead :  D=0x0000000000000005 A=0x7ffffa40
421401000: system.cpu: T0 : 0x104fc @_Z3LISiPiS_+200    : lw a5, -28(s0)             : MemRead :  D=0x0000000000000006 A=0x7ffffa44
421405000: system.cpu: T0 : 0x10500 @_Z3LISiPiS_+204    : blt a4, a5, -110           : IntAlu : 
421409000: system.cpu: T0 : 0x10492 @_Z3LISiPiS_+94    : lw a5, -28(s0)             : MemRead :  D=0x0000000000000006 A=0x7ffffa44
421413000: system.cpu: T0 : 0x10496 @_Z3LISiPiS_+98    : c_slli a5, 2               : IntAlu :  D=0x0000000000000018
421415000: system.cpu: T0 : 0x10498 @_Z3LISiPiS_+100    : lw a4, -56(s0)             : MemRead :  D=0x000000007ffffe8c A=0x7ffffa28
421419000: system.cpu: T0 : 0x1049c @_Z3LISiPiS_+104    : c_add a5, a4               : IntAlu :  D=0x000000007ffffea4
421421000: system.cpu: T0 : 0x1049e @_Z3LISiPiS_+106    : c_lw a4, 0(a5)             : MemRead :  D=0x0000000000000009 A=0x7ffffea4
421425000: system.cpu: T0 : 0x104a0 @_Z3LISiPiS_+108    : lw a5, -32(s0)             : MemRead :  D=0x0000000000000005 A=0x7ffffa40
421429000: system.cpu: T0 : 0x104a4 @_Z3LISiPiS_+112    : c_slli a5, 2               : IntAlu :  D=0x0000000000000014
421433000: system.cpu: T0 : 0x104a6 @_Z3LISiPiS_+114    : lw a3, -56(s0)             : MemRead :  D=0x000000007ffffe8c A=0x7ffffa28
421437000: system.cpu: T0 : 0x104aa @_Z3LISiPiS_+118    : c_add a5, a3               : IntAlu :  D=0x000000007ffffea0
421439000: system.cpu: T0 : 0x104ac @_Z3LISiPiS_+120    : c_lw a5, 0(a5)             : MemRead :  D=0x0000000000000006 A=0x7ffffea0
421445000: system.cpu: T0 : 0x104ae @_Z3LISiPiS_+122    : bge a5, a4, 64             : IntAlu : 
421449000: system.cpu: T0 : 0x104b2 @_Z3LISiPiS_+126    : lw a5, -32(s0)             : MemRead :  D=0x0000000000000005 A=0x7ffffa40
421453000: system.cpu: T0 : 0x104b6 @_Z3LISiPiS_+130    : c_slli a5, 2               : IntAlu :  D=0x0000000000000014
421455000: system.cpu: T0 : 0x104b8 @_Z3LISiPiS_+132    : lw a4, -60(s0)             : MemRead :  D=0x000000007ffffa60 A=0x7ffffa24
421459000: system.cpu: T0 : 0x104bc @_Z3LISiPiS_+136    : c_add a5, a4               : IntAlu :  D=0x000000007ffffa74
421461000: system.cpu: T0 : 0x104be @_Z3LISiPiS_+138    : c_lw a5, 0(a5)             : MemRead :  D=0x0000000000000003 A=0x7ffffa74
421465000: system.cpu: T0 : 0x104c0 @_Z3LISiPiS_+140    : c_addi a5, 1               : IntAlu :  D=0x0000000000000004
421469000: system.cpu: T0 : 0x104c2 @_Z3LISiPiS_+142    : sw a5, -36(s0)             : MemWrite :  D=0x0000000000000004 A=0x7ffffa3c
421475000: system.cpu: T0 : 0x104c6 @_Z3LISiPiS_+146    : lw a5, -28(s0)             : MemRead :  D=0x0000000000000006 A=0x7ffffa44
421479000: system.cpu: T0 : 0x104ca @_Z3LISiPiS_+150    : c_slli a5, 2               : IntAlu :  D=0x0000000000000018
421481000: system.cpu: T0 : 0x104cc @_Z3LISiPiS_+152    : lw a4, -60(s0)             : MemRead :  D=0x000000007ffffa60 A=0x7ffffa24
421485000: system.cpu: T0 : 0x104d0 @_Z3LISiPiS_+156    : c_add a5, a4               : IntAlu :  D=0x000000007ffffa78
421487000: system.cpu: T0 : 0x104d2 @_Z3LISiPiS_+158    : c_lw a5, 0(a5)             : MemRead :  D=0x0000000000000004 A=0x7ffffa78
421491000: system.cpu: T0 : 0x104d4 @_Z3LISiPiS_+160    : lw a4, -36(s0)             : MemRead :  D=0x0000000000000004 A=0x7ffffa3c
421495000: system.cpu: T0 : 0x104d8 @_Z3LISiPiS_+164    : bge a5, a4, 22             : IntAlu : 
421499000: system.cpu: T0 : 0x104ee @_Z3LISiPiS_+186    : lw a5, -32(s0)             : MemRead :  D=0x0000000000000005 A=0x7ffffa40
421503000: system.cpu: T0 : 0x104f2 @_Z3LISiPiS_+190    : c_addi a5, 1               : IntAlu :  D=0x0000000000000006
421505000: system.cpu: T0 : 0x104f4 @_Z3LISiPiS_+192    : sw a5, -32(s0)             : MemWrite :  D=0x0000000000000006 A=0x7ffffa40
421509000: system.cpu: T0 : 0x104f8 @_Z3LISiPiS_+196    : lw a4, -32(s0)             : MemRead :  D=0x0000000000000006 A=0x7ffffa40
421513000: system.cpu: T0 : 0x104fc @_Z3LISiPiS_+200    : lw a5, -28(s0)             : MemRead :  D=0x0000000000000006 A=0x7ffffa44
421517000: system.cpu: T0 : 0x10500 @_Z3LISiPiS_+204    : blt a4, a5, -110           : IntAlu : 
421519000: system.cpu: T0 : 0x10504 @_Z3LISiPiS_+208    : lw a5, -28(s0)             : MemRead :  D=0x0000000000000006 A=0x7ffffa44
421523000: system.cpu: T0 : 0x10508 @_Z3LISiPiS_+212    : c_slli a5, 2               : IntAlu :  D=0x0000000000000018
421527000: system.cpu: T0 : 0x1050a @_Z3LISiPiS_+214    : lw a4, -60(s0)             : MemRead :  D=0x000000007ffffa60 A=0x7ffffa24
421531000: system.cpu: T0 : 0x1050e @_Z3LISiPiS_+218    : c_add a5, a4               : IntAlu :  D=0x000000007ffffa78
421533000: system.cpu: T0 : 0x10510 @_Z3LISiPiS_+220    : c_lw a5, 0(a5)             : MemRead :  D=0x0000000000000004 A=0x7ffffa78
421539000: system.cpu: T0 : 0x10512 @_Z3LISiPiS_+222    : lw a4, -20(s0)             : MemRead :  D=0x0000000000000003 A=0x7ffffa4c
421545000: system.cpu: T0 : 0x10516 @_Z3LISiPiS_+226    : bge a4, a5, 22             : IntAlu : 
421549000: system.cpu: T0 : 0x1051a @_Z3LISiPiS_+230    : lw a5, -28(s0)             : MemRead :  D=0x0000000000000006 A=0x7ffffa44
421553000: system.cpu: T0 : 0x1051e @_Z3LISiPiS_+234    : c_slli a5, 2               : IntAlu :  D=0x0000000000000018
421555000: system.cpu: T0 : 0x10520 @_Z3LISiPiS_+236    : lw a4, -60(s0)             : MemRead :  D=0x000000007ffffa60 A=0x7ffffa24
421559000: system.cpu: T0 : 0x10524 @_Z3LISiPiS_+240    : c_add a5, a4               : IntAlu :  D=0x000000007ffffa78
421561000: system.cpu: T0 : 0x10526 @_Z3LISiPiS_+242    : c_lw a5, 0(a5)             : MemRead :  D=0x0000000000000004 A=0x7ffffa78
421565000: system.cpu: T0 : 0x10528 @_Z3LISiPiS_+244    : sw a5, -20(s0)             : MemWrite :  D=0x0000000000000004 A=0x7ffffa4c
421569000: system.cpu: T0 : 0x1052c @_Z3LISiPiS_+248    : lw a5, -28(s0)             : MemRead :  D=0x0000000000000006 A=0x7ffffa44
421573000: system.cpu: T0 : 0x10530 @_Z3LISiPiS_+252    : c_addi a5, 1               : IntAlu :  D=0x0000000000000007
421577000: system.cpu: T0 : 0x10532 @_Z3LISiPiS_+254    : sw a5, -28(s0)             : MemWrite :  D=0x0000000000000007 A=0x7ffffa44
421583000: system.cpu: T0 : 0x10536 @_Z3LISiPiS_+258    : lw a4, -28(s0)             : MemRead :  D=0x0000000000000007 A=0x7ffffa44
421589000: system.cpu: T0 : 0x1053a @_Z3LISiPiS_+262    : lw a5, -52(s0)             : MemRead :  D=0x0000000000000008 A=0x7ffffa2c
421595000: system.cpu: T0 : 0x1053e @_Z3LISiPiS_+266    : blt a4, a5, -178           : IntAlu : 
421597000: system.cpu: T0 : 0x1048c @_Z3LISiPiS_+88    : sw zero, -32(s0)           : MemWrite :  D=0x0000000000000000 A=0x7ffffa40
421601000: system.cpu: T0 : 0x10490 @_Z3LISiPiS_+92    : c_j 104                    : IntAlu : 
421603000: system.cpu: T0 : 0x104f8 @_Z3LISiPiS_+196    : lw a4, -32(s0)             : MemRead :  D=0x0000000000000000 A=0x7ffffa40
421607000: system.cpu: T0 : 0x104fc @_Z3LISiPiS_+200    : lw a5, -28(s0)             : MemRead :  D=0x0000000000000007 A=0x7ffffa44
421611000: system.cpu: T0 : 0x10500 @_Z3LISiPiS_+204    : blt a4, a5, -110           : IntAlu : 
421615000: system.cpu: T0 : 0x10492 @_Z3LISiPiS_+94    : lw a5, -28(s0)             : MemRead :  D=0x0000000000000007 A=0x7ffffa44
421619000: system.cpu: T0 : 0x10496 @_Z3LISiPiS_+98    : c_slli a5, 2               : IntAlu :  D=0x000000000000001c
421621000: system.cpu: T0 : 0x10498 @_Z3LISiPiS_+100    : lw a4, -56(s0)             : MemRead :  D=0x000000007ffffe8c A=0x7ffffa28
421625000: system.cpu: T0 : 0x1049c @_Z3LISiPiS_+104    : c_add a5, a4               : IntAlu :  D=0x000000007ffffea8
421627000: system.cpu: T0 : 0x1049e @_Z3LISiPiS_+106    : c_lw a4, 0(a5)             : MemRead :  D=0x0000000000000002 A=0x7ffffea8
421631000: system.cpu: T0 : 0x104a0 @_Z3LISiPiS_+108    : lw a5, -32(s0)             : MemRead :  D=0x0000000000000000 A=0x7ffffa40
421635000: system.cpu: T0 : 0x104a4 @_Z3LISiPiS_+112    : c_slli a5, 2               : IntAlu :  D=0x0000000000000000
421639000: system.cpu: T0 : 0x104a6 @_Z3LISiPiS_+114    : lw a3, -56(s0)             : MemRead :  D=0x000000007ffffe8c A=0x7ffffa28
421643000: system.cpu: T0 : 0x104aa @_Z3LISiPiS_+118    : c_add a5, a3               : IntAlu :  D=0x000000007ffffe8c
421645000: system.cpu: T0 : 0x104ac @_Z3LISiPiS_+120    : c_lw a5, 0(a5)             : MemRead :  D=0x0000000000000004 A=0x7ffffe8c
421651000: system.cpu: T0 : 0x104ae @_Z3LISiPiS_+122    : bge a5, a4, 64             : IntAlu : 
421655000: system.cpu: T0 : 0x104ee @_Z3LISiPiS_+186    : lw a5, -32(s0)             : MemRead :  D=0x0000000000000000 A=0x7ffffa40
421659000: system.cpu: T0 : 0x104f2 @_Z3LISiPiS_+190    : c_addi a5, 1               : IntAlu :  D=0x0000000000000001
421661000: system.cpu: T0 : 0x104f4 @_Z3LISiPiS_+192    : sw a5, -32(s0)             : MemWrite :  D=0x0000000000000001 A=0x7ffffa40
421665000: system.cpu: T0 : 0x104f8 @_Z3LISiPiS_+196    : lw a4, -32(s0)             : MemRead :  D=0x0000000000000001 A=0x7ffffa40
421669000: system.cpu: T0 : 0x104fc @_Z3LISiPiS_+200    : lw a5, -28(s0)             : MemRead :  D=0x0000000000000007 A=0x7ffffa44
421673000: system.cpu: T0 : 0x10500 @_Z3LISiPiS_+204    : blt a4, a5, -110           : IntAlu : 
421677000: system.cpu: T0 : 0x10492 @_Z3LISiPiS_+94    : lw a5, -28(s0)             : MemRead :  D=0x0000000000000007 A=0x7ffffa44
421681000: system.cpu: T0 : 0x10496 @_Z3LISiPiS_+98    : c_slli a5, 2               : IntAlu :  D=0x000000000000001c
421683000: system.cpu: T0 : 0x10498 @_Z3LISiPiS_+100    : lw a4, -56(s0)             : MemRead :  D=0x000000007ffffe8c A=0x7ffffa28
421687000: system.cpu: T0 : 0x1049c @_Z3LISiPiS_+104    : c_add a5, a4               : IntAlu :  D=0x000000007ffffea8
421689000: system.cpu: T0 : 0x1049e @_Z3LISiPiS_+106    : c_lw a4, 0(a5)             : MemRead :  D=0x0000000000000002 A=0x7ffffea8
421693000: system.cpu: T0 : 0x104a0 @_Z3LISiPiS_+108    : lw a5, -32(s0)             : MemRead :  D=0x0000000000000001 A=0x7ffffa40
421697000: system.cpu: T0 : 0x104a4 @_Z3LISiPiS_+112    : c_slli a5, 2               : IntAlu :  D=0x0000000000000004
421701000: system.cpu: T0 : 0x104a6 @_Z3LISiPiS_+114    : lw a3, -56(s0)             : MemRead :  D=0x000000007ffffe8c A=0x7ffffa28
421705000: system.cpu: T0 : 0x104aa @_Z3LISiPiS_+118    : c_add a5, a3               : IntAlu :  D=0x000000007ffffe90
421707000: system.cpu: T0 : 0x104ac @_Z3LISiPiS_+120    : c_lw a5, 0(a5)             : MemRead :  D=0x0000000000000005 A=0x7ffffe90
421713000: system.cpu: T0 : 0x104ae @_Z3LISiPiS_+122    : bge a5, a4, 64             : IntAlu : 
421717000: system.cpu: T0 : 0x104ee @_Z3LISiPiS_+186    : lw a5, -32(s0)             : MemRead :  D=0x0000000000000001 A=0x7ffffa40
421721000: system.cpu: T0 : 0x104f2 @_Z3LISiPiS_+190    : c_addi a5, 1               : IntAlu :  D=0x0000000000000002
421723000: system.cpu: T0 : 0x104f4 @_Z3LISiPiS_+192    : sw a5, -32(s0)             : MemWrite :  D=0x0000000000000002 A=0x7ffffa40
421727000: system.cpu: T0 : 0x104f8 @_Z3LISiPiS_+196    : lw a4, -32(s0)             : MemRead :  D=0x0000000000000002 A=0x7ffffa40
421731000: system.cpu: T0 : 0x104fc @_Z3LISiPiS_+200    : lw a5, -28(s0)             : MemRead :  D=0x0000000000000007 A=0x7ffffa44
421735000: system.cpu: T0 : 0x10500 @_Z3LISiPiS_+204    : blt a4, a5, -110           : IntAlu : 
421739000: system.cpu: T0 : 0x10492 @_Z3LISiPiS_+94    : lw a5, -28(s0)             : MemRead :  D=0x0000000000000007 A=0x7ffffa44
421743000: system.cpu: T0 : 0x10496 @_Z3LISiPiS_+98    : c_slli a5, 2               : IntAlu :  D=0x000000000000001c
421745000: system.cpu: T0 : 0x10498 @_Z3LISiPiS_+100    : lw a4, -56(s0)             : MemRead :  D=0x000000007ffffe8c A=0x7ffffa28
421749000: system.cpu: T0 : 0x1049c @_Z3LISiPiS_+104    : c_add a5, a4               : IntAlu :  D=0x000000007ffffea8
421751000: system.cpu: T0 : 0x1049e @_Z3LISiPiS_+106    : c_lw a4, 0(a5)             : MemRead :  D=0x0000000000000002 A=0x7ffffea8
421755000: system.cpu: T0 : 0x104a0 @_Z3LISiPiS_+108    : lw a5, -32(s0)             : MemRead :  D=0x0000000000000002 A=0x7ffffa40
421759000: system.cpu: T0 : 0x104a4 @_Z3LISiPiS_+112    : c_slli a5, 2               : IntAlu :  D=0x0000000000000008
421763000: system.cpu: T0 : 0x104a6 @_Z3LISiPiS_+114    : lw a3, -56(s0)             : MemRead :  D=0x000000007ffffe8c A=0x7ffffa28
421767000: system.cpu: T0 : 0x104aa @_Z3LISiPiS_+118    : c_add a5, a3               : IntAlu :  D=0x000000007ffffe94
421769000: system.cpu: T0 : 0x104ac @_Z3LISiPiS_+120    : c_lw a5, 0(a5)             : MemRead :  D=0x0000000000000001 A=0x7ffffe94
421775000: system.cpu: T0 : 0x104ae @_Z3LISiPiS_+122    : bge a5, a4, 64             : IntAlu : 
421779000: system.cpu: T0 : 0x104b2 @_Z3LISiPiS_+126    : lw a5, -32(s0)             : MemRead :  D=0x0000000000000002 A=0x7ffffa40
421783000: system.cpu: T0 : 0x104b6 @_Z3LISiPiS_+130    : c_slli a5, 2               : IntAlu :  D=0x0000000000000008
421785000: system.cpu: T0 : 0x104b8 @_Z3LISiPiS_+132    : lw a4, -60(s0)             : MemRead :  D=0x000000007ffffa60 A=0x7ffffa24
421789000: system.cpu: T0 : 0x104bc @_Z3LISiPiS_+136    : c_add a5, a4               : IntAlu :  D=0x000000007ffffa68
421791000: system.cpu: T0 : 0x104be @_Z3LISiPiS_+138    : c_lw a5, 0(a5)             : MemRead :  D=0x0000000000000001 A=0x7ffffa68
421795000: system.cpu: T0 : 0x104c0 @_Z3LISiPiS_+140    : c_addi a5, 1               : IntAlu :  D=0x0000000000000002
421799000: system.cpu: T0 : 0x104c2 @_Z3LISiPiS_+142    : sw a5, -36(s0)             : MemWrite :  D=0x0000000000000002 A=0x7ffffa3c
421805000: system.cpu: T0 : 0x104c6 @_Z3LISiPiS_+146    : lw a5, -28(s0)             : MemRead :  D=0x0000000000000007 A=0x7ffffa44
421809000: system.cpu: T0 : 0x104ca @_Z3LISiPiS_+150    : c_slli a5, 2               : IntAlu :  D=0x000000000000001c
421811000: system.cpu: T0 : 0x104cc @_Z3LISiPiS_+152    : lw a4, -60(s0)             : MemRead :  D=0x000000007ffffa60 A=0x7ffffa24
421815000: system.cpu: T0 : 0x104d0 @_Z3LISiPiS_+156    : c_add a5, a4               : IntAlu :  D=0x000000007ffffa7c
421817000: system.cpu: T0 : 0x104d2 @_Z3LISiPiS_+158    : c_lw a5, 0(a5)             : MemRead :  D=0x0000000000000001 A=0x7ffffa7c
421821000: system.cpu: T0 : 0x104d4 @_Z3LISiPiS_+160    : lw a4, -36(s0)             : MemRead :  D=0x0000000000000002 A=0x7ffffa3c
421825000: system.cpu: T0 : 0x104d8 @_Z3LISiPiS_+164    : bge a5, a4, 22             : IntAlu : 
421827000: system.cpu: T0 : 0x104dc @_Z3LISiPiS_+168    : lw a5, -28(s0)             : MemRead :  D=0x0000000000000007 A=0x7ffffa44
421831000: system.cpu: T0 : 0x104e0 @_Z3LISiPiS_+172    : c_slli a5, 2               : IntAlu :  D=0x000000000000001c
421835000: system.cpu: T0 : 0x104e2 @_Z3LISiPiS_+174    : lw a4, -60(s0)             : MemRead :  D=0x000000007ffffa60 A=0x7ffffa24
421839000: system.cpu: T0 : 0x104e6 @_Z3LISiPiS_+178    : c_add a5, a4               : IntAlu :  D=0x000000007ffffa7c
421841000: system.cpu: T0 : 0x104e8 @_Z3LISiPiS_+180    : lw a4, -36(s0)             : MemRead :  D=0x0000000000000002 A=0x7ffffa3c
421845000: system.cpu: T0 : 0x104ec @_Z3LISiPiS_+184    : c_sw a4, 0(a5)             : MemWrite :  D=0x0000000000000002 A=0x7ffffa7c
421851000: system.cpu: T0 : 0x104ee @_Z3LISiPiS_+186    : lw a5, -32(s0)             : MemRead :  D=0x0000000000000002 A=0x7ffffa40
421855000: system.cpu: T0 : 0x104f2 @_Z3LISiPiS_+190    : c_addi a5, 1               : IntAlu :  D=0x0000000000000003
421857000: system.cpu: T0 : 0x104f4 @_Z3LISiPiS_+192    : sw a5, -32(s0)             : MemWrite :  D=0x0000000000000003 A=0x7ffffa40
421861000: system.cpu: T0 : 0x104f8 @_Z3LISiPiS_+196    : lw a4, -32(s0)             : MemRead :  D=0x0000000000000003 A=0x7ffffa40
421865000: system.cpu: T0 : 0x104fc @_Z3LISiPiS_+200    : lw a5, -28(s0)             : MemRead :  D=0x0000000000000007 A=0x7ffffa44
421869000: system.cpu: T0 : 0x10500 @_Z3LISiPiS_+204    : blt a4, a5, -110           : IntAlu : 
421873000: system.cpu: T0 : 0x10492 @_Z3LISiPiS_+94    : lw a5, -28(s0)             : MemRead :  D=0x0000000000000007 A=0x7ffffa44
421877000: system.cpu: T0 : 0x10496 @_Z3LISiPiS_+98    : c_slli a5, 2               : IntAlu :  D=0x000000000000001c
421879000: system.cpu: T0 : 0x10498 @_Z3LISiPiS_+100    : lw a4, -56(s0)             : MemRead :  D=0x000000007ffffe8c A=0x7ffffa28
421883000: system.cpu: T0 : 0x1049c @_Z3LISiPiS_+104    : c_add a5, a4               : IntAlu :  D=0x000000007ffffea8
421885000: system.cpu: T0 : 0x1049e @_Z3LISiPiS_+106    : c_lw a4, 0(a5)             : MemRead :  D=0x0000000000000002 A=0x7ffffea8
421889000: system.cpu: T0 : 0x104a0 @_Z3LISiPiS_+108    : lw a5, -32(s0)             : MemRead :  D=0x0000000000000003 A=0x7ffffa40
421893000: system.cpu: T0 : 0x104a4 @_Z3LISiPiS_+112    : c_slli a5, 2               : IntAlu :  D=0x000000000000000c
421897000: system.cpu: T0 : 0x104a6 @_Z3LISiPiS_+114    : lw a3, -56(s0)             : MemRead :  D=0x000000007ffffe8c A=0x7ffffa28
421901000: system.cpu: T0 : 0x104aa @_Z3LISiPiS_+118    : c_add a5, a3               : IntAlu :  D=0x000000007ffffe98
421903000: system.cpu: T0 : 0x104ac @_Z3LISiPiS_+120    : c_lw a5, 0(a5)             : MemRead :  D=0x0000000000000008 A=0x7ffffe98
421909000: system.cpu: T0 : 0x104ae @_Z3LISiPiS_+122    : bge a5, a4, 64             : IntAlu : 
421913000: system.cpu: T0 : 0x104ee @_Z3LISiPiS_+186    : lw a5, -32(s0)             : MemRead :  D=0x0000000000000003 A=0x7ffffa40
421917000: system.cpu: T0 : 0x104f2 @_Z3LISiPiS_+190    : c_addi a5, 1               : IntAlu :  D=0x0000000000000004
421919000: system.cpu: T0 : 0x104f4 @_Z3LISiPiS_+192    : sw a5, -32(s0)             : MemWrite :  D=0x0000000000000004 A=0x7ffffa40
421923000: system.cpu: T0 : 0x104f8 @_Z3LISiPiS_+196    : lw a4, -32(s0)             : MemRead :  D=0x0000000000000004 A=0x7ffffa40
421927000: system.cpu: T0 : 0x104fc @_Z3LISiPiS_+200    : lw a5, -28(s0)             : MemRead :  D=0x0000000000000007 A=0x7ffffa44
421931000: system.cpu: T0 : 0x10500 @_Z3LISiPiS_+204    : blt a4, a5, -110           : IntAlu : 
421935000: system.cpu: T0 : 0x10492 @_Z3LISiPiS_+94    : lw a5, -28(s0)             : MemRead :  D=0x0000000000000007 A=0x7ffffa44
421939000: system.cpu: T0 : 0x10496 @_Z3LISiPiS_+98    : c_slli a5, 2               : IntAlu :  D=0x000000000000001c
421941000: system.cpu: T0 : 0x10498 @_Z3LISiPiS_+100    : lw a4, -56(s0)             : MemRead :  D=0x000000007ffffe8c A=0x7ffffa28
421945000: system.cpu: T0 : 0x1049c @_Z3LISiPiS_+104    : c_add a5, a4               : IntAlu :  D=0x000000007ffffea8
421947000: system.cpu: T0 : 0x1049e @_Z3LISiPiS_+106    : c_lw a4, 0(a5)             : MemRead :  D=0x0000000000000002 A=0x7ffffea8
421951000: system.cpu: T0 : 0x104a0 @_Z3LISiPiS_+108    : lw a5, -32(s0)             : MemRead :  D=0x0000000000000004 A=0x7ffffa40
421955000: system.cpu: T0 : 0x104a4 @_Z3LISiPiS_+112    : c_slli a5, 2               : IntAlu :  D=0x0000000000000010
421959000: system.cpu: T0 : 0x104a6 @_Z3LISiPiS_+114    : lw a3, -56(s0)             : MemRead :  D=0x000000007ffffe8c A=0x7ffffa28
421963000: system.cpu: T0 : 0x104aa @_Z3LISiPiS_+118    : c_add a5, a3               : IntAlu :  D=0x000000007ffffe9c
421965000: system.cpu: T0 : 0x104ac @_Z3LISiPiS_+120    : c_lw a5, 0(a5)             : MemRead :  D=0x0000000000000003 A=0x7ffffe9c
421971000: system.cpu: T0 : 0x104ae @_Z3LISiPiS_+122    : bge a5, a4, 64             : IntAlu : 
421975000: system.cpu: T0 : 0x104ee @_Z3LISiPiS_+186    : lw a5, -32(s0)             : MemRead :  D=0x0000000000000004 A=0x7ffffa40
421979000: system.cpu: T0 : 0x104f2 @_Z3LISiPiS_+190    : c_addi a5, 1               : IntAlu :  D=0x0000000000000005
421981000: system.cpu: T0 : 0x104f4 @_Z3LISiPiS_+192    : sw a5, -32(s0)             : MemWrite :  D=0x0000000000000005 A=0x7ffffa40
421985000: system.cpu: T0 : 0x104f8 @_Z3LISiPiS_+196    : lw a4, -32(s0)             : MemRead :  D=0x0000000000000005 A=0x7ffffa40
421989000: system.cpu: T0 : 0x104fc @_Z3LISiPiS_+200    : lw a5, -28(s0)             : MemRead :  D=0x0000000000000007 A=0x7ffffa44
421993000: system.cpu: T0 : 0x10500 @_Z3LISiPiS_+204    : blt a4, a5, -110           : IntAlu : 
421997000: system.cpu: T0 : 0x10492 @_Z3LISiPiS_+94    : lw a5, -28(s0)             : MemRead :  D=0x0000000000000007 A=0x7ffffa44
422001000: system.cpu: T0 : 0x10496 @_Z3LISiPiS_+98    : c_slli a5, 2               : IntAlu :  D=0x000000000000001c
422003000: system.cpu: T0 : 0x10498 @_Z3LISiPiS_+100    : lw a4, -56(s0)             : MemRead :  D=0x000000007ffffe8c A=0x7ffffa28
422007000: system.cpu: T0 : 0x1049c @_Z3LISiPiS_+104    : c_add a5, a4               : IntAlu :  D=0x000000007ffffea8
422009000: system.cpu: T0 : 0x1049e @_Z3LISiPiS_+106    : c_lw a4, 0(a5)             : MemRead :  D=0x0000000000000002 A=0x7ffffea8
422013000: system.cpu: T0 : 0x104a0 @_Z3LISiPiS_+108    : lw a5, -32(s0)             : MemRead :  D=0x0000000000000005 A=0x7ffffa40
422017000: system.cpu: T0 : 0x104a4 @_Z3LISiPiS_+112    : c_slli a5, 2               : IntAlu :  D=0x0000000000000014
422021000: system.cpu: T0 : 0x104a6 @_Z3LISiPiS_+114    : lw a3, -56(s0)             : MemRead :  D=0x000000007ffffe8c A=0x7ffffa28
422025000: system.cpu: T0 : 0x104aa @_Z3LISiPiS_+118    : c_add a5, a3               : IntAlu :  D=0x000000007ffffea0
422027000: system.cpu: T0 : 0x104ac @_Z3LISiPiS_+120    : c_lw a5, 0(a5)             : MemRead :  D=0x0000000000000006 A=0x7ffffea0
422033000: system.cpu: T0 : 0x104ae @_Z3LISiPiS_+122    : bge a5, a4, 64             : IntAlu : 
422037000: system.cpu: T0 : 0x104ee @_Z3LISiPiS_+186    : lw a5, -32(s0)             : MemRead :  D=0x0000000000000005 A=0x7ffffa40
422041000: system.cpu: T0 : 0x104f2 @_Z3LISiPiS_+190    : c_addi a5, 1               : IntAlu :  D=0x0000000000000006
422043000: system.cpu: T0 : 0x104f4 @_Z3LISiPiS_+192    : sw a5, -32(s0)             : MemWrite :  D=0x0000000000000006 A=0x7ffffa40
422047000: system.cpu: T0 : 0x104f8 @_Z3LISiPiS_+196    : lw a4, -32(s0)             : MemRead :  D=0x0000000000000006 A=0x7ffffa40
422051000: system.cpu: T0 : 0x104fc @_Z3LISiPiS_+200    : lw a5, -28(s0)             : MemRead :  D=0x0000000000000007 A=0x7ffffa44
422055000: system.cpu: T0 : 0x10500 @_Z3LISiPiS_+204    : blt a4, a5, -110           : IntAlu : 
422059000: system.cpu: T0 : 0x10492 @_Z3LISiPiS_+94    : lw a5, -28(s0)             : MemRead :  D=0x0000000000000007 A=0x7ffffa44
422063000: system.cpu: T0 : 0x10496 @_Z3LISiPiS_+98    : c_slli a5, 2               : IntAlu :  D=0x000000000000001c
422065000: system.cpu: T0 : 0x10498 @_Z3LISiPiS_+100    : lw a4, -56(s0)             : MemRead :  D=0x000000007ffffe8c A=0x7ffffa28
422069000: system.cpu: T0 : 0x1049c @_Z3LISiPiS_+104    : c_add a5, a4               : IntAlu :  D=0x000000007ffffea8
422071000: system.cpu: T0 : 0x1049e @_Z3LISiPiS_+106    : c_lw a4, 0(a5)             : MemRead :  D=0x0000000000000002 A=0x7ffffea8
422075000: system.cpu: T0 : 0x104a0 @_Z3LISiPiS_+108    : lw a5, -32(s0)             : MemRead :  D=0x0000000000000006 A=0x7ffffa40
422079000: system.cpu: T0 : 0x104a4 @_Z3LISiPiS_+112    : c_slli a5, 2               : IntAlu :  D=0x0000000000000018
422083000: system.cpu: T0 : 0x104a6 @_Z3LISiPiS_+114    : lw a3, -56(s0)             : MemRead :  D=0x000000007ffffe8c A=0x7ffffa28
422087000: system.cpu: T0 : 0x104aa @_Z3LISiPiS_+118    : c_add a5, a3               : IntAlu :  D=0x000000007ffffea4
422089000: system.cpu: T0 : 0x104ac @_Z3LISiPiS_+120    : c_lw a5, 0(a5)             : MemRead :  D=0x0000000000000009 A=0x7ffffea4
422095000: system.cpu: T0 : 0x104ae @_Z3LISiPiS_+122    : bge a5, a4, 64             : IntAlu : 
422099000: system.cpu: T0 : 0x104ee @_Z3LISiPiS_+186    : lw a5, -32(s0)             : MemRead :  D=0x0000000000000006 A=0x7ffffa40
422103000: system.cpu: T0 : 0x104f2 @_Z3LISiPiS_+190    : c_addi a5, 1               : IntAlu :  D=0x0000000000000007
422105000: system.cpu: T0 : 0x104f4 @_Z3LISiPiS_+192    : sw a5, -32(s0)             : MemWrite :  D=0x0000000000000007 A=0x7ffffa40
422109000: system.cpu: T0 : 0x104f8 @_Z3LISiPiS_+196    : lw a4, -32(s0)             : MemRead :  D=0x0000000000000007 A=0x7ffffa40
422113000: system.cpu: T0 : 0x104fc @_Z3LISiPiS_+200    : lw a5, -28(s0)             : MemRead :  D=0x0000000000000007 A=0x7ffffa44
422117000: system.cpu: T0 : 0x10500 @_Z3LISiPiS_+204    : blt a4, a5, -110           : IntAlu : 
422119000: system.cpu: T0 : 0x10504 @_Z3LISiPiS_+208    : lw a5, -28(s0)             : MemRead :  D=0x0000000000000007 A=0x7ffffa44
422123000: system.cpu: T0 : 0x10508 @_Z3LISiPiS_+212    : c_slli a5, 2               : IntAlu :  D=0x000000000000001c
422127000: system.cpu: T0 : 0x1050a @_Z3LISiPiS_+214    : lw a4, -60(s0)             : MemRead :  D=0x000000007ffffa60 A=0x7ffffa24
422131000: system.cpu: T0 : 0x1050e @_Z3LISiPiS_+218    : c_add a5, a4               : IntAlu :  D=0x000000007ffffa7c
422133000: system.cpu: T0 : 0x10510 @_Z3LISiPiS_+220    : c_lw a5, 0(a5)             : MemRead :  D=0x0000000000000002 A=0x7ffffa7c
422139000: system.cpu: T0 : 0x10512 @_Z3LISiPiS_+222    : lw a4, -20(s0)             : MemRead :  D=0x0000000000000004 A=0x7ffffa4c
422145000: system.cpu: T0 : 0x10516 @_Z3LISiPiS_+226    : bge a4, a5, 22             : IntAlu : 
422147000: system.cpu: T0 : 0x1052c @_Z3LISiPiS_+248    : lw a5, -28(s0)             : MemRead :  D=0x0000000000000007 A=0x7ffffa44
422151000: system.cpu: T0 : 0x10530 @_Z3LISiPiS_+252    : c_addi a5, 1               : IntAlu :  D=0x0000000000000008
422155000: system.cpu: T0 : 0x10532 @_Z3LISiPiS_+254    : sw a5, -28(s0)             : MemWrite :  D=0x0000000000000008 A=0x7ffffa44
422161000: system.cpu: T0 : 0x10536 @_Z3LISiPiS_+258    : lw a4, -28(s0)             : MemRead :  D=0x0000000000000008 A=0x7ffffa44
422167000: system.cpu: T0 : 0x1053a @_Z3LISiPiS_+262    : lw a5, -52(s0)             : MemRead :  D=0x0000000000000008 A=0x7ffffa2c
422173000: system.cpu: T0 : 0x1053e @_Z3LISiPiS_+266    : blt a4, a5, -178           : IntAlu : 
422177000: system.cpu: T0 : 0x10542 @_Z3LISiPiS_+270    : lw a5, -20(s0)             : MemRead :  D=0x0000000000000004 A=0x7ffffa4c
422181000: system.cpu: T0 : 0x10546 @_Z3LISiPiS_+274    : c_mv a0, a5                : IntAlu :  D=0x0000000000000004
422183000: system.cpu: T0 : 0x10548 @_Z3LISiPiS_+276    : c_lwsp ra, 60(sp)          : MemRead :  D=0x000000000001062e A=0x7ffffa5c
422187000: system.cpu: T0 : 0x1054a @_Z3LISiPiS_+278    : c_lwsp s0, 56(sp)          : MemRead :  D=0x000000007ffffed0 A=0x7ffffa58
422191000: system.cpu: T0 : 0x1054c @_Z3LISiPiS_+280    : c_addi16sp sp, 64          : IntAlu :  D=0x000000007ffffa60
422193000: system.cpu: T0 : 0x1054e @_Z3LISiPiS_+282    : c_jr ra                    : IntAlu : 
422197000: system.cpu: T0 : 0x1062e @main+222    : sw a0, -32(s0)             : MemWrite :  D=0x0000000000000004 A=0x7ffffeb0
422203000: system.cpu: T0 : 0x10632 @main+226    : addi a4, s0, -1092         : IntAlu :  D=0x000000007ffffa8c
422207000: system.cpu: T0 : 0x10636 @main+230    : lw a3, -32(s0)             : MemRead :  D=0x0000000000000004 A=0x7ffffeb0
422213000: system.cpu: T0 : 0x1063a @main+234    : lui a5, 79                 : IntAlu :  D=0x000000000004f000
422324000: system.cpu: T0 : 0x1063e @main+238    : addi a2, a5, -1732         : IntAlu :  D=0x000000000004e93c
422328000: system.cpu: T0 : 0x10642 @main+242    : addi a1, zero, 1024        : IntAlu :  D=0x0000000000000400
422330000: system.cpu: T0 : 0x10646 @main+246    : c_mv a0, a4                : IntAlu :  D=0x000000007ffffa8c
422332000: system.cpu: T0 : 0x10648 @main+248    : jal ra, 2102               : IntAlu :  D=0x000000000001064c
*/