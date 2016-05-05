// declaração de programa Raul Gil com Memory Allocation
#include <iostream>
#include <Windows.h>

using namespace std;

//DEFINIÇÕES do programa
#define	PAUSE					system("pause")
#define	CLS						system("cls")
#define	QTDE_MAX_CALOUROS		30
#define QTDE_MIN_CALOUROS		4
#define EXTENSAO_NOME           30

typedef struct tagCalouro
{
	int nNota;
	char cNome[EXTENSAO_NOME + 1];
}CALOURO;