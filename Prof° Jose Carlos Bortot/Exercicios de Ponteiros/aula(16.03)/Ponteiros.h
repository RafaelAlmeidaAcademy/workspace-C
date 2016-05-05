//Declara�oes do programa Raul Gil com quantidade maxima possivel
#include <iostream>
#include <Windows.h>
using namespace std;
//DEFINICOES 
#define PAUSA			  system("pause")
#define LIMPAR_TELA       system("cls")

//protótipos
void ListaVetor(int *ptrVet, int nQtde, char *ptrCabec);
void ListaVetorInversamente(int *ptrVet, int nQtde, char *ptrCabec);
void ListaVetorInversamentePonteiroDireto(int *ptrVet, int nQtde, char *ptrCabec);