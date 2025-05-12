#include <stdio.h>

#define TAMANHO_TABULEIRO 10
#define TAMANHO_NAVIO 3
#define NAVIO 3
#define AGUA 0

// Função para exibir o tabuleiro no console
void exibirTabuleiro(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO]) {
    printf("  ");
    for (int c = 0; c < TAMANHO_TABULEIRO; c++) {
        printf("%d ", c);
    }
    printf("\n");
    for (int i = 0; i < TAMANHO_TABULEIRO; i++) {
        printf("%d ", i);
        for (int j = 0; j < TAMANHO_TABULEIRO; j++) {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }
}

int main() {
    // Inicializa o tabuleiro com água (0)
    int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO] = {0};

    // Definição das coordenadas iniciais
    int linhaNavioHorizontal = 2;
    int colunaNavioHorizontal = 4;
    int linhaNavioVertical = 5;
    int colunaNavioVertical = 7;

    // Verificação se os navios cabem no tabuleiro
    if (colunaNavioHorizontal + TAMANHO_NAVIO <= TAMANHO_TABULEIRO &&
        linhaNavioVertical + TAMANHO_NAVIO <= TAMANHO_TABULEIRO) {

        // Verificação de sobreposição (simplificada)
        int sobreposicao = 0;
        for (int i = 0; i < TAMANHO_NAVIO; i++) {
            if (tabuleiro[linhaNavioHorizontal][colunaNavioHorizontal + i] == NAVIO ||
                tabuleiro[linhaNavioVertical + i][colunaNavioVertical] == NAVIO) {
                sobreposicao = 1;
                break;
            }
        }

        if (!sobreposicao) {
            // Posiciona o navio horizontal
            for (int i = 0; i < TAMANHO_NAVIO; i++) {
                tabuleiro[linhaNavioHorizontal][colunaNavioHorizontal + i] = NAVIO;
            }

            // Posiciona o navio vertical
            for (int i = 0; i < TAMANHO_NAVIO; i++) {
                tabuleiro[linhaNavioVertical + i][colunaNavioVertical] = NAVIO;
            }

            // Exibe o tabuleiro
            exibirTabuleiro(tabuleiro);
        } else {
            printf("Erro: Sobreposição de navios detectada.\n");
        }
    } else {
        printf("Erro: Coordenadas inválidas. Os navios não cabem no tabuleiro.\n");
    }

    return 0;
}