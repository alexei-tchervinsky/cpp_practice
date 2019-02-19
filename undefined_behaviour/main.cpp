// undefined behaviour
//
#include <iostream>

int main(void)
{
  int v[]={1,2,3};

  int i = 0;

/*1.*/ i = v[i++]; //undefined
/*2.*/ i = i++; //undefined
/*3.*/ i = 7, i++, i++; //well defined
/*4.*/ i = i + 1; //well defined
/*5.*/ i = ++i; //preincrement undefined too
/*6.*/ int j = i << -2; //undefined сдвиг на отрицательное число разрядов
/*7.*/ int k = i >> -2; //undefined сдвиг на отрицательное число разрядов
  return 0;
}
