#include "dataforcast.hpp"
#include <algorithm>

using dataProcess::ConinuousDataForcast;

ConinuousDataForcast::ConinuousDataForcast(const std::vector<double> &data): data(data), const1(0), const2(1) {
    forcastData();
}

ConinuousDataForcast::ConinuousDataForcast(const std::vector<double> &data, const ConinuousDataForcastArgSet set): data(data), const1(set.const1), const2(set.const2) {
    restoreData();
}

void ConinuousDataForcast::forcastData() {
    // 找出数据中最小值和最大值
    double max = *std::max_element(data.begin(), data.end());
    double min = *std::min_element(data.begin(), data.end());
    // 计算常数1
    // const1 = min
    const1 = min;
    // 计算常数2
    // const2 = max - min
    const2 = max - min;
    // 处理数据
    // newdata = (data-const1)/const2
    for (std::vector<double>::iterator iter = data.begin(); iter != data.end(); iter++) {
        *iter -= const1;
        *iter /= const2;
    }
}

void ConinuousDataForcast::restoreData() {
    for (std::vector<double>::iterator iter = data.begin(); iter != data.end(); iter++) {
        *iter *= const2;
        *iter += const1;
    }
}

std::vector<double> ConinuousDataForcast::getData() {
    return data;
}

dataProcess::ConinuousDataForcastArgSet ConinuousDataForcast::getArgSet() {
    ConinuousDataForcastArgSet set;
    set.const1 = const1;
    set.const2 = const2;
    return set;
}

using dataProcess::DisperseDataForcast;
DisperseDataForcast::DisperseDataForcast(const std::vector<double> &data): data_double(data), isDataDouble(true) {
    forcastData_double();
}

DisperseDataForcast::DisperseDataForcast(const std::vector<std::string> &data):data_str(data), isDataDouble(false) {
    forcastData_str();
}

DisperseDataForcast::DisperseDataForcast(const std::vector<double> &data, const DisperseDataForcastArgSet set): data_double(data), set_double(set.set_double), set_string(set.set_string), isDataDouble(set.is_data_double) {
    if (set.is_data_double) {
        restoreData_double();
    } else {
        restoreData_str();
    }
}

void DisperseDataForcast::forcastData_double() {
    for (std::vector<double>::const_iterator iter = data_double.begin(); iter != data_double.end(); iter++) {
        set_double[*iter] = 0;
    }
    // 暂不考虑单值数据或无数据
    if (set_double.size() <= 1) {return;}
    double base = 1.0 / (set_double.size() - 1);
    double i = 0;
    for (std::map<double, double>::iterator iter = set_double.begin(); iter != set_double.end(); iter++) {
        iter -> second = i;
        i += base;
    }
    for (std::vector<double>::iterator iter = data_double.begin(); iter != data_double.end(); iter++) {
        *iter = set_double[*iter];
    }
}
void DisperseDataForcast::forcastData_str() {
    for (std::vector<std::string>::const_iterator iter = data_str.begin(); iter != data_str.end(); iter++) {
        set_string[*iter] = 0;
    }
    if (set_string.size() <= 1) {return;}
    double base = 1.0 / (set_string.size() - 1);
    double i = 0;
    for (std::map<std::string, double>::iterator iter = set_string.begin(); iter != set_string.end(); iter++) {
        iter -> second = i;
        i += base;
    }
    for (std::vector<std::string>::iterator iter = data_str.begin(); iter != data_str.end(); iter++) {
        data_double.push_back(set_string[*iter]);
    }
}

void DisperseDataForcast::restoreData_double() {
    std::map<double, double> res_set;
    for (std::map<double, double>::const_iterator iter = set_double.begin(); iter != set_double.end(); iter++) {
        res_set[iter -> second] = iter -> first;
    }
    for (std::vector<double>::iterator iter = data_double.begin(); iter != data_double.end(); iter++) {
        *iter = res_set[*iter];
    }
}
void DisperseDataForcast::restoreData_str() {
    std::map<double, std::string> res_set;
    for (std::map<std::string, double>::const_iterator iter = set_string.begin(); iter != set_string.end(); iter++) {
        res_set[iter -> second] = iter -> first;
    }
    double base = 1.0 / (data_double.size() - 1);
    double *block = new double[data_double.size()];
    for (unsigned i = 0; i < data_double.size(); i++) {
        block[i] = base / 2 + i * base;
    }
    for (std::vector<double>::const_iterator iter = data_double.begin(); iter != data_double.end(); iter++) {
        double val = *iter;
        for (unsigned i = 0; i < data_double.size(); i++) {
            if (val < block[i]) {
                data_str.push_back(res_set[block[i] - base / 2]);
                break;
            }
        }
    }
    delete [] block;
}

std::vector<double> DisperseDataForcast::getData_double() {
    return data_double;
}
std::vector<std::string> DisperseDataForcast::getData_string() {
    return data_str;
}

dataProcess::DisperseDataForcastArgSet DisperseDataForcast::getArgSet() {
    DisperseDataForcastArgSet set;
    set.set_double = set_double;
    set.set_string = set_string;
    set.is_data_double = isDataDouble;
    return set;
}

