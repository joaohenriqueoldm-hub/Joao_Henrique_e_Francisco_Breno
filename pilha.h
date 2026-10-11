#include <stdlib.h>
#include <stdio.h>

typedef int *Item_p;

typedef struct pilha {
    int max;
    int topo;
    Item_p *item;
} *Pilha;

Pilha pilha(int m) {
    Pilha P = malloc(sizeof(struct pilha));
    P->max = m;
    P->topo = -1;
    P->item = malloc(m*sizeof(Item_p));
    return P;
}

int vaziap(Pilha P) {
    if (P->topo == -1) return 1;
    return 0;
}

int cheiap(Pilha P) {
    if (P->topo == P->max -1) return 1;
    return 0;
}

void empilha(Item_p x, Pilha P) {
    if (cheiap(P)) {puts("Pilha cheia"); abort();}
    P->topo++;
    P->item[P->topo] = x;
}

Item_p desempilha(Pilha P) {
    if (vaziap(P)) {puts("Pilha vazia"); abort();}
    Item_p x = P->item[P->topo];
    P->topo--;
    return x;
}

Item_p topo(Pilha P) {
    if (vaziap(P)) {puts("Pilha vazia"); abort();}
    return P->item[P->topo];
}

void destroip(Pilha *P) {
    free((*P)->item);
    free(*P);
    *P = NULL;
}
