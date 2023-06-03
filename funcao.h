void bubble(int vetor[], int n) {
    int x, y;
    for (x = 0; x < n - 1; x++) {
        for (y = 0; y < n - x - 1; y++) {
            if (vetor[y] > vetor[y + 1]) {
                int temp = vetor[y];
                vetor[y] = vetor[y + 1];
                vetor[y + 1] = temp;
            }
        }
    }
}

void insert(int vetor[], int n) {
    int i, aux, j;
    for (i = 1; i < n; i++) {
        aux = vetor[i];
        j = i - 1;
        while (j >= 0 && vetor[j] > aux) {
            vetor[j + 1] = vetor[j];
            j = j - 1;
        }
        vetor[j + 1] = aux;
    }
}

void printVetor(int vetor[], int n) {
    int i;
    for (i = 0; i < n; i++) {
        printf("%d ", vetor[i]);
    }
    printf("\n");
}
