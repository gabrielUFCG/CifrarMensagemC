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
 
string  menssagem; 


void tiraEspacos(string str){
	int i;
	string retorno;
	for(i = 0 ;i < str.size(); i++){
		if(str[i] != ' '){
			retorno += str[i] ;
		}
	}
	menssagem = retorno;
}

void verificaCondicaoX(string str){
	
	int i;
	string retorno;
	
	for(i = 0 ;i < str.size()-1; i++){
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
	}
	
	menssagem = retorno;
}


string linha(int linhax, int colunax, int linhay, int colunay){
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

string coluna(int linhax, int colunax, int linhay, int colunay){
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

string retangulo(int linhax, int colunax, int linhay, int colunay){
	string retorno;	
	retorno += matriz[linhay][colunax];
	retorno += matriz[linhax][colunay];
	
	return retorno;
}

string valorLinhaEColuna(char x ,char y){
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
		return linha(linhaX,colunaX,linhaY,colunaY);
		
	}else if(colunaX == colunaY){
		return coluna(linhaX,colunaX,linhaY,colunaY);
		
	}else {
		return retangulo(linhaX,colunaX,linhaY,colunaY);
	}
		
}

void cifraMenssagem(string str){
	string cifra;
	int i;
	for( i = 0 ;i < str.size(); i+=2){
		cifra += valorLinhaEColuna(str[i],str[i+1]);
	}
	menssagem = cifra;

}

string decifralinha(int linhax, int colunax, int linhay, int colunay){
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

string decifracoluna(int linhax, int colunax, int linhay, int colunay){
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

string decifraretangulo(int linhax, int colunax, int linhay, int colunay){
	string retorno;	
	retorno += matriz[linhay][colunax];
	retorno += matriz[linhax][colunay];
	
	return retorno;
}

string decifravalorLinhaEColuna(char x ,char y){
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
		return decifralinha(linhaX,colunaX,linhaY,colunaY);
		
	}else if(colunaX == colunaY){
		return decifracoluna(linhaX,colunaX,linhaY,colunaY);
		
	}else {
		return decifraretangulo(linhaX,colunaX,linhaY,colunaY);
	}
		
}

void decifraMenssagem(){
	string decifra;
	int i;
	for( i = 0 ;i < menssagem.size(); i+=2){
		decifra += decifravalorLinhaEColuna(menssagem[i],menssagem[i+1]);
	}
	menssagem = decifra;
}

void recebeMenssagem(){
	getline(cin,menssagem);
	cin.ignore ();
	tiraEspacos(menssagem);
	verificaCondicaoX(menssagem);
	cifraMenssagem(menssagem);
	
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
				break;	
			case 2:
				cout << "Digite a menssagem" << endl;
				recebeMenssagem();
				cout << "Menssagem cifrada com sucesso" << endl;
				break;
			case 3:
				cout << "Cifra: " << menssagem <<  endl;
				break;
			case 4:
				decifraMenssagem();
				cout << "menssagem decifrada: " << menssagem <<  endl;
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
