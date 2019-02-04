#include <iostream>
#include <string>
#include <fstream>
#include "struct1.h"
using namespace std;
void Backup(githubuser *O_array, githubuser *& B_array, int userCount)//Backing up the data by copying the array to another array
{
	for(int i=0 ; i<userCount ; i++)
	{
		B_array[i].firstname=O_array[i].firstname;
		B_array[i].username=O_array[i].username;
		B_array[i].email=O_array[i].email;
		B_array[i].foldercount=O_array[i].foldercount;
		B_array[i].githubfolders = new string[B_array[i].foldercount];
		for(int a=0; a<B_array[i].foldercount; a++)
			B_array[i].githubfolders=O_array[i].githubfolders;
		B_array[i].institute_name = new string;
		B_array[i].institute_name=O_array[i].institute_name;
		B_array[i].qualification_level = new string;
		B_array[i].qualification_level=O_array[i].qualification_level;
		
	}
}
void remove(githubuser &user)//This can remove the Background info at any time the user wishes
{
	*user.qualification_level=nullptr;
	*user.institute_name=nullptr;
}
void print(githubuser &user)//Printing the data of a specific user 
{
	cout<<user.firstname<<endl;
	cout<<user.username<<endl;
	cout<<user.email<<endl;
	cout<<user.foldercount<<endl;
	for(int i=0; i<user.foldercount;i++)
		cout<<user.githubfolders[i]<<endl;
	if(user.institute_name!=nullptr)
		cout<<*user.institute_name;
	if(user.qualification_level!=nullptr)
		cout<<*user.qualification_level;
}
void setEduBack(githubuser &user)//Getting the background information of the user
{
	cout<<user.firstname<<", enter your qualification level : ";
	user.qualification_level = new string;
	cin>>*user.qualification_level;
	cout<<user.firstname<<", enter your institution name: ";
	user.institute_name = new string;
	cin>>*user.institute_name;
	
}
int main()
{
	ifstream ali("file.txt");
	int a,b;
	ali>>a;
	githubuser *arr = new githubuser[a];
	githubuser *backup = new githubuser[a];
	ali>>arr[0].firstname;
	ali>>arr[0].username;
	ali>>arr[0].email;
	ali>>arr[0].foldercount;
	arr[0].githubfolders = new string[arr[0].foldercount];
	for(int i=0; i<arr[0].foldercount;i++)
		ali>>arr[0].githubfolders[i];
	while(1)
	{
		cout<<"Funtion 1: Press 1 to add the background info of the user. "<<endl;
		cout<<"Funtion 2: Press 2 to print the info of the user.  "<<endl;
		cout<<"Funtion 3: Press 3 to remove the background info of the user.  "<<endl;
		cout<<"Funtion 4: Press 4 to backup the data of the user.  "<<endl;
		cin>>b;
		if(b==1)
			setEduBack(arr[0]);
		if(b==2)
			print(arr[0]);
		if(b==3)
			remove(arr[0]);
		if(b==4)
			Backup(arr,backup,a);
	}
	for(int x=0; x<a ;a++)
		delete[] arr[a].institute_name;
	for(int x=0; x<a ;a++)
		delete[] arr[a].qualification_level;
	delete[] arr,backup;
}