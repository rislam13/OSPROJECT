//Reham Islam


#ifndef FILESYSTEM
#define FILESYSTEM
//#define D_SIZE 10
//#define B_SIZE 10
#include <unistd.h>
#include "FileControlBlock.h"
#include "directory.h"
#include "diskprocess.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <vector>

class FileSystem{
public:
	
	FileSystem():Disks(B_SIZE, D_SIZE)
	{	blocksUsed = 0;
		myBuffer = new DiskBlockType(B_SIZE);
		//cout << Disks.getNumBlocks();
		x = '-';
		for(int i = 0; i < Disks.getNumBlocks(); i++)
		{	free.push_back(1);
			myBuffer->data[i] = x;
		}
	
	
	}


	
// creates 0 sized file called filename, returns true if successful else false.
	bool Create(string filename)
	{	int currentBlock = 0;
		int f = freeBlock();
		//cout << "v" << endl;
		if(f != -1)
		{//	cout << "v" << endl;
			blocksUsed++;
			direct.add(filename);
			FileControlBlock k = direct.getFile(filename);
			k.setStartBlock(f);
			k.setEndBlock(f);
			//cout << f << endl;

			free[f] = 0;	

		//	cout << "T"<< endl;
			return true;
		}
		
		return false;
	}


// deletes file called filename, returns space back to the free space pool.
	bool Delete(string filename)
	{	if(direct.fileExists(filename))
		{	int index = direct.fileExist(filename);
			free[index] = 1;
			direct.deleteD(filename);	
			return true;		
		}
		return false;
	}



	int Open(string filename, char mode)
	{	const char * c = filename.c_str();
		if(direct.fileExists(filename))
			return (open(c, mode));
		else
			return -1;

	}
	// opens file called filename in the mode request and returns an integer file handle that can be used for read or write depending on mode
	//


	bool Close(int handle)
	// closes the file with this handle, returns true if successful or false if not.
	{	int cc = close(handle);
			if (cc == 0)
			{	cout << "closed "<< endl;
				return true;
			}
		
	}		

	int fileExist(string fn)
	{	return(direct.fileExist(fn));
	}
 
	int Read(int handle, int numchars, char *buffer)
	{	//int handle = direct.fileExist(fileName);
			
		//myBuffer[handle].data -> buffer;
		//Disks.read(handle, buffer);
	
	}	
	
	// reads numchars from file with this handle and returns these in buffer. Returns the number of characters actually read (might be less than numchars), or -1 if there is an error (e.g., no such handle).


	void Write(string fn, string UISTRING)
	{	if(fileExist(fn)){

			double length = UISTRING.length();
			int count = 0; 	//count needs to reset each time a new data string is passed

			int f = fileExist(fn);//index or block number


			for(int j = 0; j < B_SIZE; j++){
				myBuffer->data[j] = UISTRING[j];
				count++;
			}
			Disks.write(f,myBuffer);
	
		}
	}

		

	
	
	// writes numchars chars that are in buffer to the file with this handle. Returns the number actually written or -1 if there is an error.

	//int Stats( string filename); 
	// returns the current size of filename


	//vector<string> List(); // returns a list of all currently existing file names as stings

	int freeBlock()
	{	int newBlock = 0;
    		if(blocksUsed < Disks.getNumBlocks())
		{	for (int i = 0; i < D_SIZE; i++)
			{	Disks.read(i,myBuffer);
 				if (myBuffer->data[i] == '-' && free[i] == 1)
				{	newBlock = i;
					//cout << "IIII: " <<i << endl;
					break;
				}
			}
    			return newBlock;
		}else
			return -1;
	}


	void display()
	{	direct.display();
		cout << "FREE SPACE" << Disks.getNumBlocks()-blocksUsed << endl;
		
	}
	int getDSize()const
	{	return D_SIZE;
	}
	int getBSize() const
	{	return B_SIZE;
	}
	
	void displayFCB(string s)
	{	int index = fileExist(s);
		direct.FCB[index].display();
	}
	
private:
	directory direct;
	DiskProcessType Disks;
	DiskBlockType *myBuffer;;
	//vector<FileControlBlock>*FCB;
	vector<int> free;
	int blocksUsed;
	char x;
	static int const D_SIZE = 10;
	static int const B_SIZE = 10;
};


#endif
