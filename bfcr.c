//
//  main.c
//  30 aug Hazin
//
//  Created by Bernardo Russo on 30/08/18.
//  Copyright © 2018 Bernardo Russo. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>

typedef struct pessoa{
    int id; // id = mnumero identificador de pessoa
    struct pessoa *proximo; //ponteiro para o proximo elemento
}pessoaIn, pessoaOut;

typedef struct Fila{
    int total;
    struct pessoa *primeiro;
    struct pessoa *ultimo;
};

void addlista(struct Fila *lista, int add){
    pessoaIn *novo=(pessoaIn*)malloc(sizeof(struct pessoa)); //alocar espaço subsequente na memória
    novo->id=add;
    novo->proximo=NULL;
    if(lista->primeiro==NULL){
        lista->primeiro=novo;
        lista->ultimo=novo;
        return;
    }
    lista->ultimo->proximo=novo;
    lista->ultimo=novo;
    return;
}

void dellista(struct Fila *lista, int del){
    struct pessoa *ant = NULL, *aux;
    aux=lista->ultimo;
    while (aux!=NULL){
        if (aux->id==del){
            if (ant==NULL)
                lista->ultimo=aux->proximo;
            else
                ant->proximo=aux->proximo;
            lista->total=lista->total-1;
            return;
        }
    }
}

int main(void) {
    struct Fila *fila;
    fila=malloc(sizeof(struct Fila));
    
    int n, n0=0, codigo, m = 0, m0=0; //n = quantidade de pessoas
    scanf("%d",&n); //receber quantidade de pessoas
    while (n0<n){
        scanf("%d",&codigo);
        addlista(fila,codigo);
        n0++;
    }
    scanf("%d",m);
    while (m0<0){
        scanf ("%d",&codigo);
        dellista(fila,codigo);
        m0++;
    }
    struct pessoa *print=fila->primeiro;
    while (m0--){
        printf("%d ", print->id);
        print=print->proximo;
    }
    printf("\n");
    
    return 0;
}
