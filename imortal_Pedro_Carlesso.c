#include <stdio.h>
#include <stdlib.h>

// funcao que calcula a media
double calcular_media(double a, double b, double c) {
    return (a + b + c) / 3;
}
// funcao que encontra o valor maximo
double encontrar_maximo(double a, double b, double c) {
    double maior = a;

    if (b > maior) {
        maior = b;
    }
    if (c > maior) {
        maior = c;
    }

    return maior;
}
// funcao que encontra o valor minimo
double encontrar_minimo(double a, double b, double c){
    double menor = a;

    if (b < menor) {
        menor = b;
    }
    if (c < menor) {
        menor = c;
    }

    return menor;
}
// funcao que faz o calculo dos desvios (media - valor atual)
void ver_desvios(double a, double b, double c){
    double media = calcular_media(a,b,c);

    printf("Desvio da leitura 1: %.2f\n", a - media);
    printf("Desvio da leitura 2: %.2f\n", b - media);
    printf("Desvio da leitura 3: %.2f\n", c - media);
}
// funcao que pede 2 faixas de valores e mostra se as leituras feitas estao dentro das faixas
void verificar_faixa(double a, double b, double c){
    double min_aceito, max_aceito;

    printf("Digite o minimo aceito: ");
    scanf("%lf", &min_aceito);

    printf("Digite o maximo aceito: ");
    scanf("%lf", &max_aceito);

    if (a >= min_aceito && a <= max_aceito)
        printf("Leitura 1: OK (%.2f)\n", a);
    else
        printf("LEITURA 1: FORA DO LIMITE (%.2f)\n", a);

    if (b >= min_aceito && b <= max_aceito)
        printf("Leitura 2: OK (%.2f)\n", b);
    else
        printf("LEITURA 2: FORA DO LIMITE (%.2f)\n", b);

    if (c >= min_aceito && c <= max_aceito)
        printf("Leitura 3: OK (%.2f)\n", c);
    else
        printf("LEITURA 3: FORA DO LIMITE (%.2f)\n", c);
}
// funcao que faz a media escrita em barra grafica
void exibir_barra_grafica(double media){
    int i;

    printf("Intensidade media = %.2f\n", media);

    for(i = 0; i < (int)media && i < 20; i++){
        printf("*");
    }

    printf("\n");
}
// funcao que faz todas as outras opcoes juntas     
void exibir_relatorio_completo(double a, double b, double c){
    double media = calcular_media(a,b,c);

    printf("\n=== RELATORIO COMPLETO ===\n");

    printf("Media: %.2f\n", media);

    double max = encontrar_maximo(a,b,c);
    double min = encontrar_minimo(a,b,c);

    printf("Maximo: %.2f\n", max);
    printf("Minimo: %.2f\n", min);

    printf("\n--- Desvios ---\n");
    ver_desvios(a,b,c);

    printf("\n--- Faixa ---\n");
    verificar_faixa(a,b,c);

    printf("\n--- Barra Grafica ---\n");
    exibir_barra_grafica(media);
}

int main() {
    double L1,L2,L3,media,max,min;          // declaro todas as variaveis
    int opcao;
    char continuar = 's';
    char nova_simulacao = 's';

    while (nova_simulacao == 's'){ // uso um while para demonstrar onde comeca a simulacao

        printf("=== IMORTAL-1 - SISTEMA DE BORDO ===\n"); // titulo + as leituras

        printf("Digite a leitura 1: ");
        scanf("%lf", &L1);

        printf("Digite a leitura 2: ");
        scanf("%lf", &L2);

        printf("Digite a leitura 3: ");
        scanf("%lf", &L3);

        continuar = 's';

        while (continuar == 's'){
// mostro as possiveis opcoes
            printf("\n--- MENU ---\n");
            printf("1 - Media\n");
            printf("2 - Max/Min\n");
            printf("3 - Desvios\n");
            printf("4 - Verificacao de faixa\n");
            printf("5 - Barra grafica\n");
            printf("6 - Relatorio\n");
            printf("0 - Sair\n");

            printf("\nEscolha uma opcao: ");
            scanf("%d", &opcao);

            if (opcao == 1) {        // calcula a media
                media = calcular_media(L1, L2, L3);
                printf("Media: %.2f\n", media);
            }
            else if (opcao == 2){  // encontra o maior e o menor valor
                max = encontrar_maximo(L1,L2,L3);
                min = encontrar_minimo(L1,L2,L3);
                printf("Maximo: %.2f\n", max);
                printf("Minimo: %.2f\n", min);
            }
            else if (opcao == 3){ // calcula os desvios
                ver_desvios(L1,L2,L3);
            }
            else if (opcao == 4){ // pde um numero maximo e minimo aceitavel e calcula se as leituras estao dentro da faixa
                verificar_faixa(L1,L2,L3);
            }
            else if (opcao == 5){ // exibe a media em barra grafica de asteriscos
                media = calcular_media(L1,L2,L3);
                exibir_barra_grafica(media);
            }
            else if (opcao == 6){ // faz o relatorio completo com todas as opções juntas
                exibir_relatorio_completo(L1,L2,L3);

            }
            else if (opcao == 0){ // sai do codigo
                break;
            }

            printf("\nDeseja realizar outra operacao? (s/n): "); // pede ao usuario se ele quer realizar outra operação com as mesmas leituras
            scanf(" %c", &continuar);
        }

        printf("\nDeseja iniciar nova simulacao? (s/n): "); // pede ao usuario se ele quer realizar uma nova simulação com leituras diferentes
        scanf(" %c", &nova_simulacao);
    }

    printf("Encerrando sistema...\n"); // encerra o programa

    return 0;
}