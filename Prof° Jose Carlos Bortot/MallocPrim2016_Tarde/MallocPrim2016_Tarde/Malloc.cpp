// Programa que testa a alocação dinâmica de memória (malloc) dynamic memory Allocation
// FATEC  - MOGI DAS CRUZES 
// Modificação: 05.05.2016
// Autor: RAFAEL ALMEIDA DA SILVA

#include "Meu.h"
void ListarVetor(int *ptrVetor, int nQtde, char *ptrCabec);

// Função que classifica o vetor de inteiras e ordem crescente ou descrescente 
//        Parametros:
//					 Entrada: Int *ptrVetor - ponteiro do vetor de inteiras
//							  Int nQtde - quantidade de inteiras
//							  bool flgOrdem - true indica ordem crescente e false indica ordem decrescente
void BubbleSort(int *ptrVetor, int nQtde, bool flgOrdem)
{ 
	int i, nApoio;
	bool flgHouveTroca;

	do {
			
		flgHouveTroca = false;

		for ( i = 0; i < nQtde - 1; i++)
		{
			if (
				flgOrdem && *(ptrVetor + i) > *(ptrVetor + (i + 1)) ||
				!flgOrdem && *(ptrVetor + i) < *(ptrVetor + (i + 1))
				)
			{
				nApoio = *(ptrVetor + i);
				*(ptrVetor + i) = *(ptrVetor + i + 1);
				*(ptrVetor + i + 1) = nApoio;
				flgHouveTroca = true;
			}
		}

	} while (flgHouveTroca);
}

//Função que lista um vetor de inteiras 
//       Parametros:
//                  Entrada: int *ptrVet - endereço do primeiro byte da primeira inteira do vetor
//						     int nQtde - Quantidade de inteiras do vetor
//							 char *ptrCabec - cabeçalho da listagem
void ListarVetor(int *ptrVetor, int nQtde, char *ptrCabec)
{
	int i, j;
	LIMPA_TELA;
	cout << "\n\t" << ptrCabec << endl;

	for (i = 0; i < nQtde;)
	{
		for ( j = 0; j < 8; j++, i++)           
		{
			if (i == nQtde)           // já listou a ultima inteira?
				break;
			cout << *ptrVetor++ << "\t";
			
		}//FOR J

		cout << endl;
	}//FOR I
		
	cout << "\t\t Fim da listagem" << endl;
	PAUSA;
}
 
void main(void)
{
	int  nQtdeInteiras = 0,								//para receber a quantidade de inteiras
		*ptrVetInteiras,								//para receber o ponteiro do vetor de inteiras
		*ptrSalvaGuarda,								//copia do ponteiro do vetor de inteiras 
		 i, j;											//Indices e contadores
	
	setlocale(LC_ALL, "portuguese_brazil");

	cout << "Qtd de inteiras do vetor: ";
	cin >> nQtdeInteiras;								//recebe a quantidade de inteiras

	//fazer a alocação dinâmica deste vetor de inteiras 
	ptrSalvaGuarda =
		// Exemplo: [malloc]
		//	malloc(Qtd em Bytes que deseja receber do sistema operacional)
		//	 retorno -> void * - um espaço sem tipo nenhum
		//	(int *) - aponta o espaço da memoria (void *)  como inteiro
		// nQtdeInteiras * sizeof(int) -> ( pega a quatidade de inteiras ) * (o tamanho em byte da variavel do tipo int)
		ptrVetInteiras = (int *) malloc(nQtdeInteiras * sizeof(int));     

	if (ptrVetInteiras == NULL)
	{  
		//Não tem memória disponivel
		cout << "Não possui memória desponivel no sistema operacional." << endl
			<< "Derrube todos os programas inúteis e recarregue o porgrama." << endl;
		PAUSA;
		return;
	
	}

	//vamos inserir valores random no vetor 
	srand(100);
	
	for (i = 0; i < nQtdeInteiras; i++, ptrVetInteiras++)
	{
		*ptrVetInteiras = rand();				//insere um valor randomico
	}
	
	//restaurar o ponteiro que foi alterado.
	ptrVetInteiras = ptrSalvaGuarda;			//Restaura o ponteiro 

	ListarVetor(ptrVetInteiras, nQtdeInteiras, "LISTAGEM ORIGINAL");

	// Classificar em ordem crescente e listar
	BubbleSort(ptrVetInteiras, nQtdeInteiras, true);
	ListarVetor(ptrVetInteiras, nQtdeInteiras, "Listagem em ordem crescente");
	PAUSA;

	BubbleSort(ptrVetInteiras, nQtdeInteiras, false);
	ListarVetor(ptrVetInteiras, nQtdeInteiras, "Listagem em ordem descrescente");
	PAUSA;

	//liberar a memória que foi alocada 
	free(ptrSalvaGuarda);				 
}


