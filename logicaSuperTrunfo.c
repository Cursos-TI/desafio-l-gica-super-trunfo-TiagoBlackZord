#include<stdio.h>
#include <string.h>
int main(){

	char estado1, estado2, codigoCarta1[4], codigoCarta2[4], nomeCidade1[25], nomeCidade2[25], escolhaDoUsuarioEscrita[30], escolhaDoUsuarioEscrita2[30];
	int pontosTuristicos1, pontosTuristicos2, populacao1, populacao2, escolhaDoUsuario, escolhaDoUsuario2, carta1=0, carta2=0, aux1=0, aux2=0;
	float area1, area2, pib1, pib2, densidadePopulacional1, densidadePopulacional2, PibPerCapita1, PibPerCapita2, valorAtributoFloat1=0, valorAtributoFloat2=0, SuperPoder1, SuperPoder2;

	//Recebendo valores do usuário para a carta 1
	printf("\n\n*** Carta 1 ***\n");
	printf("\nInforme a primeira letra do Estado: ");
	scanf("%c", &estado1);
	printf("\nInforme o código da carta. Ex: 01, 02, 03 ou 04: ");
	scanf("%s", codigoCarta1);
	printf("\nInforme o nome cidade: ");
	scanf(" %[^\n]", nomeCidade1);
	printf("\nInforme quantidade total da população no Estado: ");
	scanf("%d", &populacao1);
	printf("\nInforme a área total do Estado: ");
	scanf("%f", &area1);
	printf("\nInforme o PIB do Estado: ");
	scanf("%f", &pib1);
	printf("\nInforme a quantidade de pontos turisticos do Estado: ");
	scanf(" %d", &pontosTuristicos1);

	//Recebendo valores do usuário para a carta 2
	printf("\n\n*** Carta 2 ***\n");
	printf("\nInforme a primeira letra do Estado: ");
	scanf(" %c", &estado2);
	printf("\nInforme o código da carta. Ex: 01, 02, 03 ou 04: ");
	scanf("%s", codigoCarta2);
	printf("\nInforme o nome cidade: ");
	scanf(" %[^\n]", nomeCidade2);
	printf("\nInforme quantidade total da população no Estado: ");
	scanf("%d", &populacao2);
	printf("\nInforme a área total do Estado: ");
	scanf("%f", &area2);
	printf("\nInforme o PIB do Estado: ");
	scanf("%f", &pib2);
	printf("\nInforme a quantidade de pontos turisticos do Estado: ");
	scanf("%d", &pontosTuristicos2);

	//Calculando a Densidade Populacional e o PIB per capita
    densidadePopulacional1 = populacao1 / area1;
    densidadePopulacional2 = populacao2 / area2;

    PibPerCapita1 = pib1 / populacao1;
    PibPerCapita2 = pib2 / populacao2;

	//Menu interativo 1
	printf("\n\nAgora, você deve escolher um atributo para comparar as cartas!\nVocê pode escolher entre:\n\n");
	printf("1. População\n2. Área\n3. PIB\n4. Número de Pontos Turísticos\n5. Densidade Demográfica\n\n Digite um número de opção: ");
	scanf("%d", &escolhaDoUsuario);

	//Pegando a escolha escrita do usuário 1
	if(escolhaDoUsuario == 1){
		strcpy(escolhaDoUsuarioEscrita, "População"); valorAtributoFloat1 = populacao1;
	} else if(escolhaDoUsuario == 2){
		strcpy(escolhaDoUsuarioEscrita, "Área"); valorAtributoFloat1 = area1;
	} else if(escolhaDoUsuario == 3){
		strcpy(escolhaDoUsuarioEscrita, "PIB"); valorAtributoFloat1 = pib1;
	} else if(escolhaDoUsuario == 4){
		strcpy(escolhaDoUsuarioEscrita, "Número de Pontos Turísticos"); valorAtributoFloat1 = pontosTuristicos1;
	} else if(escolhaDoUsuario == 5){
		strcpy(escolhaDoUsuarioEscrita, "Densidade Demográfica"); valorAtributoFloat1 = densidadePopulacional1;
	}

	//Menu interativo 2
	if(escolhaDoUsuario > 5 || escolhaDoUsuario < 1){
		printf("\n\n");
	}else{
        printf("\n\nVocê escolheu %s, agora escolha outro atributo\n\n", escolhaDoUsuarioEscrita);
        printf("1. População\n2. Área\n3. PIB\n4. Número de Pontos Turísticos\n5. Densidade Demográfica\n\n Digite um número de opção: ");
        scanf("%d", &escolhaDoUsuario2);
    
        //Pegando a escolha escrita do usuário 2
        if(escolhaDoUsuario2 == 1){
            strcpy(escolhaDoUsuarioEscrita2, "População"); valorAtributoFloat2 = populacao2;
        } else if(escolhaDoUsuario2 == 2){
            strcpy(escolhaDoUsuarioEscrita2, "Área"); valorAtributoFloat2 = area2;
        } else if(escolhaDoUsuario2 == 3){
            strcpy(escolhaDoUsuarioEscrita2, "PIB"); valorAtributoFloat2 = pib2;
        } else if(escolhaDoUsuario2 == 4){
            strcpy(escolhaDoUsuarioEscrita2, "Número de Pontos Turísticos"); valorAtributoFloat2 = pontosTuristicos2;
        } else if(escolhaDoUsuario2 == 5){
            strcpy(escolhaDoUsuarioEscrita2, "Densidade Demográfica"); valorAtributoFloat2 = densidadePopulacional2;
        }
	}

    // Somando os atributos de cada carta    
    SuperPoder1 = (populacao1 + area1 + pib1 + pontosTuristicos1 + PibPerCapita1)-densidadePopulacional1;
	SuperPoder2 = (populacao2 + area2 + pib2 + pontosTuristicos2 + PibPerCapita2)-densidadePopulacional2;


	//Agora, será investigado se o usuário digitou algum caractere diferente ou escolheu atributos iguais
	if(escolhaDoUsuario > 5 || escolhaDoUsuario < 1 || escolhaDoUsuario2 > 5 || escolhaDoUsuario2 < 1 || escolhaDoUsuario == escolhaDoUsuario2){
		printf("\n\nVocê escolheu uma opção que não existe ou você escolheu atributos iguais!\nExecute o programa novamente.\n\n");
	}else{
		switch (escolhaDoUsuario)//Somando primeiro atributo para saber se carta 1 ou 2 venceu
		{
		case 1:
			carta1 = populacao1 > populacao2 ? 1 : 0;
			carta2 = populacao1 < populacao2 ? 1 : 0;
			break;
		case 2:
			carta1 = area1 > area2 ? 1 : 0;
			carta2 = area1 < area2 ? 1 : 0;
			break;
		case 3:
			carta1 = pib1 > pib2 ? 1 : 0;
			carta2 = pib1 < pib2 ? 1 : 0;
			break;
		case 4:
			carta1 = pontosTuristicos1 > pontosTuristicos2 ? 1 : 0;
			carta2 = pontosTuristicos1 < pontosTuristicos2 ? 1 : 0;
			break;
		case 5:
			carta1 = densidadePopulacional1 < densidadePopulacional2 ? 1 : 0;
			carta2 = densidadePopulacional1 > densidadePopulacional2 ? 1 : 0;
			break;
		default:
			break;
		}
        
        switch (escolhaDoUsuario2)//Somando segundo atributo para saber se carta 1 ou 2 venceu
		{
		case 1:
			aux1 = populacao1 > populacao2 ? 1 : 0;
			aux2 = populacao1 < populacao2 ? 1 : 0;
			break;
		case 2:
			aux1 = area1 > area2 ? 1 : 0;
			aux2 = area1 < area2 ? 1 : 0;
			break;
		case 3:
			aux1 = pib1 > pib2 ? 1 : 0;
			aux2 = pib1 < pib2 ? 1 : 0;
			break;
		case 4:
			aux1 = pontosTuristicos1 > pontosTuristicos2 ? 1 : 0;
			aux2 = pontosTuristicos1 < pontosTuristicos2 ? 1 : 0;
			break;
		case 5:
			aux1 = densidadePopulacional1 < densidadePopulacional2 ? 1 : 0;
			aux2 = densidadePopulacional1 > densidadePopulacional2 ? 1 : 0;
			break;
		default:
			break;
		}


        //Calculando tudo para saber quem venceu

        carta1 = carta1 + aux1;
        carta2 = carta2 + aux2;

        printf("\n\n *** Resultado ***\n");
        printf("\n%s          %s", nomeCidade1, nomeCidade2);
        printf("\n%s          %s", escolhaDoUsuarioEscrita, escolhaDoUsuarioEscrita2);
        printf("\n%.2f        %.2f", valorAtributoFloat1, valorAtributoFloat2);
        printf("\n%.2f        %.2f", SuperPoder1, SuperPoder2);

        if(carta1 > carta2){
            printf("\n*** Carta 1 venceu! ***\n\n");
        } else if(carta2 > carta1){
            printf("\n*** Carta 2 venceu! ***\n\n");
        } else{
            printf("\n*** Empate! ***\n\n");
        }
	}


    return 0;

}