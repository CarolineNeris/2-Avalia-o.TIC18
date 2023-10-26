#include <iostream>
#include <string>
#include <vector>

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

    Data(int _dia, int _mes, int _ano) : dia(_dia), mes(_mes), ano(_ano) {}

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
        cin.ignore(); // Limpa o caractere de nova linha no buffer.
        for (int i = 0; i < n; i++) {
            cout << "Digite o nome:" << endl;
            getline(cin, nm);
            lista.push_back(nm);
        }
    }

    void mostraMediana() {
        cout << "Aqui vai mostrar a mediana da lista de strings" << endl;
    }

    void mostraMenor() {
        cout << "Aqui vai mostrar o primeiro nome alfabeticamente" << endl;
    }

    void mostraMaior() {
        cout << "Aqui vai mostrar o ultimo nome alfabeticamente" << endl;
    }
};

// Implementar as classes abaixo.

class ListaDatas : public Lista  {
	vector<Data> lista;
	
	public:
	void entradaDeDados() override {
		int n;
        cout << "Quantas datas deseja adicionar? ";
        cin >> n;
        for (int i = 0; i < n; i++) {
            int dia, mes, ano;
            cout << "Digite o dia, mês e ano (formato DD MM AAAA): ";
            cin >> dia >> mes >> ano;
            Data data(dia, mes, ano);
            lista.push_back(data);
        }
    }
		
	};
	
	void mostraMediana() {
		cout << "Aqui vai mostrar a mediana da lista de datas" << endl;
	}
	
	void mostraMenor() {
		cout << "Aqui vai mostrar a primeira data cronologicamente" << endl;
	}
	void mostraMaior() {
		cout << "aqui vai mostrar a ultima data cronologicamente" << endl;
	}
	

class ListaSalarios : public Lista  {
	vector<float> lista;
	
	public:		
	void entradaDeDados() override{
		
		int n;
        cout << "Quantos salários deseja adicionar? ";
        cin >> n;
        for (int i = 0; i < n; i++) {
            float salario;
            cout << "Digite o salário: ";
            cin >> salario;
            lista.push_back(salario);
        }
    }
	
			
	void mostraMediana() {
		cout << "Aqui vai mostrar a mediana da lista de salarios" << endl;
	}
	
	void mostraMenor() {
		cout << "Aqui vai mostrar o menor dos salarios" << endl;
	}
	void mostraMaior() {
		cout << "aqui vai mostrar o maior dos salarios" << endl;
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
		cout << "Aqui vai mostrar a mediana da lista de idades" << endl;
	}
	
	void mostraMenor() {
		cout << "Aqui vai mostrar a menor das idades" << endl;
	}
	void mostraMaior() {
		cout << "aqui vai mostrar a maior das idades" << endl;
	}
};

int main() {
    vector<Lista*> listaDeListas;
    Data dataum(12, 9, 2013);
    Data datadois(15, 8, 2023);
    cout << Data::compara(dataum, datadois) << endl;

    ListaNomes listaNomes;
    listaNomes.entradaDeDados();
    listaDeListas.push_back(&listaNomes);

    // Adicionar as outras classes derivadas e seus métodos.


    /*ListaDatas listaDatas;
	listaDatas.entradaDeDados();
	listaDeListas.push_back(&listaDatas);
	
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
	}*/

    return 0;
}
