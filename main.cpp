#include"Graph.h"

using namespace std;

const int MAX = 1000;
int g[100][100], x[100], bestx[100];
int cl = 0, bestl = MAX, n;

void title()
{
	cout << "--------------------------------------------------" << endl;
	cout << "---------------��ӭʹ�þ������ϵͳ---------------" << endl;
}

void mainMenu()
{
	cout << "--------------------------------------------------" << endl;
	cout << "[1]�޸�����" << endl;
	cout << "[2]���·��" << endl;
	cout << "[3]�����ܱ�" << endl;
	cout << "[4]��·�滮" << endl;
	cout << "[5]�˳�ϵͳ" << endl;
}

void subMenu()
{
	cout << "--------------------------------------------------" << endl;
	cout << "[1]��Ӿ���" << endl;
	cout << "[2]���·��" << endl;
	cout << "[3]ɾ������" << endl;
	cout << "[4]ɾ��·��" << endl;
	cout << "[5]�޸�·��" << endl;
	cout << "[6]�˳�ϵͳ" << endl;
}

int main()
{
	int mainChoice = 0;
	int subChoice = 0;
	int mainLoop = 1;
	int subLoop = 1;
	string dept, arrv;
	double dist;
	int num;
	string* array = nullptr;
	Graph g;
	g.readFile();
	title();
	while (mainLoop == 1)
	{
		mainLoop = 0;
		mainMenu();
		cin >> mainChoice;
		switch (mainChoice)
		{
		case 1:
			subLoop = 1;
			while (subLoop == 1)
			{
				subLoop = 0;
				subMenu();
				cin >> subChoice;
				switch (subChoice)
				{
				case 1:
					cout << "������Ҫ��ӵľ������ƣ�" << endl;
					cin >> dept;
					g.addVertex(dept);
					break;
				case 2:
					cout << "������Ҫ���·�������˵㼰���룺" << endl;
					cin >> dept >> arrv >> dist;
					g.addEdge(dept, arrv, dist);
					break;
				case 3:
					cout << "������Ҫɾ���ľ������ƣ�" << endl;
					cin >> dept;
					g.removeVertex(dept);
					break;
				case 4:
					cout << "������Ҫɾ��·�������˵㼰���룺" << endl;
					cin >> dept >> arrv;
					g.removeEdge(dept, arrv);
					break;
				case 5:
					cout << "������Ҫ�޸�·�������˵㼰���룺" << endl;
					cin >> dept >> arrv >> dist;
					g.updateWeight(dept, arrv, dist);
					break;
				case 6:
					break;
				default:
					cout << "ѡ��������������룺" << endl;
					subLoop = 1;
					break;
				}
				if (subChoice >= 1 && subChoice <= 5)
				{
					cout << "�Ƿ�����޸�?" << endl;
					cout << "[1]ȷ��" << endl;
					cout << "[2]����" << endl;
					cin >> subLoop;
				}
				if (subLoop == 1)
				{
					mainLoop = 1;
					continue;
				}
				else
				{
					mainLoop = 1;
					break;
				}
			}
			break;
		case 2:
			cout << "������ҪѰ�����·�������˵㣺" << endl;
			cin >> dept >> arrv;
			g.dijkstra(dept, arrv);
			break;
		case 3:
			cout << "������ҪѰ���ܱ߾���Ķ˵㼰��Χ��" << endl;
			cin >> dept >> dist;
			g.dijkstra(dept, dist);
			break;
		case 4:
			cout << "���������Ȥ�ľ���������" << endl;
			cin >> num;
			array = new string[num];
			cout << "���������Ȥ��" << num << "���������ƣ�" << endl;
			for (int i = 0; i < num; i++)
			{
				cin >> array[i];
			}
			g.kruskal(array, num);
			break;
		case 5:
			return 0;
		default:
			cout << "ѡ��������������룺" << endl;
			mainLoop = 1;
			break;
		}
		if (mainChoice >= 2 && mainChoice <= 4)
		{
			cout << "�Ƿ����?" << endl;
			cout << "[1]ȷ��" << endl;
			cout << "[2]�˳�" << endl;
			cin >> mainLoop;
		}
		if (mainLoop == 1)
		{
			continue;
		}
	}
	return 0;
}
