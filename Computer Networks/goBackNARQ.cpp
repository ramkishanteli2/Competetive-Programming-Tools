#include<iostream>

#include <time.h>

#include <queue>

#include <unistd.h>

#define timeOutTime 2
bool flag = false;
using namespace std;
int receive(int i, int & j, int & frameStart, int receiverSeq[], int startTime[]) {

  if(i == 3 and flag == false){
    sleep(3);
    flag = true;
  }

  if (i < j) {
    cout << "Frame " << i << " is duplicate!" << endl;
    return j;
  } else {
    if (time(NULL) - startTime[i] > timeOutTime) {
      cout << "Time out for Frame " << i << endl;
      i = frameStart;
      return -1;
    } else {
      cout << "Frame " << j << " is received!" << endl;
      j++;
      frameStart++;
      return j;
    }
  }
}
int main() {

  int n;
  cout << "Enter number of frames: " << endl;
  cin >> n;
  int wSize;
  cout << "Enter window size: " << endl;
  cin >> wSize;

  int senderSeq[n];
  int receiverSeq[n];

  for (int i = 0; i < n; i++) {
    senderSeq[i] = i;
    receiverSeq[i] = i;
  }
  int noOfTransmission = 0;
  int i = 0, j = 0, frameStart = 0;
  queue < int > sentFrames;
  queue < int > receivedFrames;
  int startTime[n];
  while (i < n) {
    if ((i != n - 1) and sentFrames.size() < wSize) {
      noOfTransmission++;
      sentFrames.push(i);
      i++;
    } else {
      if (i == n - 1) {
        noOfTransmission++;
        sentFrames.push(i);
        i++;
      }
      while (!sentFrames.empty()) {
        startTime[sentFrames.front()] = time(NULL);
        cout << "Frame " << sentFrames.front() << " has been sent!" << endl;
        receivedFrames.push(sentFrames.front());
        sentFrames.pop();
      }
      while (!receivedFrames.empty()) {

        int ack = receive(receivedFrames.front(), j, frameStart, receiverSeq, startTime);
        if (ack == -1) {
          while (!receivedFrames.empty()) {
            receivedFrames.pop();
          }
          i = frameStart;
          break;
        }
        cout << "Acknowledge for frame " << ack << " has been received!" << endl;
        receivedFrames.pop();
      }
    }
  }
  cout << endl << "Total number of Transmission is: " <<noOfTransmission;

}
