#include <iostream>
#include "HashSondagemLinear.h"

using namespace std;

HashSondagemLinear::HashSondagemLinear(int m)
{
	this->tableSize = m;
	this->hashTable = new vector<int>(tableSize);
	this->numeroDeColisoes = 0;
}

int HashSondagemLinear::HashFunction(int key, int i)
{
	return (key+i) % this->tableSize;
}

int HashSondagemLinear::GetNumeroDeColisoes()
{
	return this->numeroDeColisoes;
}

void HashSondagemLinear::PrintHashTable()
{
	for (int i = 0; i < this->tableSize; i++)
	{
		cout << i << ": " << this->hashTable->at(i) << endl;
	}
}

/// <summary>
/// Retorna true se conseguiu inserir e false se n�o.
/// </summary>
/// <param name="key"></param>
/// <param name="data"></param>
/// <returns></returns>
bool HashSondagemLinear::Insert(int key, int data)

{
	int i = 0;	//numero de tentativas de inser��o
	int hash = HashFunction(key, i);
	int val = hashTable->at(hash);
	while (val != 0 && i < this->tableSize-1)
	{
		this->numeroDeColisoes++;
		i++;
		hash = HashFunction(key, i);
		val = hashTable->at(hash);
	}

	if (val != 0)
		return false; // n�o conseguiu a inser��o pq faltou espa�o

	//auto pos = this->hashTable->begin() + hash;
	this->hashTable->at(hash) = data;
	return true;
}


/// <summary>
/// Procura por um item na tabela. Retorna o �ndice (hash) dele se achar, retorna -1 se n�o.
/// </summary>
/// <param name="key"></param>
/// <param name="data"></param>
/// <returns></returns>
int HashSondagemLinear::Lookup(int key, int data)
{
	int i = 0;	//numero de tentativas de busca
	int hash = HashFunction(key, i);
	int val = hashTable->at(hash);
	while (val != data && i < this->tableSize)
	{
		i++;
		hash = HashFunction(key, i);
		int val = hashTable->at(hash);
	}

	if (val != data)
		return -1; // n�o achou o elemento
	else
	{
		return hash;
	}
}
