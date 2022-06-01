#include "mathtransform.h"

float transitionMatrix2new[3][3] = { { 0.685663, 0.704416, 0.183480},
									 {-0.707066, 0.704416, -0.0620957},
									 { -0.172987, -0.0871557, 0.981060} };
float transitionMatrix2old[3][3] = { { 0.6856623, -0.7070656, -0.1729874},
									 {0.7044159, 0.7044161, -0.0871557},
									 { 0.1834796, -0.0620953, -0.9810605} };

float** multiplyMatrices(float **matrix1, float**matrix2, int rowsNumber, int columnsNumber)
{
	float** result;
	result = new float* [rowsNumber];
	for (int i = 0; i < rowsNumber; i++)
		result[i] = new float[columnsNumber];

	for (int i = 0;i < rowsNumber;i++) {
		for (int j = 0;j < columnsNumber; j++) {
			result[i][j] = 0.0;
		}
	}

	for (int i = 0;i < rowsNumber;i++) {
		for (int j = 0;j < columnsNumber; j++) {
			for (int x = 0;x < 3; x++) {
				result[i][j] += matrix1[i][x] * matrix2[x][j];
			}
		}
	}
	for (int i = 0;i < rowsNumber;i++)
		delete[] matrix1[i];
	delete[] matrix1;
	for (int i = 0;i < 3;i++)
		delete[] matrix2[i];
	delete[] matrix2;
	return result;
}

float** multiplyMatrices(float(*matrix1)[3], float** matrix2, int rowsNumber, int columnsNumber)
{
	float** result;
	result = new float* [rowsNumber];
	for (int i = 0; i < rowsNumber; i++)
		result[i] = new float[columnsNumber];

	for (int i = 0;i < rowsNumber;i++) {
		for (int j = 0;j < columnsNumber; j++) {
			result[i][j] = 0.0;
		}
	}

	for (int i = 0;i < rowsNumber;i++) {
		for (int j = 0;j < columnsNumber; j++) {
			for (int x = 0;x < 3; x++) {
				result[i][j] += matrix1[i][x] * matrix2[x][j];
			}
		}
	}
	for (int i = 0;i < 3;i++)
		delete[] matrix2[i];
	delete[] matrix2;
	return result;
}

float** multiplyMatrices(float** matrix1, float(*matrix2)[3], int rowsNumber, int columnsNumber)
{
	float** result;
	result = new float* [rowsNumber];
	for (int i = 0; i < rowsNumber; i++)
		result[i] = new float[columnsNumber];

	for (int i = 0;i < rowsNumber;i++) {
		for (int j = 0;j < columnsNumber; j++) {
			result[i][j] = 0.0;
		}
	}

	for (int i = 0;i < rowsNumber;i++) {
		for (int j = 0;j < columnsNumber; j++) {
			for (int x = 0;x < 3; x++) {
				result[i][j] += matrix1[i][x] * matrix2[x][j];
			}
		}
	}
	for (int i = 0;i < rowsNumber;i++)
		delete[] matrix1[i];
	delete[] matrix1;
	return result;
}

float** multiplyMatrices(float** matrix1, float(*matrix2)[1], int rowsNumber, int columnsNumber)
{
	float** result;
	result = new float* [rowsNumber];
	for (int i = 0; i < rowsNumber; i++)
		result[i] = new float[columnsNumber];

	for (int i = 0;i < rowsNumber;i++) {
		for (int j = 0;j < columnsNumber; j++) {
			result[i][j] = 0.0;
		}
	}

	for (int i = 0;i < rowsNumber;i++) {
		for (int j = 0;j < columnsNumber; j++) {
			for (int x = 0;x < 3; x++) {
				result[i][j] += matrix1[i][x] * matrix2[x][j];
			}
		}
	}
	for (int i = 0;i < rowsNumber;i++)
		delete[] matrix1[i];
	delete[] matrix1;
	return result;
}

float** multiplyMatrices(float (*matrix1)[3], float (*matrix2)[3], int rowsNumber, int columnsNumber)
{
	float** result;
	result = new float* [rowsNumber];
	for (int i = 0; i < rowsNumber; i++)
		result[i] = new float[columnsNumber];

	for (int i = 0;i < rowsNumber;i++) {
		for (int j = 0;j < columnsNumber; j++) {
			result[i][j] = 0.0;
		}
	}

	for (int i = 0;i < rowsNumber;i++) {
		for (int j = 0;j < columnsNumber; j++) {
			for (int x = 0;x < 3; x++) {
				result[i][j] += matrix1[i][x] * matrix2[x][j];
			}
		}
	}
	return result;
}

float** multiplyMatrices(float(*matrix1)[3], float(*matrix2)[1], int rowsNumber, int columnsNumber)
{
	float** result;
	result = new float* [rowsNumber];
	for (int i = 0; i < rowsNumber; i++)
		result[i] = new float[columnsNumber];

	for (int i = 0;i < rowsNumber;i++) {
		for (int j = 0;j < columnsNumber; j++) {
			result[i][j] = 0.0;
		}
	}

	for (int i = 0;i < rowsNumber;i++) {
		for (int j = 0;j < columnsNumber; j++) {
			for (int x = 0;x < 3; x++) {
				result[i][j] += matrix1[i][x] * matrix2[x][j];
			}
		}
	}
	
	return result;
}

float** rotateAroundAxisOld(float** matrix, float angle, char axis, int rowsNumber)
{
	if (axis == 'x') {
		float rotationMatrix[3][3] = { {1, 0, 0},
									   {0, cos(angle), -sin(angle)},
			                           {0, sin(angle), cos(angle)}, };
		return multiplyMatrices(matrix, rotationMatrix, rowsNumber, 3);
	}
	else if (axis == 'y') {
		float rotationMatrix[3][3] = { {cos(angle), 0, sin(angle)},
										{0, 1, 0},
										{-sin(angle), 0, cos(angle)} };
		return multiplyMatrices(matrix, rotationMatrix, rowsNumber, 3);
	}
	else if (axis == 'z') {
		float rotationMatrix[3][3] = { {cos(angle), -sin(angle), 0},
										{sin(angle), cos(angle), 0},
										{0, 0, 1} };
		return multiplyMatrices(matrix, rotationMatrix, rowsNumber, 3);
	}
	else {
		return nullptr;
	}
}

float** rotateAroundAxisOld(float(*matrix)[3], float angle, char axis, int rowsNumber)
{
	if (axis == 'x') {
		float rotationMatrix[3][3] = { {1, 0, 0},
									   {0, cos(angle), -sin(angle)},
									   {0, sin(angle), cos(angle)}, };
		return multiplyMatrices(matrix, rotationMatrix, rowsNumber, 3);
	}
	else if (axis == 'y') {
		float rotationMatrix[3][3] = { {cos(angle), 0, sin(angle)},
										{0, 1, 0},
										{-sin(angle), 0, cos(angle)} };
		return multiplyMatrices(matrix, rotationMatrix, rowsNumber, 3);
	}
	else if (axis == 'z') {
		float rotationMatrix[3][3] = { {cos(angle), -sin(angle), 0},
										{sin(angle), cos(angle), 0},
										{0, 0, 1} };
		return multiplyMatrices(matrix, rotationMatrix, rowsNumber, 3);
	}
	else {
		return nullptr;
	}
}

float** rotateAroundAxisNew(float** matrix, float angle, char axis, int rowsNumber)
{
	matrix = multiplyMatrices(matrix, transitionMatrix2new, rowsNumber, 3);
	if (axis == 'x') {
		float rotationMatrix[3][3] = { {1, 0, 0},
									   {0, cos(angle), -sin(angle)},
									   {0, sin(angle), cos(angle)}, };
		matrix = multiplyMatrices(matrix, rotationMatrix, rowsNumber, 3);
		
	}
	else if (axis == 'y') {
		float rotationMatrix[3][3] = { {cos(angle), 0, sin(angle)},
										{0, 1, 0},
										{-sin(angle), 0, cos(angle)} };
		matrix = multiplyMatrices(matrix, rotationMatrix, rowsNumber, 3);
	}
	else if (axis == 'z') {
		float rotationMatrix[3][3] = { {cos(angle), -sin(angle), 0},
										{sin(angle), cos(angle), 0},
										{0, 0, 1} };
		matrix = multiplyMatrices(matrix, rotationMatrix, rowsNumber, 3);
	}
	else {
		return nullptr;
	}
	return multiplyMatrices(matrix, transitionMatrix2old, rowsNumber, 3);
}

float** rotateAroundAxisNew(float(*matrix)[3], float angle, char axis, int rowsNumber)
{
	float** Matrix = multiplyMatrices(matrix, transitionMatrix2new, rowsNumber, 3);
	if (axis == 'x') {
		float rotationMatrix[3][3] = { {1, 0, 0},
									   {0, cos(angle), -sin(angle)},
									   {0, sin(angle), cos(angle)}, };
		Matrix = multiplyMatrices(Matrix, rotationMatrix, rowsNumber, 3);

	}
	else if (axis == 'y') {
		float rotationMatrix[3][3] = { {cos(angle), 0, sin(angle)},
										{0, 1, 0},
										{-sin(angle), 0, cos(angle)} };
		Matrix = multiplyMatrices(Matrix, rotationMatrix, rowsNumber, 3);
	}
	else if (axis == 'z') {
		float rotationMatrix[3][3] = { {cos(angle), -sin(angle), 0},
										{sin(angle), cos(angle), 0},
										{0, 0, 1} };
		Matrix = multiplyMatrices(Matrix, rotationMatrix, rowsNumber, 3);
	}
	else {
		return nullptr;
	}
	return multiplyMatrices(Matrix, transitionMatrix2old, rowsNumber, 3);
}

float** rotate2default(float** matrix, int rowsNumber)
{
	float** result;
	result = rotateAroundAxisOld(matrix, -10.0 * M_PI / 180.0, 'y', rowsNumber);
	result = rotateAroundAxisOld(result, 5.0 * M_PI / 180.0, 'x', rowsNumber);

	delete[] matrix;
	return rotateAroundAxisOld(result, 45.0 * M_PI / 180.0, 'z', rowsNumber);
}

float** rotate2default(float(*matrix)[3], int rowsNumber)
{
	float** result;
	result = rotateAroundAxisOld(matrix, -10.0 * M_PI / 180.0, 'y', rowsNumber);
	result = rotateAroundAxisOld(result, 5.0 * M_PI / 180.0, 'x', rowsNumber);
	return rotateAroundAxisOld(result, 45.0 * M_PI / 180.0, 'z', rowsNumber);
}
