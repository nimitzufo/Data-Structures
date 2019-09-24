#include <iostream>
#include <string>
using namespace std;

typedef struct Cadastro {
	int code=0;
	char name[30];
	int age;
	float height;	
} CADASTRO;

CADASTRO agenda[2];

void include(){
	int codigo;
	cout << "Codigo: " << endl;
	for(auto i:agenda){
		if(agenda->code==codigo){
			cout << "valor ja existente" << endl;
			return;
		}
	}
	for(int i=0;i!=3;i++){
		if(agenda[i].code==0){
			agenda[i].code=codigo;
		}
		cout << "Nome: " << endl;
		cin >> agenda[i].name;;
		cout << "Idade: " << endl;
		cin >> agenda[i].age;
		cout << "Altura: " << endl;
		cin >> agenda[i].height;
		break;
	}
}

void erase(){
	int codigo, pos=-1;
	cout << "Codigo do cadastro a ser excluido: " << endl;
	cin >> codigo;
	if(agenda==nullptr){
		cout<< "Nao existem cadastros" << endl;
	}
	for(int i=0;i!=3;i++){
		if(agenda[i].code==codigo){
			pos = i;
		}
	}
	agenda[pos].code=0;
	agenda[pos].age=0;
	agenda[pos].height=0;
}

void change(){
	int cod, pos;
	cout << "Codigo: " << endl;
	cin >> cod;
	for(int i=0;i!=3;i++){
		if(agenda[i].code==cod){
			pos = i;
		} else {
			cout << "Registro inexistente" << endl;
			return;
		}
	}
	cout << "Novo codigo: " << endl;
	cin >> agenda[pos].code;
	cout << "Novo nome: " << endl;
	cin >> agenda[pos].name;
	cout << "Nova idade: " << endl;
	cin >> agenda[pos].age;
	cout << "Nova altura: " << endl;
	cin >> agenda[pos].height;
	cout << "Cadastro alterado" << endl;
}

void list(){
	for(int i=0;i!=3;i++){
		cout << agenda[i].code << endl;
		cout << agenda[i].name << endl;
		cout << agenda[i].age << endl;
		cout << agenda[i].height << endl;
	}
}

int main(){
	bool over = false;
	int op;
	while(!over){
		cout << "Escolha op" << endl;
		cout << "Incluir(1)\nExcluir(2)\nAlterar(3)\nListar(4)\nsair(0)" << endl;
		switch (op){
			case 1:
				include();
				break;
			case 2:
				erase();
				break;
			case 3:
				change();
				break;
			case 4:
				list();
				break;
			case 0:
				over = true;
				break;	
			default:
				cout << "op invalida, escolha op valida" << endl;						
		}
	}
	
	return 0;
}
