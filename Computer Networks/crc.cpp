#include <iostream>
#include <vector>
#include <deque>
using namespace std;

class CRC{
    int crcSize;
    int dataSize;
    string crcGen;
    string data;
    int newSize;
public:
    CRC(int n,int m){
        crcSize = n;
        dataSize = m;
        cout << "Enter CRC Generator bits: ";
        cin >> crcGen;
        cout << "Enter data bits: ";
        cin >> data;
        //Adding n-1 0 bits at the end of data bits
        int k = n-1;
        while(k--){
            data.push_back('0');
        }
        newSize = data.size();
    }
    void sender(){
        deque<char>crc;
        for(int i = 0;i < crcSize-1;i++){
            crc.push_back(data[i]);
        }
        for(int i = crcSize-1;i < newSize;i++){
            crc.push_back(data[i]);
            if(crc.front() == '0'){
                crc.pop_front();
                continue;
            }
            for(int j = 0;j < crcSize;j++){
                if(crcGen[j] == crc.front()){
                    crc.push_back('0');
                }else{
                    crc.push_back('1');
                }
                crc.pop_front();
            }
            crc.pop_front();
        }
        //Printing obtained CRC in deque
        cout << "Obtained CRC bits: ";
        for(int i = 0;i < crcSize-1;i++){
            cout << crc.front();
            crc.push_back(crc.front());
            crc.pop_front();
        }
        cout << endl;
        //Replacing CRC bits to the end of data
        int j = data.size() - crc.size();
        for(int i = 0;i < crcSize-1;i++){
            data[j] = crc.front();
            crc.push_back(crc.front());
            crc.pop_front();
            j++;
        }
        //Sent data to from sender
        cout << "Data bits sent from sender side: ";
        cout << data << endl;
    }
    void receiver(){
        cout << "Data bits received at the receiver side: ";
        cout << data << endl;
        deque<char>crc;
        for(int i = 0;i < crcSize-1;i++){
            crc.push_back(data[i]);
        }
        for(int i = crcSize-1;i < newSize;i++){
            crc.push_back(data[i]);
            if(crc.front() == '0'){
                crc.pop_front();
                continue;
            }
            for(int j = 0;j < crcSize;j++){
                if(crcGen[j] == crc.front()){
                    crc.push_back('0');
                }else{
                    crc.push_back('1');
                }
                crc.pop_front();
            }
            crc.pop_front();
        }
        //Printing obtained CRC in deque
        cout << "Final obtained remainder after binary division at receiver size: ";
        bool flag = true;
        for(int i = 0;i < crcSize-1;i++){
            cout << crc.front();
            if(crc.front() == '1'){
                flag = false;
            }
            crc.push_back(crc.front());
            crc.pop_front();
        }
        cout << endl;
        if(flag == false){
            cout << "All bits are not zero! Data Rejected!";
        }else{
            cout << "All bits are zero! Data Accepted!";
        }
    }
};
int main(){
    int n,m;
    cout << "Enter CRC Generator Size: ";
    cin >> n;
    cout << "Enter Number of data bits: ";
    cin >> m;
    CRC obj(n,m);
    obj.sender();
    obj.receiver();
    return 0;
}
