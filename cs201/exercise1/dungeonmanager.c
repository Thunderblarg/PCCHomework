#include <stdio.h>
#include "dungeonhelper.h"

int main(){
    int bitmask = 0;
    int exit = 0;

    starting_up();

    while (!exit) {
        display_menu(bitmask);
        exit = toggle_trap(&bitmask);
    }

    printf("GOODBYE\n");

    return 0;
}