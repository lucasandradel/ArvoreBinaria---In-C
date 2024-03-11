#include <stdlib.h>
#include <stdio.h>

#include "ArvoreBin.h"
#include "ArvoreBin.c"

int main (){
    tipo_arv_bin *arvore;
    arvore = NULL;

    InsereArvBin(&arvore, 10);
    InsereArvBin(&arvore, 7);
    InsereArvBin(&arvore, 31);
    InsereArvBin(&arvore, 3);
    InsereArvBin(&arvore, 9);
    InsereArvBin(&arvore, 15);
    InsereArvBin(&arvore, 50);
    InsereArvBin(&arvore, 8);
    InsereArvBin(&arvore, 45);
    InsereArvBin(&arvore, 100);
    InsereArvBin(&arvore, 99);

    printf("impressão Pré ordem:\n");
    PercursoPreOrdem(arvore);
    printf ("\n\n");

    printf("impressão ordem:\n");
    PercursoOrdem(arvore);
    printf ("\n\n");

    printf("impressão Pós ordem:\n");
    PercursoPosOrdem(arvore);
    printf ("\n\n");


    int vl = 50;

    printf ("Buscando valor %d\n\n ", vl);
    if (BuscaValor(arvore, vl)){
        printf("Valor %d encontrado\n\n", vl);
    }else{
        printf("Valor %d não encontrado\n\n", vl);
    }

    printf("Altura da arvore: %d\n\n ", AlturaArvBin(arvore));

    printf ("A quantidade de nós da arvore eh: %d\n\n",ContabilizaNosArvBin(arvore) );


    printf ("A quantidade de nós folhas da arvore eh: %d\n\n",ContabilizaNosFolhasArvBin(arvore) );


    // Chamada para imprimir os nós do nível 2
    printf("Impressão dos nós do nivel 2\n");
    ImprimeNivelArvBin(arvore, 2, 0);
    printf("\n\n");

    int folha = 99;
    RemoveArvBin(arvore, folha);

    return 1;
}