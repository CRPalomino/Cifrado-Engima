#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

//Declaración de estructuras
typedef struct
{
  char msj[1024];
  int alf[1024];
  int n1;
  int n2;
  int n3;
}codigo;

//Invocación de archivos
FILE *Entrada;
FILE *Salida;

//Declaración de funciones
void cifrar(FILE *Entrada);
void descifrar(FILE *Entrada);
codigo guardarc(FILE *Entrada);
codigo guardard(FILE *Entrada);
codigo alfabeto1(codigo c1);
codigo alfabeto2(codigo c1);
codigo alfabeto3(codigo c1);
codigo movimiento(codigo c1, int n);

//Codigo main (Menu Principal)
int main() {
  system ("Color 0c");
  printf("ENIGMA\n");
  sleep(5);
  system ("Color 0A");
  char o[12];
  printf("Escribe la opcion para ejecutar:\n");
  printf("Cifrar\n");
  printf("Descifrar\n");
  scanf("%s",o);
  fflush(stdin);
  if (strcmp(o,"Cifrar")==0){
    Entrada= fopen("C:\\Proyecto\\Entrada.txt","r");
    if (Entrada== NULL){
      system("cls");
      system("color 0C");
      printf("ERROR, ARCHIVO NO EJECUTABLE\n");
      printf("GRACIAS POR USAR ENIGMA.EXE\n");
      system("pause");
      return 0;
    }
    cifrar(Entrada);
  }
  else if(strcmp(o,"Descifrar")==0){
    Entrada= fopen("C:\\Proyecto\\Entrada.txt","r");
    if (Entrada==NULL){
      system("cls");
      system("color 0C");
      printf("ERROR, ARCHIVO NO EJECUTABLE\n");
      printf("GRACIAS POR USAR ENIGMA.EXE\n");
      system("pause");
      return 0;
    }
    descifrar(Entrada);
  }
  else{
    system("cls");
    system("color 0C");
    printf("ERROR, OPCION NO DISPONIBLE\n");
    printf("GRACIAS POR USAR ENIGMA.EXE\n");
    system("pause");
    return 0;
  }
  system ("cls");
  system ("color 0c");
  printf("GRACIAS POR USAR ENIGMA.EXE\n");
  system("pause");
  return 0;
}

//Función de cifrado
void cifrar(FILE *Entrada){
  codigo original,cifrado1,cifrado2,cifrado3;
  original=guardarc(Entrada);
  fclose (Entrada);
  cifrado1=alfabeto1(original);
  cifrado2=alfabeto2(cifrado1);
  cifrado3=alfabeto3(cifrado2);
  Salida= fopen("C:\\Proyecto\\Salida.txt","w");
  fputs(cifrado3.msj, Salida);
  fclose (Salida);
  system("cls");
  printf("Primer numero de decodificacion: %i\n", cifrado3.n1);
  system("pause");
  system ("cls");
  printf("Segundo numero de decodificacion: %i\n", cifrado3.n2);
  system("pause");
  system ("cls");
  printf("Tercer numero de decodificacion: %i\n", cifrado3.n3);
  system("pause");
  system ("cls");
}

//Función de decifrado
void descifrar(FILE *Entrada){
  codigo original, cifrado1, cifrado2, cifrado3;
  original=guardard(Entrada);
  cifrado1=alfabeto3(original);
  cifrado2=alfabeto2(cifrado1);
  cifrado3=alfabeto1(cifrado2);
  Salida= fopen("C:\\Proyecto\\Salida.txt","w");
  fputs(cifrado3.msj, Salida);
  fclose (Salida);
}

//Función de guardado en estructura para cifrado
codigo guardarc(FILE *Entrada){
  codigo c1;
  fgets(c1.msj,1024,Entrada);
  for (int c=0;c<1024;c++)
    c1.alf[c]=0;
  srand(time(NULL));
  c1.n1=rand()%69;
  c1.n2=rand()%69;
  c1.n3=rand()%69;
  fclose(Entrada);
  return c1;
}

//Función de guardado de estructura para descifrado
codigo guardard(FILE *Entrada){
  codigo c1;
  fgets(c1.msj,1024,Entrada);
  for (int c=0;c<1024;c++)
    c1.alf[c]=0;
  system ("cls");
  fflush(stdin);
  printf("Primer numero de decodificacion: ");
  scanf("%i", &c1.n1);
  c1.n1=68-c1.n1;
  system ("cls");
  printf("Segundo numero de decodificacion: ");
  scanf("%i", &c1.n2);
  c1.n2=68-c1.n2;
  system ("cls");
  printf("Tercer numero de decodificacion: ");
  scanf("%i", &c1.n3);
  c1.n3=68-c1.n3;
  system ("cls");
  fclose(Entrada);
  return c1;
}

//Funciones para la modificacion de texto por intercambio de caracteres alfanumericos
  //Primera función
codigo alfabeto1(codigo c1){
  for (int c=0;c<1024;c++){
    if (c1.msj[c]=='a')
      c1.alf[c]=1;
    else if (c1.msj[c]=='b')
      c1.alf[c]=2;
    else if (c1.msj[c]=='c')
      c1.alf[c]=3;
    else if (c1.msj[c]=='d')
      c1.alf[c]=4;
    else if (c1.msj[c]=='e')
      c1.alf[c]=5;
    else if (c1.msj[c]=='f')
      c1.alf[c]=6;
    else if (c1.msj[c]=='g')
      c1.alf[c]=7;
    else if (c1.msj[c]=='h')
      c1.alf[c]=8;
    else if (c1.msj[c]=='i')
      c1.alf[c]=9;
    else if (c1.msj[c]=='j')
      c1.alf[c]=10;
    else if (c1.msj[c]=='k')
      c1.alf[c]=11;
    else if (c1.msj[c]=='l')
      c1.alf[c]=12;
    else if (c1.msj[c]=='m')
      c1.alf[c]=13;
    else if (c1.msj[c]=='n')
      c1.alf[c]=14;
    else if (c1.msj[c]=='o')
      c1.alf[c]=15;
    else if (c1.msj[c]=='p')
      c1.alf[c]=16;
    else if (c1.msj[c]=='q')
      c1.alf[c]=17;
    else if (c1.msj[c]=='r')
      c1.alf[c]=18;
    else if (c1.msj[c]=='s')
      c1.alf[c]=19;
    else if (c1.msj[c]=='t')
      c1.alf[c]=20;
    else if (c1.msj[c]=='u')
      c1.alf[c]=21;
    else if (c1.msj[c]=='v')
      c1.alf[c]=22;
    else if (c1.msj[c]=='w')
      c1.alf[c]=23;
    else if (c1.msj[c]=='x')
      c1.alf[c]=24;
    else if (c1.msj[c]=='y')
      c1.alf[c]=25;
    else if (c1.msj[c]=='z')
      c1.alf[c]=26;
    else if (c1.msj[c]=='A')
      c1.alf[c]=27;
    else if (c1.msj[c]=='B')
      c1.alf[c]=28;
    else if (c1.msj[c]=='C')
      c1.alf[c]=29;
    else if (c1.msj[c]=='D')
      c1.alf[c]=30;
    else if (c1.msj[c]=='E')
      c1.alf[c]=31;
    else if (c1.msj[c]=='F')
      c1.alf[c]=32;
    else if (c1.msj[c]=='G')
      c1.alf[c]=33;
    else if (c1.msj[c]=='H')
      c1.alf[c]=34;
    else if (c1.msj[c]=='I')
      c1.alf[c]=35;
    else if (c1.msj[c]=='J')
      c1.alf[c]=36;
    else if (c1.msj[c]=='K')
      c1.alf[c]=37;
    else if (c1.msj[c]=='L')
      c1.alf[c]=38;
    else if (c1.msj[c]=='M')
      c1.alf[c]=39;
    else if (c1.msj[c]=='N')
      c1.alf[c]=40;
    else if (c1.msj[c]=='O')
      c1.alf[c]=41;
    else if (c1.msj[c]=='P')
      c1.alf[c]=42;
    else if (c1.msj[c]=='Q')
      c1.alf[c]=43;
    else if (c1.msj[c]=='R')
      c1.alf[c]=44;
    else if (c1.msj[c]=='S')
      c1.alf[c]=45;
    else if (c1.msj[c]=='T')
      c1.alf[c]=46;
    else if (c1.msj[c]=='U')
      c1.alf[c]=47;
    else if (c1.msj[c]=='V')
      c1.alf[c]=48;
    else if (c1.msj[c]=='W')
      c1.alf[c]=49;
    else if (c1.msj[c]=='X')
      c1.alf[c]=50;
    else if (c1.msj[c]=='Y')
      c1.alf[c]=51;
    else if (c1.msj[c]=='Z')
      c1.alf[c]=52;
    else if (c1.msj[c]=='0')
      c1.alf[c]=53;
    else if (c1.msj[c]=='1')
      c1.alf[c]=54;
    else if (c1.msj[c]=='2')
      c1.alf[c]=55;
    else if (c1.msj[c]=='3')
      c1.alf[c]=56;
    else if (c1.msj[c]=='4')
      c1.alf[c]=57;
    else if (c1.msj[c]=='5')
      c1.alf[c]=58;
    else if (c1.msj[c]=='6')
      c1.alf[c]=59;
    else if (c1.msj[c]=='7')
      c1.alf[c]=60;
    else if (c1.msj[c]=='8')
      c1.alf[c]=61;
    else if (c1.msj[c]=='9')
      c1.alf[c]=62;
    else if (c1.msj[c]=='?')
      c1.alf[c]=63;
    else if (c1.msj[c]=='!')
      c1.alf[c]=64;
    else if (c1.msj[c]=='.')
      c1.alf[c]=65;
    else if (c1.msj[c]==',')
      c1.alf[c]=66;
    else if (c1.msj[c]=='\'')
      c1.alf[c]=67;
    else if (c1.msj[c]==' ')
      c1.alf[c]=68;
    else
     c1.alf[c]=-1;
  }
  c1=movimiento(c1, c1.n1);
  for (int c=0;c<1024;c++){
    if (c1.alf[c]==1)
      c1.msj[c]='a';
    else if (c1.alf[c]==2)
      c1.msj[c]='b';
    else if (c1.alf[c]==3)
      c1.msj[c]='c';
    else if (c1.alf[c]==4)
      c1.msj[c]='d';
    else if (c1.alf[c]==5)
      c1.msj[c]='e';
    else if (c1.alf[c]==6)
      c1.msj[c]='f';
    else if (c1.alf[c]==7)
      c1.msj[c]='g';
    else if (c1.alf[c]==8)
      c1.msj[c]='h';
    else if (c1.alf[c]==9)
      c1.msj[c]='i';
    else if (c1.alf[c]==10)
      c1.msj[c]='j';
    else if (c1.alf[c]==11)
      c1.msj[c]='k';
    else if (c1.alf[c]==12)
      c1.msj[c]='l';
    else if (c1.alf[c]==13)
      c1.msj[c]='m';
    else if (c1.alf[c]==14)
      c1.msj[c]='n';
    else if (c1.alf[c]==15)
      c1.msj[c]='o';
    else if (c1.alf[c]==16)
      c1.msj[c]='p';
    else if (c1.alf[c]==17)
      c1.msj[c]='q';
    else if (c1.alf[c]==18)
      c1.msj[c]='r';
    else if (c1.alf[c]==19)
      c1.msj[c]='s';
    else if (c1.alf[c]==20)
      c1.msj[c]='t';
    else if (c1.alf[c]==21)
      c1.msj[c]='u';
    else if (c1.alf[c]==22)
      c1.msj[c]='v';
    else if (c1.alf[c]==23)
      c1.msj[c]='w';
    else if (c1.alf[c]==24)
      c1.msj[c]='x';
    else if (c1.alf[c]==25)
      c1.msj[c]='y';
    else if (c1.alf[c]==26)
      c1.msj[c]='z';
    else if (c1.alf[c]==27)
      c1.msj[c]='A';
    else if (c1.alf[c]==28)
      c1.msj[c]='B';
    else if (c1.alf[c]==29)
      c1.msj[c]='C';
    else if (c1.alf[c]==30)
      c1.msj[c]='D';
    else if (c1.alf[c]==31)
      c1.msj[c]='E';
    else if (c1.alf[c]==32)
      c1.msj[c]='F';
    else if (c1.alf[c]==33)
      c1.msj[c]='G';
    else if (c1.alf[c]==34)
      c1.msj[c]='H';
    else if (c1.alf[c]==35)
      c1.msj[c]='I';
    else if (c1.alf[c]==36)
      c1.msj[c]='J';
    else if (c1.alf[c]==37)
      c1.msj[c]='K';
    else if (c1.alf[c]==38)
      c1.msj[c]='L';
    else if (c1.alf[c]==39)
      c1.msj[c]='M';
    else if (c1.alf[c]==40)
      c1.msj[c]='N';
    else if (c1.alf[c]==41)
      c1.msj[c]='O';
    else if (c1.alf[c]==42)
      c1.msj[c]='P';
    else if (c1.alf[c]==43)
      c1.msj[c]='Q';
    else if (c1.alf[c]==44)
      c1.msj[c]='R';
    else if (c1.alf[c]==45)
      c1.msj[c]='S';
    else if (c1.alf[c]==46)
      c1.msj[c]='T';
    else if (c1.alf[c]==47)
      c1.msj[c]='U';
    else if (c1.alf[c]==48)
      c1.msj[c]='V';
    else if (c1.alf[c]==49)
      c1.msj[c]='W';
    else if (c1.alf[c]==50)
      c1.msj[c]='X';
    else if (c1.alf[c]==51)
      c1.msj[c]='Y';
    else if (c1.alf[c]==52)
      c1.msj[c]='Z';
    else if (c1.alf[c]==53)
      c1.msj[c]='0';
    else if (c1.alf[c]==54)
      c1.msj[c]='1';
    else if (c1.alf[c]==55)
      c1.msj[c]='2';
    else if (c1.alf[c]==56)
      c1.msj[c]='3';
    else if (c1.alf[c]==57)
      c1.msj[c]='4';
    else if (c1.alf[c]==58)
      c1.msj[c]='5';
    else if (c1.alf[c]==59)
      c1.msj[c]='6';
    else if (c1.alf[c]==60)
      c1.msj[c]='7';
    else if (c1.alf[c]==61)
      c1.msj[c]='8';
    else if (c1.alf[c]==62)
      c1.msj[c]='9';
    else if (c1.alf[c]==63)
      c1.msj[c]='?';
    else if (c1.alf[c]==64)
      c1.msj[c]='!';
    else if (c1.alf[c]==65)
      c1.msj[c]='.';
    else if (c1.alf[c]==66)
      c1.msj[c]=',';
    else if (c1.alf[c]==67)
      c1.msj[c]='\'';
    else if (c1.alf[c]==68)
      c1.msj[c]=' ';
    else
     c1.msj[c]='\0';
  }
  return c1;
}

  //Segunda función
codigo alfabeto2(codigo c1){
  for (int c=0;c<1024;c++){
    if (c1.msj[c]=='\'')
      c1.alf[c]=1;
    else if (c1.msj[c]=='1')
      c1.alf[c]=2;
    else if (c1.msj[c]=='2')
      c1.alf[c]=3;
    else if (c1.msj[c]=='3')
      c1.alf[c]=4;
    else if (c1.msj[c]=='4')
      c1.alf[c]=5;
    else if (c1.msj[c]=='5')
      c1.alf[c]=6;
    else if (c1.msj[c]=='6')
      c1.alf[c]=7;
    else if (c1.msj[c]=='7')
      c1.alf[c]=8;
    else if (c1.msj[c]=='8')
      c1.alf[c]=9;
    else if (c1.msj[c]=='9')
      c1.alf[c]=10;
    else if (c1.msj[c]=='0')
      c1.alf[c]=11;
    else if (c1.msj[c]=='!')
      c1.alf[c]=12;
    else if (c1.msj[c]=='Q')
      c1.alf[c]=13;
    else if (c1.msj[c]=='W')
      c1.alf[c]=14;
    else if (c1.msj[c]=='E')
      c1.alf[c]=15;
    else if (c1.msj[c]=='R')
      c1.alf[c]=16;
    else if (c1.msj[c]=='T')
      c1.alf[c]=17;
    else if (c1.msj[c]=='Y')
      c1.alf[c]=18;
    else if (c1.msj[c]=='U')
      c1.alf[c]=19;
    else if (c1.msj[c]=='I')
      c1.alf[c]=20;
    else if (c1.msj[c]=='O')
      c1.alf[c]=21;
    else if (c1.msj[c]=='P')
      c1.alf[c]=22;
    else if (c1.msj[c]=='A')
      c1.alf[c]=23;
    else if (c1.msj[c]=='S')
      c1.alf[c]=24;
    else if (c1.msj[c]=='D')
      c1.alf[c]=25;
    else if (c1.msj[c]=='F')
      c1.alf[c]=26;
    else if (c1.msj[c]=='G')
      c1.alf[c]=27;
    else if (c1.msj[c]=='H')
      c1.alf[c]=28;
    else if (c1.msj[c]=='J')
      c1.alf[c]=29;
    else if (c1.msj[c]=='K')
      c1.alf[c]=30;
    else if (c1.msj[c]=='L')
      c1.alf[c]=31;
    else if (c1.msj[c]=='Z')
      c1.alf[c]=32;
    else if (c1.msj[c]=='X')
      c1.alf[c]=33;
    else if (c1.msj[c]=='C')
      c1.alf[c]=34;
    else if (c1.msj[c]=='V')
      c1.alf[c]=35;
    else if (c1.msj[c]=='B')
      c1.alf[c]=36;
    else if (c1.msj[c]=='N')
      c1.alf[c]=37;
    else if (c1.msj[c]=='M')
      c1.alf[c]=38;
    else if (c1.msj[c]==',')
      c1.alf[c]=39;
    else if (c1.msj[c]=='.')
      c1.alf[c]=40;
    else if (c1.msj[c]=='?')
      c1.alf[c]=41;
    else if (c1.msj[c]==' ')
      c1.alf[c]=42;
    else if (c1.msj[c]=='q')
      c1.alf[c]=43;
    else if (c1.msj[c]=='w')
      c1.alf[c]=44;
    else if (c1.msj[c]=='e')
      c1.alf[c]=45;
    else if (c1.msj[c]=='r')
      c1.alf[c]=46;
    else if (c1.msj[c]=='t')
      c1.alf[c]=47;
    else if (c1.msj[c]=='y')
      c1.alf[c]=48;
    else if (c1.msj[c]=='u')
      c1.alf[c]=49;
    else if (c1.msj[c]=='i')
      c1.alf[c]=50;
    else if (c1.msj[c]=='o')
      c1.alf[c]=51;
    else if (c1.msj[c]=='p')
      c1.alf[c]=52;
    else if (c1.msj[c]=='a')
      c1.alf[c]=53;
    else if (c1.msj[c]=='s')
      c1.alf[c]=54;
    else if (c1.msj[c]=='d')
      c1.alf[c]=55;
    else if (c1.msj[c]=='f')
      c1.alf[c]=56;
    else if (c1.msj[c]=='g')
      c1.alf[c]=57;
    else if (c1.msj[c]=='h')
      c1.alf[c]=58;
    else if (c1.msj[c]=='j')
      c1.alf[c]=59;
    else if (c1.msj[c]=='k')
      c1.alf[c]=60;
    else if (c1.msj[c]=='l')
      c1.alf[c]=61;
    else if (c1.msj[c]=='z')
      c1.alf[c]=62;
    else if (c1.msj[c]=='x')
      c1.alf[c]=63;
    else if (c1.msj[c]=='c')
      c1.alf[c]=64;
    else if (c1.msj[c]=='v')
      c1.alf[c]=65;
    else if (c1.msj[c]=='b')
      c1.alf[c]=66;
    else if (c1.msj[c]=='n')
      c1.alf[c]=67;
    else if (c1.msj[c]=='m')
      c1.alf[c]=68;
    else
     c1.alf[c]=-1;
  }
  c1=movimiento(c1, c1.n2);
  for (int c=0;c<1024;c++){
    if (c1.alf[c]==1)
      c1.msj[c]='\'';
    else if (c1.alf[c]==2)
      c1.msj[c]='1';
    else if (c1.alf[c]==3)
      c1.msj[c]='2';
    else if (c1.alf[c]==4)
      c1.msj[c]='3';
    else if (c1.alf[c]==5)
      c1.msj[c]='4';
    else if (c1.alf[c]==6)
      c1.msj[c]='5';
    else if (c1.alf[c]==7)
      c1.msj[c]='6';
    else if (c1.alf[c]==8)
      c1.msj[c]='7';
    else if (c1.alf[c]==9)
      c1.msj[c]='8';
    else if (c1.alf[c]==10)
      c1.msj[c]='9';
    else if (c1.alf[c]==11)
      c1.msj[c]='0';
    else if (c1.alf[c]==12)
      c1.msj[c]='!';
    else if (c1.alf[c]==13)
      c1.msj[c]='Q';
    else if (c1.alf[c]==14)
      c1.msj[c]='W';
    else if (c1.alf[c]==15)
      c1.msj[c]='E';
    else if (c1.alf[c]==16)
      c1.msj[c]='R';
    else if (c1.alf[c]==17)
      c1.msj[c]='T';
    else if (c1.alf[c]==18)
      c1.msj[c]='Y';
    else if (c1.alf[c]==19)
      c1.msj[c]='U';
    else if (c1.alf[c]==20)
      c1.msj[c]='I';
    else if (c1.alf[c]==21)
      c1.msj[c]='O';
    else if (c1.alf[c]==22)
      c1.msj[c]='P';
    else if (c1.alf[c]==23)
      c1.msj[c]='A';
    else if (c1.alf[c]==24)
      c1.msj[c]='S';
    else if (c1.alf[c]==25)
      c1.msj[c]='D';
    else if (c1.alf[c]==26)
      c1.msj[c]='F';
    else if (c1.alf[c]==27)
      c1.msj[c]='G';
    else if (c1.alf[c]==28)
      c1.msj[c]='H';
    else if (c1.alf[c]==29)
      c1.msj[c]='J';
    else if (c1.alf[c]==30)
      c1.msj[c]='K';
    else if (c1.alf[c]==31)
      c1.msj[c]='K';
    else if (c1.alf[c]==32)
      c1.msj[c]='Z';
    else if (c1.alf[c]==33)
      c1.msj[c]='X';
    else if (c1.alf[c]==34)
      c1.msj[c]='C';
    else if (c1.alf[c]==35)
      c1.msj[c]='V';
    else if (c1.alf[c]==36)
      c1.msj[c]='B';
    else if (c1.alf[c]==37)
      c1.msj[c]='N';
    else if (c1.alf[c]==38)
      c1.msj[c]='M';
    else if (c1.alf[c]==39)
      c1.msj[c]=',';
    else if (c1.alf[c]==40)
      c1.msj[c]='.';
    else if (c1.alf[c]==41)
      c1.msj[c]='?';
    else if (c1.alf[c]==42)
      c1.msj[c]=' ';
    else if (c1.alf[c]==43)
      c1.msj[c]='q';
    else if (c1.alf[c]==44)
      c1.msj[c]='w';
    else if (c1.alf[c]==45)
      c1.msj[c]='e';
    else if (c1.alf[c]==46)
      c1.msj[c]='r';
    else if (c1.alf[c]==47)
      c1.msj[c]='t';
    else if (c1.alf[c]==48)
      c1.msj[c]='y';
    else if (c1.alf[c]==49)
      c1.msj[c]='u';
    else if (c1.alf[c]==50)
      c1.msj[c]='i';
    else if (c1.alf[c]==51)
      c1.msj[c]='o';
    else if (c1.alf[c]==52)
      c1.msj[c]='p';
    else if (c1.alf[c]==53)
      c1.msj[c]='a';
    else if (c1.alf[c]==54)
      c1.msj[c]='s';
    else if (c1.alf[c]==55)
      c1.msj[c]='d';
    else if (c1.alf[c]==56)
      c1.msj[c]='f';
    else if (c1.alf[c]==57)
      c1.msj[c]='g';
    else if (c1.alf[c]==58)
      c1.msj[c]='h';
    else if (c1.alf[c]==59)
      c1.msj[c]='j';
    else if (c1.alf[c]==60)
      c1.msj[c]='k';
    else if (c1.alf[c]==61)
      c1.msj[c]='l';
    else if (c1.alf[c]==62)
      c1.msj[c]='z';
    else if (c1.alf[c]==63)
      c1.msj[c]='x';
    else if (c1.alf[c]==64)
      c1.msj[c]='c';
    else if (c1.alf[c]==65)
      c1.msj[c]='v';
    else if (c1.alf[c]==66)
      c1.msj[c]='b';
    else if (c1.alf[c]==67)
      c1.msj[c]='n';
    else if (c1.alf[c]==68)
      c1.msj[c]='m';
    else
     c1.msj[c]='\0';
  }
  return c1;
}

  //Tercera función
codigo alfabeto3(codigo c1){
  for (int c=0;c<1024;c++){
    if (c1.msj[c]=='?')
      c1.alf[c]=1;
    else if (c1.msj[c]=='!')
      c1.alf[c]=2;
    else if (c1.msj[c]=='.')
      c1.alf[c]=3;
    else if (c1.msj[c]==',')
      c1.alf[c]=4;
    else if (c1.msj[c]=='\'')
      c1.alf[c]=5;
    else if (c1.msj[c]==' ')
      c1.alf[c]=6;
    else if (c1.msj[c]=='a')
      c1.alf[c]=7;
    else if (c1.msj[c]=='A')
      c1.alf[c]=8;
    else if (c1.msj[c]=='z')
      c1.alf[c]=9;
    else if (c1.msj[c]=='Z')
      c1.alf[c]=10;
    else if (c1.msj[c]=='b')
      c1.alf[c]=11;
    else if (c1.msj[c]=='B')
      c1.alf[c]=12;
    else if (c1.msj[c]=='y')
      c1.alf[c]=13;
    else if (c1.msj[c]=='Y')
      c1.alf[c]=14;
    else if (c1.msj[c]=='c')
      c1.alf[c]=15;
    else if (c1.msj[c]=='C')
      c1.alf[c]=16;
    else if (c1.msj[c]=='x')
      c1.alf[c]=17;
    else if (c1.msj[c]=='X')
      c1.alf[c]=18;
    else if (c1.msj[c]=='d')
      c1.alf[c]=19;
    else if (c1.msj[c]=='D')
      c1.alf[c]=20;
    else if (c1.msj[c]=='w')
      c1.alf[c]=21;
    else if (c1.msj[c]=='W')
      c1.alf[c]=22;
    else if (c1.msj[c]=='e')
      c1.alf[c]=23;
    else if (c1.msj[c]=='E')
      c1.alf[c]=24;
    else if (c1.msj[c]=='v')
      c1.alf[c]=25;
    else if (c1.msj[c]=='V')
      c1.alf[c]=26;
    else if (c1.msj[c]=='f')
      c1.alf[c]=27;
    else if (c1.msj[c]=='F')
      c1.alf[c]=28;
    else if (c1.msj[c]=='u')
      c1.alf[c]=29;
    else if (c1.msj[c]=='U')
      c1.alf[c]=30;
    else if (c1.msj[c]=='g')
      c1.alf[c]=31;
    else if (c1.msj[c]=='G')
      c1.alf[c]=32;
    else if (c1.msj[c]=='t')
      c1.alf[c]=33;
    else if (c1.msj[c]=='T')
      c1.alf[c]=34;
    else if (c1.msj[c]=='h')
      c1.alf[c]=35;
    else if (c1.msj[c]=='H')
      c1.alf[c]=36;
    else if (c1.msj[c]=='s')
      c1.alf[c]=37;
    else if (c1.msj[c]=='S')
      c1.alf[c]=38;
    else if (c1.msj[c]=='i')
      c1.alf[c]=39;
    else if (c1.msj[c]=='I')
      c1.alf[c]=40;
    else if (c1.msj[c]=='r')
      c1.alf[c]=41;
    else if (c1.msj[c]=='R')
      c1.alf[c]=42;
    else if (c1.msj[c]=='j')
      c1.alf[c]=43;
    else if (c1.msj[c]=='J')
      c1.alf[c]=44;
    else if (c1.msj[c]=='q')
      c1.alf[c]=45;
    else if (c1.msj[c]=='Q')
      c1.alf[c]=46;
    else if (c1.msj[c]=='k')
      c1.alf[c]=47;
    else if (c1.msj[c]=='K')
      c1.alf[c]=48;
    else if (c1.msj[c]=='p')
      c1.alf[c]=49;
    else if (c1.msj[c]=='P')
      c1.alf[c]=50;
    else if (c1.msj[c]=='l')
      c1.alf[c]=51;
    else if (c1.msj[c]=='L')
      c1.alf[c]=52;
    else if (c1.msj[c]=='o')
      c1.alf[c]=53;
    else if (c1.msj[c]=='O')
      c1.alf[c]=54;
    else if (c1.msj[c]=='m')
      c1.alf[c]=55;
    else if (c1.msj[c]=='M')
      c1.alf[c]=56;
    else if (c1.msj[c]=='n')
      c1.alf[c]=57;
    else if (c1.msj[c]=='N')
      c1.alf[c]=58;
    else if (c1.msj[c]=='0')
      c1.alf[c]=59;
    else if (c1.msj[c]=='1')
      c1.alf[c]=60;
    else if (c1.msj[c]=='2')
      c1.alf[c]=61;
    else if (c1.msj[c]=='3')
      c1.alf[c]=62;
    else if (c1.msj[c]=='4')
      c1.alf[c]=63;
    else if (c1.msj[c]=='5')
      c1.alf[c]=64;
    else if (c1.msj[c]=='6')
      c1.alf[c]=65;
    else if (c1.msj[c]=='7')
      c1.alf[c]=66;
    else if (c1.msj[c]=='8')
      c1.alf[c]=67;
    else if (c1.msj[c]=='9')
      c1.alf[c]=68;
    else
     c1.alf[c]=-1;
  }
  c1=movimiento(c1, c1.n3);
  for (int c=0;c<1024;c++){
    if (c1.alf[c]==1)
      c1.msj[c]='?';
    else if (c1.alf[c]==2)
      c1.msj[c]='!';
    else if (c1.alf[c]==3)
      c1.msj[c]='.';
    else if (c1.alf[c]==4)
      c1.msj[c]=',';
    else if (c1.alf[c]==5)
      c1.msj[c]='\'';
    else if (c1.alf[c]==6)
      c1.msj[c]=' ';
    else if (c1.alf[c]==7)
      c1.msj[c]='a';
    else if (c1.alf[c]==8)
      c1.msj[c]='A';
    else if (c1.alf[c]==9)
      c1.msj[c]='z';
    else if (c1.alf[c]==10)
      c1.msj[c]='Z';
    else if (c1.alf[c]==11)
      c1.msj[c]='b';
    else if (c1.alf[c]==12)
      c1.msj[c]='B';
    else if (c1.alf[c]==13)
      c1.msj[c]='y';
    else if (c1.alf[c]==14)
      c1.msj[c]='Y';
    else if (c1.alf[c]==15)
      c1.msj[c]='c';
    else if (c1.alf[c]==16)
      c1.msj[c]='C';
    else if (c1.alf[c]==17)
      c1.msj[c]='x';
    else if (c1.alf[c]==18)
      c1.msj[c]='X';
    else if (c1.alf[c]==19)
      c1.msj[c]='d';
    else if (c1.alf[c]==20)
      c1.msj[c]='D';
    else if (c1.alf[c]==21)
      c1.msj[c]='w';
    else if (c1.alf[c]==22)
      c1.msj[c]='W';
    else if (c1.alf[c]==23)
      c1.msj[c]='e';
    else if (c1.alf[c]==24)
      c1.msj[c]='E';
    else if (c1.alf[c]==25)
      c1.msj[c]='v';
    else if (c1.alf[c]==26)
      c1.msj[c]='V';
    else if (c1.alf[c]==27)
      c1.msj[c]='f';
    else if (c1.alf[c]==28)
      c1.msj[c]='F';
    else if (c1.alf[c]==29)
      c1.msj[c]='u';
    else if (c1.alf[c]==30)
      c1.msj[c]='U';
    else if (c1.alf[c]==31)
      c1.msj[c]='g';
    else if (c1.alf[c]==32)
      c1.msj[c]='G';
    else if (c1.alf[c]==33)
      c1.msj[c]='t';
    else if (c1.alf[c]==34)
      c1.msj[c]='T';
    else if (c1.alf[c]==35)
      c1.msj[c]='h';
    else if (c1.alf[c]==36)
      c1.msj[c]='H';
    else if (c1.alf[c]==37)
      c1.msj[c]='s';
    else if (c1.alf[c]==38)
      c1.msj[c]='S';
    else if (c1.alf[c]==39)
      c1.msj[c]='i';
    else if (c1.alf[c]==40)
      c1.msj[c]='I';
    else if (c1.alf[c]==41)
      c1.msj[c]='r';
    else if (c1.alf[c]==42)
      c1.msj[c]='R';
    else if (c1.alf[c]==43)
      c1.msj[c]='j';
    else if (c1.alf[c]==44)
      c1.msj[c]='J';
    else if (c1.alf[c]==45)
      c1.msj[c]='q';
    else if (c1.alf[c]==46)
      c1.msj[c]='Q';
    else if (c1.alf[c]==47)
      c1.msj[c]='k';
    else if (c1.alf[c]==48)
      c1.msj[c]='K';
    else if (c1.alf[c]==49)
      c1.msj[c]='p';
    else if (c1.alf[c]==50)
      c1.msj[c]='P';
    else if (c1.alf[c]==51)
      c1.msj[c]='l';
    else if (c1.alf[c]==52)
      c1.msj[c]='L';
    else if (c1.alf[c]==53)
      c1.msj[c]='o';
    else if (c1.alf[c]==54)
      c1.msj[c]='O';
    else if (c1.alf[c]==55)
      c1.msj[c]='m';
    else if (c1.alf[c]==56)
      c1.msj[c]='M';
    else if (c1.alf[c]==57)
      c1.msj[c]='n';
    else if (c1.alf[c]==58)
      c1.msj[c]='N';
    else if (c1.alf[c]==59)
      c1.msj[c]='0';
    else if (c1.alf[c]==60)
      c1.msj[c]='1';
    else if (c1.alf[c]==61)
      c1.msj[c]='2';
    else if (c1.alf[c]==62)
      c1.msj[c]='3';
    else if (c1.alf[c]==63)
      c1.msj[c]='4';
    else if (c1.alf[c]==64)
      c1.msj[c]='5';
    else if (c1.alf[c]==65)
      c1.msj[c]='6';
    else if (c1.alf[c]==66)
      c1.msj[c]='7';
    else if (c1.alf[c]==67)
      c1.msj[c]='8';
    else if (c1.alf[c]==68)
      c1.msj[c]='9';
    else
     c1.msj[c]='\0';
  }
  return c1;
}

//Función que hace el intercambio de caracteres
codigo movimiento(codigo c1, int n){
int c2;
  for (int c=0;c<1024;c++,c2=0) {
    if (c1.alf[c]>0){
      for(c2=0;c2<n;c2++){
        c1.alf[c]++;
        if (c1.alf[c]==69)
          c1.alf[c]=0;
      }
    }
    else
      c1.alf[c]=-1;
  }
  return c1;
}
