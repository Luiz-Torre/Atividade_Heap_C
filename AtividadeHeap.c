#include <stdio.h>
#include <stdlib.h>
#include <math.h>


int TOTAL_ELEMENTOS;

void InsereElemento(int valor, int * vetor);
void ImprimeElemento(int * vetor);
int RemoveElemento (int * vetor);
void AjustarSubindo(int * vetor, int pos);
int indicePai(int x);
int indiceFilhoEsq(int x);
int indiceFilhoDir(int x);
void AjustarDescendo(int * vetor, int pos);

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
                removido = RemoveElemento(vetor);
                printf("O numero removido foi: %d", removido);
                break;

            case 3:
                ImprimeElemento(vetor);
                break;

            case 4:
                puts("Limpar o vetor aqui");
                free(vetor);
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

    AjustarSubindo(vetor, TOTAL_ELEMENTOS - 1);

}

void ImprimeElemento(int * vetor){
    printf("O vetor heap é: ");
    for(int i=0;i<TOTAL_ELEMENTOS;i++){
        printf("%d ", vetor[i]);
    }
}

int RemoveElemento(int * vetor){
    if(TOTAL_ELEMENTOS == 0) return -1;
    
    else{
        int aux = vetor[0];
        vetor[0] = vetor[--TOTAL_ELEMENTOS];
        vetor = (int*) realloc (vetor, TOTAL_ELEMENTOS * sizeof(int));
        AjustarDescendo(vetor,0);
        return aux;
    }


}

int indicePai(int x){
    int indice = (int)floor((x-1)/2);
    if(x<=0 || x>= TOTAL_ELEMENTOS) return -1;
    else return indice;
}

int indiceFilhoEsq(int x){
    int indice = (2*x) + 1;
    if(x>=TOTAL_ELEMENTOS || indice>= TOTAL_ELEMENTOS) return -1;
    else return indice;
}

int indiceFilhoDir(int x){
    int indice = (2*x) + 2;
    if(x>=TOTAL_ELEMENTOS || indice>= TOTAL_ELEMENTOS) return -1;
    else return indice;
}

void AjustarSubindo(int * vetor, int pos){

    if(pos!=-1){
        int pai= indicePai(pos);
        if(pai!= -1){
            if(vetor[pos]<vetor[pai]){
                int aux = vetor[pos];
                vetor[pos] = vetor[pai];
                vetor[pai] = aux;
                AjustarSubindo(vetor, pai);
            }
        }
    }
}

void AjustarDescendo(int * vetor, int pos){
    if(pos!= -1 && indiceFilhoEsq(pos) != -1){
        int indiceMaiorFilho = indiceFilhoEsq(pos);
        if(indiceFilhoDir(pos) != -1 && vetor[indiceFilhoDir(pos)]< vetor[indiceMaiorFilho])
            indiceMaiorFilho = indiceFilhoDir(pos);

        if(vetor[indiceMaiorFilho] < vetor[pos]){
            int aux = vetor[pos];
            vetor[pos] = vetor[indiceMaiorFilho];
            vetor[indiceMaiorFilho] = aux;
            AjustarDescendo(vetor, indiceMaiorFilho);
        }
    }
}
