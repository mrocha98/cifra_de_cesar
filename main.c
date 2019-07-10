#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

const int _A = 65, _Z = 90, _totalLetras = 26;

int encontraLetraCifrada(char c, int chave){
    for(int i = c+1, j = 0; j < chave; i++, j++){
        if(i > _Z)
            i = _A;
        c = i;
    }
    return c; 
}

void criptografa(char str[], int chave){
    for(int i = 0, len = strlen(str); (i < len); i++){
        char c = str[i];
        c = toupper(c);
        if(isalpha(c))
            c = encontraLetraCifrada(c, chave);
        printf("%c", c);
    }
    printf("\n\n");
}

void criptografa26Vezes(char frase[]){
    for(int i = 0; i < _totalLetras; i++){
        printf("[%d]\t-\t", i);
        criptografa(frase, i);
    }
}

void txtMenu(){
    printf("------------------------------------------\n");
    printf("1. Criptografar fornecendo uma chave.\n");
    printf("2. Listar frase com 26 chaves aplicadas.\n");
    printf("3. Sair.\n|\n|->\t");
}

void menu(){
    char str[200+1];
    int chave, op = 0;
    do{
        txtMenu();
        setbuf(stdin, NULL); scanf("%d", &op);
        switch(op){
            case 1:
                printf("Entre com a frase: "); setbuf(stdin, NULL); scanf("%[^\n]s", str);
                printf("Entre com a chave: "); setbuf(stdin, NULL); scanf("%d", &chave);
                printf("CRIPTOGRAFANDO SUA FRASE........\n");
                criptografa(str, chave);
            break;
            case 2:
                printf("Entre com a frase: "); setbuf(stdin, NULL); scanf("%[^\n]s", str);
                criptografa26Vezes(str);
            break;
            case 3:
                printf("\nsaindo....\n\n");
            return;
            default:
                printf("Opcao invalida....\n");
        }
    }while(op != 3);
}

int main(){
    printf("\t==========\t\tCIFRA DE CESAR\t\t==========\n\n\n\n");
    menu();
    printf("\n\t==========================================================\n");
    system("pause");
    return 0;
}