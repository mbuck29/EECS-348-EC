#include <iostream>
#include <iomanip>
#include <string>
#include <cmath>

using namespace std;

double extracNumeric(const string& str) {
    
    double result;
    const char *curr_number = str.c_str();
    const char *dec_point_loc = str.c_str();
    const char *first_int = str.c_str();
    int loop_num = 0;
    int converted_num;
    
    if (str[0] == '-' || str[0] == '+') {
        first_int++;
    }
    
    while (*dec_point_loc != '\0') {
        if (*dec_point_loc == '.') {
            break;
        }else {
            dec_point_loc++;
        }
    }
    curr_number = dec_point_loc;
    
    while (curr_number != first_int) {
        curr_number--;
        if (*curr_number >= '0' && *curr_number <= '9'){
            converted_num = *curr_number - '0';
            result += converted_num * pow(10, loop_num);
            loop_num++;
        } else {
            return -999999.99;
        }    
    }
    curr_number = dec_point_loc;
    curr_number++;
    loop_num = 1;
    
    while (*curr_number != '\0'){
        if (*curr_number >= '0' && *curr_number <= '9'){
            converted_num = *curr_number - '0';
            result += converted_num / pow(10, loop_num);
            loop_num++;
            curr_number++;
        } else {
            return -999999.99;
        }
    }
    if (str[0] == '-') {
        return result * -1;
    }
    return result;
}

int main()
{
    string input;
    while (true) {
        cout << "Enter a tring (or 'END' to quit): ";
        cin >> input;
        
        if (input == "END") {
            break;
        }
        double number = extracNumeric(input);
        
        if (number != -999999.99) {
            cout << "The input is: " << fixed << setprecision(4) 
                 << number << endl;
        } else {
            cout << "The input is invalid." << endl;
        }
    }
    return 0;
}