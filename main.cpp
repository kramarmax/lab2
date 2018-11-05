#include <iostream>
#include <locale>
#include <cstdio>
#include <cstring>
#include <windows.h>

using namespace std;

class route
{
private:
    char *start;
    char *finish;
    int number;
public:
    route()     
    {
        start=new char[20];
        finish=new char[20];
    }
    route(const route &arg)     
    {
        start=new char[20];
        finish=new char[20];
        strcpy(start, arg.start);
        strcpy(finish, arg.finish);
		    number=arg.number;
    }
    friend istream& operator >> (istream&, route&);
    friend ostream& operator << (ostream&, route&);
    bool vivod(char *punkt)
    {
        if(!strcmp(start, punkt) || !strcmp(finish, punkt))
            return 1;
        else
            return 0;
    }
    bool Bubble_sort(route element)
    {
        if(number > element.number)
            return 1;
        else
            return 0;
    }
    ~route()        /// деструктор
    {
        delete [] start;
        delete [] finish;
    }
};
istream& operator >> (istream& instream, route& rt)
{
    cout<<"Введите начальный пункт: ";
    instream>>rt.start;
    cout<<"Введите конечный пункт: ";
    instream>>rt.finish;
    cout<<"Введите номер маршрута: ";
    instream>>rt.number;
    return instream;
}

ostream& operator << (ostream& outstream, route& rt)
{
    outstream<<rt.start<<' ';
    outstream<<rt.finish<<' ';
    outstream<<rt.number<<"\n\n";
    return outstream;
}


int main()
{
    setlocale(LC_ALL, "rus");
    const int N=8;
    route inform[N];
    for(int i=0; i<N; i++)
        cin>>inform[i];
    route a;
    for(int i=0; i<N-1; i++)    ///сортировка пузырьком
    {
        for(int j=0; j<N-i-1; j++)
        {
            if(inform[j].Bubble_sort(inform[j+1]))
            {
                a = inform[j];
                inform[j] = inform[j+1];
                inform[j+1] = a;
            }
        }
    }
    while(1)
    {
        system("cls");
        cout<<"1 - Вывести информацию о маршрутах на экран\n2 - Вывести маршруты содержащие название пункта\n0 - Выход\n\n";
        int c;
        cin>>c;
        switch(c)
        {
        case 1:
            for(int i=0; i<N; i++)
                cout<<inform[i];
            break;

        case 2:
            {
                char punkt[20];
                cout<<"Введите название пункта: ";
                cin>>punkt;
                bool is_there=0;
                for(int i=0; i<N; i++)
                {
                    if(inform[i].vivod(punkt))
                    {
                        cout<<inform[i];
                        is_there=1;
                    }
                }
                if(!is_there)
                    cout<<"\nМаршрутов, с таким пунктом, нет\n\n";
                break;
            }
        default: cout<<"Введена неверная цифра!\n\n"; break;
        case 0:   exit(1);
        }
        system("pause");
    }
    return 0;
}
