#include <iostream>
#include "HashSondagemDupla.h"

using namespace std;

/// <summary>
/// m1 deve ser primo e m2 deve ser ligeiramente menor que m1
/// </summary>
/// <param name="m1"></param>
/// <param name="m2"></param>
HashSondagemDupla::HashSondagemDupla(int m1)
{
	this->tableSize = m1;
	this->m1 = m1;
	this->m2 = m1-1;
	this->hashTable = new vector<int>(tableSize);
	this->numeroDeColisoes = 0;
}

int HashSondagemDupla::HashFunction(int key, int i)
{
	return (HashFunction1(key) + i * HashFunction2(key)) % this->m1;
}

int HashSondagemDupla::HashFunction1(int key)
{
	return key % this->m1;
}

int HashSondagemDupla::HashFunction2(int key)
{
	return 1 + (key % this->m2);
}

int HashSondagemDupla::GetNumeroDeColisoes()
{
	return this->numeroDeColisoes;
}

void HashSondagemDupla::PrintHashTable()
{
	for (int i = 0; i < this->tableSize; i++)
	{
		cout << i << ": " << this->hashTable->at(i) << endl;
	}
}

/// <summary>
/// Retorna true se conseguiu inserir e false se não.
/// </summary>
/// <param name="key"></param>
/// <param name="data"></param>
/// <returns></returns>
bool HashSondagemDupla::Insert(int key, int data)

{
	int i = 0;	//numero de tentativas de inserção
	int hash = HashFunction(key, i);
	int val = hashTable->at(hash);
	while (val != 0 && i < this->tableSize - 1)
	{
		this->numeroDeColisoes++;
		i++;
		hash = HashFunction(key, i);
		val = hashTable->at(hash);
	}

	if (val != 0)
		return false; // não conseguiu a inserção pq faltou espaço

	this->hashTable->at(hash) = data;
	return true;
}


/// <summary>
/// Procura por um item na tabela. Retorna o índice (hash) dele se achar, retorna -1 se não.
/// </summary>
/// <param name="key"></param>
/// <param name="data"></param>
/// <returns></returns>
int HashSondagemDupla::Lookup(int key, int data)
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
		return -1; // não achou o elemento
	else
	{
		return hash;
	}
}
