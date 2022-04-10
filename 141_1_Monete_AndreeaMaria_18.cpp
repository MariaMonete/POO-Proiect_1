#define _CRT_SECURE_NO_WARNINGS
//Am folosit asta pt strcpy
#include <iostream>
#include <string>
using namespace std;


class Film
{
	char* denumire_film;
	string gen;
	string regizor;
	float rating;


public:

	Film()
	{
		denumire_film = new char[strlen("necunoscuta") + 1];
		strcpy(denumire_film, "necunoscuta");
		gen = "necunoscut";
		regizor = "necunoscut";
		rating = 0;
	}

	Film(const char* denumire, string gen, string regizor, float rating)
	{
		this->denumire_film = new char[strlen(denumire) + 1];
		strcpy(this->denumire_film, denumire);
		this->gen = gen;
		this->regizor = regizor;
		this->rating = rating;
	}

	Film(const Film& f)
	{
		this->denumire_film = new char[strlen(f.denumire_film) + 1];
		strcpy(this->denumire_film, f.denumire_film);
		this->gen = f.gen;
		this->regizor = f.regizor;
		this->rating = f.rating;
	}

	Film& operator= (const Film& f) {
		if (this != &f)
		{
			if (this->denumire_film != nullptr) {
				delete[]this->denumire_film;
			}

			this->denumire_film = new char[strlen(f.denumire_film) + 1];
			strcpy(this->denumire_film, f.denumire_film);

			this->gen = f.gen;
			this->regizor = f.regizor;
			this->rating = f.rating;
		}

		return *this;
	}

	~Film()
	{
		if (denumire_film != nullptr)
		{
			delete[] denumire_film;
			denumire_film = nullptr;
		}
	}



	void setDenumire(const char* denumire)
	{
		if (denumire != nullptr)
		{
			if (this->denumire_film != nullptr)
				delete[] this->denumire_film;
			this->denumire_film = new char[strlen(denumire) + 1];
			strcpy(this->denumire_film, denumire);
		}
	}

	char* getDenumire()
	{
		return this->denumire_film;
	}

	void setGen(string gen)
	{
		this->gen = gen;
	}

	string getGen()
	{
		return this->gen;
	}

	void setRegizor(string regizor)
	{
		this->regizor = regizor;
	}

	string getRegizor()
	{
		return this->regizor;
	}

	void setRating(float rating)
	{
		this->rating = rating;
	}

	float getRating()
	{
		return this->rating;
	}

	friend ostream& operator<<(ostream& out, const Film& f)
	{
		out << f.denumire_film << endl << f.gen << endl << f.regizor << endl << f.rating << endl;
		return out;
	}

	friend istream& operator>>(istream& in, Film& f)
	{
		cout << "Introduceti denumirea filmului: ";
		char aux[100];
		in >> ws;
		in.getline(aux, 99);

		delete[] f.denumire_film;
		f.denumire_film = new char[strlen(aux) + 1];
		strcpy(f.denumire_film, aux);

		cout << "Introduceti genul filmului: ";
		in >> ws;
		getline(in, f.gen);

		cout << "Introduceti regizorul filmului: ";
		in >> ws;
		getline(in, f.regizor);

		cout << "Introduceti ratingul filmului: ";
		in >> f.rating;

		return in;
	}

	bool operator >(Film f) {
		return this->rating > f.rating;
	}

	bool operator <(Film f) {
		return this->rating < f.rating;
	}

};


int main()
{
	Film f1;
	Film f2("Mother", "Horror", "Denis V", 9.2);
	Film f3(f2);
	Film f4;
	f4 = f3;
	cout << f1 << endl << f2 << endl << f3 << endl << f4 << endl;
	f1.setDenumire("Ion");
	cout<<f1.getDenumire()<<endl;

	int nr_filme;
	cout << "Introduceti numarul de filme: ";
	cin >> nr_filme;
	Film* vecFilme = new Film[nr_filme];
	for (int i = 0; i < nr_filme; i++)
		cin >> vecFilme[i];
	cout << endl;
	for (int i = 0; i < nr_filme; i++)
		cout << vecFilme[i] << endl;


}