/*
    https://www.nowcoder.com/pat/5/problem/4319
    思路:
        1.时间序列转换,按升序排列
        2.如何计算每时刻的车数,不要做累加,不然不便于统计，直接在零基础上加减,这样后续统计只有遍历一次数组
*/

#include <algorithm>
#include <iomanip>
#include <iostream>
#include <map>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

struct Record {
    string plate;
    int time;
    string status;
};

struct Car {
    int totalTime;
    int lastInTime;
    bool isIn;
    Car()
        : totalTime(0), lastInTime(-1), isIn(false) {}
};

int timeToSeconds(const string& time) {
    int hh, mm, ss;
    sscanf(time.c_str(), "%d:%d:%d", &hh, &mm, &ss);
    return hh * 3600 + mm * 60 + ss;
}

string secondsToTime(int seconds) {
    int hh = seconds / 3600;
    int mm = (seconds % 3600) / 60;
    int ss = seconds % 60;
    char buffer[9];
    sprintf(buffer, "%02d:%02d:%02d", hh, mm, ss);
    return string(buffer);
}

int main() {
    int N, K;
    cin >> N >> K;

    vector<Record> records(N);
    unordered_map<string, Car> cars;  // 车牌号对应的汽车
    map<int, int> events;             // events[time] = 对应时间的车数

    for (int i = 0; i < N; ++i) {
        string plate, time, status;
        cin >> plate >> time >> status;
        records[i] = {plate, timeToSeconds(time), status};
    }

    // 按时间排序
    sort(records.begin(), records.end(), [](const Record& a, const Record& b) {
        return a.time < b.time;
    });

    for (const auto& record : records) {
        Car& car = cars[record.plate];
        if (record.status == "in") {
            if (car.isIn) {
                // 进入校园事件按最后时间算,不做处理
            }
            // 更新进入时间
            car.lastInTime = record.time;
            car.isIn = true;
        } else {
            if (!car.isIn) {
                continue;  // 汽车还没进入校园,out忽略
            }
            int parkedTime = record.time - car.lastInTime;
            car.totalTime += parkedTime;
            car.isIn = false;
            // 更新时间数组
            events[car.lastInTime]++;
            // 出去时间车数--
            events[record.time]--;
        }
    }

    vector<int> queryTimes(K);
    for (int i = 0; i < K; ++i) {
        string time;
        cin >> time;
        queryTimes[i] = timeToSeconds(time);
    }

    vector<int> results(K);

    for (int i = 0; i < K; ++i) {
        int currentCars = 0;
        auto eventIter = events.begin();
        while (eventIter != events.end() && eventIter->first <= queryTimes[i]) {
            currentCars += eventIter->second;
            ++eventIter;
        }
        results[i] = currentCars;
    }

    for (const auto& result : results) {
        cout << result << endl;
    }

    vector<pair<string, int>> parkedTimes;
    int maxTime = 0;

    for (const auto& car : cars) {
        if (car.second.totalTime > 0) {
            parkedTimes.push_back({car.first, car.second.totalTime});
            maxTime = max(maxTime, car.second.totalTime);
        }
    }

    vector<string> longestParkedCars;
    for (const auto& car : parkedTimes) {
        if (car.second == maxTime) {
            longestParkedCars.push_back(car.first);
        }
    }

    sort(longestParkedCars.begin(), longestParkedCars.end());
    for (const auto& plate : longestParkedCars) {
        cout << plate << " ";
    }

    cout << secondsToTime(maxTime) << endl;
    return 0;
}
