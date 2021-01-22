#include <stdio.h>   //cabe�alho de Input/Output
#include <stdlib.h>  //uso dos system
#include <locale.h>  //uso da biblioteca para portugu�s
#include <string.h>  //para a compara��o do usu�rio(char) do login
#include <conio.h>   //para cobrir a senha da compara��o
#include <time.h>    //para gerrar um n�mero aleat�rio
#include <windows.h> //para dar tempo no c�digo

//Usu�rio com nome dos participantes do grupo para login do ADM
const char usuario[10] = "Alison"; const char usuario2[10] = "Cesar"; const char usuario3[10] = "Glaudson"; const char usuario4[10] = "Henrique"; const char usuario5[10] = "Jefferson"; const char usuario6[10] = "Juan"; const char usuario7[10] = "Mateus"; const char usuario8[10] = "Daniel";
char usuarioo[10]; char senhaa[7]; //usuarioo e senhaa para a compara��o de usu�rio(que varia do participante) e senha (fixa)
//senha: 2645678

void Adm(); //Menu de gest�o
void AtualizarCardapio();//Mudar os pratos do dia
void Estoque(); //Gerir estoque
void login(void); //fun��o para login do ADM
void cardapio(void); //fun��o para card�pio do CLIENTE
void cardapiovegetariano(void); //fun��o para card�pio VEGETARIANO do CLIENTE

float ValorParaAdm, Gorjetas, valorgorj; //para ganho total e gorjetas do expediente
float AtualizarTrad[5]={6.50, 5, 5.50, 6, 5}, AtualizarTrad2[5]={8, 10, 6, 7.50, 3.50}, AtualizarTrad3[5]={4, 7, 5, 3.50, 4};//atualizar pre�os do card�pio tradicional (prato(), bebida(2) e sobremesa(3))
float AtualizarVeg[5]={6.50, 5, 5, 2.50, 6}, AtualizarVeg2[5]={8, 10, 6, 7.50, 3.50}, AtualizarVeg3[5]={4, 7, 5, 8.50, 4};//atualizar pre�os do card�pio vegano (prato(), bebida(2) e sobremesa(3))

int RecursosComida, RecursosBebida, RecursosSobremesa; //subtrair os itens do estoque
int Menu, opcoes, ContinuarAdm; //menu de atualizar ou ver estoque e opcoes para escolhar qual preco do card�pio atualizar e continuar ou n�o em ADM e CLIENTE
int escolha, contousair, vegetounao; //para a escolha de ADM ou CLIENTE; continuar ou sair do sistema; vegetariano ou n�o vegetariano
int mesanum, quantpessoas, quantpessoas0; //para anotar o n�mero da mesa e para saber quantas vezes iremos mostrar o card�pio (quantas pessoas ir�o comer)
int comida, bebida, sobremesa; //n�mero para a escolha das comida

//=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=--=-=-=-=-=-=-=IN�CIO DO M�TODO PRINCIPAL=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=
int main(void)
{
  setlocale(LC_ALL, "PORTUGUESE"); //a uso da locale.h

  do{
  system("color 1F");
  printf("Seja muito bem vindo(a)! \n[1] para administrador \n[2] para cliente \nEscolha: ");
  scanf("%d", &escolha);
  system("cls"); system("color 3F");
  switch(escolha)
  {
  case 1:
  login();
  system("pause"); system("color 1F"); system("cls");
  break; //case ADM^^

  case 2:
  cardapio();
  system("pause"); system("color 1F"); system("cls");
  break; //case CLIENTE^^

  default:
  system("color 47");
  printf("A OP��O ESCOLHIDA � INV�LIDA!\n\n\n\n"); //case DIGITE ERRADO^^
  }

  system("cls"); system("color 1F"); //ajustes de pause, limpatela e cor para o fim do c�digo
  printf("Deseja continuar ou sair do sistema?\n[1] para continuar\n[2] para sair\nEscolha: ");
  scanf("%d", &contousair);
  system("cls");
  }while(contousair!=2);
} //=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=--=-=-=-=-=-=-=FIM DO M�TODO PRINCIPAL=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=
void login (void)
{
    printf("Login:   ");
    scanf("%s", &usuarioo); //pedindo Usu�rio ao ADM

    printf("Senha:   ");
    for(int i=0;i<7;i++)
    {
    senhaa[i] = getch(); printf("*"); //substituir n�meros digitados por "*"
    }
    printf("\n\n\n\n"); system("pause"); system("cls");

    //Uma conta para caad membro do grupo! -> seus primeiros nomes no USU�RIO e SENHA 2645678
    if(( strcmp(usuario,usuarioo)==0 || strcmp(usuario2,usuarioo)==0 || strcmp(usuario3,usuarioo)==0 || strcmp(usuario4,usuarioo)==0 || strcmp(usuario5,usuarioo)==0 || strcmp(usuario6,usuarioo)==0 || strcmp(usuario7,usuarioo)==0 || strcmp (usuario8, usuarioo)==0) && (senhaa[0]=='2')&&(senhaa[1]=='6')&&(senhaa[2]=='4')&&(senhaa[3]=='5')&&(senhaa[4]=='6')&&(senhaa[5]=='7')&&(senhaa[6]=='8'))
    {
        system("color 2F"); printf("ACESSO AUTORIZADO\n\n\n\n\n\n\n\n\n\n\n");
        system("pause"); system("cls");
        Adm();
    }
    else
    {
        printf("     ACESSO NEGADO\nusu�rio/senha incorretos\n\n\n\n\n\n\n\n\n\n\n\n\n");
        system("color 4F");
    }
}
//Fun��o de gest�o restrita aos funcion�rios, onde ser�o exibidas as op��es dispon�veis.
void Adm(void)
{
     do{
     system("color F0");
     printf("Ol� %s, escolha uma das op��es: \n", usuarioo);//Juan, depois do "Ol�" concatena com a constate de usuario que tem ai.'
     printf("[1] Atualizar card�pio\n[2] Estoque \n[3] Ganho do expediente \n[4] Gorjetas do expediente \nEscolha: ");
	 scanf("%d", &Menu);
	 system("cls");
	 switch (Menu)
	 {
     case 1:
     AtualizarCardapio();
     break;

	 case 2:
	 Estoque();
	 break;

	 case 3:
	 printf("Valor total \n\nO ganho total do expediente foi: R$%.2f \n\n", ValorParaAdm);
	 break;

	 case 4:
	 printf("Grojetas \n\nO total de gorjetas aos gar�ons foi: R$%.2f \n\n", valorgorj);
	 break;
     }//Fim do Switch de Menu ADM
     system("pause"); system("cls"); system("color 1F");
     printf("Deseja continuar como administrador? \n[1] para sim \n[2] para n�o \nEscolha: "); scanf("%d", &ContinuarAdm);
     system("cls");
     }while(ContinuarAdm!=2);
}

//Fun��o para atualizar os card�pios
void AtualizarCardapio(void)
{
    printf("[1] Atualizar pre�o do card�pio tradicional\n[2] Atualizar pre�o do card�pio vegetariano\n");
    printf("Escolha: ");
    scanf("%d",&opcoes);
    system("cls");

	    //A id�ia � que a variavel "Atualizar" que � um vetor pegue esses 6 novos intens e armazene eles em respctivas fun��es.
    if(opcoes == 1)
        {
	      printf("Novo pre�o do card�pio tradicional\n\n");
	      printf("Prato 1: "); scanf("%f",&AtualizarTrad[0]);
          printf("Prato 2: "); scanf("%f",&AtualizarTrad[1]);
          printf("Prato 3: "); scanf("%f",&AtualizarTrad[2]);
          printf("Prato 4: "); scanf("%f",&AtualizarTrad[3]);
          printf("Prato 5: "); scanf("%f",&AtualizarTrad[4]);
          system("cls");

          printf("Novo pre�o do card�pio tradicional\n\n");
          printf("Bebida 1: "); scanf("%f",&AtualizarTrad2[0]);
          printf("Bebida 2: "); scanf("%f",&AtualizarTrad2[1]);
          printf("Bebida 3: "); scanf("%f",&AtualizarTrad2[2]);
          printf("Bebida 4: "); scanf("%f",&AtualizarTrad2[3]);
          printf("Bebida 5: "); scanf("%f",&AtualizarTrad2[4]);
          system("cls");

          printf("Novo pre�o do card�pio tradicional\n\n");
	      printf("Sobremesa 1: "); scanf("%f",&AtualizarTrad3[0]);
          printf("Sobremesa 2: "); scanf("%f",&AtualizarTrad3[1]);
          printf("Sobremesa 3: "); scanf("%f",&AtualizarTrad3[2]);
          printf("Sobremesa 4: "); scanf("%f",&AtualizarTrad3[3]);
          printf("Sobremesa 5: "); scanf("%f",&AtualizarTrad3[4]);
          printf("Atualizando..."); Sleep(1000); printf("5..."); Sleep(1000); printf("4..."); Sleep(1000); printf("3..."); Sleep(1000); printf("2..."); Sleep(1000); printf("1...0"); system("cls"); printf("PRE�O ATUALIZADO\n\n\n\n");
	    }//FIM IF TRAD
    if(opcoes == 2)
        {
          printf("Novo pre�o do card�pio vegetariano\n\n");
	      printf("Prato 1: "); scanf("%f",&AtualizarVeg[0]);
          printf("Prato 2: "); scanf("%f",&AtualizarVeg[1]);
          printf("Prato 3: "); scanf("%f",&AtualizarVeg[2]);
          printf("Prato 4: "); scanf("%f",&AtualizarVeg[3]);
          printf("Prato 5: "); scanf("%f",&AtualizarVeg[4]);
          system("cls");

          printf("Novo pre�o do card�pio vegetariano\n\n");
          printf("Bebida 1: "); scanf("%f",&AtualizarVeg2[0]);
          printf("Bebida 2: "); scanf("%f",&AtualizarVeg2[1]);
          printf("Bebida 3: "); scanf("%f",&AtualizarVeg2[2]);
          printf("Bebida 4: "); scanf("%f",&AtualizarVeg2[3]);
          printf("Bebida 5: "); scanf("%f",&AtualizarVeg2[4]);
          system("cls");

          printf("Novo pre�o do card�pio vegetariano\n\n");
	      printf("Sobremesa 1: "); scanf("%f",&AtualizarVeg3[0]);
          printf("Sobremesa 2: "); scanf("%f",&AtualizarVeg3[1]);
          printf("Sobremesa 3: "); scanf("%f",&AtualizarVeg3[2]);
          printf("Sobremesa 4: "); scanf("%f",&AtualizarVeg3[3]);
          printf("Sobremesa 5: "); scanf("%f",&AtualizarVeg3[4]);
          printf("Atualizando..."); Sleep(1000); printf("5..."); Sleep(1000); printf("4..."); Sleep(1000); printf("3..."); Sleep(1000); printf("2..."); Sleep(1000); printf("1...0"); system("cls"); printf("PRE�O ATUALIZADO\n\n\n\n");         }//FIM IF VEG
}

//Fun��o de controle de estoque
void Estoque()
{
	printf("Estoque atual \n\n");
	printf("Produtos:\tQuantidade:\n\n");
	printf("Comida\t\t    %d\nBebidas\t\t    %d\nSobremesas\t    %d\n\n\n\n", (100-RecursosComida),(90-RecursosBebida), (80-RecursosSobremesa));
}

void cardapio (void)
{
    printf("Voc� � vegetariano? \n[1] para n�o \n[2] para sim \nEscolha: ");
    scanf("%d", &vegetounao);
    system("cls");

    if(vegetounao == 1)
    {
    printf("N�mero da mesa: ");
    scanf("%d", &mesanum);

    printf("N�mero de acompanhantes: ");
    scanf("%d", &quantpessoas, &quantpessoas0); //atribu� um valor a duas vari�veis, pois vou usar dois FORs que precisam do mesmo valor
    system("cls"); system("color F0");

    for(int valfor0=0;valfor0<=quantpessoas0;valfor0++) //For principal
    {
    float valortotal[valfor0]; //Criando o Array (VETOR) para acumular o pre�o total de todos os itens
    float precocomida[valfor0], precobebida[valfor0], precosobremesa[valfor0];//Criando o Array (VETOR) para ajudar o valortotal caso o usu�rio esteja com acompanhannte

    for(int valfor=0;valfor<=quantpessoas;valfor++) //For secund�rio
    {
    printf("CARD�PIO PARA %d� PESSOA \n\nPratos do dia: \n0) Nenhum \n1) Lasanha R$%.2f\n2) Feijoada R$%.2f\n3) Strogonoff R$%.2f\n4) Churrasco R$%.2f\n5) Risoto R$%.2f\nDigite o n�mero da comida: ", valfor+1, AtualizarTrad[0], AtualizarTrad[1], AtualizarTrad[2], AtualizarTrad[3], AtualizarTrad[4]);
    scanf("%d", &comida);
    system("cls"); //^^Comidas^^

    if(comida>0 && comida<6){ RecursosComida += 1; } //atualizando estoque de comida

    {
    switch(comida)
    {
    case 1: precocomida[valfor] = AtualizarTrad[0];  break;
    case 2: precocomida[valfor] = AtualizarTrad[1];  break;
    case 3: precocomida[valfor] = AtualizarTrad[2];  break;
    case 4: precocomida[valfor] = AtualizarTrad[3];  break;
    case 5: precocomida[valfor] = AtualizarTrad[4];  break;
    default:precocomida[valfor] = 0;
    }

    printf("CARD�PIO PARA %d� PESSOA \n\nBebidas do dia: \n0) Nenhum \n1) Vinho R$%.2f\n2) Whisky R$%.2f\n3) Guaran� R$%.2f\n4) Coca cola R$%.2f\n5) Caf� R$%.2f\nDigite o n�mero da bebida: ", valfor+1, AtualizarTrad2[0], AtualizarTrad2[1], AtualizarTrad2[2], AtualizarTrad2[3], AtualizarTrad2[4]);
    scanf("%d", &bebida);
    system("cls");//^^Bebidas^^

    if(bebida>0 && bebida<6){ RecursosBebida += 1; } //Atualizando estoque de bebida

    switch(bebida)
    {
    case 1: precobebida[valfor] = AtualizarTrad2[0]; break;
    case 2: precobebida[valfor] = AtualizarTrad2[1]; break;
    case 3: precobebida[valfor] = AtualizarTrad2[2]; break;
    case 4: precobebida[valfor] = AtualizarTrad2[3]; break;
    case 5: precobebida[valfor] = AtualizarTrad2[4]; break;
    default:precobebida[valfor] = 0;
    }

    printf("CARD�PIO PARA %d� PESSOA \n\nSobremesas do dia: \n0) Nenhum \n1) Pudim R$%.2f\n2) Milkshake R$%.2f\n3) Bolo de morango R$%.2f\n4) coxinha R$%.2f\n5) Torta R$%.2f\nDigite o n�mero da sobremesa: ", valfor+1, AtualizarTrad3[0], AtualizarTrad3[1], AtualizarTrad3[2], AtualizarTrad3[3],AtualizarTrad3[4]);
    scanf("%d", &sobremesa);
    system("cls");//^^Sobremesa^^

    if(sobremesa>0 && sobremesa<6){ RecursosSobremesa += 1; } //atualizando estoque de sobremesa

    switch(sobremesa)
    {
    case 1: precosobremesa[valfor] = AtualizarTrad3[0]; break;
    case 2: precosobremesa[valfor] = AtualizarTrad3[1]; break;
    case 3: precosobremesa[valfor] = AtualizarTrad3[2]; break;
    case 4: precosobremesa[valfor] = AtualizarTrad3[3]; break;
    case 5: precosobremesa[valfor] = AtualizarTrad3[4]; break;
    default:precosobremesa[valfor] = 0;
    }
    }
    }//FIM DO 2� FOR
    printf("Gorjeta para o gar�om: "); scanf("%f", &Gorjetas); valorgorj +=  Gorjetas; system("cls"); //gorjeta por expediente (n�o botar gojetas com pontos flutuantes)
    printf("Aguarde..."); Sleep(1000); printf("5..."); Sleep(1000); printf("4..."); Sleep(1000); printf("3..."); Sleep(1000); printf("2..."); Sleep(1000); printf("1..."); Sleep(1000); system("cls");
    system("color 80");
    printf("Restaurante Platinium\n");
    printf("Card�pio: tradicional\n");
    printf("N�mero da mesa: %d \n", mesanum);
    srand(time(NULL)); //invocando n�meros aleat�rios
    printf("Cupom Fiscal: %d \n", rand()% 503496 + 498521);

    if(quantpessoas==0)
    {
        printf("Total a pagar: R$%.2f \n\n\n\n", valortotal[0]=precocomida[0]+precobebida[0]+precosobremesa[0]);
        ValorParaAdm += valortotal[0]=precocomida[0]+precobebida[0]+precosobremesa[0];
    }
    else if(quantpessoas==1)
    {
        printf("Total a pagar: R$%.2f \n\n\n\n", (valortotal[0]=precocomida[0]+precobebida[0]+precosobremesa[0])+(valortotal[1]=precocomida[1]+precobebida[1]+precosobremesa[1]));
        ValorParaAdm += (valortotal[0]=precocomida[0]+precobebida[0]+precosobremesa[0])+(valortotal[1]=precocomida[1]+precobebida[1]+precosobremesa[1]);
    }
    else if(quantpessoas==2)
    {
        printf("Total a pagar: R$%.2f \n\n\n\n", (valortotal[0]=precocomida[0]+precobebida[0]+precosobremesa[0])+(valortotal[1]=precocomida[1]+precobebida[1]+precosobremesa[1])+(valortotal[2]=precocomida[2]+precobebida[2]+precosobremesa[2]));
        ValorParaAdm += (valortotal[0]=precocomida[0]+precobebida[0]+precosobremesa[0])+(valortotal[1]=precocomida[1]+precobebida[1]+precosobremesa[1])+(valortotal[2]=precocomida[2]+precobebida[2]+precosobremesa[2]);
    }
    else if(quantpessoas==3)
    {
        printf("Total a pagar: R$%.2f \n\n\n\n", (valortotal[0]=precocomida[0]+precobebida[0]+precosobremesa[0])+(valortotal[1]=precocomida[1]+precobebida[1]+precosobremesa[1])+(valortotal[2]=precocomida[2]+precobebida[2]+precosobremesa[2])+(valortotal[3]=precocomida[3]+precobebida[3]+precosobremesa[3]));
        ValorParaAdm += (valortotal[0]=precocomida[0]+precobebida[0]+precosobremesa[0])+(valortotal[1]=precocomida[1]+precobebida[1]+precosobremesa[1])+(valortotal[2]=precocomida[2]+precobebida[2]+precosobremesa[2])+(valortotal[3]=precocomida[3]+precobebida[3]+precosobremesa[3]);
    }
    } //FIM DO 1� FOR
    } //FIM DO IF SEM FRESCURA

    else if(vegetounao == 2)
    {
        cardapiovegetariano();
    }//FIM DO IF FRESCURA
}
void cardapiovegetariano (void)
{
    printf("N�mero da mesa: ");
    scanf("%d", &mesanum);

    printf("N�mero de acompanhantes: ");
    scanf("%d", &quantpessoas, &quantpessoas0); //atribu� um valor a duas vari�veis, pois vou usar dois FORs que precisam do mesmo valor
    system("cls"); system("color F0");

    for(int valfor0=0;valfor0<=quantpessoas0;valfor0++) //For principal
    {
    float valortotal[valfor0]; //Criando o Array (VETOR) para acumular o pre�o total de todos os itens
    float precocomida[valfor0], precobebida[valfor0], precosobremesa[valfor0];//Criando o Array (VETOR) para ajudar o valortotal caso o usu�rio esteja com acompanhannte

    for(int valfor=0;valfor<=quantpessoas;valfor++) //For secund�rio
    {
    printf("CARD�PIO VEGETARIANO PARA %d� PESSOA \n\nPratos do dia: \n0) Nenhum \n1) Lasanha ao molho funghi R$%.2f\n2) Arroz com br�colis R$%.2f\n3) Strogonoff de carne de soja R$%.2f\n4) Omelete de forno R$%.2f\n5) Risoto de aspargos R$%.2f\nDigite o n�mero da comida: ", valfor+1, AtualizarVeg[0], AtualizarVeg[1], AtualizarVeg[2], AtualizarVeg[3], AtualizarVeg[4]);
    scanf("%d", &comida);
    system("cls"); //^^Comidas^^

    if(comida>0 && comida<6){ RecursosComida += 1; } //atualizando estoque de comida

    {
    switch(comida)
    {
    case 1: precocomida[valfor] = AtualizarVeg[0]; break;
    case 2: precocomida[valfor] = AtualizarVeg[1]; break;
    case 3: precocomida[valfor] = AtualizarVeg[2]; break;
    case 4: precocomida[valfor] = AtualizarVeg[3]; break;
    case 5: precocomida[valfor] = AtualizarVeg[4]; break;
    default:precocomida[valfor] = 0;
    }

    printf("CARD�PIO VEGETARIANO PARA %d� PESSOA \n\nBebidas do dia: \n0) Nenhum \n1) Vinho R$%.2f\n2) Whisky R$%.2f\n3) Guaran� R$%.2f0\n4) Coca cola R$%.2f\n5) Caf� R$%.2f\nDigite o n�mero da bebida: ", valfor+1, AtualizarVeg2[0], AtualizarVeg2[1], AtualizarVeg2[2], AtualizarVeg2[3], AtualizarVeg2[4]);
    scanf("%d", &bebida);
    system("cls");//^^Bebidas^^

    if(bebida>0 && bebida<6){ RecursosBebida += 1; } //atualizando estoque de bebida

    switch(bebida)
    {
    case 1: precobebida[valfor] = AtualizarVeg2[0]; break;
    case 2: precobebida[valfor] = AtualizarVeg2[1]; break;
    case 3: precobebida[valfor] = AtualizarVeg2[2]; break;
    case 4: precobebida[valfor] = AtualizarVeg2[3]; break;
    case 5: precobebida[valfor] = AtualizarVeg2[4]; break;
    default:precobebida[valfor] = 0;
    }

    printf("CARD�PIO VEGETARIANO PARA %d� PESSOA \n\nSobremesas do dia: \n0) Nenhum \n1) Pudim R$4,00\n2) Milkshake R$7,00\n3) Bolo de morango R$5,00\n4) Ratatouille R$8,50\n5) Torta R$5,00\nDigite o n�mero da sobremesa: ", valfor+1);
    scanf("%d", &sobremesa);
    system("cls");//^^Sobremesa^^

    if(sobremesa>0 && sobremesa<6){ RecursosSobremesa += 1; } //atualizando estoque de sobremesa

    switch(sobremesa)
    {
    case 1: precosobremesa[valfor] = AtualizarVeg3[0]; break;
    case 2: precosobremesa[valfor] = AtualizarVeg3[1]; break;
    case 3: precosobremesa[valfor] = AtualizarVeg3[2]; break;
    case 4: precosobremesa[valfor] = AtualizarVeg3[3]; break;
    case 5: precosobremesa[valfor] = AtualizarVeg3[4]; break;
    default:precosobremesa[valfor] = 0;
    }

    }
    }//FIM DO 2� FOR
    printf("Gorjeta para o gar�om: "); scanf("%f", &Gorjetas); valorgorj +=  Gorjetas; system("cls"); //acumular gorjeta do expediente(n�o botar pontos flutuantes)
    printf("Aguarde..."); Sleep(1000); printf("5..."); Sleep(1000); printf("4..."); Sleep(1000); printf("3..."); Sleep(1000); printf("2..."); Sleep(1000); printf("1..."); Sleep(1000); printf("0"); system("cls");
    system("color 80");
    printf("Restaurante Platinium\n");
    printf("Card�pio: vegetariano\n");
    printf("N�mero da mesa: %d \n", mesanum);
    srand(time(NULL)); //invocando n�meros aleat�rios
    printf("Cupom Fiscal: %d \n", rand()% 503496 + 498521);

    if(quantpessoas==0)
    {
        printf("Total a pagar: R$%.2f \n\n\n\n", valortotal[0]=precocomida[0]+precobebida[0]+precosobremesa[0]);
        ValorParaAdm += valortotal[0]=precocomida[0]+precobebida[0]+precosobremesa[0];
    }
    else if(quantpessoas==1)
    {
        printf("Total a pagar: R$%.2f \n\n\n\n", (valortotal[0]=precocomida[0]+precobebida[0]+precosobremesa[0])+(valortotal[1]=precocomida[1]+precobebida[1]+precosobremesa[1]));
        ValorParaAdm += (valortotal[0]=precocomida[0]+precobebida[0]+precosobremesa[0])+(valortotal[1]=precocomida[1]+precobebida[1]+precosobremesa[1]);
    }
    else if(quantpessoas==2)
    {
        printf("Total a pagar: R$%.2f \n\n\n\n", (valortotal[0]=precocomida[0]+precobebida[0]+precosobremesa[0])+(valortotal[1]=precocomida[1]+precobebida[1]+precosobremesa[1])+(valortotal[2]=precocomida[2]+precobebida[2]+precosobremesa[2]));
        ValorParaAdm += (valortotal[0]=precocomida[0]+precobebida[0]+precosobremesa[0])+(valortotal[1]=precocomida[1]+precobebida[1]+precosobremesa[1])+(valortotal[2]=precocomida[2]+precobebida[2]+precosobremesa[2]);
    }
    else if(quantpessoas==3)
    {
        printf("Total a pagar: R$%.2f \n\n\n\n", (valortotal[0]=precocomida[0]+precobebida[0]+precosobremesa[0])+(valortotal[1]=precocomida[1]+precobebida[1]+precosobremesa[1])+(valortotal[2]=precocomida[2]+precobebida[2]+precosobremesa[2])+(valortotal[3]=precocomida[3]+precobebida[3]+precosobremesa[3]));
        ValorParaAdm += (valortotal[0]=precocomida[0]+precobebida[0]+precosobremesa[0])+(valortotal[1]=precocomida[1]+precobebida[1]+precosobremesa[1])+(valortotal[2]=precocomida[2]+precobebida[2]+precosobremesa[2])+(valortotal[3]=precocomida[3]+precobebida[3]+precosobremesa[3]);
    }    }//FIM DO 1� FOR
}
