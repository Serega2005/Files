#include<iostream>
#include<fstream>
using namespace std;

//#define WRITE_TO_FILE
#define READ_FROM_FILE

void main()
{
	setlocale(LC_ALL, "Russian");
#ifdef WRITE_TO_FILE
	//1) ������ ����� ������ (������) � ����;
	ofstream fout;
	//2) ��������� �����;
	fout.open("File.txt", ios::app/*append*/);
	//3) ������� ������ ���������� � ����;
	fout << "Hello World! " << endl;;
	//4) ��������� �����;
	fout.close();
	system("notepad file.txt");
#endif // WRITE_TO_FILE

	//1) ������ �����
	ifstream fin;
	//2)��������� �����
	fin.open("File.txt");
	//3)������ �� �����

	const int n = 256;
	char sz_buffer[n]{};//������ ��������������� 0
	if (fin.is_open())
	{
		while (!fin.eof())// eof() - ������� ������� ����������, �������� �� ����� ����� ��� ���.
		{
			//fin >> sz_buffer;
			fin.getline(sz_buffer, n);
			cout << sz_buffer << endl;
		}
	}

	//4)��������� �����
	fin.close();
}