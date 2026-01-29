#include<stdio.h>
#include<string.h>
void main(){
  int i,j;
  char data[30];
  printf("Enter u r name: ");
  gets(data);
  printf("Enter key: ");
  scanf("%d",&j);
  for(i=0;i<strlen(data);i++){
    if(data[i]==' '){
    }else{
      if(data[i]>'x'){
        data[i]-=26;
      }
      data[i]+=j;
    }
  }
  
  printf("Encripted msg is: %s",data);
}
