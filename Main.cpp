//Шаблон
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <algorithm>
using namespace std;

//Задача 1.
void type_of(int num);
void type_of(double num);
void type_of(char num);
//Задача 2.
int sum_AB(int A, int B);
//Задача 3.
//Задача 3. Заполняет массив случайными числами из диапазона от begin до end
template <typename T>
void fill_arr(T arr[], const int length, int begin, int end) {
	srand(time(NULL));
	for (int i = 0; i < length; i++)
		arr[i] = rand() % (end - begin) + begin;
}
//Задача 3.Вывод массива в консоль.
template <typename T>
void show_arr(T arr[], const int length) {
	cout << '[';
	for (int i = 0; i < length; i++)
		cout << arr[i] << ", ";
	cout << "\b\b]\n";
}
//Задача 3.
template <typename T>
void middel_sort(T arr[], const int length) {
	int first_index = 0, last_index = 0;
	//Первый отрицательный элемент
	for (int i = 0; i < length; i++)
		if (arr[i] < 0) {
			first_index = i;
			break;
		}
	//Последний отрицательный элемент
	for (int i = length - 1; i >= 0; i--)
		if (arr[i] < 0) {
			last_index = i;
			break;
		}
	//Сортируем диапазон между отрицательными крайними элементами
	//Пузырьковая сортировка
	/*for (int i = last_index - 1; i > first_index + 1; i--)
		for (int j = first_index + 1; j < i; j++)
			if (arr[j] > arr[j + 1])
				swap(arr[j], arr[j + 1]);*/
	//Быстрая сортировка
	sort(arr + first_index + 1, arr + last_index - 1);
}
//Задача 4.
template <typename T>
void move_arr(T arr[], const int length, int num);




int main() {
	setlocale(LC_ALL, "Russian");
	int n, m;

	//Задача 1. Создаем фукцию, которая принимает любое число и выводит его тип данных.
	/*cout << "Задача 1.\n";
	cout << "12 - "; type_of(12);
	cout << "9.11 - "; type_of(9.11);
	cout << "\'T\' - "; type_of('T');
	cout << "\n";*/

	//Задача 2. Написать рекурсивную фун-цию, которая вычисляет сумму чисел от А до В
	/*cout << "Задача 2.\nВведите два числа: \n";
	cin >> n >> m;
	cout << "\nСумма чисел от "<< n <<" до " << m << " = " << sum_AB(n, m) << "\n\n";*/

	//Задача 3. Самый левый и самый правый отрицател чисел в массиве случайных чисел и сортирует часть массива между ними.
	/*cout << "Задача 3.\nИзначальный массив:\n";
	const int size3 = 20;
	int arr3[size3];
	fill_arr(arr3, size3, -20, 21);
	show_arr(arr3, size3);
	middel_sort(arr3, size3);
	cout << "Итоговый массив:\n";
	show_arr(arr3, size3);
	cout << '\n';*/
	//Задача 4. Сдвиг массива впрво на переданное число.
	cout << "Задача 4. \nИзначальный массив:\n";
	const int size4 = 10;
	int arr4[size4]{ 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
	show_arr(arr4, size4);
	cout << "Введите кол-во сдвигов: ";
	cin >> n;
	move_arr(arr4, size4, n);
	cout << "Итоговый массив:\n";
	show_arr(arr4, size4);
	cout << '\n';




	return 0;
}
//Задача 1.
void type_of(int num) {
	cout << "INT\n";
}
void type_of(double num) {
	cout << "DOUBLE\n";
}
void type_of(char num) {
	cout << "CHAR\n";
}
//Задача 2.
int sum_AB(int A, int B) {
	if (B == A + 1)
		return A + B;
	return sum_AB(A, B - 1) + B;
}

//Задача 4.
template <typename T>
void move_arr(T arr[], const int length, int num) {
	if(num >= 0) //сдвиги вправо
		for(int j = 0; j < num; j++)
			for (int i = length - 2; i >= 0; i--)
				swap(arr[i], arr[i + 1]);
	else // сдвиги влево
		for (int j = num; j < 0; j++)
			for (int i = 0; i < length - 1; i++)
				swap(arr[i], arr[i + 1]);





}



