#include <iostream>
#include <string>
#include <Windows.h>

using namespace std;

class Drob {

private:
    int chisl;
    int znamen;
    int NOD(int x, int y)
    {
        if (y == 0) return x;
        return NOD(y, x % y);
    }
public:
    void input(int c, int z)
    {
        chisl = c;
        znamen = z;
    }
    void mult(int x)
    {
        chisl *= x;
        cout << "drob:  " << chisl << '/' << znamen << endl;
    }
    void div(int x)
    {
        znamen *= x;
        cout << "drob:  " << chisl << '/' << znamen << endl;

    }

    void sum(int x)
    {
        chisl += (x * znamen);
        cout << "drob:  " << chisl << '/' << znamen << endl;
    }
    void sub(int x)
    {
        chisl -= (x * znamen);
        cout << "drob:  " << chisl << '/' << znamen << endl;

    }
    void show()
    {
        cout << "tekushaya drob:  " << chisl << '/' << znamen << endl;
    }
    int peredacha()
    {
        return NOD(chisl, znamen);
    }
    void reduct(int x)
    {
        chisl /= x;
        znamen /= x;
    }

};



int main() {

    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    int a, b, m;
    char c = 'y';
    cout << "Введіть чисельник" << endl;
    cin >> a;
    cout << "ВВедіть знаменик" << endl;
    cin >> b;
    Drob obj;
    obj.input(a, b);
    do {
        obj.reduct(obj.peredacha());
        obj.show();
        cout << "1:Додати число" << endl;
        cout << "2:Відняти число" << endl;
        cout << "3:Помножити число" << endl;
        cout << "4:Поділити число" << endl;
        cout << "Введіть номер функції " << '\n';
        cin >> m;
        switch (m)
        {
        case 1:
            cout << "Введіть число" << endl;
            cin >> a;
            obj.sum(a);
            break;
        case 2:
            cout << "Введіть число" << endl;
            cin >> a;
            obj.sub(a);
            break;
        case 3:
            cout << "Введіть число"  << endl;
            cin >> a;
            obj.mult(a);
            break;
        case 4:
            cout << "Введіть число" << endl;
            cin >> a;
            obj.div(a);
            break;
        default:
            cout << "Введіть правильно число" << endl;
        }
        cout << "Продавжити ?(y/n)" << endl;
        cin >> c;
    } while (c != 'n');
    return 0;
}