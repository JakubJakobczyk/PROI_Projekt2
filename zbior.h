/*
Projekt 2 1812
Autor: Jakub Jakobczyk
Prowadzacy: dr inż. Piotr Witonski
*/


#ifndef ZBIOR_H_INCLUDED
#define ZBIOR_H_INCLUDED

#include "zespolone.h"

class Zbior
{
	private:
		static int ilosc; //Zmienna statyczna - informuje o liczbie istniejacych obiektow klasy Zbior
		int rozmiar; //Zmienna informuje o ilosci elementow w zbiorze
		Zespolone<int> *elem; //Wskaznik na obiekty przechowywane w zbiorze
		
		//Operatory [] wykorzystywane do operacji na elementach zbioru
		Zespolone<int> operator[] (int i) const;
		Zespolone<int> & operator[] (int i);
		//Funkcja sprawdzajaca czy przekazany element wystepuje juz w zbiorze
		bool czyPowtorzenie(const Zespolone<int> &z) const;
	public:
		//Konstruktory
		Zbior();
		Zbior(Zespolone<int> z1, int n=1);
		Zbior(const Zbior &z); //Konstruktor kopiujacy
		//Destruktor
		~Zbior();
		
		//Przeciazone operatory
		void operator= (const Zbior &z);
		Zbior operator+ (const Zbior &z);
		void operator+= (const Zbior &z);
		Zbior operator* (const Zbior &z);
		void operator*= (const Zbior &z);
		bool operator== (const Zbior &z);
		bool operator!= (const Zbior &z);
		
		
		//Funkcja dodajaca przekazany jej element do zbioru - informuje jesli element juz jest w zbiorze
		void dodaj(const Zespolone<int> &zesp);
		//Funkcja zwracajaca liczbe elementow zbioeu
		int podajIlosc();
		//Funkcja zwracajaca ilosc zbiorow
		//Zespolone<int> & getElement(int);
	
	//Przeciazony operator strumienia - wypisuje elementy odzielone spacja lub informuje o zbiorze pustym
	friend std::ostream & operator<<(std::ostream &wyjscie, const Zbior &z)
	{
		if (z.rozmiar==0)
		{
			wyjscie<<"zbior pusty";
		}
		for(int i = 0; i<z.rozmiar; i++)
		{
			wyjscie<<z[i]<<" ";
		}
		return wyjscie;
	}
};

#endif // ZBIOR_H_INCLUDED