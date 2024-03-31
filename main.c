#include <stdio.h>
#include <stdlib.h>

int pesquisa_binaria(int lista[], int tamanho, int item );

int main (){
    int vetor[] = {1,2,3,4,5,6};//matriz unidimensional ordenada.
    int escolha;// var de entrada
    int resultado;// var de recebimento

    printf("digite um numero: (entre 1 a 6): ");
    scanf("%d", &escolha);// escolha do usuario

    resultado = pesquisa_binaria(vetor, sizeof(vetor)/sizeof(vetor[0]), escolha);// atribuição a var resultado apos chamada da funcao, passando vetor, o tamanho do vetor e a escolha do usario como paramentros (sizeofpega os 24bytes e divide por 4).

    //situacao caso a escolha for encontrada ou nao.
    if (resultado != -1){
        printf("\nO item foi encontrado na posicao %d, o item foi %d\n", resultado, escolha);
    }else{
        printf("O item nao foi encontrado\n");
    }
    return 0;
}

int pesquisa_binaria(int lista[], int tamanho, int item){

    int baixo = 0;//inicializando baixo com 0
    int alto = tamanho - 1;//inicializando alto com o tamanho total do vetor -1
    int meio;//var para cortar o vetor ao meio para facil busca
    int chute;//var que recebe o valor do indice indicado pela var meio
    while (baixo <= alto){
        meio = (alto+baixo)/2;//cortando o vetor pela metade
        chute = lista[meio];//chute recebe o valor que esta na posicao [meio] do vetor lista
        if (chute == item){
            return meio;// retorna o valor se for encontrado
        }
        if (chute > item){
            alto = meio - 1;// se for maior o alto diminiu
        }
        else{
            baixo = meio + 1;// se for menor baixo aumenta
        }
    }
    return -1;// se nao encontra nada retorna -1
}