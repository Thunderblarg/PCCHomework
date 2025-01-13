#include <stdio.h>
#include "dungeonhelper.h"

// #define TRAP_DOORS      1
// #define BOULDER_ROLL    2
// #define SPIKE_TRAPS     4
// #define CEILING_CRUSH   8
// #define LOG_SWING       16
// #define FLAMETHROWER    32
// #define NET_SNARE       64
// #define BOSS_BATTLE     128

// void starting_up();
// void display_menu(int mask);
// int toggle_trap(int* mask);

int main(){
    int bitmask = 0;
    int trap_switch = 0;
    int exit = 0;

    starting_up();

    while (!exit) {
        display_menu(bitmask);
        exit = toggle_trap(&bitmask);
    }

    printf("GOODBYE\n");

    return 0;
}

// void starting_up(){
//     printf("Welcome to the Dungeon Manager.\n");
//     printf("Turn on traps to keep the Hero from getting the dungeon treasure\n");
//     printf("Or turn them off to let the Hero pass by more easily.\n\n");
// }

// void display_menu(int mask){
//     int trap_count = 1;
//     printf("Trap settings:\n");
//     printf("%d) Trap Doors:      %s\n",   trap_count++, mask & TRAP_DOORS    ? "READY" : "Safety locked");
//     printf("%d) Boulder Roller:  %s\n",   trap_count++, mask & BOULDER_ROLL  ? "READY" : "Safety locked");
//     printf("%d) Spike Traps:     %s\n",   trap_count++, mask & SPIKE_TRAPS   ? "READY" : "Safety locked");
//     printf("%d) Ceiling Crusher: %s\n",   trap_count++, mask & CEILING_CRUSH ? "READY" : "Safety Locked");
//     printf("%d) Log Knocker:     %s\n",   trap_count++, mask & LOG_SWING     ? "READY" : "Safety Locked");
//     printf("%d) Fire Traps:      %s\n",   trap_count++, mask & FLAMETHROWER  ? "READY" : "Safety Locked");
//     printf("%d) Net Snares:      %s\n",   trap_count++, mask & NET_SNARE     ? "READY" : "Safety Locked");
//     printf("%d) Boss Guardian:   %s\n",   trap_count++, mask & BOSS_BATTLE   ? "READY" : "Off Duty");
//     printf( "0) Quit Dungeon Manager\n");
// }

// int toggle_trap(int* mask){
//     int selection = 0;
//     int go = 0;
//     do {
//         printf("Input a number to toggle a trap: ");
//         scanf("%d", &selection);
//         if (0 > selection || selection > 8){
//             printf("Not a valid selection.\n");
//             printf("selection: %d\n", selection);
//         } else {
//             go = 1;
//         }
//     } while (!go);

//     if (!selection){
//         return 1;
//     } else {
//         *mask ^= (int)pow(2, (selection - 1));
//         return 0;
//     }
// }