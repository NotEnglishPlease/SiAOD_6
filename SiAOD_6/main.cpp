#include "Graph.h"

using namespace std;

Graph createGraph(int n);

int main()
{
	setlocale(LC_ALL, "rus");
	short problem;
	bool flag = true;
	string s;
	int n;
	Graph graph;
	while (flag)
	{
		system("cls");
		cout << "Практическая работа №6 ИКБО-06-21 Эрднеева Н.Д. Варинат 10" << "\n\n"
			"Меню\n"
			"0) Ввод графа методом добавления одного ребра.\n"
			"1) Вывод графа.\n"
			"2) Определить эксцентриситет заданного узла.\n"
			"3) Нахождение кратчайших путей методом «Беллмана-Форда». Используя результат алгоритма вывести путь между вводимыми парами вершин.\n";
		cout << "Ваш выбор: ";
		cin >> problem;
		switch (problem) {
		case 0:
		{
			cout << "Введите номер графа из теста: ";
			cin >> n;
			graph = createGraph(n);
			system("pause");
			break;
		}
		case 1:
		{
			graph.outGraph();
			system("pause");
			break;
		}
		case 2:
		{
			graph.buildMatrix();
			graph.setBellFord();
			system("pause");
			break;
		}
		case 3:
		{
			system("pause");
			break;
		}
		default:
			cout << "Извините, я не совсем понимаю, что вы хотите сделать. Попробуйте в другой раз.\n";
			system("pause");
			break;
		}
	}
	return 0;
}

Graph createGraph(int n) {
	Graph graph;
	switch (n)
	{
	case 1:
	{
		graph.addEl(1, 2, 1);
		graph.addEl(1, 3, 2);
		graph.addEl(2, 4, 3);
		graph.addEl(2, 5, 6);
		graph.addEl(3, 5, 7);
		graph.addEl(3, 4, 4);
		graph.addEl(5, 4, 11);
		break;
	}
	case 2:
	{
		graph.addEl(1, 2, 7);
		graph.addEl(1, 6, 4);
		graph.addEl(2, 4, 2);
		graph.addEl(2, 3, 1);
		graph.addEl(3, 4, 2);
		graph.addEl(3, 5, 3);
		graph.addEl(4, 5, 6);
		graph.addEl(4, 6, 1);
		graph.addEl(5, 6, 8);
		break;
	}
	case 3:
	{
		graph.addEl(1, 2, 20);
		graph.addEl(1, 6, 23);
		graph.addEl(1, 7, 1);
		graph.addEl(2, 3, 15);
		graph.addEl(2, 7, 4);
		graph.addEl(3, 4, 3);
		graph.addEl(3, 7, 9);
		graph.addEl(4, 5, 17);
		graph.addEl(4, 7, 16);
		graph.addEl(5, 7, 25);
		graph.addEl(5, 6, 28);
		graph.addEl(6, 7, 36);
		break;
	}
	case 4:
	{
		graph.addEl(1, 2, 2);
		graph.addEl(1, 3, 6);
		graph.addEl(1, 4, 4);
		graph.addEl(2, 4, 7);
		graph.addEl(2, 5, 8);
		graph.addEl(3, 4, 8);
		graph.addEl(3, 6, 5);
		graph.addEl(4, 5, 2);
		graph.addEl(4, 6, 8);
		graph.addEl(5, 6, 4);
		break;
	}
	case 5:
	{
		graph.addEl(1, 2, 2);
		graph.addEl(1, 3, 4);
		graph.addEl(1, 4, 5);
		graph.addEl(2, 4, 4);
		graph.addEl(2, 5, 3);
		graph.addEl(3, 7, 6);
		graph.addEl(4, 5, 6);
		graph.addEl(4, 6, 4);
		graph.addEl(5, 6, 2);
		break;
	}
	case 6:
	{
		graph.addEl(1, 2, 8);
		graph.addEl(1, 3, 4);
		graph.addEl(2, 3, 3);
		graph.addEl(2, 4, 6);
		graph.addEl(2, 5, 3);
		graph.addEl(3, 4, 2);
		graph.addEl(3, 6, 10);
		graph.addEl(4, 5, 3);
		graph.addEl(4, 6, 1);
		graph.addEl(5, 6, 4);
		break;
	}
	default:
		break;
	}
	return graph;
}