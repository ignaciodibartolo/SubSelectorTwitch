#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include <math.h>
#include <time.h>
#define N 10000
#define M 64


void cargarArchivo(char lst[N][M]);
void seleccionarGanador(char lst[N][M], int pos);


int main(){
  srand(time(NULL));
  char lst[N][M] = {0};
  cargarArchivo(lst);
}


void cargarArchivo(char lst[N][M]){
  FILE* arch = fopen("subscriber-list.csv", "r");
  char l;
  int i = 0, t = 0, pos = 0;
  printf("\t\tSUBSCRIPTORES CARGADOS:\n\n");
  while (l != EOF){
    l = fgetc(arch);
    while (l != '\n' && l != EOF){
      if (l == ','){i++;}
      if (i == 0){lst[pos][t] = l;}
      l = fgetc(arch);
      t++;
    }
    printf("%s\n", lst[pos]);
    i = 0;
    t = 0;
    pos++;
  }
  seleccionarGanador (lst, pos);
}


void seleccionarGanador(char lst[N][M], int pos){
  int i = rand() % (pos-1);
  printf("\n\n\t\tEL GANADOR ES: \n");
  printf("%s\n\n", lst[i]);
}
