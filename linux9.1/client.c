//7.19
//client.c
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#define BUF_SIZE 20484
int main(int argc, char** argv) {
    /* trying to run command */
    FILE *command_result = popen("./server", "r");
    if (command_result) {

        char bufor[BUF_SIZE];
        /* reading output line */
        fgets(bufor, BUF_SIZE, command_result);
        sleep(10);
        /* if "file" was not finished */
        while (!feof(command_result)) {
            printf("Serwer wysłał: %s", bufor);
            fgets(bufor, BUF_SIZE, command_result);
        }
        /* end of readiing results */
        pclose(command_result);
        fflush(stdout);
        return EXIT_SUCCESS;
    } else {
        printf("Niepowodzenie funkcji popen \n");
        fflush(stdout);
        return EXIT_FAILURE;
    }
}
