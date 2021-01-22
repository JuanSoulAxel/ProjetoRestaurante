#include <stdio.h>   //cabeçalho de Input/Output
#include <stdlib.h>  //uso dos system
#include <locale.h>  //uso da biblioteca para português
#include <string.h>  //para a comparação do usuário(char) do login
#include <conio.h>   //para cobrir a senha da comparação
#include <time.h>    //para gerrar um número aleatório
#include <windows.h> //para dar tempo no código

//Usuário com nome dos participantes do grupo para login do ADM
const char usuario[10] = "Alison"; const char usuario2[10] = "Cesar"; const char usuario3[10] = "Glaudson"; const char usuario4[10] = "Henrique"; const char usuario5[10] = "Jefferson"; const char usuario6[10] = "Juan"; const char usuario7[10] = "Mateus"; const char usuario8[10] = "Daniel";
char usuarioo[10]; char senhaa[7]; //usuarioo e senhaa para a comparação de usuário(que varia do participante) e senha (fixa)
//senha: 2645678

void Adm(); //Menu de gestão
void AtualizarCardapio();//Mudar os pratos do dia
void Estoque(); //Gerir estoque
void login(void); //função para login do ADM
void cardapio(void); //função para cardápio do CLIENTE
void cardapiovegetariano(void); //função para cardápio VEGETARIANO do CLIENTE

float ValorParaAdm, Gorjetas, valorgorj; //para ganho total e gorjetas do expediente
float AtualizarTrad[5]={6.50, 5, 5.50, 6, 5}, AtualizarTrad2[5]={8, 10, 6, 7.50, 3.50}, AtualizarTrad3[5]={4, 7, 5, 3.50, 4};//atualizar preços do cardápio tradicional (prato(), bebida(2) e sobremesa(3))
float AtualizarVeg[5]={6.50, 5, 5, 2.50, 6}, AtualizarVeg2[5]={8, 10, 6, 7.50, 3.50}, AtualizarVeg3[5]={4, 7, 5, 8.50, 4};//atualizar preços do cardápio vegano (prato(), bebida(2) e sobremesa(3))

int RecursosComida, RecursosBebida, RecursosSobremesa; //subtrair os itens do estoque
int Menu, opcoes, ContinuarAdm; //menu de atualizar ou ver estoque e opcoes para escolhar qual preco do cardápio atualizar e continuar ou não em ADM e CLIENTE
int escolha, contousair, vegetounao; //para a escolha de ADM ou CLIENTE; continuar ou sair do sistema; vegetariano ou não vegetariano
int mesanum, quantpessoas, quantpessoas0; //para anotar o número da mesa e para saber quantas vezes iremos mostrar o cardápio (quantas pessoas irão comer)
int comida, bebida, sobremesa; //número para a escolha das comida

//=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=--=-=-=-=-=-=-=INÍCIO DO MÉTODO PRINCIPAL=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=
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
  printf("A OPÇÃO ESCOLHIDA É INVÁLIDA!\n\n\n\n"); //case DIGITE ERRADO^^
  }

  system("cls"); system("color 1F"); //ajustes de pause, limpatela e cor para o fim do código
  printf("Deseja continuar ou sair do sistema?\n[1] para continuar\n[2] para sair\nEscolha: ");
  scanf("%d", &contousair);
  system("cls");
  }while(contousair!=2);
} //=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=--=-=-=-=-=-=-=FIM DO MÉTODO PRINCIPAL=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=
void login (void)
{
    printf("Login:   ");
    scanf("%s", &usuarioo); //pedindo Usuário ao ADM

    printf("Senha:   ");
    for(int i=0;i<7;i++)
    {
    senhaa[i] = getch(); printf("*"); //substituir números digitados por "*"
    }
    printf("\n\n\n\n"); system("pause"); system("cls");

    //Uma conta para caad membro do grupo! -> seus primeiros nomes no USUÁRIO e SENHA 2645678
    if(( strcmp(usuario,usuarioo)==0 || strcmp(usuario2,usuarioo)==0 || strcmp(usuario3,usuarioo)==0 || strcmp(usuario4,usuarioo)==0 || strcmp(usuario5,usuarioo)==0 || strcmp(usuario6,usuarioo)==0 || strcmp(usuario7,usuarioo)==0 || strcmp (usuario8, usuarioo)==0) && (senhaa[0]=='2')&&(senhaa[1]=='6')&&(senhaa[2]=='4')&&(senhaa[3]=='5')&&(senhaa[4]=='6')&&(senhaa[5]=='7')&&(senhaa[6]=='8'))
    {
        system("color 2F"); printf("ACESSO AUTORIZADO\n\n\n\n\n\n\n\n\n\n\n");
        system("pause"); system("cls");
        Adm();
    }
    else
    {
        printf("     ACESSO NEGADO\nusuário/senha incorretos\n\n\n\n\n\n\n\n\n\n\n\n\n");
        system("color 4F");
    }
}
//Função de gestão restrita aos funcionários, onde serão exibidas as opções disponíveis.
void Adm(void)
{
     do{
     system("color F0");
     printf("Olá %s, escolha uma das opções: \n", usuarioo);//Juan, depois do "Olá" concatena com a constate de usuario que tem ai.'
     printf("[1] Atualizar cardápio\n[2] Estoque \n[3] Ganho do expediente \n[4] Gorjetas do expediente \nEscolha: ");
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
	 printf("Grojetas \n\nO total de gorjetas aos garçons foi: R$%.2f \n\n", valorgorj);
	 break;
     }//Fim do Switch de Menu ADM
     system("pause"); system("cls"); system("color 1F");
     printf("Deseja continuar como administrador? \n[1] para sim \n[2] para não \nEscolha: "); scanf("%d", &ContinuarAdm);
     system("cls");
     }while(ContinuarAdm!=2);
}

//Função para atualizar os cardápios
void AtualizarCardapio(void)
{
    printf("[1] Atualizar preço do cardápio tradicional\n[2] Atualizar preço do cardápio vegetariano\n");
    printf("Escolha: ");
    scanf("%d",&opcoes);
    system("cls");

	    //A idéia é que a variavel "Atualizar" que é um vetor pegue esses 6 novos intens e armazene eles em respctivas funções.
    if(opcoes == 1)
        {
	      printf("Novo preço do cardápio tradicional\n\n");
	      printf("Prato 1: "); scanf("%f",&AtualizarTrad[0]);
          printf("Prato 2: "); scanf("%f",&AtualizarTrad[1]);
          printf("Prato 3: "); scanf("%f",&AtualizarTrad[2]);
          printf("Prato 4: "); scanf("%f",&AtualizarTrad[3]);
          printf("Prato 5: "); scanf("%f",&AtualizarTrad[4]);
          system("cls");

          printf("Novo preço do cardápio tradicional\n\n");
          printf("Bebida 1: "); scanf("%f",&AtualizarTrad2[0]);
          printf("Bebida 2: "); scanf("%f",&AtualizarTrad2[1]);
          printf("Bebida 3: "); scanf("%f",&AtualizarTrad2[2]);
          printf("Bebida 4: "); scanf("%f",&AtualizarTrad2[3]);
          printf("Bebida 5: "); scanf("%f",&AtualizarTrad2[4]);
          system("cls");

          printf("Novo preço do cardápio tradicional\n\n");
	      printf("Sobremesa 1: "); scanf("%f",&AtualizarTrad3[0]);
          printf("Sobremesa 2: "); scanf("%f",&AtualizarTrad3[1]);
          printf("Sobremesa 3: "); scanf("%f",&AtualizarTrad3[2]);
          printf("Sobremesa 4: "); scanf("%f",&AtualizarTrad3[3]);
          printf("Sobremesa 5: "); scanf("%f",&AtualizarTrad3[4]);
          printf("Atualizando..."); Sleep(1000); printf("5..."); Sleep(1000); printf("4..."); Sleep(1000); printf("3..."); Sleep(1000); printf("2..."); Sleep(1000); printf("1...0"); system("cls"); printf("PREÇO ATUALIZADO\n\n\n\n");
	    }//FIM IF TRAD
    if(opcoes == 2)
        {
          printf("Novo preço do cardápio vegetariano\n\n");
	      printf("Prato 1: "); scanf("%f",&AtualizarVeg[0]);
          printf("Prato 2: "); scanf("%f",&AtualizarVeg[1]);
          printf("Prato 3: "); scanf("%f",&AtualizarVeg[2]);
          printf("Prato 4: "); scanf("%f",&AtualizarVeg[3]);
          printf("Prato 5: "); scanf("%f",&AtualizarVeg[4]);
          system("cls");

          printf("Novo preço do cardápio vegetariano\n\n");
          printf("Bebida 1: "); scanf("%f",&AtualizarVeg2[0]);
          printf("Bebida 2: "); scanf("%f",&AtualizarVeg2[1]);
          printf("Bebida 3: "); scanf("%f",&AtualizarVeg2[2]);
          printf("Bebida 4: "); scanf("%f",&AtualizarVeg2[3]);
          printf("Bebida 5: "); scanf("%f",&AtualizarVeg2[4]);
          system("cls");

          printf("Novo preço do cardápio vegetariano\n\n");
	      printf("Sobremesa 1: "); scanf("%f",&AtualizarVeg3[0]);
          printf("Sobremesa 2: "); scanf("%f",&AtualizarVeg3[1]);
          printf("Sobremesa 3: "); scanf("%f",&AtualizarVeg3[2]);
          printf("Sobremesa 4: "); scanf("%f",&AtualizarVeg3[3]);
          printf("Sobremesa 5: "); scanf("%f",&AtualizarVeg3[4]);
          printf("Atualizando..."); Sleep(1000); printf("5..."); Sleep(1000); printf("4..."); Sleep(1000); printf("3..."); Sleep(1000); printf("2..."); Sleep(1000); printf("1...0"); system("cls"); printf("PREÇO ATUALIZADO\n\n\n\n");         }//FIM IF VEG
}

//Função de controle de estoque
void Estoque()
{
	printf("Estoque atual \n\n");
	printf("Produtos:\tQuantidade:\n\n");
	printf("Comida\t\t    %d\nBebidas\t\t    %d\nSobremesas\t    %d\n\n\n\n", (100-RecursosComida),(90-RecursosBebida), (80-RecursosSobremesa));
}

void cardapio (void)
{
    printf("Você é vegetariano? \n[1] para não \n[2] para sim \nEscolha: ");
    scanf("%d", &vegetounao);
    system("cls");

    if(vegetounao == 1)
    {
    printf("Número da mesa: ");
    scanf("%d", &mesanum);

    printf("Número de acompanhantes: ");
    scanf("%d", &quantpessoas, &quantpessoas0); //atribuí um valor a duas variáveis, pois vou usar dois FORs que precisam do mesmo valor
    system("cls"); system("color F0");

    for(int valfor0=0;valfor0<=quantpessoas0;valfor0++) //For principal
    {
    float valortotal[valfor0]; //Criando o Array (VETOR) para acumular o preço total de todos os itens
    float precocomida[valfor0], precobebida[valfor0], precosobremesa[valfor0];//Criando o Array (VETOR) para ajudar o valortotal caso o usuário esteja com acompanhannte

    for(int valfor=0;valfor<=quantpessoas;valfor++) //For secundário
    {
    printf("CARDÁPIO PARA %dª PESSOA \n\nPratos do dia: \n0) Nenhum \n1) Lasanha R$%.2f\n2) Feijoada R$%.2f\n3) Strogonoff R$%.2f\n4) Churrasco R$%.2f\n5) Risoto R$%.2f\nDigite o número da comida: ", valfor+1, AtualizarTrad[0], AtualizarTrad[1], AtualizarTrad[2], AtualizarTrad[3], AtualizarTrad[4]);
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

    printf("CARDÁPIO PARA %dª PESSOA \n\nBebidas do dia: \n0) Nenhum \n1) Vinho R$%.2f\n2) Whisky R$%.2f\n3) Guaraná R$%.2f\n4) Coca cola R$%.2f\n5) Café R$%.2f\nDigite o número da bebida: ", valfor+1, AtualizarTrad2[0], AtualizarTrad2[1], AtualizarTrad2[2], AtualizarTrad2[3], AtualizarTrad2[4]);
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

    printf("CARDÁPIO PARA %dª PESSOA \n\nSobremesas do dia: \n0) Nenhum \n1) Pudim R$%.2f\n2) Milkshake R$%.2f\n3) Bolo de morango R$%.2f\n4) coxinha R$%.2f\n5) Torta R$%.2f\nDigite o número da sobremesa: ", valfor+1, AtualizarTrad3[0], AtualizarTrad3[1], AtualizarTrad3[2], AtualizarTrad3[3],AtualizarTrad3[4]);
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
    }//FIM DO 2º FOR
    printf("Gorjeta para o garçom: "); scanf("%f", &Gorjetas); valorgorj +=  Gorjetas; system("cls"); //gorjeta por expediente (não botar gojetas com pontos flutuantes)
    printf("Aguarde..."); Sleep(1000); printf("5..."); Sleep(1000); printf("4..."); Sleep(1000); printf("3..."); Sleep(1000); printf("2..."); Sleep(1000); printf("1..."); Sleep(1000); system("cls");
    system("color 80");
    printf("Restaurante Platinium\n");
    printf("Cardápio: tradicional\n");
    printf("Número da mesa: %d \n", mesanum);
    srand(time(NULL)); //invocando números aleatórios
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
    } //FIM DO 1º FOR
    } //FIM DO IF SEM FRESCURA

    else if(vegetounao == 2)
    {
        cardapiovegetariano();
    }//FIM DO IF FRESCURA
}
void cardapiovegetariano (void)
{
    printf("Número da mesa: ");
    scanf("%d", &mesanum);

    printf("Número de acompanhantes: ");
    scanf("%d", &quantpessoas, &quantpessoas0); //atribuí um valor a duas variáveis, pois vou usar dois FORs que precisam do mesmo valor
    system("cls"); system("color F0");

    for(int valfor0=0;valfor0<=quantpessoas0;valfor0++) //For principal
    {
    float valortotal[valfor0]; //Criando o Array (VETOR) para acumular o preço total de todos os itens
    float precocomida[valfor0], precobebida[valfor0], precosobremesa[valfor0];//Criando o Array (VETOR) para ajudar o valortotal caso o usuário esteja com acompanhannte

    for(int valfor=0;valfor<=quantpessoas;valfor++) //For secundário
    {
    printf("CARDÁPIO VEGETARIANO PARA %dª PESSOA \n\nPratos do dia: \n0) Nenhum \n1) Lasanha ao molho funghi R$%.2f\n2) Arroz com brócolis R$%.2f\n3) Strogonoff de carne de soja R$%.2f\n4) Omelete de forno R$%.2f\n5) Risoto de aspargos R$%.2f\nDigite o número da comida: ", valfor+1, AtualizarVeg[0], AtualizarVeg[1], AtualizarVeg[2], AtualizarVeg[3], AtualizarVeg[4]);
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

    printf("CARDÁPIO VEGETARIANO PARA %dª PESSOA \n\nBebidas do dia: \n0) Nenhum \n1) Vinho R$%.2f\n2) Whisky R$%.2f\n3) Guaraná R$%.2f0\n4) Coca cola R$%.2f\n5) Café R$%.2f\nDigite o número da bebida: ", valfor+1, AtualizarVeg2[0], AtualizarVeg2[1], AtualizarVeg2[2], AtualizarVeg2[3], AtualizarVeg2[4]);
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

    printf("CARDÁPIO VEGETARIANO PARA %dª PESSOA \n\nSobremesas do dia: \n0) Nenhum \n1) Pudim R$4,00\n2) Milkshake R$7,00\n3) Bolo de morango R$5,00\n4) Ratatouille R$8,50\n5) Torta R$5,00\nDigite o número da sobremesa: ", valfor+1);
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
    }//FIM DO 2º FOR
    printf("Gorjeta para o garçom: "); scanf("%f", &Gorjetas); valorgorj +=  Gorjetas; system("cls"); //acumular gorjeta do expediente(não botar pontos flutuantes)
    printf("Aguarde..."); Sleep(1000); printf("5..."); Sleep(1000); printf("4..."); Sleep(1000); printf("3..."); Sleep(1000); printf("2..."); Sleep(1000); printf("1..."); Sleep(1000); printf("0"); system("cls");
    system("color 80");
    printf("Restaurante Platinium\n");
    printf("Cardápio: vegetariano\n");
    printf("Número da mesa: %d \n", mesanum);
    srand(time(NULL)); //invocando números aleatórios
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
    }    }//FIM DO 1º FOR
}
