#include <iostream>

void passByValue(int a)
{
     a++;
}

void passByPointer(int *ptr)
{
     //std::cout << "address stored in ptr:"<< ptr << '\n';
     //*ptr = *ptr + 1;
     //(*ptr)++;
}

void passByReference(int &a)
{
     a++;
}

void passByArray(int *a)
{
     a[0] = 10;
     a[1] = 11;
}

int main(int argc, char *argv[])
{
     int a = 5;
     std::cout << &a << '\n';
     std::cout << a << '\n';

     int* b = &a;

     std::cout << &b << ", " << b << ", " << *b << '\n';

     a = 10;

     std::cout << &b << ", " << b << ", " << *b << '\n';

     int c = 20;
     b = &c;
     std::cout << *b << '\n';

     int arrayA[5];
     std::cout << arrayA << '\n';

     passByValue(a);
     std::cout << a << '\n';
     std::cout << "address stored in b:" << b << '\n';
     passByPointer(b);
     std::cout << *b << '\n';

     passByReference(a);
     std::cout << a << '\n';

     for(int i = 0; i<5; i++)
     {
          arrayA[i] = 0;
     }
     passByArray(arrayA);
     for(int i = 0; i<5; i++)
     {
          std::cout << arrayA[i] << '\n';
     }

     int *y = new int[10];
     double *x = new double[20];

     delete[] x;
     delete[] y;

     int *x2 = new int;
     *x2 = 5;
     y = x2;
}
