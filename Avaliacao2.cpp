#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class Data {
	int dia, mes, ano;
	public:
	static int compara(Data d1, Data d2) { 
 if (d1.ano < d2.ano) {
            return -1;
        } else if (d1.ano > d2.ano) {
            return 1;
        } else {
            if (d1.mes < d2.mes) {
                return -1;
            } else if (d1.mes > d2.mes) {
                return 1;
            } else {
                if (d1.dia < d2.dia) {
                    return -1;
                } else if (d1.dia > d2.dia) {
                    return 1;
                } else {
                    return 0;
                }
            }
        }
    }
    
	Data(int _dia, int _mes, int _ano) {
		dia = _dia;
		mes = _mes;
		ano = _ano;
	}
	string toString() {
		string ret = "";
		ret.append(to_string(dia));
		ret.append("/");
		ret.append(to_string(mes));
		ret.append("/");
		ret.append(to_string(ano));
		return ret;
	}
};

class Lista {
	public:
	virtual void entradaDeDados() = 0;
	virtual void mostraMediana() = 0;
	virtual void mostraMenor() = 0;
	virtual void mostraMaior() = 0;
};

class ListaNomes : public Lista {
	vector<string> lista;
	
	public:
	void entradaDeDados() override {
		int n;
		string nm;
		cout << "Deseja inserir quantos nomes? " << endl;
		cin >> n;
		for (int i = 0; i < n; i++) {
			cout << "Digite o nome:" << endl;
			cin >> nm;
			lista.push_back(nm);
		}
	}
		
	void mostraMediana() {
	
		cout << "Aqui vai mostrar a mediana da lista de nomes" << endl;
	}
	
	void mostraMenor() {
	
		cout << "Aqui vai mostrar o primeiro nome alfabeticamente" << endl;
	}
	
	void mostraMaior() {

		cout << "Aqui vai mostrar o último nome alfabeticamente" << endl;
	}
};

class ListaDatas : public Lista {
	vector<Data> lista;
	
	public:
	void entradaDeDados() override {
	
         int n;
        cout << "Deseja inserir quantas datas? " << endl;
        cin >> n;
        
        for (int i = 0; i < n; i++) {
            int dia, mes, ano;
            cout << "Digite o dia (1-31): ";
            cin >> dia;
            cout << "Digite o mês (1-12): ";
            cin >> mes;
            cout << "Digite o ano: ";
            cin >> ano;
            
            // falta implementar a verificação de datas
            
            Data data(dia, mes, ano);
            lista.push_back(data);
        }
    }
	
	
	void mostraMediana() {

		cout << "Aqui vai mostrar a mediana da lista de datas" << endl;
	}
	
	void mostraMenor() {

		cout << "Aqui vai mostrar a primeira data cronologicamente" << endl;
	}
	
	void mostraMaior() {

		cout << "Aqui vai mostrar a última data cronologicamente" << endl;
	}
};

class ListaSalarios : public Lista {
	vector<float> lista;
	
	public:
	void entradaDeDados() override {

	}
	
	void mostraMediana() {

		cout << "Aqui vai mostrar a mediana da lista de salários" << endl;
	}
	
	void mostraMenor() {

		cout << "Aqui vai mostrar o menor dos salários" << endl;
	}
	
	void mostraMaior() {

		cout << "Aqui vai mostrar o maior dos salários" << endl;
	}
};

class ListaIdades : public Lista {
	vector<int> lista;
	
	public:
	void entradaDeDados() override {

	}
	
	void mostraMediana() {

		cout << "Aqui vai mostrar a mediana da lista de idades" << endl;
	}
	
	void mostraMenor() {

		cout << "Aqui vai mostrar a menor das idades" << endl;
	}
	
	void mostraMaior() {

		cout << "Aqui vai mostrar a maior das idades" << endl;
	}
};
 
int main() {
	vector<Lista*> listaDeListas;
	

	ListaNomes listaNomes;
	listaNomes.entradaDeDados();
	listaDeListas.push_back(&listaNomes);
	
	/* ListaDatas listaDatas;
	listaDatas.entradaDeDados();
	listaDeListas.push_back(&listaDatas);
	
	ListaSalarios listaSalarios;
	listaSalarios.entradaDeDados();
	listaDeListas.push_back(&listaSalarios);
	
	ListaIdades listaIdades;
	listaIdades.entradaDeDados();
	listaDeListas.push_back(&listaIdades);
	*/
	
	for (Lista* l : listaDeListas) {
		l->mostraMediana();
		l->mostraMenor();
		l->mostraMaior();
	}
}
