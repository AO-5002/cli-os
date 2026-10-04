//
// Created by Andres Ortiz Osorio on 10/2/26.
//

#include <stdio.h>
#include <stdlib.h>
#include <libproc.h>


int main() {

    int count = proc_listallpids(NULL, 0);
    if (count <= 0) { perror("ps"); return 1; }

    pid_t *pids = malloc(sizeof(pid_t) * count);
    if (pids == NULL) { perror("ps"); return 1; }
    count = proc_listallpids(pids, (int) sizeof(pid_t) * count);

    printf("%7s  %s\n", "PID", "CMD");

    for (int i = 0; i < count; i++) {
        char name[256];
        if (proc_name(pids[i], name, sizeof(name)) <= 0) continue;
        printf("%7d  %s\n", pids[i], name);
    }

    free(pids);
    return 0;
}