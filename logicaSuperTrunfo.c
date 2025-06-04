#include <stdio.h>
#include <string.h>

// Estrutura para representar uma carta de país
typedef struct {
    char nome[30];
    int populacao;         // em milhões
    int area;              // em km²
    int densidade;         // pessoas por km²
    int pib;               // em bilhões de dólares
} Carta;

// Função para mostrar os atributos disponíveis
void mostrarMenuAtributos(int atributoOmitido) {
    printf("\nEscolha um atributo para comparar:\n");
    if (atributoOmitido != 1) printf("1. Populacao\n");
    if (atributoOmitido != 2) printf("2. Area\n");
    if (atributoOmitido != 3) printf("3. Densidade Demografica\n");
    if (atributoOmitido != 4) printf("4. PIB\n");
}

// Função para obter valor de um atributo
int obterValorAtributo(Carta c, int atributo) {
    switch (atributo) {
        case 1: return c.populacao;
        case 2: return c.area;
        case 3: return c.densidade;
        case 4: return c.pib;
        default: return -1;
    }
}

// Função para imprimir o nome do atributo
void imprimirNomeAtributo(int atributo) {
    switch (atributo) {
        case 1: printf("Populacao"); break;
        case 2: printf("Area"); break;
        case 3: printf("Densidade Demografica"); break;
        case 4: printf("PIB"); break;
        default: printf("Desconhecido");
    }
}

int main() {
    // Cartas pré-cadastradas
    Carta carta1 = {"Brasil", 213, 8516, 25, 1800};
    Carta carta2 = {"Japao", 126, 377, 336, 5100};

    int atributo1 = 0, atributo2 = 0;
    int valor1_c1, valor1_c2, valor2_c1, valor2_c2;
    int soma_c1, soma_c2;

    // Menu para escolha do primeiro atributo
    do {
        mostrarMenuAtributos(0);
        printf("Escolha o primeiro atributo: ");
        scanf("%d", &atributo1);
        if (atributo1 < 1 || atributo1 > 4)
            printf("Opcao invalida. Tente novamente.\n");
    } while (atributo1 < 1 || atributo1 > 4);

    // Menu para escolha do segundo atributo (não pode ser igual ao primeiro)
    do {
        mostrarMenuAtributos(atributo1);
        printf("Escolha o segundo atributo (diferente do primeiro): ");
        scanf("%d", &atributo2);
        if (atributo2 < 1 || atributo2 > 4 || atributo2 == atributo1)
            printf("Opcao invalida ou repetida. Tente novamente.\n");
    } while (atributo2 < 1 || atributo2 > 4 || atributo2 == atributo1);

    // Coleta de valores para os atributos
    valor1_c1 = obterValorAtributo(carta1, atributo1);
    valor1_c2 = obterValorAtributo(carta2, atributo1);
    valor2_c1 = obterValorAtributo(carta1, atributo2);
    valor2_c2 = obterValorAtributo(carta2, atributo2);

    // Exibição dos valores
    printf("\n--- Comparacao de Cartas ---\n\n");
    printf("Carta 1: %s\n", carta1.nome);
    printf("Carta 2: %s\n\n", carta2.nome);

    printf("Atributo 1: ");
    imprimirNomeAtributo(atributo1);
    printf("\n%s: %d\n", carta1.nome, valor1_c1);
    printf("%s: %d\n\n", carta2.nome, valor1_c2);

    printf("Atributo 2: ");
    imprimirNomeAtributo(atributo2);
    printf("\n%s: %d\n", carta1.nome, valor2_c1);
    printf("%s: %d\n\n", carta2.nome, valor2_c2);

    // Comparações individuais com destaque à exceção (densidade)
    printf("--- Resultado das Comparacoes Individuais ---\n");
    if (atributo1 == 3) {
        printf("Vencedor em Densidade Demografica: %s\n", (valor1_c1 < valor1_c2) ? carta1.nome : carta2.nome);
    } else {
        printf("Vencedor em ");
        imprimirNomeAtributo(atributo1);
        printf(": %s\n", (valor1_c1 > valor1_c2) ? carta1.nome : carta2.nome);
    }

    if (atributo2 == 3) {
        printf("Vencedor em Densidade Demografica: %s\n", (valor2_c1 < valor2_c2) ? carta1.nome : carta2.nome);
    } else {
        printf("Vencedor em ");
        imprimirNomeAtributo(atributo2);
        printf(": %s\n", (valor2_c1 > valor2_c2) ? carta1.nome : carta2.nome);
    }

    // Soma dos atributos (maior valor sempre, mesmo para densidade)
    soma_c1 = valor1_c1 + valor2_c1;
    soma_c2 = valor1_c2 + valor2_c2;

    printf("\nSoma dos atributos:\n");
    printf("%s: %d\n", carta1.nome, soma_c1);
    printf("%s: %d\n", carta2.nome, soma_c2);

    printf("\n--- Resultado Final ---\n");
    if (soma_c1 > soma_c2) {
        printf("Vencedor: %s\n", carta1.nome);
    } else if (soma_c2 > soma_c1) {
        printf("Vencedor: %s\n", carta2.nome);
    } else {
        printf("Empate!\n");
    }

    return 0;
}