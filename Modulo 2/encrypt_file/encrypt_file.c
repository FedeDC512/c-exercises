/* 1. Write a program in C to encrypt a text file.
Assume that, the content of the file test.txt is  :
Welcome to w3resource.com. 
Test Data :
Input the name of file to encrypt : test.txt
Expected Output :
File test.txt successfully encrypted ..!!
If you read the file test.txt you will see the following :
������Ʉ�ӄۗ�������ɒ��ђn */

#include <stdio.h>

char encrypt (char c);

int main()
{
    FILE *punta;

    char c;

    if ((punta = fopen("text.txt", "r+")) == NULL) {
        printf("File could not be opened");
    }
    else {

        while ((c = fgetc(punta)) != EOF) {
            
            fputc(encrypt(c), punta);
        
        }
    }

    printf("File test.txt successfully encrypted ..!!");
    fclose(punta);
}

char encrypt (char c){
    return c+96;
}