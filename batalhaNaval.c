#include <stdio.h>
#include <string.h>

#define TAM 10
#define TAM_HAB 5  // Tamanho fixo das matrizes de habilidade (5x5)

int tabuleiro[TAM][TAM];

// Função para inicializar o tabuleiro com água (0)
void inicializarTabuleiro() {
    for (int i = 0; i < TAM; i++) {
        for (int j = 0; j < TAM; j++) {
            tabuleiro[i][j] = 0;
        }
    }
}

// Função para posicionar navios (valor 3)
void posicionarNavios() {
    // Horizontal
    tabuleiro[1][2] = 3;
    tabuleiro[1][3] = 3;
    tabuleiro[1][4] = 3;

    // Vertical
    tabuleiro[4][6] = 3;
    tabuleiro[5][6] = 3;
    tabuleiro[6][6] = 3;

    // Diagonal principal (↘)
    tabuleiro[2][2] = 3;
    tabuleiro[3][3] = 3;
    tabuleiro[4][4] = 3;

    // Diagonal secundária (↙)
    tabuleiro[5][5] = 3;
    tabuleiro[6][4] = 3;
    tabuleiro[7][3] = 3;
}

// Cria matriz de habilidade em forma de cone
void criarHabilidadeCone(int matriz[TAM_HAB][TAM_HAB]) {
    memset(matriz, 0, sizeof(int) * TAM_HAB * TAM_HAB);
    for (int i = 0; i < TAM_HAB; i++) {
        for (int j = 0; j < TAM_HAB; j++) {
            if (j >= TAM_HAB / 2 - i && j <= TAM_HAB / 2 + i) {
                matriz[i][j] = 1;
            }
        }
    }
}

// Cria matriz de habilidade em forma de cruz
void criarHabilidadeCruz(int matriz[TAM_HAB][TAM_HAB]) {
    memset(matriz, 0, sizeof(int) * TAM_HAB * TAM_HAB);
    for (int i = 0; i < TAM_HAB; i++) {
        for (int j = 0; j < TAM_HAB; j++) {
            if (i == TAM_HAB / 2 || j == TAM_HAB / 2) {
                matriz[i][j] = 1;
            }
        }
    }
}

// Cria matriz de habilidade em forma de octaedro (losango)
void criarHabilidadeOctaedro(int matriz[TAM_HAB][TAM_HAB]) {
    memset(matriz, 0, sizeof(int) * TAM_HAB * TAM_HAB);
    for (int i = 0; i < TAM_HAB; i++) {
        for (int j = 0; j < TAM_HAB; j++) {
            if (abs(i - TAM_HAB / 2) + abs(j - TAM_HAB / 2) <= TAM_HAB / 2) {
                matriz[i][j] = 1;
            }
        }
    }
}

// Sobrepõe uma matriz de habilidade ao tabuleiro (usa valor 5)
void aplicarHabilidade(int matriz[TAM_HAB][TAM_HAB], int origemX, int origemY) {
    for (int i = 0; i < TAM_HAB; i++) {
        for (int j = 0; j < TAM_HAB; j++) {
            if (matriz[i][j] == 1) {
                int x = origemX + i - TAM_HAB / 2;
                int y = origemY + j - TAM_HAB / 2;
                if (x >= 0 && x < TAM && y >= 0 && y < TAM && tabuleiro[x][y] == 0) {
                    tabuleiro[x][y] = 5;
                }
            }
        }
    }
}

// Exibe o tabuleiro com legenda
void exibirTabuleiro() {
    printf("\nLegenda: 0 = Água | 3 = Navio | 5 = Área de Habilidade\n\n");
    for (int i = 0; i < TAM; i++) {
        for (int j = 0; j < TAM; j++) {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int cone[TAM_HAB][TAM_HAB];
    int cruz[TAM_HAB][TAM_HAB];
    int octaedro[TAM_HAB][TAM_HAB];

    inicializarTabuleiro();
    posicionarNavios();

    criarHabilidadeCone(cone);
    criarHabilidadeCruz(cruz);
    criarHabilidadeOctaedro(octaedro);

    aplicarHabilidade(cone, 2, 7);       // Cone com origem em (2,7)
    aplicarHabilidade(cruz, 6, 2);       // Cruz com origem em (6,2)
    aplicarHabilidade(octaedro, 8, 8);   // Octaedro com origem em (8,8)

    exibirTabuleiro();

    return 0;
}