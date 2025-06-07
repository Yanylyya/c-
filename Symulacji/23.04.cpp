#include <iostream>
using namespace std;

class sklep{
	private:
		bool zamkniety;
		string rzeczy[50];
		int liczba;
		int haslo;
		string nazwa;
		string lista[5];
		int liczbapr;
		float ceny[50];
		
	bool otworz(int kod){
		if(kod!=haslo){
			cout << "\n\tNieprawiedlowy PIN!\n"; return false;
		}
		return true;
	}	
		
	public:
		sklep(string nazwa = "Zabka", int haslo = 0000){
			zamkniety = true;
			liczba = 0;
			liczbapr = 0;
			this-> haslo = haslo;
			cout << "\n\tOtworzono sklep o nazwie " << nazwa << " :)\n";
		}
			
	void zamknij(){
		if(zamkniety) return;
		zamkniety = true;
		cout << "\n\tSklep " << nazwa << " zamyka sie!\n"; }		
	
	void otworz(){
		if(!zamkniety){
			cout << "\n\tSklep jest juz otwarty!\n"; return; }
			
	int kod;	
	do{
		cout << "\n\tPodaj PIN: "; cin >> kod;
	}while(!otworz(kod));
	
	zamkniety = false;
	cout << "\n\t\tSklep otwiera sie!\n"; }	
	
	void dodaj(){
		if(zamkniety){
			cout << "\n\tSklep jest zamkniety!\n"; return; }
		if(liczba >= 50){
			cout << "\n\tNie mozesz dodac produkt!. Limit 50!\n"; return; }
			
	string przedmiot;
	float cena;
	cout << "\n\tPodaj produkt: "; cin >> przedmiot;
	rzeczy[liczba] = przedmiot;
	cout << "\n\tPodaj cene produktu: "; cin >> cena;
	ceny[liczba] = cena;
	
	liczba++;
	cout << "\n\tDodano produkt o nazwie " << przedmiot << " z cena " << cena << " PLN\n"; }
	
	void wyswietl(){
		if(zamkniety){
			cout << "\n\tSklep jest zamkniety!\n"; return; }	
			
	if(liczba == 0){
		cout << "\n\t\tNiema produktow w sklepie!\n"; return; }			
	
	cout << "\n\t\tProdukty w sklepie:\n";
	for(int i = 0; i < liczba; i++){
		cout << "\n\t- " << rzeczy[i] << " (" << ceny[i] << " PLN)\n"; }
}
	
	void dodajliste(){
		if(zamkniety){
			cout << "\n\tSklep jest zamkniety!\n"; return; }
		
	if(liczbapr >= 5){
		cout << "\n\t\tLista zakupow ma limit w 5 produktow!\n"; return; }		
	
	string ll;
	cout << "\n\tPodaj nazwe produkty do wpisywania w liste zakypow: "; cin >> ll;
	lista[liczbapr] = ll;
	liczbapr++; 
	cout << "\n\tDodano produkt do listy zakupy!\n"; }
	
	void wyswliste(){
		if(zamkniety){
			cout << "\n\tSklep jest zamkniety!\n"; return; }	
			
	if(liczbapr == 0 ){
		cout << "\n\tJeczsze nie dodano produktow do listy zakupow!\n"; return;	}		
	
	cout << "\n\tTwoja lista zakupow:\n";
	for(int i = 0; i < liczbapr; i++){
		cout << "\n\t" << i + 1 << ". " << lista[i] << endl; } 	
 }
 
 	void usun(){
 		if(zamkniety){
			cout << "\n\tSklep jest zamkniety!\n"; return; }
			
	if(liczbapr == 0 ){
		cout << "\n\tJeczsze nie dodano produktow do listy zakupow!\n"; return;	}	
		
	int indeks;
	cout << "\n\tPodaj numer produktu do usuniecia(1- "<< liczba << "): "; cin >> indeks;
	
	if(indeks < 1 || indeks > liczba){
		cout << "\n\tNieprawiedlowy numer!\n"; return; }	
	
	for(int i = indeks - 1; i < liczba - 1; i++){
		rzeczy[i] = rzeczy[i + 1]; }
	liczba--;
	
	cout << "\n\t\tProdukt usunieto!\n"; }
	
	void wyczysc(){
 	if(zamkniety){
		cout << "\n\tSklep jest zamkniety!\n"; return; }
		
	if(liczbapr == 0 ){
		cout << "\n\t\tLista jest pusta!\n"; return; }
	
	liczbapr = 0;
	cout << "\n\tListe zakupow wyczyczszono!\n"; }
	
	void sumacen(){
 	if(zamkniety){
		cout << "\n\tSklep jest zamkniety!\n"; return; }
		
	float suma = 0;
	for(int i = 0; i < liczba; i++){
		suma += ceny[i];
	}			
	
	cout << "\n\t\tLaczna wartosc wszystkich produktow " << suma << " PLN\n";
	}
	
	void szukaj (){
 	if(zamkniety){
		cout << "\n\tSklep jest zamkniety!\n"; return; }		
	
	string szukany;
	cout << "\n\tPodaj szukany produkt: "; cin >> szukany; 	
	bool znaleziono = false;
	
	for(int i = 0; i < liczba; i++){
		if(rzeczy[i] == szukany){
			cout << "\n\tZnaleziono " << rzeczy[i] << " -  " << ceny[i] << " PLN\n";
		znaleziono = true; break; }
	}
	
	if(!znaleziono){
		cout << "\n\tNie znaleziono takiego produkty!\n"; }	
	}
	
	void edytojcene(){
	if(zamkniety){	
		cout << "\n\tSklep jest zamkniety!\n"; return; }
			
	if(liczba == 0 ){
		cout << "\n\tBrak produktu dla edycji!\n"; return;	}	
		
	int indeks;
	cout << "\n\tPodaj numer produktu do usuniecia(1- "<< liczba << "): "; cin >> indeks;	
	
	if(indeks < 1 || indeks > liczba){
		cout << "\n\tNieprawiedlowy numer!\n"; return;
	}
	
	float nowa;
	cout << "\n\tPodaj nowa cene dla " << rzeczy[indeks - 1] << ": "; cin >> nowa;
	
	ceny[indeks - 1] = nowa;
	
	cout << "\n\tCene zaktualizowana!\n";
		
	}	
				
};

int main(int argc, char** argv) {
sklep vip("Zabka", 0000);

while(true){
	
cout << "\n\t\t1 - Otworz sklep\n"
	 << "\n\t\t2 - Zamknij sklep\n"
	 << "\n\t\t3 - Dodaj ptodukt\n"
	 << "\n\t\t4 - Wyswietl produkt\n"
	 << "\n\t\t5 - Dodaj produkt do listy zakupow\n"
	 << "\n\t\t6 - Wyswitl liste zakupow\n"	 
	 << "\n\t\t7 - Usun produkt\n"
	 << "\n\t\t8 - Wyczysc liste zakupow\n"
	 << "\n\t\t9 - Suma wszystkich produktow\n"
	 << "\n\t\t10 - Wyszukaj produkt\n"
	 << "\n\t\t11 - Edycja ceny\n"
	 << "\n\t\t0 - Wyjscie\n";
	 	 	 
int wybor;	
cout << "\n\tPodaj wybor: "; cin >> wybor;

switch(wybor){
	case 1: 
		vip.otworz();
	break;
	
	case 2: 
		vip.zamknij();
	break;
		
	case 3: 
		vip.dodaj();
	break;
	
	case 4: 
		vip.wyswietl();
	break;

	case 5: 
		vip.dodajliste();
	break;
	
	case 6: 
		vip.wyswliste();
	break;
	
	case 7: 
		vip.usun();
	break;
	
	case 8: 
		vip.wyczysc();
	break;	

	case 9: 
		vip.sumacen();
	break;	
	
	case 10: 
		vip.szukaj();
	break;	
	
	case 11: 
		vip.edytojcene();
	break;	
	
	case 0: 
		cout << "\n\t\tZanykanie programu :( \n";	return 0; 
	break;
	
	default:
		cout << "\n\t\tNiema takiego wyboru!\n";
	break; 							
	}
}
	
	return 0;
}
