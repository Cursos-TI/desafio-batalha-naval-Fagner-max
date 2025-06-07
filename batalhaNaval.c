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

#include <stdlib.h> // Inclui a biblioteca padrão para funções como abs (usada para o octaedro)

// --- Definições de Constantes ---
#define TAMANHO_TABULEIRO 10 // Define o tamanho do tabuleiro (10x10)
#define TAMANHO_NAVIO 3      // Define o tamanho fixo dos navios
#define AGUA 0               // Valor que representa a água no tabuleiro
#define NAVIO 3              // Valor que representa uma parte de um navio no tabuleiro
#define HABILIDADE_AFETADA 5 // Novo valor para representar uma posição afetada por uma habilidade

// Tamanho das matrizes de habilidade (ex: 7x7 para permitir formas maiores)
#define TAMANHO_HABILIDADE 7
// Valor que representa uma posição afetada na matriz de habilidade
#define HABILIDADE_MARCA 1
// Valor que representa uma posição não afetada na matriz de habilidade
#define HABILIDADE_VAZIO 0


// --- Função para Exibir o Tabuleiro ---
// Parâmetros:
//   tabuleiro: Uma matriz bidimensional que representa o estado atual do tabuleiro.
// Retorno: void (não retorna valor).
// Objetivo: Imprimir o tabuleiro no console de forma organizada, mostrando as posições dos navios, da água e das habilidades.
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
            printf("%d ", tabuleiro[i][j]); // Imprime o valor da célula (0, 3 ou 5)
        }
        printf("\n"); // Nova linha após imprimir todas as células de uma linha
    }
    printf("\n"); // Espaço adicional para separar o tabuleiro de outras saídas
}

// --- Função para Criar a Matriz da Habilidade Cone ---
// Parâmetros:
//   matriz_habilidade: Uma matriz bidimensional onde o formato do cone será desenhado.
// Retorno: void.
// Objetivo: Preencher a matriz de habilidade com o formato de um cone apontando para baixo.
void criarCone(int matriz_habilidade[TAMANHO_HABILIDADE][TAMANHO_HABILIDADE]) {
    // Inicializa a matriz com HABILIDADE_VAZIO (0)
    for (int i = 0; i < TAMANHO_HABILIDADE; i++) {
        for (int j = 0; j < TAMANHO_HABILIDADE; j++) {
            matriz_habilidade[i][j] = HABILIDADE_VAZIO;
        }
    }

    // Calcula o centro da matriz de habilidade
    int centro_col = TAMANHO_HABILIDADE / 2;

    // Constrói o formato do cone usando loops e condicionais
    // A cada linha, a largura do cone aumenta.
    for (int i = 0; i < TAMANHO_HABILIDADE; i++) {
        // 'largura' é a distância máxima do centro para preencher em cada lado
        int largura = i;
        // Garante que o cone não exceda o tamanho da matriz se for muito grande
        if (largura >= centro_col) {
            largura = centro_col; // Limita a largura ao centro da matriz
        }

        for (int j = 0; j < TAMANHO_HABILIDADE; j++) {
            // Se a coluna 'j' estiver dentro da 'largura' do centro, marca como parte do cone
            if (j >= (centro_col - largura) && j <= (centro_col + largura)) {
                 // Ajuste para um cone mais visualmente agradável, similar ao exemplo:
                 // A largura aumenta de forma a preencher as linhas progressivamente
                 if (i == 0 && j == centro_col) { // Ponta do cone
                    matriz_habilidade[i][j] = HABILIDADE_MARCA;
                 } else if (i == 1 && (j == centro_col - 1 || j == centro_col || j == centro_col + 1)) {
                    matriz_habilidade[i][j] = HABILIDADE_MARCA;
                 } else if (i == 2 && (j >= centro_col - 2 && j <= centro_col + 2)) {
                    matriz_habilidade[i][j] = HABILIDADE_MARCA;
                 } else if (i == 3) { // Base larga
                    matriz_habilidade[i][j] = HABILIDADE_MARCA;
                 }
            }
        }
    }
}

// --- Função para Criar a Matriz da Habilidade Cruz ---
// Parâmetros:
//   matriz_habilidade: Uma matriz bidimensional onde o formato da cruz será desenhado.
// Retorno: void.
// Objetivo: Preencher a matriz de habilidade com o formato de uma cruz centrada.
void criarCruz(int matriz_habilidade[TAMANHO_HABILIDADE][TAMANHO_HABILIDADE]) {
    // Inicializa a matriz com HABILIDADE_VAZIO (0)
    for (int i = 0; i < TAMANHO_HABILIDADE; i++) {
        for (int j = 0; j < TAMANHO_HABILIDADE; j++) {
            matriz_habilidade[i][j] = HABILIDADE_VAZIO;
        }
    }

    // Calcula o centro da matriz de habilidade
    int centro = TAMANHO_HABILIDADE / 2;

    // Constrói o formato da cruz usando loops e condicionais
    for (int i = 0; i < TAMANHO_HABILIDADE; i++) {
        for (int j = 0; j < TAMANHO_HABILIDADE; j++) {
            // Se a célula estiver na linha central OU na coluna central, marca como parte da cruz
            if (i == centro || j == centro) {
                matriz_habilidade[i][j] = HABILIDADE_MARCA;
            }
        }
    }
}

// --- Função para Criar a Matriz da Habilidade Octaedro (Losango) ---
// Parâmetros:
//   matriz_habilidade: Uma matriz bidimensional onde o formato do octaedro será desenhado.
// Retorno: void.
// Objetivo: Preencher a matriz de habilidade com o formato de um losango (vista frontal de um octaedro) centrado.
void criarOctaedro(int matriz_habilidade[TAMANHO_HABILIDADE][TAMANHO_HABILIDADE]) {
    // Inicializa a matriz com HABILIDADE_VAZIO (0)
    for (int i = 0; i < TAMANHO_HABILIDADE; i++) {
        for (int j = 0; j < TAMANHO_HABILIDADE; j++) {
            matriz_habilidade[i][j] = HABILIDADE_VAZIO;
        }
    }

    // Calcula o centro da matriz de habilidade e o raio para o losango
    int centro_row = TAMANHO_HABILIDADE / 2;
    int centro_col = TAMANHO_HABILIDADE / 2;
    int raio = TAMANHO_HABILIDADE / 2; // O raio define a "distância" do centro até a borda do losango

    // Constrói o formato do octaedro (losango) usando loops e condicionais
    // Um ponto (i,j) faz parte de um losango centrado se |i - centro_row| + |j - centro_col| <= raio
    for (int i = 0; i < TAMANHO_HABILIDADE; i++) {
        for (int j = 0; j < TAMANHO_HABILIDADE; j++) {
            if (abs(i - centro_row) + abs(j - centro_col) <= raio) {
                matriz_habilidade[i][j] = HABILIDADE_MARCA;
            }
        }
    }
}

// --- Função para Aplicar uma Habilidade ao Tabuleiro Principal ---
// Parâmetros:
//   tabuleiro: A matriz do tabuleiro principal.
//   habilidade: A matriz da habilidade a ser aplicada.
//   origem_linha: A linha no tabuleiro principal onde o centro da habilidade será posicionado.
//   origem_coluna: A coluna no tabuleiro principal onde o centro da habilidade será posicionado.
// Retorno: void.
// Objetivo: Sobrepor a matriz de habilidade ao tabuleiro principal, marcando as posições afetadas.
void aplicarHabilidade(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO],
                       int habilidade[TAMANHO_HABILIDADE][TAMANHO_HABILIDADE],
                       int origem_linha, int origem_coluna) {

    // Calcula o deslocamento para o canto superior esquerdo da matriz de habilidade em relação ao tabuleiro
    int deslocamento_linha = origem_linha - (TAMANHO_HABILIDADE / 2);
    int deslocamento_coluna = origem_coluna - (TAMANHO_HABILIDADE / 2);

    printf("Aplicando habilidade com origem em (%d, %d)...\n", origem_linha, origem_coluna);

    // Percorre a matriz da habilidade
    for (int i = 0; i < TAMANHO_HABILIDADE; i++) {
        for (int j = 0; j < TAMANHO_HABILIDADE; j++) {
            // Se a posição na matriz de habilidade é '1' (afetada)
            if (habilidade[i][j] == HABILIDADE_MARCA) {
                // Calcula as coordenadas correspondentes no tabuleiro principal
                int tabuleiro_linha = deslocamento_linha + i;
                int tabuleiro_coluna = deslocamento_coluna + j;

                // Verifica se as coordenadas estão dentro dos limites do tabuleiro
                if (tabuleiro_linha >= 0 && tabuleiro_linha < TAMANHO_TABULEIRO &&
                    tabuleiro_coluna >= 0 && tabuleiro_coluna < TAMANHO_TABULEIRO) {
                    // Se a posição no tabuleiro for água (0), marca como afetada pela habilidade (5)
                    // Navios (3) não são sobrescritos, mantendo a prioridade visual dos navios.
                    if (tabuleiro[tabuleiro_linha][tabuleiro_coluna] == AGUA) {
                        tabuleiro[tabuleiro_linha][tabuleiro_coluna] = HABILIDADE_AFETADA;
                    }
                }
            }
        }
    }
    printf("Habilidade aplicada.\n");
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

    // Navio 3: Posicionado diagonalmente (crescente: linha e coluna aumentam)
    int navio3_linha_inicial = 0; // Linha de início do navio diagonal
    int navio3_coluna_inicial = 0; // Coluna de início do navio diagonal

    // Navio 4: Posicionado diagonalmente (decrescente na linha, crescente na coluna: linha diminui, coluna aumenta)
    int navio4_linha_inicial = 7; // Linha de início do navio diagonal
    int navio4_coluna_inicial = 2; // Coluna de início do navio diagonal

    // Variáveis de controle para erros de posicionamento de navios (limites ou sobreposição)
    int erro_posicionamento;

    // --- Posicionar Navio 1 (Horizontal) ---
    erro_posicionamento = 0; // Reinicia a variável de erro para cada navio
    printf("Tentando posicionar Navio 1 (Horizontal) em (%d, %d)...\n", navio1_linha_inicial, navio1_coluna_inicial);
    // Validação de limites para o Navio 1
    if (navio1_linha_inicial < 0 || navio1_linha_inicial >= TAMANHO_TABULEIRO ||
        navio1_coluna_inicial < 0 || (navio1_coluna_inicial + TAMANHO_NAVIO) > TAMANHO_TABULEIRO) {
        printf("Erro: Posicao inicial do Navio 1 (horizontal) fora dos limites do tabuleiro.\n");
        erro_posicionamento = 1;
    } else {
        // Verifica sobreposição antes de posicionar o Navio 1
        for (int j = 0; j < TAMANHO_NAVIO; j++) {
            if (tabuleiro[navio1_linha_inicial][navio1_coluna_inicial + j] == NAVIO) {
                printf("Erro: Sobreposicao detectada para o Navio 1 (horizontal) em (%d, %d).\n",
                       navio1_linha_inicial, navio1_coluna_inicial + j);
                erro_posicionamento = 1;
                break; // Sai do loop de verificação de sobreposição
            }
        }
        // Se não houve erro de limite ou sobreposição, posiciona o navio
        if (!erro_posicionamento) {
            for (int j = 0; j < TAMANHO_NAVIO; j++) {
                tabuleiro[navio1_linha_inicial][navio1_coluna_inicial + j] = NAVIO;
            }
            printf("Navio 1 (Horizontal) posicionado com sucesso.\n");
        }
    }

    // --- Posicionar Navio 2 (Vertical) ---
    erro_posicionamento = 0; // Reinicia a variável de erro
    printf("Tentando posicionar Navio 2 (Vertical) em (%d, %d)...\n", navio2_linha_inicial, navio2_coluna_inicial);
    // Validação de limites para o Navio 2
    if (navio2_linha_inicial < 0 || (navio2_linha_inicial + TAMANHO_NAVIO) > TAMANHO_TABULEIRO ||
        navio2_coluna_inicial < 0 || navio2_coluna_inicial >= TAMANHO_TABULEIRO) {
        printf("Erro: Posicao inicial do Navio 2 (vertical) fora dos limites do tabuleiro.\n");
        erro_posicionamento = 1;
    } else {
        // Verifica sobreposição antes de posicionar o Navio 2
        for (int i = 0; i < TAMANHO_NAVIO; i++) {
            if (tabuleiro[navio2_linha_inicial + i][navio2_coluna_inicial] == NAVIO) {
                printf("Erro: Sobreposicao detectada para o Navio 2 (vertical) em (%d, %d).\n",
                       navio2_linha_inicial + i, navio2_coluna_inicial);
                erro_posicionamento = 1;
                break; // Sai do loop de verificação de sobreposição
            }
        }
        // Se não houve erro de limite ou sobreposição, posiciona o navio
        if (!erro_posicionamento) {
            for (int i = 0; i < TAMANHO_NAVIO; i++) {
                tabuleiro[navio2_linha_inicial + i][navio2_coluna_inicial] = NAVIO;
            }
            printf("Navio 2 (Vertical) posicionado com sucesso.\n");
        }
    }

    // --- Posicionar Navio 3 (Diagonal: linha e coluna aumentam) ---
    erro_posicionamento = 0; // Reinicia a variável de erro
    printf("Tentando posicionar Navio 3 (Diagonal crescente) em (%d, %d)...\n", navio3_linha_inicial, navio3_coluna_inicial);
    // Validação de limites para o Navio 3 (diagonal crescente)
    if (navio3_linha_inicial < 0 || (navio3_linha_inicial + TAMANHO_NAVIO) > TAMANHO_TABULEIRO ||
        navio3_coluna_inicial < 0 || (navio3_coluna_inicial + TAMANHO_NAVIO) > TAMANHO_TABULEIRO) {
        printf("Erro: Posicao inicial do Navio 3 (diagonal crescente) fora dos limites do tabuleiro.\n");
        erro_posicionamento = 1;
    } else {
        // Verifica sobreposição antes de posicionar o Navio 3
        for (int k = 0; k < TAMANHO_NAVIO; k++) {
            if (tabuleiro[navio3_linha_inicial + k][navio3_coluna_inicial + k] == NAVIO) {
                printf("Erro: Sobreposicao detectada para o Navio 3 (diagonal crescente) em (%d, %d).\n",
                       navio3_linha_inicial + k, navio3_coluna_inicial + k);
                erro_posicionamento = 1;
                break;
            }
        }
        // Se não houve erro, posiciona o navio
        if (!erro_posicionamento) {
            for (int k = 0; k < TAMANHO_NAVIO; k++) {
                tabuleiro[navio3_linha_inicial + k][navio3_coluna_inicial + k] = NAVIO;
            }
            printf("Navio 3 (Diagonal crescente) posicionado com sucesso.\n");
        }
    }

    // --- Posicionar Navio 4 (Diagonal: linha diminui, coluna aumenta) ---
    erro_posicionamento = 0; // Reinicia a variável de erro
    printf("Tentando posicionar Navio 4 (Diagonal decrescente/crescente) em (%d, %d)...\n", navio4_linha_inicial, navio4_coluna_inicial);
    // Validação de limites para o Navio 4 (diagonal decrescente na linha, crescente na coluna)
    if (navio4_linha_inicial < (TAMANHO_NAVIO - 1) || navio4_linha_inicial >= TAMANHO_TABULEIRO || // A linha final (navio4_linha_inicial - (TAMANHO_NAVIO-1)) não pode ser negativa
        navio4_coluna_inicial < 0 || (navio4_coluna_inicial + TAMANHO_NAVIO) > TAMANHO_TABULEIRO) {
        printf("Erro: Posicao inicial do Navio 4 (diagonal decrescente/crescente) fora dos limites do tabuleiro.\n");
        erro_posicionamento = 1;
    } else {
        // Verifica sobreposição antes de posicionar o Navio 4
        for (int k = 0; k < TAMANHO_NAVIO; k++) {
            if (tabuleiro[navio4_linha_inicial - k][navio4_coluna_inicial + k] == NAVIO) {
                printf("Erro: Sobreposicao detectada para o Navio 4 (diagonal decrescente/crescente) em (%d, %d).\n",
                       navio4_linha_inicial - k, navio4_coluna_inicial + k);
                erro_posicionamento = 1;
                break;
            }
        }
        // Se não houve erro, posiciona o navio
        if (!erro_posicionamento) {
            for (int k = 0; k < TAMANHO_NAVIO; k++) {
                tabuleiro[navio4_linha_inicial - k][navio4_coluna_inicial + k] = NAVIO;
            }
            printf("Navio 4 (Diagonal decrescente/crescente) posicionado com sucesso.\n");
        }
    }

    // --- 3. Criar e Integrar Habilidades ao Tabuleiro ---
    int matriz_cone[TAMANHO_HABILIDADE][TAMANHO_HABILIDADE];
    int matriz_cruz[TAMANHO_HABILIDADE][TAMANHO_HABILIDADE];
    int matriz_octaedro[TAMANHO_HABILIDADE][TAMANHO_HABILIDADE];

    // Cria as matrizes de habilidade
    criarCone(matriz_cone);
    criarCruz(matriz_cruz);
    criarOctaedro(matriz_octaedro);

    // Define os pontos de origem para cada habilidade no tabuleiro principal
    // (As habilidades são centradas nestes pontos)
    int origem_cone_linha = 4;
    int origem_cone_coluna = 5;

    int origem_cruz_linha = 7;
    int origem_cruz_coluna = 8;

    int origem_octaedro_linha = 3;
    int origem_octaedro_coluna = 2;

    // Aplica as habilidades ao tabuleiro principal
    aplicarHabilidade(tabuleiro, matriz_cone, origem_cone_linha, origem_cone_coluna);
    aplicarHabilidade(tabuleiro, matriz_cruz, origem_cruz_linha, origem_cruz_coluna);
    aplicarHabilidade(tabuleiro, matriz_octaedro, origem_octaedro_linha, origem_octaedro_coluna);

    // 4. Exibir o Tabuleiro Final com Navios e Habilidades
    printf("\n--- Tabuleiro de Batalha Naval Final com Habilidades ---\n");
    exibirTabuleiro(tabuleiro);

    return 0; // Indica que o programa foi executado com sucesso
}