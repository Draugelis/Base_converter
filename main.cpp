#include "operations.h"
using namespace std;
int main()
{
    number in_number, out_number;
    char op;
    do
    {
        system("cls");
        cout << "1) Binary\n2) Octal\n3) Hexadecimal\n4) Decimal";
        out_number.value = "";
        cout << "\nEnter input number base: ";
        cin >> in_number.base;
        cout << "Enter output number base: ";
        cin >> out_number.base;
        if(out_number.base == in_number.base)
        {
            cout << "\nError: You can't convert number to itself\n";
        }
        else {
            cout << "Enter input number: ";
            cin >> in_number.value;
            if (in_number.base == 1) {
                if (out_number.base == 2 || out_number.base == 3) {
                    bin_to_oct_hex(in_number, out_number);
                } else if (out_number.base == 4) {
                    bin_to_dec(in_number, out_number);
                }
            } else if (in_number.base == 2) {
                if (out_number.base == 1) {
                    oct_hex_to_bin(in_number, out_number);
                } else if (out_number.base == 3) {
                    number temp_number;
                    temp_number.base = 2;
                    oct_hex_to_bin(in_number, temp_number);
                    bin_to_oct_hex(temp_number, out_number);
                } else if (out_number.base == 4) {
                    number temp_number;
                    temp_number.base = 2;
                    oct_hex_to_bin(in_number, temp_number);
                    bin_to_dec(temp_number, out_number);
                }

            } else if (in_number.base == 3) {
                if (out_number.base == 1) {
                    oct_hex_to_bin(in_number, out_number);
                } else if (out_number.base == 2) {
                    number temp_number;
                    temp_number.base = 3;
                    oct_hex_to_bin(in_number, temp_number);
                    bin_to_oct_hex(temp_number, out_number);
                } else if (out_number.base == 4) {
                    number temp_number;
                    temp_number.base = 3;
                    oct_hex_to_bin(in_number, temp_number);
                    bin_to_dec(temp_number, out_number);
                }

            } else if (in_number.base == 4) {
                if (out_number.base == 1) {
                    dec_to_bin(in_number, out_number);
                } else if (out_number.base == 2 || out_number.base == 3) {
                    number temp_number;
                    dec_to_bin(in_number, temp_number);
                    bin_to_oct_hex(temp_number, out_number);
                }

            }
            output(out_number);
        }
        cout << "\nDo you want continue working? (Enter 'Y' to continue, any other key to quit)\n> ";
        cin >> op;
    } while (op == 'Y' || op == 'y');
    return 0;
}
