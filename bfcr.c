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
}pessoaIn;

typedef struct Fila{
    int total;//total de elementos na lista
    struct pessoa *primeiro;//ponteiro para primeiro elemento
    struct pessoa *ultimo;//ponteiro para ultimo elemento
};

void addlista(struct Fila *lista, int add){
    struct pessoa *novo=(pessoaIn*)malloc(sizeof(struct pessoa)); //alocar espaço subsequente na memória
    novo->id=add;//adiciona valor de add para id de pessoa
    novo->proximo=NULL;//zera proximo ponteiro
    if(lista->primeiro==NULL){//ajusta valores para lista que antes não tinha itens
        lista->primeiro=novo;
        lista->ultimo=novo;
        return;
    }
    lista->ultimo->proximo=novo;//mudança de posições na lista
    lista->ultimo=novo;
    return;
}

void dellista(struct Fila *lista, int del){
    struct pessoa *ant = NULL, *aux;
    aux=lista->primeiro;//define aux para inicio de teste da fila
    while (aux!=NULL){//while roda até chegar no ponteiro que aponta para nulo
        if (aux->id==del){
            if (ant==NULL)//caso valor anterior seja nulo
                lista->primeiro=aux->proximo;//transfere valor proximo valor para começo
            else
                ant->proximo=aux->proximo;//se não anterior vai receber valor de proximo
            lista->total=(lista->total)-1;//reduz tamanho da lista
            return;
        }
        ant=aux;//dar seguimento ao while as duas funções fazem a lista caminhar
        aux=aux->proximo;
    }
    return;
}

int main(void) {
    struct Fila *fila;
    fila=malloc(sizeof(struct Fila));
    int n, n0=0, codigo, m = 0, m0=0; //n = quantidade de pessoas
    scanf("%d",&n); //receber quantidade de pessoas
    fila->total=n;//transferir total para lista
    while (n0<n){
        scanf("%d",&codigo);//receber codigo
        addlista(fila,codigo);//puchar função de adicionar valor na lista
        n0++;
    }
    scanf("%d",&m);
    while (m0<m){
        scanf ("%d",&codigo);//receber codigo
        dellista(fila,codigo);//puchar função de varrer lista e deletar codigo
        m0++;
    }
    int r=n-m;//definir número final de elementos na lista
    struct pessoa *print=fila->primeiro;//definir struct para printar pessoas
    while (r--){
        printf("%d ", print->id);//printar item atual
        print=print->proximo;//ir ao proximo item
    }
    printf("\n");
    
    return 0;
}
