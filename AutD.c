//BIBLIOTECAS
//DESENVOLVIDO POR GUILHERME PATRICK BRAGA DE OLIVEIRA
#include <stdlib.h>
#include <stdio.h>
#include <locale.h>
#include <time.h>
#include <dos.h>

//DELAY
void delay (unsigned int mseconds){

unsigned int goal = mseconds + clock();
while (goal > clock());
}

//MENU's
int menuPrincipal(){

    int menu=0;

	printf("Primeiramente digite:\n"
		"1 - Calcular em quanto tempo o download ir� terminar ;\n"
		"2 - J� sei em quanto tempo desejo desligar/reiniciar;\n"
		"Qualquer outro caractere para sair.\n"
		"-----> ");
	scanf("%d", &menu);

	return menu;
}

int menuTempo(){

    int menu=0;

	printf("\nDigite:\n"
		"1 - Para Desligar;\n"
		"2 - Para Reiniciar;\n"
		"Qualquer outro caractere para sair.\n"
		"-----> ");
	scanf("%d", &menu);

	return menu;
}

//FUN��O DE DESLIGAMENTO POR TEMPO
int DeslTempo (){

            int segundos, minutos, horas, calculo;

            printf("\n\nAgora digite em quanto tempo voc� deseja desligar: \n");
            printf("Horas: ");
            scanf("%d", &horas);
            printf("Minutos: ");
            scanf("%d", &minutos);
            printf("Segundos: ");
            scanf("%d", &segundos);

            InstrucoesCancelamento();

            calculo = ((horas*3600) + (minutos*60) + (segundos))*1000;
            printf("\n         Seu computador ir� desligar/reiniciar em: %d segundos", calculo/1000);
            printf("\n         A barra indica que o tempo est� correndo: ");

            return calculo;

}

//FUN��O DE DESLIGAMENTO POR DOWNLOAD
int DeslDownload (){

            int kb, mb, gb, calculo, velocidade;

            printf("\n\nAgora digite a quantidade de dados total a ser baixada: \n");
            printf("Gigabytes: ");
            scanf("%d", &gb);
            printf("Megabytes: ");
            scanf("%d", &mb);
            printf("Kbytes: ");
            scanf("%d", &kb);

            printf("\nQual sua taxa m�nima de download em kbps? ");
            scanf("%d", &velocidade);

            InstrucoesCancelamento();

            calculo = (((gb*1048576) + (mb*1024) + (kb))/velocidade)*1000;
            printf("\n         Seu computador ir� desligar em: %d segundos", calculo/1000);
            printf("\n         A barra indica que o tempo est� correndo: ");

            return calculo;

}

//FUN��O EXPLICATIVA SOBRE O CANCELAMENTO
void InstrucoesCancelamento(){

            printf("\n\nINSTRU��ES PARA CANCELAMENTO:\n\n");

            printf("***     O programa funciona com um delay de contagem de tempo.\n"
                   "***     V�o haver dois momentos principais antes do desligamento.\n"
                   "***     O primeiro � a contagem de tempo e o segundo � o tempo que\n"
                   "***     o Windows leva para desligar de maneira segura.\n\n");
            printf("***     Como reconhe�o em qual momento estou?\n"
                   "***     O reconhecimento � simples e claro.\n"
                   "***     Durante a contagem do tempo o programa vai estar sendo executado.\n"
                   "***     Na segunda fase ser� exibida uma mensagem pelo Windows antecipando o desligamento.\n\n");

            printf("***     Para cancelar durante a primeira fase � necess�rio\n"
                   "***     apenas o fechamento do programa.\n\n");

            printf("***     Para cancelar ap�s a mensagem do windows \n"
                    "***     entre no CMD (prompt de comando) e digite \n"
                    "***    'shutdown -a', sem as aspas.\n");
            printf("***     Para entrar no prompt de comando digite:\n"
                    "***     CTRL + R para abrir o 'Executar', digite\n"
                    "***     ent�o: 'cmd' e aperte enter.\n\n");

}

//MAIN
int main (){
setlocale(LC_ALL, "Portuguese");

	printf("\nOl�, seja muito bem vindo ao AutD!\n"
            "Minha fun��o � ajudar voc� a desligar ou\n"
            "reiniciar seu computador de forma\n"
            "automatizada de acordo com um timer.\n"
            "Vamos l�!\n\n");

    switch (menuPrincipal()){

        case 1: {

            //CALCULAR E DESLIGAR COM O TEMPO DE DOWNLOAD
            delay(DeslDownload());
            system("c:\\windows\\system32\\shutdown /s");

        break;}

        case 2: {switch (menuTempo()){

            case 1:{

                delay(DeslTempo());
                system("c:\\windows\\system32\\shutdown /s");

            break;}

            case 2:{

                delay(DeslTempo());
                system("c:\\windows\\system32\\shutdown /r");

            break;}

            default:{break;}/*MENU TEMPO*/}

        default:{break;}/*MENU PRINCIPAL*/}

    }
    printf("\n\n         Obrigado por usar o AutD!\n\n");
    return 0;
}
