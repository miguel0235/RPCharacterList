#pragma once
#include <string>
using namespace std;

class Node
{
public:
	int level;
	string name, race, job;


	Node* next;
	Node* prev;
	Node(): level(0), next(nullptr), prev(nullptr) {}
	Node(string name): name(name), level(1), race("pc"), job("villager"), next(nullptr), prev(nullptr) {}
	Node(string name, Node *next, Node *prev): name(name), level(1), race("pc"), job("villager"), next(next), prev(prev) {}
};

