//logic:
//sort the string
//traverse and get duplicates along woth the count of each individual duplicate
//initialize an empty output string and append each character followed by its count
//print the output string

//My assumptions:
//if i/p => aabbcccccaaa
//o/p should be a5b2c5 and not a3b2c5a3

#include<iostream>
#include<cstring>    //to use append()
#include<algorithm>  //to use sort()
#include<cstdlib>   //to use malloc()

using namespace std; //isse baar baar std:: nhi likhna padta

int main()
{
	int n,i,flag=0; 
	char charcount='0'; //characters can also be incremented like an integer
	
	cout<<"\nWhat should be your string's size => ";
	cin>>n;
	
	//output string
	//Let the size of output string be same as the input string
	char *compressed=(char*)malloc(sizeof(char)*(n));
	compressed[0]={'\0'};//making it as an empty string
	
	//input string
	cout<<"\nStart filling the string => ";
	char *str=(char*)malloc(sizeof(char)*(n));
	for(i=0;i<n;i++)
	{
		cout<<"\nCharacter at index "<<i<<" ";
		cin>>str[i];
	}
	
	//sorting the string to get duplicate characters in the consecutive locations
	sort(str,str+n);
	
	//now iterate thorugh the string again. Now the string is already sorted
   for(i=0;i<n;i++)
   {
   		//to count the duplicate characters
   		charcount++;  		
	
   		if((str[i]!=str[i+1] || i+1>=n))   //i+1>=n isiliye taaki last element ko ek baar check kar sake
   		{
   			//concantenating the string to output
   			strncat(compressed,&str[i],1);
   			strncat(compressed,&charcount,1);
   	
			//reset karo ab count ko
			charcount='0';
		}	
   }
   
   //printing the compressed string now
   cout<<"\n "<<compressed;
	return 0;
}
