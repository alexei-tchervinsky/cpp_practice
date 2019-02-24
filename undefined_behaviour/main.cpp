// undefined behaviour
// Блог на русском языке о точках следования (sequence point) и неопределенном поведениие (undefined behaviour)
// http://alenacpp.blogspot.com/2005/11/sequence-points.html/

#include <iostream>

class IntExample
{
  public:
    // default constructor
    IntExample(int i) 
    {
      i_ = i;
    }

    // copy constructor
    IntExample(IntExample & copy)
    {
      i_ = copy.i_;
    }
  int getValue () const 
  {
    return i_;
  }
   IntExample & operator = (const IntExample & ie)
 { 
    i_ = ie.i_;
    return *this;
  }
  IntExample & operator++()
  {
    ++i_;
    return *this;
  }
  IntExample & operator++(int)
  {
    i_++;
    return *this;
  }
  friend std::ostream& operator <<(std::ostream &out, const IntExample &ie)
  {
    out << ie.i_;
    return out;
  }

 private:
    int i_;
};

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
/*9.*/ f(i, i++); //undefined порядок вычисления аргументов функции не определен (unspecified behavior в данном случае приводит к undefined)
/*10.*/ i = 10;
        IntExample ie(i); // class! 
        ie = ++ie;  // well defined preincrement поскольку перегруженные операторы декремента и инкремента эквивалентны операторам  +=  и  -= 
        std::cout << __LINE__ << " ie: " << ie.getValue() << std::endl; // Вместо getValue() нужно перегрузить оператор  <<   
        ie = ie++; // well defined
        std::cout << __LINE__ << " ie: " << ie << std::endl; // перегружен оператор <<    
  return 0;
}
