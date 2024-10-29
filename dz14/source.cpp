#include <iostream>
#define SIZE 10

using namespace std;

int size_of_arr = 0;

int* createDynamicArr(int size)
{
	int* parr = new int[size];
	return parr;
}
int* InitializationDynamicArr(int* parr, int size)
{
	for (int i = 0; i < size; i++)
	{
		parr[i] = rand() % 100;
	}
	return parr;
}
void PrintDynamicArr(int* parr, int size)
{
	for (int i = 0; i < size; i++)
	{
		cout << parr[i] << " ";
	}
}
void DeleteArr(int* parr)
{
	delete[] parr;
}

int* AddElementEnd(int* parr, int size, int new_num)
{
	int* new_parr = new int[size + 1];
	for (int i = 0; i < size; i++)
	{
		new_parr[i] = parr[i];
	}
	new_parr[size + 1] = new_num;

	delete[] parr;
	return new_parr;
}

int* AddElementByIndex(int* parr, int size, int new_num, int index)
{
	int* new_parr = new int[size + 1];
	if (index > size)
	{
		cout << "Index is higher than size, its unreal to add an element by this index " << endl;
		return parr;
	}
	for (int i = 0; i < index; i++)
	{
		new_parr[i] = parr[i];
	}
	new_parr[index] = new_num;

	for (int i = index + 1; i < size + 1; i++)
	{
		new_parr[i] = parr[i - 1];
		index++;
	}
	delete[] parr;

	return new_parr;
}

int* DeleteElementByIndex(int* parr, int size, int index)
{
	int* new_parr = new int[size - 1];
	if (index < 0 || index > size)
	{
		cout << "Invalid index, its unreal to delete element by this index." << endl;
		return parr;
	}
	if (index == 0) {
		for (int i = 0; i < size - 1; i++)
		{
			new_parr[i] = parr[i + 1];
		}
		return new_parr;
	}
	for (int i = 0; i < size; i++)
	{
		if (i < index)
		{
			new_parr[i] = parr[i];
		}
		if (i > index)
		{
			new_parr[i - 1] = parr[i];
		}
	}
	delete[] parr;
	return new_parr;
}

int* DeletePrimeNumbersInArr(int* parr, int size)
{
	int* new_parr = new int[size];
	for (int i = 0; i < size; i++)
	{
		if ((parr[i] % 2 != 0 ) && (parr[i] % 3 != 0) && (parr[i] % 5) || parr[i] == 2 || parr[i] == 3 || parr[i] == 5)
		{
			new_parr[size_of_arr] = parr[i];
			++size_of_arr;
		}
	}
	delete[] parr;
	return new_parr;
}

void SortIntoDynamicArrays(int* parr, int size)
{

	int* parr_minus = new int[size];
	int* parr_zero = new int[size];
	int* parr_add = new int[size];
	int m = 0, z = 0, a = 0;
	for (int i = 0; i < size; i++)
	{
		if (parr[i] < 0) {
			parr_minus[m] = parr[i];
			++m;
		}
		else if (parr[i] > 0) {
			parr_add[a] = parr[i];
			++a;
		}
		else{
			parr_zero[z] = parr[i];
			++z;
		}
	}
	cout << "Arr of nums less than 0: " ;
	for (int i = 0; i < m; i++)
	{
		cout << parr_minus[i] << " ";
	}
	cout << endl;
	cout << "Arr of nums higher than 0: ";
	for (int i = 0; i < m; i++)
	{
		cout <<  parr_add[i] << " ";
	}
	cout << endl;
	cout << "Arr of nums equal 0: ";
	for (int i = 0; i < z; i++)
	{
		cout << parr_zero[i] << " ";
	}
	cout << endl;
	delete[] parr_minus;
	delete[] parr_add;
	delete[] parr_zero;

}

int main() 
{
	srand(time(NULL));
	int size1, size2;
	cout << "Enter ur sizes for two arrays -> ";
	cin >> size1 >> size2;
	int* parr1 = new int[size1];
	int* parr2 = new int[size2];
	int* parr3 = new int[size1];

	for (int i = 0; i < size1; i++)
	{
		*(parr1 + i) = rand() % 11;
		cout << *(parr1 + i) << " ";
	}
	cout << endl;
	for (int i = 0; i < size2; i++)
	{
		*(parr2 + i) = rand() % 11;
		cout << *(parr2 + i) << " ";
	}
	cout << endl;
	int k = 0;
	int l = 0;
	for (int i = 0; i < size1; i++)
	{
		bool is_unique = true;
		bool is_used = false;
		for (int j = 0; j < size2; j++)
		{
			if (*(parr1 + i) == *(parr2 + j))
			{
				is_unique = false;
			}
			if (*(parr3 + j) == *(parr1 + i))
			{
				is_used = true;
			}
		}
		if (is_unique && is_used == false)
		{
			*(parr3 + k) = *(parr1 + i);
			++k;
		}
	}
	for (int i = 0; i < k; i++)
	{
		cout << *(parr3 + i) << " ";
	}
	int* parr4 = new int[size1 + size2];

	for (int i = 0; i < size1; i++)
	{
		bool is_unique = true;
		bool is_used = false;
		for (int j = 0; j < size2; j++)
		{
			if (*(parr1 + i) == *(parr2 + j))
			{
				is_unique = false;
			}
			if (*(parr4 + j) == *(parr1 + i))
			{
				is_used = true;
			}
		}
		if (is_unique && is_used == false)
		{
			*(parr4 + k) = *(parr1 + i);
			++k;
		}
	}
	for (int i = 0; i < size2; i++)
	{
		bool is_unique = true;
		bool is_used = false;
		for (int j = 0; j < size1; j++)
		{
			if (*(parr2 + i) == *(parr1 + j))
			{
				is_unique = false;
			}
			if (*(parr4 + j) == *(parr2 + i))
			{
				is_used = true;
			}
		}
		if (is_unique && is_used == false)
		{
			*(parr4 + k) = *(parr2 + i);
			++k;
		}
	}
	for (int i = 0; i < k; i++)
	{
		cout << *(parr4 + i) << " ";
	}
	delete[] parr1;
	delete[] parr2;
	delete[] parr3;
	delete[] parr4;
	

	int* MyArr = createDynamicArr(10);
	MyArr = InitializationDynamicArr(MyArr, 10);
	for (int i = 0; i < 10; i++)
	{
		cout << MyArr[i] << " ";
	}
	delete[] MyArr;

	int* parr1 = new int[10] {1,2,3,4,5,6,7,8,9,10};

	parr1 = DeletePrimeNumbersInArr(parr1, 10);

	for (int i = 0; i < size_of_arr; i++)
	{
		cout << parr1[i] << " ";
	}


	int arr[SIZE]{ -2,-3,5,1,5,0,9,0,2,-3 };
	int* parr = arr;
	SortIntoDynamicArrays(parr, SIZE);
}