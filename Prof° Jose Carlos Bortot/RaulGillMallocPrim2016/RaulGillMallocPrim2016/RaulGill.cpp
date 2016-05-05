// RaulGill - Para praticar locação dinámica de memória, Ordenação de vetor.
// FATEC  - MOGI DAS CRUZES 
// Modificação: 05.05.2016
// Autor: RAFAEL ALMEIDA DA SILVA


#include "RaulGill.h"

//Função que lista um vetor de inteiras 
//       Parametros:
//                  Entrada: int *ptrVet - endereço do primeiro byte da primeira inteira do vetor
//						     int nQtde - Quantidade de inteiras do vetor
//							 char *ptrCabec - cabeçalho da listagem
void ListarVetor(CALOURO *ptrVetor, int nQtde, char *ptrCabec)
 {
	int i;
	char cWork[200];
	CLS;
	cout << "\n\t" << ptrCabec << endl;

	for (i = 0; i < nQtde; i++)
	{
		if (i == nQtde)           // já listou a ultima inteira?
				break;

			sprintf_s(cWork, sizeof(cWork), "%d %s %d", i + 1, (ptrVetor + i)->cNome, (ptrVetor + i)->nNota);
			cout << cWork << endl;

	}//FOR I

	cout << "\t\t Fim da listagem" << endl;
	PAUSE;
}//Função - ListarVetor

// Função que classifica o vetor de Calouros e ordem alfabetica
//        Parametros:
//					 Entrada: CALOURO *ptrVetor - ponteiro do vetor de inteiras
//							  Int nQtde - quantidade de inteiras
void BubbleSortAlfabetico(CALOURO *ptrVetor, int nQtde)
{
	int i, nVetApoio;
	char cVetApoio[EXTENSAO_NOME + 1];
	bool flgHouveTroca;

	do {

		flgHouveTroca = false;

		for (i = 0; i < nQtde - 1; i++)
		{
			if (strcmp((ptrVetor + i)->cNome, (ptrVetor + i + 1)->cNome) == 1)
			{
				strcpy_s(cVetApoio, EXTENSAO_NOME + 1, (ptrVetor + i)->cNome);
				strcpy_s((ptrVetor + i)->cNome, EXTENSAO_NOME + 1, (ptrVetor + i + 1)->cNome);
				strcpy_s((ptrVetor + i + 1)->cNome, EXTENSAO_NOME + 1, cVetApoio);
				nVetApoio = (ptrVetor + i)->nNota;
				(ptrVetor + i)->nNota = (ptrVetor + i + 1)->nNota;
				(ptrVetor + i + 1)->nNota = nVetApoio;
				flgHouveTroca = true;
			}
		}
		
	} while (flgHouveTroca);
}//Função - BubbleSortAlfabetico

//Função que ordena os calouros pela nota
//			Parâmetros:
//					Entrada: CALOURO *ptrVetor - ponteiro do vetor de Calouros
//							 Int nQted - Quantidade de calouros contido no vetor
//							 Bool flgOrdem - Ordem Crescente ou Descrescente
//											(True) - Crescente
//											(False)- Decrescente.
void BubbleSortNota(CALOURO *ptrVetor, int nQtde, bool flgOrdem)
{	
	int i, nApoio;
	char cVetApoio[EXTENSAO_NOME + 1];
	bool flgHouveTroca;
	do{
		flgHouveTroca = false;

		for (i = 0; i < nQtde - 1; i++)
		{
			if (flgOrdem && (ptrVetor + i)->nNota >(ptrVetor + i + 1)->nNota 
				|| !flgOrdem && (ptrVetor + i)->nNota <(ptrVetor + i + 1)->nNota)
			{
				strcpy_s(cVetApoio, EXTENSAO_NOME + 1, (ptrVetor + i)->cNome);
				strcpy_s((ptrVetor + i)->cNome, EXTENSAO_NOME + 1, (ptrVetor + i + 1)->cNome);
				strcpy_s((ptrVetor + i + 1)->cNome, EXTENSAO_NOME + 1,cVetApoio);
				nApoio = (ptrVetor + i)->nNota;
				(ptrVetor + i)->nNota = (ptrVetor + i + 1)->nNota;
				(ptrVetor + i + 1)->nNota = nApoio;
				flgHouveTroca = true;
			}
		}
	

	} while (flgHouveTroca);

		
}// Função - BubbleSortNota

void main(void)
{
	int i,						    //indice e contador
		nIndVencedor = 0,			//indice do vencendor
		nTrono = -1,				//nota do melhor calouro
		nQtde = 0;					//Quantidade de calouros que irá cantar

	CALOURO *ptrVetCalouros,
		*ptrSalva;

	setlocale(LC_ALL, "portuguese_brazil");

	do{

		cout << "Informa a quantidade de calouros entre " << QTDE_MIN_CALOUROS << " e "
			<< QTDE_MAX_CALOUROS << endl << " Ou zero para cancelar a execução do programa: ";
		cin >> nQtde;

		if (nQtde == 0)
			return;


	} while (nQtde < QTDE_MIN_CALOUROS || nQtde > QTDE_MAX_CALOUROS);

	//sabemos a quantidade de calouros - fazer a alocação de dinamica de memoria 
	ptrVetCalouros =
		ptrSalva = (CALOURO *)malloc(nQtde * sizeof(CALOURO));
	if (ptrSalva == NULL)
	{
		cout << "Nao tem memoria disponivel!" << endl;
		PAUSE;
		return;
	}

	//loop para receber os calouros 
	for (i = 0; i < nQtde; i++)
	{
		//pedir nome e sobrenome 
		cin.ignore(1, EOF);
		cout << "Informe o nome: ";
		cin.getline((ptrVetCalouros + i)->cNome, 30, '\n');

		do {
			cout << "Nota de 0 a 10: ";
			cin >> (ptrVetCalouros + i)->nNota;

		} while ((ptrVetCalouros + i)->nNota < 0 || (ptrVetCalouros + i)->nNota > 10);

		// verifica se vai para o trono 
		if ((ptrVetCalouros + i)->nNota > nTrono)
		{
			nTrono = (ptrVetCalouros + i)->nNota;
			nIndVencedor = i;
		}
	}//For 

	//sabemos quem e o vencendor 
	cout << "O vencedor é: " << (ptrVetCalouros + nIndVencedor)->cNome << " Nota: "
		<< (ptrVetCalouros + nIndVencedor)->nNota << endl;

	PAUSE;
	  
	// Exibir os calouros na ordem que cantaram
	ListarVetor(ptrVetCalouros, nQtde,"LISTA CALOUROS POR ORDEM QUE CATARAM: ");

	// Classificar em ordem alfabetica e exibir calouros em ordem 
	BubbleSortAlfabetico(ptrVetCalouros, nQtde);
	ListarVetor(ptrVetCalouros, nQtde, "LISTA CALOUROS POR ORDEM ALFABETICA: ");
	// Classificar pela nota
	BubbleSortNota(ptrVetCalouros, nQtde, true);
	ListarVetor(ptrVetCalouros, nQtde, "LISTAR ORDENADA POR NOTA");

	free(ptrSalva);

}// MAIN();
	