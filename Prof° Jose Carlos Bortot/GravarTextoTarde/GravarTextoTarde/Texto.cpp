// Programa que grava e le um arquivo texto
// FATEC-MC - JCB - 28/10/2015 - Vers�o 0.0
#include "Meu.h"
//
// entry point do programa
//
void main(void)
{
	int iBufferLeitura, iBuffer,					// indices para de contagem dos buffer
		nQtdeLido;									// indicar quantos bytes foram lidos
	char cWork[1024],								// string de trabalho
		cLinha[132];								// para montar a linha a ser escrita
	FILE *fdTexto;									// file descriptor do arquivo
	
	//---------------------------------------------------------[ESCRITA]----------------------------------------------------------->
	if (fopen_s(&fdTexto, CAMINHO_ARQUIVO, "wb") != 0)	// Abre escrita Bin�ria, se retorno for diferente de 0 entao � ->[ERRO]
	{
		if (&fdTexto == NULL)
		{
			printf("Problemas na CRIACAO do arquivo\n");
			return;
		}
		cout << "Erro de abertura!" << endl;
		PAUSA;											// PAUSA o terminal, evitando a finaliza��o
		return;											// Finaliza MAIN()
	}

    //-------------------------------------------------------------------------------------------------------------------->
	while (true)										// LOOP infinito de Grava��o. se digitar "***" finaliza LOOP
	{
	
		
		cout << "Digite um Primeiro texto ou *** para encerrar" << endl;

		//-------------------------------------------------------------------------------------------------------------------->
		// getLine e utlizado para que nao seja ignorado os espa�os em branco
		// vet [14] = "Rafael Almeida" [Com getLine]
		// vet [14] = "RafaelALmeida"  [Sem getLine]
		 cin.getline(cWork, sizeof(cWork), '\n');                //Pega a linha e Armazena em cWork
		
		  

		//-------------------------------------------------------------------------------------------------------------------->
		// Exemplo: [strcmp]
		//
		// strcmp("aa","bb") =  1
		// strcmp("aa","aa") =  0
		// strcmp("bb","aa") = -1
		if (strcmp(cWork, "***") == 0) // Faz compara��o com o texto digitado e "***", se o retorno for 0-> FINALIZA LOOP
		{   
			// Strcpy serve para copiar um texto e colar no destino informado 
			// strcpy(Destino, Texto);
			strcpy_s(cWork, "Fim da Gravacao\r\n");		// Copia Texto constante para cWork
			
			// fwrite serve para transferir o texto para 1 ou mais linhas no arquivo texto.
			// fwrite(VariavelTexto, quantidadeDeCaracteres, quantidadeItensOuLinhas, Arquivo)
			fwrite(cWork, strlen(cWork), 1, fdTexto);	// Inseri cWork de finaliza��o de escrita no txt
			fclose(fdTexto);							// Encerra fdTexto[Arquivo.txt] da mem�ria 
			break;										// Finaliza LOOP
		}

		//-------------------------------------------------------------------------------------------------------------------->
		//S� passar� por aqui SENAO for DIGITADO os caracteres de FINALIZA��O -> "***"
		// Exemplo: [Strcat_s]
		//
		// strcat_s serve para Concatenar dos textos.
		// strcat_s (VariavelDeTexto1, Texto2 )
		// VariavelDeTexto1 += Texto2;
		strcat_s(cWork, "\r\n");         // Concatena Carriage Return e Line Feed ("\r" desce a linha , "\n" pula uma linha)
		
		//-------------------------------------------------------------------------------------------------------------------->
		
			//Inseri o valor no ARQUIVO Texto
			if (fwrite(cWork, strlen(cWork), 1, fdTexto) == 0) // erro de grava��o?
			{
				fclose(fdTexto);						// fechar o arquivo
				cout << "Erro de grava��o!" << endl;
				PAUSA;
				return;									// volta ao sistema operacional
			}

	} // while


	//fazer a leitura do arquivo em Bin�rio
	//---------------------------------------------------------[LEITURA]----------------------------------------------------------->	
	// 
	if (fopen_s(&fdTexto, CAMINHO_ARQUIVO, "rb") != 0)	// Abre fdTexto como Leitura Bin�ria, se retorno for igual 0->[ERRO]
	{
		cout << "Erro de abertura do arquivo!" << endl;
		PAUSA;
		return;                                          // volta ao sistema operacional
	}

	iBufferLeitura = 0;											// inicializa o iBufferLeitura

	
	//-------------------------------------------------------------------------------------------------------------------->
	while (true)									
	{	
		//-------------------------------------------------------------------------------------------------------------------->
		// fread_s serve para ler o arquivo texto, retornando a quantidade de caracteres lidos
		// Exemplo: [fread_s]
		// 
		// fread_s(buffer, bufferSize, elementSize, count, stream);
		// fread_s(O local de armazenamento para os dados, 
		//         Tamanho do buffer de destino em bytes, 
		//         Tamanho do item a ser lido em bytes, 
		//		   O n�mero m�ximo de itens a serem lidos,
		//         Ponteiro para ARQUIVO estrutura);

		// [nQtdeLido] ir� receber a quantidade de caracter ou elementos do cWork 
		nQtdeLido = fread_s(cWork, 1024, 1, 1024, fdTexto);		    // ler 1024 bytes ou menos
		
		  
		for (iBuffer = 0; iBuffer < nQtdeLido;)						// loop de todos os bytes
		{	
			//-------------------------------------------------------------------------------------------------------------------->
			//LOOP que vai montando a linha caracter por caracter passando do cWork= "CONTEUDO do INTEIROR do ARQUIVO" para cLinha = "Linha inserida"
			for (;; iBufferLeitura++, iBuffer++)					// montagem da linha
			{	

				//-------------------------------------------------------------------------------------------------------------------->
				if (iBuffer == nQtdeLido)							// chegou ao fim do buffer?
					break;

				//-------------------------------------------------------------------------------------------------------------------->
				cLinha[iBufferLeitura] = cWork[iBuffer];			// Move caracter por caracter (byte a Byte)  '\n'= 1 byte 'e'=1 byte 
				
				//-------------------------------------------------------------------------------------------------------------------->
				if (cLinha[iBufferLeitura] == '\n')					// Verifica se o caracter transmitido de cWork para cLinha � igual a '\n' 
				{	// fim da linha ?					
				
					cLinha[iBufferLeitura + 1] = NULL;		// completa o texto
					cout << cLinha;							// lista linha montada
					iBufferLeitura = -1;					// inicializa para pr�xima linha
					continue;
				}
			} // for j
		} // for i 
		
		//-------------------------------------------------------------------------------------------------------------------->
		if (nQtdeLido != 1024)						// foi o �ltiimo bloco?
		{
			PAUSA;
		//	fclose(fdTexto);
			break;									// sai do while
		}
	} // while


	//--------------------------------------------------------[Leitura em Texto]------------------------------------------------------>
	
	// Vai carregar valor de confirma��o da leitura.
	char *iResultado;

	// Abri em leitura bin�ria
	 if (fopen_s(&fdTexto, CAMINHO_ARQUIVO, "rb") != 0)  // Se houve erro na abertura
	{
		printf("Problemas na abertura do arquivo\n");
		return;
	}
	iBuffer = 1;
	
	//--------------------------------------------------------------------------------------->
	// Exemplo: [feof]
	//
	//  feof(Arquivo);
	//  retorna 0 - quando o arquivo chegou ao seu fim;
	//  retorna != 0 - quando n�o � o fim da leitura.
	while (!feof(fdTexto))						         // enquanto nao for 0 ou nao chegar no fim do arquivo.
	{
		// L� uma linha (inclusive com o '\n')
		iResultado = fgets(cWork, 100, fdTexto);      // fgets' l� at� 99 caracteres ou at� o '\n'

		if (iResultado)                               // Se foi poss�vel ler ou 
			printf("Linha %d : %s", iBuffer, cWork);
		
		iBuffer++;
	}
	fclose(fdTexto);
	PAUSA;




}