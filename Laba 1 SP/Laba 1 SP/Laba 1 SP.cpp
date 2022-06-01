#include <iostream>


using namespace std;

void Func() {
    cout << ":)" << endl;
}

class Operations {

public:


    int Addition(int x, int y)
    {
        _asm
        {
            mov eax, x;
            mov ebx, y;
            add eax, ebx;
            mov x, eax;
        }
        return x;
    }

    int Subtraction(int x, int y)
    {
        _asm
        {
            mov eax, x;
            mov ebx, y;
            sub eax, ebx;
            mov x, eax;
        }
        return x;
    }

    int Multiplication(int x, int y)
    {
        _asm
        {
            mov eax, x;
            mov ebx, y;
            mul ebx;
            mov x, eax;
        }
        return x;
    }

    int Division(int x, int y)
    {
        _asm
        {
            mov eax, x;
            mov ecx, y;
            sub edx, edx;
            div ecx;
            mov x, eax;
        }
        return x;
    }

    int CompM(int x, int y)
    {
        int z = 0;
        _asm
        {
            mov eax, x;
            cmp eax, y;
            JG t;
            mov eax, 0;
            JMP f;
        t: mov eax, 1;
        f: mov z, eax;
        }
        return z;
    }

    int CompE(int x, int y)
    {
        int z = 0;
        _asm
        {
            mov eax, x;
            mov ebx, y;
            cmp eax, ebx;
            JE t;
            mov eax, 0;
            JMP f;
        t: mov eax, 1;
        f: mov z, eax;
        }
        return z;
    }

    int CompL(int x, int y)
    {
        int z = 0;
        _asm
        {
            mov eax, x;
            cmp eax, y;
            JL t;
            mov eax, 0;
            JMP f;
        t: mov eax, 1;
        f: mov z, eax;
        }
        return z;
    }

    int XNot(int x)
    {
        _asm
        {
            mov eax, x;
            not eax; 
            mov x, eax;
        }
        return x;
    }

    int YNot(int y)
    {
        _asm
        {
            mov eax, y;
            not eax;
            mov y, eax;
        }
        return y;
    }

    int And(int x, int y)
    {
        _asm
        {
            mov eax, x;
            mov ebx, y;
            and ebx, eax; 
            mov y, ebx;
        }
        return y;
    }

    int Or(int x, int y)
    {
        _asm
        {
            mov ebx, x;
            mov eax, y;
            or ebx, eax; 
            mov y, ebx;
        }
        return y;
    }

    int Xor(int x, int y)
    {
        _asm
        {
            mov ebx, x;
            mov eax, y;
            xor ebx, eax;
            mov y, ebx;
        }
        return y;
    }

    int SHR(int x)
    {
        _asm
        {
            mov eax, x;

            shr eax, 1;
            mov x, eax;

        }
        return x;
    }

    int SAR(int x)
    {
        _asm
        {
            mov eax, x;
            sar eax, 1;
            mov x, eax;

        }
        return x;
    }

    int SAL(int x)
    {
        _asm
        {
            mov eax, x;
            sal eax, 1;
            mov x, eax;

        }
        return x;
    }

    int SHL(int x)
    {
        _asm
        {
            mov eax, x;
            shl eax, 1;
            mov x, eax;
        }
        return x;
    }

    int ROL(int x)
    {
        _asm
        {
            mov eax, x;
            rol eax, 1;
            mov x, eax;
        }
        return x;
    }

    int ROR(int x)
    {
        _asm
        {
            mov eax, x;
            ror eax, 1;
            mov x, eax;
        }
        return x;
    }

    int IndexMas(int* x, int y)
    {
        int z;
        _asm
        {
            mov eax, x
            mov ebx, y
            mov ebx, [eax + 4 * ebx]
            mov z, ebx
        }
        return z;
    }

    int Iter(void* func, int iter)
    {
        _asm {
            mov edi, 0
            mov esi, iter
            L : call func
            inc   edi
            cmp   edi, esi
            jb    L
        }
    }

};
int n;
int* a = new int[n];


int main()
{
    setlocale(LC_ALL, "Russian");
    Operations oper;
    int x;
    int y;

   // cout << "Данные операции можно выполнять с числами со знаком " << "\n";

    cout << "first numeric: ";
    cin >> x;
    cout << "second numeric: ";
    cin >> y;
    if (y == 0) {
        while (y == 0)
        {
            cout << "the second number must not be zero: ";
            cin >> y;
        }
    }
    cout << "\n";

    cout << "1. mathematic operations" << endl;
    cout << x << " + " << y << " = " << oper.Addition(x, y) << "\n";
    cout << x << " - " << y << " = " << oper.Subtraction(x, y) << "\n";
    cout << x << " * " << y << " = " << oper.Multiplication(x, y) << "\n";
    cout << x << " / " << y << " = " << oper.Division(x, y) << "\n";
    cout << "\n";

    cout << "2. Compare numbers" << endl;
    if (oper.CompM(x, y) == 1)
    {
        cout << x << " > " << y << "\n";
    };

    if (oper.CompE(x, y) == 1)
    {
        cout << x << " = " << y << "\n";
    };

    if (oper.CompL(x, y) == 1)
    {
        cout << x << " < " << y << "\n";
    };
    cout << "\n";

    cout << "3. Logic operations" << endl;
    cout << "Not " << x << " = " << oper.XNot(x) << "\n";
    cout << "Not " << y << " = " << oper.YNot(y) << "\n";
    cout << x << " & " << y << " = " << oper.And(x, y) << "\n";
    cout << x << " or " << y << " = " << oper.Or(x, y) << "\n";
    cout << x << " ^ " << y << " = " << oper.Xor(x, y) << "\n";
    cout << "\n";

    cout << "4.shift operations" << "\n";
    cout << "Enter number: ";
    cin >> x;
    cout << "\n";
    cout << "SHR (right shift log): " << oper.SHR(x) << "\n";
    cout << "SHL (left shift log): " << oper.SHL(x) << "\n";
    cout << "SAR (right shift arf): " << oper.SAR(x) << "\n";
    cout << "SAL (left shift arf): " << oper.SAL(x) << "\n";
    cout << "ROR (cyclic shift to the right): " << oper.ROR(x) << "\n";
    cout << "ROL (cyclic shift to the left): " << oper.ROL(x) << "\n";
    cout << "\n";

    cout << "5.array indexing" << "\n";
    cout << "array size:";
    cin >> n;
    cout << "\n";
    cout << "Enter numbers: " << endl;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    };

    cout << "\nYour array:\n";
    for (int i = 0; i < int(n); i++)
        cout << a[i] << " ";
    cout << "\n";

    cout << "Enter array position number:";
    cin >> y;
    while (y > n)
    {
        cout << "you enter false position!" <<"\n";
        cout << "Enter array position number:";
        cin >> y;
    }
    cout << "Number on the position:" << y << " " << " = " << "'" << oper.IndexMas(a, y) << "'" << endl;
    cout << "\n";

    cout << oper.Iter(Func, 10);

    system("pause");
};