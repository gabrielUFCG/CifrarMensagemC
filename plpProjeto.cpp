#include <iostream>
#include <string>

using namespace std;

char matriz[5][5]= {
  {'a','b','c','d','e'},
  {'f','g','h','i','j'},
  {'k','l','m','n','o'},
  {'p','q','r','s','t'},
  {'u','v','w','x','z'}
};
 
string  mensagem; 
bool completandaNumeroPar = false;

void tiraEspacos(string str){
	int i;
	string retorno;
	int tamanhoMensagem = str.size();
	for(i = 0 ;i < tamanhoMensagem; i++){
		if(str[i] != ' '){
			retorno += str[i] ;
		}
	}
	mensagem = retorno;
}

void colocaX(string str){
	
	string retorno;
	int tamanhoMensagem = str.size() - 1;
	for(int i = 0 ;i < tamanhoMensagem; i++){
		if(str[i] == str[i+1]){
			retorno += str[i];
			retorno += "x";
		}else{
			retorno += str[i];
			
		}
	}
	
	retorno += str[str.size()-1];

	if(retorno.size()%2 != 0){
		retorno += "x";
		completandaNumeroPar = true;
	}
	
	mensagem = retorno;
}


string condicaoLinha(int linhax, int colunax, int linhay, int colunay){
	string retorno;
	if(colunax == 4){
		colunax = -1;
	}
	
	if(colunay == 4){
		colunay = -1;
	}
	
	retorno += matriz[linhax][colunax+1];
	retorno += matriz[linhay][colunay+1];
	return retorno;
}

string condicaoColuna(int linhax, int colunax, int linhay, int colunay){
	string retorno;
	if(linhax == 4){
		linhax = -1;
	}
	
	if(linhay == 4){
		linhay = -1;
	}
	
	retorno += matriz[linhax+1][colunax];
	retorno += matriz[linhay+1][colunay];
	
	return retorno;
}

string condicaoRetangulo(int linhax, int colunax, int linhay, int colunay){
	string retorno;	
	retorno += matriz[linhay][colunax];
	retorno += matriz[linhax][colunay];
	
	return retorno;
}

string condicionaCifra(char x ,char y){
	int linhaX = -1;
	int colunaX = -1;
	int linhaY = -1;
	int colunaY = -1;
	
	int i = 0;
	
	while( i<5 && linhaX == -1){
		int j = 0;
		
		while(j<5 && linhaX == -1){
			if(matriz[i][j] == x){
				linhaX = i;
				colunaX = j;
			}
			j++;
		}
		i++;
	}
	
	i = 0;
	
	while(i<5 && linhaY == -1){	
		int j = 0;
		
		while(j<5 && linhaY == -1){
			if(matriz[i][j] == y){
				linhaY = i;
				colunaY = j;
			}
			j++;
		}
		
		i++;
	}


	if(linhaX == linhaY){
		return condicaoLinha(linhaX,colunaX,linhaY,colunaY);
		
	}else if(colunaX == colunaY){
		return condicaoColuna(linhaX,colunaX,linhaY,colunaY);
		
	}else {
		return condicaoRetangulo(linhaX,colunaX,linhaY,colunaY);
	}
		
}


void cifra2a2(string str){
	string cifra;
	int tamanhoMensagem = str.size();
	for(int i = 0 ;i < tamanhoMensagem; i+=2){
		cifra += condicionaCifra(str[i],str[i+1]);
	}
	mensagem = cifra;

}

string condicaoDecifraLinha(int linhax, int colunax, int linhay, int colunay){
	string retorno;
	if(colunax == 0){
		colunax = 5;
	}
	
	if(colunay == 0){
		colunay = 5;
	}
	
	retorno += matriz[linhax][colunax-1];
	retorno += matriz[linhay][colunay-1];
	return retorno;
}

string condicaoDecifraColuna(int linhax, int colunax, int linhay, int colunay){
	string retorno;
	if(linhax == 0){
		linhax = 5;
	}
	
	if(linhay == 0){
		linhay = 5;
	}
	
	retorno += matriz[linhax-1][colunax];
	retorno += matriz[linhay-1][colunay];
	
	return retorno;
}

string condicaoDecifraRetangulo(int linhax, int colunax, int linhay, int colunay){
	string retorno;	
	retorno += matriz[linhay][colunax];
	retorno += matriz[linhax][colunay];
	
	return retorno;
}

string condicionaDeciframento(char x ,char y){
	int linhaX = -1;
	int colunaX = -1;
	int linhaY = -1;
	int colunaY = -1;
	
	int i = 0;
	
	while( i<5 && linhaX == -1){
		int j = 0;
		
		while(j<5 && linhaX == -1){
			if(matriz[i][j] == x){
				linhaX = i;
				colunaX = j;
			}
			j++;
		}
		i++;
	}
	
	i = 0;
	
	while(i<5 && linhaY == -1){	
		int j = 0;
		
		while(j<5 && linhaY == -1){
			if(matriz[i][j] == y){
				linhaY = i;
				colunaY = j;
			}
			j++;
		}
		
		i++;
	}


	if(linhaX == linhaY){
		return condicaoDecifraLinha(linhaX,colunaX,linhaY,colunaY);
		
	}else if(colunaX == colunaY){
		return condicaoDecifraColuna(linhaX,colunaX,linhaY,colunaY);
		
	}else {
		return condicaoDecifraRetangulo(linhaX,colunaX,linhaY,colunaY);
	}
		
}

void decifra2a2(){
	string decifra;
	int tamanhoMensagem = mensagem.size();
	for(int i = 0 ;i < tamanhoMensagem; i+=2){
		decifra += condicionaDeciframento(mensagem[i],mensagem[i+1]);
	}
	mensagem = decifra;
}

void cifra(){
	completandaNumeroPar = false;
	getline(cin,mensagem);
	tiraEspacos(mensagem);
	colocaX(mensagem);
	cifra2a2(mensagem);
	
}

void verAlfabeto(){
	int i = 0;
	string alfabeto;
	
	while( i<5 ){
		int j = 0;
		
		while(j<5 ){
			alfabeto += matriz[i][j];
			if(j == 4){
				alfabeto += "\n";
			}
		
			j++;
		}
		i++;
	}
	cout << alfabeto << endl;

}

void encontraFalsoX(){
	int tamanhoMensagem = mensagem.size();
	for (int i=1; i < tamanhoMensagem-1 ; i++){
		if( mensagem[i-1] == mensagem[i+1] && mensagem[i] == 'x' ) {
			mensagem[i] = 'y';
		} 
		
	}
	if(completandaNumeroPar){
		mensagem[tamanhoMensagem-1] = 'y';
	}
}

void retirarX(){
	string retorno;
	int tamanhoMensagem = mensagem.size();
	for(int i=0 ; i< tamanhoMensagem ; i++ ){
		if(mensagem[i] != 'y'){
			retorno += mensagem[i];
		}
	}
	mensagem = retorno;
}

void decifra(){
	decifra2a2();
	encontraFalsoX();
	retirarX();
}

void redefineTabela(){
	string novaMatriz;
	int k = 0;
	
	cout << "Digite as 25 trs do alfabeto sem repetir (desconsidere 'y'): " << "\n" <<  endl;
	getline(cin,novaMatriz);
	
	for(int i=0 ; i<5 ; i++){
		for(int j=0 ; j<5 ; j++){
			matriz[i][j] = novaMatriz[k];
			k++;
		}
	}
	
}

int main(){
	bool terminar = true;
	int opcoes;
	while(terminar){
		
		cout << "Digite o numero da opcao\n"<<
		"1. Escolher uma tabela de cifra nova\n" <<
		"2. Introduzir uma mensagem para cifrar\n" << 
		"3. Ver a mensagem cifrada\n" <<
		"4. Decifrar a mensagem\n" <<
		"5. Ver o alfabeto\n" <<
		"6. Terminar\n" << endl;
		cin>>opcoes;
		cin.ignore ();
		
		switch (opcoes){
			case 1:
				redefineTabela();
				break;	
			case 2:
				cout << "Digite a mensagem" << endl;
				cifra();
				cout << "Mensagem cifrada com sucesso" << "\n" << endl;
				break;
			case 3:
				cout << "Cifra: " << mensagem << "\n" <<  endl;
				break;
			case 4:
				decifra();
				cout << "mensagem decifrada: " << mensagem << "\n" <<  endl;
				break;
			case 5:
				verAlfabeto();
				break;
			case 6:
				terminar = false;
				break;
		}
		
	}
	
}
