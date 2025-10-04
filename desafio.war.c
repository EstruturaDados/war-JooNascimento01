#include <stdio.h>
#include <string.h>

// Definição da struct Territorio
// Agrupa informações relacionadas a um território: nome, cor do exército e quantidade de tropas.
typedef struct {
    char nome[30];  // Nome do território (capacidade para 29 caracteres + '\0')
    char cor[10];   // Cor do exército (capacidade para 9 caracteres + '\0')
    int tropas;     // Número de tropas
} Territorio;

// Constante para o número de territórios a serem cadastrados
#define NUM_TERRITORIOS 5

int main() {
    // Declaração do vetor de structs
    // Cria um array capaz de armazenar 5 estruturas do tipo Territorio.
    Territorio lista_territorios[NUM_TERRITORIOS];
    int i; // Variável de controle para os laços

    printf("--- Cadastro de Territórios ---\n");
    printf("O sistema permitirá o cadastro de %d territórios.\n\n", NUM_TERRITORIOS);

    // Entrada dos dados: Laço for para preencher os dados dos 5 territórios
    // O laço itera de 0 até NUM_TERRITORIOS-1, coletando os dados de cada posição do vetor.
    for (i = 0; i < NUM_TERRITORIOS; i++) {
        printf("Cadastrando o Território %d de %d:\n", i + 1, NUM_TERRITORIOS);

        // Entrada do Nome
        // Utiliza fgets para ler a linha inteira, o que é mais seguro para strings.
        printf("  Nome do Território (max 29 caracteres): ");
        if (fgets(lista_territorios[i].nome, sizeof(lista_territorios[i].nome), stdin)) {
            // Remove o caractere de nova linha ('\n') adicionado pelo fgets, se ele existir.
            lista_territorios[i].nome[strcspn(lista_territorios[i].nome, "\n")] = 0;
        }

        // Entrada da Cor do Exército
        // Usando scanf("%s", ...) para garantir que apenas uma palavra seja lida para a cor.
        printf("  Cor do Exército (max 9 caracteres): ");
        scanf("%s", lista_territorios[i].cor);

        // Entrada do Número de Tropas
        printf("  Quantidade de Tropas: ");
        scanf("%d", &lista_territorios[i].tropas);

        // Limpa o buffer de entrada. É necessário após o uso de scanf para que o próximo fgets (do nome)
        // funcione corretamente e não leia uma nova linha pendente.
        while (getchar() != '\n'); 

        printf("\n"); // Espaço após o cadastro de cada território
    }

    // ---
    
    // Exibição dos Dados
    printf("--- Dados dos Territórios Cadastrados ---\n");

    // O laço percorre o vetor e exibe as informações de cada território com formatação clara.
    for (i = 0; i < NUM_TERRITORIOS; i++) {
        printf("\nTerritório %d:\n", i + 1);
        printf("  -> Nome: %s\n", lista_territorios[i].nome);
        printf("  -> Cor do Exército: %s\n", lista_territorios[i].cor);
        printf("  -> Tropas: %d\n", lista_territorios[i].tropas);
    }

    printf("\n--- Fim da Exibição ---\n");

    return 0;
}