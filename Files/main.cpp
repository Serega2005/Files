#include<iostream>
#include<fstream>
using namespace std;

//#define WRITE_TO_FILE
#define READ_FROM_FILE

void main()
{
	setlocale(LC_ALL, "Russian");
#ifdef WRITE_TO_FILE
	//1) Создаём поток вывода (записи) в файл;
	ofstream fout;
	//2) Открываем поток;
	fout.open("File.txt", ios::app/*append*/);
	//3) Выводим нужную информацию в файл;
	fout << "Hello World! " << endl;;
	//4) Закрываем поток;
	fout.close();
	system("notepad file.txt");
#endif // WRITE_TO_FILE

	//1) Создаём поток
	ifstream fin;
	//2)открываем поток
	fin.open("File.txt");
	//3)Чтение из файла

	const int n = 256;
	char sz_buffer[n]{};//строка заканчивающаяся 0
	if (fin.is_open())
	{
		while (!fin.eof())// eof() - функция которая определяет, достигли мы конец файла или нет.
		{
			//fin >> sz_buffer;
			fin.getline(sz_buffer, n);
			cout << sz_buffer << endl;
		}
	}

	//4)Закрываем поток
	fin.close();
}