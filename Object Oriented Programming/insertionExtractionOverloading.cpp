#include <iostream>
using namespace std;

class Complex{
    int a,b;
public:
    void showData(){
        cout << a << "+i" << b << endl;
    }
    friend istream& operator >> (istream&,Complex &obj);
    friend ostream& operator << (ostream&,Complex &obj);
};
istream& operator >> (istream&din,Complex &c1){
        din >> c1.a >> c1.b;
        return din;
}
ostream& operator << (ostream&dout,Complex &obj){
    dout << obj.a << "+i" << obj.b << endl;
}
int main(){
    Complex c1;
    cin >> c1;
    cout << c1;
}
