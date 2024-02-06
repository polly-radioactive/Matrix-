#include <gtest/gtest.h>

#include "s21_matrix_oop.h"

TEST(test_constructor, test_1) {
  bool catch_ex = false;
  try {
    S21Matrix matrix6(0, 0);
  } catch (const logic_error& e) {
    std::cerr << e.what() << '\n';
    catch_ex = true;
  }
  ASSERT_EQ(catch_ex, true);
}

TEST(test_operator, test_1) {
  S21Matrix mat1(3, 3);
  vector<vector<double>> values_1 = {{0, 2, 3}, {4, 5, 6}, {7, 8, 9}};
  mat1.FillMatrix(values_1);

  S21Matrix mat2(3, 3);
  vector<vector<double>> values_2 = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
  mat2.FillMatrix(values_2);

  S21Matrix mat3(3, 3);
  vector<vector<double>> values_3 = {{1, 4, 6}, {8, 10, 12}, {14, 16, 18}};
  mat3.FillMatrix(values_3);

  S21Matrix res = mat1 + mat2;
  bool result = res.EqMatrix(mat3);

  ASSERT_EQ(result, 1);
}

TEST(test_operator, test_2) {
  S21Matrix mat1(3, 3);
  vector<vector<double>> values_1 = {{0, 2, 3}, {4, 5, 6}, {7, 8, 9}};
  mat1.FillMatrix(values_1);

  S21Matrix mat2(3, 3);
  vector<vector<double>> values_2 = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
  mat2.FillMatrix(values_2);

  S21Matrix mat3(3, 3);
  vector<vector<double>> values_3 = {{-1, 0, 0}, {0, 0, 0}, {0, 0, 0}};
  mat3.FillMatrix(values_3);

  S21Matrix res = mat1 - mat2;
  bool result = res.EqMatrix(mat3);

  ASSERT_EQ(result, 1);
}

TEST(test_operator, test_3) {
  S21Matrix mat1(2, 3);
  vector<vector<double>> values_1 = {{0, 2, 3}, {4, 5, 6}};
  mat1.FillMatrix(values_1);

  S21Matrix mat2(3, 3);
  vector<vector<double>> values_2 = {{10, 2, 3}, {4, 5, 6}, {7, 8, 9}};
  mat2.FillMatrix(values_2);

  S21Matrix mat3(2, 3);
  vector<vector<double>> values_3 = {{29, 34, 39}, {102, 81, 96}};
  mat3.FillMatrix(values_3);

  S21Matrix res = mat1 * mat2;
  bool result = res.EqMatrix(mat3);

  ASSERT_EQ(result, 1);
}

TEST(test_operator, test_4) {
  S21Matrix mat1(3, 3);
  vector<vector<double>> values_1 = {{3.33333357, 2, 3}, {4, 5, 6}, {7, 8, 9}};
  mat1.FillMatrix(values_1);

  S21Matrix mat2(3, 3);
  vector<vector<double>> values_2 = {{3.33333356, 2, 3}, {4, 5, 6}, {7, 8, 9}};
  mat2.FillMatrix(values_2);

  ASSERT_EQ(mat1 == mat2, 1);
}

TEST(test_operator, test_5) {
  S21Matrix mat1(3, 3);
  vector<vector<double>> values_1 = {{0, 2, 3}, {4, 5, 6}, {7, 8, 9}};
  mat1.FillMatrix(values_1);

  S21Matrix mat2(3, 3);
  vector<vector<double>> values_2 = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
  mat2.FillMatrix(values_2);

  S21Matrix mat3(3, 3);
  vector<vector<double>> values_3 = {{1, 4, 6}, {8, 10, 12}, {14, 16, 18}};
  mat3.FillMatrix(values_3);

  mat1 += mat2;
  bool result = mat1.EqMatrix(mat3);

  ASSERT_EQ(result, 1);
}

TEST(test_operator, test_6) {
  S21Matrix mat1(3, 3);
  vector<vector<double>> values_1 = {{0, 2, 3}, {4, 5, 6}, {7, 8, 9}};
  mat1.FillMatrix(values_1);

  S21Matrix mat2(3, 3);
  vector<vector<double>> values_2 = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
  mat2.FillMatrix(values_2);

  S21Matrix mat3(3, 3);
  vector<vector<double>> values_3 = {{-1, 0, 0}, {0, 0, 0}, {0, 0, 0}};
  mat3.FillMatrix(values_3);

  mat1 -= mat2;
  bool result = mat1.EqMatrix(mat3);

  ASSERT_EQ(result, 1);
}

TEST(test_operator, test_7) {
  S21Matrix mat2(3, 3);
  vector<vector<double>> values_2 = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
  mat2.FillMatrix(values_2);

  S21Matrix mat3(3, 3);
  vector<vector<double>> values_3 = {{2, 4, 6}, {8, 10, 12}, {14, 16, 18}};
  mat3.FillMatrix(values_3);

  mat2 *= 2;
  bool result = mat2.EqMatrix(mat3);

  ASSERT_EQ(result, 1);
}

TEST(test_operator, test_8) {
  S21Matrix mat1(2, 3);
  vector<vector<double>> values_1 = {{0, 2, 3}, {4, 5, 6}};
  mat1.FillMatrix(values_1);

  S21Matrix mat2(3, 3);
  vector<vector<double>> values_2 = {{10, 2, 3}, {4, 5, 6}, {7, 8, 9}};
  mat2.FillMatrix(values_2);

  S21Matrix mat3(2, 3);
  vector<vector<double>> values_3 = {{29, 34, 39}, {102, 81, 96}};
  mat3.FillMatrix(values_3);

  mat1 *= mat2;
  bool result = mat1.EqMatrix(mat3);

  ASSERT_EQ(result, 1);
}

TEST(test_operator, test_9) {
  S21Matrix A(2, 2);
  A(0, 0) = 2.987654;
  A(0, 1) = -5.3456;
  A(1, 0) = 6.23;
  A(1, 1) = -3.9292;

  S21Matrix B(2, 2);
  B(0, 0) = 4.838;
  B(0, 1) = 8.0987;
  B(1, 0) = -8;
  B(1, 1) = -0.921;

  S21Matrix C(2, 2);
  C(0, 0) = -1.850346;
  C(0, 1) = -13.4443;
  C(1, 0) = 14.23;
  C(1, 1) = -3.0082;

  A.SubMatrix(B);

  bool result = A.EqMatrix(C);
  ASSERT_EQ(result, 1);

  ASSERT_EQ(result, 1);
}

TEST(test_eq, EqMatrix_1) {
  S21Matrix mat1(3, 3);
  vector<vector<double>> values_1 = {{3.3333335, 2, 3}, {4, 5, 6}, {7, 8, 9}};
  mat1.FillMatrix(values_1);

  S21Matrix mat2(3, 3);
  vector<vector<double>> values_2 = {{3.33333356, 2, 3}, {4, 5, 6}, {7, 8, 9}};
  mat2.FillMatrix(values_2);

  ASSERT_EQ(mat1.EqMatrix(mat2), 1);
}

TEST(test_eq, EqMatrix_2) {
  S21Matrix mat1(3, 3);
  vector<vector<double>> values_1 = {{3.33333357, 2, 3}, {4, 5, 6}, {7, 8, 9}};
  mat1.FillMatrix(values_1);

  S21Matrix mat2(3, 3);
  vector<vector<double>> values_2 = {{3.33333356, 2, 3}, {4, 5, 6}, {7, 8, 9}};
  mat2.FillMatrix(values_2);

  ASSERT_EQ(mat1.EqMatrix(mat2), 1);
}

TEST(test_eq, EqMatrix_3) {
  S21Matrix mat1(3, 3);
  vector<vector<double>> values_1 = {{3.3333334, 2, 3}, {4, 5, 6}, {7, 8, 9}};
  mat1.FillMatrix(values_1);

  S21Matrix mat2(3, 3);
  vector<vector<double>> values_2 = {{3.3333335, 2, 3}, {4, 5, 6}, {7, 8, 9}};
  mat2.FillMatrix(values_2);

  ASSERT_EQ(mat1.EqMatrix(mat2), 0);
}

TEST(test_eq, EqMatrix_4) {
  S21Matrix mat1(3, 3);
  vector<vector<double>> values_1 = {{3.3333334, 2, 3}, {4, 5, 6}, {7, 8, 9}};
  mat1.FillMatrix(values_1);

  S21Matrix mat2(2, 3);
  vector<vector<double>> values_2 = {{0, 2, 3}, {4, 5, 6}};
  mat2.FillMatrix(values_2);

  ASSERT_EQ(mat1.EqMatrix(mat2), 0);
}

TEST(test_sum, SumMatrix_1) {
  S21Matrix mat1(3, 3);
  vector<vector<double>> values_1 = {{0, 2, 3}, {4, 5, 6}, {7, 8, 9}};
  mat1.FillMatrix(values_1);

  S21Matrix mat2(3, 3);
  vector<vector<double>> values_2 = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
  mat2.FillMatrix(values_2);

  S21Matrix mat3(3, 3);
  vector<vector<double>> values_3 = {{1, 4, 6}, {8, 10, 12}, {14, 16, 18}};
  mat3.FillMatrix(values_3);

  mat1.SumMatrix(mat2);
  bool result = mat1.EqMatrix(mat3);

  ASSERT_EQ(result, 1);
}

TEST(test_sum, SumMatrix_2) {
  S21Matrix mat1(3, 3);
  vector<vector<double>> values_1 = {{0, 2, 3}, {4, 5, 6}, {7, 8, 9}};
  mat1.FillMatrix(values_1);

  S21Matrix mat2;
  bool catch_ex = false;
  try {
    mat1.SumMatrix(mat2);
  } catch (const logic_error& e) {
    std::cerr << e.what() << '\n';
    catch_ex = true;
  }

  ASSERT_EQ(catch_ex, true);
}

TEST(test_sub, SubMatrix_1) {
  S21Matrix mat1(3, 3);
  vector<vector<double>> values_1 = {{0, 2, 3}, {4, 5, 6}, {7, 8, 9}};
  mat1.FillMatrix(values_1);

  S21Matrix mat2(3, 3);
  vector<vector<double>> values_2 = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
  mat2.FillMatrix(values_2);

  S21Matrix mat3(3, 3);
  vector<vector<double>> values_3 = {{-1, 0, 0}, {0, 0, 0}, {0, 0, 0}};
  mat3.FillMatrix(values_3);

  mat1.SubMatrix(mat2);
  bool result = mat1.EqMatrix(mat3);

  ASSERT_EQ(result, 1);
}

TEST(test_sub, SubMatrix_2) {
  S21Matrix mat1(3, 3);
  vector<vector<double>> values_1 = {{0, 2, 3}, {4, 5, 6}, {7, 8, 9}};
  mat1.FillMatrix(values_1);

  S21Matrix mat2;
  bool catch_ex = false;
  try {
    mat1.SubMatrix(mat2);
  } catch (const logic_error& e) {
    std::cerr << e.what() << '\n';
    catch_ex = true;
  }

  ASSERT_EQ(catch_ex, true);
}

TEST(test_mult, MultMatrix_1) {
  S21Matrix mat2(3, 3);
  vector<vector<double>> values_2 = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
  mat2.FillMatrix(values_2);

  S21Matrix mat3(3, 3);
  vector<vector<double>> values_3 = {{2, 4, 6}, {8, 10, 12}, {14, 16, 18}};
  mat3.FillMatrix(values_3);

  mat2.MulNumber(2);
  bool result = mat2.EqMatrix(mat3);

  ASSERT_EQ(result, 1);
}

TEST(test_mult, MultMatrix_2) {
  S21Matrix mat1(2, 3);
  vector<vector<double>> values_1 = {{0, 2, 3}, {4, 5, 6}};
  mat1.FillMatrix(values_1);

  S21Matrix mat2(3, 3);
  vector<vector<double>> values_2 = {{10, 2, 3}, {4, 5, 6}, {7, 8, 9}};
  mat2.FillMatrix(values_2);

  S21Matrix mat3(2, 3);
  vector<vector<double>> values_3 = {{29, 34, 39}, {102, 81, 96}};
  mat3.FillMatrix(values_3);

  mat1.MulMatrix(mat2);
  bool result = mat1.EqMatrix(mat3);

  ASSERT_EQ(result, 1);
}

TEST(test_mult, MultMatrix_3) {
  S21Matrix mat1(3, 3);
  vector<vector<double>> values_1 = {{0, 2, 3}, {4, 5, 6}, {7, 8, 9}};
  mat1.FillMatrix(values_1);

  S21Matrix mat2;
  bool catch_ex = false;
  try {
    mat1.MulMatrix(mat2);
  } catch (const logic_error& e) {
    std::cerr << e.what() << '\n';
    catch_ex = true;
  }

  ASSERT_EQ(catch_ex, true);
}

TEST(test_transpose, Transpose_1) {
  S21Matrix mat1(2, 3);
  vector<vector<double>> values_1 = {{0, 2, 3}, {4, 5, 6}};
  mat1.FillMatrix(values_1);

  S21Matrix mat2(3, 2);
  vector<vector<double>> values_2 = {{0, 4}, {2, 5}, {3, 6}};
  mat2.FillMatrix(values_2);

  S21Matrix res = mat1.Transpose();
  bool result = res.EqMatrix(mat2);

  ASSERT_EQ(result, 1);
}

TEST(test_det, Determinant_1) {
  S21Matrix mat1(3, 3);
  vector<vector<double>> values_1 = {{100, 2, 3}, {4, 50, 6}, {7, 8, 9}};
  mat1.FillMatrix(values_1);
  int result = mat1.Determinant();
  ASSERT_EQ(result, 39258);
}

TEST(test_det, Determinant_2) {
  S21Matrix mat1(3, 3);
  vector<vector<double>> values_1 = {{0, 2, 3}, {4, 5, 6}, {7, 8, 9}};
  mat1.FillMatrix(values_1);
  int result = mat1.Determinant();
  ASSERT_EQ(result, 3);
}

TEST(test_det, Determinant_3) {
  S21Matrix mat1(1, 1);
  vector<vector<double>> values_1 = {{100}};
  mat1.FillMatrix(values_1);
  int result = mat1.Determinant();
  ASSERT_EQ(result, 100);
}

TEST(test_det, Determinant_4) {
  S21Matrix mat1(2, 1);
  bool catch_ex = false;
  try {
    mat1.Determinant();
  } catch (const logic_error& e) {
    std::cerr << e.what() << '\n';
    catch_ex = true;
  }
  ASSERT_EQ(catch_ex, true);
}

TEST(test_calc, CalcComplements_1) {
  S21Matrix mat1(2, 1);
  bool catch_ex = false;
  try {
    mat1.CalcComplements();
  } catch (const logic_error& e) {
    std::cerr << e.what() << '\n';
    catch_ex = true;
  }
  ASSERT_EQ(catch_ex, true);
}

TEST(test_calc, CalcComplements_2) {
  S21Matrix mat1(1, 1);
  vector<vector<double>> values_1 = {{100}};
  mat1.FillMatrix(values_1);

  S21Matrix check(1, 1);
  vector<vector<double>> values_2 = {{1}};
  check.FillMatrix(values_2);

  S21Matrix res = mat1.CalcComplements();

  bool result = res.EqMatrix(check);
  ASSERT_EQ(result, 1);
}

TEST(test_calc, CalcComplements_3) {
  S21Matrix mat1(3, 3);
  vector<vector<double>> values_1 = {{1, 2, 3}, {0, 4, 2}, {5, 2, 1}};
  mat1.FillMatrix(values_1);

  S21Matrix check(3, 3);
  vector<vector<double>> values_2 = {{0, 10, -20}, {4, -14, 8}, {-8, -2, 4}};
  check.FillMatrix(values_2);

  S21Matrix res = mat1.CalcComplements();

  bool result = res.EqMatrix(check);
  ASSERT_EQ(result, 1);
}

TEST(test_inverse, Inverse_1) {
  S21Matrix mat1(3, 3);
  vector<vector<double>> values_1 = {{2, 5, 7}, {6, 3, 4}, {5, -2, -3}};
  mat1.FillMatrix(values_1);

  S21Matrix check(3, 3);
  vector<vector<double>> values_2 = {{1, -1, 1}, {-38, 41, -34}, {27, -29, 24}};
  check.FillMatrix(values_2);

  S21Matrix res = mat1.InverseMatrix();

  bool result = res.EqMatrix(check);
  ASSERT_EQ(result, 1);
}

TEST(test_calc, Inverse_2) {
  S21Matrix mat1(2, 1);
  bool catch_ex = false;
  try {
    mat1.InverseMatrix();
  } catch (const logic_error& e) {
    std::cerr << e.what() << '\n';
    catch_ex = true;
  }
  ASSERT_EQ(catch_ex, true);
}

TEST(test_calc, Inverse_3) {
  S21Matrix mat1(2, 2);
  bool catch_ex = false;
  try {
    mat1.InverseMatrix();
  } catch (const logic_error& e) {
    std::cerr << e.what() << '\n';
    catch_ex = true;
  }
  ASSERT_EQ(catch_ex, true);
}

TEST(test_help, Help_1) {
  S21Matrix mat1(1, 1);
  vector<vector<double>> values_2 = {{1, -1, 1}, {-38, 41, -34}, {27, -29, 24}};
  bool catch_ex = false;
  try {
    mat1.FillMatrix(values_2);
  } catch (const logic_error& e) {
    std::cerr << e.what() << '\n';
    catch_ex = true;
  }
  ASSERT_EQ(catch_ex, true);
}

TEST(test_mutator, Mutator_1) {
  S21Matrix A(2, 2);
  A(0, 0) = 3;
  A(0, 1) = -5;
  A(1, 0) = 6;
  A(1, 1) = 3;

  A.setCols(3);
  ASSERT_EQ(A.getCols(), 3);
  ASSERT_EQ(A(1, 2), 0);
}

TEST(test_mutator, Mutator_2) {
  S21Matrix A(2, 2);
  A(0, 0) = 3;
  A(0, 1) = -5;
  A(1, 0) = 6;
  A(1, 1) = 3;

  A.setRows(3);
  ASSERT_EQ(A.getRows(), 3);
  ASSERT_EQ(A(2, 0), 0);
}

int main(int argc, char* argv[]) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}