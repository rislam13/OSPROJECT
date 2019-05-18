//Name:Reham Islam
//This is directory class

#ifndef DIRECTORYCPP
#define DIRECTORYCPP


#include<fstream>
#include<iomanip>
#include <vector>
 
#include "FileControlBlock.cpp"
 
 
class directory
{
private:
	string name;
	//std::vector<FileControlBlock> FCB;
	int numofFiles;
public:
	std::vector<FileControlBlock> FCB;

	directory() { name = " "; numofFiles = 0; }
	directory(string names){ name = names; }
	bool fileExists(string fn);
	int fileExist(string fn);
	bool add(string fn);
	string file() { string s = name; return(s); };
	bool deleteD(string);
	FileControlBlock& getFile ( string x)
	{	FileControlBlock a(x);
		for(int i =0; i < FCB.size(); i++)
			if(FCB[i] == x )
			{	return FCB[i];
			}
	}
	void display();
	void reset(string filename)
	{	int index = fileExist(filename);
		FCB[index].setStartBlock(-1);
		FCB[index].setEndBlock(-1);
	}
	int  getSize(){ return FCB.size(); }


};
 
 
 
int directory::fileExist(string fn)
{	for (int i = 0; i<FCB.size();i++)
	{
 		if(FCB[i].getFileName() == fn)
    		{	return i;
      		}
	}

	return -1;

}

bool directory::fileExists(string fn)
{	if(fileExist( fn) == -1)
		return false;
	else 
		return true;
}


bool directory::add(string fn)
{	if(fileExists(fn)==false) //to avoid repitations
    	{	
        	FCB.push_back(fn);
        	cout<<fn<< " added"<<endl;
		return true;
    	}
    	else
        {	cout<<"File exists!"<<endl;
		return false;
	}
}
 
 
 
bool directory::deleteD(string fn)
{	FileControlBlock c(fn);
	if(fileExist(fn)!=-1)
	{	int it = fileExist(fn);
		FCB.erase(FCB.begin()+it);
		cout<<fn<<" erased"<<endl;
		return true;
	}else
	{	cout<<fn<<" does not exist, can't be erased!"<<endl;
		return false;
	}

}



void directory::display() //just shows all the contents of the directory
{
    for(int i=0; i< FCB.size(); i++)
        cout << "\t"<< FCB[i].getFileName() << "\t\t\t" << FCB[i].getSize() << endl;

}


#endif
