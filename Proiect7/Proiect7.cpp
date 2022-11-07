#include <iostream>
using namespace std;

enum culoareSemafor {rosu = 10, galben = 20, galbenIntermitent = 25 ,verde = 30};

union eticheta
{
	short v1;
	int v2;
	long long v3;
};

struct Carte
{
	int nrPagini;
	float pret;
	char titlu[21];
	char autor[21];
};

class TelefonMobil
{	public: 
	  int nivelBaterie;

	void incarca(int nivelIncarcare)
	{
		nivelBaterie += nivelIncarcare;
	}
	protected:
	   string producator;
	private:
	   string model;
};

int main()
{
	culoareSemafor c1 = culoareSemafor::galben;
	cout << c1 << endl; // afiseaza 20
	c1 = (culoareSemafor)30;
	cout << c1 << endl; // afiseaza verde

	cout << sizeof(eticheta) << endl; // ia dimensiunea cea mai mare, adica v3 care este 8 din cauza a long long
	eticheta e1;
	e1.v3 = 9999999;
	cout << e1.v1 << " " << e1.v2 << " " << e1.v3 << endl;

	e1.v3 = 7;
	cout << e1.v1 << " " << e1.v2 << " " << e1.v3 << endl;

	cout << sizeof(Carte) << endl; // afiseaza 52, deoarece suma bytes-ilor din struct este 50, IDE-ul afiseaza doar multipli de 4, de aceea apare 52, si lasa 2 bytes liberi

	Carte carte1;
	carte1.nrPagini = 50;
	carte1.pret = 50.5;
	strcpy_s(carte1.titlu, "Limbajul C++");
	cout << carte1.titlu << " " << carte1.pret << endl;

	TelefonMobil telefonPersonal;
	TelefonMobil telefonDeServiciu;

	telefonPersonal.nivelBaterie = 20;
	telefonPersonal.incarca(50);
	cout << telefonPersonal.nivelBaterie << endl;

}
