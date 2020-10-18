#pragma once
#include <vector>

using namespace std;

class HashSondagemLinear
{
private:
	int numeroDeColisoes;
	int tableSize;

public:
	HashSondagemLinear(int m);
	int HashFunction(int key, int i);
	vector<int>* hashTable;
	bool Insert(int key, int data);
	int Lookup(int key, int data);
	void Destroy(int m);
	int GetNumeroDeColisoes();
	void PrintHashTable();
};

