#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "../lib/cJSON/cJSON.h" 

#define DIAS_DO_MES 30

/*3) Dado um vetor que guarda o valor de faturamento diário de uma distribuidora, faça um programa, na linguagem que desejar, que calcule e retorne:
• O menor valor de faturamento ocorrido em um dia do mês;
• O maior valor de faturamento ocorrido em um dia do mês;
• Número de dias no mês em que o valor de faturamento diário foi superior à média mensal.

IMPORTANTE:
a) Usar o json ou xml disponível como fonte dos dados do faturamento mensal;
b) Podem existir dias sem faturamento, como nos finais de semana e feriados. Estes dias devem ser ignorados no cálculo da média;*/

float menorFaturamento(float faturamento[]) {
    float menor = faturamento[0];
    for (int i = 1; i < DIAS_DO_MES; i++) {
        if (faturamento[i] < menor)
            menor = faturamento[i];
    }
    return menor;
}

float maiorFaturamento(float faturamento[]) {
    float maior = faturamento[0];
    for (int i = 1; i < DIAS_DO_MES; i++) {
        if (faturamento[i] > maior)
            maior = faturamento[i];
    }
    return maior;
}

float mediaFaturamento(float faturamento[]) {
    float soma = 0;
    for (int i = 0; i < DIAS_DO_MES; i++) {
        soma += faturamento[i];
    }
    return soma / DIAS_DO_MES;
}

int diasAcimaDaMediaFaturamento(float faturamento[]) {
    float media = mediaFaturamento(faturamento);
    int dias = 0;
    for (int i = 0; i < DIAS_DO_MES; i++) {
        if (faturamento[i] > media)
            dias++;
    }
    return dias;
}

void removerEspacos(char *str) {
    char *i = str, *j = str;
    while (*j != '\0') {
        *i = *j++;
        if (!isspace(*i)) i++;
    }
    *i = '\0';
}

void lerFaturamento(float faturamento[]) {
    FILE *file = fopen("../data/dados.json", "r");
    if (file == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        exit(1);
    }

    fseek(file, 0, SEEK_END);
    long length = ftell(file);
    fseek(file, 0, SEEK_SET);
    char *data = (char*)malloc(length + 1);
    fread(data, 1, length, file);
    data[length] = '\0';
    fclose(file);

    cJSON *json = cJSON_Parse(data);
    if (json == NULL) {
        printf("Erro ao fazer o parsing do JSON.\n");
        free(data);
        exit(1);
    }

    for (int i = 0; i < DIAS_DO_MES; i++) {
        cJSON *dia = cJSON_GetArrayItem(json, i);
        if (dia != NULL) {
            cJSON *valor = cJSON_GetObjectItem(dia, "valor");
            if (valor != NULL) {
                faturamento[i] = valor->valuedouble;
            }
        }
    }

    cJSON_Delete(json);
    free(data);
}

int main() {
    float faturamento[DIAS_DO_MES];

    lerFaturamento(faturamento);

    float valorMenor = menorFaturamento(faturamento);
    float valorMaior = maiorFaturamento(faturamento);
    int diasAcimaMedia = diasAcimaDaMediaFaturamento(faturamento);

    printf("Menor valor de faturamento: %.2f\n", valorMenor);
    printf("Maior valor de faturamento: %.2f\n", valorMaior);
    printf("Número de dias com faturamento acima da média: %d\n", diasAcimaMedia);

    return 0;
}
