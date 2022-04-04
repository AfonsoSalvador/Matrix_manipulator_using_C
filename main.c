#include <stdio.h>
#include "minha_matriz.h"

int main () {
    MinhaMatriz_pt ptMat1 = NULL, ptMat2 = NULL, ptMat3 = NULL, ptMat4 = NULL, ptMat5 = NULL, ptMat6 = NULL, ptMat7 = NULL, ptRes= NULL;

    //Criação de matrizes para demonstração
    
    unsigned int tamMat1[2] = {3,3};
    double valMat1[9] = {5,2,1,3,4,2,5,8,2};
    ptMat1= Matriz_Constroi(ptMat1,tamMat1,valMat1);
    
    unsigned int tamMat3[2]= {3,3};
    double valMat3[9] = {1,3,1,2,1,3,4,5,1};
    ptMat3=Matriz_Constroi(ptMat3,tamMat3,valMat3);

    unsigned int tamMat4[2] = {4,2};
    double valMat4[8] = {4,2,1,6,5,4,3,7};
    ptMat4= Matriz_Constroi(ptMat4,tamMat4,valMat4);

    unsigned int tamMat5[2] = {2,2};
    double valMat5[4] = {1, 2, 3, 4};
    ptMat5= Matriz_Constroi(ptMat5,tamMat5,valMat5);

    unsigned int tamMat6[2] = {3,3};
    double valMat6[9] = {2, 4, 6, 8, 10, 12, 14, 16, 18};
    ptMat6= Matriz_Constroi(ptMat6,tamMat6,valMat6);

    unsigned int tamMat7[2] = {3,3};
    double valMat7[9] = {1, 24, 3, 0, 8, 1, 0, 4, 0};
    ptMat7= Matriz_Constroi(ptMat7,tamMat7,valMat7);

    unsigned int tamMatRes[2] = {3,3};
    double valMatRes[9] = {0,0,0,0,0,0,0,0,0};
    ptRes= Matriz_Constroi(ptRes,tamMatRes,valMatRes);



    //demonstração de Funções Básicas

    // Função de impressão, e demonstração de valores iniciais de M1 e M2
    printf("Imprimindo M1\nM1 = \n");
    ptMat1->Metodo->imprime(ptMat1);

    //Função de cópia, copiar os valores de M1 e passar para M2
    printf("Copiando os valores internos de M1 e passando para M2\n");
    ptMat2= ptMat1->Metodo->copia(ptMat1);

    printf("Imprimindo M2\nM2 = \n");
    ptMat2->Metodo->imprime(ptMat2);

    //Função de atribuir, pega os valores de M3 e atribui em M2

    printf("Imprimindo M3\nM3 = \n");
    ptMat3->Metodo->imprime(ptMat3);

    printf("Imprimindo M2\nM2 = \n");
    ptMat2->Metodo->imprime(ptMat2);

    printf("Atribuindo os valores de M3 a M2\n");
    ptMat2= ptMat3->Metodo->atribui(ptMat3,ptMat2);

    printf("Imprimindo M2\nM2 = \n");
    ptMat2->Metodo->imprime(ptMat2);

    //Função de soma, soma os elementos de uma matriz com seus respectivos de outra

    printf("Imprimindo M1\nM1 = \n");
    ptMat1->Metodo->imprime(ptMat1);

    printf("Imprimindo M2\nM2 = \n");
    ptMat2->Metodo->imprime(ptMat2);


    printf("Somando M1 com M2 e colocando o valor em MR\n");
    ptRes= ptRes->Metodo->soma(ptMat1,ptMat2,ptRes);

    printf("Imprimindo MR\nMR = \n");
    ptRes->Metodo->imprime(ptRes);

    //Função de subtração, subtrai os elementos de uma matriz com seus respectivos de outra

    printf("Imprimindo M3\nM3 = \n");
    ptMat3->Metodo->imprime(ptMat3);

    printf("Imprimindo M2\nM2 = \n");
    ptMat2->Metodo->imprime(ptMat2);

    printf("Subtraindo M3 com M2 e colocando o valor em MR\n");
    ptRes= ptRes->Metodo->subt(ptMat3,ptMat2,ptRes);

    printf("Imprimindo MR\nMR = \n");
    ptRes->Metodo->imprime(ptRes);

    //Função de Multiplicação, multiplica os elementos de uma matriz com seus respectivos de outra

    printf("Imprimindo M1\nM1 = \n");
    ptMat1->Metodo->imprime(ptMat1);

    printf("Imprimindo M2\nM2 = \n");
    ptMat2->Metodo->imprime(ptMat2);

    printf("Multiplicando M1 com M2 e colocando o valor em MR\n");
    ptRes=ptRes->Metodo->mult(ptMat1,ptMat2,ptRes);

    printf("Imprimindo MR\nMR = \n");
    ptRes->Metodo->imprime(ptRes);

    //Função de Divisão, divide os elementos de uma matriz com seus respectivos de outra

    printf("Imprimindo M1\nM1 = \n");
    ptMat1->Metodo->imprime(ptMat1);

    printf("Imprimindo M2\nM2 = \n");
    ptMat2->Metodo->imprime(ptMat2);

    printf("Dividindo M1 por M2 e colocando o valor em MR\n");
    ptRes=ptRes->Metodo->divd(ptMat1,ptMat2,ptRes);

    printf("Imprimindo MR\nMR = \n");
    ptRes->Metodo->imprime(ptRes);

    //Função de Soma Acumulada, soma os elementos de uma matriz com a de outra, mantendo seus novos valores na primeira

    printf("Imprimindo M1\nM1 = \n");
    ptMat1->Metodo->imprime(ptMat1);

    printf("Imprimindo M2\nM2 = \n");
    ptMat2->Metodo->imprime(ptMat2);

    printf("Somando M1 com M2 mantendo em M1\n");
    ptMat1=ptMat1->Metodo->ac_soma(ptMat1,ptMat2);

    printf("Imprimindo M1\nM1 = \n");
    ptMat1->Metodo->imprime(ptMat1);

    //Função de Subtração Acumulada, subtrai os elementos de uma matriz com a outra, mantendo seus novos valores na primeira

    printf("Imprimindo M1\nM1 = \n");
    ptMat1->Metodo->imprime(ptMat1);

    printf("Imprimindo M2\nM2 = \n");
    ptMat2->Metodo->imprime(ptMat2);

    printf("Subtraindo M1 com M2 mantendo em M1\n");
    ptMat1=ptMat1->Metodo->ac_subt(ptMat1,ptMat2);

    printf("Imprimindo M1\nM1 = \n");
    ptMat1->Metodo->imprime(ptMat1);
    

    //Função de Multiplicação Acumulada, multiplica os elementos de uma matriz com a outra, mantendo seus novos valores na primeira

    printf("Imprimindo M1\nM1 = \n");
    ptMat1->Metodo->imprime(ptMat1);

    printf("Imprimindo M2\nM2 = \n");
    ptMat2->Metodo->imprime(ptMat2);

    printf("Multiplicando M1 com M2 mantendo em M1\n");
    ptMat1=ptMat1->Metodo->ac_mult(ptMat1,ptMat2);

    printf("Imprimindo M1\nM1 = \n");
    ptMat1->Metodo->imprime(ptMat1);

    //Função de Divisão Acumulada, divide os elementos de uma matriz com a outra, mantendo seus novos valores na primeira

    printf("Imprimindo M1\nM1 = \n");
    ptMat1->Metodo->imprime(ptMat1);

    printf("Imprimindo M2\nM2 = \n");
    ptMat2->Metodo->imprime(ptMat2);

    printf("Dividindo M1 com M2 mantendo em M1\n");
    ptMat1=ptMat1->Metodo->ac_divd(ptMat1,ptMat2);

    printf("Imprimindo M1\nM1 = \n");
    ptMat1->Metodo->imprime(ptMat1);


    //Função de Comparação, pega duas matrizes e diz se elas são iguais ou diferentes


    printf("Imprimindo M1\nM1 = \n");
    ptMat1->Metodo->imprime(ptMat1);

    printf("Imprimindo M2\nM2 = \n");
    ptMat2->Metodo->imprime(ptMat2);

    printf("Imprimindo M3\nM3 = \n");
    ptMat3->Metodo->imprime(ptMat3);

    printf("Comparando M1 com M2\n");
    
    if(ptMat1->Metodo->compara(ptMat1,ptMat2)){
        printf("As duas matrizes sao iguais!\n\n");
    }
    else{ 
        printf("As duas matrizes sao diferentes!\n\n");
    }
    

    printf("Comparando M2 com M3\n");

    if(ptMat2->Metodo->compara(ptMat2,ptMat3)){
        printf("As duas matrizes sao iguais!\n\n");
    }
    else{
        printf("As duas matrizes sao diferentes!\n\n");
    }

    
    /*----------------------FUNÇÕES ADICIONAIS-------------------------*/

    //Função de Redimensionamento

    printf("Redimensionando matriz 3x3 para 4x4\n");

    unsigned int tamMatnovo[2] = {4,4};
    ptMat1=ptMat1->Metodo->resize(ptMat1,tamMatnovo);

    printf("Imprimindo M1\nM1 = \n");
    ptMat1->Metodo->imprime(ptMat1);


    //Função de Matriz preenchida em 1s

    printf("Criando matriz preenchida na 1\n");

    ptMat1=ptMat1->Metodo->ones(ptMat1);

    printf("Imprimindo M1\nM1 = \n");
    ptMat1->Metodo->imprime(ptMat1);


    //Função de Matriz adicionar linha

    printf("Adicionando uma linha na matriz M1\n");
    ptMat1=ptMat1->Metodo->add_linha(ptMat1);

    printf("Imprimindo M1\nM1 = \n");
    ptMat1->Metodo->imprime(ptMat1);


    //Função de Matriz adicionar coluna

    printf("Adicionando uma coluna na matriz M1\n");
    ptMat1=ptMat1->Metodo->add_coluna(ptMat1);

    printf("Imprimindo M1\nM1 = \n");
    ptMat1->Metodo->imprime(ptMat1);


    //Função de criar matriz identidade

    printf("Criando matriz identidade com a matriz M1\n");
    ptMat1=ptMat1->Metodo->identidade(ptMat1);

    printf("Imprimindo M1\nM1 = \n");
    ptMat1->Metodo->imprime(ptMat1);


    //Função de transpor uma matriz

    printf("Imprimindo M2\nM2 = \n");
    ptMat2->Metodo->imprime(ptMat2);

    printf("Transpondo a M2\n");
    ptMat2=ptMat2->Metodo->transposta(ptMat2);

    printf("Imprimindo M2\nM2 = \n");
    ptMat2->Metodo->imprime(ptMat2);


    //Função de Multiplicar por escalar

    printf("Imprimindo M2\nM2 = \n");
    ptMat2->Metodo->imprime(ptMat2);

    printf("Multiplicando pelo escalar 4\n");
    ptMat2=ptMat2->Metodo->escalar_mult(ptMat2,4.0);

    printf("Imprimindo M2\nM2 = \n");
    ptMat2->Metodo->imprime(ptMat2);


    //Função de reverter linhas

    printf("Imprimindo M1\nM1 = \n");
    ptMat1->Metodo->imprime(ptMat1);

    printf("Revertendo a linha da M1\n");
    ptMat1=ptMat1->Metodo->reverter_linhas(ptMat1);

    printf("Imprimindo M1\nM1 = \n");
    ptMat1->Metodo->imprime(ptMat1);


    //Função de reverter colunas

    printf("Imprimindo M1\nM1 = \n");
    ptMat1->Metodo->imprime(ptMat1);

    printf("Revertendo a coluna da M1\n");
    ptMat1=ptMat1->Metodo->reverter_colunas(ptMat1);

    printf("Imprimindo M1\nM1 = \n");
    ptMat1->Metodo->imprime(ptMat1);


    //Função de ordenar crescente

    printf("Imprimindo M1\nM1 = \n");
    ptMat1->Metodo->imprime(ptMat1);

    printf("Ordenando a matriz por ordem crescente\n");
    ptMat1=ptMat1->Metodo->ordena_crescente(ptMat1);

    printf("Imprimindo M1\nM1 = \n");
    ptMat1->Metodo->imprime(ptMat1);


    //Função de ordenar decrescente 

    printf("Imprimindo M1\nM1 = \n");
    ptMat1->Metodo->imprime(ptMat1);

    printf("Ordenando a matriz por ordem decrescente\n");
    ptMat1=ptMat1->Metodo->ordena_decrescente(ptMat1);

    printf("Imprimindo M1\nM1 = \n");
    ptMat1->Metodo->imprime(ptMat1);


    //Função de multiplicação por matrizes de acordo com a álgebra linear

    printf("Imprimindo M2\nM2 = \n");
    ptMat2->Metodo->imprime(ptMat2);

    printf("Imprimindo M3\nM3 = \n");
    ptMat3->Metodo->imprime(ptMat3);

    printf("Multiplicando o M2 pelo M3 seguindo o metódo de multiplicação de matrizes e colocando o resultado em MR\n");
    ptRes=ptRes->Metodo->dot_(ptMat2,ptMat3,ptRes);

    printf("Imprimindo MR\nMR = \n");
    if(ptRes != NULL) ptRes->Metodo->imprime(ptRes);

    // Função para verificar se a matriz é simétrica

    printf("Imprimindo M1\nM1 = \n");
    ptMat1->Metodo->imprime(ptMat1);

    if(ptMat1->Metodo->simetrica_(ptMat1)){
        printf("A matriz M1 é simétrica!\n\n");
    }else{
        printf("A matriz M1 não é simétrica!\n\n");
    }

    // Função para calcular o determinante de uma matriz 2x2 
     
    printf("Imprimindo M5\nM5 = \n");
    ptMat5->Metodo->imprime(ptMat5);

    printf("Calculando o determinante de M5\n");
    printf("O determinante de M5 é [%.2lf]\n\n", ptMat5->Metodo->determinante_(ptMat5, 2));

    // Função para calcular o determinante de uma matriz 3x3

    printf("Imprimindo M6\nM6 = \n");
    ptMat6->Metodo->imprime(ptMat6);

    printf("Calculando o determinante de M6\n");
    printf("O determinante de M6 é [%.2lf]\n\n", ptMat6->Metodo->determinante_(ptMat6, 3));


    /* ----------- OPERAÇÕES ELEMENTARES COM MATRIZES ----------- */ 
    printf("Escalonando a matriz M7 = \n");
    ptMat7->Metodo->imprime(ptMat7);

    printf("Trocando a linha 2 pela linha 3\n");
    ptMat7 = ptMat7->Metodo->trocarLinhas_(ptMat7, 2, 3);
    ptMat7->Metodo->imprime(ptMat7);

    printf("linha1 - 3*(linha3)\n");
    ptMat7 = ptMat7->Metodo->somarLinhaIporMultEscalarLinhaJ_(ptMat7, 1, 3, -3);
    ptMat7->Metodo->imprime(ptMat7);

    printf("linha3 - 2*(linha2)\n");
    ptMat7 = ptMat7->Metodo->somarLinhaIporMultEscalarLinhaJ_(ptMat7, 3, 2, -2);
    ptMat7->Metodo->imprime(ptMat7);

    printf("Divindo a linha 2 por 4\n");
    ptMat7 = ptMat7->Metodo->multiplicarLinhaEscalar_(ptMat7, 2, (double)1/4);
    ptMat7->Metodo->imprime(ptMat7);

    /* ------------- Destruindo as matrizes ------------- */

    printf("Destruindo as matrizes utilizadas\n");

    ptMat1->Metodo->destroi(ptMat1);
    ptMat2->Metodo->destroi(ptMat2);
    ptMat3->Metodo->destroi(ptMat3);
    ptMat4->Metodo->destroi(ptMat4);
    ptMat5->Metodo->destroi(ptMat5);
    ptMat6->Metodo->destroi(ptMat6);
    ptMat7->Metodo->destroi(ptMat7);
    ptRes->Metodo->destroi(ptRes);

    return(0);
}