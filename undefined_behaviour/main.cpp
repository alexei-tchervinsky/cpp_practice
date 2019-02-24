// undefined behaviour
//
#include <iostream>

void f(int i1, int i2)
{
  int j = 0;
  j = i1 + i2;
}

int main(void)
{
  int v[]={1,2,3};

  int i = 0;

/*1.*/ i = v[i++]; //undefined
/*2.*/ i = i++; //undefined
/*3.*/ i = 7, i++, i++; //well defined
/*4.*/ i = i + 1; //well defined
/*5.*/ i = ++i; //preincrement undefined too
/*5'*/ int x = ++i + i++; // undefined
/*6.*/ int j = i << -2; //undefined сдвиг на отрицательное число разрядов
/*7.*/ int k = i >> -2; //undefined сдвиг на отрицательное число разрядов
/*8.*/ uint32_t u = 0; u <<= 32; //undefined сдвиг больше, чем разрядность
/*9.*/ f(i, i++); //undefined порядок вычисления аргументов функции не определен (unspecified behavior в данном случае приводит к undefined
    
  return 0;
}
