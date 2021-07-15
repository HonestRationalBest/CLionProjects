#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>

const int longs = 80;
int main()
{
    pid_t pid_potomka, pid_wlasny, pid_rodzica;
    char komunikat[longs];
    char forSystem[longs];
    int powtorzen;
    int status;
    int *stat_loc = &pid_potomka;//7.6
    printf("Na razie działa jeden proces\n");
    pid_potomka = fork();
    pid_wlasny = getpid();
    pid_rodzica = getppid();
    switch (pid_potomka)
    {
        case -1:
            printf("rozwidlenie procesu nie powiodło się\n");
            exit(1);
        case 0:
            snprintf(komunikat, longs, "Jestem potomkiem, moj PID = %d, PID mojego rodzica = %d", pid_wlasny, pid_rodzica);
            powtorzen = 1;
            break;
        default:
            snprintf(komunikat, longs, "Jestem rodzicem, moj PID = %d, PID mojego rodzica = %d, PID potomka = %d", pid_wlasny, pid_rodzica, pid_potomka);
            powtorzen = 3;
            wait(stat_loc);//7.6
            break;
    }
    snprintf(forSystem, longs, "ps -ef | grep -E '%d|%d' | grep -vE 'grep|bash'", pid_wlasny, pid_rodzica);
    for (; powtorzen > 0; powtorzen--)
    {
        puts(komunikat);
        if(powtorzen == 1 && pid_potomka == 0)
        {
            printf("Potomek konczy dzialanie\n");
            system(forSystem);
            exit(2);
        }
        else if(powtorzen == 1 && pid_potomka != -1)
        {
            while (pid_potomka == 0)
            {
                printf("Rodziciel czeka na zakończenie procesu potomka\n");
                pid_potomka = waitpid(-1, &status, WNOHANG);
                sleep(1);
            }
        }
    }
    return 0;
}

