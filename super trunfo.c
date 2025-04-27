#include <stdio.h>

// Definindo a estrutura da carta
typedef struct {
    char estado[3];
    char codigo[10];
    char nomeCidade[50];
    int populacao;
    float area;
    float pib;
    int pontosTuristicos;
    float densidadePopulacional;
    float pibPerCapita;
} Carta;

// Função para calcular a densidade populacional
float calcularDensidadePopulacional(int populacao, float area) {
    return populacao / area;
}

// Função para calcular o PIB per capita
float calcularPIBPerCapita(float pib, int populacao) {
    return pib / populacao;
}

int main() {
    // Cadastro de duas cartas pré-definidas
    Carta carta1 = {"SP", "C001", "São Paulo", 12300000, 1521.11, 236000000000.0, 20};
    Carta carta2 = {"RJ", "C002", "Rio de Janeiro", 6748000, 1182.3, 408000000000.0, 18};

    // Cálculo da densidade populacional e PIB per capita para cada carta
    carta1.densidadePopulacional = calcularDensidadePopulacional(carta1.populacao, carta1.area);
    carta1.pibPerCapita = calcularPIBPerCapita(carta1.pib, carta1.populacao);

    carta2.densidadePopulacional = calcularDensidadePopulacional(carta2.populacao, carta2.area);
    carta2.pibPerCapita = calcularPIBPerCapita(carta2.pib, carta2.populacao);

    // Escolha do atributo para comparação
    // Opções: populacao, area, pib, densidadePopulacional, pibPerCapita
    // Neste exemplo, vamos comparar PIB per capita
    float valor1 = carta1.pibPerCapita;
    float valor2 = carta2.pibPerCapita;
    char atributo[] = "PIB per capita";

    // Impressão das informações e resultado
    printf("Comparação de cartas (Atributo: %s):\n\n", atributo);
    printf("Carta 1 - %s (%s): %.2f\n", carta1.nomeCidade, carta1.estado, valor1);
    printf("Carta 2 - %s (%s): %.2f\n\n", carta2.nomeCidade, carta2.estado, valor2);

    // Comparação para determinar a carta vencedora
    // OBS: Se fosse densidade populacional, menor valor venceria
    if (valor1 > valor2) {
        printf("Resultado: Carta 1 (%s) venceu!\n", carta1.nomeCidade);
    } else if (valor2 > valor1) {
        printf("Resultado: Carta 2 (%s) venceu!\n", carta2.nomeCidade);
    } else {
        printf("Resultado: Empate!\n");
    }

    return 0;
}
