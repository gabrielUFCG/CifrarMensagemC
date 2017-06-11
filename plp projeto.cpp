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


void recebeMenssagem(){
	getline(cin,menssagem);
	/* 
	tiraEspacos(menssagem);
	verificaCondicaoX(menssagem);
	cifraMenssagem(menssagem);
	*/
}

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
	cout << "linha" << endl;
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
	cout << "coluna" << endl;
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
	cout << "retangulo" << endl;
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


int main(){
	recebeMenssagem();
	cout << menssagem << " menssagem recebida"<< endl;
	tiraEspacos(menssagem);
	cout << menssagem << " sem os espacos" << endl;
	verificaCondicaoX(menssagem);
	cout << menssagem << " condicoes de modificaçao"<< endl;
	cifraMenssagem(menssagem);
	cout << menssagem << " menssagem cifrada"<< endl;
	
}
