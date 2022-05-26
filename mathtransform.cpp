#include "mathtransform.h"

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
		for (int j = 0;j < 3; j++) {
			for (int x = 0;x < 3; x++) {
				result[i][j] += matrix1[i][x] * matrix2[x][j];
			}
		}
	}

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
		for (int j = 0;j < 3; j++) {
			for (int x = 0;x < 3; x++) {
				result[i][j] += matrix1[i][x] * matrix2[x][j];
			}
		}
	}

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
		for (int j = 0;j < 3; j++) {
			for (int x = 0;x < 3; x++) {
				result[i][j] += matrix1[i][x] * matrix2[x][j];
			}
		}
	}

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
		for (int j = 0;j < 3; j++) {
			for (int x = 0;x < 3; x++) {
				result[i][j] += matrix1[i][x] * matrix2[x][j];
			}
		}
	}

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
		for (int j = 0;j < 3; j++) {
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
		for (int j = 0;j < 3; j++) {
			for (int x = 0;x < 3; x++) {
				result[i][j] += matrix1[i][x] * matrix2[x][j];
			}
		}
	}

	return result;
}

float** rotateAroundAxis(float** matrix, float angle, char axis, int rowsNumber)
{
	switch (axis) {
		case 'x' :
			float rotationMatrix[3][3] = { {1, 0, 0},
										   {0, cos(angle), -sin(angle)},
				                           {0, sin(angle), cos(angle)} };
			return multiplyMatrices(matrix, rotationMatrix, rowsNumber, 3);
			// no break;

		case 'y' :
			float rotationMatrix[3][3] = { {cos(angle), 0, sin(angle)},
										   {0, 1, 0}, 
										   {-sin(angle), 0, cos(angle)} };
			return multiplyMatrices(matrix, rotationMatrix, rowsNumber, 3);
			// no break;

		case 'z':
			float rotationMatrix[3][3] = { {cos(angle), -sin(angle), 0},
										   {sin(angle), cos(angle), 0},
										   {0, 0, 1} };
			return multiplyMatrices(matrix, rotationMatrix, rowsNumber, 3);
			// no break;
		default:
			return nullptr;
			// no break;
	};
}

float** rotateAroundAxis(float(*matrix)[3], float angle, char axis, int rowsNumber)
{
	switch (axis) {
	case 'x':
		float rotationMatrix[3][3] = { {1, 0, 0},
									   {0, cos(angle), -sin(angle)},
									   {0, sin(angle), cos(angle)} };
		return multiplyMatrices(matrix, rotationMatrix, rowsNumber, 3);
		// no break;

	case 'y':
		float rotationMatrix[3][3] = { {cos(angle), 0, sin(angle)},
									   {0, 1, 0},
									   {-sin(angle), 0, cos(angle)} };
		return multiplyMatrices(matrix, rotationMatrix, rowsNumber, 3);
		// no break;

	case 'z':
		float rotationMatrix[3][3] = { {cos(angle), -sin(angle), 0},
									   {sin(angle), cos(angle), 0},
									   {0, 0, 1} };
		return multiplyMatrices(matrix, rotationMatrix, rowsNumber, 3);
		// no break;
	default:
		return nullptr;
		// no break;
	};
}
