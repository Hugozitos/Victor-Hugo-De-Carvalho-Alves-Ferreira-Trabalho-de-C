#include <limits.h>
#include <stdlib.h>
#include <stdio.h>

#include "pilha.h"
#include "fila.h"
#include "arvore.h"

int main()
{
    int altr,Pnum,Fnum,Anum;
    int removerElemento,buscarElemento,maior_num;
    
    node_pilha PILHA = (node_pilha)malloc(sizeof(node_pilha));
    PILHA -> prox = NULL;
    int tam=0;

    fila_node FILA = (fila_node)malloc(sizeof(fila_node));
    FILA ->prox = NULL; 

     Arvore_B arvore;
    arvore.raiz = NULL;
    No *raiz = NULL;
  
    do{
    printf("escolha\n");
    printf("1 Pilha\n");
    printf("2 Fila\n");
    printf("3 Arvore\n");
    scanf("%d",&altr);
  
    switch(altr){
        case 1:
        do{
        
            printf("\nescolha: ");
            printf("\n1 empilhar\n");
            printf("2 desempilhar\n");
            printf("3 imprimir topo\n");
            printf("4 imprimir\n");
            printf("5 limpar\n");
            scanf("%d",&Pnum);
        
          switch(Pnum){
                case 1:
                PUSH(PILHA,tam);
                break;
                
                case 2:
                POP(PILHA,tam);
                break;
                
                case 3:
                TOPOPILHA(PILHA);
                break;
                
                case 4:
                IMPRIME(PILHA,tam);
                break;

                case 5:
                LIMPARPILHA(PILHA);
                break;
            }
        }while(Pnum != 0);
        break;
      
        case 2:

      do{
        
            printf("\nescolha: ");
            printf("\n1 enfileirar\n");
            printf("2 desenfileirar\n");
            printf("3 imprimir maior\n");
            printf("4 imprimir menor\n");
            printf("5 imprimir tudo\n");
            printf("6 limpar\n");
            scanf("%d",&Fnum);
        
            
            switch(Fnum){
                case 1:
                ENQUEUE(FILA,tam);
                break;
                
                case 2:
                DEQUEUE(FILA,tam);
                break;
                
                case 3:
                IMPRIMEMAIOR(FILA);
                break;
                
                case 4:
                IMPRIMEMENOR(FILA);
                break;

                case 5:
                IMPRIMEFILA(FILA,tam);
                break;
                
                case 6:
                LIMPARFILA(FILA);
                break;
            }
        }while(Fnum != 0);
        break;
      
        case 3:

      do{
            printf("\nescolha: ");
            printf("\n1 inserir\n");
            printf("2 imprima a arvore\n");
            printf("3 imprima a arvore da direita para esquerda\n");
            printf("4 imprimir maior elemento\n");
            printf("5 buscar \n");
            printf("6 deletar \n");
            scanf("%d",&Anum);
        
            
            switch(Anum){
                case 1:
                raiz = input(raiz);
                break;
                
                case 2:
                  printf("\narvore: ");
                imprime(raiz);
                printf("\n");
                break;
                
                case 3:
                  printf("\n\narvore da direita para esquerda: ");  
                imprimirDireitaEsquerda(raiz);
                printf("\n");
                break;
                
                case 4:
                maior_num = encontrarMaiorNumero(raiz);
                printf("\n");
                break;

                case 5:
                  printf("digite a busca: ");
                  scanf("%d", &buscarElemento);
                buscar(raiz, buscarElemento);
                printf("\n");
                break;
                
                case 6:
                  printf("\n\ndigite o valor pra remover: ");
                  scanf("%d", &removerElemento);
                raiz = remover(raiz, removerElemento);
                break;
            }
        }while(Anum != 0);
        
        default:
        break;
    }
  }while(altr != 0);
  printf("tudo certo");
  return 0;
}
