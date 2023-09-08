# include <iostream>

void print_Array(short* parr, const short length); // Процедура вывода массива через указатель первого элемента и арифметику указетелей
void func(long long* pn, short degree); // Процедура возведения числа n в степень degree через указатель на обл.памяти, в которой хранится значение n

int main() {

	// Задача 1. Изменение мест чётных и нечётных элементов в массиве	
	std::cout << "\033[91mTask 1. Changing the locations of even and odd elements in an array\033[0m\n\n";
	const short size = 10;
	short array[size]{ 1,2,3,4,5,6,7,8,9,10 };
	std::cout << "Source array is: ";
	print_Array(array, size); // В качестве указателя на первый элемент массива будем использователь array	
	for (short i = 0; i < size; i += 2) // Цикл перебора массива с шагом 2 (чётное + нечётное числа)
		/* В функцию swap в качестве аргументов передаём разыменованные указатели текущего и следующего элементов массива, то есть значения, хранящиеся в
		области памяти, на которую указывает указатель "array", и в следующей области памяти (адрес +2 байта в соответствии с размером short)
		Функция swap меняет местами значения, хранящиеся в областях памяти, на которые указывают указатели "array + i" и "array + i + 1" соответственно*/
		std::swap(*(array + i), *(array + i + 1));
	std::cout << "\033[92mFinal array is: \033[0m";
	print_Array(array, size);
	std::cout << std::endl;	

	// Задача 2. Возведение числа в степень
	std::cout << "\033[91mTask 2. Raising a number to a degree\033[0m\n\nEnter the number = ";
	long long n;
	short degree;
	std::cin >> n;
	std::cout << "Enter the degree = ";
	std::cin >> degree;
	if (degree < 0) {		
		func(&n, abs(degree)); // В процедуру передаём модуль отрицательной степени
		std::cout << "\n\033[92mResult of exponentiation is \033[0m" << 1/double(n) << std::endl;
	}
	else {
		func(&n, degree);
		std::cout << "\n\033[92mResult of exponentiation is \033[0m" << n << std::endl;
	}

	return 0;
}

void print_Array(short* parr, const short length) {
	for (short i = 0; i < length; i++)
		std::cout << *(parr + i) << ", ";
	std::cout << "\b\b \n" << std::endl;
}

void func(long long* pn, short degree) {
	if (degree)	{ // Если степень не ноль (true), то
		short tmp = *pn; // Объявляем переменную и инициализируем её значением, хранящимся в области памяти, на которую указывает указатель pn
		for (short i = 1; i < degree; i++) // Цикл перезаписи значения, хранящегося в области памяти, на которую указывает указатель pn
			*pn *= tmp;						// Если degree = 1, то значение в памяти по указателю *pn не меняется, т.к. цикл не запускается
	}
	else // Если степень = 0, то 
		*pn = 1; // значение, хрянящяяся в области памяти, на которую указывает указатель pn, перезаписывается на "1"
}
