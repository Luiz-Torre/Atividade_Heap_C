#include <stdio.h>
#include <stdlib.h>
#include <math.h>


int TOTAL_ELEMENTOS;

void InsereElemento(int valor, int * vetor);
void ImprimeElemento(int * vetor);
int main(){
    TOTAL_ELEMENTOS = 0;
    int *vetor;
    vetor = (int * ) malloc(1*sizeof(int));
    int removido = 0, num, valor;
    printf("Digite 1, 2, 3 ou 4 :\n1- Inserir um elemento na heap\n2- Remover um elemento\n3- Imprimir a Heap\n4- Sair:\n");
    scanf("%d", &num);

    while(num !=4){

        switch (num)
        {
            case 1:
                puts("Informe o elemento que deseja inserir");
                scanf("%d", &valor);
                InsereElemento(valor,vetor);

                break;
            case 2:
                printf("O numero removido foi: %d", removido);
                break;

            case 3:
                ImprimeElemento(vetor);
                break;

            case 4:
                puts("Limpar o vetor aqui");
                exit(0);
                break;
            default:
                puts("\nNúmero invalido.");
                break;
        }
        printf("\nDigite 1, 2, 3 ou 4 :\n1- Inserir um elemento na heap\n2- Remover um elemento\n3- Imprimir a Heap\n4- Sair\n");
        scanf("%d", &num);
    }
}



void InsereElemento(int valor, int * vetor){
    if(TOTAL_ELEMENTOS == 0){
        vetor[TOTAL_ELEMENTOS] = valor;
    }
    else{
        vetor = (int*) realloc (vetor, (TOTAL_ELEMENTOS +1) * sizeof(int));
        vetor[TOTAL_ELEMENTOS] = valor;
    }
    TOTAL_ELEMENTOS++;

}

void ImprimeElemento(int * vetor){
    printf("O vetor heap é: ");
    for(int i=0;i<TOTAL_ELEMENTOS;i++){
        printf("%d ", vetor[i]);
    }
}