#include <iostream>
#include <locale>
#include <cstdio>
#include <cstring>
#include <windows.h>
#include <iomanip>
const int N=8;
int check_number[N];    /// массив дл€ номеров маршрута (дл€ исключений)
int ch_nmb=0;           /// счЄтчик дл€ этого массива
using namespace std;
#include "route.cpp"

int main()
{
    setlocale(LC_ALL, "rus");
    route inform[N];
    /*route b("ne4opa", "CTaBponoJIb", 15);
    cout<<b;                    //проверка конструктора с параметрами
    system("pause");*/
    system("cls");
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
        cout<<"1 - ¬ывести информацию о маршрутах на экран\n2 - ¬ывести маршруты содержащие название пункта\n0 - ¬ыход\n\n";
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
                cout<<"¬ведите название пункта: ";
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
                    cout<<"\nћаршрутов, с таким пунктом, нет\n\n";
                break;
            }
        default: cout<<"¬ведена неверна€ цифра!\n\n"; break;
        case 0:   exit(1);
        }
        system("pause");
    }
    return 0;
}
