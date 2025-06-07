#include <iostream>
using namespace std;

class Kawiarnia{
	private:
		bool zamkniety;
		const int rozmiar = 10;
		string nazwa[10];
		float cena[10];
		float ilosc[10];
		float karta;
		int liczbapr;
		int haslo;
		
bool otworz(int kod){
if(kod != haslo){
	cout << "\n\tNiprawiedlowuj PIN!\n"; return false; } 
return true;	
}	
		
	public:
		Kawiarnia(int kod) : zamkniety(true), karta(50.0), liczbapr(2), haslo(kod){
		nazwa[0] = "herbata", ilosc[0] = 12, cena[0] = 5;
		nazwa[1] = "kawa", ilosc[1] = 12, cena[1] = 7;
	}
	
void pokaz(){
	cout << "\n\t\tDzisziaj dostepne w kawiarnie:\n";
for(int i = 0; i < liczbapr; i++){
cout << "\n\t - " << nazwa[i] << " " << ilosc[i] << " szt."<< endl;
	}	
}
	
void ceny(){
	cout << "\n\t\tCeny na napoje: \n";
for(int i = 0; i < liczbapr; i++){
	cout << "\n\t" << nazwa[i] << " " << cena[i] << endl;
	}	
}

void kup(){
int wybor, ile;

cout << "\n\tCo chcesz kupic? Podaj numer 1 - " << liczbapr << ": "; cin >> wybor;	
wybor -= 1;

if(wybor < 0 || wybor > liczbapr){
	cout << "\n\tNieprawiedlowy numer!\n"; return; }
	
cout << "\n\tPodaj ilosc: "; cin >> ile;

if(ile <= 0){
	cout << "\n\tNieprawiedlowa ilosc!\n"; return; }	

if(ilosc[wybor] < ile){
	cout << "\n\tNie mamy sztuk na stanie!\n"; return; }
	
float koszt = cena[wybor] * ile;

if(karta < koszt){
	cout << "\n\tNie masz wystarczjaco pieniadzkow! :)\n"; return; } 

ilosc[wybor] -= ile;
karta -= koszt;

cout << "\n\tKupiles/las " << ile << " " << nazwa[wybor] << " za " << koszt << " zl\n";
}

void dodajpr(){
	if(liczbapr >= rozmiar){
		cout << "\n\tNie mozesz dodac wiecej produktow!\n"; return; }
string nowy;
int ile;
float cenapr;

cout << "\n\tPodaj nazwe nowego produkty: "; cin >> nowy;
cout << "\n\tPodaj ilosc produkty: "; cin >> ile;
cout << "\n\tPOdaj cene: "; cin >> cenapr;

nazwa[liczbapr] = nowy;
ilosc[liczbapr] = ile;
cena[liczbapr] = cenapr;
liczbapr++;

cout << "\n\tDodales/las " << nowy << " " << ile << " szt. Po " << cenapr << " zl.\n"; 			
}

void usun(){
	if(liczbapr == 0){
		cout << "\n\tNie ma produktow :(\n"; return; }
	
pokaz();

int numer;

cout << "\n\tPodaj numer do usuniecia 1 - " << liczbapr << ": "; cin >> numer;
numer -= 1;

if(numer < 0 || numer > liczbapr){
	cout << "\n\tNieprawiedlowy numer!!!\n"; return; }
	
cout << "\n\tUsuwam produkt " << nazwa[numer] << endl;

for(int i = numer; i < liczbapr - 1; i++){
	nazwa[i] = nazwa[i + 1];
	ilosc[i] = ilosc[i + 1];
	cena[i] = cena[i + 1];
}

liczbapr--;
cout << "\n\tProdukt zostal uduniety :)\n"; 	
}

void otworzk(){	
	if(!zamkniety){
		cout << "\n\tKonto otwarte!\n"; return;	}
int kod;	
do{
cout << "\n\tPodaj PIN: "; cin >> kod;
}while(!otworz(kod));

zamkniety = false;
cout << "\n\tKonto zostalo otwarte!\n"; 	
}

void kkarta(){
	if(zamkniety){
		cout << "\n\tKonto zamknieto!\n"; return; }	
		
cout << "\n\tMasz " << karta << " zl.\n";		
}

void doladuj(){
	if(zamkniety){
		cout << "\n\tKonto zamknieto!\n"; return; }
float zl;
cout << "\n\tPodaj ile chcesz dodac: "; cin >> zl;
karta += zl;

cout << "\n\tTeraz masz " << karta << endl;				
}
	
};

int main(){
Kawiarnia k(7777);	
int wybor;
while(true){
	cout << "\n\t1 - Popatrz co mamy\n"
		 << "\n\t2 - Ceny\n"
		 << "\n\t3 - Kup\n"
		 << "\n\t4 - Dodaj produkt\n"
		 << "\n\t5 - Usun produkt\n"
		 << "\n\t6 - Aktywuj konto\n"
		 << "\n\t7 - Ile srodkow masz?\n"
		 << "\n\t8 - Wplac na konto\n";
		 
cout << "\n\tPodaj wybor: "; cin >> wybor;

switch(wybor){
	case 1: 
		k.pokaz();
		break;
		
	case 2:
		k.ceny();
		break;	
	
	case 3:
		k.kup();
		break;
		
	case 4:
		k.dodajpr();
		break;
		
	case 5:
		k.usun();
		break;
		
	case 6:
		k.otworzk();
		break;
		
	case 7:
		k.kkarta();
		break;
		
	case 8:
		k.doladuj();
		break;								
	
	}		 
}	
	
return 0;
}
