#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#define BUF_SIZE 20484
int main(int argc, char** argv) {
    /* trying to run command */
    int p[2];
    pipe(p);
    if (pipe(potoki_plikowe) == 0) {
        rezultat_fork = fork();
        if (rezultat_fork == -1) {
            fprintf(stderr, "Fork failure");
            exit(EXIT_FAILURE); }
// fork zadzialal, wiec rezultat_fork = 0 , jestesmy w procesie potomnym.
        if (rezultat_fork == 0) {
            przetworzone_dane = read(potoki_plikowe[0], buffer, BUFSIZ);
            printf("Odczytano %d bajtow: %s\n", przetworzone_dane, buffer);
            exit(EXIT_SUCCESS); }
// W przeciwnym przypadku jesteśmy w procesie macierzystym.
        else { przetworzone_dane = write(potoki_plikowe[1], jakies_dane, strlen(jakies_dane));
            printf("Zapisano %d bajtow\n", przetworzone_dane); }
    }
}
