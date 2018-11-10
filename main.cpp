#include "stdafx.h"
#include <iostream>
#include <fstream>
#include "Tree.h"
using namespace std;

int main()
{
	ofstream output;
	output.open("output.txt");
	Tree smallTree;
	int insertNumber[11] = {6, 9, 3, 5, 5, 7, 2, 10, 4, 1, 8};
	for (int i = 0;i < 11;i++) {
		smallTree.insert(insertNumber[i]);
		cout << endl << endl;
	}
	output << smallTree;
	output.close();
	system("pause");
    return 0;
