#include <stdio.h>
#include <stdbool.h>

#include "headers/menusH.h"

//Variables
bool inProgram = true;

int main() {

    do {
        InitialMenu();
    } while (inProgram);

    return 0;
}




