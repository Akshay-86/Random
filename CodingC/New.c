#include<stdio.h>
#include<string.h>

void encrypt(char text[],char key[]);

void main(){
  char text[100],key[100];
  printf("Enter text: ");
  gets(text);
  printf("Enter key: ");
  gets(key);
  
  encrypt(text,key);
  
  printf("Encrypted msg: %s",text);
}

void encrypt(char text[],char key[]){
  int i,j;
  int textlen=strlen(text);
  int keylen=strlen(key);
  
  for(i=0,j=0;i<textlen;i++){
    if(text[i]>='A' && text[i]<='Z'){
      text[i]= ((text[i]-'A')+(text[j%keylen]-'A'))%26+'A';
      j++;
    }else if(text[i]>='a' && text[i]<='z'){
      text[i]= ((text[i]-'a')+(text[j%keylen]-'a'))%26+'a';
      j++;
    }
  }
}