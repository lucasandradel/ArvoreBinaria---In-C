#include "ArvoreBin.h"

tipo_arv_bin *AlocaNo(int vl){
    tipo_arv_bin *novo_no;
    novo_no = (tipo_arv_bin*) malloc(sizeof(tipo_arv_bin));
    novo_no -> valor = vl;
    novo_no -> esq = NULL;
    novo_no -> dir = NULL;
    return novo_no;
}

void InsereArvBin(tipo_arv_bin**arv , int valor ){
    if ((*arv) == NULL){//se não houver ninguguém na minha arvore, alocar um novo valor usando a função "AlocaNo"
        (*arv) = AlocaNo(valor);//Função "AlocaNo" para aderir um valor caso a arvore esteja vazia 

    }else{// se minha arvore não está vazia faça:
        if (valor < (*arv) -> valor){ //verifica se o valor que quero inserir é menor ou maior que o elemento 
            InsereArvBin(&(*arv) -> esq, valor);//se for menor, chama função recursiva e insere no ramo da esquerda
        }else{
            InsereArvBin (&(*arv)-> dir, valor);//senão for menor, chama função recursiva e insere no ramo da direita
        }
        
    }
   
}

//função que percore em pré ordem
/*
Passos:
-Imprimir
-Chamar recursão a esquerda
-Chamar recursão a direita
*/
void PercursoPreOrdem(tipo_arv_bin *arv){
    if (arv != NULL){
        printf (" %d ",  arv -> valor );
        PercursoPreOrdem(arv ->esq);
        PercursoPreOrdem(arv ->dir);
    }
}   

//função que percorre em ordem
/*
Passos:
-Chamar recursão a esquerda
-Imprimir
-Chamar recursão a direita
*/
void PercursoOrdem(tipo_arv_bin *arv){
    if (arv != NULL){
        PercursoOrdem(arv -> esq);
        printf(" %d ", arv -> valor);
        PercursoOrdem(arv -> dir);

    }
}

//função que percorre em pós ordem
/*
Passos:
-Chamar recursão a esquerda
-Chamar recursão a direita
-Imprimir
*/
void PercursoPosOrdem(tipo_arv_bin *arv){
    if (arv != NULL){
        PercursoPosOrdem(arv -> esq);
        PercursoPosOrdem(arv -> dir);
        printf(" %d ", arv -> valor);
        

    }
}

tipo_arv_bin *BuscaValor(tipo_arv_bin *arv, int valor ){
    if ((arv == NULL) || (arv -> valor == valor)){// verifica se a raiz é igual a nulo ou a raiz já é meu valor 
        return arv;//se for, retornar raiz 
    }
    //se não for o valor da raiz:
    if (valor < arv -> valor){
        BuscaValor(arv -> esq, valor);
    }else{
        BuscaValor (arv -> dir, valor);
    }
}

//Função que retorna a altura da árvore binária
/*

- Declarar duas variáveis para armazenar a quantidade de nós que tem na esquerda e na direita

- verificar se a raiz é nula, se for, retornar -1, se não, fazer duas chamadas recursiva da função altura, para esquerda e para a direita da árvore,
- comparar as duas variáveis esquerda e direita que foram armazenadas o valor e retornar a que for mais + 1
*/
int AlturaArvBin(tipo_arv_bin*arv){
    int esquerda, direita;

    if (arv == NULL){
        return -1;

    }else{
        esquerda = AlturaArvBin(arv -> esq);
        direita = AlturaArvBin (arv -> dir);
        if (esquerda > direita){

            return esquerda + 1;
        }else{
            return direita +1;
        }

    }
}

//Função que retorna a quantidade de nós da árvore binária
int ContabilizaNosArvBin(tipo_arv_bin* arv){
    if (arv == NULL){
        return 0;

    }else{
        return 1 + ContabilizaNosArvBin(arv -> esq) + ContabilizaNosArvBin (arv -> dir);
    }
}

//Função que retorna a quantidade de nós folhas da árvore binária
int ContabilizaNosFolhasArvBin(tipo_arv_bin* arv ){
    if (arv == NULL){
        return 0;
    }else if((arv -> esq == NULL) && (arv -> dir == NULL)){
        return 1;
    }else{
        return ContabilizaNosFolhasArvBin(arv -> esq) + ContabilizaNosFolhasArvBin (arv -> dir);
    }


}   

int ImprimeNivelArvBin(tipo_arv_bin* arv, int nivel, int contador) {
    if (arv == NULL) {
        return 0 ;
    }

    int vl = arv->valor;
    if (contador == nivel) {
        printf("%d ", vl);
    }

    // Chama recursivamente para os nós filhos com contador incrementado
    ImprimeNivelArvBin(arv->esq, nivel, contador + 1);
    ImprimeNivelArvBin(arv->dir, nivel, contador + 1);
}


int RemoveArvBin(tipo_arv_bin*, int);

