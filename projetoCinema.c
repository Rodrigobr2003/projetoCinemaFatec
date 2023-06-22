#include <stdio.h>
#include <stdlib.h>

int main() {
    int COLUNAS = 30, FILEIRAS = 20, assentos[FILEIRAS][COLUNAS], coluna, fileira;
    int comprarNovamente, tipoIngresso, contInt = 0, contMei = 0, contCor = 0, valorInt = 30, valorMei = 15, valorCor = 0;
    int c = 0, f = 0;

    for (c = 0; c < FILEIRAS; c++) {
        for (f = 0; f < COLUNAS; f++) {
            assentos[c][f] = 0;
        }
    }

    do {
        coluna = 0;
        fileira = 0;
        system("cls");

        printf("-------------------\n");
        printf("      CINEMA\n");
        printf("-------------------\n");

        printf("\nAssentos disponiveis: \n");

        printf("\nAssentos 0 - desocupados");
        printf("\nAssentos 1 - ocupados\n\n");

        for (c = 0; c < FILEIRAS; c++) {
            for (f = 0; f < COLUNAS; f++) {
                printf("  %d", assentos[c][f]);
            }
            printf("\n");
        }

        do {
            if (assentos[fileira - 1][coluna - 1] == 1) {
                printf("\nEsse assento ja foi escolhido, insira outro...");
            }

            printf("\nEscolha seu lugar!");

            printf("\nEscolha sua fileira: ");
            scanf("%i", &fileira);

            printf("\nEscolha sua coluna: ");
            scanf("%i", &coluna);
        } while (assentos[fileira - 1][coluna - 1] == 1);

        printf("\nQual o tipo de ingresso?");
        printf("\n 1 - Inteira");
        printf("\n 2 - Meia");
        printf("\n 3 - Cortesia\n");
        scanf("%i", &tipoIngresso);

        if (tipoIngresso == 1)
            contInt += 1;
        if (tipoIngresso == 2)
            contMei += 1;
        if (tipoIngresso == 3)
            contCor += 1;

        assentos[fileira - 1][coluna - 1] = 1;

        printf("\nDeseja comprar novamente?");
        printf("\n 1 - Sim");
        printf("\n 2 - Nao\n");
        scanf("%i", &comprarNovamente);

        for (c = 0; c < FILEIRAS; c++) {
            for (f = 0; f < COLUNAS; f++) {
                printf("  %d", assentos[c][f]);
            }
            printf("\n");
        }

    } while (comprarNovamente == 1);

    printf("\nEste eh o total de ingressos inteiros: %i", contInt);
    printf("\nEste eh o total de ingressos meia: %i", contMei);
    printf("\nEste eh o total de ingressos cortesia: %i", contCor);

    int valorFinal = 0;

    valorFinal = (contInt * valorInt) + (contMei * valorMei);
    printf("\nValor a pagar: %i", valorFinal);

    return 0;
}

