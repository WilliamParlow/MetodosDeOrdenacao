#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <iostream>
#include <fstream>
#include <string>
using namespace std;


typedef struct metodosOrdenacao {
	float tempoOrd;
	int trocaOrd;
	int comparacaoOrd;
	float tempoDec;
	int trocaDec;
	int comparacaoDec;
	float tempoAl;
	int trocaAl;
	int comparacaoAl;
}METODOORDENACAO;

//--------------------------------------------------BubbleSort-------------------------------//

void bubbleSort (int vet[], float clone[]){
	float tempo = (clock());  
	int n, i, aux,trocas = 0, comparacoes = 0;
	
    for (n = 1; n <= 10000; n++) {
    	for (i = 0; i < 9999; i++) {
        	comparacoes++;	
            if (vet[i] > vet[i + 1]) {
            	trocas++;
                aux = vet[i];
                vet[i] = vet[i + 1];
                vet[i + 1] = aux;
            }
        }
    }  
	
    clone[0] = comparacoes;
    clone[1] = trocas;
    clone[2] = ((clock())-tempo)/1000;
    
}

//----------------------------------------- InsertionSort----------------------------------------//
void insertionSort (int vet[], float clone[]) {
	
	float tempo = (clock());
    int i, j, eleito, trocas = 0, comparacoes = 0;

	for (i = 1; i <= 9999; i++) {
		comparacoes++;
        eleito = vet[i];
        j = i - 1;
        while (j >= 0 && vet[j] > eleito) {
        	trocas++;
        	comparacoes++;
            vet[j + 1] = vet[j];
            j = j - 1;
        }
        vet[j + 1] = eleito;
    }
	
	clone[0] = comparacoes;
    clone[1] = trocas;
    clone[2] = ((clock())-tempo)/1000;
    
}

//--------------------------------------------SelectionSort----------------------------------------//
void selectionSort (int vet[], float clone[]) {
	
	float tempo = (clock());
	
    int i, j, eleito, menor, pos, trocas = 0, comparacoes = 0;

	for (i = 0; i <= 9998; i++) {
		comparacoes++;
        eleito = vet[i];
        menor = vet[i + 1];
        pos = i + 1;
        for (j = i + 2; j <= 9999; j++) {
        	comparacoes++;
            if (vet[j] < menor) {
                menor = vet[j];
                pos = j;
            }
        }
        if (menor < eleito) {
        	trocas++;
            vet[i] = vet[pos];
            vet[pos] = eleito;
        }
    }

	
	clone[0] = comparacoes;
    clone[1] = trocas;
    clone[2] = ((clock())-tempo)/1000;
    
}

//--------------------------------------------MergeSort----------------------------------------//

void intercala(int vet[], int inicio, int fim, int meio, float resposta[]) {
    int poslivre = inicio, iniciovetor1 = inicio, iniciovetor2 = meio + 1, i;
    int aux[9999];
    while (iniciovetor1 <= meio && iniciovetor2 <= fim) {
    	resposta[0]++;
    	resposta[1]++;
        if (vet[iniciovetor1] <= vet[iniciovetor2]) {
            aux[poslivre] = vet[iniciovetor1];
            iniciovetor1++;
        } else {
            aux[poslivre] = vet[iniciovetor2];
            iniciovetor2++;
        }
        poslivre++;
    }
    for (i = iniciovetor1; i <= meio; i++) {
    	resposta[1]++;
        aux[poslivre] = vet[i];
        poslivre++;
    }
    for (i = iniciovetor2; i <= fim; i++) {
    	resposta[1]++;
        aux[poslivre] = vet[i];
        poslivre++;
    }
    for (i = inicio; i <= fim; i++) {
    	resposta[1]++;
        vet[i] = aux[i];
    }
}

void merge(int vet[], float resposta[], int inicio, int fim) {
    int meio;
//    resposta[0]++;
    if (inicio < fim) {
        meio = (inicio + fim) / 2;
        merge(vet, resposta, inicio, meio);
        merge(vet, resposta, meio + 1, fim);
        intercala(vet, inicio, fim, meio, resposta);
    }
}

void mergeSort(int vet[], float resposta[], int inicio, int fim) {
    
	int i;
    
    for (i = 0; i < 3; i++) {
    	resposta[i] = 0;
	}
    
    float tempo = (clock());
    merge(vet, resposta, inicio, fim);
	resposta[2]= ((clock())-tempo)/1000;    
    
}


//-------------------------------------------quickSort------------------------------------------//
int partition(int vet[], int ini, int fim,float resposta[]) {
    int pivo, topo, i;
    pivo = vet[ini];
    topo = ini;

    for (i = ini + 1; i <= fim; i++) {
    	resposta[0]++;
        if (vet[i] < pivo) {
        	resposta[1]++;
            vet[topo] = vet[i];
            vet[i] = vet[topo + 1];
            topo++;
        }
    }
    vet[topo] = pivo;
    return topo;
}

void quicksort(int vet[], int ini, int fim,float resposta[]) {
    int meio;
	resposta[0]++;
    if (ini < fim) {    	
        meio = partition(vet, ini, fim,resposta);
        quicksort(vet, ini, meio,resposta);
        quicksort(vet, meio + 1, fim,resposta);
    }
}



void quickSort(int vet[], float resposta[]){
	float tempo = (clock());
	int ini = 0, fim = 10000;
	quicksort(vet,ini,fim,resposta);
	resposta[2]= ((clock())-tempo)/1000;
}

//-----------------------------------------------------complementos-------------------------------------------//

/* Função geradora do vetor*/
void geraNumero(int *vet, int op, int length) {
        int i, j;

        switch (op) {
            case 1: // Ordenados
                for (i = 0; i < length; i++) {
                    vet[i] = i + 1;
                }
                break;
            case 2: //Invertidos
                for (i = 0; i < length; i++) {
                   vet[i] = length-i;
                }
                break;
            case 3: // Aleatórios
                for (i = 0; i < length; i++) {
                    vet[i] = (int) (rand() % 1000);
                }
                break;
        }

    }
void armazenaResposta(float comparacoes, float trocas, float tempo,int operacao, METODOORDENACAO* metodo,int indiceMetodo){
	switch (operacao){
		case 1:
			metodo[indiceMetodo].comparacaoAl = comparacoes;
			metodo[indiceMetodo].trocaAl = trocas;
			metodo[indiceMetodo].tempoAl = tempo;
			break;
		case 2:
			metodo[indiceMetodo].comparacaoDec = comparacoes;
			metodo[indiceMetodo].trocaDec = trocas;
			metodo[indiceMetodo].tempoDec;
			break;
		case 3:
			metodo[indiceMetodo].comparacaoOrd = comparacoes;
			metodo[indiceMetodo].trocaOrd = trocas;
			metodo[indiceMetodo].tempoOrd = tempo;
			break;
	}
	
}



void gravaArquivo(METODOORDENACAO* dados){
	int i,j;

	ofstream myfile ("../js/dados.js");
  if (myfile.is_open())
  {
  	myfile << "var dadosGerais = [\n";
    for(i=0;i<5;i++){
    	myfile << "\t{\n";
    	myfile << "\t\t\"Comparacoes\": [" << dados[i].comparacaoAl<<", " << dados[i].comparacaoDec <<", "<< dados[i].comparacaoOrd<<"],\n";
    	myfile << "\t\t\"Trocas\": [" << dados[i].trocaAl<<", " << dados[i].trocaDec <<", "<< dados[i].trocaOrd<<"],\n";
    	myfile << "\t\t\"Tempos\": [" << dados[i].tempoAl<<", " << dados[i].tempoDec <<", "<< dados[i].tempoOrd<<"]\n";
    	if (i == 4) {
    		myfile << "\t}\n";
		} else {
			myfile << "\t},\n";	
		}
		
	}
	myfile << "\n];";
  }
  else cout << "Unable to open file";
  
}

