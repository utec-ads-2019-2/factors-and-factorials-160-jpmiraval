#include <iostream>
#include <map>
#include <cmath>
#include <iomanip>

using namespace std;

map<int,int> factoresPrimos;
int num;

void primeFactors(int n){
    while (n % 2 == 0)
    {
        factoresPrimos[2]++;
        n = n/2;
    }


    for (int i = 3; i <= sqrt(n); i = i + 2)
    {
        while (n % i == 0)
        {
            factoresPrimos[i]++;
            n = n/i;
        }
    }

    if (n > 2)
        factoresPrimos[n]++;
}

int main() {

    while(cin>>num, num!=0){

        cout<<setw(3)<<num<<"! =";
        while(num != 1){
            primeFactors(num);
            num--;
        }
        int contador = 0;
        for(auto it= factoresPrimos.begin();it != factoresPrimos.end()--; it++){
            if(contador == 15) {
                cout<<endl<<"      ";
                contador = 0;
            }
            cout<<setw(3)<<it->second;
            contador++;
        }
        cout<<endl;
        factoresPrimos.clear();
    }
    return 0;
}
