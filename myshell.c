//
// Created by Andres Ortiz Osorio on 9/25/26.
//

#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>


typedef enum { TEST, PS, LS, EXIT, OTHER } CMD;
char *flags[] = { "-e", "-a" };

void prompt(char *input);
CMD encode(const char *s);

int main() {

    const char *SRC = "./cmake-build-debug/";   // Executables' location
    char input [256] = "";

    // CLI-loop
    while (1) {
        prompt(input);
        if (encode(input) == EXIT) break;

        const int pid = fork();
        if (pid == 0) {
            char copy [256];
            strcpy(copy, SRC);
            switch (encode(input)) {
                case TEST: { execv(strcat(copy, "test"), NULL); _exit(0); }
                case PS: { execv(strcat(copy, "ps"), NULL); _exit(0); }
                case LS: { execv(strcat(copy, "ls"), NULL); _exit(0); }
                default: { _exit(0); }
            }
        }

        waitpid(pid, NULL, 0);
        printf("\n");
    }

    return 0;
}

// Helper-functions

void prompt(char *input) {
    printf("%% ");
    fgets(input, 256, stdin);
}

CMD encode(const char *s) {
    if (strcmp(s, "exit\n") == 0) return EXIT;
    if (strcmp(s, "test\n") == 0) return TEST;
    return OTHER;
}
