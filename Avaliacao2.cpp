#include <iostream>
#include <string>
#include <vector>
#include<algorithm>

using namespace std;

class Data {
    int dia, mes, ano;

public:
    static int compara(Data d1, Data d2) {
        if (d1.ano < d2.ano || (d1.ano == d2.ano && (d1.mes < d2.mes || (d1.mes == d2.mes && d1.dia < d2.dia)))) {
            return -1;
        } else if (d1.ano == d2.ano && d1.mes == d2.mes && d1.dia == d2.dia) {
            return 0;
        } else {
            return 1;
        }
    };

    Data(int _dia, int _mes, int _ano) {
        dia = _dia;
        mes= _mes;
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
    virtual void listarEmOrdem() = 0;
};

class ListaNomes : public Lista {
    vector<string> lista;

public:
    void entradaDeDados() override {
        int n;
        string nm;
        cout << "Deseja inserir quantos nomes? " << endl;
        cin >> n;
        cin.ignore(); 
        for (int i = 0; i < n; i++) {
            cout << "Digite o nome:" << endl;
            getline(cin, nm);
            lista.push_back(nm);
        }
    }

    void mostraMediana() {
        if (lista.empty()) {
            cout << "A lista de nomes esta vazia, nao eh possivel calcular a mediana." << endl;
        } else {
            sort(lista.begin(), lista.end());
            int size = lista.size();
            if (size % 2 == 0) {
                cout << "A mediana eh indefinida. O primeiro nome em ordem alfabetica eh: " << lista[size / 2 - 1] << endl;
            } else {
                cout << "A mediana da lista de nomes eh: " << lista[size / 2] << endl;
            }
        }
    }

    void mostraMenor() {
        if (lista.empty()) {
            cout << "A lista de nomes esta vazia, não eh possivel encontrar o menor nome." << endl;
        } else {
            sort(lista.begin(), lista.end());
            cout << "O menor nome em ordem alfabetica eh: " << lista.front() << endl;
        }
    }

    void mostraMaior() {
        if (lista.empty()) {
            cout << "A lista de nomes esta vazia, nao eh possivel encontrar o maior nome." << endl;
        } else {
            sort(lista.begin(), lista.end());
            cout << "O maior nome em ordem alfabetica eh: " << lista.back() << endl;
        }
    }
     void listarEmOrdem() {
        sort(lista.begin(), lista.end());
        for (const string& nome : lista) {
            cout << nome << endl;
        }
    }
};


class ListaDatas : public Lista  {
	vector<Data> lista;
	
	public:
	void entradaDeDados() override {
		int n;
        cout << "Quantas datas deseja adicionar? ";
        cin >> n;
        for (int i = 0; i < n; i++) {
            int dia, mes, ano;
            cout << "Digite o dia, mes e ano (formato DD MM AAAA): ";
            cin >> dia >> mes >> ano;
            Data data(dia, mes, ano);
            lista.push_back(data);
        }
    }
		
	
	void mostraMediana() {
        if (lista.empty()) {
            cout << "A lista de datas esta vazia." << endl;
        } else {
            sort(lista.begin(), lista.end(), [](const Data& d1, const Data& d2) {
                return Data::compara(d1, d2) < 0;
            });
            int meio = lista.size() / 2;
            cout << "Mediana: " << lista[meio].toString() << endl;
        }
    }
	
	   void mostraMenor() {
        if (lista.empty()) {
            cout << "A lista de datas esta vazia." << endl;
        } else {
            sort(lista.begin(), lista.end(), [](const Data& d1, const Data& d2) {
                return Data::compara(d1, d2) < 0;
            });
            cout << "Menor data: " << lista.front().toString() << endl;
        }
    }

    void mostraMaior() {
        if (lista.empty()) {
            cout << "A lista de datas esta vazia." << endl;
        } else {
            sort(lista.begin(), lista.end(), [](const Data& d1, const Data& d2) {
                return Data::compara(d1, d2) < 0;
            });
            cout << "Maior data: " << lista.back().toString() << endl;
        }
    }
    
};

class ListaSalarios : public Lista  {
	vector<float> lista;
	
	public:		
	void entradaDeDados() override{
		
		int n;
        cout << "Quantos salarios deseja adicionar? ";
        cin >> n;
        for (int i = 0; i < n; i++) {
            float salario;
            cout << "Digite o salario: ";
            cin >> salario;
            lista.push_back(salario);
        }
    }
	
			
	void mostraMediana() {
        if (lista.empty()) {
            cout << "A lista de salarios esta vazia." << endl;
        } else {
            sort(lista.begin(), lista.end());
            int meio = lista.size() / 2;
            if (lista.size() % 2 == 0) {
                float mediana = (lista[meio - 1] + lista[meio]) / 2.0;
                cout << "Mediana: " << mediana << endl;
            } else {
                cout << "Mediana: " << lista[meio] << endl;
            }
        }
    }
	
	void mostraMenor() {
        if (lista.empty()) {
            cout << "A lista de salários esta vazia." << endl;
        } else {
            sort(lista.begin(), lista.end());
            cout << "Menor salario: " << lista.front() << endl;
        }
    }
	void mostraMaior() {
        if (lista.empty()) {
            cout << "A lista de salarios esta vazia." << endl;
        } else {
            sort(lista.begin(), lista.end());
            cout << "Maior salario: " << lista.back() << endl;
        }
    }
     void listarEmOrdem(){
        sort(lista.begin(), lista.end());
        for (float salario : lista) {
            cout << salario << endl;
        }
    }
};


class ListaIdades : public Lista  {
	vector<int> lista;
	
	public:
		void entradaDeDados() override {
        int n;
        cout << "Quantas idades deseja adicionar? ";
        cin >> n;
        for (int i = 0; i < n; i++) {
            int idade;
            cout << "Digite a idade: ";
            cin >> idade;
            lista.push_back(idade);
        }
    }
	
	
void mostraMediana() {
        if (lista.empty()) {
            cout << "A lista de idades esta vazia." << endl;
        } else {
            sort(lista.begin(), lista.end());
            int meio = lista.size() / 2;
            if (lista.size() % 2 == 0) {
                int mediana = (lista[meio - 1] + lista[meio]) / 2;
                cout << "Mediana: " << mediana << endl;
            } else {
                cout << "Mediana: " << lista[meio] << endl;
            }
        }
    }
	
	void mostraMenor() {
        if (lista.empty()) {
            cout << "A lista de idades esta vazia." << endl;
        } else {
            sort(lista.begin(), lista.end());
            cout << "Menor idade: " << lista.front() << endl;
        }
    }
	void mostraMaior() {
        if (lista.empty()) {
            cout << "A lista de idades esta vazia." << endl;
        } else {
            sort(lista.begin(), lista.end());
            cout << "Maior idade: " << lista.back() << endl;
        }
    }
     void listarEmOrdem(){
        sort(lista.begin(), lista.end());
        for (int idade : lista) {
            cout << idade << endl;
        }
    }

};

int main() {
    vector<Lista*> listaDeListas;
   //teste
   /* Data dataum(12, 9, 2013);
    Data datadois(15, 8, 2023);
    cout << Data::compara(dataum, datadois) << endl;*/

    ListaNomes listaNomes;
    listaNomes.entradaDeDados();
    listaDeListas.push_back(&listaNomes);	

    /*ListaDatas listaDatas;
	listaDatas.entradaDeDados();
	listaDeListas.push_back(&listaDatas);*/
	
	ListaSalarios listaSalarios;
	listaSalarios.entradaDeDados();
	listaDeListas.push_back(&listaSalarios);
	
	ListaIdades listaIdades;
	listaIdades.entradaDeDados();
	listaDeListas.push_back(&listaIdades);
	
	for (Lista* l : listaDeListas) {
		l->mostraMediana();
		l->mostraMenor();
		l->mostraMaior();
        cout << "Listagem em ordem:" << endl;
        l->listarEmOrdem();
	}

    return 0;
}