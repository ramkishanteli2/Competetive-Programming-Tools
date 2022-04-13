#include <iostream>
#include <vector>
using namespace std;

int main(){
    int m;
    int n;
    cout << "Enter the No. of bit in Checksum: ";
    cin >> m;
    cout << "Enter the No. of bit in data: ";
    cin >> n;
    cout << "Enter " << n << " bits of data: \n";

    vector<int>data(n,0);

    for(int i = 0;i < n;i++){
        cin >> data[i];
    }

    while(data.size()%m){
        data.push_back(0);
    }
    //Sender side checksum generation
    vector<int>checkSum(m,0);
    for(int i = 0; i < m;i++){
        checkSum[i] = data[i];
    }
    for(int i = m; i < n;i++){
        int j = i+m-1;
        int k = m-1;
        int carry = 0;
        vector<int>tempCheckSum(m,0);
        while(k >= 0){
            int bit = checkSum[k] + data[j] + carry;
            tempCheckSum[k] = bit % 2;
            carry = bit / 2;
            k--;
            j--;
        }
        if(carry){
            k = m-1;
            while(carry and k>=0){
                int bit = tempCheckSum[k] + carry;
                tempCheckSum[k] = bit % 2;
                carry = bit / 2;
                k--;
            }
        }
        checkSum = tempCheckSum;
        i = i+m-1;
    }
    // Transmission
    // Taking 1's complement of checksum
    for(int i = 0;i<m;i++){
        checkSum[i] = !checkSum[i];
    }
    cout << "Obtained checksum: \n";
    for(int i = 0;i<m;i++){
        cout << checkSum[i] << " ";
    }
    cout << endl;
    // Appending checksum to the data
    for(int i = 0 ;i<m;i++){
        data.push_back(checkSum[i]);
    }
    // Receiver side :
    // After transmission checking for validation at receiver side
    cout << "Data has to be sent at sender side: \n";

    for(int i = 0;i< m+n;i++){
        cout << data[i] << " ";
    }
    cout << endl;
    bool flag;
    cout << "Enter 1 if you want to change the data otherwise enter 0: \n";
    cin >> flag;

    if(flag){
        data[0] = !data[0];
    }
    cout << "Data received at receiver side: \n";
    for(int i = 0;i< m+n;i++){
        cout << data[i] << " ";
    }
    cout << endl;
    vector<int>validationSum(m,0);
    for(int i = 0; i < m;i++){
        validationSum[i] = data[i];
    }
    for(int i = m; i < n+m;i++){
        int j = i+m-1;
        int k = m-1;
        int carry = 0;
        vector<int>tempCheckSum(m,0);
        while(k >= 0){
            int bit = validationSum[k] + data[j] + carry;
            tempCheckSum[k] = bit % 2;
            carry = bit / 2;
            k--;
            j--;
        }
        if(carry){
            k = m-1;
            while(carry){
                int bit = tempCheckSum[k] + carry;
                tempCheckSum[k] = bit % 2;
                carry = bit / 2;
                k--;
            }
        }
        validationSum = tempCheckSum;
        i = i+m-1;
    }
    // Again taking 1's complement of validation sum

    for(int i = 0;i < m;i++){
        validationSum[i] = !validationSum[i];
    }

    flag = true;
    for(int i = 0; i < m;i++){
        if(validationSum[i] == 1){
            flag = false;
            break;
        }
    }

    if(flag){
        cout << "No Error, Data Accepted!";
    }else{
        cout << "Error, Data Rejected!";
    }

}
