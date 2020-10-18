#pragma once
#include <vector>

using namespace std;

class HashSondagemDupla
{
private:
	int numeroDeColisoes;
	int tableSize;
	int m1;
	int m2;
public:
	HashSondagemDupla(int m1);
	int HashFunction(int key, int i);
	int HashFunction1(int key);
	int HashFunction2(int key);
	vector<int>* hashTable;
	bool Insert(int key, int data);
	int Lookup(int key, int data);
	void Destroy(int m);
	int GetNumeroDeColisoes();
	void PrintHashTable();
};

