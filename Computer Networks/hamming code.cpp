#include <iostream>
#include <math.h>
using namespace std;
class HammingCode{
    int *data;
    int n;
    int no_parity_bits;
    int *sentData;
    int size;
public:
    bool isPowerOf2(int n){
        while(n%2 == 0){
            n /= 2;
        }
        return n == 1;
    }
    HammingCode(int n){
        this -> n = n;
        data = new int[n];
        cout << "Enter " << n << " bits: " << endl;

        for(int i = n-1;i >= 0;i--){
            cin >> data[i];
        }
        no_parity_bits = ceil(log2(n)) + 1;
        cout << "Total number of parity bits are " << no_parity_bits << endl;
        size = no_parity_bits + n;
        cout << "Total bits has to be sent: " << size << endl;
        sentData = new int[size+1];
        int i = 0;
        int j = 1;
        while(j <= size){
            if(!isPowerOf2(j)){
                sentData[j] = data[i];
                i++;
            }
            j++;
        }

    }
    void sender(){
        int i = 1;
        while(i < size){
            int ones = 0;
            int j = i+1;
            int cnt = 1;
            for(;j <= size;j++){
                if(cnt == i){
                    cnt = 0;
                    j += i - 1;
                }else{
                    cnt++;
                    if(sentData[j]){
                        ones++;
                    }
                }
            }
            //cout << i << " " << ones << " " << endl;
            if(ones % 2){
                sentData[i] = 1;
            }else{
                sentData[i] = 0;
            }
            //cout << sentData[i] << " ";
            i *= 2;
        }
        cout << "Data has to be sent: " <<endl;
        for(int i = size;i >= 1;i--){
            cout << sentData[i] << " ";
        }
        cout << endl;
    }
    void receiver(){
        int i = 1;
        bool flag = true;
        //sentData[1] = !sentData[1];
        cout << "Data received at receiver side: " <<endl;
        for(int i = size;i >= 1;i--){
            cout << sentData[i] << " ";
        }
        cout << endl;

        while(i < size){
            int ones = 0;
            int j = i;
            int cnt = 0;
            for(;j <= size;j++){
                if(cnt == i){
                    cnt = 0;
                    j += i - 1;
                }else{
                    cnt++;
                    if(sentData[j]){
                        ones++;
                    }
                }
            }
            if(ones % 2){
               flag = false;
               break;
            }
            i *= 2;
        }
        if(flag){
            cout << "No Error! Data Accepted!" << endl;
        }else{
            cout << "Error! Data Rejected" << endl;
        }
    }
};
int main(){
    int n;
    cout << "Enter number of data bits: ";
    cin >> n;
    HammingCode obj(n);
    obj.sender();
    obj.receiver();
}
