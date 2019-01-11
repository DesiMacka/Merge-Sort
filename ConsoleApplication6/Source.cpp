//23/March/2017
//Hello human!
//This code implements the algorithm to sort data
//using the merge sort method. It divides the unsorted list into 
//n sublists, each containing 1 element (a list of 1 element is
//considered sorted). Repeatedly merges sublists to produce new 
//sorted sublists until there is only 1 sublist remaining. 
//This will be the sorted list that will be returned.
//The code uses the wordlist.txt from BlackBoard as the test bed.
//***************************************************************
//*  The code takes about 34 seconds to sort all the list.      *
//***************************************************************
//Written by Desi, CIS 2542-001, Homework(3).

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

//MergeSort function to implement the algorithm
void MergeSort(vector<string> & LIST, int START, int MIDPOINT, int END)
{
	vector<string> temp;
	int i = START;			 //LHS sublist
	int j = MIDPOINT + 1;	 //RHS sublist

	while ((i <= MIDPOINT) && (j <= END))
	{
		if (LIST[i] < LIST[j])
		{
			temp.push_back(LIST[i]);
			++i;
		}
		else
		{
			temp.push_back(LIST[j]);
			++j;
		}
	}

	while (i <= MIDPOINT)
	{
		temp.push_back(LIST[i]);
		++i;
	}
	while (j <= END)
	{
		temp.push_back(LIST[j]);
		++j;
	}

	//loading elements on the temporary vector 'temp'
	for (int k = 0; k < temp.size(); ++k)
	{
		LIST[k + START] = temp[k];
	}

}

//Merge function repeatedly merging sublists until one remaining
void Merge(vector<string>& LIST, int START, int END)
{

	if (END > START)
	{
		int MIDPOINT = (START + END) / 2;
		Merge(LIST, START, MIDPOINT);
		Merge(LIST, MIDPOINT + 1, END);
		MergeSort(LIST, START, MIDPOINT, END);
	}
}

int main()
{
	//loading the wordlist file used as test bed
	ifstream file("wordlist.txt");
	vector<string> LIST;
	while (file.eof() == false)
	{
		string word;
		file >> word;
		LIST.push_back(word);
	}

	//calling the function to sort the list
	Merge(LIST, 0, LIST.size() - 1);

	//for loop to print the sorted list
	for (int i = 0; i < LIST.size(); ++i)
	{
		cout << LIST[i] << endl;
	}

	file.close();

	system("PAUSE");
	return 0;
}