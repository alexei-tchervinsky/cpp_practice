// undefined behaviour
// Блог на русском языке о точках следования (sequence point) и неопределенном поведениие (undefined behaviour)
// http://alenacpp.blogspot.com/2005/11/sequence-points.html/

#include <iostream>

class IntExample
{
  public:
    // конструктор по умолчанию (default constructor)
    IntExample(int i) 
    {
      i_ = i;
    }
    // конструктор копировная (copy constructor) нужен для оператора присваивания 
    IntExample(IntExample & copy)
    {
      i_ = copy.i_;
    }
  // получение значения 
  int getValue () const 
  {
    return i_;
  }
  // перегруженный оператор присваивания
   IntExample & operator = (const IntExample & ie)
 { 
    i_ = ie.i_;
    return *this;
  }
  // перегруженный оператор preincrement
  IntExample & operator++()
  {
    ++i_;
    return *this;
  }
  // перегруженный оператор postincrement (в скобках неиспользуемый int - определяет пост-инкремент)
  IntExample & operator++(int)
  {
    i_++;
    return *this;
  }
  // перегруженный оператор вывода -  friend для доступа к private полю
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
/*2'.*/ i = i--; //undefined
/*3.*/ i = 7, i++, i++; //well defined
/*4.*/ i = i + 1; //well defined НАДО ДЕЛАТЬ ТАК во избежании путаницы с pre- и post инкрементом
/*5.*/ i = ++i; //well defined
// https://stackoverflow.com/questions/14005508/so-why-is-i-i-1-well-defined-in-c11
// https://www.reddit.com/r/cpp_questions/comments/3au94b/why_is_i_i_1_undefined_but_i_i_1_well_defined
/*5'*/ int x = ++i + i++; // undefined
/*6.*/ int j = i << -2; //undefined сдвиг на отрицательное число разрядов
/*7.*/ int k = i >> -2; //undefined сдвиг на отрицательное число разрядов
/*8.*/ uint32_t u = 0; u <<= 32; //undefined сдвиг больше, чем разрядность
/*9.*/ f(i, i++); //undefined порядок вычисления аргументов функции не определен (unspecified behavior в данном случае приводит к undefined)
/*10.*/ i = 10;
        IntExample ie(i); // class! 
        ie = ie++;  // well defined preincrement поскольку перегруженные операторы декремента и инкремента эквивалентны операторам  +=  и  -= 
        std::cout << __LINE__ << " ie: " << ie.getValue() << std::endl; // Вместо getValue() нужно перегрузить оператор  <<   
        ie = ++ie; // well defined
        std::cout << __LINE__ << " ie: " << ie << std::endl; // перегружен оператор <<    

/*
 Из блога Елены Сагалаевой и лекции Алексея Валерьевича:
 Где находятся точки следования
 
 
 В конце каждого полного выражения(Глава Стандарта 1.9/16). Обычно они помечены точкой с запятой ;
 
 В точке вызова функции (1.9/17). Но после вычисления всех аргументов. Это и для inline функций в том числе.
 
 При возвращении из функции. (1.9/17) Есть точка следования сразу после возврата функции, перед тем как любой другой код из вызвавшей функции начал выполняться.
 
 (1.9/18) После первого выражения (здесь оно называется 'a') в следующих конструкциях:
 
 a || b
 
 a && b
 
 a , b
 
 a ? b : c
 
 Вычисление здесь идет слева направо. То есть левое выражение (по имени 'a') вычисляется и все побочные эффекты от такого вычисления завершаются. Потом, если все значение всего выражения известно, правое выражение не вычисляется, иначе вычисляется.
 Правило слево-направо не работает для переопределенных операторов. В этом случае переопределенный оператор ведет себя как обычная функция. Еще такой момент - ?: не может быть переопределен по стандарту.
 
 (Упомянутая запятая это оператор запятая. Она не имеет никакого отношения к запятой, разделяющей аргументы функции.)
 
 
 Если рассмотреть пример "x = x++;", то здесь имеет место попытка изменить объект дважды.
 Если программа пытается модифицировать одну переменную дважды не пересекая точку следования, то это ведет к undefined behavior. Так говорит Стандарт. И тут же в Стандарте приводятся примеры.

 */

/*
   Забегаяя вперед - из того же блога Елены Сагалаевой:
   
   Очень подробное и хорошее объяснение про эти операторы есть у Мейерса в More Effective C++.
   Item 7: Never overload &&, ||, or ,.
   
   Из книги Скотта Мейерса в переложении:
   Перегрузка операторов является вызовом функции, а для функций порядок вычисления аргументов неспецифицирован (unspecified behaviour) - поэтому при перегрузке операторов &&, || и , - невозможно определить порядок вычислений - нарушается последовательность точек следования.
*/

// Самый страшное неопределенное поведение - разъименование нулевого или неправильного указателя - как правило, приводит к аварийному завершению программы, но может быть любым образом 

#if 0 // так можно сделать, чтобы код не обрабатывался компилятором
/*11.*/
  char *p = 0; 
std::cout << __FILE__ << ":" << __LINE__ << " ATTENTION: разъименование нулевого указателя!!! Крах!" << std::endl;

  char a = *p; //undefined NULL pointer dereference, более свойственно для Си, хотя и С++ применяет указатели
#endif    
  return 0;
}
