#include <iostream>
using namespace std;

class kasa{
	private:
		bool zamkniety;
		float saldo;
		int haslo;
		int liczbaWpl;
		int liczbaWypl;
		float obrot;

	bool otworz(int kod){
		if(kod != haslo){
			cout << "\n\tNieprawiedlowe haslo!\n"; 
			return false;
		}
	return true;	
	}
	
	bool otw(int stare){
		if(stare != haslo){
			cout << "\n\tZle haslo!\n"; return false;
		}
	return true;	
	}		
		
	public: 
		kasa(int haslo = 1234){
			this->haslo = haslo;
			saldo = 0;
			zamkniety = true;
			liczbaWypl = 0;
			liczbaWpl = 0;
			obrot = 0;
		}
		
	void otworz(){
		if(!zamkniety){
			cout << "\n\tKasa jest kuz otwarta!\n"; return; 
		}
	int kod;
	do{
		cout << "\n\tPodaj PIN: "; cin >> kod;
	}while(!otworz(kod));
	
	zamkniety = false;	
	cout << "\n\tKasa zoztala otwarta!\n"; }	
	
	void zamkniej(){
		if(zamkniety) return;
		zamkniety = true;
		cout << "\n\tKasa zostala zamknieta!\n"; }
	
	void dodaj(){
		if(zamkniety){
			cout << "\n\tKasa jest zamknita!\n"; return; }
	
	float ile;
	cout << "\n\tIle pieniedzy dodac: "; cin >> ile;

	if(ile < 0){
		cout << "\n\tNie mozesz dodac ujemnej kwoty!\n"; return; }

	saldo += ile;	
	cout << "\n\tDodano pienidze. Nowe saldo: " << saldo << " PLN\n";	
	liczbaWpl++;
	obrot += ile;
}

	void wyplac(){
		if(zamkniety){
			cout << "\n\tKasa jest zamknita!\n"; return; }
		
	float ile;
	cout << "\n\tIle pienidzy wyplacic: "; cin >> ile;
	
	if(ile > saldo ){
		cout << "\n\tZa malo srodkow w kasie!\n"; return; }
		
	saldo -= ile;
	cout << "\n\tWyplacono pienidze. Nowe saldo: " << saldo << " PLN\n";
	
	liczbaWypl++;
	obrot += ile;
	}
	
	void pokaz(){
		if(zamkniety){
			cout << "\n\tKasa jest zamknita!\n"; return; }	
			
	cout << "\n\tSaldo: " << saldo << " PLN\n";			
	}
	
	void wyczysc(){
		if(zamkniety){
			cout << "\n\tKasa jest zamknita!\n"; return; }
	if(saldo==0){
		cout << "\n\tJuz jest pusto!\n"; return;
	}		
	saldo = 0;
	cout << "\n\tKasa zostala okradziona!\n";			
	}
	
	void zmienhaslo(){
		if(zamkniety){
			cout << "\n\tKasa jest zamknita!\n"; return; }	
			
	int stare, nowe;
	do{
	cout << "\n\tPodaj stare haslo: "; cin >> stare;
	}while(!otw(stare));
		
	cout << "\n\tPodaj nowe haslo: "; cin >> nowe;
	haslo = nowe;
	
	cout << "\n\tHaslo zostalo zmienione!\n"; 					
	}

	void statystyki(){
		if(zamkniety){
			cout << "\n\tKasa jest zamknieta!\n"; return;}
	cout << "\n\tStatystyki kasy:";
	cout << "\n\t- Liczba wplat: " << liczbaWpl;
	cout << "\n\t- Liczba wyplat: " << liczbaWypl;
	cout << "\n\t- Obrot calkowity: " << obrot << " PLN\n";
}

		
};

int main(){
	
kasa vip(0000);

while(true){
	cout << "\n\t\t1 - Otworz kase\n"
		 << "\n\t\t2 - Zamknij kase\n"
		 << "\n\t\t3 - Wplac pienidze\n"
		 << "\n\t\t4 - Wyplac pienidze\n"
		 << "\n\t\t5 - Pokaz saldo\n"
		 << "\n\t\t6 - Wyczycs kase\n"
		 << "\n\t\t7 - Zmien haslo\n"
		 << "\n\t\t8 - Statystyka\n";
		 
int wybor; 
cout << "\n\tPodaj wybor: "; cin >> wybor;

switch(wybor){
	case 1:
		vip.otworz();
	break;	
	
	case 2:
		vip.zamkniej();
	break;	
	
	case 3:
		vip.dodaj();
	break;	
	
	case 4:
		vip.wyplac();
	break;		
	
	case 5:
		vip.pokaz();
	break;	
	
	case 6:
		vip.wyczysc();
	break;
	
	case 7:
		vip.zmienhaslo();
	break;
	
	case 8:
		vip.statystyki();
	break;	
	
	
	default: 
		cout << "\n\tNiema takiego wyboru!\n";
	break;	
	
}
}		
	return 0;
}
