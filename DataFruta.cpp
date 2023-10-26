#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Data {
	int dia, mes, ano;
	public:
	
	/*
	O m�todo abaixo retornar� -1 se d1 � anterior a d2
	Retornar� 0 se d1 = d2
	Retornar� +1 se d1 � posterior a d2
	*/	
	static int compara(Data d1, Data d2) { 
		if(d1<d2){return -1;}
		else if(!(d1<d2)){return 1;}
		else{return 0;}
	}
	bool operator<(const Data& _data) const {
		if (ano < _data.ano) {
            //cout<<"ano<_data.ano"<<endl;
			return true;
		}
		else if (ano > _data.ano) {
            //cout<<"ano>_data.ano"<<endl;
			return false;
		}

		if (mes < _data.mes) {
            //cout<<"mes<_data.mes"<<endl;
			return true;
		}
		else if (mes > _data.mes) {
            //cout<<"mes>_data.mes"<<endl;
			return false;
		}
		//cout<<"dia<_data.dia"<<endl;
		return dia < _data.dia;
	}
	
	Data (int _dia, int _mes, int _ano) {
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
	static void ordenarDataQuickSort(vector<Data> *list, int esq, int dir){
			int pivo=esq,i,j;
			Data aux;
			
			for(i=esq+1;i<=dir;i++){
				j=i;
				if(compara(list->at(j),list->at(pivo))<0){				
				//if(list->at(j)<list->at(pivo)){
				
						aux=list->at(j);
						while(j>pivo){
							list->at(j)=list->at(j-1);
							j--;
						}
						list->at(j)=aux;
						pivo++;
				}
			}
			if(pivo-1>=esq){
				ordenarDataQuickSort(list,esq,pivo-1);
			}
			if(pivo+1 <=dir){
				ordenarDataQuickSort(list,pivo+1,dir);
			}
		}
};
template <typename T>
class Utils{
	public:
		static vector<int>* stringDate(){

			string date,d,m,a;
    		vector<int>* id = new vector<int>();
			
			///d={};
			//m={};
			//a={};
			cout<<"Digite uma data formato dd/mm/aaaa: ";
			getline(cin>>ws,date);			
			for(int i=0;i<date.length();i++){
				if(date.at(i)!='/'){
					d+=date.at(i);
				}else{date.erase(0,i+1);break;}
			}
			for(int i=0;i<date.length();i++){
				if(date.at(i)!='/'){
					m+=date.at(i);
				}else{date.erase(0,i+1);break;}
			}
			for(int i=0;i<date.length();i++){
					a+=date.at(i);
			}
			id->push_back(stoi(d));
			id->push_back(stoi(m));
			id->push_back(stoi(a));
			return id;
		}
		static void ordenarQuickSort(vector<T> *list, int esq, int dir){
			int pivo=esq,i,j;
			T aux;
			
			for(i=esq+1;i<=dir;i++){
				j=i;
				if(list->at(j)<list->at(pivo)){
						aux=list->at(j);
						while(j>pivo){
							list->at(j)=list->at(j-1);
							j--;
						}
						list->at(j)=aux;
						pivo++;
				}
			}
			if(pivo-1>=esq){
				ordenarQuickSort(list,esq,pivo-1);
			}
			if(pivo+1 <=dir){
				ordenarQuickSort(list,pivo+1,dir);
			}
		}
};

class Lista {
	public:
	virtual void entradaDeDados() =0;
	virtual void mostraMediana() =0;
	virtual void mostraMenor() =0;
	virtual void mostraMaior() =0;
};

class ListaNomes: public Lista {
	vector<string> lista;
	
	public:
	
	/*
	O m�todo abaixo pergunta ao usu�rios quantos
	elementos v�o existir na lista e depois
	solicita a digita��o de cada um deles
	*/	
	void entradaDeDados() override{
		int n;
		string nome;
		cout<<"Nomes: Quantas entradas :";
		cin>>n;
		for(int i=0;i<n;i++){
			cout<<"Digite nome: ";
			getline(cin>>ws,nome);
			lista.push_back(nome);
		}
		Utils<string>::ordenarQuickSort(&lista,0,lista.size()-1);
	}
		
	void mostraMediana() override{
		//cout << "Aqui vai mostrar a mediana da lista de strings" << endl;
		int metade=static_cast<int>((lista.size()/2)+lista.size()%2);
		//cout<<"metade:"<<metade<<endl;
		cout<<"Mediana: "<<lista.at(metade-1)<<endl;
	}
	
	void mostraMenor() override{
		//cout << "Aqui vai mostrar o primeiro nome alfabeticamente" << endl;
		cout<<"Menor: "<<lista.front()<<endl;
	}
	void mostraMaior() override{
		//cout << "aqui vai mostrar o ultimo nome alfabeticamente" << endl;
		cout<<"Maior: "<<lista.back()<<endl;
	}
};

class ListaDatas: public Lista  {
	vector<Data> lista;
	
	public:
		
	/*
	O m�todo abaixo pergunta ao usu�rios quantos
	elementos v�o existir na lista e depois
	solicita a digita��o de cada um deles
	*/	
	void entradaDeDados() override{
		int n;
		int dia,mes,ano;
		
		cout<<"Data: Quantas entradas:";
		cin>>n;
		//getchar();
		for(int i=0;i<n;i++){
			//cout<<"Digite dia mes ano: ";
			//cin>>dia>>mes>>ano;
			vector<int>* id=Utils<vector<int>*>::stringDate();
			dia=id->at(0);
			mes=id->at(1);
			ano=id->at(2);
			Data d1(dia,mes,ano);
			//str_d1=d1.toString();
			//cout<<"str_d1: "<<str_d1<<endl;
			lista.push_back(d1);
			//cout<<lista.at(<<endl;
		}
		Data::ordenarDataQuickSort(&lista,0,lista.size()-1);
	}
	
	void mostraMediana() override{
		//cout << "Aqui vai mostrar a mediana da lista de datas" << endl;
		int metade=static_cast<int>((lista.size()/2)+lista.size()%2);
		//cout<<"metade:"<<metade<<endl;
		cout<<"Mediana: "<<lista.at(metade-1).toString()<<endl;
	}
	
	void mostraMenor() override{
		//cout << "Aqui vai mostrar a primeira data cronologicamente" << endl;
		cout<<"Menor: "<<lista.front().toString()<<endl;
	}
	void mostraMaior() override{
		//cout << "aqui vai mostrar a ultima data cronologicamente" << endl;
		cout<<"Maior: "<<lista.back().toString()<<endl;
	}
};

class ListaSalarios: public Lista  {
	vector<float> lista;
	
	public:
	
	/*
	O m�todo abaixo pergunta ao usu�rios quantos
	elementos v�o existir na lista e depois
	solicita a digita��o de cada um deles
	*/	
	void entradaDeDados() {
		int n;
		float salario;
		cout<<"Salarios: Quantas entradas:";
		cin>>n;
		for(int i=0;i<n;i++){
			cout<<"Digite salario: ";
			cin>>salario;
			lista.push_back(salario);
			//cout<<lista.at(i)<<endl;
		}
		Utils<float>::ordenarQuickSort(&lista,0,lista.size()-1);
	}
			
	void mostraMediana() override{
		//cout << "Aqui vai mostrar a mediana da lista de salarios" << endl;
		int metade=static_cast<int>((lista.size()/2));//+lista.size()%2);
		if(lista.size()%2){
			cout<<"Mediana: "<<(lista.at(metade))<<endl;
		}else{
			cout<<"Mediana: "<<((lista.at(metade-1)+lista.at(metade))/2)<<endl;
		}
	}
	
	void mostraMenor() override{
		//cout << "Aqui vai mostrar o menor dos salarios" << endl;
		cout<<"Menor:"<<lista.front()<<endl;
	}
	void mostraMaior() override{
		//cout << "aqui vai mostrar o maior dos salarios" << endl;
		cout<<"Maior: "<<lista.back()<<endl;
	}
};


class ListaIdades:public Lista  {
	vector<int> lista;
	
	public:
		
		/*
	O m�todo abaixo pergunta ao usu�rios quantos
	elementos v�o existir na lista e depois
	solicita a digita��o de cada um deles
	*/	
	void entradaDeDados() {
		int n;
		int idade;
		cout<<"Idades: Quantas entradas:";
		cin>>n;
		for(int i=0;i<n;i++){
			cout<<"Digite idade: ";
			cin>>idade;
			lista.push_back(idade);
			//cout<<lista.at(i)<<endl;
		}
		Utils<int>::ordenarQuickSort(&lista,0,lista.size()-1);
	}
	
	void mostraMediana() override{
		//cout << "Aqui vai mostrar a mediana da lista de idades" << endl;
		int metade=static_cast<int>((lista.size()/2));//+lista.size()%2);
		if(lista.size()%2){
			cout<<"Mediana: "<<(lista.at(metade))<<endl;
		}else{
			cout<<"Mediana: "<<((lista.at(metade-1)+lista.at(metade))/2)<<endl;
		}
	}
	
	void mostraMenor() override{
		//cout << "Aqui vai mostrar a menor das idades" << endl;
		cout<<"Menor:"<<lista.front()<<endl;
	}
	void mostraMaior() override{
		//cout << "aqui vai mostrar a maior das idades" << endl;
		cout<<"Maior: "<<lista.back()<<endl;
	}
};
 
int main () {
	vector<Lista*> listaDeListas;
	
	//ListaNomes listaNomes;
	//listaNomes.entradaDeDados();
	//listaDeListas.push_back(&listaNomes);
	
	ListaDatas listaDatas;
	listaDatas.entradaDeDados();
	listaDeListas.push_back(&listaDatas);
	
	//ListaSalarios listaSalarios;
	//listaSalarios.entradaDeDados();
	//listaDeListas.push_back(&listaSalarios);
	
	//ListaIdades listaIdades;
	//listaIdades.entradaDeDados();
	//listaDeListas.push_back(&listaIdades);
	
	for (Lista* l : listaDeListas) {
		l->mostraMediana();
		l->mostraMenor();
		l->mostraMaior();
	}
	
}
    

