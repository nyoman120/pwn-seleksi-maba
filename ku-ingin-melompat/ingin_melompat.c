//gcc -g -no-pie -fno-stack-protector -fno-pic -fno-builtin -mpreferred-stack-boundary=2 -m32 ingin_melompat.c -o ingin_melompat     
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>

int wallet = 18;
char burung[8];

void secret_message(){
  system("/bin/sh");
}

void init(){
setvbuf(stdin, NULL, _IONBF, 0);
setvbuf(stdout, NULL, _IONBF, 0);
setvbuf(stderr, NULL, _IONBF, 0);
}

void buy_flag(){
  if(wallet < 999999999999) printf("kamu terlalu lemah dude :)\n");
    else secret_message();
}
void jual_burung(){
    char buffer[64];
    printf("burung apa yang kamu mau jual ?\n");
    read(0,buffer,128);
}
void menu(){
  printf("+--------------------------------+\n");
  printf("------------PASAR BURUNG----------\n");
  printf("+--------------------------------+\n");
  printf("1. beli flag (999999 ruby)\n");
  printf("2. beli garuda (10 ruby)\n");
  printf("3. lihat burung yang udah di beli\n");
  printf("4. jual burung\n");
  printf("5. check wallet\n");
  printf("6. exit\n");
}

int main()
{
  while(1){
  char pilihan;
  init();
  menu();
  printf(">>");
  fflush(stdout);

  scanf("%s",&pilihan);
  switch(pilihan){
    case '1' : 
    buy_flag();
    break;
    case '2' :
    if(wallet > 10){
      printf("burung berhasil di beli\n");
      wallet = wallet - 10;
      strcpy(burung,"garuda");
    } else printf("uang gak cukup!\n");
    break;
    case '3' :
    if(strlen(burung) == 0) printf("belum ada yang kamu beli!\n");
    else printf("burung yg dah di beli : %s\n",burung);
    break;
    case '4' :
    jual_burung();
    break;
    case '5' :
    printf("isi wallet : %d ruby\n",wallet);
    break;
    case '6' :
    printf("makasih udah berkunjung :)\n");
    exit(0);
    break;
    default :
    fprintf(stderr,"bad request!\n");
    exit(0);
  }
}

}
