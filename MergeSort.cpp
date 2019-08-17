#include <iostream>

constexpr int c_size = 8;

void Merge(int *a, int begin, int end, int mid)
{
	int i, j, k, temp[c_size];
	i = begin;
	k = 0;
	j = mid + 1;

	while (i <= mid && j <= end)
	{
		if (a[i] < a[j])
		{
			temp[k] = a[i];
			k++;
			i++;
		}
		else
		{
			temp[k] = a[j];
			k++;
			j++;
		}
	}

	while (i <= mid)
	{
		temp[k] = a[i];
		k++;
		i++;
	}

	while (j <= end)
	{
		temp[k] = a[j];
		k++;
		j++;
	}


	for (i = begin; i <= end; i++)
	{
		a[i] = temp[i - begin];
	}
}


void MergeSort(int *a, int l, int r)
{
	int m;
	if (l < r)
	{
		m = (l + r) / 2;
		MergeSort(a, l, m);
		MergeSort(a, m + 1, r);

		Merge(a, l, r, m);
	}
}



int main(int argc, char* argv[])
{

	int a[c_size];

	std::cout << "Merge sort with 8 numbers" << std::endl 
	<< "Enter numbers that you want to sort " << std::endl;

	for (int i = 0; i < c_size; i++)
	{
		std::cin >> a[i];
	}

	MergeSort(a,0, c_size - 1);
	
	for (int i = 0; i < c_size; i++)
	{
		std::cout<< a[i] << " ";
	}

	system("pause");
	return 0;
}
