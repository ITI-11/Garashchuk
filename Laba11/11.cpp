#include <locale.h>
#include <iostream>
#include <windows.h>
#include <vector>
#include <string>
#include <cstdlib>
#include <ctime>

using namespace std;

typedef struct {
	int pageNum;
	int isFreePage;
	int pageMemory;
	int pageFreeMemory;
} virtualPage;

typedef struct {
	string fileName;
	int fileMemory;
	int filePage;
	int isDef;
} virtualFile;

virtualPage * page;
vector <virtualFile> files(1);
int fileNum = 0;
int pageNum = 0;

FILE *File;

void inputData()
{
	if(File == NULL) {printf("Error\n"); fflush(stdin);}
	int N, i = 0;
	cout << "������� ���-�� ������� ������: ";
	cin >> N;
	page = new virtualPage[N];
	fprintf(File, "������� ���������� ������� - %d ���.\n", N);
	while (i < N)
	{
		cout << "������� ������ " << i + 1 << " ��������: ";
		cin >> page[i].pageMemory;
		fprintf(File, "������ %d �������� - %d\n", (i+1), page[i].pageMemory);
		page[i].pageNum = i + 1;
		page[i].isFreePage = 1;
		page[i].pageFreeMemory = page[i].pageMemory;
		i++;
	}
	pageNum = N;
}

void outputData()
{
	int j, i = 0;
	bool isFirst;
	while (i < pageNum)
	{
		j = 0;
		isFirst = true;
		cout << "�������� �" << i + 1;
		while (j < fileNum)
		{
			if (files[j].filePage == page[i].pageNum)
			{
				if (isFirst)
				{
					cout << "\n��������� ������ � �������: ";
					isFirst = false;
				}
				cout << files[j].fileName << "(" << files[j].fileMemory << ") ";
			}
			j++;
		}
		cout << "\n������ ��������: " << page[i].pageMemory << ". ��������: " << page[i].pageFreeMemory << endl;
		i++;
	}

}

int menu()
{
	int n;

	cout << "\t�������� ����� ����\n";
	cout << "1. ������ ���-�� ������� � �� ������\n";
	cout << "2. ������� ����������\n";
	cout << "3. �������� �������� �����\n";
	cout << "4. Exit\n";
	cin >> n;
	return n;
};

void inputFile()
{
	int i = 0, isPage, memory;
	string name;
	if (fileNum == 0)
	{
		cout << "������� ��� �����: ";
		cin >> name;
		cout << "������� ����� ��������: ";
		cin >> isPage;
		cout << "������� ������ ��������� �����: ";
		cin >> memory;
	}
	else
	{
		files.insert(files.end(), files[0]);
		cout << "������� ��� �����: ";
		cin >> name;
		cout << "������� ����� ��������: ";
		cin >> isPage;
		cout << "������� ������ ��������� �����: ";
		cin >> memory;
	}
	fprintf(File, "�������� ���� %s � �������� %d �� %d ��������\n", name.c_str(),memory,isPage);
	
	bool isFind = false;

	while (memory > page[isPage - 1].pageFreeMemory && !isFind)
	{
		if (memory <= page[i].pageFreeMemory)
		{
			cout << "��������� ������ �� ����� �������� ���� ������ ������, ���� ������� � ������ �" << i + 1;
			isPage = i + 1;
			isFind = true;
		}

		i++;

		if (i > pageNum)
		{
			cout << "���������� ���������� �������� � ������";
			return;
		}

	}
	files[fileNum].fileName = name;
	files[fileNum].filePage = isPage;
	files[fileNum].fileMemory = memory;
	files[fileNum].isDef = 0;
	page[isPage - 1].pageFreeMemory -= memory;
	page[isPage - 1].isFreePage = 0;
	fileNum++;
}


int main()
{
	File = fopen("11.txt", "w+t");
	setlocale(LC_ALL, "RUS");
	int n;
	
	while ((n = menu()) != 4)
	{
		system("cls");
		switch (n)
		{
		case 1: inputData();
			break;
		case 2: outputData();
			break;
		case 3: inputFile();
			break;
		default:
			break;
		}
	}
	system("pause");
	delete [] page;
	return 0;
}
