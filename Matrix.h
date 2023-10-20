#include <vector>


class Matrix {
private:
	std::vector<std::vector<double>> matrica;

public:
	Matrix();

	Matrix(int lines, int columns);

	Matrix(const Matrix& sec);

	Matrix(const std::vector<std::vector<double>>& sec);

	~Matrix();

	void Print();

	void Filling();

	const Matrix& operator=(const Matrix& sec);

	const Matrix& operator+=(const Matrix& sec);

	const Matrix& operator+=(int x);

	const Matrix& operator-=(int x);

	Matrix operator+(const Matrix& sec) const;

	const Matrix operator+(int x) const;
	 
	const Matrix operator-(int x) const;

	const Matrix& operator-=(const Matrix& sec);

	Matrix operator-(const Matrix& sec) const;

	const Matrix operator*(const Matrix& sec) const;

	const Matrix operator*(int x) const;

	friend Matrix operator*(int x, const Matrix& sec);

	Matrix operator++(int);

	Matrix operator--(int);

	const Matrix& operator++();

	const Matrix& operator--();

	friend Matrix operator+(int x, const Matrix& sec);

	friend Matrix operator-(int x, const Matrix& sec);

	bool operator==(const Matrix& sec);

	bool operator!=(const Matrix& sec);

	Matrix operator/(const Matrix& sec) const;

	Matrix Inverse() const;

	const Matrix operator/(int x) const;

	friend Matrix operator/(int x, const Matrix& sec);

	const double Element(int x, int y) const;

	const int Size() const;

	Matrix Transpose() const;
};