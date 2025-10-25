#include <stdio.h>

#define TAMANHO_TABULEIRO 10     // Tamanho fixo do tabuleiro
#define TAMANHO_NAVIO 3          // Tamanho fixo dos navios
#define VALOR_AGUA 0             // Representa água no tabuleiro
#define VALOR_NAVIO 3            // Representa parte de navio no tabuleiro

int main() {
    // Declaração da matriz do tabuleiro
    int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO];

    // Inicializa todas as posições com água (valor 0)
    for (int linha = 0; linha < TAMANHO_TABULEIRO; linha++) {
        for (int coluna = 0; coluna < TAMANHO_TABULEIRO; coluna++) {
            tabuleiro[linha][coluna] = VALOR_AGUA;
        }
    }

    // Vetores representando os navios (valores 3)
    int navioHorizontal[TAMANHO_NAVIO] = {VALOR_NAVIO, VALOR_NAVIO, VALOR_NAVIO};
    int navioVertical[TAMANHO_NAVIO] = {VALOR_NAVIO, VALOR_NAVIO, VALOR_NAVIO};

    // Coordenadas iniciais dos navios (definidas diretamente no código)
    int linhaHorizontal = 2;
    int colunaHorizontal = 4;

    int linhaVertical = 5;
    int colunaVertical = 7;

    // Validação: verifica se os navios cabem no tabuleiro
    if (colunaHorizontal + TAMANHO_NAVIO > TAMANHO_TABULEIRO ||
        linhaVertical + TAMANHO_NAVIO > TAMANHO_TABULEIRO) {
        printf("Erro: coordenadas inválidas para posicionar os navios.\n");
        return 1;
    }

    // Validação simplificada de sobreposição
    for (int i = 0; i < TAMANHO_NAVIO; i++) {
        if (linhaHorizontal == linhaVertical + i &&
            colunaHorizontal + i == colunaVertical) {
            printf("Erro: os navios estão se sobrepondo.\n");
            return 1;
        }
    }

    // Posiciona navio horizontal no tabuleiro
    for (int i = 0; i < TAMANHO_NAVIO; i++) {
        tabuleiro[linhaHorizontal][colunaHorizontal + i] = navioHorizontal[i];
    }

    // Posiciona navio vertical no tabuleiro
    for (int i = 0; i < TAMANHO_NAVIO; i++) {
        tabuleiro[linhaVertical + i][colunaVertical] = navioVertical[i];
    }

    // Exibe o tabuleiro no console
    printf("\nTabuleiro de Batalha Naval:\n\n");
    for (int linha = 0; linha < TAMANHO_TABULEIRO; linha++) {
        for (int coluna = 0; coluna < TAMANHO_TABULEIRO; coluna++) {
            printf("%d ", tabuleiro[linha][coluna]);
        }
        printf("\n");
    }

    return 0;
}