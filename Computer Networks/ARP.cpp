#include <iostream>

#include <vector>

using namespace std;
string findMAC(string & ipToMAC, vector < pair < string, string >> & network) {
  for (auto & item: network) {
    if (item.first == ipToMAC) {
      return item.second;
    }
  }
  return "";
}
int main() {
  int n;
  cout << "Enter number of nodes in the network: ";
  cin >> n;

  vector < pair < string, string >> network(n);

  for (int i = 0; i < n; i++) {
    string ip, mac;
    cout << "Enter IP and MAC address for " << i << "th nodes: ";
    cin >> ip >> mac;
    network[i] = {ip,mac};
  }

  cout << "Enter the IP address to search corresponding MAC address: ";
  string ipToMAC;
  cin >> ipToMAC;
  string MACAddress = findMAC(ipToMAC, network);

  if (MACAddress == "") {
    cout << ipToMAC << " does not exists in the network!" << endl;
  } else {
    cout << "Corresponding MAC Address is : " << MACAddress << endl;
  }
}
