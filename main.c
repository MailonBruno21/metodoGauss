#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#define MAX 100

void imprimiResultado(double resultado[MAX],int quantElement){
    printf("\n\nRESULTADOS\n ");
    for(int i = 0;i < quantElement; i++){
        printf("%.2lf ", resultado[i]);
    }
}

void imprimiMatrizAumentada(double matriz[MAX][MAX], double b[MAX], int quantElement){
    for(int i = 0; i < quantElement; i++){
        printf("|");
        for(int j = 0; j < quantElement; j++){
            printf("%.2lf ", matriz[i][j]);
        }
        printf("| %.2lf |\n", b[i]);
    }

}

void eliminacaoIngenuaGauss(double matriz[MAX][MAX], double b[MAX], int quantElement){
    double constantes[quantElement];
    for(int i = 0; i < quantElement; i++){
        for(int j = i; j < quantElement-1; j++){
            constantes[j] = matriz[j+1][i]/matriz[i][i];
        }
        for(int k = i; k < quantElement; k++){
            for(int j = 0; j < quantElement;j++){
            matriz[k+1][j]= matriz[k+1][j]-(constantes[k]*matriz[i][j]);
            }
            b[k+1]=b[k+1]-(constantes[k]*b[i]);
        }
    }
    system("cls");
    imprimiMatrizAumentada(matriz,b,quantElement);
    system("pause");

}

void substituicaoRegreciva(double matriz[MAX][MAX], double b[MAX], int quantElement){
    double resultado[quantElement];

    for(int i =0; i<quantElement;i++){
        resultado[i]=0;
    }

    resultado[quantElement-1] = b[quantElement-1] / matriz[quantElement-1][quantElement-1];

    for(int i = quantElement -2 ; i >= 0; i--){
        for(int j = quantElement-1; j > i; j--){
                if(matriz[i][j] == 0){
                    continue;
                }else{
                    matriz[i][j] = matriz[i][j] * resultado[j];
                }
        }
        for(int j = 0; j < quantElement; j++){
            if(i != j){
                if(matriz[i][j] !=0){
                    resultado[i] = resultado[i] + (matriz[i][j]* -1);
                }
            }
        }
        resultado[i] = (b[i]+resultado[i])/matriz[i][i];
    }

    imprimiResultado(resultado,quantElement);
}
int main(){
    setlocale(LC_ALL,"");

    int quantElement;
    double matriz[MAX][MAX], b[MAX];

    printf("-------- ATENÇÃO --------\n\n");
    printf("A NOTAÇÃO A11, A12 , ...\n");
    printf("REPRESENTA AS VARIAVEIS DO SISTEMA\n\n");
    printf("-------------------------\n\n\n");

    system("pause");
    system("cls");

    printf("INSIRA A QUANTIDADE DE ELEMENTOS DA EQUAÇÃO (1 ATÉ 100): ");
    scanf("%d", &quantElement);

    system("cls");
    printf("DÍGITE OS VALORES DO SISTEMA LINEAR\n\n");

    for(int i = 0; i < quantElement; i++){
            for(int j = 0; j < quantElement; j++){
                printf("A%d%d = ",i+1,j+1);
                scanf("%lf",&matriz[i][j]);
                if(i == j && matriz[i][j] == 0){
                    printf("MATRIZ COM PIVO NULO");
                    return -1;
                }
            }
            printf("B%d = ",i+1);
            scanf("%lf",&b[i]);
            system("cls");
    }

    imprimiMatrizAumentada(matriz,b,quantElement);
    eliminacaoIngenuaGauss(matriz,b,quantElement);
    substituicaoRegreciva(matriz,b,quantElement);
    return 0;
}
