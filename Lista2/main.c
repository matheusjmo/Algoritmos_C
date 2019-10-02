#include <stdio.h>
#include <stdlib.h>

typedef struct pessoa{
	int ID;
	int age;
	struct pessoa * prox;
}pessoa;

typedef struct fila{
    pessoa * inicio;
    pessoa * fim;
}Fila;

pessoa * cria(){
    Fila * fila = (Fila*)malloc(sizeof(Fila));
    fila->inicio=NULL;
    fila->fim=NULL;
    return fila;
}

int filavazia(Fila*f){
    if (f == NULL){
        return 1;
    }
    return (f->inicio == NULL);
}


void insere(int identidade, int idade, Fila*f){
    pessoa* no = (pessoa*)malloc(sizeof(pessoa));
    no->ID=identidade;
    no->age=idade;
    no->prox=NULL;

    if(filavazia(f)){
        f->inicio=no;
    }
    else{
        f->fim->prox=no;
    }
    f->fim=no;
}

void Remove(Fila*f){
    pessoa*aux;
    if(filavazia(f)){
        return;
    }
    aux = f->inicio;
    f->inicio = aux->prox;
    if(f->inicio == NULL){
        f->fim = NULL;
    }
    free(aux);
}

void imprime(Fila*f){
    pessoa*aux;
    if(filavazia(f)){
        printf("fila vazia!\n");
    }
    else{
        //printf("\n");
        for(aux=f->inicio; aux!=NULL; aux=aux->prox){
            printf("ID: %d IDADE: %d\n", aux->ID, aux->age);
        }
    }
}

int main() {

	int n, cont=0;
    char cd;

	pessoa* f1 = cria();
	pessoa* f2 = cria();

	scanf("%d", &n);
	while(cd!='f'){
		scanf("%c", &cd);
		if(cd =='r'){
            if(cont != n && !(filavazia(f1))){
                Remove(f1);
                cont++;
            }
            else {
                printf("entrei");
                Remove(f2);
                cont = 0;
            }
		}
		if(cd =='i'){
            printf("fila de idosos:\n");
            imprime(f1);
            printf("fila de nao-idosos:\n");
            imprime(f2);
            printf("----------");
            printf("\n");

		}
		if(cd =='a'){
			int identidade, idade;
			scanf("%d %d", &identidade, &idade);
			if(idade>60){
                insere(identidade, idade, f1);
			}
			else{
                insere(identidade, idade, f2);
			}
		}
	}

	return 0;
}
