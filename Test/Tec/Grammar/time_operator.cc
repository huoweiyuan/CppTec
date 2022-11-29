#include <chrono>
#include <iostream>
using namespace std;
using namespace std::chrono;


int main()
{
  cout << duration_cast<milliseconds>(high_resolution_clock::now().time_since_epoch()).count() << endl;
  return 0;
}
