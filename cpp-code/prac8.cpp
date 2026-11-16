#include<iostream>
#include<string>
#include<stack>
#include<cctype>
using namespace std;

string reverse(string str){
    stack<char> s;
    string rev = "";

    for(char c:str){
        s.push(c);
    }

    while(!s.empty()){
        rev+=s.top();
        s.pop();
    }

    return rev;
        
}

bool is_palindrome(string str){
    string clean = "";

    for(char c : str){
        if(isalnum(c)){
            clean += tolower(c);
        }
    }

    return clean == reverse(clean);
}
int main(){
    string str;

    cout << "Enter a string: ";
    getline(cin, str);

    cout << "Original String: " << str << endl;
    cout << "Reversed String: " << reverse(str) << endl;

    if (is_palindrome(str))
        cout << "The string is a palindrome.";
    else
        cout << "The string is not a palindrome.";

    return 0;

}