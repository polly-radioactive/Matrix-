#include "s21_matrix_oop.h"

// Базовый конструктор, инициализирующий матрицу некоторой заранее заданной
// размерностью.
S21Matrix::S21Matrix() : rows_(0), cols_(0), matrix_(nullptr) {}

// Параметризированный конструктор с количеством строк и столбцов.
S21Matrix::S21Matrix(int rows, int cols) : rows_(rows), cols_(cols) {
  if (rows_ < 1 || cols_ < 1)
    throw logic_error("Значение столбцов и строк матрицы должно быть больше 0");
  matrix_ = new double *[rows_]();
  for (int i = 0; i < rows_; i++) {
    matrix_[i] = new double[cols_]();
  }
};

// Конструктор копирования.
S21Matrix::S21Matrix(const S21Matrix &other) {
  rows_ = other.rows_;
  cols_ = other.cols_;
  matrix_ = new double *[rows_]();
  for (int i = 0; i < rows_; i++) {
    matrix_[i] = new double[cols_];
  }
  for (int i = 0; i < rows_; i++)
    for (int j = 0; j < cols_; j++) matrix_[i][j] = other.matrix_[i][j];
}

// Конструктор переноса.
S21Matrix::S21Matrix(S21Matrix &&other)
    : rows_(other.rows_), cols_(other.cols_), matrix_(other.matrix_) {
  other.matrix_ = nullptr;
  other.rows_ = 0;
  other.cols_ = 0;
}

// Деструктор
S21Matrix::~S21Matrix() {
  delete[] matrix_;  // Destructor to free the allocated memory
}

// Mutator
void S21Matrix::setRows(int newRows) {
  if (newRows > rows_) {
    double **newMatrix = new double *[newRows];
    for (int i = 0; i < newRows; i++) {
      newMatrix[i] = new double[cols_];
      for (int j = 0; j < cols_; j++) {
        newMatrix[i][j] = (i < rows_) ? matrix_[i][j] : 0;
      }
    }
    for (int i = 0; i < rows_; i++) {
      delete[] matrix_[i];
    }
    delete[] matrix_;
    matrix_ = newMatrix;
  }
  rows_ = newRows;
}

void S21Matrix::setCols(int newCols) {
  if (newCols > cols_) {
    for (int i = 0; i < rows_; i++) {
      double *newMatrixRow = new double[newCols];
      for (int j = 0; j < newCols; j++) {
        newMatrixRow[j] = (j < cols_) ? matrix_[i][j] : 0;
      }
      delete[] matrix_[i];
      matrix_[i] = newMatrixRow;
    }
  }
  cols_ = newCols;
}

// Accessors
int S21Matrix::getRows() const { return rows_; }
int S21Matrix::getCols() const { return cols_; }

// Сложение двух матриц.
S21Matrix S21Matrix::operator+(const S21Matrix &other) {
  this->SumMatrix(other);
  S21Matrix result = *this;
  return result;
}

// Вычитание одной матрицы из другой.
S21Matrix S21Matrix::operator-(const S21Matrix &other) {
  this->SubMatrix(other);
  S21Matrix result = *this;
  return result;
}

// Умножение матриц и умножение матрицы на число.
S21Matrix S21Matrix::operator*(double value) {
  this->MulNumber(value);
  S21Matrix result = *this;
  return result;
}
S21Matrix S21Matrix::operator*(const S21Matrix other) {
  this->MulMatrix(other);
  S21Matrix result = *this;
  return result;
}

// Проверка на равенство матриц (EqMatrix).
bool S21Matrix::operator==(const S21Matrix &other) {
  bool t = false;
  if (this->EqMatrix(other)) t = true;
  return t;
}

// Присвоение матрице значений другой матрицы.
S21Matrix &S21Matrix::operator=(const S21Matrix &other) {
  rows_ = other.rows_;
  cols_ = other.cols_;
  this->matrix_ = new double *[rows_]();
  for (int i = 0; i < rows_; i++) {
    this->matrix_[i] = new double[other.cols_]();
  }

  for (int i = 0; i < rows_; ++i) {
    for (int j = 0; j < cols_; ++j) {
      matrix_[i][j] = other.matrix_[i][j];
    }
  }

  return *this;
}

// Присвоение сложения (SumMatrix).
void S21Matrix::operator+=(const S21Matrix &other) { this->SumMatrix(other); }

// Присвоение разности (SubMatrix).
void S21Matrix::operator-=(const S21Matrix &other) { this->SubMatrix(other); }

// Присвоение умножения (MulMatrix/MulNumber).
void S21Matrix::operator*=(const S21Matrix &other) { this->MulMatrix(other); }
void S21Matrix::operator*=(double value) { this->MulNumber(value); }

// Индексация по элементам матрицы (строка, колонка).
double &S21Matrix::operator()(int i, int j) { return matrix_[i][j]; }

void S21Matrix::FillMatrix(const vector<vector<double>> &values) {
  if (values.size() != static_cast<size_t>(rows_) ||
      values[0].size() != static_cast<size_t>(cols_)) {
    throw logic_error(
        "Ошибка: Размеры переданной матрицы не соответствуют размерам "
        "текущей матрицы.");
    return;
  }

  for (int i = 0; i < rows_; i++) {
    for (int j = 0; j < cols_; j++) {
      matrix_[i][j] = values[i][j];
    }
  }
}

// void S21Matrix::PrintMatrix() {
//   for (int i = 0; i < rows_; i++) {
//     for (int j = 0; j < cols_; j++) {
//       cout << matrix_[i][j] << " ";
//     }
//     cout << endl;
//   }
// }

// Проверяет матрицы на равенство между собой.
bool S21Matrix::EqMatrix(const S21Matrix &other) {
  if (rows_ != other.getRows() || cols_ != other.getCols()) {
    return false;
  }

  for (int i = 0; i < rows_; i++) {
    for (int j = 0; j < cols_; j++) {
      if (fabs(matrix_[i][j] - other.matrix_[i][j]) > eps) {
        return false;
      }
    }
  }
  return true;
}

// Прибавляет вторую матрицы к текущей
void S21Matrix::SumMatrix(const S21Matrix &other) {
  if (rows_ != other.getRows() || cols_ != other.getCols()) {
    throw logic_error("Ошибка: Сложение матриц разных размеров невозможно.");
    return;
  }
  for (int i = 0; i < rows_; i++) {
    for (int j = 0; j < cols_; j++) {
      matrix_[i][j] += other.matrix_[i][j];
    }
  }
}

// Вычитает из текущей матрицы другую
void S21Matrix::SubMatrix(const S21Matrix &other) {
  if (rows_ != other.getRows() || cols_ != other.getCols()) {
    throw logic_error("Ошибка: Вычитание матриц разных размеров невозможно.");
    return;
  }

  for (int i = 0; i < rows_; i++) {
    for (int j = 0; j < cols_; j++) {
      matrix_[i][j] -= other.matrix_[i][j];
    }
  }
}

// Умножает текущую матрицу на число.
void S21Matrix::MulNumber(const double num) {
  for (int i = 0; i < rows_; i++) {
    for (int j = 0; j < cols_; j++) {
      matrix_[i][j] *= num;
    }
  }
}

// Умножает текущую матрицу на вторую.
void S21Matrix::MulMatrix(const S21Matrix &other) {
  if (cols_ != other.getRows()) {
    throw logic_error(
        "Ошибка: Перемножение матриц разных размеров невозможно: число "
        "столбцов первой матрицы не равно числу строк второй матрицы. ");
    return;
  }
  S21Matrix result(rows_, other.getCols());

  for (int i = 0; i < rows_; i++) {
    for (int j = 0; j < other.getCols(); j++) {
      for (int k = 0; k < other.getRows(); k++) {
        result.matrix_[i][j] += matrix_[i][k] * other.matrix_[k][j];
      }
    }
  }
  *this = result;
}

// Создает новую транспонированную матрицу из текущей и возвращает ее.
S21Matrix S21Matrix::Transpose() {
  S21Matrix result(cols_, rows_);
  for (int i = 0; i < cols_; i++) {
    for (int j = 0; j < rows_; j++) {
      result.matrix_[i][j] = matrix_[j][i];
    }
  }
  return result;
}

double S21Matrix::Determinant() {
  double det = 0;
  int n = rows_;
  if (rows_ != cols_) {
    throw logic_error(
        "Матрица должна быть квадратной для вычисления определителя.");
  } else {
    if (n == 1) {
      return matrix_[0][0];
    }

    if (n == 2) {
      return matrix_[0][0] * matrix_[1][1] - matrix_[0][1] * matrix_[1][0];
    } else {
      S21Matrix minor(n - 1, n - 1);
      for (int i = 0; i < n; i++) {
        for (int j = 1; j < n; j++) {
          for (int k = 0; k < i; k++) {
            minor.matrix_[j - 1][k] = matrix_[j][k];
          }
          for (int k = i + 1; k < n; k++) {
            minor.matrix_[j - 1][k - 1] = matrix_[j][k];
          }
        }
        det += (i % 2 == 0 ? 1 : -1) * matrix_[0][i] * minor.Determinant();
      }
      return det;
    }
  }
}

// Вычисляет матрицу алгебраических дополнений текущей матрицы и возвращает
// ее.
S21Matrix S21Matrix::CalcComplements() {
  int n = rows_;
  if (rows_ != cols_) {
    throw logic_error(
        "Матрица должна быть квадратной для вычисления определителя.");
  } else {
    S21Matrix result(n, n);
    if (n == 1) {
      result.matrix_[0][0] = 1;
    } else {
      S21Matrix C(n - 1, n - 1);
      int sign;
      for (int x = 0; x < n; x++) {
        for (int y = 0; y < n; y++) {
          int row_idx = 0;
          for (int row = 0; row < n; row++) {
            if (row == x) continue;
            int col_idx = 0;
            for (int col = 0; col < n; col++) {
              if (col == y) continue;
              C.matrix_[row_idx][col_idx] = matrix_[row][col];
              col_idx++;
            }
            row_idx++;
          }
          if ((x + y) % 2 == 0) {
            sign = 1;
          } else {
            sign = -1;
          }
          result.matrix_[x][y] = sign * C.Determinant();
        }
      }
    }
    return result;
  }
}

// Вычисляет и возвращает обратную матрицу.
S21Matrix S21Matrix::InverseMatrix() {
  if (rows_ != cols_) {
    throw logic_error(
        "Матрица должна быть квадратной для вычисления определителя.");
  } else {
    double det = this->Determinant();
    if (det == 0) {
      throw logic_error("Y матрицы 0 детерминант");
    }
    S21Matrix temp = this->CalcComplements();
    S21Matrix trans_temp = temp.Transpose();
    S21Matrix result = trans_temp * (1 / det);
    return trans_temp;
  }
}
