/*Baseado na função abaixo que gera números ordenados, invertidos e aleatórios,
 construa um programa para simular os resultados das cinco figuras acima, deve ser 
 simulando em três vetores de dez mil dados do tipo inteiro:*/

 #include <windows.h>
 #include <stdio.h>
 #include <stdlib.h>
 #include <conio.h>
 #include "ordenacao.h"

#define qtd 10000

int main(void) {
	float loading = 0;
	const float loadingSoma = 5.5556;
	int vetor[qtd];
	float resposta[3];
	METODOORDENACAO metodos[5];
	int i=0, op=1 ,tamanho = sizeof(vetor)/sizeof(int);
	//--------------------------Variaveis----------------------------------//
	for(op;op<=3;op++){
		
		geraNumero(vetor , op, tamanho); // gera o vetor de acordo com a operação solicitada.
		loading += loadingSoma;
		system("cls");
		printf("Loading... %.2f%s", loading, "%");		
		
		//--------------------------------------bubbleSort--------------------------------//
		bubbleSort(vetor,resposta);
		armazenaResposta(resposta[0],resposta[1],resposta[2],op,metodos,0);
		
		loading += loadingSoma;
		system("cls");
		printf("Loading... %.2f%s", loading, "%");
				
		//--------------------------------------InsertionSort--------------------------------//
		geraNumero(vetor , op, tamanho);
		insertionSort(vetor,resposta);
		armazenaResposta(resposta[0],resposta[1],resposta[2],op,metodos,1);
		
		loading += loadingSoma;
		system("cls");
		printf("Loading... %.2f%s", loading, "%");
		
		//--------------------------------------SelectionSort--------------------------------//
		geraNumero(vetor , op, tamanho);
		selectionSort(vetor,resposta);
		armazenaResposta(resposta[0],resposta[1],resposta[2],op,metodos,2);
		
		loading += loadingSoma;
		system("cls");
		printf("Loading... %.2f%s", loading, "%");
		
		//--------------------------------------MergeSort--------------------------------//
		geraNumero(vetor , op, tamanho);
		mergeSort(vetor, resposta, 0, 9999);
		armazenaResposta(resposta[0],resposta[1],resposta[2],op,metodos,3);
		
		loading += loadingSoma;
		system("cls");
		printf("Loading... %.2f%s", loading, "%");
		
		//--------------------------------------QuickSort--------------------------------//
		geraNumero(vetor , op, tamanho);
		quickSort(vetor,resposta);
		armazenaResposta(resposta[0],resposta[1],resposta[2],op,metodos,4);
		gravaArquivo(metodos);
		
		loading += loadingSoma;
		system("cls");
		printf("Loading... %.2f%s", loading, "%");
	}
	
	system("cls");
	printf("\n\nLoading... 100%s Complete!!!\n\n","%");
	printf("\n-----------------------------\n\n");
	printf("Press any key to continue...");
	getch();
	
	
	ShellExecute(NULL, "open", "..\\main.html",
                NULL, NULL, SW_SHOWNORMAL);
	
}





