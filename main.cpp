/*
Projekt 2 1812
Autor: Jakub Jakobczyk
Prowadzacy: dr inż. Piotr Witonski
*/



/*Odkomentowac przy debugowaniu, pozwala na sledzenie konstruktorow i destruktorow*/
//#define _DEBUG 1

#include <iostream>
#include <cstdio>

#include "zespolone.h"
#include "zbior.h"

using namespace std;

int main()
{
	//Test automatyczny
    Zespolone<int> l1(1,2), l2(3,4), l3(5,6), l4(7,8), l5(9,10), l6(1,2), l7(3,4);
	cout<<"Stowrzylem liczby  o wspolczynnikach calkowitych: "<<l1<<" "<<l2<<" "<<l3<<" "<<l4<<" "<<l5<<" "<<l6<<" "<<l7<<endl;
	cout<<"Tworze zbior z1"<<endl;
	Zbior z1;
	cout<<"Ilosc zbiorow to: "<<z1.podajIlosc()<<endl;
	
	cout<<"Dodaje liczby do zbioru z1: "<<l1<<","<<l2<<","<<l3<<endl;
	z1.dodaj(l1);
	z1.dodaj(l2);
	z1.dodaj(l3);
	
	cout<<"Zbior z1: "<<z1<<endl;
	
	cout<<"Probuje dodac ponownie "<<l1<<endl;
	z1.dodaj(l1);
	
	cout<<endl<<"Tworze z2 rowny z1"<<endl;
	Zbior z2=z1;
	
	cout<<"Ilosc zbiorow to: "<<z1.podajIlosc()<<endl;
	
	cout<<"Tworze zbior z3 z liczby: "<<l4<<endl;
	Zbior z3(l4);
	cout<<"Dodaje do zbioru z3 liczby: "<<l5<<","<<l6<<","<<l7<<endl;
	z3.dodaj(l5);
	z3.dodaj(l6);
	z3.dodaj(l7);
	
	cout<<"Tworze zbior z4 - pusty"<<endl;
	Zbior z4;
	
	cout<<endl<<"Ilosc zbiorow to: "<<z1.podajIlosc()<<endl;
	cout<<"Zbior z1: "<<z1<<endl;
	cout<<"Zbior z2: "<<z2<<endl;
	cout<<"Zbior z3: "<<z3<<endl;
	cout<<"Zbior z4: "<<z4<<endl;
	
	cout<<endl<<"Test operatorow '==' oraz '=!' <1-prawda 0-falsz>"<<endl;
	cout<<"z1==z2: "<<(int)(z1==z2)<<endl;
	cout<<"z1==z3: "<<(int)(z1==z3)<<endl;
	cout<<"z1!=z3: "<<(int)(z1!=z3)<<endl;
	cout<<"z1!=z2: "<<(int)(z1!=z2)<<endl;
	
	cout<<endl<<"Operator '+'"<<endl;
	cout<<"z1+z2= {"<<z1+z2<<"}"<<endl;
	cout<<"z1+z3= {"<<z1+z3<<"}"<<endl;
	cout<<"z1+z4= {"<<z1+z4<<"}"<<endl;
	
	cout<<endl<<"Operator '+=': z1+=z3"<<endl;
	z1+=z3;
	cout<<"z1 = {"<<z1<<"}"<<endl;
	
	cout<<endl<<"Zbior z1: "<<z1<<endl;
	cout<<"Zbior z2: "<<z2<<endl;
	cout<<"Zbior z3: "<<z3<<endl;
	cout<<"Zbior z4: "<<z4<<endl;
	
	cout<<endl<<"Operator '*'"<<endl;
	cout<<"z2*z3= {"<<z2*z3<<"}"<<endl;
	cout<<"z1*z4= {"<<z1*z4<<"}"<<endl;
	cout<<"z1*z2= {"<<z1*z2<<"}"<<endl;
	
	cout<<endl<<"Operator '*=': z2*=z3"<<endl;
	z2*=z3;
	cout<<"z2 = {"<<z2<<"}"<<endl;
	
    return 0;
}