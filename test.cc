#include <iostream>
using namespace std;


int main(){
float f[2] = {4.0,1.0};
cout << **(&f);
cout << endl;
printf("%f\n",f[0]);

char c[3] = {'c',0,'C'};

//cout << c << endl;;
printf("%s\n",c);


    return 0;

}
