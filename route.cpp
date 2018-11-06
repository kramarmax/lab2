#include "route.h"

route::route()     /// конструктор без параметров
{
    start=new char[20];
    finish=new char[20];
}
route::route(const route &arg)     ///конструктор копирования
{
    start=new char[20];
    finish=new char[20];
    strcpy(start, arg.start);
    strcpy(finish, arg.finish);
    number=arg.number;
}
route::route(char *strt, char *fnsh, int nmbr)
{
    start=new char[20];
    finish=new char[20];
    strcpy(start, strt);
    strcpy(finish, fnsh);
    number=nmbr;
}

bool route::vivod(char *punkt)
{
    if(!strcmp(start, punkt) || !strcmp(finish, punkt))
        return 1;
    else
        return 0;
}
bool route::Bubble_sort(route element)
{
    if(number > element.number)
        return 1;
    else
        return 0;
}
route::~route()        /// деструктор
{
    delete [] start;
    delete [] finish;
}

istream& operator >> (istream& instream, route& rt)
{
    cout<<"\nВведите начальный пункт: ";
    instream>>rt.start;
    cout<<"Введите конечный пункт: ";
    instream>>rt.finish;
    do
    {
        cout<<"Введите номер маршрута: ";
        try
        {
            instream>>rt.number;
            for(int i=0; i<ch_nmb; i++)
            {
                if(rt.number==check_number[i])
                    throw 666;
            }
            check_number[ch_nmb]=rt.number;
            break;
        }
        catch(int i)
        {
            cout<<"Ошибка №"<<i<< " - такой номер маршрута уже был введён ранее\n";
        }

    }while(1);
    ch_nmb++;
    return instream;
}

ostream& operator << (ostream& outstream, route& rt)
{
    outstream<<rt.start<<' ';
    outstream<<rt.finish<<' ';
    outstream<<rt.number<<"\n\n";
    return outstream;
}
