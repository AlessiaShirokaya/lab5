// ConsoleApplication6.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <regex>
#include <string>
using namespace std;

class Book
{
public:
	virtual int getKolstr() = 0;//создаем виртуальны функции
	virtual string getAutor() = 0;
	virtual string getNazvanie() = 0;
};
class Det : public Book
{
private:
	int kolstr;
	string aut;
	string naz;
public:
	Det(int c, string n, string a) : kolstr(c), aut(n), naz(a)//Конструктор класса принимающий аргументы
	{
	}
	int getKolstr() override//Методы класса
	{
		return kolstr;
	}
	string getAutor() override
	{
		return aut;
	}
	string getNazvanie() override
	{
		return naz;
	}
};
class Fan : public Book
{
private:
	int kolstr;
	string aut;
	string naz;
public:
	Fan(int c, string n, string a) : kolstr(c), aut(n), naz(a)//Конструктор класса принимающий аргументы
	{
	}
	int getKolstr() override//Методы класса
	{
		return kolstr;
	}
	string getAutor() override
	{
		return aut;
	}
	string getNazvanie() override
	{
		return naz;
	}
};
class Prik : public Book
{
private:
	int kolstr;
	string aut;
	string naz;
public:
	Prik(int c, string n, string a) : kolstr(c), aut(n), naz(a)//Конструктор класса принимающий аргументы
	{
	}
	int getKolstr() override//Методы класса
	{
		return kolstr;
	}
	string getAutor() override
	{
		return aut;
	}
	string getNazvanie() override
	{
		return naz;
	}
};

int isIntTru() {//Функция, проверяющая ввод чисел с клавиатуры. Если было введено число - вернет его, если же нет - выведет ошибку и повторит ввод
	regex integers(R"(\d+)");//Создаем регулярное выражение, только на цифры
	char input[80];//Создаем массив символов
	do {
		memset(input, 0, 80);//выделяем под массив память
		cin >> input;//вводит строку
		if (regex_match(input, input + strlen(input), integers))//проверяем условие содержит ли строка только цифры
		{
			return atoi(input);//если только цифры - возвращаем их, преобразовывая из char в int
		}
		else
		{
			cout << "Ошибка! Введите число!";
		}
	} while (1);//Бесконечный цикл, пока не будет число
}

int main()
{
	system("chcp 1251");
	system("cls");
	string a, b;
	int c = 0;
	Book* book[3];//Создаем массив указателей на базовый класс
	cout << "Детектив" << endl;
	cout << "Введите автора книги:" << endl;
	getline(cin, a);
	cout << "Введите название книги:" << endl;
	getline(cin, b);
	cout << "Введите количество страниц:" << endl;
	c = isIntTru();
	Det d(c, a, b);
	book[0] = &d;//присваиваем первому элементу массива указателей значение, указывающее на дочерний(по отношению к базовому) класс Det
	cout << "Фантастика" << endl;
	cout << "Введите автора книги:" << endl;
	getline(cin, a); getline(cin, a);
	cout << "Введите название книги" << endl;
	getline(cin, b);
	cout << "Введите количество страниц:" << endl;
	c = isIntTru();
	Fan f(c, a, b);
	book[1] = &f;
	cout << "Приключения" << endl;
	cout << "Введите автора книги:" << endl;
	getline(cin, a); getline(cin, a);
	cout << "Введите название книги:" << endl;
	getline(cin, b);
	cout << "Введите количество страниц:" << endl;
	c = isIntTru();
	Prik p(c, a, b);
	book[2] = &p;

	//book[0]-> означает, что мы берем указатель, хранящийся в массиве указателей и вызываем у него функцию. book[0] это указатель на детективы, book[1] на фантастику и т.д.
	cout << "Детектив: " << endl << "Автор книги: " << book[0]->getAutor() << endl << "Наименование книги: " << book[0]->getNazvanie() << endl << "Количество страниц: " << book[0]->getKolstr() << endl;
	cout << "Фантастика: " << endl << "Автор книги: " << book[1]->getAutor() << endl << "Наименование книги: " << book[1]->getNazvanie() << endl << "Количество страниц: " << book[1]->getKolstr() << endl;
	cout << "Прикючение: " << endl << "Автор книги: " << book[2]->getAutor() << endl << "Наименование книги: " << book[2]->getNazvanie() << endl << "Количество страниц: " << book[2]->getKolstr() << endl;

	return 0;
}

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
