#include <iostream>
#include <time.h>
#include <unistd.h>
#include <queue>
#include <unordered_set>
#define timeOutTime 2
using namespace std;
int flag = 1;
void receive(int j,int receiverFrameSeq[],queue<int>&ack){
   if(receiverFrameSeq[j] == true){
       cout << "Frame " << j << " is duplicate!" << endl;
       ack.push(j);
   }else{
       receiverFrameSeq[j] = 1;
       cout << "Frame " << j << " is received!" << endl;
       ack.push(j);
   }
   if(j == 3 and flag){
       sleep(3);
       flag = 0;
   }
}
void send(int i,int senderFrameSeq[],int receiverFrameSeq[],queue<int>&receiver,unordered_set<int>&sentNotAck){
    senderFrameSeq[i] = 0;
    sentNotAck.insert(i);
    receiver.push(i);
    cout << "Frame " << i << " is sent!" << endl;
}
int main(){
    int n;
    int wSize;
    cout << "Enter number of frames to be transmitted: \n";
    cin >> n;
    cout << "Enter window size: \n";
    cin >> wSize;
    int senderFrameSeq[n];
    int receiverFrameSeq[n];
    int sentTime[n];

    for(int i = 0;i < n; i++){
        senderFrameSeq[i] = -1;
        receiverFrameSeq[i] = -1;
    }

    int i = 0,j = 0;
    queue<int>sender;
    queue<int>receiver;
    unordered_set<int>sentNotAck;
    queue<int>ack;
    int cnt = 0;
    while(i < n or !sender.empty()){
        if(cnt < wSize and i < n){
            sender.push(i);
            i++;
            cnt++;
        }
        else{
            while(!sender.empty()){
                sentTime[i] = time(NULL);
                send(sender.front(),senderFrameSeq,receiverFrameSeq,receiver,sentNotAck);
                sender.pop();
            }
            vector<int>temp;
            for(auto &item:sentNotAck){
                if(time(NULL)-sentTime[i] > timeOutTime){
                    cout << "Time out for frame " << item << "!";
                    temp.push_back(item);
                    sender.push(item);
                    senderFrameSeq[item] = -1;
                    cnt--;
                }
            }
            while(!temp.empty()){
                sentNotAck.erase(temp.back());
                temp.pop_back();
            }

            while(!receiver.empty()){
                receive(receiver.front(),receiverFrameSeq,ack);
                receiver.pop();
            }

            while(!ack.empty()){
                int item = ack.front();
                ack.pop();
                if(time(NULL)-sentTime[i] > timeOutTime){
                    cout << "Time out for frame " << item << "!\n";
                    temp.push_back(item);
                    sender.push(item);
                    senderFrameSeq[item] = -1;
                }else{
                    senderFrameSeq[item] = 1;
                    sentNotAck.erase(item);
                    cout << "Frame " << item << " is successfully acknowledged!\n";
                }
                cnt--;
            }

        }
    }
}
