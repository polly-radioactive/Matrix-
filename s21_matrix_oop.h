#include <cmath>
#include <iostream>
#include <vector>
#define eps 1e-7
using namespace std;

class S21Matrix {
 private:
  int rows_, cols_;
  double **matrix_;

 public:
  S21Matrix();
  S21Matrix(int rows, int cols);
  S21Matrix(const S21Matrix &other);
  S21Matrix(S21Matrix &&other);
  ~S21Matrix();

  // Mutator
  void setRows(int newRows);
  void setCols(int newCols);

  // Accessors
  int getRows() const;
  int getCols() const;

  // methods
  bool EqMatrix(const S21Matrix &other);
  void SumMatrix(const S21Matrix &other);
  void SubMatrix(const S21Matrix &other);
  void MulNumber(const double num);
  void MulMatrix(const S21Matrix &other);
  S21Matrix Transpose();
  double Determinant();
  S21Matrix CalcComplements();
  S21Matrix InverseMatrix();

  // operators
  S21Matrix &operator=(const S21Matrix &other);
  S21Matrix operator+(const S21Matrix &other);
  S21Matrix operator-(const S21Matrix &other);
  bool operator==(const S21Matrix &other);
  double &operator()(int i, int j);
  S21Matrix operator*(const S21Matrix other);
  S21Matrix operator*(double value);
  void operator+=(const S21Matrix &other);
  void operator-=(const S21Matrix &other);
  void operator*=(const S21Matrix &other);
  void operator*=(double value);

  // helpful function
  void FillMatrix(const vector<vector<double>> &values);
  void PrintMatrix();
};
