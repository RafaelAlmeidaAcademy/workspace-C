// Programa de [Introdução] a ponteiros
// FATEC  - MOGI DAS CRUZES 
// Modificação: 05.05.2016
// Autor: RAFAEL ALMEIDA DA SILVA

#include "Ponteiros.h"

void main(void)
{
	int nValor = 100,
		nValor1 = 500,
		nResultado,
		*ptrA,                                   //Ponteiro do tipo int sem valor de inicio
		*ptrB = &nValor1,                        // Aponta o nValor1 
		*ptrC = &nResultado,                     // Aponta Resultado
		**ptrX = &ptrC,
		***ptrZ = &ptrX,
		vetInteiras[100];

	setlocale(LC_ALL, "portuguese_brazil");




	nResultado = nValor + nValor1;
	cout << " nValor=" << nValor << " nValor1 = " << nValor1 << " nResultado = " << nResultado << endl;
	PAUSA;

	ptrA = &nValor;
	*ptrC = 0;
	cout << "&nResultado = " << &nResultado << " Resultado = " << nResultado << endl;

	*ptrC = *ptrA + *ptrB;
	cout << " *ptrA = " << *ptrA << " *ptrB = " << *ptrB << " *ptrC = " << *ptrC << endl    // Mostra o valor dos locais armazenados 
		<< " ptrA = " << ptrA << " ptrB= " << ptrB << " ptrC = " << ptrC << endl;          // Mostra os locais armazenados 
	cout << "**ptrX = " << **ptrX << " *ptrX = "<< *ptrX <<endl;
	cout << "***ptrZ = " << ***ptrZ << "&ptrX = " << &ptrX << endl;

	***ptrZ = *ptrA + *ptrB;                                             // Soma os valores apontados pelos ponteiros A e B
	cout << "*** ptrZ = " << ***ptrZ << "&ptrX = " << &ptrX << endl;
	ptrA = vetInteiras;                                                  // ptrA esta apontando para a primeira inteira do Vetor &vetinteiras tbm funcionaria

	cout << "ptrA antes: " << ptrA << endl; 
	PAUSA;
	int i, j;
	for (i = 0; i < 100; i++,ptrA++)           // Preencher o ponteiro direto 
		*ptrA = i + 1;
	
	// UTILIZAR O PONTEIRO DIRETO 
	 cout << "ptrA depois: " << ptrA << endl;
     PAUSA;

	  ptrA = vetInteiras;                     // Restaurar o ponteiro que foi modificado
	 for (i = 0; i < 100;)
	 {
		 for (j = 0; j < 5; j++, i++)
		 {
			 if (i == 100)                    // Listou tudo?
				 break;
			 cout << *ptrA ++ << "\t";       // Aritmeticas de Ponteiros
		 }
		 cout << endl;
	 }


	 // UTILIZAR PONTEIRO  ARITMÉTICO
	 cout << "ptrA depois: " << ptrA << endl;
	 PAUSA;
	 ptrA = vetInteiras;                      // Restaurar o ponteiro que foi modificado
	 for (i = 0; i < 100;)
	 {
		 for (j = 0; j < 5; j++, i++)
		 {
			 if (i == 100)                    // Listou tudo?
				 break;
			 cout << *(ptrA + i) << "\t";     // Aritmeticas de Ponteiros
		 }
		 cout << endl;
	 }

	 cout << "ptrA depois: " << ptrA << endl;
	 PAUSA;


	 //utilizar o ponteiro como se fosse vetor
	 ptrA = vetInteiras;                       // Restaurar o ponteiro que foi modificado
	 for (i = 0; i < 100;)
	 {
		 for (j = 0; j < 5; j++, i++)
		 {
			 if (i == 100)                    // Listou tudo?
				 break;
			 cout << ptrA[i] << "\t";       // Lista como se fosse vetor.
		 }
		 cout << endl;
	 }


	 cout << "ptrA depois: " << ptrA <<"Ultima inteira: "<< *(ptrA +99)<< endl;
	 ptrA += 10;                                    // soma para o indice 10
	 cout << "*ptrA = " << *ptrA << endl;
	 PAUSA;
	 ListaVetor(vetInteiras, 100, "Listagem na Função");

	 ListaVetor(&vetInteiras[49], 50, "Listagem apartir do Indice 50");

	 ListaVetorInversamente(vetInteiras, 100, "Lista o vetor inversamente");

	 ListaVetorInversamentePonteiroDireto(vetInteiras, 100, "Lista o vetor inversamente Ponteiro Direto");


}// MAIN


// Função que lista o vetor de inteiras
// Parametros:
//    Entrada: int *ptrVet - Ponteiro para o vetor 
//             int nQtde - quantidade de inteiras para o Vetor
//             char *ptrCabec - ponteiro para um cabeçalho
void ListaVetor(int *ptrVet, int nQtde, char *ptrCabec)
{
	int i, j;
	LIMPAR_TELA;

	cout << "\n\t" << ptrCabec << endl;
	for (i = 0; i < nQtde;)
	{
		for (j = 0; j < 8; j++, i++)
		{
			if (i == nQtde)
				break;
			cout << *(ptrVet + i) << "\t";
		}
		cout << endl;

	}

	PAUSA;
}

// Função que lista o vetor de inteiras
// Parametros:
//    Entrada: int *ptrVet - Ponteiro para o vetor 
//             int nQtde - quantidade de inteiras para o Vetor
//             char *ptrCabec - ponteiro para um cabeçalho
void ListaVetorInversamente(int *ptrVet, int nQtde, char *ptrCabec)
{
	int i, j;
	LIMPAR_TELA;

	cout << "\n\t" << ptrCabec << endl;
	for (i = nQtde - 1; i >= 0;)
	{
		for (j = 0; j < 8; j++, i--)
		{
			if (i == -1)
				break;
			cout << *(ptrVet + i) << "\t";
		}
		cout << endl;

	}

	PAUSA;
}

// Função que lista o vetor de inteiras
// Parametros:
//    Entrada: int *ptrVet - Ponteiro para o vetor 
//             int nQtde - quantidade de inteiras para o Vetor
//             char *ptrCabec - ponteiro para um cabeçalho
void ListaVetorInversamentePonteiroDireto(int *ptrVet, int nQtde, char *ptrCabec)
{
	int i, j,
		*ptrAuxiliar = ptrVet + 99;

	LIMPAR_TELA;

	cout << "\n\t" << ptrCabec << endl;

	for (i = 0; i < nQtde;)
	{
		for (j = 0; j < 8; j++, i++)
		{
			if (i == 100)
				break;
			cout << *ptrAuxiliar-- << "\t";      // Lista ponteiro direto
		}
		cout << endl;

	}

	PAUSA;
}

