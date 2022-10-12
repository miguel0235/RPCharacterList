#pragma once
#include "node.h"
#include <iostream>  
#include <iomanip>
using namespace std;

//LinkList Functions

class characters :
    public Node
{
private:
    Node* head;
    Node* tail;
public:

    //constructor and deconstructor
    characters(): head(nullptr), tail(nullptr) {}
    ~characters();

    //add character to end of linklist
    void add(string name);

    //set Functions
    //Set Words is for changing Race or Job
    bool setWords(string name, string stat, string value);
    //Set the Level 
    bool setLevel(string name, string stat, int value);

    //search Functions
    void searchName(string Name);
    void searchLevel(int level);
    void searchRace(string race);
    void searchJob(string job);


    //remove character
    //Bug- after removing character and then running display it crashes program
    bool remove(string name);

    //displays all characters
    void display(ostream& os);

    friend ostream& operator<<(ostream& os, characters& right);
};

