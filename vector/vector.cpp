

#include "pch.h"
#include <iostream>
#include <cstring>


class matrix {

protected:
	int rows;
	int columns;
	double matr[10][10] = { {0} };

public:
	matrix();
	~matrix();

	bool input();
	void print();
	bool summMatrix(matrix matr2);
	bool multMatrix(matrix matr2);
	bool transp();

	int getRows();
	int getColumns();
	double getElem(int row, int col);
};

class  vector : public matrix
{   public:

	/* int *vec = new int[n];
	int n;
	vector();
	~vector();
	int getN() { return n; }
	int getEl(int i);
	bool enter();
	void kvec(int k)
	{
		for (int i = 0; i < n; i++)
		{
			vec[i] *= k;
			std::cout << vec[i] << ' ';
		}
	}; */
	bool multvec(vector vec2);
};

/*vector::vector() {}
vector::~vector() {} */



matrix::matrix()
{
}

matrix::~matrix()
{
}

bool matrix::input()
{
	std::cout << "number of rows:";
	std::cin >> rows;
	if (rows < 1 || rows>10)
		return false;
	std::cout << "number of columns:";
	std::cin >> columns;
	if (columns < 1 || columns>10)
		return false;
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < columns; j++) {
			std::cin >> matr[i][j];
		}
	}
	return true;
}

void matrix::print()
{
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < columns; j++) {
			std::cout << matr[i][j] << '\t';
		}
		std::cout << '\n';
	}
}

bool matrix::summMatrix(matrix matr2)
{
	std::cout << "summ:\n";
	double result[10][10];
	if ((rows == matr2.getRows()) && (columns == matr2.getColumns())) {
		for (int i = 0; i < rows; i++) {
			for (int j = 0; j < columns; j++) {
				result[i][j] = matr[i][j] + matr2.getElem(i, j);
				std::cout << result[i][j] << '\t';
			}
			std::cout << std::endl;
		}
		return true;
	}
	else return false;
}

bool matrix::multMatrix(matrix matr2)
{
	std::cout << "mult\n";
	double matr3[10][10];
	if (columns == matr2.getRows()) {
		for (int i = 0; i < rows; i++) {
			for (int j = 0; j < rows; j++) {
				double sum = 0;
				for (int k = 0; k < matr2.getColumns(); k++) {
					sum += matr[i][k] * matr2.getElem(k, j);
				}
				matr3[i][j] = sum;
				std::cout << matr3[i][j] << '\t';
			}
			std::cout << std::endl;
		}
		return true;
	}
	else return false;
	std::cout << "error!";
}
 
bool matrix::transp() //ПОЧЕМУ ТРАНСПОНИРУЕТ В СТРОКУ?
{
	std::cout << "transp:\t";
	int ch;
	if (rows != columns) {
		ch = rows;
		rows = columns;
		columns = ch;
	}
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < columns; j++) {
			
			std::cout << matr[j][i] << "\t";
		}
	}

	return true;
} 

int matrix::getRows()
{
	return rows;
}

int matrix::getColumns()
{
	return columns;
}

double matrix::getElem(int row, int col)
{
	if (row<rows && col<columns && row>-1 && col>-1)
		return matr[row][col];
	else
		return -11111111111;
	std::cout << "Error!\n";
	return -1;
}
int main()
{
	matrix matA, matB;
	matA.input();
	matB.input(); 
	vector vecA, vecB;
	vecB.input();
	vecA.input();
	//matA.print();

	/*matA.summMatrix(matB);//matA = matA + matB
	matA.multMatrix(matB);
	matA.transp();
	matB.transp(); */
	vecA.multvec(vecB);
	return 0;
}
  
bool vector::multvec(vector vec2)
{
	int scal = 0;
	if (columns = vec2.getRows()) {
		for (int i = 0; i < rows; i++)
		{
			scal += matr[i][0] * vec2.getElem(i, 0);
		}
		std::cout <<"vector mult:"<< scal;
		

		return true;
	}
	else { return false; }
}

/*bool vector::enter()
{
	std::cout << "n=";
	std::cin >> n;
	for (int j = 0; j < n; j++)
	{
		std::cout << "vector" << j << "=";
		std::cin >> vec[j];
	}
	return true;
}

int vector::getEl(int i)
{
	if (i > -1 && i < n) { return vec[i]; }
	else
	{
		std::cout << "error!";
		return -1;
	}
} 
*/
