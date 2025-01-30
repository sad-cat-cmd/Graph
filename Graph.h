#pragma once

#include <iostream>
#include <vector>
#include <random>

using namespace std;
class Graph
{
private:
	unsigned int Cols_Graph { NULL };
	unsigned int Rows_Graph{ NULL };
	bool Oriented_Matrix{ false };

	vector <vector<unsigned int>> Adjacency_List;
	vector <vector<unsigned int>> Adjacency_Matrix;
	
	void Changing_ROWS_COLS(unsigned int NEWCOLS, unsigned int NEWROWS) {
		Cols_Graph = NEWCOLS;
		Rows_Graph = NEWROWS;
	}

public:
	Graph(unsigned int Size_Adjacency_Matrix) {
		Cols_Graph = Size_Adjacency_Matrix;
		Rows_Graph = Size_Adjacency_Matrix;
	}
	Graph(unsigned int ROWS_Adjancence_Matrix, unsigned int COLS_Adjancence_Matrix){
		Cols_Graph = COLS_Adjancence_Matrix;
		Rows_Graph = ROWS_Adjancence_Matrix;
	}
	Graph(unsigned int ROWS_Adjancence_Matrix, unsigned int COLS_Adjancence_Matrix, bool Oriented_Adjancency_Matrix) {
		Cols_Graph = COLS_Adjancence_Matrix;
		Rows_Graph = ROWS_Adjancence_Matrix;
		Oriented_Matrix = Oriented_Adjancency_Matrix;
	}
	/*Graph(unsigned int Size_Adjacency_Matrix, bool Oriented_Adjancency_Matrix) {
		Cols_Graph = Size_Adjacency_Matrix;
		Rows_Graph = Size_Adjacency_Matrix;
		Oriented_Matrix = Oriented_Adjancency_Matrix;
	}*/
	// гетерры / GETERS
	size_t Get_Max_Size_Matrix() {
		return Adjacency_Matrix.max_size();
	}
	unsigned int Get_Rows_Adjancency_Matrix() {
		return Rows_Graph;
	}
	unsigned int Get_Cols_Adjancency_Matrix() {
		return Cols_Graph;
	}
	auto Get_Pointer_Adjancency_Matrix() {
		return Adjacency_Matrix.data();
	}
	
	// инициализация 
	void Changing_Size_Adjacency_Matrix(const int New_Rows, const int New_Cols) {
		Adjacency_Matrix.reserve(New_Rows);
		for (size_t i = 0; i < New_Rows; i++)
		{
			Adjacency_Matrix.emplace_back();
			Adjacency_Matrix[i].reserve(New_Cols);
			Adjacency_Matrix[i].resize(New_Cols);
		}
		if (New_Cols != Cols_Graph || New_Rows != Rows_Graph) Changing_ROWS_COLS(New_Rows, New_Cols);
	}
	
	void Random_Value_Initializing_Adjacency_Matrix(const int New_Rows, const int New_Cols) {
		Adjacency_Matrix.reserve(New_Rows);
		for (size_t i = 0; i < New_Rows; i++)
		{
			Adjacency_Matrix.emplace_back();
			Adjacency_Matrix[i].reserve(New_Cols);
			Adjacency_Matrix[i].resize(New_Cols);
		}
		if (New_Cols != Cols_Graph || New_Rows != Rows_Graph) Changing_ROWS_COLS(New_Rows, New_Cols);
	}
	void ME_Int_Value_Initializing_Adjacency_Matrix() {

	}
	void printf_adjacency_list() {
		cout << "--adjancnecy_list--" << endl;
		for (int i = 0; i < Adjacency_List.size(); i++)
		{
			/*if (check_sum_in_line(adjacency_list[i]) == 0) {
				continue;
			}*/
			cout << i;
			for (int j = 0; j < Adjacency_List[i].size(); j++)
			{
				if (j == Adjacency_List[i].size() - 1)
				{
					cout << " -> " << Adjacency_List[i][j] << endl;
					break;
				}
				else
					cout << " -> " << Adjacency_List[i][j];
			}
		}
	}
	void Converting_Adjacency_Matrix_to_Adjacency_List() {
		Adjacency_List.resize(Rows_Graph);

		for (int i = 0; i < Rows_Graph; ++i) {
			for (int j = 0; j < Cols_Graph; j++) {
				if (Adjacency_Matrix[i][j] == 1) {
					Adjacency_List[i].push_back(j);
					cout << Adjacency_List[i][j];
				}
			}
		}

		
	}

	//void creating_an_adjacency_list() {
	//	adjacency_list.resize(number_of_vertices);
	//	for (int i = 0; i < number_of_vertices; i++) {
	//		for (int j = 0; j < number_of_vertices; j++) {
	//			/*if (check_sum_in_line(array, i) == 0) {
	//				adjacency_list.clear();
	//				continue;
	//			}*/
	//			if (array[i][j] == 1) {

	//				adjacency_list[i].push_back(j);
	//				//adjacency_list[j].push_back(i);
	//			}
	//		}
	//	}
	//}
	void Print_Adjacency_Matrix() {
		for (size_t i = 0; i < Rows_Graph; ++i) {
			for (size_t j = 0; j < Cols_Graph; ++j) {
				std::cout << Adjacency_Matrix[i][j] << " ";
			}
			std::cout << std::endl;
		}
	}
};

//#include <iostream>
//
//template <typename T>
//class MyClass {
//public:
//    T value;
//
//    // Конструктор по умолчанию
//    MyClass() : value() {}
//
//    // Конструктор с инициализацией значением
//    MyClass(T val) : value(val) {}
//};
//
//int main() {
//    // Инициализируем переменную разными типами данных
//    MyClass<double> double_var;
//    double_var.value = 1.5;
//
//    MyClass<int> int_var(42);
//
//    // Выводим её значения
//    std::cout << "Double value: " << double_var.value << std::endl;
//    std::cout << "Int value: " << int_var.value << std::endl;
//
//    return 0;
//}