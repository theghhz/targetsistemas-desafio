#include <stdio.h>
#include <stdlib.h>

void inverterString(char *string){
    int i = 0;
    int j = 0;
    char temp;

    while(string[j] != '\0'){
        j++;
    }

    j--;

    while(i < j){
        temp = string[i];
        string[i] = string[j];
        string[j] = temp;
        i++;
        j--;
    }

    printf("INVERTIDA: %s\n", string);
    
}

int main(){

    char *string;

    scanf("%s", string);

    printf("NORMAL: %s\n", string);

    inverterString(string);

}