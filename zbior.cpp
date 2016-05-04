/*
Projekt 2 1812
Autor: Jakub Jakobczyk
Prowadzacy: dr inż. Piotr Witonski
*/

#include<iostream>

#include "zbior.h"

//Zmienna statyczna - informuje o liczbie istniejacych obiektow klasy Zbior
int Zbior::ilosc(0);


//Konstruktory
Zbior::Zbior():rozmiar(0)
{
	ilosc++;
	#ifdef _DEBUG
		std::cout<<"<KONSTRUKTOR>Zbior nr: "<<ilosc<<std::endl;
	#endif
}

Zbior::Zbior(Zespolone<int> z1, int n):rozmiar(n), elem(new Zespolone<int>[n])
{
	ilosc++;
	#ifdef _DEBUG
		std::cout<<"<KONSTRUKTOR>Zbior nr: "<<ilosc<<std::endl;
	#endif
	elem[0] = z1;
}

Zbior::Zbior(const Zbior &z):rozmiar(z.rozmiar), elem(new Zespolone<int>[z.rozmiar])
{
	ilosc++;
	#ifdef _DEBUG
		std::cout<<"<KONSTRUKTOR>Zbior nr: "<<ilosc<<std::endl;
	#endif
	for (int i=0; i<rozmiar; i++)
	{
		elem[i] = Zespolone<int>(z.elem[i]);
	}
}

//Destruktor
Zbior::~Zbior()
{
	#ifdef _DEBUG
		std::cout<<"<DESTRUKTOR>Zbior nr: "<<ilosc<<std::endl;
	#endif
	ilosc--;
	if(rozmiar != 0)delete[] elem;
}

//Funkcje prywatne:

//Operatory [] wykorzystywane do operacji na elementach zbioru
Zespolone<int> Zbior::operator[] (int i) const
{
	return elem[i];
}

Zespolone<int> & Zbior::operator[] (int i)
{
	return elem[i];
}

//Funkcja sprawdzajaca czy przekazany element wystepuje juz w zbiorze
bool Zbior::czyPowtorzenie(const Zespolone<int> &z) const
{
	for (int i = 0; i<rozmiar; i++)
	{
		if(elem[i]==z) return true;
	}
	return false;
}

//Funkcje publiczne

//Przeciazone operatory
void Zbior::operator= (const Zbior &z)
{
	delete[] elem;
	rozmiar = z.rozmiar;
	
	elem = new Zespolone<int>[rozmiar];
	for (int i = 0; i<rozmiar; i++)
	{
		elem[i] = z.elem[i];
	}
}

Zbior Zbior::operator+ (const Zbior &z)
{
	Zbior nowy;
	for (int i = 0; i<rozmiar; i++)
	{
		nowy.dodaj(elem[i]);
	}
	for (int i = 0; i<z.rozmiar; i++)
	{
		if (!czyPowtorzenie(z.elem[i]))
		{
			nowy.dodaj(z.elem[i]);
		}
	}
	return nowy;
}

void Zbior::operator+= (const Zbior &z)
{
	for (int i = 0; i<z.rozmiar; i++)
	{
		if (!czyPowtorzenie(z.elem[i]))
		{
			dodaj(z.elem[i]);
		}
	}
}

Zbior Zbior::operator* (const Zbior &z)
{
	Zbior nowy;
	for(int i = 0; i<rozmiar; i++)
	{
		if(z.czyPowtorzenie(elem[i]))
		{
			nowy.dodaj(elem[i]);
		}
	}
	return nowy;
}

void Zbior::operator*= (const Zbior &z)
{
	*this = *this*z;
}

bool Zbior::operator== (const Zbior &z)
{
	if (rozmiar!=z.rozmiar) return false;
	
	for (int i = 0; i<rozmiar; i++)
	{
		if(!czyPowtorzenie(z.elem[i])) return false;
	}
	return true;
}

bool Zbior::operator!= (const Zbior &z)
{
	return !(*this==z);
}

//Funkcja dodajaca przekazany jej element do zbioru - informuje jesli element juz jest w zbiorze
void Zbior::dodaj(const Zespolone<int> &zesp)
{
	if (czyPowtorzenie(zesp))
	{
		std::cout<<"Element juz jest w zbiorze!"<<std::endl;
		return;
	}
	
	Zbior temp = *this;
	if(rozmiar != 0) delete[] elem;
	rozmiar++;
	elem = new Zespolone<int>[rozmiar];
	for (int i = 0; i<rozmiar-1; i++)
	{
		elem[i] = temp.elem[i];
	}
	elem[rozmiar-1]=zesp;
}

//Funkcja zwracajaca liczbe elementow zbioeu

int Zbior::podajIlosc()
{
	return ilosc;
}

//Funkcja zwracajaca ilosc zbiorow

/*Zespolone<int> & Zbior::getElement(int i)
{
	return elem[i];
}*/