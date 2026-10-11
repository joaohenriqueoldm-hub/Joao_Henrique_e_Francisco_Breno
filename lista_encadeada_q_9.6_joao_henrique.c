#include <stdio.h>
#include <stdlib.h>

#define fmt "%d"
typedef int Item;
typedef struct no {
    Item item;
    struct no *prox;
} *Lista;

Lista no (Item x, Lista p) {
    Lista n = malloc(sizeof(struct no));
    n->item = x;
    n->prox = p;
    return n;
}

void percorrer(Lista L) {
	while (L!=NULL){
		printf("%d",L->item);
		L=L->prox;
    }
}

// x é o valor que vai ser substituído.
// y é o valor que será posto no lugar.
// L é a lista que será alterada.
// Lista pré-substituição: 2 1 2 1
int substituir(Item x, Item y, Lista L) {
    if (L == NULL) return 0;
    if (L->item == x) L->item = y;
    return substituir(x,y,L->prox);
}

int main() {
    Lista L = no(2,no(1,no(2,no(1,NULL))));
    int x = 1;
    int y = 2;

    printf("Lista antes da substituicao: ");
    percorrer(L);
    printf("\n");

    substituir(x,y,L);

    printf("Lista depois da substituicao: ");
    percorrer(L);
}
