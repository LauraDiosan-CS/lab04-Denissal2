#include "Repo.h"
#include <string>
#include <algorithm> 
#include "Service.h"
#include <iostream>
using namespace std;

//
Service::Service()
{
	this->repo = Repo();
}
Service::Service( Repo& r)
{
	this->repo = r;
}
Service::Service(const Service& s)
{
	//cout << "constructor de copiere Service" << endl;
	this->repo = s.repo;
}
void Service::setRepo(const Repo& r)
{
	this->repo = r;
}

void Service::addExamen(Examen& e)
{
	repo.add(e);
}

Examen* Service::getAllserv() {
	return this->repo.getAll();
}

vector<Examen> Service::ExameneBune(int  nota_min) {
	
		vector<Examen> Examinare ;
		for (int i = 0; i < repo.getSize(); i++) {
			Examen crtExamen = repo.getItemFromPos(i);
			if (crtExamen.getNota() > nota_min) {
				Examinare.push_back(crtExamen);
			}
		}
		return Examinare;
	}

 vector<Examen> Service::AdaugaPunct(char* name,int plus) {

	vector<Examen> ExamenFilter;
	for (int i = 0; i < repo.getSize(); i++) {
		Examen& Student = repo.getItemFromPos(i);
		// Daca nu pui &  - se creeaza un nou student si nu se modifica valoarea notei
		if (strcmp(Student.getNume(), name) == 0) {
			plus = Student.getNota() +1;
			Student.setNota(plus);
			ExamenFilter.push_back(Student);
		}
		
	}
	
	return ExamenFilter;


}

 bool myNameCompare(Examen x, Examen y) {
	 return ((strcmp(x.getNume(), y.getNume()) < 0));
 }


vector<Examen> Service::sortByName() {
	 vector<Examen> all;
	 // Nu am construit un constructor pt a putea pune  " = repo.getAll();//
	 for (int i = 0; i < repo.getSize(); i++) {

		 Examen Student = repo.getItemFromPos(i);
		 all.push_back(Student);
		 std::sort(all.begin(), all.end(),myNameCompare);
	 }
	 // la mynamecompare nu se mai pun parametrii ii ia la rand cand parcurge vectorul(Sper ca am inteles corect!)

	 return all;




 }

 bool myGradeCompare(Examen x, Examen y) { 
	 return (x.getNota() > y.getNota());
 }

 vector<Examen> Service::sortByNota(int val) {

	 vector<Examen> all;
	 vector<Examen> allp;
	 // Nu am construit un constructor pt a putea pune  " = repo.getAll();//
	 if (val == 0) {
		 for (int i = 0; i < repo.getSize(); i++) {

			 Examen Student = repo.getItemFromPos(i);
			 all.push_back(Student);
			 std::sort(all.begin(), all.end(), myGradeCompare);
		 }

		 return all;
	 }

	 else if (val == 1) {

		 for (int i = 0; i < repo.getSize(); i++) {
			 Examen Studentx = repo.getItemFromPos(i);
			 if (Studentx.getNota() > 5) {
					 allp.push_back(Studentx);
				 std::sort(allp.begin(), allp.end(), myGradeCompare);
				 }


		 }

		 

	 }
	 return allp;
 }

 vector <Examen> Service::filterByNameAndGrade(int val, const char* n, int a) {

	 vector<Examen> rez;
	 if (val == 0) {
		 for (int i = 0;i < repo.getSize();i++)
		 {
			 Examen crt = repo.getItemFromPos(i);
			 if (strstr(crt.getNume(), n) && crt.getNota() >= a)
				 rez.push_back(crt);
		 }
		 //return rez;
	 }
	 else if (val == 1) {
		 for (int i = 0;i < repo.getSize();i++)
		 {
			 Examen crt = repo.getItemFromPos(i);
			 if (strstr(crt.getNume(), n) && crt.getNota() > 5)
				 rez.push_back(crt);
		 }
		// return rez;
	 }
	 else if (val == 2) {
		 for (int i = 0;i < repo.getSize();i++)
		 {
			 Examen crt = repo.getItemFromPos(i);
			 if (strstr(crt.getNume(), n) && crt.getNota() > 5 && crt.getData() > 20 )
				 rez.push_back(crt);
		 }
		// return rez;



	 }
	 else if (val == 3) {
		 for (int i = 0;i < repo.getSize();i++)
		 {
			 Examen crt = repo.getItemFromPos(i);
			 if (strcmp(crt.getNume(),n) == 0 && crt.getNota() <= a && crt.getData() > 3)
				 rez.push_back(crt);
		 }
		



	 }


	 return rez;
	 // Se executa in functie de if ales


	 }

	 
 

void Service::delExamen(Examen& ex)
{
	repo.del(ex);
}

void Service::afisare() {
	repo.afisareLista();
}
void Service::afisareNotaBuna(int nota_min) {
	Examen* Notare = new Examen[this->repo.getSize()];
	Notare = this->repo.getAll();
	for (int i = 0; i <= this->repo.getSize(); i++)
	{
		if (Notare[i].getNota() > nota_min)
		{
			cout << Notare[i];
		}

	}
	
}

void Service::AfiseazaNotaCeaMaiMareMicaStudent(int nr_opt, char* y) {
	Examen* Notare = new Examen[this->repo.getSize()];
	Notare = this->repo.getAll();
	if (nr_opt == 0)
	{
		int max = 0;
		for (int i = 0;i < this->repo.getSize();i++)
		{
			if (strcmp(Notare[i].getNume(), y) == 0 && Notare[i].getNota() > max)
			{

				max = Notare[i].getNota();


			}

		}
		cout << "Cea mai mare nota a studentului este :" << max << endl;

	}
	else if (nr_opt == 1)
	{

		int min = 999;
		for (int i = 0;i < this->repo.getSize();i++)
		{
			if (strcmp(Notare[i].getNume(), y) == 0 && Notare[i].getNota() < min)
			{

				min = Notare[i].getNota();


			}

		}
		cout << "Cea mai mica nota a studentului este :" << min << endl;

	}
}


void Service::SumaNotelorStudentului(char* p, int& suma) {
	Examen* Notare ;
	Notare = this->repo.getAll();
	int sum = 0;
	for (int i = 0;i < this->repo.getSize();i++) {
		if (strcmp(Notare[i].getNume(), p) == 0)
		{
			sum = sum + Notare[i].getNota();


		}

	}

	suma = sum;

}

void Service::OrdonareStudentiData(int nr, char* l) {
	if (nr == 0) {
		Examen* rez = new Examen[this->repo.getSize()];
		// e nevoie de alocare dinamica ,se foloseste dupa !
		int n = 0;
		for (int i = 0; i < this->repo.getSize(); i++)
		{
			if (strcmp(repo.getItemFromPos(i).getNume(), l) == 0)
			{
				//cout << repo.getItemFromPos(i)<< endl;
				//Eventual se pune acest cout pentru verificare
				rez[n] = repo.getItemFromPos(i);
				n++;
			}
		}
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
				//Daca pun j = i ->sortare descrescatoare
			{
				if (rez[i].getData() < rez[j].getData())
					// conditia pentru sortare
				{
					Examen x;
					// x - min
					x = rez[i];
					// elementul 1
					rez[i] = rez[j];
					// rez[i] primeste rez[j]
					rez[j] = x;
					// rez[j] ->devine elementul 2
				}
			}
		}
		for (int i = 0; i < n; i++)
		{
			cout <<  rez[i] << " ";
		}
	}

	else if (nr == 1) {
		Examen* rezx = new Examen[this->repo.getSize()];
		int nx = 0;
		for (int i = 0; i < this->repo.getSize(); i++)
		{
			if (strcmp(repo.getItemFromPos(i).getNume(), l) == 0)
			{
				//cout << repo.getItemFromPos(i)<< endl;
				//Eventual se pune acest cout pentru verificare
				rezx[nx] = repo.getItemFromPos(i);
				nx++;
			}
		}
		for (int i = 0; i < nx; i++)
		{
			for (int j = 0; j < nx; j++)
				//Daca pun j = i ->sortare descrescatoare
			{
				if (rezx[i].getData() > rezx[j].getData())
					// conditia pentru sortare
				{
					Examen x;
					// x - min
					x = rezx[i];
					// elementul 1
					rezx[i] = rezx[j];
					// rez[i] primeste rez[j]
					rezx[j] = x;
					// rez[j] ->devine elementul 2
				}
			}
		}
		for (int i = 0; i < nx; i++)
		{
			cout << rezx[i] << " ";



		}

	}

}

void Service::adaugare_punct(char* elev, int nota_punct_bonus) {
	Examen* Notare;
	Notare = this->repo.getAll();
	
	for (int i = 0; i < this->repo.getSize(); i++)
	{
		if (strcmp(Notare[i].getNume(), elev) == 0 )
		{	
			nota_punct_bonus = Notare[i].getNota() + 1;
			Notare[i].setNota(nota_punct_bonus);
			//cout << Notare[i];
		}
	}
}


Service& Service::operator=(const Service &s)
{
	if (this != &s) this->repo = s.repo;
	return *this;
}

Examen* Service::getAlls()
{
	return this->repo.getAll();
}

Examen Service::updateExamen(Examen e2, char* n, int a,int b)
{
	repo.update(e2, n, a,b);
	return e2;
}
int Service::findOne(Examen e3)
{
	return repo.find(e3);
}




int Service::getNumarServ() {
	return this->repo.getSize();
}

Examen& Service::getExamenServ(int pz)
{
	return this->repo.getExamen(pz);

}

Repo Service::getRepo()
{
	return this->repo;
}


Service::~Service()
{
}
