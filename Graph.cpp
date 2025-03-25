#include "Graph.h"

#include <iostream>

using namespace std;
int main() {
	Graph G(5, 5);
	
	size_t size = G.Get_Max_Size_Matrix();
	cout << size << endl;
	
	//G.Changing_Size_Adjacency_Matrix(10, 10);
	G.Initializing_0_Adjacency_Matrix(10, 10);
	//G.Random_Filling();
	G.Print_Adjacency_Matrix();
	int a = 6;
	
	//G.Converting_Adjacency_Matrix_to_Adjacency_List();
	//G.printf_adjacency_list();
}