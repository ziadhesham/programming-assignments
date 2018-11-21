#include <iostream>
#include <string>
#include <conio.h>
#include <fstream>

using namespace std;

/////////////////////ahmed code////////////////




/////////////////////////hesham code///////////////////




/////////////////////////gamal code///////////////////
void verifier(string FileName,string &message, string &generatorFunction)
{
	FileInput(FileName, message, generatorFunction);
	if (VERIFIER(message, generatorFunction))
	{
	cout << "Message is correct!" << endl<<endl;
	}
	else
	{
		cout<<"Message is incorrect!"<<endl<<endl;
	}
}


int main()
{
	char x;
	char choice='y';
	int v;
	string command;
	string message;
	string generatorFunction;
	int alterflag=0;
	cout<<"Put message and generator in message_generator.txt file then"<<endl<<"Press any key to continue..."<<endl;
	//cin >>x;
	getch();
	Generator(message, generatorFunction);
	cout<<"Output is displayed in \"transmitted_message.txt\" file"<<endl<<endl;
	while (choice=='y'||choice=='Y'){
	cout <<"Press \"1\" to activate verifier"<<endl<<"Press \"2\" to activate alter..."<<endl;
	cin>>command;
	if (command== "1")
	{
		cout<<"Press \"1\" to verify generator output"<<endl<<"Press \"2\" if you want to verify alter output"<<endl;
		cin >>v;
		if(v==1)
		{
			verifier("transmitted_message.txt",message,generatorFunction);
		}
		else if (v==2)
		{
			if (alterflag==0)
			{
				cout<<"please run alter first"<<endl;
			}
			else
			{
				verifier("alter_output.txt",message,generatorFunction);
			}
		}
		else
		{
			cout<<"This is not a choice please try again"<<endl<<endl;
		}
		
	}
	else if (command=="2")
	{
		alterflag=1;
		cout<<"Please enter bit number to change in transmitted message"<<endl;
		cin>>v;
		Alter( message, v,generatorFunction);
		cout<<"Output is displayed in \"alter_output.txt\" file"<<endl<<endl;
	}
	else
	{
		cout<<"This is not a choice please try again"<<endl<<endl;
	}
	cout<<"Do you want to try again? (Y/N)";
	cin>>choice;
	}

	return 0;
}
