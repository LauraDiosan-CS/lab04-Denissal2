#pragma once
#include "Service.h"
#include <iostream>
using namespace std;


class TestService {
private:
	Service s;
	void testeaza();
public:
	TestService();
	void runTest();
	~TestService();
};