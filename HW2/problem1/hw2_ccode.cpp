#include <fcntl.h>
#include <unistd.h>
#include <cstdio>
#include <cstdlib>

int fact(int n){
    return (n == 0)? 4 : (4 * fact((n - 1) >> 1) + 8 * n + 3);
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
// Total simulation time: 432953000 ticks
// Time enter @main: 416967000 ticks
// Main execution time: 15986000 ticks

// n=30
// Total simulation time: 433033000 ticks
// Time enter @main: 416967000 ticks
// Main execution time: 16066000 ticks
// 651


/*
416967000: system.cpu: T0 : 0x1046e @main    : c_addi16sp sp, -64         : IntAlu :  D=0x000000007ffffe90
416969000: system.cpu: T0 : 0x10470 @main+2    : c_swsp ra, 60(sp)          : MemWrite :  D=0x000000000001053a A=0x7ffffecc
416973000: system.cpu: T0 : 0x10472 @main+4    : c_swsp s0, 56(sp)          : MemWrite :  D=0x0000000000077b68 A=0x7ffffec8
416977000: system.cpu: T0 : 0x10474 @main+6    : c_addi4spn s0, sp, 64      : IntAlu :  D=0x000000007ffffed0
416979000: system.cpu: T0 : 0x10476 @main+8    : c_li a5, 30                : IntAlu :  D=0x000000000000001e
416981000: system.cpu: T0 : 0x10478 @main+10    : sw a5, -20(s0)             : MemWrite :  D=0x000000000000001e A=0x7ffffebc
416985000: system.cpu: T0 : 0x1047c @main+14    : lw a0, -20(s0)             : MemRead :  D=0x000000000000001e A=0x7ffffebc
417082000: system.cpu: T0 : 0x10480 @main+18    : c_jal -76                  : IntAlu :  D=0x0000000000010482
417084000: system.cpu: T0 : 0x10434 @_Z4facti    : c_addi sp, -32             : IntAlu :  D=0x000000007ffffe70
417086000: system.cpu: T0 : 0x10436 @_Z4facti+2    : c_swsp ra, 28(sp)          : MemWrite :  D=0x0000000000010482 A=0x7ffffe8c
417090000: system.cpu: T0 : 0x10438 @_Z4facti+4    : c_swsp s0, 24(sp)          : MemWrite :  D=0x000000007ffffed0 A=0x7ffffe88
417094000: system.cpu: T0 : 0x1043a @_Z4facti+6    : c_addi4spn s0, sp, 32      : IntAlu :  D=0x000000007ffffe90
417096000: system.cpu: T0 : 0x1043c @_Z4facti+8    : sw a0, -20(s0)             : MemWrite :  D=0x000000000000001e A=0x7ffffe7c
417124000: system.cpu: T0 : 0x10440 @_Z4facti+12    : lw a5, -20(s0)             : MemRead :  D=0x000000000000001e A=0x7ffffe7c
417128000: system.cpu: T0 : 0x10444 @_Z4facti+16    : c_beqz a5, 30              : IntAlu : 
417132000: system.cpu: T0 : 0x10446 @_Z4facti+18    : lw a5, -20(s0)             : MemRead :  D=0x000000000000001e A=0x7ffffe7c
417136000: system.cpu: T0 : 0x1044a @_Z4facti+22    : c_addi a5, -1              : IntAlu :  D=0x000000000000001d
417138000: system.cpu: T0 : 0x1044c @_Z4facti+24    : c_srai a5, 1               : IntAlu :  D=0x000000000000000e
417140000: system.cpu: T0 : 0x1044e @_Z4facti+26    : c_mv a0, a5                : IntAlu :  D=0x000000000000000e
417142000: system.cpu: T0 : 0x10450 @_Z4facti+28    : c_jal -28                  : IntAlu :  D=0x0000000000010452
417144000: system.cpu: T0 : 0x10434 @_Z4facti    : c_addi sp, -32             : IntAlu :  D=0x000000007ffffe50
417146000: system.cpu: T0 : 0x10436 @_Z4facti+2    : c_swsp ra, 28(sp)          : MemWrite :  D=0x0000000000010452 A=0x7ffffe6c
417150000: system.cpu: T0 : 0x10438 @_Z4facti+4    : c_swsp s0, 24(sp)          : MemWrite :  D=0x000000007ffffe90 A=0x7ffffe68
417154000: system.cpu: T0 : 0x1043a @_Z4facti+6    : c_addi4spn s0, sp, 32      : IntAlu :  D=0x000000007ffffe70
417156000: system.cpu: T0 : 0x1043c @_Z4facti+8    : sw a0, -20(s0)             : MemWrite :  D=0x000000000000000e A=0x7ffffe5c
417160000: system.cpu: T0 : 0x10440 @_Z4facti+12    : lw a5, -20(s0)             : MemRead :  D=0x000000000000000e A=0x7ffffe5c
417164000: system.cpu: T0 : 0x10444 @_Z4facti+16    : c_beqz a5, 30              : IntAlu : 
417168000: system.cpu: T0 : 0x10446 @_Z4facti+18    : lw a5, -20(s0)             : MemRead :  D=0x000000000000000e A=0x7ffffe5c
417172000: system.cpu: T0 : 0x1044a @_Z4facti+22    : c_addi a5, -1              : IntAlu :  D=0x000000000000000d
417174000: system.cpu: T0 : 0x1044c @_Z4facti+24    : c_srai a5, 1               : IntAlu :  D=0x0000000000000006
417176000: system.cpu: T0 : 0x1044e @_Z4facti+26    : c_mv a0, a5                : IntAlu :  D=0x0000000000000006
417178000: system.cpu: T0 : 0x10450 @_Z4facti+28    : c_jal -28                  : IntAlu :  D=0x0000000000010452
417180000: system.cpu: T0 : 0x10434 @_Z4facti    : c_addi sp, -32             : IntAlu :  D=0x000000007ffffe30
417182000: system.cpu: T0 : 0x10436 @_Z4facti+2    : c_swsp ra, 28(sp)          : MemWrite :  D=0x0000000000010452 A=0x7ffffe4c
417186000: system.cpu: T0 : 0x10438 @_Z4facti+4    : c_swsp s0, 24(sp)          : MemWrite :  D=0x000000007ffffe70 A=0x7ffffe48
417190000: system.cpu: T0 : 0x1043a @_Z4facti+6    : c_addi4spn s0, sp, 32      : IntAlu :  D=0x000000007ffffe50
417192000: system.cpu: T0 : 0x1043c @_Z4facti+8    : sw a0, -20(s0)             : MemWrite :  D=0x0000000000000006 A=0x7ffffe3c
417289000: system.cpu: T0 : 0x10440 @_Z4facti+12    : lw a5, -20(s0)             : MemRead :  D=0x0000000000000006 A=0x7ffffe3c
417293000: system.cpu: T0 : 0x10444 @_Z4facti+16    : c_beqz a5, 30              : IntAlu : 
417297000: system.cpu: T0 : 0x10446 @_Z4facti+18    : lw a5, -20(s0)             : MemRead :  D=0x0000000000000006 A=0x7ffffe3c
417301000: system.cpu: T0 : 0x1044a @_Z4facti+22    : c_addi a5, -1              : IntAlu :  D=0x0000000000000005
417303000: system.cpu: T0 : 0x1044c @_Z4facti+24    : c_srai a5, 1               : IntAlu :  D=0x0000000000000002
417305000: system.cpu: T0 : 0x1044e @_Z4facti+26    : c_mv a0, a5                : IntAlu :  D=0x0000000000000002
417307000: system.cpu: T0 : 0x10450 @_Z4facti+28    : c_jal -28                  : IntAlu :  D=0x0000000000010452
417309000: system.cpu: T0 : 0x10434 @_Z4facti    : c_addi sp, -32             : IntAlu :  D=0x000000007ffffe10
417311000: system.cpu: T0 : 0x10436 @_Z4facti+2    : c_swsp ra, 28(sp)          : MemWrite :  D=0x0000000000010452 A=0x7ffffe2c
417315000: system.cpu: T0 : 0x10438 @_Z4facti+4    : c_swsp s0, 24(sp)          : MemWrite :  D=0x000000007ffffe50 A=0x7ffffe28
417319000: system.cpu: T0 : 0x1043a @_Z4facti+6    : c_addi4spn s0, sp, 32      : IntAlu :  D=0x000000007ffffe30
417321000: system.cpu: T0 : 0x1043c @_Z4facti+8    : sw a0, -20(s0)             : MemWrite :  D=0x0000000000000002 A=0x7ffffe1c
417325000: system.cpu: T0 : 0x10440 @_Z4facti+12    : lw a5, -20(s0)             : MemRead :  D=0x0000000000000002 A=0x7ffffe1c
417329000: system.cpu: T0 : 0x10444 @_Z4facti+16    : c_beqz a5, 30              : IntAlu : 
417333000: system.cpu: T0 : 0x10446 @_Z4facti+18    : lw a5, -20(s0)             : MemRead :  D=0x0000000000000002 A=0x7ffffe1c
417337000: system.cpu: T0 : 0x1044a @_Z4facti+22    : c_addi a5, -1              : IntAlu :  D=0x0000000000000001
417339000: system.cpu: T0 : 0x1044c @_Z4facti+24    : c_srai a5, 1               : IntAlu :  D=0x0000000000000000
417341000: system.cpu: T0 : 0x1044e @_Z4facti+26    : c_mv a0, a5                : IntAlu :  D=0x0000000000000000
417343000: system.cpu: T0 : 0x10450 @_Z4facti+28    : c_jal -28                  : IntAlu :  D=0x0000000000010452
417345000: system.cpu: T0 : 0x10434 @_Z4facti    : c_addi sp, -32             : IntAlu :  D=0x000000007ffffdf0
417347000: system.cpu: T0 : 0x10436 @_Z4facti+2    : c_swsp ra, 28(sp)          : MemWrite :  D=0x0000000000010452 A=0x7ffffe0c
417351000: system.cpu: T0 : 0x10438 @_Z4facti+4    : c_swsp s0, 24(sp)          : MemWrite :  D=0x000000007ffffe30 A=0x7ffffe08
417355000: system.cpu: T0 : 0x1043a @_Z4facti+6    : c_addi4spn s0, sp, 32      : IntAlu :  D=0x000000007ffffe10
417357000: system.cpu: T0 : 0x1043c @_Z4facti+8    : sw a0, -20(s0)             : MemWrite :  D=0x0000000000000000 A=0x7ffffdfc
417454000: system.cpu: T0 : 0x10440 @_Z4facti+12    : lw a5, -20(s0)             : MemRead :  D=0x0000000000000000 A=0x7ffffdfc
417458000: system.cpu: T0 : 0x10444 @_Z4facti+16    : c_beqz a5, 30              : IntAlu : 
417460000: system.cpu: T0 : 0x10462 @_Z4facti+46    : c_li a5, 4                 : IntAlu :  D=0x0000000000000004
417462000: system.cpu: T0 : 0x10464 @_Z4facti+48    : c_mv a0, a5                : IntAlu :  D=0x0000000000000004
417464000: system.cpu: T0 : 0x10466 @_Z4facti+50    : c_lwsp ra, 28(sp)          : MemRead :  D=0x0000000000010452 A=0x7ffffe0c
417468000: system.cpu: T0 : 0x10468 @_Z4facti+52    : c_lwsp s0, 24(sp)          : MemRead :  D=0x000000007ffffe30 A=0x7ffffe08
417472000: system.cpu: T0 : 0x1046a @_Z4facti+54    : c_addi16sp sp, 32          : IntAlu :  D=0x000000007ffffe10
417474000: system.cpu: T0 : 0x1046c @_Z4facti+56    : c_jr ra                    : IntAlu : 
417476000: system.cpu: T0 : 0x10452 @_Z4facti+30    : c_mv a4, a0                : IntAlu :  D=0x0000000000000004
417478000: system.cpu: T0 : 0x10454 @_Z4facti+32    : lw a5, -20(s0)             : MemRead :  D=0x0000000000000002 A=0x7ffffe1c
417482000: system.cpu: T0 : 0x10458 @_Z4facti+36    : c_slli a5, 1               : IntAlu :  D=0x0000000000000004
417484000: system.cpu: T0 : 0x1045a @_Z4facti+38    : c_add a5, a4               : IntAlu :  D=0x0000000000000008
417486000: system.cpu: T0 : 0x1045c @_Z4facti+40    : c_slli a5, 2               : IntAlu :  D=0x0000000000000020
417488000: system.cpu: T0 : 0x1045e @_Z4facti+42    : c_addi a5, 3               : IntAlu :  D=0x0000000000000023
417490000: system.cpu: T0 : 0x10460 @_Z4facti+44    : c_j 4                      : IntAlu : 
417492000: system.cpu: T0 : 0x10464 @_Z4facti+48    : c_mv a0, a5                : IntAlu :  D=0x0000000000000023
417494000: system.cpu: T0 : 0x10466 @_Z4facti+50    : c_lwsp ra, 28(sp)          : MemRead :  D=0x0000000000010452 A=0x7ffffe2c
417498000: system.cpu: T0 : 0x10468 @_Z4facti+52    : c_lwsp s0, 24(sp)          : MemRead :  D=0x000000007ffffe50 A=0x7ffffe28
417502000: system.cpu: T0 : 0x1046a @_Z4facti+54    : c_addi16sp sp, 32          : IntAlu :  D=0x000000007ffffe30
417504000: system.cpu: T0 : 0x1046c @_Z4facti+56    : c_jr ra                    : IntAlu : 
417506000: system.cpu: T0 : 0x10452 @_Z4facti+30    : c_mv a4, a0                : IntAlu :  D=0x0000000000000023
417508000: system.cpu: T0 : 0x10454 @_Z4facti+32    : lw a5, -20(s0)             : MemRead :  D=0x0000000000000006 A=0x7ffffe3c
417512000: system.cpu: T0 : 0x10458 @_Z4facti+36    : c_slli a5, 1               : IntAlu :  D=0x000000000000000c
417514000: system.cpu: T0 : 0x1045a @_Z4facti+38    : c_add a5, a4               : IntAlu :  D=0x000000000000002f
417516000: system.cpu: T0 : 0x1045c @_Z4facti+40    : c_slli a5, 2               : IntAlu :  D=0x00000000000000bc
417518000: system.cpu: T0 : 0x1045e @_Z4facti+42    : c_addi a5, 3               : IntAlu :  D=0x00000000000000bf
417520000: system.cpu: T0 : 0x10460 @_Z4facti+44    : c_j 4                      : IntAlu : 
417522000: system.cpu: T0 : 0x10464 @_Z4facti+48    : c_mv a0, a5                : IntAlu :  D=0x00000000000000bf
417524000: system.cpu: T0 : 0x10466 @_Z4facti+50    : c_lwsp ra, 28(sp)          : MemRead :  D=0x0000000000010452 A=0x7ffffe4c
417528000: system.cpu: T0 : 0x10468 @_Z4facti+52    : c_lwsp s0, 24(sp)          : MemRead :  D=0x000000007ffffe70 A=0x7ffffe48
417532000: system.cpu: T0 : 0x1046a @_Z4facti+54    : c_addi16sp sp, 32          : IntAlu :  D=0x000000007ffffe50
417534000: system.cpu: T0 : 0x1046c @_Z4facti+56    : c_jr ra                    : IntAlu : 
417536000: system.cpu: T0 : 0x10452 @_Z4facti+30    : c_mv a4, a0                : IntAlu :  D=0x00000000000000bf
417538000: system.cpu: T0 : 0x10454 @_Z4facti+32    : lw a5, -20(s0)             : MemRead :  D=0x000000000000000e A=0x7ffffe5c
417542000: system.cpu: T0 : 0x10458 @_Z4facti+36    : c_slli a5, 1               : IntAlu :  D=0x000000000000001c
417544000: system.cpu: T0 : 0x1045a @_Z4facti+38    : c_add a5, a4               : IntAlu :  D=0x00000000000000db
417546000: system.cpu: T0 : 0x1045c @_Z4facti+40    : c_slli a5, 2               : IntAlu :  D=0x000000000000036c
417548000: system.cpu: T0 : 0x1045e @_Z4facti+42    : c_addi a5, 3               : IntAlu :  D=0x000000000000036f
417550000: system.cpu: T0 : 0x10460 @_Z4facti+44    : c_j 4                      : IntAlu : 
417552000: system.cpu: T0 : 0x10464 @_Z4facti+48    : c_mv a0, a5                : IntAlu :  D=0x000000000000036f
417554000: system.cpu: T0 : 0x10466 @_Z4facti+50    : c_lwsp ra, 28(sp)          : MemRead :  D=0x0000000000010452 A=0x7ffffe6c
417558000: system.cpu: T0 : 0x10468 @_Z4facti+52    : c_lwsp s0, 24(sp)          : MemRead :  D=0x000000007ffffe90 A=0x7ffffe68
417562000: system.cpu: T0 : 0x1046a @_Z4facti+54    : c_addi16sp sp, 32          : IntAlu :  D=0x000000007ffffe70
417564000: system.cpu: T0 : 0x1046c @_Z4facti+56    : c_jr ra                    : IntAlu : 
417566000: system.cpu: T0 : 0x10452 @_Z4facti+30    : c_mv a4, a0                : IntAlu :  D=0x000000000000036f
417568000: system.cpu: T0 : 0x10454 @_Z4facti+32    : lw a5, -20(s0)             : MemRead :  D=0x000000000000001e A=0x7ffffe7c
417572000: system.cpu: T0 : 0x10458 @_Z4facti+36    : c_slli a5, 1               : IntAlu :  D=0x000000000000003c
417574000: system.cpu: T0 : 0x1045a @_Z4facti+38    : c_add a5, a4               : IntAlu :  D=0x00000000000003ab
417576000: system.cpu: T0 : 0x1045c @_Z4facti+40    : c_slli a5, 2               : IntAlu :  D=0x0000000000000eac
417578000: system.cpu: T0 : 0x1045e @_Z4facti+42    : c_addi a5, 3               : IntAlu :  D=0x0000000000000eaf
417580000: system.cpu: T0 : 0x10460 @_Z4facti+44    : c_j 4                      : IntAlu : 
417582000: system.cpu: T0 : 0x10464 @_Z4facti+48    : c_mv a0, a5                : IntAlu :  D=0x0000000000000eaf
417584000: system.cpu: T0 : 0x10466 @_Z4facti+50    : c_lwsp ra, 28(sp)          : MemRead :  D=0x0000000000010482 A=0x7ffffe8c
417588000: system.cpu: T0 : 0x10468 @_Z4facti+52    : c_lwsp s0, 24(sp)          : MemRead :  D=0x000000007ffffed0 A=0x7ffffe88
417592000: system.cpu: T0 : 0x1046a @_Z4facti+54    : c_addi16sp sp, 32          : IntAlu :  D=0x000000007ffffe90
417594000: system.cpu: T0 : 0x1046c @_Z4facti+56    : c_jr ra                    : IntAlu : 
417596000: system.cpu: T0 : 0x10482 @main+20    : c_mv a5, a0                : IntAlu :  D=0x0000000000000eaf
417598000: system.cpu: T0 : 0x10484 @main+22    : sw a5, -24(s0)             : MemWrite :  D=0x0000000000000eaf A=0x7ffffeb8
417602000: system.cpu: T0 : 0x10488 @main+26    : addi a4, s0, -60           : IntAlu :  D=0x000000007ffffe94
417604000: system.cpu: T0 : 0x1048c @main+30    : lw a3, -24(s0)             : MemRead :  D=0x0000000000000eaf A=0x7ffffeb8
417608000: system.cpu: T0 : 0x10490 @main+34    : lui a5, 78                 : IntAlu :  D=0x000000000004e000
417610000: system.cpu: T0 : 0x10494 @main+38    : addi a2, a5, 1916          : IntAlu :  D=0x000000000004e77c
417612000: system.cpu: T0 : 0x10498 @main+42    : addi a1, zero, 32          : IntAlu :  D=0x0000000000000020
417614000: system.cpu: T0 : 0x1049c @main+46    : c_mv a0, a4                : IntAlu :  D=0x000000007ffffe94
417618000: system.cpu: T0 : 0x1049e @main+48    : jal ra, 2084               : IntAlu :  D=0x00000000000104a2
*/