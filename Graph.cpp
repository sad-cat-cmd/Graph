#include "Graph.h"

#include <iostream>

using namespace std;
int main() {
	Graph G(5, 5);
	
	size_t size = G.Get_Max_Size_Matrix();
	cout << size << endl;
	
	G.Changing_Size_Adjacency_Matrix(100, 100);

	G.Converting_Adjacency_Matrix_to_Adjacency_List();
	G.printf_adjacency_list();
}