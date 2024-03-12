#include <stdlib.h>
#include <stdio.h>

#include "ArvoreBin.h"
#include "ArvoreBin.c"

int main (){
    tipo_arv_bin *arvore;
    arvore = NULL;

    InsereArvBin(&arvore, 583);
    InsereArvBin(&arvore, 245);
    InsereArvBin(&arvore, 731);
    InsereArvBin(&arvore, 123);
    InsereArvBin(&arvore, 389);
    InsereArvBin(&arvore, 684);
    InsereArvBin(&arvore, 893);
    InsereArvBin(&arvore, 278);

    printf("\t\n--------- Valores inseridos!!! --------\n\n ");

    printf("impressão Pré ordem:\n");
    PercursoPreOrdem(arvore);
    printf ("\n\n");

    printf("impressão ordem:\n");
    PercursoOrdem(arvore);
    printf ("\n\n");

    printf("impressão Pós ordem:\n");
    PercursoPosOrdem(arvore);
    printf ("\n\n");

    printf("\t\n--------- Tipos de Elementos ---------\n\n");
    ImprimeTipoNoh(arvore);

    printf ("\n----- A quantidade de nós da arvore eh: %d -----\n\n",ContabilizaNosArvBin(arvore) );

    printf ("----- A quantidade de nós folhas da arvore eh: %d -----\n\n",ContabilizaNosFolhasArvBin(arvore) );

    printf ("----- A quantidade de nós com apenas um filho da arvore eh: %d -----\n\n",ContabilizaNosComUmFilho(arvore) );



    int vl;

    printf("Digite o valor que deseja buscar:");
    scanf("%d", &vl);

    printf ("Buscando valor... %d\n\n ", vl);
    if (BuscaValor(arvore, vl)){
        printf("-------- Valor %d encontrado -------\n\n", vl);
    }else{
        printf("[ERRO] Valor %d não encontrado [ERRO]\n\n", vl);
    }

    printf(" -------- Altura da arvore: %d --------\n\n ", AlturaArvBin(arvore));


    printf("----------------------------------------------------------------------------------     REMOÇÂO    ----------------------------------------------------------------------------------------------\n\n");
   
    int ValorRemovido;
    printf("Digite o Número que deseja remover, porfavor: ");
    scanf("%d", &ValorRemovido);


    RemoveArvBin(arvore, ValorRemovido);

    printf ("\nA quantidade de nós da arvore depois da remoção eh: %d\n\n",ContabilizaNosArvBin(arvore) );


    printf("impressão em pré ordem após o elemento (%d) ser removido \n", ValorRemovido);
    PercursoPreOrdem(arvore);
    printf ("\n\n");

    printf("impressão em ordem após o elemento (%d) ser removido \n", ValorRemovido);
    PercursoOrdem(arvore);
    printf ("\n\n");

    printf("impressão em pós ordem após o elemento (%d) ser removido \n", ValorRemovido);
    PercursoPosOrdem(arvore);
    printf ("\n\n");

    return 1;
}