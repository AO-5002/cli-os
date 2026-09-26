//
// Created by Andres Ortiz Osorio on 9/25/26.
//

#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>


enum CMD { TEST, PD, LS, EXIT, OTHER };
enum CMD encode(const char *s);

int main() {
    char input [256] = "";
    while (1) {
        printf("%% ");
        fgets(input, 256, stdin);
        if (encode(input) == EXIT) break;

        const int pid = fork();
        if (pid == 0) {
            switch (encode(input)) {
                case TEST: { execv("./cmake-build-debug/test", NULL); _exit(0); }
                case PD: { execv("./cmake-build-debug/pd", NULL); _exit(0); }
                case LS: { execv("./cmake-build-debug/ls", NULL); _exit(0); }
                default: { _exit(0); }
            }
        }

        waitpid(pid, NULL, 0);
        printf("\n");
    }

    return 0;
}

enum CMD encode(const char *s) {
    if (strcmp(s, "exit\n") == 0) return EXIT;
    if (strcmp(s, "test\n") == 0) return TEST;
    return OTHER;
}
