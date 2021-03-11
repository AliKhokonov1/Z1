#include"CComplexPoint.h"
#include"CComplexVector.h"
#include "CComplexVector0.h"
#include "CComplexVector1.h"
#include "stdio.h"
#include <fstream>
#include <iostream>
#include <string>
#include <sstream>
#include <vector>
using namespace std;
//int Autotest();
int main () {
//Autotest();
string str;
ifstream fin("zhozhozho.txt");
if (fin.fail()) {
        cout<<"File did not open!"<<endl;
        return 1;
}
int n=0;
while(getline(fin,str)){
	n++;
}
CComplexVector  **arr = new CComplexVector* [n];
int x = 0;
string filename;
int m = 0;
int i = 0;
double re;
double im;
CComplexVector* tmp;
fin.seekg(0,ios_base::beg);
while(getline(fin,str)){
        istringstream ss(str);//Работаем со строкой как с входным файлом
        ss >> x;
        ss >> filename;
        ss >> m;
        if(x == 0){
		tmp = new CComplexVector0(m);
	}
	else{
		tmp = new CComplexVector1(m);
	}
        tmp->setFilename(filename.c_str());//Устанавливаем char *  в filename
        for(int j = 0; j < m; j++){
		 ss >> re >> im;
		 tmp->set(j,CComplexPoint(re,im));//Инициализируем массив e входными данными	
	}
	arr[i++] = tmp;
}
for(int i = 0; i < n; i++){
	arr[i]->output();
}
for(int i = 0; i < n;i++){
	delete arr[i];
}
delete arr;
return 0;
}