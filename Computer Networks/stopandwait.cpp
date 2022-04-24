#include <iostream>
#include <vector>
#include <ctime>
#include <time.h>
using namespace std;
#define timeOut 2
int receive(int &j, int sf, int rec_s[])
{
    if (sf == rec_s[j] && rand() % 2)
    {
        j++;
        cout << "Frame" << sf << " is received" << endl;
        cout << "Acknowledgement received" << endl;
        return 1;
    }
    else
    {
        cout << "late acknowledgement received " << endl;
        cout << "Frame " << sf << " is duplicate!" << endl;
        return 0;
    }
}
void send(int &i, int &j, int sen_s[], int rec_s[], int n)
{
    int stime, etime;
    stime = time(NULL); // start the timmer
    cout << "frame " << sen_s[i] << " is sent" << endl;
    if (rand() % 2)
        for (int i = 0; i < 1000000; i++)
            for (int j = 0; j < 10000; j++) // forcreating delay
                etime = time(NULL);         // timeout time
    int totalTime = (stime - etime) / CLOCKS_PER_SEC;
    // cout << totalTime << " ";

    if (totalTime <= timeOut)
    {
        int ack = receive(j, sen_s[i], rec_s);
        if (ack && j < n)
            cout << "Acknowledgement for " << rec_s[j] << " is Received " << endl;
        i++;
    }
    else
    {
        cout << "Time out!"
             << "Resending frame " << sen_s[i] << endl;
    }
}

int main()
{
    int n;
    cout << "please enter the number of frames to be sent: ";
    cin >> n;
    int sen_s[n];
    int rec_s[n];
    bool f = false;
    for (int i = 0; i < n; i++)
    {
        sen_s[i] = f;
        rec_s[i] = f;
        f = !f;
    }
    // cout << sen_s.size() << " " << rec_s.size();
    int i = 0, j = 0;
    while (i < n)
    {
        cout << i << "th frame in progress " << endl;
        send(i, j, sen_s, rec_s, n);
    }
    return 0;
}
