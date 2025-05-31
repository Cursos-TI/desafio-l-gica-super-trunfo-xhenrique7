#include <stdio.h>

// Desafio Super Trunfo - Países
// Tema 2 - Comparação das Cartas
// Este código inicial serve como base para o desenvolvimento do sistema de comparação de cartas de cidades. 
// Siga os comentários para implementar cada parte do desafio.

int main() {
    // Definição das variáveis para armazenar as propriedades das cidades
    // Você pode utilizar o código do primeiro desafio

    
    // Cadastro das Cartas:
     char estado1[100], codigo1[100], nome1[100];
     char estado2[100], codigo2[100], nome2[100];
     int ponto1, pop1,options;
     int ponto2, pop2;
     float area1, pib1, densidade1, capita1;
     float area2, pib2, densidade2, capita2;


 //ENTRADA DE DADOS CARTA1
     printf("**** DADOS CARTA 1 ***\n");
     printf("Digite seu Estado abreviado EX(MG):\n");
     scanf("%s", estado1 );
     printf("Digite o nome da cidade: \n");
     scanf("%s", nome1);
     printf("Digite o código da sua carta: \n");
    scanf("%s", codigo1);
    printf("Digite o valor da população:\n");
    scanf("%d", &pop1);
    printf("Digite a área (em km²): \n");
    scanf("%f", &area1);
    printf("Digite a quantidade de pontos turísticos : \n");
    scanf("%d", &ponto1);
    printf("Digite o PIB da sua cidade: \n");
    scanf("%f", &pib1);
//CALCULAR
    densidade1 = (float) pop1/area1 ;
    capita1 = (float) pib1/pop1;
    printf("A Densidade da cidade é:%.2f \n", densidade1);
    printf("PIB per capita: %.2f\n", capita1);
    printf("\n");

//ENTRADA DE DADOS CARTA2 
    printf("**** DADOS CARTA 2 ***\n");
    printf("Digite seu Estado abreviado EX(SP): \n");
    scanf("%s", estado2 );
    printf("Digite o nome da cidade: \n");
    scanf("%s", nome2);
    printf("Digite o código da sua carta: \n");
    scanf("%s", codigo2);
    printf("Digite o valor da população:\n");
    scanf("%d", &pop2);
    printf("Digite a área (em km²): \n");
    scanf("%f", &area2);
    printf("Digite a quantidade de pontos turísticos : \n");
    scanf("%d", &ponto2);
    printf("Digite o PIB da sua cidade: \n");
    scanf("%f", &pib2);


//CALCULAR 2
    densidade2 = (float)(pop2/area2);
     capita2 = (float)(pib2/pop2);
    
    // Comparação de Cartas:
    // Desenvolva a lógica de comparação entre duas cartas.
    // Utilize estruturas de decisão como if, if-else para comparar atributos como população, área, PIB, etc.

    // Exemplo:
    if (pop1 > pop2) {
         printf("Cidade 1 tem maior população.\n");
     } else {
         printf("Cidade 2 tem maior população.\n");
    }

    // Exibição dos Resultados:
    // Após realizar as comparações, exiba os resultados para o usuário.
    // Certifique-se de que o sistema mostre claramente qual carta venceu e com base em qual atributo.

    // Exemplo:
      printf("A cidade vencedora é: %s\n", nome1,nome2);

    return 0;
}
