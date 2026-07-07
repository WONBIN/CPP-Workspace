#include <iostream>

#include <string>



using namespace std;



int main() {

    string input = "0123456789-2381937466-015628391847-34849512067";



    string alphabet = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";

    string result = "";



    for (char ch : input) {

        if (ch == '-') {

            result += '-';

        }

        else {

            int n = ch - '0';



            alphabet = alphabet.substr(n) + alphabet.substr(0, n);



            result += alphabet[n];
        }
    }

    cout << result << endl;

    return 0;

}