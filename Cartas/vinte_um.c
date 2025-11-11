#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void distribui_pilhas(int cards[], int pilha1[], int pilha2[], int pilha3[]) {
    int p1 = 0, p2 = 0, p3 = 0;
    for(int i=0;i<21;i++)
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
}

void distribui_cartas(int pilha_esq[], int pilha_meio[], int pilha_dir[], int cards[]) {
    for(int i=0;i<21;i++)
    {
        if(i < 7)
        {
            cards[i] = pilha_esq[i];
        }
        else if(i >= 7 && i < 14)
        {
            cards[i] = pilha_meio[i-7];
        }
        else if(i >= 14 && i < 21)
        {
            cards[i] = pilha_dir[i-14];
        }
    }
}

void imprime_pilhas(int pilha1[], int pilha2[], int pilha3[]) {
    int p1 = 0, p2 = 0, p3 = 0;
    for(int i=0;i<21;i++)
    {
        if(i%3 == 0)
        {
            printf("| ");
        }
        if((i+1)%3 == 0)
        {
            if(pilha3[p3] > 9) printf("%d ", pilha3[p3]);
            else printf(" %d ", pilha3[p3]);
            p3++;
        }
        else if((i+2)%3 == 0)
        {
            if(pilha2[p2] > 9) printf("%d ", pilha2[p2]);
            else printf(" %d ", pilha2[p2]);
            p2++;
        }
        else
        {
            if(pilha1[p1] > 9) printf("%d ", pilha1[p1]);
            else printf(" %d ", pilha1[p1]);
            p1++;
        }
        printf("| ");
        if(i != 0 && (i+1)%3 == 0) printf("\n");
    }
}

int main() {
    int cards[21] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21};
    
    // DESCOMENTE O CÓDIGO A SEGUIR PARA NÚMEROS ALEATÓRIOS (AUMENTA O TEMPO DE EXECUÇÃO DO CÓDIGO)

    /*
    int temp, found;
    int i;
    for(i=0;i<21;i++) cards[i] = 0;
    i = 0;
    while(i < 21)
    {
        found = 0;
        srand(time(0));
        temp = rand()%100 + 1;
        for(int j=0;j<21;j++) if(cards[j] == temp) found = 1;
        if(found == 0)
        {
            cards[i] = temp;
            i++;
        }
    }
    */

    int pilha1[7], pilha2[7], pilha3[7];
    distribui_pilhas(cards, pilha1, pilha2, pilha3);

    int caso;
    for(int i=0;i<2;i++)
    {
        imprime_pilhas(pilha1, pilha2, pilha3);
        printf("Em que pilha, da esquerda para a direita, está a sua carta escolhida? (1-3): ");
        while(1)
        {
            scanf("%d", &caso);
            if(caso == 1 || caso == 2 || caso == 3) break;
            else printf("Valor inválido. Tente novamente: ");
        }
        if(caso == 1)
        {
            distribui_cartas(pilha2, pilha1, pilha3, cards);
        }
        else if(caso == 2)
        {
            distribui_cartas(pilha1, pilha2, pilha3, cards);
        }
        else
        {
            distribui_cartas(pilha1, pilha3, pilha2, cards);
        }
        distribui_pilhas(cards, pilha1, pilha2, pilha3);
    }
    
    imprime_pilhas(pilha1, pilha2, pilha3);
    printf("Em que pilha, da esquerda para a direita, está a sua carta escolhida? (1-3): ");
    while(1)
    {
        scanf("%d", &caso);
        if(caso == 1 || caso == 2 || caso == 3) break;
        else printf("Valor inválido. Tente novamente: ");
    }
    if(caso == 1)
    {
        printf("Sua carta é: %d\n", pilha1[3]);
    }
    else if(caso == 2)
    {
        printf("Sua carta é: %d\n", pilha2[3]);
    }
    else
    {
        printf("Sua carta é: %d\n", pilha3[3]);
    }
    return 0;
}