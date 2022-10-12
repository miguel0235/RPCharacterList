

#include "Tokenizer.h"
#include "Characters.h"
#include <iostream>  
#include <string>
using namespace std;

using std::ifstream;
#include <fstream>
using std::cin;
using std::cout;
using std::endl;

// please note that the following function will normally
// have a function prototype more like
// bool processText(istream& is, <type> &b, bool interactive = true)
// where <type> is the type of the data structure we are working with
bool processText(istream& is, bool interactive = true)
{
	// implement support for 
	// exit ... exit the program
	// add string string ... concatenate two strings
	// add double double ... sum two integers
	// load file ... loads a file containing supported commands
	string line;
	string command;
	string arg1, arg2;
	double darg1, darg2;
	int iarg1;

	Tokenizer tkn;
	
	//Create the LinkList Class 
	characters ch;

	while (true)
	{
		if (!interactive)
		{
			if (is.eof()) return true;
		}
		else { cout << ">> "; }

		getline(is, line);
		tkn.setString(line);

		tkn.readWord(command);
		if (command == "exit")
		{
			cout << "Exiting ...." << endl;
			return false;
		}
		if (command == "load")
		{
			// load expects a filename .. so read one more word
			if (!tkn.readWord(arg1)) {
				cout << "Missing file name" << endl;
				continue; // skip back to the top of the read loop
			}
			ifstream fin;
			bool status = true;
			fin.open(arg1);
			if (fin.is_open())
			{
				// keeping in mind the note about the definition for the processText fuction
																	// the following line of code is closer to
				// status = processText(fin, b, false);
				status = processText(fin, false);
			}
			else { cout << "Failed to open the file" << endl; }
			fin.close();
			if (!status) return false;
		}
		if (command == "add")
		{
			//takes in the name for new character
			tkn.readWord(command);

			//adds new character with default stats
			ch.add(command);

		}
		if (command == "set")
		{
			//takes in the character name
			tkn.readWord(command);

			//saves character name for whan set function is called
			string name = command;

			//takes in stat to be changed
			tkn.readWord(command);

			//saves what stat needs to be changed
			string stat = command;

			//calls functoin for changing race, job, or level
			if (command == "race" || command == "job")
			{
				cout << "*****************Setting Race/Job************" << endl;

				//takes in value for stat to be changed to
				tkn.readWord(command);

				//display if item was changed or not
				if (ch.setWords(name, stat, command))
				{
					cout << "Successfully changed " << stat << " for " << name << endl;
				}
				else
				{
					cout << "error Changing stat" << endl;
				}
				cout << "*********************************************" << endl;
			}
			else if (command == "level")
			{
				cout << "*****************Setting Level***************" << endl;

				//takes in value for stat to be changed to
				tkn.readInteger(iarg1);

				//display if item was changed or not
				if (ch.setLevel(name, stat, iarg1))
				{
					cout << "Successfully changed " << stat << " for " << name << endl;
				}
				else
				{
					cout << "error Changing stat" << endl;
				}
				cout << "*********************************************" << endl;
			}
		}
		if (command == "search")
		{
			//takes in item to be searched
			tkn.readWord(command);

			//Checks name and executes the correlating functions for that command
			if (command == "name")
			{
				cout << "************Searching Name*******************" << endl;

				//reads the name to be searched for
				tkn.readWord(command);

				//searches for that name
				ch.searchName(command);

				cout << "*********************************************" << endl;
			}
			else if (command == "level")
			{
				cout << "************Searching Level******************" << endl;

				//reads in level to be searched for
				tkn.readInteger(iarg1);
				
				//searches for the level
				ch.searchLevel(iarg1);

				cout << "*********************************************" << endl;
			}
			else if (command == "race")
			{
				cout << "************Searching Race*******************" << endl;

				//reads in the race to be searched for
				tkn.readWord(command);

				//search for the race
				ch.searchRace(command);

				cout << "*********************************************" << endl;
			}
			else if (command == "job")
			{
				cout << "************Searching Job********************" << endl;

				//reads in the job to be searched
				tkn.readWord(command);

				//search for the job
				ch.searchJob(command);
				cout << "*********************************************" << endl;
			}
			else
			{
				cout << "*********************************************" << endl;
				cout << "           Stat command error" << endl;
				cout << "*********************************************" << endl;
			}
		}
		if (command == "display")
		{
			cout << "****************Display**********************" << endl;

			//displays all characters
			//doesn't specify if list needs to be sorted
			ch.display(cout);

			cout << "*********************************************" << endl;
		}
		if (command == "remove")
		{
			cout << "*****************Remove**********************" << endl;

			//reads in character name to be removed
			tkn.readWord(command);

			//removes character and tells if it was deleted
			if (ch.remove(command))
			{
				cout << command << " Character removed!" << endl;
			}
			else
			{
				cout << "Character not removed!" << endl;
			}
			cout << "*********************************************" << endl;
		}
	}
}


int main()
{
	// little menu for commands 
	cout << "*****************Stats***********************" << endl;
	cout << "level                race                 job" << endl;
	cout << "*********************************************" << endl;
	cout << "            Commands " << endl;
	cout << "*********************************************" << endl;
	cout << "exit" << endl;
	cout << "load <file>" << endl;
	cout << "set <name> <stat> <value>" << endl;
	cout << "search <stat> <value>" << endl;
	cout << "remove <name>" << endl;
	cout << "display" << endl; 
	cout << "*********************************************" << endl;

	processText(cin);
	return 0;

}