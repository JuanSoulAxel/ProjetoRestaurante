#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>
#include <time.h>

//constantes e vari�veis para a compara��o da senha correta
const char usuario[10] = "Juan";
char usuarioo[10];
const int senha = 2645678;
int senhaa;

void login(void); //fun��o para login do ADM
void cardapio(void); //fun��o para card�pio do CLIENTE

int escolha, contousair; //para a escolha de ADM ou CLIENTE e continuar ou sair do sistema
int mesanum, quantpessoas, quantpessoas0; //para anotar o n�mero da mesa e para saber quantas vezes iremos mostrar o card�pio (quantas pessoas ir�o comer)
int comida, bebida, sobremesa; //n�mero da comida

int main(void)
{
  setlocale(LC_ALL, "PORTUGUESE");

  do{
  printf("Seja muito bem vindo(a)! \n[1] para administrador \n[2] para cliente \nEscolha: ");
  scanf("%d", &escolha);
  system("cls");


  switch(escolha)
  {
  case 1:
  system("color 3F");
  login();
  break;
  case 2:
  cardapio();
  break;
  default:
  printf("OP��O ESCOLHIDA � INV�LIDA!");
  }
  system("pause");
  system("cls");
  system("color 07");
  printf("Deseja continuar ou sair do sistema?\n[1] para CONTINUAR\n[2] para SAIR\nEscolha: ");
  scanf("%d", &contousair);
  system("cls");
  }while(contousair!=2);
}
void login (void)
{
    printf("Usu�rio: ");
    scanf("%s", &usuarioo);
    printf("Senha: ");
    scanf("%d", &senhaa);
    system("cls");

    if(strcmp(usuario,usuarioo)==0 && senha==senhaa)
    {
        system("color 2F");
        printf("\n\n\t\tACESSO PERMITIDO\n\n");
    }
    else
    {
        system("color 4F");
        printf("\n\n\t\tACESSO NEGADO\n\tusu�rio/senha incorretos\n\n");
    }
}
void cardapio (void)
{
    printf("N�mero da mesa: ");
    scanf("%d", &mesanum);
    printf("N�mero de acompanhantes: ");
    scanf("%d", &quantpessoas, &quantpessoas0); //atribu� um valor a duas vari�veis, pois vou usar dois FORs que precisam do mesmo valor
    system("cls");

    for(int valfor0=0;valfor0<=quantpessoas0;valfor0++) //For principal
    {
    float valortotal[valfor0]; //Criando o Array (VETOR) para acumular o pre�o total de todos os itens
    float precocomida[valfor0], precobebida[valfor0], precosobremesa[valfor0];

    for(int valfor=0;valfor<=quantpessoas;valfor++) //For secund�rio
    {
    printf("CARD�PIO PARA PESSOA %d\n\nPratos do dia: \n0) Nenhum \n1) Lasanha R$12,00\n2) Feijoada R$10,00\n3) Strogonoff R$12,00\n4) Churrasco R$20,00\n5) Risoto R$15,00\nDigite o n�mero da comida: ", valfor+1);
    scanf("%d", &comida);
    system("cls"); //^^Comidas^^
    {
    switch(comida)
    {
    case 0:
        precocomida[valfor] = 0;
        break;
    case 1:
        precocomida[valfor] = 12;
        break;
    case 2:
        precocomida[valfor] = 10;
        break;
    case 3:
        precocomida[valfor] = 12;
        break;
    case 4:
        precocomida[valfor] = 20;
        break;
    case 5:
        precocomida[valfor] = 15;
        break;
    default:
        precocomida[valfor] = 0;
    }

    printf("CARD�PIO PARA PESSOA %d\n\nBebidas do dia: \n0) Nenhum \n1) Vinho R$15,00\n2) Whisky R$45,00\n3) Guaran� R$7,00\n4) Coca cola R$8,00\n5) Caf� R$5,00\n Digite o n�mero da bebida: ", valfor+1);
    scanf("%d", &bebida);
    system("cls");//^^Bebidas^^

    switch(bebida)
    {
    case 0:
        precobebida[valfor] = 0;
        break;
    case 1:
        precobebida[valfor] = 15;
        break;
    case 2:
        precobebida[valfor] = 45;
        break;
    case 3:
        precobebida[valfor] = 7;
        break;
    case 4:
        precobebida[valfor] = 8;
        break;
    case 5:
        precobebida[valfor] = 5;
        break;
    default:
        precobebida[valfor] = 0;
    }

    printf("CARD�PIO PARA PESSOA %d\n\nSobremesas do dia: \n0) Nenhum \n1) Pudim R$10,00\n2) Milkshake R$11,00\n3) Bolo de morango R$8,00\n4) Sorvete R$10,00\n5) Torta R$8,00\n Digite o n�mero da sobremesa: ", valfor+1);

    scanf("%d", &sobremesa);
    system("cls");//^^Sobremesa^^

    switch(sobremesa)
    {
    case 0:
        precosobremesa[valfor] = 0;
        break;
    case 1:
        precosobremesa[valfor] = 10;
        break;
    case 2:
        precosobremesa[valfor] = 11;
        break;
    case 3:
        precosobremesa[valfor] = 8;
        break;
    case 4:
        precosobremesa[valfor] = 10;
        break;
    case 5:
        precosobremesa[valfor] = 8;
        break;
    default:
        precosobremesa[valfor] = 0;
    }
    }
    }
    srand(time(NULL)); //invocando n�meros aleat�rios
    printf("Restaurante Platinium\n");
    printf("Cupom Fiscal: %d \n", rand()% 503496 + 498521);
    printf("N� da mesa: %d", mesanum);
    //todas op��es para o pre�o total dependendo da vari�vel quantpessoas
    if(quantpessoas==0)
    {
        printf("\t\t\t\t\tO total a pagar: %.2f", valortotal[0]=precocomida[0]+precobebida[0]+precosobremesa[0]);
    }
    else if(quantpessoas==1)
    {
        printf("\t\t\t\t\tO total a pagar: %.2f", (valortotal[0]=precocomida[0]+precobebida[0]+precosobremesa[0])+(valortotal[1]=precocomida[1]+precobebida[1]+precosobremesa[1]));
    }
    else if(quantpessoas==2)
    {
        printf("\t\t\t\t\tO total a pagar: %.2f", (valortotal[0]=precocomida[0]+precobebida[0]+precosobremesa[0])+(valortotal[1]=precocomida[1]+precobebida[1]+precosobremesa[1])+(valortotal[2]=precocomida[2]+precobebida[2]+precosobremesa[2]));
    }
    else if(quantpessoas==3)
    {
        printf("\t\t\t\t\tO total a pagar: %.2f", (valortotal[0]=precocomida[0]+precobebida[0]+precosobremesa[0])+(valortotal[1]=precocomida[1]+precobebida[1]+precosobremesa[1])+(valortotal[2]=precocomida[2]+precobebida[2]+precosobremesa[2])+(valortotal[3]=precocomida[3]+precobebida[3]+precosobremesa[3]));
    }
    }
}
