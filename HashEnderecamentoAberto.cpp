#include <iostream>
#include <fstream>
#include "HashSondagemLinear.h"
#include "HashSondagemDupla.h"

using namespace std;

int main()
{
	ifstream entrada;
	entrada.open("entrada.txt");
	int tableSize;
	entrada >> tableSize;

	cout << "Sondagem Linear: " << endl;
	HashSondagemLinear* hashLinear = new HashSondagemLinear(11);
	hashLinear->Insert(10,10);
	hashLinear->Insert(22,22);
	hashLinear->Insert(31,31);
	hashLinear->Insert(4,4);
	hashLinear->Insert(15,15);
	hashLinear->Insert(28,28);
	hashLinear->Insert(59,59);
	hashLinear->PrintHashTable();
	cout << "Numero de colisoes: " << hashLinear->GetNumeroDeColisoes() << "\n" << endl;
 
	cout << "Sondagem Duplo: " << endl;
	HashSondagemDupla* hashDuplo= new HashSondagemDupla(7);
	hashDuplo->Insert(74, 74);
	hashDuplo->Insert(92, 92);
	hashDuplo->Insert(32, 32);
	hashDuplo->Insert(70, 70);
	hashDuplo->Insert(47, 47);
	hashDuplo->PrintHashTable();
	cout << "Numero de colisoes: " << hashDuplo->GetNumeroDeColisoes() << endl;

}