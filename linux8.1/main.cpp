#include <signal.h>
#include <stdio.h>
#include <unistd.h>
char napisy[3][80]={"Ha! Ha! Ha! To tylko sygnał powierzchowny!\n",
                    "Tylko proces %d śmieje się sygnałowi %d prosto w twarz!\n",
                    "Auć - to bolało!\n"};
        int nr_napisu=0;
        void obsluga_sig_int(int sig) {
            if(nr_napisu == 3)
            {
                printf("Dobrze! Dobrze! Już kończę.\n");
                _exit(1);
            }
            printf(napisy[nr_napisu],getpid(),sig);
            nr_napisu ++;
        }
        int main(int argc, char** argv) {
            signal(SIGINT,obsluga_sig_int);
            printf("Sygnały zablokowane.\n");
            sidset_t zestaw_blokowanych,ktore_wystapily;
            sigemptyset(&zestaw_blokowanych);
            sigaddset(&zestaw_blokowanych,SIGNIT);
            sigaddset(&zestaw_blokowanych,SIGQUIT);
            sigprocmask(SIG_BLOCK, &zestaw_blokowanych,NULL);
            int licznik=0;
            while (true) {
                printf("Cześć tu proces: %d\n",getpid());
                sleep(1);
                licznik++;
                if (licznik==15)
                {
                    sigpending(&które_wystapily);
                    if (sigismember(&ktore_wystapily,SIGINT))
                        printf(“Próbowałeś mnie wykończyć!\n);
                    if (sigismember(&ktore_wystapily,SIGQUIT))
                        printf(“Próbowałeś mnie opuścić!\n);
                    sigprocmask(SIG_UNBLOCK,&zestaw_blokowanych,NULL);
                    printf(„Sygnały odblokowane.\n”);
                }
            }
            return 0;
        }