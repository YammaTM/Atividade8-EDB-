#include <stdio.h>
#include <stdlib.h>

typedef struct no {
   int info;
   struct no *prox;
}Lista;

Lista *crialista() {
    return NULL;
}

Lista *insere(Lista *list, int valor)
{
    if(list == NULL || list->info > valor)
    {
        Lista *novo = (Lista*) malloc(sizeof(Lista));
        novo->info = valor;
        novo->prox = list;
        return novo;
    }
    else
    {
        list->prox = insere(list->prox,valor);
    }

}

void imprime (Lista *list) {
    Lista *p;
    for (p = list; p != NULL; p = p->prox) {
        printf("info = %d\n", p->info);
    }
}

int estavazia(Lista *list) {
    return (list == NULL);
}

Lista *busca(Lista *list, int valor)
{
    if(list == NULL)
    {
        return NULL;
    }
    else if(list->info == valor)
    {
        return list;
    }
    else
    {
        return busca(list->prox,valor);
    }
}

Lista *retira(Lista *lista, int v) {
        Lista *ant = NULL;
        Lista *p = lista;

        while (p != NULL && p->info != v) {
            ant = p;
            p = p->prox;
        }

        if (p==NULL) {
            return lista;
        }

        if (ant==NULL) {
                lista = p->prox;
        } else {
            ant->prox = p->prox;
        }
	free(p);
	return lista;
}

Lista* libera(Lista *lista)
{
    Lista *p = lista;
    while (p != NULL)
    {
        p = lista->prox;
        free(lista);
        lista = p;
    }
    return NULL;
}

int main() {
   //IMPLEMENTE AS FUNÇÕES ANTERIORES

   //EM SEGUIDA CRIE A LISTA E FAÇA AS SEGUINTES OPERAÇÕES
   //INSIRA 6 ELEMENTOS (88,71,23,12,29,1)
   //IMPRIMA A LISTA

   //BUSQUE PELO ELEMENTO 70
   //BUSQUE PELO ELEMENTO 29

   //REMOVA OS ELEMENTOS 12, 23, 1
   //IMPRIMA A LISTA

   //LIBERE A LISTA

   Lista *l = crialista();
   Lista *aux = crialista();
   l = insere(l,88);
   l = insere(l,71);
   l = insere(l,23);
   l = insere(l,12);
   l = insere(l,29);
   l = insere(l,1);
   imprime(l);
   system("pause");
   system("cls");


   printf("Pesquisando o Elemento 70\n");
   if(busca(l,70)!= NULL){
    printf("Valor encontrado!\n");
   }else{
   printf("Valor nao encontrado!\n");
   }
   system("pause");
   system("cls");

   printf("Pesquisando o Elemento 29\n");
   if(busca(l,29)!= NULL){
    printf("Valor encontrado!\n");
   }else{
   printf("Valor nao encontrado!\n");
   }
   system("pause");
   system("cls");

   l = retira(l,12);
   l = retira(l,23);
   l = retira(l,1);
   imprime(l);
   system("pause");
   system("cls");

   libera(l);
   system("pause");
   system("cls");


	return 0;
}
