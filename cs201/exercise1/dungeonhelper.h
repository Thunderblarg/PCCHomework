#include <stdio.h>
#include <math.h>

#define TRAP_DOORS      1
#define BOULDER_ROLL    2
#define SPIKE_TRAPS     4
#define CEILING_CRUSH   8
#define LOG_SWING       16
#define FLAMETHROWER    32
#define NET_SNARE       64
#define BOSS_BATTLE     128

void starting_up();
void display_menu(int mask);
int toggle_trap(int* mask);