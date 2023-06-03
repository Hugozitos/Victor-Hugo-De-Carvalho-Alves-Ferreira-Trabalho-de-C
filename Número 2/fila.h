struct NodeF{
    int conteudo;
    struct NodeF *prox;
};
typedef struct NodeF fila_node;


int EMPTY(fila_node *FILA){
    if(FILA->prox == NULL){
        return 1;
    }else{
        return 0;
    }
}

fila_node* ENQUEUE(fila_node *FILA,int tam){
    fila_node novo=(fila_node)malloc(sizeof(fila_node));
    novo->prox = NULL;
    
    printf("novo item: ");
    scanf("%d",&novo->conteudo);
    
    if(EMPTY(FILA)){
        FILA->prox = novo;
    }
    else{
        fila_node *tmp = FILA ->prox;
        while(tmp->prox !=NULL){
            tmp = tmp->prox;
        }
        tmp->prox =novo;
    }
  tam++;
  return novo;
}

void DEQUEUE(fila_node *FILA,int tam){
    if(FILA->prox == NULL){
        printf("vazio\n");
        return;
    }else{
        fila_node *tmp = FILA->prox;
        FILA->prox = tmp->prox;
        tam--;
        free(tmp);
    }
  printf("item removido");
  
}

void IMPRIMEFILA(fila_node *FILA, int tam){
    if(EMPTY(FILA)){
        printf("\nvazio\n\n");
        return ;
    }
    fila_node *tmp = FILA -> prox;
    
    printf("\n fila: ");
    
    while (tmp != NULL){
        printf("%3d ",tmp -> conteudo);
        tmp = tmp ->prox;
        tam++;
    }
  printf("\n\n");
}

void IMPRIMEMAIOR(fila_node *FILA){
     if (EMPTY(FILA)) {
        printf("vazio\n");
        return;
    }else{
        
       int maior = INT_MIN;
        
        fila_node *tmp = FILA->prox;
        while (tmp != NULL) {
            if (tmp -> conteudo > maior) {
                maior = tmp -> conteudo;
            }
            tmp = tmp->prox;
        }
    
    printf("\n\nmaior elemento: %d\n", maior);
    }   
    
}

void IMPRIMEMENOR(fila_node *FILA){
     if (EMPTY(FILA)) {
        printf("vazio\n");
        return;
    }else{
        
       int menor = INT_MAX;
        
        fila_node *tmp = FILA->prox;
        while (tmp != NULL) {
            if (tmp -> conteudo < menor) {
                menor = tmp -> conteudo;
            }
            tmp = tmp->prox;
        }
    
    printf("\n\nmenor elemento: %d\n", menor);
    }   
    
}
void LIMPARFILA(fila_node *FILA){
    if(EMPTY(FILA)){
        
        printf("\nvazio \n\n");
        return ;
        
    }else{
        while(!EMPTY(FILA)){
            fila_node *ultimo = FILA -> prox;
            fila_node *penultimo = FILA;
            
            while(ultimo -> prox !=NULL){
                penultimo = ultimo;
                ultimo = ultimo -> prox;
            }
            free(ultimo);
            penultimo -> prox = NULL;
        }
        printf("\n\nfila limpa\n\n");
    }
}
