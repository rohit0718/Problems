#include <iostream>
#include <chrono>

using namespace std;

class Timer {
  public:
    Timer() {
      m_StartTimePoint = chrono::high_resolution_clock::now();
    }
    ~Timer() {
      Stop();
    }

    void Stop() {
      auto endTimepoint = chrono::high_resolution_clock::now();

      auto start = std::chrono::time_point_cast<chrono::microseconds>(m_StartTimePoint).time_since_epoch().count();
      auto end = std::chrono::time_point_cast<chrono::microseconds>(endTimepoint).time_since_epoch().count();

      auto duration = end - start;
      double ms = duration * 0.001;

      cout << "Total time taken: " << duration << " microseconds (" << ms << " milliseconds)\n";
    }

  private:
    chrono::time_point < chrono::high_resolution_clock > m_StartTimePoint;
};

int main() {

  int val = 0;

  {
    Timer timer;
    for (int i = 0; i < 10000000; ++i) val += 2;
  }

  cout << val << "\n";
}
