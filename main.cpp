#include <iostream>
#include "operations.h"
using namespace std;
int main()
{
    number in_number, out_number;
    char op;
    cout << "a) Binary\nb) Octal\nc) Hexadecimal\nd) Decimal\n";
    do
    {
        out_number.value = "";
        cout << "\nEnter input number base: ";
        cin >> in_number.base;
        cout << "Enter output number base: ";
        cin >> out_number.base;
        cout << "Enter input number: ";
        cin >> in_number.value;
        if(in_number.base == 'a' || in_number.base == 'A')
        {
            if(out_number.base == 'b' || out_number.base == 'B' ||
               out_number.base == 'c' || out_number.base == 'C')
            {
                bin_to_oct_hex(in_number, out_number);
            }
            else if(out_number.base == 'd' || out_number.base == 'D')
            {
                bin_to_dec(in_number, out_number);
            }
        }
        else if(in_number.base == 'b' || in_number.base == 'B')
        {
            if(out_number.base == 'a' || out_number.base == 'A')
            {
                oct_hex_to_bin(in_number, out_number);
            }
            else if(out_number.base == 'c' || out_number.base == 'C')
            {
                number temp_number;
                temp_number.base = 'b';
                oct_hex_to_bin(in_number, temp_number);
                bin_to_oct_hex(temp_number, out_number);
            }
            else if(out_number.base == 'd' || out_number.base == 'D')
            {
                number temp_number;
                temp_number.base = 'b';
                oct_hex_to_bin(in_number, temp_number);
                bin_to_dec(temp_number, out_number);
            }

        }
        else if(in_number.base == 'c' || in_number.base == 'C')
        {
            if(out_number.base == 'a' || out_number.base == 'A')
            {
                oct_hex_to_bin(in_number, out_number);
            }
            else if(out_number.base == 'b' || out_number.base == 'B')
            {
                number temp_number;
                temp_number.base = 'c';
                oct_hex_to_bin(in_number, temp_number);
                bin_to_oct_hex(temp_number, out_number);
            }
            else if(out_number.base == 'd' || out_number.base == 'D')
            {
                number temp_number;
                temp_number.base = 'c';
                oct_hex_to_bin(in_number, temp_number);
                bin_to_dec(temp_number, out_number);
            }

        }
        else if(in_number.base == 'd' || in_number.base == 'D')
        {
            if(out_number.base == 'a' || out_number.base == 'A')
            {
                dec_to_bin(in_number, out_number);
            }
            else if(out_number.base == 'b' || out_number.base == 'B' ||
               out_number.base == 'c' || out_number.base == 'C')
            {
                number temp_number;
                dec_to_bin(in_number, temp_number);
                bin_to_oct_hex(temp_number, out_number);
            }

        }
        output(out_number);
        cout << "\nDo you want continue working? [Y/N]\n> ";
        cin >> op;
    } while (op == 'Y' || op == 'y');
    return 0;
}
