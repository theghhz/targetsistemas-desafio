#include <stdio.h>
#include <stdlib.h>

/*4) Dado o valor de faturamento mensal de uma distribuidora, detalhado por estado:
• SP – R$67.836,43
• RJ – R$36.678,66
• MG – R$29.229,88
• ES – R$27.165,48
• Outros – R$19.849,53*/

int main(){
    
    float sp = 67836.43;
    float rj = 36678.66;
    float mg = 29229.88;
    float es = 27165.48;
    float outros = 19849.53;

    float total = sp + rj + mg + es + outros;

    printf("Percentual de faturamento de SP: %.2f%%\n", (sp / total) * 100);
    printf("Percentual de faturamento de RJ: %.2f%%\n", (rj / total) * 100);
    printf("Percentual de faturamento de MG: %.2f%%\n", (mg / total) * 100);
    printf("Percentual de faturamento de ES: %.2f%%\n", (es / total) * 100);
    printf("Percentual de faturamento de Outros: %.2f%%\n", (outros / total) * 100);

    return 0;
}