#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <time.h>


void mostrarMatriz(int M[6][6]){

    int i, j;

    printf("    0 1 2 3 4 5\n\n");
    for(i=0; i<6; i++){
        printf("%d   ", i);
        for(j=0; j<6; j++){
            if(M[i][j] == 0){
                printf("? ");
            }else if(M[i][j] == 1){
                printf("~ ");
            }else if(M[i][j] == 2){
                printf("O ");
            }else if(M[i][j] == 3){
                printf("X ");
            }
        }
        printf("\n");
    }
}

void mostrarAtaque(int M[6][6]){

    int i, j;

    printf("    0 1 2 3 4 5\n\n");
    for(i=0; i<6; i++){
        printf("%d   ", i);
        for(j=0; j<6; j++){
            if(M[i][j] == 0 || M[i][j] == 2){
                printf("? ");
            }else if(M[i][j] == 1){
                printf("~ ");
            }else if(M[i][j] == 3){
                printf("X ");
            }
        }
        printf("\n");
    }
}

int main(){

    int M[6][6]={0};
    int P[6][6]={0};
    int i, j, x, y, l, m, t, q, z, w, anteriorT=0, anteriorQ=0;
    srand((unsigned) time(NULL));

    printf("Bem vindo ao jogo batalha naval =)\n\n");

    //mostra o tabuleiro do computador
    printf("esse eh o tabuleiro onde os barcos do computador estarao posicionados\n\n");

    mostrarMatriz(M);

    printf("\n");

    //mostra o tabuleiro do jogador
    printf("esse eh o tabuleiro onde os seus barcos estarao posicionados\n\n");

    mostrarMatriz(P);

    printf("\n");

    //sorteia as posições dos barcos do computador
    for(i=0; i<4; i++){
        do
        {
            l = rand()%6;
            m = rand()%6;
        }while(M[l][m]==2);
        M[l][m] = 2;
        //printf("M[%d][%d] \n\n", l, m); //gabarito
    }

    //jogador posiciona seus barcos
    printf("Escolha as posicoes que seus barcos ficarao\n\n");
    for(i=0; i<4; i++){
        scanf("%d%d", &z, &w);
        P[z][w] = 2;
    }

    printf("Chegou a hora de atacar!\n\n");

    for(i=0; i<8; i++){
        scanf("%d%d", &x, &y);
        M[x][y]++;
        printf("esse eh o tabuleiro do computador\n\n");
        mostrarAtaque(M);

        do{
            t = rand()%6;
            q = rand()%6;
        }while(P[t][q] == 1 || P[t][q] == 3);
        P[t][q]++;
        printf("esse eh seu tabuleiro\n\n");
        mostrarAtaque(P);

        printf("\n");
        system("pause");
        system("cls");
        if(i!=7){
            printf("ataque de novo\n");
        }
    }

     //mostra o tabuleiro do computador
    printf("Esse eh como ficou o tabuleiro do computador\n\n");

    mostrarMatriz(M);

    printf("\n");

     //mostra o tabuleiro do jogador
    printf("Esse eh como ficou o seu tabuleiro\n\n");

    mostrarMatriz(P);

    printf("\n");

    printf(" ~ atirou mas nao acertou em nada\n");
    printf(" O ainda ha um barco ali\n");
    printf(" X atirou e acertou um barco, PARABENS\n");

}
