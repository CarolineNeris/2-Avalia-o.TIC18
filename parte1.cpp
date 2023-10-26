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

    string paraString() const {
        return to_string(dia) + "/" + to_string(mes) + "/" + to_string(ano);
    }
};

class Lista {
public:
    virtual ~Lista() {}  // Destrutor virtual

    virtual void inserirDados() = 0;
    virtual void calcularMediana() = 0;
    virtual void calcularMenor() = 0;
    virtual void calcularMaior() = 0;
    virtual void listarEmOrdem() = 0;  
    virtual void mostrarTopN(int N) = 0; 
};

class ListaNomes : public Lista {
    vector<string> nomes;
public:
    void inserirDados() override {
        nomes.push_back("Pedrinho");
        nomes.push_back("Guto");
        nomes.push_back("Bia");
        nomes.push_back("Fernanda");
        nomes.push_back("Betina");
    }

    void calcularMediana() override {
        sort(nomes.begin(), nomes.end());
        cout << "Mediana da lista de nomes: " << nomes[nomes.size() / 2 - 1] << endl;
    }

    void calcularMenor() override {
        cout << "Primeiro nome em ordem alfabética: " << *min_element(nomes.begin(), nomes.end()) << endl;
    }

    void calcularMaior() override {
        cout << "Último nome em ordem alfabética: " << *max_element(nomes.begin(), nomes.end()) << endl;
    }

    void listarEmOrdem() override {
        sort(nomes.begin(), nomes.end());
        for (const string &nome : nomes) {
            cout << nome << endl;
        }
    }

    void mostrarTopN(int N) override {
        for (int i = 0; i < min(N, (int)nomes.size()); i++) {
            cout << nomes[i] << endl;
        }
    }
};

class ListaDatas : public Lista {
    vector<Data> datas;
public:
    void inserirDados() override {
        datas.push_back(Data(22, 7, 2010));
        datas.push_back(Data(15, 11, 2013));
        datas.push_back(Data(18, 3, 2015));
        datas.push_back(Data(7, 12, 2020));
        datas.push_back(Data(10, 1, 2018));
    }

    void calcularMediana() override {
        sort(datas.begin(), datas.end());
        cout << "Mediana da lista de datas: " << datas[datas.size() / 2 - 1].paraString() << endl;
    }

    void calcularMenor() override {
        cout << "Primeira data cronologicamente: " << min_element(datas.begin(), datas.end())->paraString() << endl;
    }

    void calcularMaior() override {
        cout << "Última data cronologicamente: " << max_element(datas.begin(), datas.end())->paraString() << endl;
    }

    void listarEmOrdem() override {
        sort(datas.begin(), datas.end());
        for (const Data &data : datas) {
            cout << data.paraString() << endl;
        }
    }

    void mostrarTopN(int N) override {
        for (int i = 0; i < min(N, (int)datas.size()); i++) {
            cout << datas[i].paraString() << endl;
        }
    }
};

class ListaSalarios : public Lista {
    vector<float> salarios;
public:
    void inserirDados() override {
        salarios.push_back(2500.50);
        salarios.push_back(3000.75);
        salarios.push_back(2700.30);
        salarios.push_back(2800.80);
        salarios.push_back(100000.00);
    }

    void calcularMediana() override {
        sort(salarios.begin(), salarios.end());
        if (salarios.size() % 2 == 0)
            cout << "Mediana da lista de salários: " << (salarios[salarios.size() / 2 - 1] + salarios[salarios.size() / 2]) / 2 << endl;
        else
            cout << "Mediana da lista de salários: " << salarios[salarios.size() / 2] << endl;
    }

    void calcularMenor() override {
        cout << "Menor salário: " << *min_element(salarios.begin(), salarios.end()) << endl;
    }

    void calcularMaior() override {
        cout << "Maior salário: " << *max_element(salarios.begin(), salarios.end()) << endl;
    }

    void listarEmOrdem() override {
        sort(salarios.begin(), salarios.end());
        for (float salario : salarios) {
            cout << salario << endl;
        }
    }

    void mostrarTopN(int N) override {
        for (int i = 0; i < min(N, (int)salarios.size()); i++) {
            cout << salarios[i] << endl;
        }
    }
};

class ListaIdades : public Lista {
    vector<int> idades;
public:
    void inserirDados() override {
        idades.push_back(25);
        idades.push_back(30);
        idades.push_back(29);
        idades.push_back(28);
        idades.push_back(27);
    }

    void calcularMediana() override {
        sort(idades.begin(), idades.end());
        if (idades.size() % 2 == 0)
            cout << "Mediana da lista de idades: " << (idades[idades.size() / 2 - 1] + idades[idades.size() / 2]) / 2 << endl;
        else
            cout << "Mediana da lista de idades: " << idades[idades.size() / 2] << endl;
    }

    void calcularMenor() override {
        cout << "Menor idade: " << *min_element(idades.begin(), idades.end()) << endl;
    }

    void calcularMaior() override {
        cout << "Maior idade: " << *max_element(idades.begin(), idades.end()) << endl;
    }

    void listarEmOrdem() override {
        sort(idades.begin(), idades.end());
        for (int idade : idades) {
            cout << idade << endl;
        }
    }

    void mostrarTopN(int N) override {
        for (int i = 0; i < min(N, (int)idades.size()); i++) {
            cout << idades[i] << endl;
        }
    }
};

int main() {
    vector<Lista*> listaDeListas;
    
    ListaNomes* listaNomes = new ListaNomes();
    listaNomes->inserirDados();
    listaDeListas.push_back(listaNomes);
    
    ListaDatas* listaDatas = new ListaDatas();
    listaDatas->inserirDados();
    listaDeListas.push_back(listaDatas);
    
    ListaSalarios* listaSalarios = new ListaSalarios();
    listaSalarios->inserirDados();
    listaDeListas.push_back(listaSalarios);
    
    ListaIdades* listaIdades = new ListaIdades();
    listaIdades->inserirDados();
    listaDeListas.push_back(listaIdades);
    
    for (Lista* l : listaDeListas) {
        l->calcularMediana();
        l->calcularMenor();
        l->calcularMaior();
        l->listarEmOrdem();
        l->mostrarTopN(5);  // Exemplo para mostrar os primeiros 5 elementos.
    }

    // Limpando memória
    for (Lista* l : listaDeListas) {
        delete l;
    }
}
