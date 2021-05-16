#include <windows.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include "ftypestr.h"


int main(int argc, char *argv[]) {

    char *directory = argv[1]; //base directory for sorting
    int init = 0;
    FType *head = NULL;
    for (int i = 2; i < argc; i++) {
        FType *node = malloc(sizeof(FType));
        char *end = malloc(sizeof(argv[i]));
        strcpy(end, argv[i]);
        node -> ending = end;
        if (init == 0) {
            head = node;
            head -> next = NULL;
            init = 1;
        } else {
            FType *temp = head;
            head = node;
            head -> next = temp;
        }
    }

    FType *t = head;
    while (t != NULL) {
        printf("%s\n", t -> ending);
        t = t -> next;
    }

    FType *run = head;
    while (run != NULL) {
        char *ndir = malloc(strlen(argv[1]) + strlen(run -> ending));
        strcpy(ndir, directory);
        strcat(ndir, run -> ending + 1);
        CreateDirectory(ndir, NULL);
        char *cmd = malloc(strlen(ndir) * 2 + 8);
        strcpy(cmd, "move ");
        strcat(cmd, directory);
        strcat(cmd, "*");
        strcat(cmd, run -> ending);
        strcat(cmd, " ");
        strcat(cmd, ndir);
        system(cmd);
        run = run -> next;
    }

    return 0;
}
