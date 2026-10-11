
#include <stdio.h>
#include <stdlib.h>
#include "pilha.h"

int main() {
    Pilha A = pilha(100);
    Pilha B = pilha(100);

    int op = 0;
    int numero;

    while (op != 1) {
        printf("\nInserir um elemento?");
        printf("\n0 - Sim\n1 - Nao\n");
        scanf("%d", &op);

        if (op == 0) {
            printf("Insira o elemento: ");
            scanf("%d", &numero);

            Item_p elemento = malloc(sizeof(int));
            *elemento = numero;

            if (vaziap(A)) {
                empilha(elemento, A);
            }
            else {
                while (!vaziap(A) && *elemento > *topo(A)) {
                    empilha(desempilha(A), B);
                }

                empilha(elemento, A);

                while (!vaziap(B)) {
                    empilha(desempilha(B), A);
                }
            }
        }
    }

    printf("\nPilha ordenada:\n");

    while (!vaziap(A)) {
        Item_p p = desempilha(A);
        printf("%d\n", *p);
        free(p);
    }

    destroip(&A);
    destroip(&B);

    return 0;
}