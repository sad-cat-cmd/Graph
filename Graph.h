#pragma once

#include <iostream>
#include <vector>
#include <random>
#include <exception>
#include <string>

using namespace std;
class My_Excaption : public exception {
	private:
	string msg = "";
	int code_error;

	public:
	int get_error_code () {return code_error;}
	string _get_error_msg () {return msg;}
	
	friend class Graph;
	friend class Oriented_Graph;

	
};
class Graph
{
private:
	unsigned int Cols_Graph { NULL };
	unsigned int Rows_Graph{ NULL };
	bool Oriented_Matrix{ false };
	bool Auto_Edited_Graph_List_and_Matrix {false};

	vector <vector<unsigned int>> Adjacency_List;
	vector <vector<unsigned int>> Adjacency_Matrix;
	vector <vector<unsigned int>> Weighted_Matrix;
	
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
	void operator [] (const Graph& _graph){
	}
	void operator + (const Graph& _graph) {

	}
	// GETERS
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

	void Set_Value_In_Adjancency_Matrix_At_Double_Index(unsigned int index_1, unsigned int index_2, unsigned int value) {
		Adjacency_Matrix[index_1][index_2];
	}
	void Changing_Size_Adjancency_Matrix (){
		
	}
	void Increasing_Size_Adjacency_Matrix_with_edeting_values_0(const int New_Rows, const int New_Cols) {
		if (New_Rows <= Rows_Graph || New_Cols <=Cols_Graph) return; 
		Adjacency_Matrix.reserve(New_Rows);
		for (size_t i = 0; i < New_Rows; i++)
		{
			Adjacency_Matrix.emplace_back();
			Adjacency_Matrix[i].reserve(New_Cols);
			Adjacency_Matrix[i].resize(New_Cols);
		}
		if (New_Cols != Cols_Graph || New_Rows != Rows_Graph) Changing_ROWS_COLS(New_Rows, New_Cols);
	}
	void Increasing_Size_Adjancency_Matrix_Without_Edeting_values(const int New_Rows, const int New_Cols){
		if (New_Rows <= Rows_Graph || New_Cols <=Cols_Graph) return; 
		if (New_Rows < Rows_Graph); // ;
		if (New_Rows > Cols_Graph); // ;
	}
	void Initializing_0_Adjacency_Matrix(const int New_Rows, const int New_Cols) {
		Adjacency_Matrix.reserve(New_Rows);
		for (size_t i = 0; i < New_Rows; i++)
		{
			Adjacency_Matrix.emplace_back();
			Adjacency_Matrix[i].reserve(New_Cols);
			Adjacency_Matrix[i].resize(New_Cols);
		}
		if (New_Cols != Cols_Graph || New_Rows != Rows_Graph) Changing_ROWS_COLS(New_Rows, New_Cols);
	}
	void Random_Filling_Weighted_Matrix(){


		// for (int i = 0; i < Rows_Graph; i++) {
		// 	for (int j = i + 1; j < Cols_Graph; j++){
		// 		Adjacency_Matrix[i][j] = rand () % 2 - 0;
		// 		if (Adjacency_Matrix[i][j]) Adjacency_Matrix[j][i] = 1;
		// 	}
		// }
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
	void Print_Adjacency_Matrix() {
		for (size_t i = 0; i < Rows_Graph; ++i) {
			for (size_t j = 0; j < Cols_Graph; ++j) {
				std::cout << Adjacency_Matrix[i][j] << " ";
			}
			std::cout << std::endl;
		}
	}
	
	
	/// edit
	void Identifying_Vertices_Adjancency_Matrix(const int vertex_1, const int vertex_2){
		int New_I_Index {0};
		int New_J_Indes {0};
		for (int i = 0; i < Rows_Graph; i++) {
			if (i = vertex_2) continue;
			for (int j = 0; j < Cols_Graph; ++j) {
                if (j == vertex_2) continue;
                int New_J_index = (j > vertex_2) ? j - 1 : j;
                Adjacency_Matrix[New_I_Index][New_J_index];
            }
            New_I_Index++;
		}
	}
	void Rib_Tightening_Adjncency_Matrix(){
	}
	void Splitting_Vertices(){

	}

};
class Oriented_Graph {
	private:
	vector <vector<unsigned int>> Adjacency_Matrix;
	vector <vector<unsigned int>> Adjcency_List;
	unsigned int Rows_Matrix;
	unsigned int Cols_Matrix;
	const int auto_max_cols_size (vector <vector<unsigned int>> temp_vector){
		int Max_Len {0};
		for (int i = 0; i < temp_vector.size(); i++) {if (temp_vector[i].size() > Max_Len) {Max_Len = temp_vector[i].size();}}
		return Max_Len;
	}

	void edit_cols_rows_Value ();

	void function_copied_construction(const vector <vector<unsigned int>>& passed_vector) {
		for (size_t i = 0; i < auto_max_cols_size(passed_vector); i++)
		{
			Adjacency_Matrix.emplace_back();
			Adjacency_Matrix[i].reserve(New_Cols);
			Adjacency_Matrix[i].resize(New_Cols);
		}
		for (int i = 0; i< passed_vector.size(); i++) {
			for (int j = 0; j < passed_vector.size();j++) {
				Adjacency_Matrix[i][j] = passed_vector[i][j];
			}
		}
	}
	public:
		Oriented_Graph(const vector <vector<unsigned int>> temp_Matrix){

		}
		Oriented_Graph() {

		}
		Oriented_Graph (const Graph& temp_Object) {
			//function_copied_construction(temp_Object);
			//this->Cols_Matrix = temp_Object.Get_Cols_Adjancency_Matrix();
			//this->Rows_Matrix = ;
		}
};
