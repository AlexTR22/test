#include <iostream>
#include <iomanip>
#include <algorithm>
using namespace std;

struct persoana
{
	char nume[50];
	int varsta;

	//definire operator mai mic supraincarcare operator
	//exact ca orice alta functie
	bool operator<(const persoana& pers)
	{
		return strcmp(nume, pers.nume) < 0;
	}
};

void CitireaDatelor(int& nrPers, persoana lista[20])
{
	cout << "Introduceti numarul de persoane din lista: " << endl;
	cin >> nrPers;
	cin.get();
	cout << "Introduceti numele persoanelor si varsta lor: " << endl;
	for (int i = 0; i < nrPers; i++)
	{
		cin.getline(lista[i].nume, 50);
		cin >> lista[i].varsta;
		cin.get();
	}
}

bool Comparator(persoana elem1, persoana elem2)
{
	if (elem1.nume[0] > elem2.nume[0])
		return true;
	return false;
}

void Sortare(const int& nrPers,persoana lista[20])
{
	sort(lista, lista + nrPers);
	// pointer pt iceputul si sfarsitul listei
	//acum ca e supraincarcat operatorul nu mai trebuie sa transmitem comparator
}

void AfisareTabel(const int& nrPers, persoana lista[20])
{
	cout << setfill('-') << setw(64) << "-" << endl;
	cout << setfill(' ');
	cout << "|" << setw(4) << "Nr. " << "|";
	cout << setiosflags(ios::left);
	cout << setw(50) << "NUME SI PRENUME" << "|Varsta|" << endl;
	cout << "|crt." << setw(51) << "|" << setw(7) << "|" << "|" << endl;
	cout << setfill('-');
	cout <<setw(5) << "|" << setw(51) << "|" << setw(7) << "|" << "|" << endl;
	cout << setfill(' ');
	float medie = 0;
	for (int i = 0; i < nrPers; i++)
	{
		cout << setiosflags(ios::right);
		cout << "|" << setw(4) << i + 1;
		cout << resetiosflags(ios::right);
		cout << "|" << setw(50) << lista[i].nume;
		cout << setiosflags(ios::right);
		cout << "|" << setw(6) << lista[i].varsta << "|" << endl;
		medie += lista[i].varsta;
	}

	medie /= nrPers;
	cout << resetiosflags(ios::right);
	cout << setfill('-');
	cout << setw(56) << "|" << setw(7) << "|" << "|" << endl;
	cout << setfill(' ');
	cout << "|" << setw(55) << "Media varstelor:" << "|";
	cout << setiosflags(ios::right | ios::fixed);
	cout << setprecision(2) << setw(6)<< medie << "|"<< endl;
	cout << setfill('-') << setw(64) << "-" << endl;
}

int main()
{
	//double mat[10][10];
	//int n, m;

	//cout << "Introcuceti dimensiunile matricii: " << endl;
	//cin >> n >> m;

	//cout << "Introduceti elementele matricii: " << endl;
	//for (int i = 0; i < n; i++)
	//{
	//	for (int j = 0; j < m; j++)
	//	{
	//		cin >> mat[i][j];
	//	}
	//}

	//cout << setiosflags(ios::right | ios::fixed); 
	// formatare la dreapta si scriere fara exponent
	//raman valide pana le dezactivez cu comanda

	//for (int i = 0; i < n; i++)
	//{
	//	for (int j = 0; j < m; j++)
	//	{
	//		cout << setw(8) << setprecision(2) << mat[i][j] <<  " "; // setw nr minim de caractere
	//	}
	//	cout << endl;
	//}

	persoana lista[20];
	int nrPers;
	CitireaDatelor(nrPers, lista);
	Sortare(nrPers, lista);
	AfisareTabel(nrPers, lista);

	return 0;
}