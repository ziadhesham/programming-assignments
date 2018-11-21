#include <iostream>
#include <string>
#include <conio.h>
#include <fstream>

using namespace std;

/////////////////////ahmed code////////////////




/////////////////////////hesham code///////////////////

/*the fn takes the input file name and save up to 2 strings in the 2 strings variables send to it*/
void FileInput(string FileName, string &frame, string &generator)
{
	string x;
	ifstream myfile;
	x=generator;
	myfile.open(FileName);
	if (myfile.is_open())
	{
		if (getline(myfile, frame));
		if (!getline(myfile, generator) )
			if(generator=="")
			generator=x;
		// ofstream("message_transmitted.txt") << frame << '\n'<<generator;
		myfile.close();
	}
}


/*the fn takes the output file name and the transmitted message to be printed in the file and the message to be printed in the console*/
void OutputFile(string output_file, string transmitted_message = "", string message = "")
{
	ofstream myfile;
	myfile.open(output_file);
	myfile << transmitted_message << '\n';
	myfile.close();
	cout << message << '\n';

}

/*this fn takes the text to be processed on and the number number of the bit to be toggled with counting of bits starts by 1*/
void Alter(string message, int bit_number/*start counting from one*/,string generatorFunction)
{
	FileInput("transmitted_message.txt", message, generatorFunction);
	if (bit_number>0)
	{
		bit_number--;
		if (message[bit_number] == '0')
		{
			message[bit_number] = '1';
		}
		else
		{
			message[bit_number] = '0';
		}
	}
	else cout << "invalid bit number" << '\n';
	OutputFile("alter_output.txt", message);
}


void Generator(string &message, string &generatorFunction)
{
	FileInput("message_generator.txt", message, generatorFunction);
	OutputFile("transmitted_message.txt", sent_msg(message, generatorFunction));
}




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
