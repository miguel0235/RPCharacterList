#include "characters.h"

//LinkList Functions


//destructor
characters::~characters()
{
	Node* tmp = head;

	while (tmp != nullptr)
	{
		head = head->next;
		delete tmp;

		tmp = head;	
	}

	tail = nullptr;
}


//adds the character to the end of program
void characters::add(string name)
{
	//created new node 
	Node *tmp = new Node(name);

	if (head == nullptr)
	{
		//sets new node to beginning 
		//No other items in list
		head = tmp;
	}
	else
	{
		//sets new node to tail
		tail->next = tmp;
	}
	tail = tmp;
}

bool characters::setWords(string name, string stat, string value)
{
	//starts at the head of LinkList
	Node* tmp = head;

	//loops through all names till item is found
	while (tmp != nullptr)
	{
		if (tmp->name == name)
		{
			//stops loop because we foudn the character we're looking for
			break;
		}
		tmp = tmp->next;
	}

	//If character wasn't found return false
	if (tmp == nullptr)
	{
		return false;
	}

	//changes race if character was found
	if (stat == "race")
	{
		tmp->race = value;
		return true;
	}
	//changes job if character was found
	if (stat == "job")
	{
		tmp->job = value;
		return true;
	}
	return false;
}

bool characters::setLevel(string name, string stat, int value)
{
	//starts at the head of LinkList
	Node* tmp = head;

	//loops through all names till item is found
	while (tmp != nullptr)
	{
		if (tmp->name == name)
		{
			//stops loop because we foudn the character we're looking for
			break;
		}
		tmp = tmp->next;
	}

	//If character wasn't found return
	if (tmp == nullptr)
	{
		return false;
	}

	//changes the level if character was found
	if (stat == "level")
	{
		tmp->level = value;
		return true;
	}
	return false;
}


void characters::searchName(string name)
{
	//starts at the head of LinkList
	Node* tmp = head;

	//loops through all names till item is found
	while (tmp != nullptr)
	{
		if (tmp->name == name)
		{
			cout << left << setw(14) << tmp->name << "  " << setw(8) << tmp->race << "  " << setw(8) 
				<< tmp->job << "   Level: " << tmp->level << endl;
		}
		tmp = tmp->next;
	}
}

void characters::searchLevel(int level)
{
	//starts at the head of LinkList
	Node* tmp = head;

	//loops through all levels till item is found
	while (tmp != nullptr)
	{
		if (tmp->level == level)
		{
			cout << left << setw(14) << tmp->name << "  " << setw(8) << tmp->race << "  " << setw(8) 
				<< tmp->job << "   Level: " << tmp->level << endl;
		}
		tmp = tmp->next;
	}
}

void characters::searchRace(string race)
{
	//starts at the head of LinkList
	Node* tmp = head;

	//loops through all races till item is found
	while (tmp != nullptr)
	{
		if (tmp->race == race)
		{
			cout << left << setw(14) << tmp->name << "  " << setw(8) << tmp->race << "  " << setw(8) 
				<< tmp->job << "   Level: " << tmp->level << endl;
		}
		tmp = tmp->next;
	}
}

void characters::searchJob(string job)
{
	//starts at the head of LinkList
	Node* tmp = head;

	//loops through all jobs till item is found
	while (tmp != nullptr)
	{
		if (tmp->job == job)
		{
			cout << left << setw(14) << tmp->name<< "  " << setw(8) << tmp->race << "  " << setw(8) 
				<< tmp->job << "   Level: " << tmp->level << endl;
		}
		tmp = tmp->next;
	}
}


bool characters::remove(string name)
{
	//starts at the head of LinkList
	Node* tmp = head;

	//loops through all names till item is found
	while (tmp != nullptr)
	{
		//Compares names till item is found
		if (tmp->name == name)
		{
			if (tmp->prev != nullptr)
			{
				tmp->prev->next = tmp->next;

			}
			if (tmp->next != nullptr)
			{
				tmp->next->prev = tmp->prev;
			}
			if (tmp == head)
			{
				head = tmp->next;
			}
			if (tmp == tail)
			{
				tail = tmp->prev;
			}
			delete tmp;

			return true;
		}
		tmp = tmp->next;
	}
	return false;
}

void characters::display(ostream& os)
{
	//starts at the head of LinkList
	Node* tmp = head;

	//loops through all items
	while (tmp != nullptr)
	{
		os << left << setw(14) << tmp->name<< "  " << setw(8) << tmp->race << "  " << setw(8) << tmp->job << "   Level: " << tmp->level << endl;

		tmp = tmp->next;
	}
}

ostream& operator<<(ostream& os, characters& right)
{
	right.display(os);

	return os;
}
