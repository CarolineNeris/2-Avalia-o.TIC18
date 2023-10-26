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
    virtual ~Lista() {}  // Destrutor virtual

    virtual void entradaDeDados() = 0;
    virtual void mostraMediana() = 0;
    virtual void mostraMenor() = 0;
    virtual void mostraMaior() = 0;
    virtual void listarEmOrdem() = 0;  
    virtual void mostrarPrimeiros(int N) = 0; 
};

class ListaNomes : public Lista {
    vector<string> lista;
public:
    void entradaDeDados() override {
        lista.push_back("Carlos");
        lista.push_back("Ana");
        lista.push_back("Beatriz");
        lista.push_back("Eduardo");
        lista.push_back("Diana");
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

    void listarEmOrdem() override {
        sort(lista.begin(), lista.end());
        for (const string &nome : lista) {
            cout << nome << endl;
        }
    }

    void mostrarPrimeiros(int N) override {
        for (int i = 0; i < min(N, (int)lista.size()); i++) {
            cout << lista[i] << endl;
        }
    }
};

class ListaDatas : public Lista {
    vector<Data> lista;
public:
    void entradaDeDados() override {
        lista.push_back(Data(12, 5, 2020));
        lista.push_back(Data(3, 11, 2019));
        lista.push_back(Data(15, 2, 2021));
        lista.push_back(Data(7, 8, 2020));
        lista.push_back(Data(20, 12, 2018));
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

    void listarEmOrdem() override {
        sort(lista.begin(), lista.end());
        for (const Data &data : lista) {
            cout << data.toString() << endl;
        }
    }

    void mostrarPrimeiros(int N) override {
        for (int i = 0; i < min(N, (int)lista.size()); i++) {
            cout << lista[i].toString() << endl;
        }
    }
};

class ListaSalarios : public Lista {
    vector<float> lista;
public:
    void entradaDeDados() override {
        lista.push_back(2500.50);
        lista.push_back(3000.75);
        lista.push_back(2700.30);
        lista.push_back(2800.80);
        lista.push_back(2650.00);
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

    void listarEmOrdem() override {
        sort(lista.begin(), lista.end());
        for (float salario : lista) {
            cout << salario << endl;
        }
    }

    void mostrarPrimeiros(int N) override {
        for (int i = 0; i < min(N, (int)lista.size()); i++) {
            cout << lista[i] << endl;
        }
    }
};

class ListaIdades : public Lista {
    vector<int> lista;
public:
    void entradaDeDados() override {
        lista.push_back(25);
        lista.push_back(30);
        lista.push_back(29);
        lista.push_back(28);
        lista.push_back(27);
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

    void listarEmOrdem() override {
        sort(lista.begin(), lista.end());
        for (int idade : lista) {
            cout << idade << endl;
        }
    }

    void mostrarPrimeiros(int N) override {
        for (int i = 0; i < min(N, (int)lista.size()); i++) {
            cout << lista[i] << endl;
        }
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
        l->listarEmOrdem();
        l->mostrarPrimeiros(5);  // Exemplo para mostrar os primeiros 5 elementos.
    }

    // Limpando memória
    for (Lista* l : listaDeListas) {
        delete l;
    }
}
