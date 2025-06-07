#include <stdio.h>

// Desafio Batalha Naval - MateCheck
// Este código inicial serve como base para o desenvolvimento do sistema de Batalha Naval.
// Siga os comentários para implementar cada parte do desafio.

// int main() {
    // Nível Novato - Posicionamento dos Navios
    // Sugestão: Declare uma matriz bidimensional para representar o tabuleiro (Ex: int tabuleiro[5][5];).
    // Sugestão: Posicione dois navios no tabuleiro, um verticalmente e outro horizontalmente.
    // Sugestão: Utilize `printf` para exibir as coordenadas de cada parte dos navios.

    // Nível Aventureiro - Expansão do Tabuleiro e Posicionamento Diagonal
    // Sugestão: Expanda o tabuleiro para uma matriz 10x10.
    // Sugestão: Posicione quatro navios no tabuleiro, incluindo dois na diagonal.
    // Sugestão: Exiba o tabuleiro completo no console, mostrando 0 para posições vazias e 3 para posições ocupadas.

    // Nível Mestre - Habilidades Especiais com Matrizes
    // Sugestão: Crie matrizes para representar habilidades especiais como cone, cruz, e octaedro.
    // Sugestão: Utilize estruturas de repetição aninhadas para preencher as áreas afetadas por essas habilidades no tabuleiro.
    // Sugestão: Exiba o tabuleiro com as áreas afetadas, utilizando 0 para áreas não afetadas e 1 para áreas atingidas.

    // Exemplos de exibição das habilidades:
    // Exemplo para habilidade em cone:
    // 0 0 1 0 0
    // 0 1 1 1 0
    // 1 1 1 1 1
    
    // Exemplo para habilidade em octaedro:
    // 0 0 1 0 0
    // 0 1 1 1 0
    // 0 0 1 0 0

    // Exemplo para habilidade em cruz:
    // 0 0 1 0 0
    // 1 1 1 1 1
    // 0 0 1 0 0

//    return 0;

// --- Definições de Constantes ---
#define TAMANHO_TABULEIRO 10 // Define o tamanho do tabuleiro (10x10)
#define TAMANHO_NAVIO 3      // Define o tamanho fixo dos navios
#define AGUA 0               // Valor que representa a água no tabuleiro
#define NAVIO 3              // Valor que representa uma parte de um navio no tabuleiro

// --- Função para Exibir o Tabuleiro ---
// Parâmetros:
//   tabuleiro: Uma matriz bidimensional que representa o estado atual do tabuleiro.
// Retorno: void (não retorna valor).
// Objetivo: Imprimir o tabuleiro no console de forma organizada, mostrando as posições dos navios e da água.
void exibirTabuleiro(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO]) {
    // Imprime os cabeçalhos das colunas para facilitar a leitura do tabuleiro
    printf("  "); // Espaço para alinhar com os números das linhas
    for (int col = 0; col < TAMANHO_TABULEIRO; col++) {
        printf("%d ", col); // Imprime o índice da coluna
    }
    printf("\n"); // Nova linha após os cabeçalhos das colunas

    // Percorre cada linha do tabuleiro
    for (int i = 0; i < TAMANHO_TABULEIRO; i++) {
        printf("%d ", i); // Imprime o índice da linha atual
        // Percorre cada coluna na linha atual
        for (int j = 0; j < TAMANHO_TABULEIRO; j++) {
            printf("%d ", tabuleiro[i][j]); // Imprime o valor da célula (0 para água, 3 para navio)
        }
        printf("\n"); // Nova linha após imprimir todas as células de uma linha
    }
    printf("\n"); // Espaço adicional para separar o tabuleiro de outras saídas
}

// --- Função Principal do Programa ---
int main() {
    // 1. Representação do Tabuleiro: Matriz 10x10
    int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO];

    // Inicializa todas as posições do tabuleiro com AGUA (0)
    for (int i = 0; i < TAMANHO_TABULEIRO; i++) {
        for (int j = 0; j < TAMANHO_TABULEIRO; j++) {
            tabuleiro[i][j] = AGUA;
        }
    }

    // 2. Posicionamento dos Navios: Coordenadas iniciais definidas no código
    // Navio 1: Posicionado horizontalmente
    int navio1_linha_inicial = 2; // Linha de início do navio horizontal
    int navio1_coluna_inicial = 3; // Coluna de início do navio horizontal

    // Navio 2: Posicionado verticalmente
    int navio2_linha_inicial = 5; // Linha de início do navio vertical
    int navio2_coluna_inicial = 1; // Coluna de início do navio vertical

    // Variável de controle para erros de posicionamento (limites ou sobreposição)
    int erro_posicionamento_navio1 = 0;
    int erro_posicionamento_navio2 = 0;

    // --- Posicionar Navio 1 (Horizontal) ---
    printf("Tentando posicionar Navio 1 (Horizontal) em (%d, %d)...\n", navio1_linha_inicial, navio1_coluna_inicial);
    // Validação de limites para o Navio 1
    if (navio1_linha_inicial < 0 || navio1_linha_inicial >= TAMANHO_TABULEIRO ||
        navio1_coluna_inicial < 0 || (navio1_coluna_inicial + TAMANHO_NAVIO) > TAMANHO_TABULEIRO) {
        printf("Erro: Posicao inicial do Navio 1 (horizontal) fora dos limites do tabuleiro.\n");
        erro_posicionamento_navio1 = 1;
    } else {
        // Verifica sobreposição antes de posicionar o Navio 1
        for (int j = 0; j < TAMANHO_NAVIO; j++) {
            if (tabuleiro[navio1_linha_inicial][navio1_coluna_inicial + j] == NAVIO) {
                printf("Erro: Sobreposicao detectada para o Navio 1 (horizontal) em (%d, %d).\n",
                       navio1_linha_inicial, navio1_coluna_inicial + j);
                erro_posicionamento_navio1 = 1;
                break; // Sai do loop de verificação de sobreposição
            }
        }
        // Se não houve erro de limite ou sobreposição, posiciona o navio
        if (!erro_posicionamento_navio1) {
            for (int j = 0; j < TAMANHO_NAVIO; j++) {
                tabuleiro[navio1_linha_inicial][navio1_coluna_inicial + j] = NAVIO;
            }
            printf("Navio 1 (Horizontal) posicionado com sucesso.\n");
        }
    }

    // --- Posicionar Navio 2 (Vertical) ---
    printf("Tentando posicionar Navio 2 (Vertical) em (%d, %d)...\n", navio2_linha_inicial, navio2_coluna_inicial);
    // Validação de limites para o Navio 2
    if (navio2_linha_inicial < 0 || (navio2_linha_inicial + TAMANHO_NAVIO) > TAMANHO_TABULEIRO ||
        navio2_coluna_inicial < 0 || navio2_coluna_inicial >= TAMANHO_TABULEIRO) {
        printf("Erro: Posicao inicial do Navio 2 (vertical) fora dos limites do tabuleiro.\n");
        erro_posicionamento_navio2 = 1;
    } else {
        // Verifica sobreposição antes de posicionar o Navio 2
        for (int i = 0; i < TAMANHO_NAVIO; i++) {
            if (tabuleiro[navio2_linha_inicial + i][navio2_coluna_inicial] == NAVIO) {
                printf("Erro: Sobreposicao detectada para o Navio 2 (vertical) em (%d, %d).\n",
                       navio2_linha_inicial + i, navio2_coluna_inicial);
                erro_posicionamento_navio2 = 1;
                break; // Sai do loop de verificação de sobreposição
            }
        }
        // Se não houve erro de limite ou sobreposição, posiciona o navio
        if (!erro_posicionamento_navio2) {
            for (int i = 0; i < TAMANHO_NAVIO; i++) {
                tabuleiro[navio2_linha_inicial + i][navio2_coluna_inicial] = NAVIO;
            }
            printf("Navio 2 (Vertical) posicionado com sucesso.\n");
        }
    }

    // 3. Exibir o Tabuleiro Final
    printf("\n--- Tabuleiro de Batalha Naval Final ---\n");
    exibirTabuleiro(tabuleiro);

    return 0; // Indica que o programa foi executado com sucesso
}