#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class Data {
    int dia, mes, ano;

public:
    static int compara(Data d1, Data d2) {
        if (d1.ano < d2.ano)
            return -1;
        else if (d1.ano > d2.ano)
            return 1;
        else if (d1.mes < d2.mes)
            return -1;
        else if (d1.mes > d2.mes)
            return 1;
        else if (d1.dia < d2.dia)
            return -1;
        else if (d1.dia > d2.dia)
            return 1;
        else
            return 0;
    }

    Data(int _dia, int _mes, int _ano) {
        dia = _dia;
        mes = _mes;
        ano = _ano;
    }

    // Sobrecarga do operador de saída
    friend ostream& operator<<(ostream& os, const Data& data) {
        os << data.dia << "/" << data.mes << "/" << data.ano;
        return os;
    }
};

class Lista {
public:
    virtual void entradaDeDados() = 0;
    virtual void mostraMediana() = 0;
    virtual void mostraMenor() = 0;
    virtual void mostraMaior() = 0;
    virtual void listarEmOrdem() = 0;
    virtual void mostrarNPrimeirosElementos(int N) = 0;
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

    void mostraMediana() override {
        if (lista.empty()) {
            cout << "A lista de nomes está vazia." << endl;
        } else {
            // Ordena a lista de nomes e exibe o nome do meio (mediana)
            sort(lista.begin(), lista.end());
            int meio = lista.size() / 2;
            cout << "A mediana da lista de nomes é: " << lista[meio] << endl;
        }
    }

    void mostraMenor() override {
        if (lista.empty()) {
            cout << "A lista de nomes está vazia." << endl;
        } else {
            // Ordena a lista de nomes e exibe o primeiro nome alfabeticamente
            sort(lista.begin(), lista.end());
            cout << "O primeiro nome na ordem alfabética é: " << lista[0] << endl;
        }
    }

    void mostraMaior() override {
        if (lista.empty()) {
            cout << "A lista de nomes está vazia." << endl;
        } else {
            // Ordena a lista de nomes em ordem reversa e exibe o último nome alfabeticamente
            sort(lista.rbegin(), lista.rend());
            cout << "O último nome na ordem alfabética é: " << lista[0] << endl;
        }
    }

    void listarEmOrdem() override {
        if (lista.empty()) {
            cout << "A lista de nomes está vazia." << endl;
        } else {
            sort(lista.begin(), lista.end());
            cout << "Lista de nomes em ordem alfabética:" << endl;
            for (const string& nome : lista) {
                cout << nome << endl;
            }
        }
    }

    void mostrarNPrimeirosElementos(int N) override {
        if (lista.empty()) {
            cout << "A lista de nomes está vazia." << endl;
        } else {
            cout << "Os primeiros " << N << " nomes da lista são:" << endl;
            for (int i = 0; i < N && i < lista.size(); i++) {
                cout << lista[i] << endl;
            }
        }
    }
};

class ListaDatas : public Lista {
    vector<Data> lista;

public:
    ListaDatas() {} // Construtor padrão

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
            Data data(dia, mes, ano);
            lista.push_back(data);
        }
    }

    void mostraMediana() override {
        if (lista.empty()) {
            cout << "A lista de datas está vazia." << endl;
        } else {
            // Ordena a lista de datas e exibe a data do meio (mediana)
            sort(lista.begin(), lista.end(), Data::compara);
            int meio = lista.size() / 2;
            cout << "A mediana da lista de datas é: " << lista[meio] << endl;
        }
    }

    void mostraMenor() override {
        if (lista.empty()) {
            cout << "A lista de datas está vazia." << endl;
        } else {
            // Ordena a lista de datas e exibe a primeira data cronologicamente
            sort(lista.begin(), lista.end(), Data::compara);
            cout << "A primeira data na ordem cronológica é: " << lista[0] << endl;
        }
    }

    void mostraMaior() override {
        if (lista.empty()) {
            cout << "A lista de datas está vazia." << endl;
        } else {
            // Ordena a lista de datas em ordem reversa e exibe a última data cronologicamente
            sort(lista.rbegin(), lista.rend(), Data::compara);
            cout << "A última data na ordem cronológica é: " << lista[0] << endl;
        }
    }

    void listarEmOrdem() override {
        if (lista.empty()) {
            cout << "A lista de datas está vazia." << endl;
        } else {
            sort(lista.begin(), lista.end(), Data::compara);
            cout << "Lista de datas em ordem cronológica:" << endl;
            for (const Data& data : lista) {
                cout << data << endl;
            }
        }
    }

    void mostrarNPrimeirosElementos(int N) override {
        if (lista.empty()) {
            cout << "A lista de datas está vazia." << endl;
        } else {
            cout << "As primeiras " << N << " datas da lista são:" << endl;
            for (int i = 0; i < N && i < lista.size(); i++) {
                cout << lista[i] << endl;
            }
        }
    }
};

class ListaSalarios : public Lista {
    vector<float> lista;

public:
    void entradaDeDados() override {
        int n;
        float salario;
        cout << "Deseja inserir quantos salários? " << endl;
        cin >> n;
        for (int i = 0; i < n; i++) {
            cout << "Digite o salário: ";
            cin >> salario;
            lista.push_back(salario);
        }
    }

    void mostraMediana() override {
        if (lista.empty()) {
            cout << "A lista de salários está vazia." << endl;
        } else {
            // Ordena a lista de salários e exibe a mediana
            sort(lista.begin(), lista.end());
            int meio = lista.size() / 2;
            if (lista.size() % 2 == 0) {
                float mediana = (lista[meio - 1] + lista[meio]) / 2.0;
                cout << "A mediana da lista de salários é: " << mediana << endl;
            } else {
                cout << "A mediana da lista de salários é: " << lista[meio] << endl;
            }
        }
    }

    void mostraMenor() override {
        if (lista.empty()) {
            cout << "A lista de salários está vazia." << endl;
        } else {
            // Ordena a lista de salários e exibe o menor salário
            sort(lista.begin(), lista.end());
            cout << "O menor salário na lista é: " << lista[0] << endl;
        }
    }

    void mostraMaior() override {
        if (lista.empty()) {
            cout << "A lista de salários está vazia." << endl;
        } else {
            // Ordena a lista de salários em ordem reversa e exibe o maior salário
            sort(lista.rbegin(), lista.rend());
            cout << "O maior salário na lista é: " << lista[0] << endl;
        }
    }

    void listarEmOrdem() override {
        if (lista.empty()) {
            cout << "A lista de salários está vazia." << endl;
        } else {
            sort(lista.begin(), lista.end());
            cout << "Lista de salários em ordem crescente:" << endl;
            for (float salario : lista) {
                cout << salario << endl;
            }
        }
    }

    void mostrarNPrimeirosElementos(int N) override {
        if (lista.empty()) {
            cout << "A lista de salários está vazia." << endl;
        } else {
            cout << "Os primeiros " << N << " salários da lista são:" << endl;
            for (int i = 0; i < N && i < lista.size(); i++) {
                cout << lista[i] << endl;
            }
        }
    }
};

class ListaIdades : public Lista {
    vector<int> lista;

public:
    void entradaDeDados() override {
        int n;
        int idade;
        cout << "Deseja inserir quantas idades? " << endl;
        cin >> n;
        for (int i = 0; i < n; i++) {
            cout << "Digite a idade: ";
            cin >> idade;
            lista.push_back(idade);
        }
    }

    void mostraMediana() override {
        if (lista.empty()) {
            cout << "A lista de idades está vazia." << endl;
        } else {
            // Ordena a lista de idades e exibe a mediana
            sort(lista.begin(), lista.end());
            int meio = lista.size() / 2;
            if (lista.size() % 2 == 0) {
                int mediana = (lista[meio - 1] + lista[meio]) / 2;
                cout << "A mediana da lista de idades é: " << mediana << endl;
            } else {
                cout << "A mediana da lista de idades é: " << lista[meio] << endl;
            }
        }
    }

    void mostraMenor() override {
        if (lista.empty()) {
            cout << "A lista de idades está vazia." << endl;
        } else {
            // Ordena a lista de idades e exibe a menor idade
            sort(lista.begin(), lista.end());
            cout << "A menor idade na lista é: " << lista[0] << endl;
        }
    }

    void mostraMaior() override {
        if (lista.empty()) {
            cout << "A lista de idades está vazia." << endl;
        } else {
            // Ordena a lista de idades em ordem reversa e exibe a maior idade
            sort(lista.rbegin(), lista.rend());
            cout << "A maior idade na lista é: " << lista[0] << endl;
        }
    }

    void listarEmOrdem() override {
        if (lista.empty()) {
            cout << "A lista de idades está vazia." << endl;
        } else {
            sort(lista.begin(), lista.end());
            cout << "Lista de idades em ordem crescente:" << endl;
            for (int idade : lista) {
                cout << idade << endl;
            }
        }
    }

    void mostrarNPrimeirosElementos(int N) override {
        if (lista.empty()) {
            cout << "A lista de idades está vazia." << endl;
        } else {
            cout << "As primeiras " << N << " idades da lista são:" << endl;
            for (int i = 0; i < N && i < lista.size(); i++) {
                cout << lista[i] << endl;
            }
        }
    }
};

int main() {
    vector<Lista*> listaDeListas;

    // Adicione as listas desejadas à listaDeListas
    ListaNomes listaNomes;
    listaNomes.entradaDeDados();
    listaDeListas.push_back(&listaNomes);

    ListaDatas listaDatas;
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
        l->listarEmOrdem();
        l->mostrarNPrimeirosElementos(3); // Exemplo: Mostra os primeiros 3 elementos
    }

    return 0;
}
