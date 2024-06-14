#include <iostream>
#include <stdlib.h>
using namespace std;

int main(){
    int n;
    do
    {
    cout << "moi ban nhap so tien: ";
    cin >> n;
    } while (n<10000);
    if (n % 10000 != 0){
        cout << "so tien phai chia het cho 10.000\n";
        return 1;
    }
    int motTram = n/100000;
    n = n % 100000;
    int namMuoi = n/50000;
    n = n % 50000;
    int haiMuoi = n/20000;
    n = n % 20000;
    int muoi = n/10000;
    cout<<"Ket qua: \n";
    cout<<motTram<<" x 100.000 + "<<namMuoi<<" x 50.000 + "
        <<haiMuoi<<" x 20.000 + "<<muoi<<" x 10.000"<<endl;
    system("pause");

    return 0;
}
