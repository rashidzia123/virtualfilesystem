#include<fstream>
#include<unistd.h>
#include<vector>
#include"dependencies/filesystem.h"
//#include"json.hpp"


void fileinfo(string &name, string &path, int &size)
{
	ifstream i("data.txt");
	if(i.good())
	{
			fstream handle;
			handle.open("data.txt",fstream::in);
			handle>>size;
			handle>>name;
			handle>>path;
			handle.close();	
			system("clear");	
	
	}
	else
	{	cout<<"Enter: "<<endl;
		cout<<"Drive name: ";
		cin>>name;
		while(name =="")
		{
			cout<<"invalid name, enter again: ";
			cin>>name;
		}
		cin.ignore();
		cout<<"Path: ";
		getline(cin, path);
		while(path == "")
		{
			cout<<"invalid path, enter again: ";
			getline(cin, path);
		}
		int size = 0;
		cout<<"Size: ";
		cin>>size;
		while(size<1)
		{
			cout<<"invalid size, enter again: ";
			cin>>size;
		}
		system("clear");
		cout<<"New drive created, details given below: "<<endl;
		cout<<"Name: "<<name<<endl;
		cout<<"Size: "<<size<<endl;
		cout<<"Path: "<<path+name<<endl;	
			fstream handle;
			handle.open("data.txt",fstream::out);
			handle<<size<<endl;
			handle<<name<<endl;
			handle<<path<<endl;
			handle.close();		
			
	
	cin.ignore();
	}
	i.close();
}

int main()
{

	//for importing to the root directory
	//imprt <host address> root
	//for importing to sub-dir in root, do not write root at the start
	//start address host address with / and write complete adbolute address   e.g. /home/rashid/Desktop/file.txt
	
	int size;
	string name;
	string path;
		fileinfo(name, path, size);
	filesystem *newDrive  = new filesystem(name,size,path);

	cout<<"Commands:"<<endl;
	cout<<"ls\t:to listing files and direcotries"<<endl;
	cout<<"cd\t:to change direcoty"<<endl;
	cout<<"mkdir\t:to make new directory"<<endl;
	cout<<"rm\t:to remove file or direcotry"<<endl;
	cout<<"import\t:import file from host"<<endl;
	cout<<"Extra: "<<endl;
	cout<<"clear\t:to clear screen"<<endl;
	cout<<"exit\t:to terminate program"<<endl;
	cout<<"show\t:to display details and data of file"<<endl;
	cout<<"	e.g. show file.txt"<<endl;	

	
	newDrive->take_command();



	
	return 0;
}
