#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int e,t;
char s[4];

int main()
{
    int opcao = 9;
    setlocale (LC_ALL, "portuguese"); t=0; strcpy(s,"off");

    while (opcao != 0) {
        e = 64;
        system("cls");
        printf("\nDigite sua opção : \n");
        printf("\n1 - Fatorial");
        printf("\n2 - Somatório de n números naturais");
        printf("\n3 - Somatório dos números de um vetor");
        printf("\n4 - Calcular o eNéssimo número de Fibonacci");
        printf("\n5 - Soma de dois números inteiros não negativos");
        printf("\n    usando apenas incrementos e decrementos unitários");
        printf("\n6 - Multiplicação de dois números inteiros positivos");
        printf("\n    usando apenas somas ou subtrações");
        printf("\n7 - Soma de todos os inteiros positivos pares menores");
        printf("\n    ou iguais a um valor inteiro n");
        printf("\n8 - Torres de Hanoi");
        printf("\n\n9 - trace : status %s",s);
        printf("\n0 - fim\n");
        scanf("%d",&opcao);
        if (opcao == 1) runFatorial();
        if (opcao == 2) runSomatorio();
        if (opcao == 3) runSomaVetor();
        if (opcao == 4) runFibonacci();
        if (opcao == 5) runPassoUnitario();
        if (opcao == 6) runMultiplicacao();
        if (opcao == 7) runSomaPares();
        if (opcao == 8) runTorres();

        if (opcao == 9) {
            if (t == 0) { t = 1; strcpy(s,"on");}
            else { t = 0; strcpy(s,"off");}
        } else { printf("\n\n"); system("pause"); }
    }
    return 0;
}

void runFatorial() {
    int x;
    system("cls");
    printf("\nExecutando Fatorial - trace : status %s\n",s);
    printf("\nDigite o numero que deseja calcular o fatorial :\n");
    scanf("%d",&x);
    printf("\n\nResultado do fatorial de %d é %d",x,fatorial(x));
}

int fatorial(int n) {
    /* linha para fazer o trace */ int r; e++; r=e; if ( t == 1 ) printf("\n\nrun %c : Fatorial(%d)",r,n);

    int aux;

    if (n == 1) {
        aux = 1;
        /* linha para fazer o trace */ if ( t == 1 ) printf("\nrun %c : vou retornar 1 pois é o fim da recursividade\n",r);
    }
    else {
        /* linha para fazer o trace */ if ( t == 1 ) printf("\nrun %c : vou calcular N vezes N-1",r);
        aux = fatorial(n-1);
        /* linha para fazer o trace */ if ( t == 1 ) printf("\nrun %c : N=%d e N-1=%d ",r,n,aux);
        aux = n * aux;
        /* linha para fazer o trace */ if ( t == 1 ) printf(" e o resultado de N*N-1 = %d",aux);
        /* linha para fazer o trace */ if ( t == 1 ) printf("\nrun %c : vou encerrar retornando %d\n",r,aux);
    }
    return aux;
}

void runSomatorio() {
    int x;
    system("cls");
    printf("\nExecutando Somatório de n números naturais - trace : status %s\n",s);
    printf("\nDigite o numero que deseja calcular o somatorio :\n");
    scanf("%d",&x);
    printf("\n\nResultado do somatorio até o número %d é %d",x,somatorio(x));
}

int somatorio(int n) {
    /* linha para fazer o trace */ int r; e++; r=e; if ( t == 1 ) printf("\n\nrun %c : Fatorial(%d)",r,n);

    int aux;

    if (n == 1) {
        aux = 1;
        /* linha para fazer o trace */ if ( t == 1 ) printf("\nrun %c : vou retornar 1 pois é o fim da recursividade\n",r);
    }
    else {
        /* linha para fazer o trace */ if ( t == 1 ) printf("\nrun %c : vou calcular N mais N-1",r);
        aux = somatorio(n-1);
        /* linha para fazer o trace */ if ( t == 1 ) printf("\nrun %c : N=%d e N-1=%d ",r,n,aux);
        aux = n + aux;
        /* linha para fazer o trace */ if ( t == 1 ) printf(" e o resultado de N+N-1 = %d",aux);
        /* linha para fazer o trace */ if ( t == 1 ) printf("\nrun %c : vou encerrar retornando %d\n",r,aux);
    }
    return aux;
}

void runSomaVetor() {
    int v[99]; int t;
    system("cls");
    printf("\nExecutando Somatório dos números de um vetor");
    printf("\nQual o tamanho do vetor :\n");
    scanf("%d",&t);
    for (int i=0; i<t;i++) {
        printf("\nDigite o elemento %d :\n",i);
        scanf("%d",&v[i]);
    }
    printf("\n\nResultado do somatorio foi de %d ",somaVetor(v,t));
}

int somaVetor(int v[], int n) {

    int aux;

    if (n == 0)
        aux = 0;
    else {
        aux = v[n-1] + somaVetor(v,n-1);
    }

    return aux;
}


void runFibonacci() {
    int x;
    system("cls");
    printf("\nCalcular o eNéssimo número de Fibonacci");
    printf("\nQual o elemento :\n");
    scanf("%d",&x);
    printf("\n\no eNéssimo número de Fibonacci é %d ",fibonacci(x));
}

int fibonacci(int  n) {

    int aux;

    if (n == 1 || n == 2)
        aux = 1;
    else {
        aux = fibonacci(n-1) + fibonacci(n-2) ;
    }

    return aux;
}

void runPassoUnitario() {
    int x,y;
    system("cls");
    printf("\nSoma de dois números inteiros não negativos");
    printf("\n     usando apenas incrementos e decrementos unitários");
    printf("\nDigite os dois numeros a serem somandos :\n");
    scanf("%d %d",&x,&y);
    printf("\n\nResultado da soma é %d ",passoUnitario(x,y));
}

int passoUnitario(int x, int y) {

    int aux;

    if (y == 0)
        aux = x;
    else {
        aux = passoUnitario(x+1,y-1) ;
    }

    return aux;
}

void runMultiplicacao() {
    int x,y;
    system("cls");
    printf("\nMultiplicação de dois números inteiros positivos");
    printf("\n              usando apenas somas ou subtrações");
    printf("\nDigite os dois numeros a serem multiplicados :\n");
    scanf("%d %d",&x,&y);
    printf("\n\nResultado da multiplicacao é %d ",multiplicacao(x,y));
}

int multiplicacao(int x, int y) {

    int aux;

    if (y == 1)
        aux = x;
    else {
        aux = x + multiplicacao(x,y-1) ;
    }

    return aux;
}

void runSomaPares() {
    int x,y;
    system("cls");
        printf("\nSoma de todos os inteiros positivos pares menores");
        printf("\n     ou iguais a um valor inteiro n");
    printf("\nDigite o número desejado :\n");
    scanf("%d",&x);
    printf("\n\nResultado da soma é %d ",somaPares(x));
}

int somaPares(int x) {

    int aux;

    if (x == 0)
        aux = 0;
    else {
        if ( x % 2 == 0)
            aux = x + somaPares(x - 2);
        else
            aux = somaPares(x - 1);
    }

    return aux;
}

void runTorres() {
    int x,y;
    system("cls");
    printf("\nTorres de Hanoi");

    printf("\nDigite a quantidade de discos :\n");
    scanf("%d",&x);
    printf("\n--- lista dos movimentos ---\n");
    torres(x,'A','C','B');
}

void torres(int disco, char inicio, char fim, char auxiliar) {

    if (disco == 1)
        printf("\nmova o disco %d do pino %c para o pino %c",disco,inicio,fim);
    else {
        torres(disco-1,inicio,auxiliar,fim);
        printf("\nmova o disco %d do pino %c para o pino %c",disco,inicio,fim);
        torres(disco-1,auxiliar, fim, inicio);
    }

    return;
}



