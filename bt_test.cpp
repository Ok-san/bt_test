#include <iostream>

void printArr(const int* arr, const int size) {
	for (int i{}; i < size; i++)
		std::cout << arr[i] << " ";
	std::cout << std::endl;
}

void merge(int* arr, int* subArr, int start, int q, int end) {
	int i{ start }, j{ q + 1 }, pos{ 0 };

	//выбираем меньший элемент из двух подмассивов
	while (i <= q && j <= end) {
		if (arr[i] < arr[j])
			subArr[pos++] = arr[i++];
		else
			subArr[pos++] = arr[j++];
	}

	//переносим оставшиеся элементы из одного подмасива
	while (j <= end)
		subArr[pos++] = arr[j++];
	while (i <= q)
		subArr[pos++] = arr[i++];

	for (int k = 0; k < end - start+1 ; k++)
		arr[start + k] = subArr[k];
}

void sort(int* arr, int* subArr, int start, int end)
{
	if (start < end) {
		int q{ (start + end) / 2 };
		sort(arr, subArr, start, q);
		sort(arr, subArr, q + 1, end);
		merge(arr, subArr, start, q, end);
	}
}

int main()
{
	int size{};
	size = 8;

	/*std::cout << "Enter array size: "; 	
	if ((std::cin >> size).fail() || (size < 1) || (size > INT_MAX)) {
		std::cin.clear();
		std::cin.ignore();
		std::cout << "Incorect array size.";
		return 1;
	}
	std::cin.sync();*/	

	int* arr{ new int[size] {/*5,2,4,6,1,3,2,6*/} };
	if (!arr) {
		std::cout << "Failed to allocate memory.\n";
		return 1;
	}

	int* subArr{ new int[size] {} };
	if (!subArr) {
		delete[] arr;
		std::cout << "Failed to allocate memory.\n";
		return 1;
	}

	/*std::cout << "Enter element: ";
	for (int i{}; i < size; i++)
		if ((std::cin >> arr[i]).fail()) {
			std::cin.clear();
			std::cin.ignore();
			delete[] arr;
			std::cout << "Incorect element.";
			return 1;
		}
	std::cin.sync();*/
	
	srand(time(NULL));
	for (int i{}; i < size; i++)
		arr[i] = -10 + rand() % (20 + 10 + 1);;

	std::cout << "Array:\n";
	printArr(arr, size);			
	
	sort(arr, subArr, 0, size - 1);

	std::cout << "Sorted array:\n";
	printArr(arr, size);

	delete[] subArr;
	delete[] arr;

	return 0;
}