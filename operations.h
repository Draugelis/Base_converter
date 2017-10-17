#include <iostream>
#include <string>
#include <sstream>
#include <cmath>
#include <iomanip>
using namespace std;

#ifndef OPERATIONS_H_INCLUDED
#define OPERATIONS_H_INCLUDED

struct number
{
    string value;
    int base;
};
void f_point(number in, int &f_lim, int &d_lim);
void oct_hex_to_bin(number in, number& out);
void dec_to_bin(number in, number& out);
void bin_to_oct_hex(number in, number& out);
void bin_to_dec(number in, number& out);
void output(number out);
long double power(int a, int n);
long long int f_separation(number in, int d_lim);

void oct_hex_to_bin(number in, number& out)
{
    char temp;
    if(in.base == 2)
    {
        for (char i : in.value) {
            temp = i;
            switch(temp)
            {
                case '0':
                    out.value.append("000");
                    break;
                case '1':
                    out.value.append("001");
                    break;
                case '2':
                    out.value.append("010");
                    break;
                case '3':
                    out.value.append("011");
                    break;
                case '4':
                    out.value.append("100");
                    break;
                case '5':
                    out.value.append("101");
                    break;
                case '6':
                    out.value.append("110");
                    break;
                case '7':
                    out.value.append("111");
                    break;
                case ',':
                case '.':
                    out.value.append(",");
                    break;
                default: break;
            }
        }
    }
    else if(in.base == 3)
    {
        for (char i : in.value) {
            temp = i;
            switch(temp)
            {
                case '0':
                    out.value.append("0000");
                    break;
                case '1':
                    out.value.append("0001");
                    break;
                case '2':
                    out.value.append("0010");
                    break;
                case '3':
                    out.value.append("0011");
                    break;
                case '4':
                    out.value.append("0100");
                    break;
                case '5':
                    out.value.append("0101");
                    break;
                case '6':
                    out.value.append("0110");
                    break;
                case '7':
                    out.value.append("0111");
                    break;
                case '8':
                    out.value.append("1000");
                    break;
                case '9':
                    out.value.append("1001");
                    break;
                case 'a':
                case 'A':
                    out.value.append("1010");
                    break;
                case 'b':
                case 'B':
                    out.value.append("1011");
                    break;
                case 'c':
                case 'C':
                    out.value.append("1100");
                    break;
                case 'd':
                case 'D':
                    out.value.append("1101");
                    break;
                case 'e':
                case 'E':
                    out.value.append("1110");
                    break;
                case 'f':
                case 'F':
                    out.value.append("1111");
                    break;
                case ',':
                case '.':
                    out.value.append(",");
                    break;
                default: break;
            }
        }
    }
}
void dec_to_bin(number in, number& out)
{
    const int max_bin = 20;
    bool ss(false);
    long double in_value, d_val;
    int f_lim(0), d_lim(0);
    long long int f_val;
    f_point(in, f_lim, d_lim);
    f_val = f_separation(in, d_lim);
    cout << f_val << "x";
    istringstream iss (in.value);
    iss >> in_value;
    d_val = floor(in_value);
    for(int i = max_bin; i >= 0; i--)
    {
        if(d_val >= power(2, i))
        {
            ss = true;
            d_val -= power(2, i);
            out.value.append("1");
        }
        else if(d_val < pow(2, i) && ss) {
            out.value.append("0");
        }
    }
    if(!ss) out.value.append("0");
    if(f_lim > 0)
    {
        out.value.append(",");
        int i(0);
        while(f_val != 0 && i < 120)
        {
            f_val *= 2;
            if(f_val >= power(10, f_lim ))
            {
                f_val -= power(10, f_lim);
                out.value.append("1");
            }
            else out.value.append("0");
            i++;
        }
    }
}
void bin_to_oct_hex(number in, number& out)
{
    int f_lim(0), d_lim(0);
    f_point(in, f_lim, d_lim);
    string temp_ch;
    if(out.base == 2)
    {
        if(f_lim % 3 == 1) in.value.append("00");
        else if(f_lim % 3 == 2) in.value.append("0");
        if(d_lim % 3 == 1) { in.value.insert (0, 2, '0'); d_lim += 2;}
        else if(d_lim % 3 == 2) { in.value.insert (0, 1, '0'); d_lim++;}
        for(int i = 0; i < d_lim; i += 3)
        {
            int temp(0);
            if(in.value[i] == '1') temp += 4;
            if(in.value[i + 1] == '1') temp += 2;
            if(in.value[i + 2] == '1') temp += 1;
            temp_ch = to_string(temp);
            out.value += temp_ch;
        }
        if(f_lim > 0)
        {
            out.value.append(",");
            for(int i = d_lim + 1; i < in.value.length(); i += 3)
            {
                int temp(0);
                if(in.value[i] == '1') temp += 4;
                if(in.value[i + 1] == '1') temp += 2;
                if(in.value[i + 2] == '1') temp += 1;
                temp_ch = to_string(temp);
                out.value += temp_ch;
            }

        }
    }
    else if(out.base == 3)
    {
        if(f_lim % 4 == 1) in.value.append("000");
        else if(f_lim % 4 == 2) in.value.append("00");
        else if(f_lim % 4 == 3) in.value.append("0");
        if(d_lim % 4 == 1) { in.value.insert (0, 3, '0'); d_lim += 3;}
        else if(d_lim % 4 == 2) { in.value.insert (0, 2, '0'); d_lim += 2;}
        else if(d_lim % 4 == 3) { in.value.insert (0, 1, '0'); d_lim++;}
        for(int i = 0; i < d_lim; i += 4)
        {
            int temp(0);
            if(in.value[i] == '1') temp += 8;
            if(in.value[i + 1] == '1') temp += 4;
            if(in.value[i + 2] == '1') temp += 2;
            if(in.value[i + 3] == '1') temp += 1;
            switch(temp)
            {
                case 0: temp_ch = '0'; break;
                case 1: temp_ch = '1'; break;
                case 2: temp_ch = '2'; break;
                case 3: temp_ch = '3'; break;
                case 4: temp_ch = '4'; break;
                case 5: temp_ch = '5'; break;
                case 6: temp_ch = '6'; break;
                case 7: temp_ch = '7'; break;
                case 8: temp_ch = '8'; break;
                case 9: temp_ch = '9'; break;
                case 10: temp_ch = 'A'; break;
                case 11: temp_ch = 'B'; break;
                case 12: temp_ch = 'C'; break;
                case 13: temp_ch = 'D'; break;
                case 14: temp_ch = 'E'; break;
                case 15: temp_ch = 'F'; break;
                default: break;
            }
            out.value += temp_ch;
        }
        if(f_lim > 0)
        {
            out.value.append(",");
            for(int i = d_lim + 1; i < in.value.length(); i += 4)
            {
                int temp(0);
                if(in.value[i] == '1') temp += 8;
                if(in.value[i + 1] == '1') temp += 4;
                if(in.value[i + 2] == '1') temp += 2;
                if(in.value[i + 3] == '1') temp += 1;
                switch(temp)
                {
                    case 0: temp_ch = '0'; break;
                    case 1: temp_ch = '1'; break;
                    case 2: temp_ch = '2'; break;
                    case 3: temp_ch = '3'; break;
                    case 4: temp_ch = '4'; break;
                    case 5: temp_ch = '5'; break;
                    case 6: temp_ch = '6'; break;
                    case 7: temp_ch = '7'; break;
                    case 8: temp_ch = '8'; break;
                    case 9: temp_ch = '9'; break;
                    case 10: temp_ch = 'A'; break;
                    case 11: temp_ch = 'B'; break;
                    case 12: temp_ch = 'C'; break;
                    case 13: temp_ch = 'D'; break;
                    case 14: temp_ch = 'E'; break;
                    case 15: temp_ch = 'F'; break;
                    default: break;
                }
                out.value += temp_ch;
            }
        }
    }
}
void bin_to_dec(number in, number& out)
{
    int d_lim(0), f_lim(0), n(0), precision(0);
    float temp(0);
    f_point(in, f_lim, d_lim);

    for(int i = d_lim; i >= 0; i--)
    {
        if(in.value[i] == '1') temp += power(2, n);
        n++;
    }
    if(f_lim > 0)
    {
        cout << "\nEnter precision value: ";
        cin >> precision;
        n = -1;
        for(int i = d_lim; i < in.value.length(); i++)
        {
            if(in.value[i] == '1') temp += power(2, n);
            n--;
        }
    }
    ostringstream strs;
    strs << fixed << setprecision(precision) << temp;
    out.value = strs.str();
}
void f_point(number in, int &f_lim, int &d_lim)
{
    for (char i : in.value) {
        if(i == '.' || i == ',') break;
        d_lim++;
    }
    if(d_lim + 1 != in.value.length())
    {
        for (int i = d_lim + 2; i <= in.value.length(); i++)
        {
            f_lim++;
        }
    }
}
void output(number out)
{
    cout << "\nOutput number: " << out.value;
}
long double power(int a, int n)
{
    double ans(1);
    if(n > 0) for(int i = 0; i < n; i++) ans *= a;
    else if(n < 0) for(int i = 0; i > n; i--) ans /= a;

    return ans;
}
long long int f_separation(number in, int d_lim)
{
    long long int a(0);
    for(int i = d_lim + 1; i < in.value.length(); i++)
    {
        a *= 10;
        a += in.value[i] - 48;
    }

    return a;
}

#endif // OPERATIONS_H_INCLUDED
