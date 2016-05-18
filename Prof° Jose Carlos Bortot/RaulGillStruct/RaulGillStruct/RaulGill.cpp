//Programa RAUL GIL com struct e menu do operador
// FATEC  - MOGI DAS CRUZES 
// Modificação: 30/03/2016
// Autor: RAFAEL ALMEIDA DA SILVA


#include "RaulGill.h"
//
// Entry point do programa
//
void main(void)
{
	 
	int nQteCalouro,                                             // quantidade de calouros
		nNotaTrono = -1,										// nota do trono
		iIndiceVencedor = 0,									// indice do calouro vencendor
		iIndProximo = 0;										// indice do próximo

	CALOURO stCalouro,											//struct para conter os dados de um calouro
		vetCalouros[QTDE_MAX_CALOUROS];							//vetor de calouros
	 
	char cOpcao,												// opção de Escolha do Operador
		cWork[200];												// para sprintf_s

	SYSTEMTIME stTime;											//struct para obter a data e hora do sistema

//--------------------------------------------[VARIAVEIS DE INICIALIZAÇÂO]---------------------------------------->	
	
	setlocale(LC_ALL, "portuguese_brazil");

	// LOOP para pedir a quantidade de calouros

	do 
	{  
		cout << "Quantidade de calouros entre " << QTDE_MIN_CALOUROS << " e "
			<< QTDE_MAX_CALOUROS << endl
			<< "Ou zero para cancelar a execução do programa: ";
		 cin >> nQteCalouro;
		
		 if (nQteCalouro == 0)
			 return;
	} while (nQteCalouro < QTDE_MIN_CALOUROS || nQteCalouro > QTDE_MAX_CALOUROS);
	
	// LOOP infinito do programa
	while (true)
	{
		CLS;

		//-----------------------------[ CABEÇALHO ]----------------------->
		GetLocalTime(&stTime);                            //data e hora do sistema
		sprintf_s(cWork, sizeof(cWork), "Programa de calouros Raul Gil em %02d/%02d/%04d às %02d:%02d:%02d",
			stTime.wDay, stTime.wMonth , stTime.wYear,
			stTime.wHour, stTime.wMinute, stTime.wSecond );

		cout << "\n\t" << cWork << endl<< endl;                   //exibe o cabeçalho do programa

		//-----------------------------[ MENU ]----------------------->
		cout << INCLUIR_CALOURO << "- Incluir calouro;" << endl;
		cout << EXIBIR_VENCEDOR << "- Vencedor até o momento;" << endl;
		cout << LISTAR_CALOUROS << "- Listar os calouros que cantaram;" << endl;
		cout << SAIR_DO_PROGRAMA << "- SAIR do programa." << endl;
		cout << "\tSelecione: ";

		cin >> cOpcao;                                   
		cOpcao = toupper(cOpcao);                          //Converte o char de opcao para Maiusculo
	    
		//-----------------------------[ SELEÇÃO DO MENU ]----------------------->
		switch (cOpcao)
		{
			case INCLUIR_CALOURO:
				
				CLS;

				// Testar se todos os calouros já cantaram
				if (iIndProximo == nQteCalouro)
				{
					cout << "Todos os " << nQteCalouro << " já cantaram" << endl;
					PAUSE;
					break;
				}
				cin.ignore(1, EOF);  // ignorar a tecla Enter em um campo
				cout << "Nome do calouro: ";
				cin.getline(stCalouro.cNome, EXTENSAO_NOME + 1, '\n');

				//pedir um sexo válido
				do{

					cout << "Sexo (" << MASCULINO << "- Masculino ou )" << FEMININO << "- Feminino): ";
					cin >> stCalouro.cSexo;
					stCalouro.cSexo = toupper(stCalouro.cSexo);

				} while (stCalouro.cSexo != MASCULINO && stCalouro.cSexo != FEMININO);
				
				//pedir nota válida
				do{
					cout << "Nota entre " << NOTA_MIN << " e " << NOTA_MAX << ": ";
					cin >> stCalouro.nNota;

				} while (stCalouro.nNota < NOTA_MIN || stCalouro.nNota > NOTA_MAX);

				//vamos incluir este calouro no vetor e calouros
				iIndProximo = IncluirCalouro(&stCalouro, vetCalouros, &iIndProximo, &nNotaTrono, &iIndiceVencedor);
				break;                                         
			case EXIBIR_VENCEDOR:
				CLS;
				ExibirVencedor(vetCalouros,iIndiceVencedor);
				break;                                         
			case LISTAR_CALOUROS:
				CLS;
				ListarCalouros(vetCalouros, iIndProximo,&stTime);
				break;                                         
			case SAIR_DO_PROGRAMA:

				cout << "Sair realmente? (S ou N): ";
				cin >> cOpcao;

				if (cOpcao == 's' || cOpcao == 'S')
					return;                                // Sai do programa.
			default:
				cout << "Opção inválida!" << endl;
				PAUSE;

		}
		

 	}

}