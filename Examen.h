#include <ostream>
#ifndef EXAMEN_H
#define EXAMEN_H
class Examen {
private:
	char* nume;
	int data;
	int nota;

public:
	Examen();
	Examen(char*, int, int);
	Examen(const Examen&);
	char* getNume();
	int getData();
	int getNota();
	void setNume(char*);
	void setData(int);
	void setNota(int);
	~Examen();
	Examen& operator=(const Examen&);
	bool operator==(const Examen& e);
	bool compare(Examen& e);
	//friend ostream& operator<<(ostream& os, const Examen& e);


};
#endif