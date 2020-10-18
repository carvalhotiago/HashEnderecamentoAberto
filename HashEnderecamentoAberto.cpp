#include <iostream>
#include <sstream>
#include <fstream>
#include "HashSondagemLinear.h"
#include "HashSondagemDupla.h"

using namespace std;

int main()
{
	ifstream arquivo;

	string str;
	string tableSize;
	string quantidadeValores;
	string tipoHash;
	vector<int>* numbers = new vector<int>;
	arquivo.open("entrada.txt");

	if (arquivo.is_open())
	{
		getline(arquivo, tableSize, ' ');
		getline(arquivo, quantidadeValores, ' ');
		getline(arquivo, tipoHash);

		while (getline(arquivo, str))
		{
			stringstream ss(str);
			int x;
			ss >> x;
			numbers->push_back(x);
		}
	}

	stringstream ss(tableSize);
	int tamanhoTabelaInt;
	ss >> tamanhoTabelaInt;

	if (tipoHash == "1")
	{
		cout << "Sondagem Linear: " << endl;
		HashSondagemLinear* hashLinear = new HashSondagemLinear(tamanhoTabelaInt);
		for (int i = 0; i < numbers->size(); i++)
		{
			hashLinear->Insert(numbers->at(i), numbers->at(i));
		}
		//hashLinear->PrintHashTable();
		cout << "Numero de colisoes: " << hashLinear->GetNumeroDeColisoes() << "\n" << endl;
	}
	else if (tipoHash == "2")
	{
		cout << "Sondagem Duplo: " << endl;
		HashSondagemDupla* hashDuplo= new HashSondagemDupla(tamanhoTabelaInt);
		for (int i = 0; i < numbers->size(); i++)
		{
			hashDuplo->Insert(numbers->at(i), numbers->at(i));
		}
		//hashDuplo->PrintHashTable();
		cout << "Numero de colisoes: " << hashDuplo->GetNumeroDeColisoes() << endl;
	}
	else
	{
		cout << "Tipo de hash invalido!" << endl;
	}

 

}