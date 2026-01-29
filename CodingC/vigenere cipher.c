#include <stdio.h>
#include <string.h>

void encrypt(char text[], char key[]) {
    int textLen = strlen(text);
    int keyLen = strlen(key);
    
    for (int i = 0, j = 0; i < textLen; i++) {
        if (text[i] >= 'A' && text[i] <= 'Z') {
            text[i] = ((text[i] - 'A') + (key[j % keyLen] - 'A')) % 26 + 'A';
            j++;
        } else if (text[i] >= 'a' && text[i] <= 'z') {
            text[i] = ((text[i] - 'a') + (key[j % keyLen] - 'a')) % 26 + 'a';
            j++;
        }
    }
}

int main() {
    char text[100], key[100];
    
    printf("Enter text: ");
    gets(text);
    printf("Enter key: ");
    gets(key);
    
    encrypt(text, key);
    
    printf("Encrypted text: %s\n", text);
    
    return 0;
}