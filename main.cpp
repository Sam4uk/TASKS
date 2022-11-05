#include <iostream>
#include <cstdio>
using std::cin;
using std::cout;
using std::endl;

int ShowMatrix(int arr[], unsigned columns, unsigned rows)
{
	for (unsigned row{0}; row < rows; row++)
	{
		for (unsigned column{0}; column < columns; column++)
			cout << arr[row * rows + column] << '\t';
		cout << endl;
	}
	return EXIT_SUCCESS;
}

int CountRowsWithZero(int arr[], unsigned columns, unsigned rows)
{
	unsigned Count{0};
	for (unsigned row{0}; row < rows; row++)
	{
		for (unsigned column{0}; column < columns; column++)
			if (arr[row * rows + column] == 0)
			{
				Count++;
				break;
			}
	}
	return Count;
}
int RowWithBiggestSeries(int arr[], unsigned columns, unsigned rows)
{
	unsigned MaxLengInLine{0};
	unsigned NumLine{0};
	for (unsigned row{0}; row < rows; row++)
	{
		unsigned startSeries{0};
		for (unsigned column{1}; column < columns; column++)
		{
			if (arr[row * rows + startSeries] == arr[row * rows + column])
			{
				if (MaxLengInLine <= column - startSeries)
				{
					MaxLengInLine = column - startSeries;
					NumLine = row;
				}
			}
			else
				startSeries = column;
		};
	}
	return NumLine;
}
// #define RANDOM (10)
int main()
{
	cout << "Column count = ";
	unsigned ColumnCount;
	cin >> ColumnCount;
	cout << "Row count = ";
	unsigned RowCount;
	cin >> RowCount;

	int Matrix[ColumnCount][RowCount];
	srand(time(0));
	for (unsigned column{0}; column < ColumnCount; column++)
		for (unsigned row{0}; row < RowCount; row++)
#ifdef RANDOM
			Matrix[column][row] = rand() % RANDOM;
#else
		{
			cout << "[" << column << "," << row << "] = " << endl;
			cin >> Matrix[column][row];
		}
#endif
	ShowMatrix(reinterpret_cast<int *>(Matrix), ColumnCount, RowCount);
	cout << "Count colums with \"0\" = " << CountRowsWithZero(reinterpret_cast<int *>(Matrix), ColumnCount, RowCount) << endl;
	cout << "Longest series in " << CountRowsWithZero(reinterpret_cast<int *>(Matrix), ColumnCount, RowCount) << " line." << endl;
	return EXIT_SUCCESS;
}
