#pragma once
#include "Service.h"
#include <iostream>
using namespace std;


class TestService {
private:
	Service s;
	void testeaza();
	void testeazaOperatii();
	
public:
	TestService();
	void runTest();
	~TestService();
};