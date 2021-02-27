#include <stdio.h>
#include <math.h>

int main()
{
int i, k, n, m; // i, k - счетчики циклов, n, m - длины последовательностей
float a, b, c, d, p0, h, x; // остальные переменные
float p, ak, S; // p, ak - текущее значение последовательностей, S - значение суммы
//Ввод данных
printf("Введите значения n, m, a, b, c, d, p0, h\n");
scanf("%i%i%f%f%f%f%f%f", &n,&m,&a,&b,&c,&d,&p0,&h);

// 1.Посчитаю и выведу х
if(a>b)
    x=a;
else
    x=b;
if(c<d)
    x+=c;
else
    x+=d;

printf("x=%f\n",x);

//2. Работа с рекуррентными формулами
for(i=1; i<=m; i++)
{
    p=p0+(i-1)*h; // вычисление текущего значения p;
    ak = (-1)*p*cos(2*x); // вычисление a1
    printf("a1=%f ",ak); // вывод a1
    S = ak; // занесение в сумматор а1, т.к. оно точно является нечетным
    
    for(k=2; k<=n; k++)
    {
       ak = (-1)*ak*cos(2*x)*p/k; //вычисление текущего значение ak
       printf("a%i=%f ", k, ak); // вывод значения очередного члена последовательности
       if(k%2!=0) // проверка на четность, если не верно, то делать ничего не надо
           S += ak; // добавление в сумматор, если нечетно
    }
    printf("p=%f ",p); // вывод текущего значения p;
    printf("S=%f\n",S); // вывод суммы нечетных членов
}
return 0;
}
