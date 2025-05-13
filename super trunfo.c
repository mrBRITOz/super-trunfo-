#include <stdio.h>

// Estrutura para armazenar os dados de uma carta
typedef struct {
    char estado[50];
    int codigo;
    char nome[50];
    long populacao;
    float area;
    float pib;
    int pontos_turisticos;
    float densidade_populacional;
    float pib_per_capita;
    float super_poder;
} Carta;

// Funções
void calcular_estatisticas(Carta *carta) {
    carta->densidade_populacional = carta->populacao / carta->area;
    carta->pib_per_capita = carta->pib / carta->populacao;
    carta->super_poder = carta->populacao + carta->area + carta->pib +
                         carta->pontos_turisticos + carta->pib_per_capita +
                         (1.0 / carta->densidade_populacional);  // Inverso da densidade
}

void comparar_e_exibir(Carta c1, Carta c2) {
    printf("\nComparação de Cartas:\n\n");

    printf("População: Carta 1 venceu (%d)\n", c1.populacao > c2.populacao ? 1 : 0);
    printf("Área: Carta 1 venceu (%d)\n", c1.area > c2.area ? 1 : 0);
    printf("PIB: Carta 1 venceu (%d)\n", c1.pib > c2.pib ? 1 : 0);
    printf("Pontos Turísticos: Carta 1 venceu (%d)\n", c1.pontos_turisticos > c2.pontos_turisticos ? 1 : 0);
    printf("Densidade Populacional: Carta 1 venceu (%d)\n", c1.densidade_populacional < c2.densidade_populacional ? 1 : 0);
    printf("PIB per Capita: Carta 1 venceu (%d)\n", c1.pib_per_capita > c2.pib_per_capita ? 1 : 0);
    printf("Super Poder: Carta 1 venceu (%d)\n", c1.super_poder > c2.super_poder ? 1 : 0);
}

int main() {
    Carta carta1, carta2;

    // Leitura dos dados da Carta 1
    printf("Digite os dados da Carta 1:\n");
    printf("Estado: "); scanf(" %[^\n]", carta1.estado);
    printf("Código: "); scanf("%d", &carta1.codigo);
    printf("Nome: "); scanf(" %[^\n]", carta1.nome);
    printf("População: "); scanf("%ld", &carta1.populacao);
    printf("Área: "); scanf("%f", &carta1.area);
    printf("PIB: "); scanf("%f", &carta1.pib);
    printf("Pontos Turísticos: "); scanf("%d", &carta1.pontos_turisticos);

    // Leitura dos dados da Carta 2
    printf("\nDigite os dados da Carta 2:\n");
    printf("Estado: "); scanf(" %[^\n]", carta2.estado);
    printf("Código: "); scanf("%d", &carta2.codigo);
    printf("Nome: "); scanf(" %[^\n]", carta2.nome);
    printf("População: "); scanf("%ld", &carta2.populacao);
    printf("Área: "); scanf("%f", &carta2.area);
    printf("PIB: "); scanf("%f", &carta2.pib);
    printf("Pontos Turísticos: "); scanf("%d", &carta2.pontos_turisticos);

    // Cálculos
    calcular_estatisticas(&carta1);
    calcular_estatisticas(&carta2);

    // Comparações
    comparar_e_exibir(carta1, carta2);

    return 0;
}
