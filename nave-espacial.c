#include <stdio.h>  //stdio = standard input-output header, que significa "cabeçalho padrão de entrada/saída
#include <stdlib.h>  //Stdlib.h é um arquivo cabeçalho da biblioteca de funções envolvendo alocação de memória, controle de processos, conversões e outras.
#include <conio.h> //conio.h é para desenhar tela
#include <windows.h> 
#include <string.h>
#include <time.h>
#define  escreva   printf
#define  limpatela     system("cls")
#define  pausa         system("pause")

void sleep(unsigned int mseconds)       // Delay
{
    clock_t goal = mseconds + clock();
    while (goal > clock());
}


void gotoxy(int x, int y)             
{
  COORD c;
  c.X = x - 1;
  c.Y = y - 1;
  SetConsoleCursorPosition (GetStdHandle(STD_OUTPUT_HANDLE), c);
}

//Formato da Nave Gaita

void pedaco1(void) //Funçao para um pedaço do boneco
{
     escreva("%c%c%c%c%c",32,162,32,149,32);
}
void pedaco2(void)  //Funçao para um pedaço do boneco
{
    escreva("%c%c%c%c%c",201,176,176,176,187); 
}
void pedaco3(void)  //Funçao para um pedaço do boneco
{
    escreva("%c%c%c%c%c",186,176,176,176,186);
}
void pedaco4(void)  //Funçao para um pedaço do boneco
{
     escreva("%c%c%c%c%c",200,177,190,177,188);
}
void gaita(void)  //Funçao para titulo do boneco
{
     system("color 27");   // Altera a cor de texto e fundo
     escreva("NAVE ANTI COVID");    
}
void tiro(void)
{
     escreva("%c%c%c%c%c",124,255,255,255,124);
}
void tudo(int p,int q)  //Funçao que engloba todos os pedaços do boneco
{
     limpatela; 
    gotoxy(p,q);
    pedaco1();
    gotoxy(p,q+1);
    pedaco2();
    gotoxy(p,q+2);
    pedaco3();
    gotoxy(p,q+3);
    pedaco4();
    gotoxy (35,1);
    gaita();
}
int main(void)
{
    char     b;
    int  x,y,z;

//Cabeçário do programa
   system("color 70");   // Altera a cor de texto e fundo
   escreva("\n\n\t Esboco de um jogo em C++ para posterior emplementacao em OpenGL...");
   escreva("\n\n\n\t COMANDOS:\n\n\t     Cima = W \n Esquerda = A \t Direita = D \n\t     Baixo = S \n\n\t Sair = ESC\n\n\t");
   pausa;
       
x=37;  //Define posição inicial
y=26;

    tudo(x,y);

do
{
    z=y;      //Define uma nova variavel para posiçao que sera usada pelo tiro depois
    b=getch();    //Atribui os valores do teclado a 'b'
    switch (b)      
    {
    case 100:  //Passa o comando a tecla 'd'

//Move para direita
    x=x+1;
if (x>75)    //Define limites de tela
{
	x=75;
}    
     tudo(x,y);
    break;
    
//Move para esquerda
    case 97:   //Passa o comando a tecla 'a'
    x=x-1;
    if (x<1)   //Define limites de tela
{
	x=1;
}
    tudo(x,y);
    break;
    
//Move para cima
    case 115:   //Passa o comando a tecla 'w'
    y=y+1;
    if (y>51)   //Define limites de tela 
{
	y=51;
}
    tudo(x,y);
    break;
    
//Move para baixo
    case 119:    //Passa o comando a tecla 's'
    y=y-1;   
    if (y<2)    //Define limites de tela 
{
	y=2;
}
    tudo(x,y);
    break;
    
//Dispara tiro
    case 116:     //Passa o comando a tecla 't'    
    while (z>2)   //Define limites de tela
{
    z=z-1;
    gotoxy(x,z);
    tiro();
    sleep(1);      
}
    tudo(x,y);
    
    }
}
while (b!=27);    //Encerra o programa quando pressionada a tecla ESC
    pausa;
}
