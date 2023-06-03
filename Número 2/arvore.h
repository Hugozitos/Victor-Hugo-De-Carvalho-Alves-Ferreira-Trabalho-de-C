typedef struct No{
  int chave;
  struct No *esquerda, *direita;
}No;

typedef struct{
  No *raiz;
  int tam;
}Arvore_B;


No* inserir(No* raiz, int valor){
  if(raiz == NULL){
    No novo = (No)malloc (sizeof(No));
    novo -> chave = valor;
    novo -> esquerda = NULL;
    novo -> direita = NULL;
    
    return novo;
    
  }else{
    if(valor < raiz -> chave)
      raiz -> esquerda = inserir(raiz -> esquerda, valor);
      
    if(valor > raiz -> chave)
      raiz -> direita = inserir(raiz -> direita, valor);
      
    return raiz;
  }
}

No* remover(No *raiz, int item){
  if(raiz == NULL){
    printf("erro\n");
    return NULL;
  }else{
    if(raiz -> chave == item){
      if(raiz -> esquerda == NULL && raiz -> direita == NULL){
        
        free(raiz);
        return NULL;
        
      }
      else{
        if(raiz -> esquerda == NULL || raiz -> direita == NULL){
            No *temp;
            
          if(raiz -> esquerda != NULL){
            temp = raiz -> esquerda;
            free(raiz);
            return temp;
            
          }else{
            temp = raiz -> direita;
            free(raiz);
            return temp;
            
          }
          }else{
            No *temp = raiz -> esquerda;
          
            while(temp -> direita != NULL)
                temp = temp -> direita;
                
              raiz -> chave = temp -> chave;
              temp -> chave = item;
              raiz -> esquerda = remover(raiz -> esquerda, item);
          
          return raiz;
        }
      }
    }else{
        if(item < raiz -> chave){
            raiz -> esquerda = remover (raiz -> esquerda, item);
            return raiz;
        }else{
            raiz -> direita = remover(raiz -> direita, item);
            return raiz;
        }
    }
  }
}

void imprime(No *raiz){
  if(raiz != NULL){
    imprime(raiz -> esquerda);
    
    printf("%d ",raiz -> chave);
    
    imprime(raiz -> direita);
  }
}


No* input(No* raiz){
    int num;
  int tamanho;    
    
  printf("digite numero: ");
  scanf("%d", &num);
  
  raiz = inserir(raiz, num);
  
  return raiz;
}

void buscar(No* raiz, int valor) {
  if (raiz == NULL) {
    printf("erro\n");
    } else{
      
        if (raiz->chave == valor) {
        printf("valor encontrado\n");
        
        } else if (valor < raiz->chave) {
        buscar(raiz->esquerda, valor);
        
        }else {
        buscar(raiz->direita, valor);
        }
    }
}

void imprimirDireitaEsquerda(No* raiz){
   if(raiz != NULL){
    imprimirDireitaEsquerda(raiz -> direita);
    
    printf("%d ",raiz -> chave);
    
    imprimirDireitaEsquerda(raiz -> esquerda);
  }
    
}

int encontrarMaiorNumero(No* raiz) {
  if (raiz == NULL) {
    printf("arvore vazia\n");
    return 0;
  

        }else if (raiz->direita != NULL) {
          return encontrarMaiorNumero(raiz->direita);
          
        }else{
          printf("%d\n", raiz->chave);
          return raiz->chave;
    }
