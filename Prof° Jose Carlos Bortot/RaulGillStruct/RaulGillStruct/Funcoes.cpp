// Fun��es do programa Raul Gil
#include "RaulGill.h"

//EXEMPLO COMENT�RIO
// DESCRI��O de a��o da fun��o
//  Par�metros:
//        Entrada: 


// Fun��o que inclui um calouro no vetor de calouros
//  Par�metros:
//        Entrada:   CALOURO *ptrStCalouro - ponteiro para um struct que contem os dados do calouro; 
//					 CALOURO *ptrVetCalouro - ponteiro do primeiro calouro do vetor;
//                  int *ptrProx - ponteiro do indice do proximo calouro do vetor de calouros;
//                  int *ptrTrono - ponteiro para a nota  do melhor calouro ;
//                  int *ptrVenc - ponteiro de indice do melhor calouro do vetor.
//
//        Retorno:	int  Indice do proximo calouro no vetor de calouros.
// 
int IncluirCalouro(CALOURO *ptrStCalouro,CALOURO *ptrVetCalouros, int *ptrProx, int *ptrTrono, int *ptrVenc)
{
	// inclus�o do calouro no vetor de calouros
	memcpy_s((ptrVetCalouros + *ptrProx),                  //Endere�o base do vetor + (indice * sizeof(CALOURO)) 
		sizeof(CALOURO),                                   //tamanho em bytes do destino
		ptrStCalouro,                                      //endere�o da struct do chamador que contem o calouro 
		sizeof(CALOURO));                                  //tamanho em bytes da origem

	// verificar se o calouro va para o trono
	if (ptrStCalouro->nNota > *ptrTrono)                    //vai para o trono ?
	{
		*ptrTrono = ptrStCalouro->nNota;                    //nota do melhor vai para o trno
		*ptrVenc = *ptrProx;								//salva o indice deste melhor calouro

	}
    // devolver o indice da fun�ao
	return ++*ptrProx;
} // Incluir Calouro


// Fun��o que exibe o vencendor 
//  Par�metros:
//        Entrada: CALOURO *ptrVetCalouros - ponteiro do primeiro calouro do vetor
//                 int     iIndVencedor - Indice do calouro vencedor 
//
void ExibirVencedor(CALOURO *ptrVetCalouros, int iIndVencedor)
{
	cout <<endl<<"<-----------------[INFORMA��ES DO VENCEDOR]--------------->"<<endl
		<< "NOME: " << (ptrVetCalouros + iIndVencedor)->cNome<< endl
		<< "NOTA: " << (ptrVetCalouros + iIndVencedor)->nNota<< endl;
	PAUSE;
}


// Fun��o que lista os calouros que cantaram at� agora
//  Par�metros:
//        Entrada: CALOURO *ptrVetcalouros - ponteiro para o primeiro calouro do vetor 
//                 int iIndProx - indice do proximo calouro aser inserido no vetor 
//                 SYSTEMTIME *ptrStTime - ponteiro para struct que contem a data e hora para compor um cabe�alho simp�tico.
void ListarCalouros(CALOURO *ptrVetCalouros, int iIndProx, SYSTEMTIME *ptrStTime)
{
	int i;
	char cWork[200];
	sprintf_s(cWork, sizeof(cWork), "\n\t<----------Listar todos os Alunos---------> \n\t %02d/%02d/%04d �s %02d:%02d:%02d",
		(ptrStTime)->wDay,
		(ptrStTime)->wMonth, 
		(ptrStTime)->wYear,
		(ptrStTime)->wHour,
		(ptrStTime)->wMinute, 
		(ptrStTime)->wSecond);
	cout << cWork << endl;
	cout << "C�digo |\tNome |\t\tSexo |\t\t\tNota" << endl;
	for (i = 0; i < iIndProx; i++)
	{

		sprintf_s(cWork, sizeof(cWork), "%d \t%s \t\t%c \t\t\t%d",
			(i+1),
			(ptrVetCalouros + i)->cNome,
			(ptrVetCalouros + i)->cSexo,
			(ptrVetCalouros + i)->nNota);
		cout << cWork << endl;
	}
	PAUSE;
}