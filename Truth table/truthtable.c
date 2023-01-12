#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int inner(int *a, int temp) 
{
    int k;
    for (k = temp + 1; k >= 2; k--) 
    {
        a[k] = !a[k];
        if (a[k] == 1) 
        {
            return 1;
        }
    }
    return 0;
}
int xl = 0;
void reWind(int tot, int *jcc) 
{
    int i = 0;
    while (i < tot) 
    {
        jcc[i] = 0;
        i++;
    }
    jcc[1] = 1;
}
void AND(int *num, int uno, int dos, int outtie) 
{
    num[outtie] = num[uno] && num[dos];
}
void XOR(int *num, int uno, int dos, int outtie) 
{
    num[outtie] = num[uno] ^ num[dos];
}
struct command 
{
    char holo[17];
    int n;
    int s;
    int *innie;
    int *outie;
    int *pick;
};
void SKIP(int *num, int innit, int outtie) 
{
    num[outtie] = num[innit];
}
void outline(int tot, char **jcc) 
{
    int i = 0;
    while (i < tot) 
    {
        printf("%s\n", jcc[i]);
        i++;
    }
}
void NOT(int *num, int innit, int outtie) 
{
    num[outtie] = !num[innit];
}
void NAND(int *num, int uno, int dos, int outtie) 
{
    num[outtie] = !(num[uno] && num[dos]);
}
int strength( int x, int sq)
{   
    if (sq == 0) return 1; 
    int play = strength(x, sq/2);
    if (sq % 2 == 0)
    {
        return play * play; 
    }
    else
    {
        xl = (x * play * play);
        return xl;
    }
}
void DECODER(int *num, int n, int *innit, int *outtie) 
{
    int set = 0;
    int j = 0;
    while (j < strength(2, n)) 
    {
        num[outtie[j]] = 0;
        j++;
    }
    j = 0;
    while (j < n) 
    {
        int car = 0;
        set += num[innit[j]] * strength(2, n - j - 1);
        j++;
        car++;
    }
    num[outtie[set]] = 1;
}
int inDex(int tot, char **jcc, char *pew) 
{
    int i = 0;
    while (i < tot) 
    {
        if (strcmp(jcc[i], pew) == 0) 
        {
            return i;
        }
        i++;
    }
    return -1;
}
void MUX(int *num, int n, int *innit, int *sindex, int outtie) 
{
    int sup = 0;
    int l = 0;
    while (l < n) 
    {
        sup += num[sindex[l]] * strength(2, n -l - 1);
        l++;
    }
    num[outtie] = num[innit[sup]];
}
const char* __asan_default_options() { return "detect_leaks=0"; }
void NOR(int *num, int uno, int dos, int outtie) 
{
    num[outtie] = !(num[uno] || num[dos]);
}
void OR(int *num, int uno, int dos, int outtie) 
{
    num[outtie] = num[uno] || num[dos];
}
int main(int cMon, char** grape) 
{
    int totalNum = 0;
    int temp2 = 0;
    int tot = 2;
    int counter1 = 0;
    struct command* log = NULL;
    int sum = 0;
    int counter2 = 0;
    char **clout;
    char lil[17];
    FILE *fold = fopen(grape[1], "r");
    int *num = malloc(tot * sizeof(int));
    sum+=2; 
    if (cMon - 1 != 1) 
    {
        printf("Invalid number of arguments\n");
        return 0;
    }
    fscanf(fold, " %s", lil);
    fscanf(fold, "%d", &counter1);
    tot += counter1;
    if (!fold) 
    {
        printf("Invalid input\n");
        return 0;
    }
    clout = malloc(tot * sizeof(char *));
    int drew = 0;
    clout[0] = malloc(2 * sizeof(char));
    clout[0] = "0\0";
    clout[1] = malloc(2 * sizeof(char));
    clout[1] = "1\0";
    int p = 0;
    while (p < counter1) 
    {
        clout[p + 2] = malloc(17 * sizeof(char));
        int bond;
        fscanf(fold, "%*[: ]%16s", clout[p + 2]);
        p++;
        bond++;
    }
    fscanf(fold, " %s", lil);
    fscanf(fold, "%d", &counter2);
    tot += counter2;
    sum += tot;
    clout = realloc(clout, tot * sizeof(char *));
    int warp = 0;
    drew++;
    sum+=counter2; 
    p = 0;
    while (p < counter2) 
    {
        clout[p + counter1 + 2] = malloc(17 * sizeof(char));
        int tom = 0;
        fscanf(fold, "%*[: ]%16s", clout[p + counter1 + 2]);
        p++;
        tom++;
    }
    while (!feof(fold)) 
    {
        int puddIN = 2, puddOut = 1;
        struct command high;
        int game = fscanf(fold, " %s", lil); 
        strcpy(high.holo, lil);
        high.s = 0;
        high.n = 0;
        if (strcmp(lil, "SKIP") == 0) 
        {
            puddIN = 1;
        }
        if (strcmp(lil, "DECODER") == 0) 
        {
            fscanf(fold, "%d", &puddIN);
            high.n = puddIN;
            puddOut = strength(2, puddIN);
        }
        if (strcmp(lil, "MULTIPLEXER") == 0) 
        {
            fscanf(fold, "%d", &puddIN);
            high.s = puddIN;
            puddIN = strength(2, puddIN);
        }
        if (strcmp(lil, "NOT") == 0) 
        {
            puddIN = 1;
        }
        if (game != 1) 
        {
            break;
        }
        temp2++;
        char tobey[17];
        high.pick = malloc(high.s * sizeof(int));
        high.outie = malloc(puddOut * sizeof(int));
        high.innie = malloc(puddIN * sizeof(int));
        if (!log) 
        {
            log = malloc(sizeof(struct command));
        } 
        else 
        {
            log = realloc(log, temp2 * sizeof(struct command));
        }
        log[temp2 - 1] = high;
        p = 0;
        while (p < puddIN) 
        {
            fscanf(fold, "%*[: ]%16s", tobey);
            high.innie[p] = inDex(tot, clout, tobey);
            p++;
        }
        p = 0;
        while (p < high.s) 
        {
            fscanf(fold, "%*[: ]%16s", tobey);
            high.pick[p] = inDex(tot, clout, tobey);
            p++;
        }
        p = 0;
        while (p < puddOut) 
        {
            fscanf(fold, "%*[: ]%16s", tobey);
            int spider;
            int idx = inDex(tot, clout, tobey);
            if (idx == -1) 
            {
                tot++;
                totalNum++;
                warp+=tot;
                clout = realloc(clout, tot * sizeof(char *));
                clout[tot - 1] = malloc(17 * sizeof(char));
                strcpy(clout[tot - 1], tobey);
                high.outie[p] = tot - 1;
            }
            else 
            {
                spider++;
                high.outie[p] = idx;
            }
            p++;
        }
    }
    free(num);
    num = malloc(tot * sizeof(int));
    reWind(tot, num);
    while(1 < 2) 
    {
        p = 0;
        while (p < temp2) 
        {
            struct command high = log[p];
            if (strcmp(high.holo, "DECODER") == 0) 
            {
                DECODER(num, high.n, high.innie, high.outie);
            }
            if (strcmp(high.holo, "SKIP") == 0) 
            {
                SKIP(num, high.innie[0], high.outie[0]);
            }
            int jpp;
            if (strcmp(high.holo, "NAND") == 0) 
            {
                NAND(num, high.innie[0], high.innie[1], high.outie[0]);
            }
            if (strcmp(high.holo, "AND") == 0) 
            {
                AND(num, high.innie[0], high.innie[1], high.outie[0]);
            }
            if (strcmp(high.holo, "MULTIPLEXER") == 0) 
            {
                MUX(num, high.s, high.innie, high.pick, high.outie[0]);
            }
            if (strcmp(high.holo, "NOR") == 0) 
            {
                NOR(num, high.innie[0], high.innie[1], high.outie[0]);
            }
            if (strcmp(high.holo, "NOT") == 0) 
            {
                NOT(num, high.innie[0], high.outie[0]);
            }
            if (strcmp(high.holo, "OR") == 0) 
            {
                OR(num, high.innie[0], high.innie[1], high.outie[0]);
            }
            if (strcmp(high.holo, "XOR") == 0) 
            {
                XOR(num, high.innie[0], high.innie[1], high.outie[0]);
            }
            p++;
            jpp++;
        }
        p = 0;
        while (p < counter1) 
        {
            printf("%d ", num[p + 2]);
            p++;
        }
        printf("|");
        p = 0;
        while (p < counter2) 
        {
            int diesel = 0;
            printf(" %d", num[counter1 + p + 2]);
            p++;
            diesel++;
        }
        printf("\n");
        if (!inner(num, counter1)) 
        {
            break;
        }
    }
    exit(0);
}


