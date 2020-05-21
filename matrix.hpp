#ifndef __Matrix__hpp
#define __Matrix__hpp

#include <iostream>
#include <vector>
#include <stdexcept>
#include <cmath>
using namespace std;

class Matrix{
private:
	int rows;
	int columns;
	bool extended;
	vector<vector<double>> a;
	vector<double> b;
public:
	Matrix();
	Matrix(int r, int c, bool fill);
	Matrix(const Matrix &m);
	~Matrix(){};
	
	double get_element(int row, int column);
	vector<double> get_row(int row);
	vector<double> get_column(int column);
	vector<double> get_sol();
	vector<int> get_dimensions();
	void set_element(int i, int j, double x);
	bool is_squared();
	bool is_diagonal();
	bool is_superior_triangular();
	bool is_inferior_triangular();
	bool is_triangular();	
	bool is_null();
	bool is_identity();
	bool is_invertible();
	bool is_symmetrical();


	Matrix solve_system(); //Only for squared matrices for now
	double determinant();
	double trace();
	void extend(bool homogeneus);
	void round_elements();
	vector<double> multiply_row(int row, double a);//
	vector<double> multiply_column(int column, double a);//
	void sum_rows(int row_1, int row_2, double a);//
	double sum_elements_row(int row);
	Matrix inverse();
	Matrix transpose();
	Matrix minor_matrix(int row, int column);
	double cofactor(int row, int column);
	Matrix adj();

	//Operators
	Matrix operator+(const Matrix &m);
	Matrix operator-(const Matrix &m);
	Matrix operator*(const Matrix &m);
	bool operator==(const Matrix &m);
	Matrix& operator=(const Matrix &m);
	friend ostream& operator<<(ostream& out, const Matrix& m);
	friend Matrix operator*(Matrix m, double a);
	friend Matrix operator*(double a, Matrix m);
};

Matrix Identity(int n);


#endif
