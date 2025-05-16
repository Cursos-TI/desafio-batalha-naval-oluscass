#include <stdio.h>

#define TAMANHO 10
#define NAVIO 3
#define TAM_NAVIO 3

// Função para verificar se a posição está dentro dos limites e livre
int podePosicionar(int tabuleiro[TAMANHO][TAMANHO], int linha, int coluna, int deltaLinha, int deltaColuna) {
    for (int i = 0; i < TAM_NAVIO; i++) {
        int l = linha + i * deltaLinha;
        int c = coluna + i * deltaColuna;
        if (l < 0 || l >= TAMANHO || c < 0 || c >= TAMANHO) return 0;
        if (tabuleiro[l][c] != 0) return 0;
    }
    return 1;
}

// Função para posicionar o navio
void posicionarNavio(int tabuleiro[TAMANHO][TAMANHO], int linha, int coluna, int deltaLinha, int deltaColuna) {
    for (int i = 0; i < TAM_NAVIO; i++) {
        tabuleiro[linha + i * deltaLinha][coluna + i * deltaColuna] = NAVIO;
    }
}

int main() {
    int tabuleiro[TAMANHO][TAMANHO] = {0};

    // 1º navio horizontal (da esquerda para direita)
    int linha1 = 1, coluna1 = 2;
    if (podePosicionar(tabuleiro, linha1, coluna1, 0, 1)) {
        posicionarNavio(tabuleiro, linha1, coluna1, 0, 1);
    }

    // 2º navio vertical (de cima para baixo)
    int linha2 = 4, coluna2 = 5;
    if (podePosicionar(tabuleiro, linha2, coluna2, 1, 0)) {
        posicionarNavio(tabuleiro, linha2, coluna2, 1, 0);
    }

    // 3º navio diagonal principal (↘)
    int linha3 = 0, coluna3 = 0;
    if (podePosicionar(tabuleiro, linha3, coluna3, 1, 1)) {
        posicionarNavio(tabuleiro, linha3, coluna3, 1, 1);
    }

    // 4º navio diagonal secundária (↙)
    int linha4 = 2, coluna4 = 7;
    if (podePosicionar(tabuleiro, linha4, coluna4, 1, -1)) {
        posicionarNavio(tabuleiro, linha4, coluna4, 1, -1);
    }

    // Exibindo o tabuleiro
    printf("Tabuleiro Batalha Naval 10x10:\n\n");
    for (int i = 0; i < TAMANHO; i++) {
        for (int j = 0; j < TAMANHO; j++) {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }

    return 0;
}