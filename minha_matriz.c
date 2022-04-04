#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "minha_matriz.h"

//PROTÓTIPOS
static  Numero_pt copia_ (Numero_t const * const me);
static  Numero_pt atribui_ (Numero_t const * const me,Numero_t * const   outro) ;
static  Numero_pt soma_  (Numero_t const * const me,Numero_t const * const outro,Numero_t * const res);
static  Numero_pt subt_  (Numero_t const * const me,Numero_t const * const outro,Numero_t * const res);
static  Numero_pt mult_  (Numero_t const * const me,Numero_t const * const outro,Numero_t * const res);
static  Numero_pt divd_  (Numero_t const * const  me,Numero_t const * const outro,Numero_t * const res);
static  Numero_pt ac_soma_  (Numero_t * const me,Numero_t const * const outro);
static  Numero_pt ac_subt_  (Numero_t * const me,Numero_t const * const outro);
static  Numero_pt ac_mult_  (Numero_t * const me,Numero_t const * const outro);
static  Numero_pt ac_divd_  (Numero_t * const me,Numero_t const * const outro);
static  int	compara_ 	(Numero_t const * const me,Numero_t const * const outro);
static  char * imprime_  (Numero_t const * const me);
static  void   destroi_  (Numero_t * me);


static  MinhaMatriz_pt Copia_ (MinhaMatriz_t const * const me);
static  MinhaMatriz_pt Atribui_ (MinhaMatriz_t const * const me,MinhaMatriz_t * const   outro) ;
static  MinhaMatriz_pt Soma_  (MinhaMatriz_t const * const me,MinhaMatriz_t const * const outro,MinhaMatriz_t * const res);
static  MinhaMatriz_pt Subt_  (MinhaMatriz_t const * const me,MinhaMatriz_t const * const outro,MinhaMatriz_t * const res);
static  MinhaMatriz_pt Mult_  (MinhaMatriz_t const * const me,MinhaMatriz_t const * const outro,MinhaMatriz_t * const res);
static  MinhaMatriz_pt Divd_  (MinhaMatriz_t const * const  me,MinhaMatriz_t const * const outro,MinhaMatriz_t * const res);
static  MinhaMatriz_pt Ac_soma_  (MinhaMatriz_t * const me,MinhaMatriz_t const * const outro);
static  MinhaMatriz_pt Ac_subt_  (MinhaMatriz_t * const me,MinhaMatriz_t const * const outro);
static  MinhaMatriz_pt Ac_mult_  (MinhaMatriz_t * const me,MinhaMatriz_t const * const outro);
static  MinhaMatriz_pt Ac_divd_  (MinhaMatriz_t * const me,MinhaMatriz_t const * const outro);
static  int	Compara_ 	(MinhaMatriz_t const * const me,MinhaMatriz_t const * const outro);
static  char * Imprime_  (MinhaMatriz_t const * const me);
static  void   Destroi_  (MinhaMatriz_t * me);
static MinhaMatriz_pt Dot_ (MinhaMatriz_t const * const me, MinhaMatriz_t const * const outro, MinhaMatriz_t * const res);
static MinhaMatriz_pt Resize_ (MinhaMatriz_t * me, unsigned int * tam);
static MinhaMatriz_pt Ones_ (MinhaMatriz_t * me);   
static MinhaMatriz_pt Add_linha_ (MinhaMatriz_t * me);
static MinhaMatriz_pt Add_coluna_ (MinhaMatriz_t * me);
static MinhaMatriz_pt Identidade_ (MinhaMatriz_t * me);
static MinhaMatriz_pt Transposta_ (MinhaMatriz_t * me);
static MinhaMatriz_pt Escalar_mult_ (MinhaMatriz_t * const me, double escalar);
static MinhaMatriz_pt Reverter_linhas_ (MinhaMatriz_t * const me);
static MinhaMatriz_pt Reverter_colunas_ (MinhaMatriz_t * const me);
static MinhaMatriz_pt Ordena_crescente_ (MinhaMatriz_t * me);
static MinhaMatriz_pt Orderna_decrescente_ (MinhaMatriz_t * me);
static int Simetrica_ (MinhaMatriz_t * me);
static double Determinante_ (MinhaMatriz_t * me, int indice); // determinante 2x2 ou 3x3
static double Get_elemento_ (MinhaMatriz_t const * const me, unsigned int * indice);
static void Set_elemento_ (MinhaMatriz_t const * const me, unsigned int * indice, double elemento);
static double * Get_elementos_ (MinhaMatriz_t const * const me, double * elementos);
static void Set_elementos_ (MinhaMatriz_t const * const me, double * elementos);

/* OPERAÇÕES ELEMENTARES PARA ESCALONAR MATRIZES */
static MinhaMatriz_pt TrocarLinhas_ (MinhaMatriz_t * me, int i, int j); 
static MinhaMatriz_pt MultiplicarLinhaEscalar_ (MinhaMatriz_t * me, unsigned int linha, double escalar); 
static MinhaMatriz_pt SomarLinhaIporMultEscalarLinhaJ_ (MinhaMatriz_t * me, int i, int j, double escalar);

//IMPLEMENTAÇÕES

MinhaMatriz_pt Matriz_Constroi(MinhaMatriz_pt me, unsigned int * tamanho, double * valores){

    //Tabela do tipo numero
    static struct NumeroVtbl numVtbl = { 

        .ac_divd = &ac_divd_,
        .ac_mult = &ac_mult_,
        .ac_soma = &ac_soma_,
        .ac_subt = &ac_subt_,
        .atribui = &atribui_,
        .compara = &compara_,
        .copia = &copia_,
        .destroi = &destroi_,
        .divd = &divd_,
        .imprime = &imprime_,
        .mult = &mult_,
        .soma = &soma_,
        .subt = &subt_
    };

    //Alocando o tipo
    MinhaMatriz_t * ptMat = (MinhaMatriz_t*) malloc (sizeof(MinhaMatriz_t));

    //Tabela da matriz
    static struct MinhaMatriz_Interface_st interface = {  

        .ac_divd = &Ac_divd_,
        .ac_mult = &Ac_mult_,
        .ac_soma = &Ac_soma_,
        .ac_subt = &Ac_subt_,
        .add_coluna = &Add_coluna_,
        .add_linha = &Add_linha_,
        .atribui = &Atribui_,
        .compara = &Compara_,
        .copia = &Copia_,
        .destroi = &Destroi_,
        .divd = &Divd_,
        .escalar_mult = &Escalar_mult_,
        .get_elemento = &Get_elemento_,
        .set_elemento = &Set_elemento_,
        .get_elementos = &Get_elementos_,
        .set_elementos = &Set_elementos_,
        .identidade = &Identidade_,
        .imprime = &Imprime_,
        .mult = &Mult_,
        .ones = &Ones_,
        .ordena_crescente = &Ordena_crescente_,
        .ordena_decrescente = &Orderna_decrescente_,
        .resize = &Resize_,
        .reverter_colunas = &Reverter_colunas_,
        .reverter_linhas = &Reverter_linhas_,
        .dot_ = &Dot_,
        .simetrica_ = &Simetrica_,
        .soma = &Soma_,
        .subt = &Subt_,
        .multiplicarLinhaEscalar_ = &MultiplicarLinhaEscalar_,
        .trocarLinhas_ = &TrocarLinhas_,
        .somarLinhaIporMultEscalarLinhaJ_ = &SomarLinhaIporMultEscalarLinhaJ_,
        .determinante_ = &Determinante_,
        .transposta = &Transposta_
    };


    //Alocando o tamanho
    ptMat->tam = (unsigned int *)malloc (sizeof(unsigned int) * 2);
    ptMat->tam[0] = tamanho[0];
    ptMat->tam[1] = tamanho[1];

    //Alocando a matriz
    ptMat->matriz = (double **)malloc (sizeof(double*) * tamanho[0]);
    for(int i=0; i<tamanho[0];i++){
        ptMat->matriz[i] = (double *)malloc (sizeof(double) * tamanho[1]);
    }

    int cont = 0;
    for(int i=0; i<tamanho[0];i++){

        for(int j=0; j<tamanho[1]; j++){

            ptMat->matriz[i][j] = valores[cont];
            cont++;
        }
    }


    ptMat->super.metodo = &numVtbl;
    ptMat->Metodo = &interface;
    me = ptMat;

    return ptMat; 
}


static inline MinhaMatriz_pt Copia_ (MinhaMatriz_t const * const me){ 
    return ((MinhaMatriz_pt) copia_ ((Numero_pt)me));
}

static Numero_pt copia_ (Numero_t const * const me){
    assert (me != NULL);

    Numero_pt outro = NULL;

    unsigned int linha = ((MinhaMatriz_pt)me)->tam[0], coluna = ((MinhaMatriz_pt)me)->tam[1], tamanho = linha * coluna;

    double * elementos = (double *) malloc (sizeof(double) * tamanho);

    outro = (Numero_pt) Matriz_Constroi ((MinhaMatriz_pt) outro, ((MinhaMatriz_pt)me)->tam, Get_elementos_((MinhaMatriz_pt)me, elementos));

    free(elementos);

    return outro;
}

static inline MinhaMatriz_pt Atribui_ (MinhaMatriz_t const * const me,MinhaMatriz_t * const outro){
    return ((MinhaMatriz_pt) atribui_((Numero_pt) me,(Numero_pt)outro));
}

static  Numero_pt atribui_ (Numero_t const * const me, Numero_t * const outro){
    unsigned int l1,l2,c1,c2;
    l1=((MinhaMatriz_pt)me)->tam[0], c1=((MinhaMatriz_pt)me)->tam[1];
    l2=((MinhaMatriz_pt)outro)->tam[0], c2=((MinhaMatriz_pt)outro)->tam[1];

    if((l1!=l2)||(c1!=c2)){
        Resize_((MinhaMatriz_pt) outro, ((MinhaMatriz_pt)me)->tam);
    }

    unsigned int linha = ((MinhaMatriz_pt)me)->tam[0], coluna = ((MinhaMatriz_pt)me)->tam[1], tamanho = linha * coluna;

    double * elementos = (double *) malloc (sizeof(double) * tamanho);

    Set_elementos_((MinhaMatriz_pt)outro, Get_elementos_((MinhaMatriz_pt)me, elementos));

    free(elementos);

    return (Numero_pt)outro;
}

static inline  MinhaMatriz_pt Soma_  (MinhaMatriz_t const * const me,MinhaMatriz_t const * const outro,MinhaMatriz_t * const res){
    return((MinhaMatriz_pt)soma_ ((Numero_pt)me, (Numero_pt)outro, (Numero_pt)res));
}

static  Numero_pt soma_  (Numero_t const * const me,Numero_t const * const outro,Numero_t * const res){
    unsigned int l1,l2,c1,c2;
    l1=((MinhaMatriz_pt)me)->tam[0], c1=((MinhaMatriz_pt)me)->tam[1];
    l2=((MinhaMatriz_pt)outro)->tam[0], c2=((MinhaMatriz_pt)outro)->tam[1];


    if((l1!=l2) || (c1!=c2)){
        printf("ERRO: Nao eh possivel realizar a operacao soma, porque as matrizes possuem tamanhos diferentes \n");
        printf("Retornando a primeira matriz, temos:\n");
        return (Numero_pt) me;
    }

    for(int i=0; i<l1; i++){
        for(int j=0; j<c1; j++){
            ((MinhaMatriz_pt)res)->matriz[i][j] = (double)((MinhaMatriz_pt)me)->matriz[i][j] + (double)((MinhaMatriz_pt)outro)->matriz[i][j];
        }
    }

    return (Numero_pt) res;
} 

static  inline MinhaMatriz_pt Subt_ (MinhaMatriz_t const * const me,MinhaMatriz_t const * const outro,MinhaMatriz_t * const res){
    return((MinhaMatriz_pt)subt_ ((Numero_pt)me, (Numero_pt)outro, (Numero_pt)res));
}

static  Numero_pt subt_ (Numero_t const * const me,Numero_t const * const outro,Numero_t * const res){
    unsigned int l1,l2,c1,c2;
    l1=((MinhaMatriz_pt)me)->tam[0], c1=((MinhaMatriz_pt)me)->tam[1];
    l2=((MinhaMatriz_pt)outro)->tam[0], c2=((MinhaMatriz_pt)outro)->tam[1];


    if((l1!=l2) || (c1!=c2)){
        printf("ERRO: Nao eh possivel realizar a operacao subtracao, porque as matrizes possuem tamanhos diferentes \n");
        printf("Retornando a primeira matriz, temos:\n");
        return (Numero_pt) me;
    }

    for(int i=0; i<l1; i++){
        for(int j=0; j<c1; j++){
            ((MinhaMatriz_pt)res)->matriz[i][j] = (double)((MinhaMatriz_pt)me)->matriz[i][j] - (double)((MinhaMatriz_pt)outro)->matriz[i][j];
        }
    }

    return (Numero_pt) res;
} 

static  inline MinhaMatriz_pt Mult_ (MinhaMatriz_t const * const me,MinhaMatriz_t const * const outro,MinhaMatriz_t * const res){
    return((MinhaMatriz_pt) mult_ ((Numero_pt)me, (Numero_pt)outro, (Numero_pt)res));
}

static  Numero_pt mult_ (Numero_t const * const me, Numero_t const * const outro,Numero_t * const res){
    unsigned int l1,l2,c1,c2;
    l1=((MinhaMatriz_pt)me)->tam[0], c1=((MinhaMatriz_pt)me)->tam[1];
    l2=((MinhaMatriz_pt)outro)->tam[0], c2=((MinhaMatriz_pt)outro)->tam[1];


    if((l1!=l2) || (c1!=c2)){
        printf("ERRO: Nao eh possivel realizar a operacao multiplicacao, porque as matrizes possuem tamanhos diferentes \n");
        printf("Retornando a primeira matriz, temos:\n");
        return (Numero_pt) me;
    }

    for(int i=0; i<l1; i++){
        for(int j=0; j<c1; j++){
            ((MinhaMatriz_pt)res)->matriz[i][j] = (double)((MinhaMatriz_pt)me)->matriz[i][j] * (double)((MinhaMatriz_pt)outro)->matriz[i][j];
        }
    }

    return (Numero_pt) res;
} 


static  inline MinhaMatriz_pt Divd_  (MinhaMatriz_t const * const me,MinhaMatriz_t const * const outro,MinhaMatriz_t * const res){
    return((MinhaMatriz_pt) divd_ ((Numero_pt)me, (Numero_pt)outro, (Numero_pt)res));
}

static  Numero_pt divd_  (Numero_t const * const me,Numero_t const * const outro,Numero_t * const res){
    unsigned int l1,l2,c1,c2;
    l1=((MinhaMatriz_pt)me)->tam[0], c1=((MinhaMatriz_pt)me)->tam[1];
    l2=((MinhaMatriz_pt)outro)->tam[0], c2=((MinhaMatriz_pt)outro)->tam[1];


    if((l1!=l2) || (c1!=c2)){
        printf("ERRO: Nao eh possivel realizar a operacao divisao, porque as matrizes possuem tamanhos diferentes \n");
        printf("Retornando a primeira matriz, temos:\n");
        return (Numero_pt) me;
    }

    for(int i=0; i<l1; i++){
        for(int j=0; j<c1; j++){
            if(((MinhaMatriz_pt)outro)->matriz[i][j] == 0){
                printf("ERRO: Nao eh possivel dividir por zero! O elemento foi mantido no seu estado original\n");
                continue;
            }

            ((MinhaMatriz_pt)res)->matriz[i][j] = (double)((MinhaMatriz_pt)me)->matriz[i][j] / (double)((MinhaMatriz_pt)outro)->matriz[i][j];
        }
    }

    return (Numero_pt) res;
} 



static inline MinhaMatriz_pt Ac_soma_  (MinhaMatriz_t * const me,MinhaMatriz_t const * const outro){
    return((MinhaMatriz_pt) ac_soma_ ((Numero_pt)me, (Numero_pt)outro));
}

static  Numero_pt ac_soma_  (Numero_t * const  me, Numero_t const * const outro){
    unsigned int l1,l2,c1,c2;
    l1=((MinhaMatriz_pt)me)->tam[0], c1=((MinhaMatriz_pt)me)->tam[1];
    l2=((MinhaMatriz_pt)outro)->tam[0], c2=((MinhaMatriz_pt)outro)->tam[1];


    if((l1!=l2) || (c1!=c2)){
        printf("ERRO: Nao eh possivel realizar a operacao soma acumulada, porque as matrizes possuem tamanhos diferentes \n");
        printf("Retornando a primeira matriz, temos:\n");
        return (Numero_pt) me;
    }

    for(int i=0; i<l1; i++){
        for(int j=0; j<c1; j++){
            ((MinhaMatriz_pt)me)->matriz[i][j] = (double)((MinhaMatriz_pt)me)->matriz[i][j] + (double)((MinhaMatriz_pt)outro)->matriz[i][j];
        }
    }

    return (Numero_pt) me;
} 

static  inline MinhaMatriz_pt Ac_subt_  (MinhaMatriz_t * const me,MinhaMatriz_t const * const outro){
    return((MinhaMatriz_pt) ac_subt_ ((Numero_pt)me, (Numero_pt)outro));
}

static  Numero_pt ac_subt_  (Numero_t * const  me, Numero_t const * const outro){
    unsigned int l1,l2,c1,c2;
    l1=((MinhaMatriz_pt)me)->tam[0], c1=((MinhaMatriz_pt)me)->tam[1];
    l2=((MinhaMatriz_pt)outro)->tam[0], c2=((MinhaMatriz_pt)outro)->tam[1];


    if((l1!=l2) || (c1!=c2)){
        printf("ERRO: Nao eh possivel realizar a operacao subtracao acumulada, porque as matrizes possuem tamanhos diferentes \n");
        printf("Retornando a primeira matriz, temos:\n");
        return (Numero_pt) me;
    }

    for(int i=0; i<l1; i++){
        for(int j=0; j<c1; j++){
            ((MinhaMatriz_pt)me)->matriz[i][j] = (double)((MinhaMatriz_pt)me)->matriz[i][j] - (double)((MinhaMatriz_pt)outro)->matriz[i][j];
        }
    }

    return (Numero_pt) me;
} 

static  inline MinhaMatriz_pt Ac_mult_  (MinhaMatriz_t * const me,MinhaMatriz_t const * const outro){
    return((MinhaMatriz_pt) ac_mult_ ((Numero_pt)me, (Numero_pt)outro));
}

static  Numero_pt ac_mult_  (Numero_t * const  me, Numero_t const * const outro){
    unsigned int l1,l2,c1,c2;
    l1=((MinhaMatriz_pt)me)->tam[0], c1=((MinhaMatriz_pt)me)->tam[1];
    l2=((MinhaMatriz_pt)outro)->tam[0], c2=((MinhaMatriz_pt)outro)->tam[1];


    if((l1!=l2) || (c1!=c2)){
        printf("ERRO: Nao eh possivel realizar a operacao multiplicacao acumulada, porque as matrizes possuem tamanhos diferentes \n");
        printf("Retornando a primeira matriz, temos:\n");
        return (Numero_pt) me;
    }

    for(int i=0; i<l1; i++){
        for(int j=0; j<c1; j++){
            ((MinhaMatriz_pt)me)->matriz[i][j] = (double)((MinhaMatriz_pt)me)->matriz[i][j] * (double)((MinhaMatriz_pt)outro)->matriz[i][j];
        }
    }

    return (Numero_pt) me;
} 



static  inline MinhaMatriz_pt Ac_divd_  (MinhaMatriz_t * const me,MinhaMatriz_t const * const outro){
    return((MinhaMatriz_pt) ac_divd_ ((Numero_pt)me, (Numero_pt)outro));
}

static  Numero_pt ac_divd_  (Numero_t * const  me, Numero_t const * const outro){
    unsigned int l1,l2,c1,c2;
    l1=((MinhaMatriz_pt)me)->tam[0], c1=((MinhaMatriz_pt)me)->tam[1];
    l2=((MinhaMatriz_pt)outro)->tam[0], c2=((MinhaMatriz_pt)outro)->tam[1];


    if((l1!=l2) || (c1!=c2)){
        printf("ERRO: Nao eh possivel realizar a operacao divisao acumulada, porque as matrizes possuem tamanhos diferentes \n");
        printf("Retornando a primeira matriz, temos:\n");
        return (Numero_pt) me;
    }

    for(int i=0; i<l1; i++){
        for(int j=0; j<c1; j++){
            if(((MinhaMatriz_pt)outro)->matriz[i][j] == 0){
                printf("ERRO: Nao eh possivel dividir por zero! O elemento foi mantido no seu estado original\n");
                continue;
            }
            
            ((MinhaMatriz_pt)me)->matriz[i][j] = (double)((MinhaMatriz_pt)me)->matriz[i][j] / (double)((MinhaMatriz_pt)outro)->matriz[i][j];
        }
    }

    return (Numero_pt) me;
} 

static inline int Compara_ (MinhaMatriz_t const * const me, MinhaMatriz_t const * const outro){ 
    return (compara_((Numero_pt)me, (Numero_pt)outro));
}


static int compara_ (Numero_t const * const me,Numero_t const * const outro){
    unsigned int l1,c1, l2, c2;
    l1 = ((MinhaMatriz_pt)me)->tam[0], c1 = ((MinhaMatriz_pt)me)->tam[1];
    l2 = ((MinhaMatriz_pt)outro)->tam[0], c2 = ((MinhaMatriz_pt)outro)->tam[1];
    
    // retorna 0 para indicar que as matrizes são diferentes, por apresentarem tamanhos diferentes
    if((l1!=l2) || (c1!=c2)){
        return 0;
    }
    
    for(int i=0; i<l1; i++){
        for(int j=0; j<c1; j++){
            if(((MinhaMatriz_pt)me)->matriz[i][j] != ((MinhaMatriz_pt)outro)->matriz[i][j]){
                return 0;
            }
        }
    }

    return 1;
}

static inline char * Imprime_  (MinhaMatriz_t const * const me){
    return (imprime_((Numero_pt)me));
}

static char * imprime_ (Numero_t const * const me){
    unsigned int l1,c1;
    l1 = ((MinhaMatriz_pt)me)->tam[0], c1 = ((MinhaMatriz_pt)me)->tam[1];
    
    for(int i=0; i<l1; i++){ 
        printf("[ ");
        for(int j=0; j<c1; j++){
            printf("%.2lf ", ((MinhaMatriz_pt)me)->matriz[i][j]);
        }

        printf("]\n");
    }

    printf("\n\n");

    return '\0';
}



static  void   Destroi_  (MinhaMatriz_t * me){ 
    destroi_((Numero_t *)me);
}

static  void   destroi_  (Numero_t * me){

    for(int i = 0; i < ((MinhaMatriz_t *)me)->tam[0]; i++){

        if(((MinhaMatriz_t *)me)->matriz[i] != NULL) free(((MinhaMatriz_t *)me)->matriz[i]);
    }

    if(((MinhaMatriz_t *)me)->matriz != NULL) free(((MinhaMatriz_t *)me)->matriz);

    if(((MinhaMatriz_t *)me)->tam != NULL) free(((MinhaMatriz_t *)me)->tam);

    if((MinhaMatriz_t *)me != NULL) free((MinhaMatriz_t *)me);
}

/*------------------------------------------------ get e set ---------------------------------------------*/

static double Get_elemento_ (MinhaMatriz_t const * const me, unsigned int * indice){ 
    unsigned int linha, coluna; 

    linha = indice[0], coluna = indice[1];

    return me->matriz[linha][coluna];
}

static void Set_elemento_ (MinhaMatriz_t const * const me, unsigned int * indice, double elemento){ 
    unsigned int linha, coluna;

    linha = indice[0], coluna = indice[1];

    me->matriz[linha][coluna] = elemento;
}

static double * Get_elementos_ (MinhaMatriz_t const * const me, double * elementos){
   
    unsigned int linha = ((MinhaMatriz_pt)me)->tam[0], coluna = ((MinhaMatriz_pt)me)->tam[1];
    int i=0, j=0, k=0;

    for(i=0; i<linha; i++){
        for(j=0; j<coluna; j++){
            elementos[k] = ((MinhaMatriz_pt)me)->matriz[i][j];
            k++;
      
        }
    }

    return elementos;
}


static void Set_elementos_ (MinhaMatriz_t const * const me, double * elementos){
    unsigned int linha = ((MinhaMatriz_pt)me)->tam[0], coluna = ((MinhaMatriz_pt)me)->tam[1];
    int i=0, j=0, k=0;

    for(i=0; i<linha; i++){
        for(j=0; j<coluna; j++){
           ((MinhaMatriz_pt)me)->matriz[i][j] = elementos[k] ;
            k++;
      
        }
    }
}




/*----------------------- FUNÇÕES ADICIONAIS ------------------------*/

static MinhaMatriz_pt Dot_ (MinhaMatriz_t const * const me, MinhaMatriz_t const * const outro, MinhaMatriz_t * const res){
    
    unsigned int l1,l2,c1,c2, tamRes[2];
    l1= me->tam[0], c1= me->tam[1];
    l2= outro->tam[0], c2= outro->tam[1];
    tamRes[0] = l1, tamRes[1] = c2;

    Resize_(res, tamRes);

    if(c1!=l2){
        printf("ERRO: Nao eh possivel realizar a operacao multiplicao, porque as matrizes possuem tamanhos diferentes.\n");
        printf("Eh preciso que o numero de colunas da primeira matriz inserida seja igual ao numero de linhas da segunda matriz\n");
        return NULL;
    }

    int i=0, j=0, k=0;
    double somaDosProdutos=0;

    for(i=0; i<l1; i++){
        for(j=0; j<c2; j++){
            somaDosProdutos = 0;

            for(k=0; k<c1; k++){
                somaDosProdutos += me->matriz[i][k]  * outro->matriz[k][j]; 
            }

            res->matriz[i][j] = somaDosProdutos;
        }
    } 

    return res;
}



static MinhaMatriz_pt Resize_ (MinhaMatriz_t * me, unsigned int * tam){

    unsigned int l1, c1, l2, c2;
    l1 = me->tam[0], c1 = me->tam[1], l2 = tam[0],c2 = tam[1];
    
    if(l1 == l2 && c1 == c2) return me;

    

    me->matriz = realloc(me->matriz, sizeof(double*) * l2);
    for(int i=0;i<l2;i++){
        me->matriz[i] = realloc(me->matriz[i], sizeof(double) * c2);
    }

    for(int i= l1; i<l2; i++){
        for(int j=0; j<c2; j++){

            me->matriz[i][j] = 0;
        }
    }

    for(int j =c1; j<c2; j++){
        for(int i=0; i<l2; i++){

            me->matriz[i][j] = 0;
        }
    }

    me->tam[1]=tam[1];
    me->tam[0]=tam[0];

    
    return me;
}   

static MinhaMatriz_pt Ones_ (MinhaMatriz_t * me){ 
    unsigned int linha = me->tam[0], coluna = me->tam[1];

    for(int i=0; i<linha; i++){
        for(int j=0; j<coluna; j++){
            me->matriz[i][j] = 1;
        }
    }

    return me;
}


static MinhaMatriz_pt Add_linha_ (MinhaMatriz_t * me){
    unsigned int novaLinha = me->tam[0] + 1, coluna = me->tam[1];
    unsigned int novoTamanho[2] = {novaLinha, coluna};

    Resize_(me, novoTamanho);
    return me; 
}


static MinhaMatriz_pt Add_coluna_ (MinhaMatriz_t * me){
    unsigned int novaColuna = me->tam[1] + 1, linha = me->tam[0];
    unsigned int novoTamanho[2] = {linha, novaColuna};

    Resize_(me, novoTamanho);
    return me; 
}


static MinhaMatriz_pt Identidade_ (MinhaMatriz_t * me){ 
    unsigned int linha = me->tam[0], coluna = me->tam[1];
    int i=0, j=0;

    /* verifica se a matriz é quadrada */
    if(linha!=coluna){ 
        printf("ERRO: O num de linhas eh diferente do de colunas. A matriz identidade precisa ser quadrada!");
        return me;
    }


    for(i=0; i<linha; i++){ 
        for(j=0; j<coluna; j++){
            if(i==j){
                me->matriz[i][j] = 1;
            }else{ 
                me->matriz[i][j] = 0;
            }
        }
    }

    return me;
}

static MinhaMatriz_pt Transposta_ (MinhaMatriz_t * me){
    unsigned int linha = me->tam[0], coluna = me->tam[1];
    unsigned int tamVetor = linha * coluna;
    unsigned int novoTamanho[2] = {coluna, linha};
    int i=0, j=0, k=0;

    double * valores = (double*) malloc(sizeof(double)*tamVetor);

    for(j=0; j<coluna; j++){
        for(i=0; i<linha; i++){
            valores[k] = me->matriz[i][j];
            k++;
        }
    }

    me->tam[0] = coluna;
    me->tam[1] = linha;

    Resize_(me, novoTamanho);

    int cont = 0;
    for(i=0;i<me->tam[0];i++){

        for(j=0;j<me->tam[1];j++){

            me->matriz[i][j] = valores[cont];
            cont++;
        }
    }

    free(valores);
    return me;
}

static MinhaMatriz_pt Escalar_mult_ (MinhaMatriz_t * const me, double escalar){
    unsigned int linha = me->tam[0], coluna = me->tam[1];

    for(int i=0; i<linha; i++){
        for(int j=0; j<coluna; j++){
            me->matriz[i][j] *= escalar;
        }
    }

    return me; 
}


static MinhaMatriz_pt Reverter_linhas_ (MinhaMatriz_t * const me){
    unsigned int linha = me->tam[0], coluna = me->tam[1];
    unsigned int tamVetor = linha * coluna;
    int i=0, j=0, k=0;

    double * valores = (double*) malloc(sizeof(double)*tamVetor);
    
    valores = Get_elementos_(me, valores);

    for(i=linha-1; i>=0; i--){
        for(j=0; j<coluna; j++){
            me->matriz[i][j] = valores[k];
            k++;
        }
    }

    free(valores);

    return me;
}

static MinhaMatriz_pt Reverter_colunas_ (MinhaMatriz_t * const me){
    unsigned int linha = me->tam[0], coluna = me->tam[1];
    unsigned int tamVetor = linha * coluna;
    int i=0, j=0, k=0;

    double * valores = (double*) malloc(sizeof(double)*tamVetor);

    valores = Get_elementos_(me, valores);

    for(i=0; i<linha; i++){
        for(j=coluna-1; j>=0; j--){
            me->matriz[i][j] = valores[k];
            k++;
        }
    }

    free(valores);

    return me;
}


static MinhaMatriz_pt Ordena_crescente_ (MinhaMatriz_t * me){
    unsigned int linha = me->tam[0], coluna = me->tam[1];
    unsigned int tamVetor = linha * coluna;
    int i=0, j=0, idMenor, menorValor, aux;

    double * valores = (double*) malloc(sizeof(double)*tamVetor);
    
    valores = Get_elementos_(me, valores);

    /* ordena o vetor de valores de 'me' */
    for(i=0; i<tamVetor; i++){
        menorValor=valores[i];
        for(j=i+1; j<tamVetor; j++){
            if(valores[j]<menorValor){
                menorValor=valores[j];
                idMenor=j;
            }
        }

        if(valores[i]>menorValor){
            aux=valores[i];
            valores[i]=menorValor;
            valores[idMenor]=aux;
        }
    }

    int cont = 0;
    for(i=0;i<me->tam[0];i++){

        for(j=0;j<me->tam[1];j++){

            me->matriz[i][j] = valores[cont];
            cont++;
        }
    }

    free(valores);
    return me;

}

static MinhaMatriz_pt Orderna_decrescente_ (MinhaMatriz_t * me){
    unsigned int linha = me->tam[0], coluna = me->tam[1];
    unsigned int tamVetor = linha * coluna;
    int i=0, j=0, idMaior, maiorValor, aux;

    double * valores = (double*) malloc(sizeof(double)*tamVetor);
    
    valores = Get_elementos_(me, valores);

    /* ordena o vetor de valores de 'me' */
    for(i=0; i<tamVetor; i++){
        maiorValor=valores[i];
        for(j=i+1; j<tamVetor; j++){
            if(valores[j]>maiorValor){
                maiorValor=valores[j];
                idMaior=j;
            }
        }

        if(valores[i]<maiorValor){
            aux=valores[i];
            valores[i]=maiorValor;
            valores[idMaior]=aux;
        }
    }

    int cont = 0;
    for(i=0;i<me->tam[0];i++){

        for(j=0;j<me->tam[1];j++){

            me->matriz[i][j] = valores[cont];
            cont++;
        }
    }

    free(valores);
    return me;
}

static int Simetrica_ (MinhaMatriz_t * me){
    unsigned int linha = me->tam[0], coluna = me->tam[1];
    unsigned int tamValores = linha * coluna;

    double * valoresMe = (double*) malloc(sizeof(double)*tamValores);
    double * valoresOutro = (double*) malloc(sizeof(double)*tamValores);
    
    valoresMe = Get_elementos_(me, valoresMe);
    valoresOutro = Get_elementos_(Transposta_(me), valoresOutro);

    for(int i=0; i<tamValores; i++){
        if(valoresMe[i]!=valoresOutro[i]){
            return 0;
        }
    }

    free(valoresMe);
    free(valoresOutro);
    return 1;
}

static double Determinante_ (MinhaMatriz_t * me, int indice){
    double res=0;

    if(indice == 2){
        res = (me->matriz[0][0] * me->matriz[1][1]) - (me->matriz[0][1] * me->matriz[1][0]);
    
    }else if(indice == 3){
        double d1=0, d2=0, d3=0, d4=0, d5=0, d6=0;
        
        d1 = me->matriz[0][0] * me->matriz[1][1] * me->matriz[2][2];
        d2 = me->matriz[0][1] * me->matriz[1][2] * me->matriz[2][0];
        d3 = me->matriz[0][2] * me->matriz[1][0] * me->matriz[2][1];
        d4 = me->matriz[2][0] * me->matriz[1][1] * me->matriz[0][2];
        d5 = me->matriz[2][1] * me->matriz[1][2] * me->matriz[0][0];
        d6 = me->matriz[2][2] * me->matriz[1][0] * me->matriz[0][1];

        res = (d1+d2+d3) - (d4+d5+d6);
    }

    return res;

}

/* ----------- OPERAÇÕES ELEMENTARES PARA ESCALONAR MATRIZES ------------ */
static MinhaMatriz_pt TrocarLinhas_ (MinhaMatriz_t * me, int i, int j){ 
    unsigned int coluna = me->tam[1];
    i--, j--;

    double valoresLinha_i[coluna];
    double valoresLinha_j[coluna];

   
    for(int k=0; k<coluna; k++){
        valoresLinha_i[k] = me->matriz[i][k];
        valoresLinha_j[k] = me->matriz[j][k];
    }
 
    for(int k=0; k<coluna; k++){
        me->matriz[i][k] = valoresLinha_j[k];
        me->matriz[j][k] = valoresLinha_i[k];
    }

    return me;
}

static MinhaMatriz_pt MultiplicarLinhaEscalar_ (MinhaMatriz_t * me, unsigned int linha, double escalar){
    unsigned int coluna = me->tam[1];
    linha--;

    for(int j=0; j<coluna; j++){
        me->matriz[linha][j] *= escalar;
    }

    return me;
}

static MinhaMatriz_pt SomarLinhaIporMultEscalarLinhaJ_ (MinhaMatriz_t * me, int i, int j, double escalar){
    unsigned int coluna = me->tam[1];
    i--, j--;

    for(int k=0; k<coluna; k++){
        me->matriz[i][k] += me->matriz[j][k] * escalar;
    }

    return me;
}