#include <stdio.h>
#include <stdlib.h>

typedef struct lista{
	int num;
	struct lista* prox;
}lista;

typedef struct pilha{
	int quantidade;
	lista* topo;
}pilha;

pilha * cria(){
    pilha*p=(pilha*)malloc(sizeof(pilha));
    p->topo=NULL;
    return p;
}

void insere_pilha(pilha*p, int valor) {
	lista*v = (lista*) malloc (sizeof(lista));
	v->num = valor;
	v->prox = p->topo;
	p->topo = v;
	p->quantidade++;
}

int pilha_vazia(pilha* p){
	return p->topo == NULL;
}

void remover(pilha*p){
    if(pilha_vazia(p)){
        return;
    }
    lista*aux;
    aux=p->topo;
    p->topo=p->topo->prox;
    free(aux);
}

void imprime(pilha* p){
    lista* l;
    printf("\n");
    if (p == NULL || p->topo == NULL){
        printf("Lista vazia!");
        return;
    }
    for (l = p->topo; l != NULL; l = l->prox){
        printf("%d ", l->num);
    }
}

int main(){

	char v, v2 = 0;
	char cd;
    int var;

	pilha*p1=cria();
	pilha*p2=cria();

	while(v != '=' || v != '\n'){
        scanf("%c", &v);
        while(v == '0'){
            var=0;
        }var=1;
        int valor = v-48;
        if(var==1){
            printf("valor: %d      v: %c \n", valor, v);
        }
	}

	//scanf("%c", &v);
	//int valor = v-48;
	//printf("s   %d", valor);

    /*while(v != '='){
		scanf("%c", &v);
		int valor = v-48;
        while(valor==0){
            var=0;
        }var==1;
        if(var==1){
            printf("%d", valor);
        }
        if(v == '+'){
            printf("p2");
            p2 = (pilha*)malloc(sizeof(pilha));
            p2->topo = NULL;
            p2->quantidade = 0;
        }
    }*/

    return 0;
}
