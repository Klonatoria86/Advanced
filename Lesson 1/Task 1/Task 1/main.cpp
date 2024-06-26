#include<iostream>
#include<fstream>
void foo(int x, int* arr)
{
	int z = arr[0];
	for (int i = 0; i < x; i++)
	{
		if (i == (x - 1))
		{
			arr[i] = z;
		}
		else
		{
			arr[i] = arr[i + 1];
		}

	}
}
void foo2(int x, int* arr)
{
	int z = arr[x - 1];
	for (int i = x - 1; i >= 0; i--)
	{
		if (i == 0)
		{
			arr[i] = z;
		}
		else
		{
			arr[i] = arr[i - 1];
		}

	}
}

int main() {
	setlocale(LC_ALL, "Russian");
	std::ifstream File("in.txt");
	if (File.is_open())
	{
		int x, y;
		File >> x;
		int* arr = new int[x];
		for (int i = 0; i < x; i++)
		{
			File >> arr[i];
		}
		File >> y;
		int* arr2 = new int[x];
		for (int i = 0; i < y; i++)
		{
			File >> arr2[i];
		}
		File.close();
		foo(x, arr);
		foo2(y, arr2);



		std::ofstream File2("out.txt");
		if (File2.is_open())
		{
			File2 << y << std::endl;
			for (int i = 0; i < y; i++)
			{
				File2 << arr2[i] << " ";
			}
			File2 << std::endl;
			File2 << x << std::endl;
			for (int i = 0; i < x; i++)
			{
				File2 << arr[i] << " ";
			}
			File2 << std::endl;
			File2.close();
			
		}
		else
		{
			std::cout << "Файл out.txt не открылся" << std::endl;
		}
	}
	else
	{
		std::cout << "Файл in.txt не открылся" << std::endl;
	}
	return 0;
}



