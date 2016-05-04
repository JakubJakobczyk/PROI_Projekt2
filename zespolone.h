/*
Projekt 2 1812
Autor: Jakub Jakobczyk
Prowadzacy: dr inż. Piotr Witonski
*/

#ifndef ZESPOLONE_H_INCLUDED
#define ZESPOLONE_H_INCLUDED

#include <cmath>

template<class Typ>
class Zespolone
{
private:
	Typ rzecz;
    Typ uroj;

public:
	
	//konstruktor
	Zespolone(Typ a = 0, Typ b = 0): rzecz(a), uroj(b)
	{
		#ifdef _DEBUG
		std::cout<<"Konstruktor l. zespolonej "<<a<<"+"<<b<<"j"<<std::endl;
		#endif
	}

	//destruktor
    ~Zespolone()
	{
		#ifdef _DEBUG
		std::cout<<"Destruktor l. zespolonej "<<rzecz<<"+"<<uroj<<"j"<<std::endl;
		#endif
	}

    //przeciazone operatory
    Zespolone operator+ (Zespolone &z)
	{
		Typ r, u;

		r = rzecz+z.rzecz;
		u = uroj+z.uroj;

		return Zespolone(r, u);
	}
	
    void operator+= (Zespolone &z)
	{
		Typ r,u;

		r = rzecz+z.rzecz;
		u = uroj+z.uroj;

		rzecz = r;
		uroj = u;
	}
	
    Zespolone operator- (Zespolone &z)
	{
		Typ r, u;

		r = rzecz-z.rzecz;
		u = uroj-z.uroj;

		return Zespolone(r, u);
	}

    void operator-= (Zespolone &z)
	{
		Typ r,u;

		r = rzecz-z.rzecz;
		u = uroj-z.uroj;

		rzecz = r;
		uroj = u;
	}
	
    Zespolone operator* (Zespolone &z)
	{
		Typ r, u;
	
		r = (rzecz*z.rzecz)-(uroj*z.uroj);
		u = (rzecz*z.uroj)+(uroj*z.rzecz);
	
		return Zespolone(r, u);
	}

    void operator*= (Zespolone &z)
	{
		Typ r, u;
	
		r = (rzecz*z.rzecz)-(uroj*z.uroj);
		u = (rzecz*z.uroj)+(uroj*z.rzecz);
	
		rzecz=r, uroj=u;
	}
	
	bool operator== (const Zespolone &z)
	{
		if(rzecz == z.rzecz && uroj == z.uroj) return true;
		else return false;
	}
	
	//funkcje
    double mod() //funkcja zwraca modol liczby zespolonej
	{
		Typ a, b;
		a = rzecz;
		a = a*a;
		b = uroj;
		b = b*b;
		a = a+b;
		return sqrt(a);
	}
	
//przeciazony operator strumienia
	friend std::ostream & operator<< (std::ostream &wyjscie, const Zespolone &z)
	{
		return wyjscie<<z.rzecz<<"+"<<z.uroj<<"j";
	}
};


#endif // ZESPOLONE_H_INCLUDED
