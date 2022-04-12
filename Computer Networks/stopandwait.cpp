#include <iostream>
#include <time.h>
#define timeOutTime 2
using namespace std;
int receive(int &j,int expectedFrame,int receiverFrameSeq[]){
    if(expectedFrame == receiverFrameSeq[j]){
        j++;
        cout << "Frame " << expectedFrame << " is Received!" << endl;
        return !expectedFrame;
    }else{
        cout << "Frame " << expectedFrame << " is Duplicate!" << endl;
        return expectedFrame;
    }
}
void send(int &i,int &j,int senderFrameSeq[],int receiverFrameSeq[]){
    int startTime = time(NULL);
    cout << "Frame " << senderFrameSeq[i] << " is sent!" << endl;
    int ack = receive(j,senderFrameSeq[i],receiverFrameSeq);
    int endTime = time(NULL);
    int timeTaken = endTime - startTime;
    if(timeTaken <= timeOutTime){
        cout << "Acknowledgement for " << !senderFrameSeq[i] << " is received!" << endl;
        i++;
    }else{
        cout << "Time Out!" << endl;
    }
}

int main(){
    int n;
    cout << "Enter number of frames to be transmitted: ";
    cin >> n;
    int senderFrameSeq[n];
    int receiverFrameSeq[n];
    bool temp = false;
    for(int i = 0;i < n; i++){
        senderFrameSeq[i] = temp;
        receiverFrameSeq[i] = temp;
        temp = !temp;
    }
    int i = 0,j = 0;

    while(i < n){
        cout << i << "th frame in progress: "<< endl;
        send(i,j,senderFrameSeq,receiverFrameSeq);
    }

}
