#ifndef MINHA_MATRIZ_DOUBLE
#define MINHA_MATRIZ_DOUBLE

#include "numero.h"

struct MinhaMatriz_Interface_st;


struct MinhaMatriz_st {

    struct Numero_st super;

    struct MinhaMatriz_Interface_st const * Metodo;

    unsigned int * tam;
    double ** matriz;

};

typedef struct MinhaMatriz_st MinhaMatriz_t;
typedef struct MinhaMatriz_st * MinhaMatriz_pt;

struct MinhaMatriz_Interface_st {

    MinhaMatriz_pt 	(*copia)	(MinhaMatriz_t const * const me);
    MinhaMatriz_pt 	(*atribui)	(MinhaMatriz_t const * const  me, MinhaMatriz_t * const  outro);
    MinhaMatriz_pt 	(*soma)		(MinhaMatriz_t const * const  me, MinhaMatriz_t const * const  outro, MinhaMatriz_t * const res);
    MinhaMatriz_pt 	(*subt)		(MinhaMatriz_t const * const  me,MinhaMatriz_t const * const  outro,MinhaMatriz_t * const res);
    MinhaMatriz_pt 	(*mult)		(MinhaMatriz_t const * const  me,MinhaMatriz_t const * const  outro,MinhaMatriz_t * const res);
    MinhaMatriz_pt 	(*divd)		(MinhaMatriz_t const * const  me,MinhaMatriz_t const * const  outro,MinhaMatriz_t * const res);
    MinhaMatriz_pt 	(*ac_soma)	(MinhaMatriz_t * const  me,MinhaMatriz_t const * const  outro);
    MinhaMatriz_pt 	(*ac_subt)	(MinhaMatriz_t * const  me,MinhaMatriz_t const * const outro);
    MinhaMatriz_pt 	(*ac_mult)	(MinhaMatriz_t * const  me,MinhaMatriz_t const * const outro);
    MinhaMatriz_pt 	(*ac_divd)	(MinhaMatriz_t * const  me,MinhaMatriz_t const * const outro);
    int			(*compara)	(MinhaMatriz_t const * const  me,MinhaMatriz_t const * const  outro);
    char *      (*imprime)  (MinhaMatriz_t const * const  me);
    void        (*destroi)  (MinhaMatriz_t * me);

    MinhaMatriz_pt (*dot_) (MinhaMatriz_t const * const me, MinhaMatriz_t const * const outro, MinhaMatriz_t * const res);
    MinhaMatriz_pt (*resize) (MinhaMatriz_t * me, unsigned int * tam);
    MinhaMatriz_pt (*ones) (MinhaMatriz_t * me);   
    MinhaMatriz_pt (*add_linha) (MinhaMatriz_t * me);
    MinhaMatriz_pt (*add_coluna) (MinhaMatriz_t * me);
    MinhaMatriz_pt (*identidade) (MinhaMatriz_t * me);
    MinhaMatriz_pt (*transposta) (MinhaMatriz_t * me);
    MinhaMatriz_pt (*escalar_mult) (MinhaMatriz_t * const me, double escalar);
    MinhaMatriz_pt (*reverter_linhas) (MinhaMatriz_t * const me);
    MinhaMatriz_pt (*reverter_colunas) (MinhaMatriz_t * const me);
    MinhaMatriz_pt (*ordena_crescente) (MinhaMatriz_t * me);
    MinhaMatriz_pt (*ordena_decrescente) (MinhaMatriz_t * me);
    int (*simetrica_) (MinhaMatriz_t * me);
    double (*determinante_) (MinhaMatriz_t * me, int indice);
    double (*get_elemento) (MinhaMatriz_t const * const me, unsigned int * indice);
    void (*set_elemento) (MinhaMatriz_t const * const me, unsigned int * indice, double elemento);
    double * (*get_elementos) (MinhaMatriz_t const * const me, double * elementos);
    void (*set_elementos) (MinhaMatriz_t const * const me, double * elementos);
    MinhaMatriz_pt (*trocarLinhas_) (MinhaMatriz_t * me, int i, int j); 
    MinhaMatriz_pt (*multiplicarLinhaEscalar_) (MinhaMatriz_t * me, unsigned int linha, double escalar); 
    MinhaMatriz_pt (*somarLinhaIporMultEscalarLinhaJ_) (MinhaMatriz_t * me, int i, int j, double escalar);
};

typedef struct MinhaMatriz_Interface_st Interface_t;

MinhaMatriz_pt Matriz_Constroi(MinhaMatriz_pt me, unsigned int * tamanho, double * valores);


#endif