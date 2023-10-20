#include <iostream>
#include <vector>
#include <exception>
#include "Matrix.h"

using namespace std;

	Matrix::Matrix() {
	}

	Matrix::Matrix(int lines, int columns) : matrica(lines, vector<double>(columns, 0)) {
	}

	Matrix::Matrix(const Matrix& sec) : matrica(sec.matrica) {
	}


	Matrix::Matrix(const vector<vector<double>>& sec) : matrica(sec) {
	}

	Matrix::~Matrix() {}
	
	void Matrix::Print() {
		cout << endl;
		for (int i = 0; i < matrica.size(); i++) {
			for (int j = 0; j < matrica[i].size(); j++) {
				cout << matrica[i][j] << " ";
			}
			cout << endl;
		}
	}

	void Matrix::Filling() {
		int value;
		cout << "enter number of lines and columns: ";
		int lines, columns;
		cin >> lines >> columns;
		matrica.resize(lines);
		for (int i = 0; i < lines; i++) {
			matrica[i].resize(columns);
			cout << endl << "enter " << columns << " numbers:";
			for (int j = 0; j < columns; j++) {								
				cin >> value;
				matrica[i][j] = value;
			}
		}
	}

	const Matrix& Matrix::operator=(const Matrix& sec) {
			matrica.resize(sec.matrica.size());
			for (int i = 0; i < matrica.size(); i++) {
				matrica[i].resize(sec.matrica[i].size());
				for (int j = 0; j < matrica[i].size(); j++){
					matrica[i][j] = sec.matrica[i][j];
				}
			}
			return *this;
		}

	const Matrix& Matrix::operator+=(const Matrix& sec) {
			if (matrica.size() != sec.matrica.size() || matrica[0].size() != sec.matrica[0].size()) {
				exception error("different sizes of matrices");
				throw error;
			}
			for (int i = 0; i < matrica.size(); i++) {
				for (int j = 0; j < matrica.size(); j++)
				{
					matrica[i][j] = matrica[i][j] + sec.matrica[i][j];
				}
			}
			return *this;
	}
	
	Matrix Matrix::operator+(const Matrix& sec) const{
		Matrix m(*this);
		m += sec;
		return m;
	}

	const Matrix& Matrix::operator-=(const Matrix& sec) {
		if (matrica.size() != sec.matrica.size() || matrica[0].size() != sec.matrica[0].size()) {
			exception error("different sizes of matrices");
			throw error;
		}
		for (int i = 0; i < matrica.size(); i++) {
			for (int j = 0; j < matrica.size(); j++)
			{
				matrica[i][j] = matrica[i][j] - sec.matrica[i][j];
			}
		}
		return *this;
	}

	Matrix Matrix::operator-(const Matrix& sec) const{
		Matrix m(*this);
		m -= sec;
		return m;
	}

	const Matrix Matrix::operator*(const Matrix& sec) const{
		if (matrica[0].size() != sec.matrica.size()) {
			exception error("wrong sizes of matrices");
			throw error;
		}
		int k = matrica[0].size();
		Matrix m(matrica.size(), sec.matrica[0].size());
		for (int i = 0; i < matrica.size() ; i++)
		{
			for (int j = 0; j < sec.matrica[0].size(); j++)
			{
				m.matrica[i][j] = 0;
				for (int k = 0; k < matrica[0].size(); k++)
				{
					m.matrica[i][j] += matrica[i][k] * sec.matrica[k][j];
				}
			}
		}
		return m;
	}



	const Matrix Matrix::operator+(int x) const {
		Matrix m(matrica.size(), matrica[0].size());
		for (int i = 0; i < matrica.size(); i++) {
			for (int j = 0; j < matrica[0].size(); j++) {
				m.matrica[i][j] = matrica[i][j] + x;
			}
		}
		return m;
	}

	const Matrix Matrix::operator-(int x) const {
		Matrix m(matrica.size(), matrica[0].size());
		for (int i = 0; i < matrica.size(); i++) {
			for (int j = 0; j < matrica[0].size(); j++) {
				m.matrica[i][j] = matrica[i][j] - x;
			}
		}
		return m;
	}

	const Matrix Matrix::operator*(int x) const {
		Matrix m(matrica.size(), matrica[0].size());
		for (int i = 0; i < matrica.size(); i++) {
			for (int j = 0; j < matrica[0].size(); j++) {
				m.matrica[i][j] = matrica[i][j] * x;
			}
		}
		return m;
	} 

	Matrix Matrix::operator++(int)
	{
		 Matrix temp = *this;
		 ++*this;
		 return temp;
	}

	Matrix Matrix::operator--(int)
	{
		Matrix temp = *this;
		--*this;
		return temp;
	}

	const Matrix& Matrix::operator++() {
		for (int i = 0; i < matrica.size(); i++) {
			for (int j = 0; j < matrica[0].size(); j++) {
				matrica[i][j] = matrica[i][j] + 1;
			}
		}
		return *this;
	}

	const Matrix& Matrix::operator--() {
		for (int i = 0; i < matrica.size(); i++) {
			for (int j = 0; j < matrica[0].size(); j++) {
				matrica[i][j] = matrica[i][j] - 1;
			}
		}
		return *this;
	}

	Matrix operator+(int x, const Matrix& sec) {
		return sec + x;
	}

	Matrix operator-(int x, const Matrix& sec) {
		Matrix m(sec.matrica.size(), sec.matrica[0].size());
		for (int i = 0; i < sec.matrica.size(); i++) {
			for (int j = 0; j < sec.matrica[0].size(); j++) {
				m.matrica[i][j] = sec.matrica[i][j] * (-1);
			}
		}
		return m + x;
	}

	Matrix operator*(int x, const Matrix& sec) {
		return sec * x;
	}

	bool Matrix::operator==(const Matrix& sec) {
		if (matrica.size() != sec.matrica.size() || matrica[0].size() != sec.matrica[0].size()) {
			exception error("different sizes of matrices, matrices incomparable");
			throw error;
		}
		for (int i = 0; i < sec.matrica.size(); i++) {
			for (int j = 0; j < sec.matrica[0].size(); j++) {
				if (matrica[i][j] != sec.matrica[i][j]) {
					return false;
				}
			}
		}
		return true;
	}

	bool Matrix::operator!=(const Matrix& sec) {
		if (matrica.size() != sec.matrica.size() || matrica[0].size() != sec.matrica[0].size()) {
			exception error("different sizes of matrices, matrices incomparable");
			throw error;
		}
		for (int i = 0; i < sec.matrica.size(); i++) {
			for (int j = 0; j < sec.matrica[0].size(); j++) {
				if (matrica[i][j] == sec.matrica[i][j]) {
					return false;
				}
			}
		}
		return true;
	}

	Matrix Matrix::Inverse() const {
		if (matrica.size() != matrica[0].size()) {
			exception error("wrong sizes of matrices");
			throw error;
		}
			int n = matrica.size();
			vector < vector <double> > a(matrica);
			vector < vector <double> > ans(n, vector <double>(n, 0));  
			for (int i = 0; i < n; i++) {
				ans[i][i] = 1.0;
			}
			for (int i = 0; i < n; i++) {
				int row = i;
				double mx = a[i][i];
				for (int k = i + 1; k < n; k++) {
					if (abs(a[k][i]) > mx) {
						row = k;
						mx = abs(a[k][i]);
					}
				}
				if (row != i) {
					swap(a[row], a[i]);
					swap(ans[row], ans[i]);
				}
				for (int j = i + 1; j < n; j++) {
					double e = a[j][i] / a[i][i];
					for (int k = 0; k < n; k++) {
						a[j][k] -= e * a[i][k];
						ans[j][k] -= e * ans[i][k];
					}
				}
			}
			for (int i = n - 1; i >= 0; i--) {
				for (int j = i - 1; j >= 0; j--) {
					double e = a[j][i] / a[i][i];
					for (int k = 0; k < n; k++) {
						a[j][k] -= e * a[i][k];
						ans[j][k] -= e * ans[i][k];
					}
				}
				for (int j = 0; j < n; j++) {
					ans[i][j] /= a[i][i];
				}
			}			
			return Matrix(ans);
	}

	Matrix Matrix::operator/(const Matrix& sec) const{
		return *this * sec.Inverse();
	}

	const Matrix Matrix::operator/(int x) const {
		Matrix m(matrica.size(), matrica[0].size());
		for (int i = 0; i < matrica.size(); i++) {
			for (int j = 0; j < matrica[0].size(); j++) {
				m.matrica[i][j] = matrica[i][j] / x;
			}
		}
		return m;
	}

	Matrix operator/(int x, const Matrix& sec) {
		return x * sec.Inverse();
	}

	const double Matrix::Element(int x, int y) const{
		return matrica[x][y];
	}

	const int Matrix::Size() const {
		return matrica.size() * matrica[0].size();
	}

	const Matrix& Matrix::operator+=(int x) {
		for (int i = 0; i < matrica.size(); i++) {
			for (int j = 0; j < matrica[0].size(); j++) {
				matrica[i][j] += x;
			}
		}
		return*this;
	}

	const Matrix& Matrix::operator-=(int x) {
		for (int i = 0; i < matrica.size(); i++) {
			for (int j = 0; j < matrica[0].size(); j++) {
				matrica[i][j] -= x;
			}
		}
		return* this;
	}

	Matrix Matrix::Transpose() const {
		Matrix m(matrica.size(), matrica[0].size());
		int t;
		for (int i = 0; i < matrica.size(); ++i)
		{
			for (int j = i; j < matrica[0].size(); ++j)
			{
				t = matrica[i][j];
				m.matrica[i][j] = matrica[j][i];
				m.matrica[j][i] = t;
			}
		}
		return m;
	}