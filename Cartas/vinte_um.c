#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int cards[21] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21};
    int temp, found;
    int i;
    // for(i=0;i<21;i++) cards[i] = 0;
    // i = 0;
    // while(i < 21)
    // {
        // found = 0;
        // srand(time(0));
        // temp = rand()%100 + 1;
        // for(int j=0;j<21;j++) if(cards[j] == temp) found = 1;
        // if(found == 0)
        // {
            // cards[i] = temp;
            // i++;
        // }
    // }

    int pilha1[7], pilha2[7], pilha3[7];
    int p1 = 0, p2 = 0, p3 = 0;
    for(i=0;i<21;i++)
    {
        if((i+1)%3 == 0)
        {
            pilha3[p3] = cards[i];
            p3++;
        }
        else if((i+2)%3 == 0)
        {
            pilha2[p2] = cards[i];
            p2++;
        }
        else
        {
            pilha1[p1] = cards[i];
            p1++;
        }
    }

    p1 = p2 = p3 = 0;
    for(i=0;i<21;i++)
    {
        if((i+1)%3 == 0)
        {
            if(pilha3[p3] > 9) printf("%d ", pilha3[p3]);
            else printf(" %d", pilha3[p3]);
            p3++;
        }
        else if((i+2)%3 == 0)
        {
            if(pilha2[p2] > 9) printf("%d ", pilha2[p2]);
            else printf(" %d", pilha2[p2]);
            p2++;
        }
        else
        {
            if(pilha1[p1] > 9) printf("%d ", pilha1[p1]);
            else printf(" %d", pilha1[p1]);
            p1++;
        }
        if(i != 0 && i%3 == 0) printf("\n");
    }

    return 0;
}