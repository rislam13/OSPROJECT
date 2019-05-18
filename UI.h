//Reham Islam

#ifndef UI_H
#define UI_H

#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include "FileSystem.h"
#include "directory.h"

using namespace std;

class UI {
    public:

    UI()// default constructor
    {	
    } 

    void input()
    {	string commandLine;
	string first, name;

	while (first != "EXIT")
	{	cout << "$$ ";
		getline(cin,commandLine,'\n');
		first = commandLine.substr(0, commandLine.find(" "));
		name = commandLine.substr(commandLine.find_first_of(" \t")+1);


		if(first == "CREATE")
		{	f.Create(name); 
			//d.add(name);
		}else if(first == "DELETE")
		{	if(f.fileExist(name)!= -1)
				f.Delete(name);
			else
				cout << "File doesnt exsist" << endl;
		}
		else if(first == "EDIT")
		{	if(f.fileExist(name)!= -1)
			{	string v = "";
				while (v.length()< f.getBSize())
				{	string Input;
					getline(cin, Input);

					v = v + "\n" + Input;
				}

				cin.clear();
				int x = f.Open(name,O_RDWR);

				//cout << "x" <<x << endl;
				
				
			} 
		}else if(first =="DIR")
		{	cout << "\tATOS-FS Directory Listing\n"; 
			cout << "\tFILENAME\t\tSIZE\n";
			f.display();
		}else if (first == "TYPE")
		{	
			if(f.fileExist(name)!= -1)	
			{	f.displayFCB(name);			
			}else
				cout << "File doesnt exists"<< endl;	
		}
	}
     }
private:
	FileSystem f;
};

#endif
