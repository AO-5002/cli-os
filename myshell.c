//
// Created by Andres Ortiz Osorio on 9/25/26.
//

#include <stdio.h>
#include <string.h>

static const char *commands[] = {"ps", "ls", "test", "exit" };

int main(int argc, char *argv[]) {
    // if (argc != 2) { fprintf(stderr, "Error: Invalid input!"); return -1; }
    const int SIZE = 256;
    char input [SIZE] = "";

    while (strcmp(input, "exit\n") != 0) {
        printf("%% ");
        fgets(input, SIZE, stdin);
    }

    return 0;
}
