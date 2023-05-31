#include <iostream>
#include <fstream>
#include <string>

using namespace std;

void leggi() {
	char cletto;
	int alunni=0;
	ifstream elenco("palom.txt");
	
	while (elenco.get(cletto)) {
		if(cletto==';'){
			cout << " || ";	
			alunni++;
		}
		else {
			cout << cletto;
		}	
	}
	
	elenco.close();
	cout<<endl;
	cout<<"Gli alunni sono: "<<alunni;
	return;
}
void scrivi() {
	
	int nalunni;	
	ofstream Documento("palom.txt");
	
	cout<<"Quanti alunni deve segnare? ";
	cin>>nalunni;
	nalunni++;
	for(int i = nalunni; i>0; i--) {
		char Nome[100];
		
		cout<<"Inserire nome e il cognome. (dividere il nome e il cognome con ;): ";
		cin.getline(Nome, 100);
		Documento<<Nome;
		Documento<<endl;
	}	
	
	Documento.close();
	cout<<"Documento creato correttamente!";
	return;
}
void richiesta(int &nvolte) {
	char scelta;
	bool capito=true;
	
	while(capito==true) {
		capito=true;
		
		if(nvolte>0) {
			cout<<"Inserisci 0 se vuoi leggere altrimenti 1 se vuoi scrivere: ";
			cin>>scelta;
			if(scelta=='0') {
				leggi();
				capito=false;
			}
			else if(scelta=='1'){
				scrivi();
				capito=false;
			}
			else {
				cout<<"Non ho capito :/ \n";
			}
		}
		else {
			cout<<"Inserisci 0 se vuoi uscire 1 se vuoi scrivere: ";
			cin>>scelta;
			if(scelta=='0') {
				nvolte+=1;	
				capito=false;
			}
			else if(scelta=='1'){
				nvolte+=1;
				scrivi();
				capito=false;
			}
			else {
				cout<<"Non ho capito :/ \n";
			}		
		}		
	}
	return;
}
int main() {
	char scelta2;
	bool capito2=true;
	int volte=0;
	richiesta(volte);
	while(capito2==true) {
		capito2=true;
		cout<<"\n"<<"vuoi continuare?(si=1 no=0): ";
		cin>>scelta2;
		if(scelta2=='1') {
			richiesta(volte);
			capito2=true;
		}
		else if(scelta2=='0'){
			capito2=false;
		}
		else {
			cout<<"Non ho capito, ripeti: \n";
		}	
	}	
	return 0;
}
