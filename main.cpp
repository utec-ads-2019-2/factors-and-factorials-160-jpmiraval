#include <iostream>
#include <string>
#include <map>
#include <iomanip>

using namespace std;

map<int, int> mapa;

bool esprimo(int n){
    for(int i = 2; i < n; i++){
        if(n%i == 0 && n != i){
            return false;
        }
    }
    return true;
}

void factory(int num){
    for(int i = 2; i <= num; i ++){

        if(esprimo(i)){
            mapa[i]++;
        }else{

            auto temp = i;
            for(int k = 2; k <= temp; k++){

                if(k ==1)
                    break;



                if(esprimo(k)){
                    while(temp%k == 0 && k!=1){
                        temp = temp / k;
                        mapa[k]++;
                    }
                }

            }

        }



    }
}



int main() {
    string numero;
    int num;

    while(cin >> numero){
        if(numero == "O")
            break;

        num = stoi(numero);
        factory(num);

        cout << setw(3) << num << "!";
        cout << setw(3) << "=";


    for(auto c : mapa){
        cout << setw(3) << c.second;
    }

    cout << endl;

    mapa.clear();
    }

    return 0;
}