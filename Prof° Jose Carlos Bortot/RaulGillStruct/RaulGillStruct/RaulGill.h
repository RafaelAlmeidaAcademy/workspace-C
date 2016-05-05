// declaração de programa Raul Gil com struct
#include <iostream>
#include <Windows.h>

using namespace std;

//DEFINIÇÕES do programa
#define	PAUSE					system("pause")
#define	CLS						system("cls")
#define	QTDE_MAX_CALOUROS		30
#define QTDE_MIN_CALOUROS		4
#define EXTENSAO_NOME           30
#define MASCULINO               'M'
#define FEMININO                'F'
#define NOTA_MIN                0
#define NOTA_MAX                10 

//
// Opções do menu de operador 
//
#define INCLUIR_CALOURO  'I'
#define EXIBIR_VENCEDOR  'V'
#define LISTAR_CALOUROS	 'L'
#define SAIR_DO_PROGRAMA 'S'

//
//COLECAO de Calouros
//
typedef struct tagCALOURO
{
	int nNota;
	char cSexo,
		cNome[EXTENSAO_NOME + 1];

}CALOURO;

int IncluirCalouro(CALOURO *ptrStCalouro, CALOURO *ptrVetCalouros, int *ptrProx, int *ptrTrono, int *ptrVenc);
void ExibirVencedor(CALOURO *ptrVetCalouros, int iIndVencedor);
void ListarCalouros(CALOURO *ptrVetCalouros, int iIndProx, SYSTEMTIME *ptrStTime);