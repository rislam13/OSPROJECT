//Name:Reham Islam
//This is FILECONTROLBLOCK class


#ifndef FILECONTROLBLOCK
#define FILECONTROLBLOCK

//***********************
//#include "diskprocess.h"
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string>

using namespace std;


class FileControlBlock{


	public:
		

		friend bool operator== ( const FileControlBlock &n1, const FileControlBlock &n2)
		{	return (n1.getFileName() == n2.getFileName());
		}

		void operator= ( const FileControlBlock &n2)
		{	setStartBlock(n2.getStartBlock());
			setEndBlock(n2.getEndBlock());
			incrementSize(n2.getSize());
			setFN(n2.getFileName());
		}


		FileControlBlock()
		{	fileName = " ";
			startBlock = 0;
			endBlock = 0;
			size = 0;
		}
		FileControlBlock(string name)
		{	fileName = name;
			startBlock = 0;
			endBlock = 0;
			size = 0;
		}
		
		void setFN(string FN)
		{	fileName = FN;
		}
			
		void setStartBlock(int startNumber)
		{	startBlock = startNumber;
		}


		void setEndBlock(int endNumber)
		{	endBlock = endNumber;
		}

		void setBlockSize(int bs)
		{	blockSize = bs;
		}

		void incrementSize(int s)
		{	size = size +s;
		}

		void decrementSize(int s)
		{	size = size -s;
		}


		string getFileName() const {	return fileName; }
		int getStartBlock() const {	return startBlock; }
		int getEndBlock() const{ return endBlock; }
		int getSize() const { return size; }
		int getBlockSize() const { return blockSize; }
		void display()
		{	cout << "FileName: " << fileName << endl;
			cout << "startBlock: " << startBlock << endl;
			cout << "endBlock: " << endBlock << endl;
		}	

	

	private:
		int endBlock;
		int size;
		int blockSize;
		string fileName;
		int startBlock;
	

};

#endif
