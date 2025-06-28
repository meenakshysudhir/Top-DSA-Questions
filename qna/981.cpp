#include <everything.h>
using namespace std;
class TimeMap {
public:
  //   unordered_map<string, map<int, string>> timeMap;
  //   TimeMap() {}
  //
  //   void set(string key, string value, int timestamp) {
  //     timeMap[key][timestamp] = value;
  //   }
  //
  //   string get(string key, int timestamp) {
  //     if (timeMap.find(key) == timeMap.end()) {
  //       return "";
  //     }
  //     int seen = 0;
  //     for (const auto [time, _] : timeMap[key]) {
  //       if (time <= timestamp) {
  //         seen = max(seen, time);
  //       }
  //     }
  //     return seen == 0 ? "" : timeMap[key][seen];
  //   }
  // };

  unordered_map<string, map<int, string>> timeMap;
  TimeMap() {}

  void set(string key, string value, int timestamp) {
    timeMap[key][timestamp] = value;
  }

  string get(string key, int timestamp) {

    auto it = timeMap[key].upper_bound(timestamp);
    return it == timeMap.begin() : "" : prev(it)->second;
  }
};
int main(void) {
  Solution obj;
  vector<string> inp1 = {"TimeMap", "set", "get", "get", "set", "get", "get"};
  vector<vector<string>> inp2 = {{},         {"foo", "bar", 1},  {"foo", 1},
                                 {"foo", 3}, {"foo", "bar2", 4}, {"foo", 4},
                                 {"foo", 5}};
}
