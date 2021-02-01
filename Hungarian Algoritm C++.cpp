// Muhammed Kaðan Erdoðan 
// Hungarian Algoritm C++ Code
// 19.5.2020
// Tested http://www.hungarianalgorithm.com/solve.php

#include<iostream>
#include<ctime>
#include<time.h>
#define size 4
using namespace std;

void coverZeros();
void coverZeros2();
int maxVh(int row, int col);
void marked(int row, int col, int maxVh);
void unmarked(int row, int col, int maxVh);
void Addzero();
void print_matrix(int[][size]);
int A[size][size];
int random()
{
	srand(time(0));
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			A[i][j] = rand() % 100;
		}
	}
	return 1;
}
int B[size], C[size], D[size][size], E[size][size], F[size][size], G[size][size], H[size][size], A2[size][size];
int numLines;
void main() 
{
	random();
	int colmin,rowmin;
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			A2[i][j] = A[i][j];
		}
	}
	cout << "MATRIX" << endl;
	cout << "-----------" << endl;
	print_matrix(A);
	cout << endl << endl;
	rowmin = A[0][0];
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			if (rowmin>A[i][j])
			{
				rowmin = A[i][j];
			}
		}
		cout << rowmin << "\t";
		B[i] = rowmin;
		rowmin = A[i+1][0];
	}
	cout << endl << endl;
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			A[i][j] = A[i][j] - B[i];
		}
	}
	cout << "ROW MINIMA MATRIX" << endl;
	cout << "-----------" << endl;
	print_matrix(A);
	cout << endl << endl;
	colmin = A[0][0];
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			if (colmin>A[j][i])
			{
				colmin = A[j][i];
			}
		}
		cout << colmin << "\t";
		C[i] = colmin;
		colmin = A[0][i+1];
	}
	cout << endl << endl;
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			A[j][i] = A[j][i] - C[i];
		}
	}

	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			G[i][j] = A[i][j];
		}
	}

	cout << "COL MINIMA MATRIX" << endl;
	cout << "-----------" << endl;
	print_matrix(A);
	cout << endl << endl;
	for (int i = size - 1; i >= 0; i--)
	{
		for (int j = size - 1; j >= 0; j--)
		{
			
			E[i][j] = A[i][j];
		}
	}
	
	coverZeros();
	while (numLines<size)  // Bazý durumlarda riskli.
	{
		Addzero();
		coverZeros();
		numLines++;
	}

	cout << endl << endl;
	cout << "F MATRIX STEP-3" << endl;
	cout << "-----------" << endl;
	print_matrix(E);
	for (int i = size - 1; i >= 0; i--)
	{
		for (int j = size - 1; j >= 0; j--)
		{

			H[i][j] = E[i][j];
		}
	}
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			F[i][j] = E[i][j];
		}
	}
	coverZeros2();
	int temp;
	temp = E[0][0];
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			if (E[i][j]<temp && E[i][j]!=0)
			{
				temp = E[i][j];
			}
		}
	}
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			if (E[i][j]!=0)
			{
				E[i][j] -= temp;
			}
		}
	}
	
	cout << endl;
	cout << "E MATRIX STEP-3" << endl;
	cout << "-----------" << endl;
	print_matrix(E);
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			if (F[i][j]!=-1&&F[i][j]!=1&&F[i][j]!=2)
			{
				F[i][j]=E[i][j];
			}
			else
			{
				
			}
		}
	}
	cout << endl << endl;
	cout << "F MATRIX STEP-3" << endl;
	cout << "-----------" << endl;
	print_matrix(F);
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			if (H[i][j] == 2)
			{
				F[i][j] = (G[i][j] + temp);
			}
			else if(F[i][j]==1|| F[i][j] ==-1)
			{
				F[i][j] = 0;
			}
			else
			{

			}
		}
	}
	cout << "F MATRIX STEP-4" << endl;
	cout << "-----------" << endl;
	print_matrix(F);
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			if (G[i][j] != 0 && G[i][j]!=(F[i][j]-temp)&&G[i][j]!= (F[i][j] + temp))
			{
				F[i][j] = G[i][j];
			}
			else
			{

			}
		}
	}
	cout << "F MATRIX STEP-5" << endl;
	cout << "-----------" << endl;
	print_matrix(F);
	int x = 0;
	int Y[100];
	bool flag = true;
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			if (F[i][j]==0)
			{	
				flag = true;
				if (x==0)
				{
					Y[x] = (i * 10) + j;
					x++;
				}
				else 
				{
					for (int k = 0; k < x; k++)
					{
						if (Y[k]%10==j || Y[k]/10==i)
						{
							flag = false;
						}
					}
					if (flag == true)
					{
						Y[x] = (i * 10) + j;
						if (x != size)
						{
							x++;
						}
					}
					
				}
			}
		}
	}
	cout << "Sirasiyla Alinacak Satir Sutun Bilgileri:" << endl << endl;
	cout << "('i' degerinin '0' oldugu durumda ekranda gorunmemektedir." << endl << endl;
	for (int i = 0; i < x; i++)
	{
		cout << "Matrix:" << Y[i] << "\t";
	}
	cout << endl << endl;
	cout << "Orijinal Matrix" << endl;
	cout << "-----------" << endl;
	print_matrix(A2);
	cout << endl << endl;
	int sum = 0;
	for (int i = 0; i < size; i++)
	{
		sum += A2[Y[i] / 10][Y[i] % 10];
	}
	cout << "The total cost of optimal assignment= " << " \t "<<sum << endl<<endl;
	system("pause");
}

void coverZeros()
{

	for (int row = 0; row < size; row++)
	{
		for (int col = 0; col < size; col++)
		{
			if (A[row][col] == 0)
			{
				marked(row, col, maxVh(row, col));

			}
		}
	}

}
void coverZeros2()
{
	for (int row = 0; row < size; row++)
	{
		for (int col = 0; col < size; col++)
		{
			if (A[row][col] == 0)
			{
				unmarked(row, col, maxVh(row, col));

			}
		}
	}
}
int maxVh(int row, int col)
{
	int result = 0;
	for (int i = 0; i < size; i++)
	{
		if (A[i][col] == 0)
		{
			result++;
		}
		if (A[row][i] == 0)
		{
			result--;
		}

	}
	return result;
}
void unmarked(int row, int col, int maxVh)
{
	if (E[row][col] == 0)
	{
		return;
	}
	if (maxVh > 0 && E[row][col] == 0)
	{
		return;
	}
	if (maxVh <= 0 && E[row][col] == 0)
	{
		return;
	}
	for (int i = 0; i < size; i++)
	{
		if (maxVh > 0)
		{
			E[i][col] = E[i][col] == 0 || E[i][col] == 0 ? 0 : 0;

		}
		else
		{
			E[row][i] = E[row][i] == 0 || E[row][i] == 0 ? 0 : 0;
		}
	};

}
void marked(int row, int col, int maxVh)
{
	if (E[row][col] == 2)
	{
		return;
	}
	if (maxVh > 0 && E[row][col] == 1)
	{
		return;
	}
	if (maxVh <= 0 && E[row][col] == -1)
	{
		return;
	}
	for (int i = 0; i < size; i++)
	{
		if (maxVh > 0)
		{
			E[i][col] = E[i][col] == -1 || E[i][col] == 2 ? 2 : 1;

		}
		else
		{
			E[row][i] = E[row][i] == 1 || E[row][i] == 2 ? 2 : -1;
		}
	};
	numLines++;
}
void Addzero()
{
	int mincoveredvalue = 0;
	for (int row = 0; row < size; row++)
	{
	for (int col = 0; col < size; col++)
	{
	if (E[row][col] == 0 && (A[row][col] < mincoveredvalue || mincoveredvalue == 0))
	{
	mincoveredvalue = A[row][col];
	}
	}
	}

	for (int row = 0; row < size; row++)
	{
		for (int col = 0; col < size; col++)
		{
		if (E[row][col] == 0)
			{
			A[row][col] -= mincoveredvalue;
			}

		else if (A[row][col] == 2)
			{
			A[row][col] += mincoveredvalue;
			}
		}
	}

	
}

void print_matrix(int M[][size])
{
	int i, j;
	for (i = 0; i < size; i++)
	{
		for (j = 0; j < size; j++)
			cout << M[i][j] << "\t";

		cout << "\n";
	}
}
