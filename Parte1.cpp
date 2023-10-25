#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class Data {
    int dia, mes, ano;
public:
    Data(int _dia, int _mes, int _ano): dia(_dia), mes(_mes), ano(_ano) {}

    bool operator<(const Data &d) const {
        if (ano != d.ano) return ano < d.ano;
        if (mes != d.mes) return mes < d.mes;
        return dia < d.dia;
    }

    string toString() const {
        return to_string(dia) + "/" + to_string(mes) + "/" + to_string(ano);
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
        // Implementação de entrada de dados para nomes.
    }

    void mostraMediana() override {
        sort(lista.begin(), lista.end());
        cout << "Mediana da lista de strings: " << lista[lista.size() / 2 - 1] << endl;
    }

    void mostraMenor() override {
        cout << "Primeiro nome alfabeticamente: " << *min_element(lista.begin(), lista.end()) << endl;
    }

    void mostraMaior() override {
        cout << "Último nome alfabeticamente: " << *max_element(lista.begin(), lista.end()) << endl;
    }
};

class ListaDatas : public Lista {
    vector<Data> lista;
public:
    void entradaDeDados() override {
        // Implementação de entrada de dados para datas.
    }

    void mostraMediana() override {
        sort(lista.begin(), lista.end());
        cout << "Mediana da lista de datas: " << lista[lista.size() / 2 - 1].toString() << endl;
    }

    void mostraMenor() override {
        cout << "Primeira data cronologicamente: " << min_element(lista.begin(), lista.end())->toString() << endl;
    }

    void mostraMaior() override {
        cout << "Última data cronologicamente: " << max_element(lista.begin(), lista.end())->toString() << endl;
    }
};

class ListaSalarios : public Lista {
    vector<float> lista;
public:
    void entradaDeDados() override {
        // Implementação de entrada de dados para salários.
    }

    void mostraMediana() override {
        sort(lista.begin(), lista.end());
        if (lista.size() % 2 == 0)
            cout << "Mediana da lista de salários: " << (lista[lista.size() / 2 - 1] + lista[lista.size() / 2]) / 2 << endl;
        else
            cout << "Mediana da lista de salários: " << lista[lista.size() / 2] << endl;
    }

    void mostraMenor() override {
        cout << "Menor salário: " << *min_element(lista.begin(), lista.end()) << endl;
    }

    void mostraMaior() override {
        cout << "Maior salário: " << *max_element(lista.begin(), lista.end()) << endl;
    }
};

class ListaIdades : public Lista {
    vector<int> lista;
public:
    void entradaDeDados() override {
        // Implementação de entrada de dados para idades.
    }

    void mostraMediana() override {
        sort(lista.begin(), lista.end());
        if (lista.size() % 2 == 0)
            cout << "Mediana da lista de idades: " << (lista[lista.size() / 2 - 1] + lista[lista.size() / 2]) / 2 << endl;
        else
            cout << "Mediana da lista de idades: " << lista[lista.size() / 2] << endl;
    }

    void mostraMenor() override {
        cout << "Menor idade: " << *min_element(lista.begin(), lista.end()) << endl;
    }

    void mostraMaior() override {
        cout << "Maior idade: " << *max_element(lista.begin(), lista.end()) << endl;
    }
};

int main() {
    vector<Lista*> listaDeListas;
    
    ListaNomes* listaNomes = new ListaNomes();
    listaNomes->entradaDeDados();
    listaDeListas.push_back(listaNomes);
    
    ListaDatas* listaDatas = new ListaDatas();
    listaDatas->entradaDeDados();
    listaDeListas.push_back(listaDatas);
    
    ListaSalarios* listaSalarios = new ListaSalarios();
    listaSalarios->entradaDeDados();
    listaDeListas.push_back(listaSalarios);
    
    ListaIdades* listaIdades = new ListaIdades();
    listaIdades->entradaDeDados();
    listaDeListas.push_back(listaIdades);
    
    for (Lista* l : listaDeListas) {
        l->mostraMediana();
        l->mostraMenor();
        l->mostraMaior();
    }

    // Limpando memória
    for (Lista* l : listaDeListas) {
        delete l;
    }
}