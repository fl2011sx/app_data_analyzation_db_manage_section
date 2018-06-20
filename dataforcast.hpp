#ifndef DATAFORCAST_H
#define DATAFORCAST_H

#include <vector>
#include <string>
#include <set>
#include <map>

namespace dataProcess {
    
    struct ConinuousDataForcastArgSet {
        double const1;
        double const2;
    };
    
    class ConinuousDataForcast {
    private:
        std::vector<double> data;
        void forcastData();
        void restoreData();
        // 处理后数据=(原始数据-const1)/const2
        double const1;
        double const2;
    public:
        ConinuousDataForcast(const std::vector<double> &data);
        ConinuousDataForcast(const std::vector<double> &data, const ConinuousDataForcastArgSet set);
        std::vector<double> getData();
        ConinuousDataForcastArgSet getArgSet();
        static std::vector<double> processData(const std::vector<double> &data, const ConinuousDataForcastArgSet set);
        static ConinuousDataForcastArgSet processData(std::vector<double> &data);
        static double pre_processData(const double data, const ConinuousDataForcastArgSet set);
        static double aft_processData(const double data, const ConinuousDataForcastArgSet set);
    };
    
    struct DisperseDataForcastArgSet {
        std::map<double, double> set_double;
        std::map<std::string, double> set_string;
        bool is_data_double; // 原始数据是否为doule，决定用哪个set
    };
    
    class DisperseDataForcast {
    private:
        std::vector<double> data_double;
        std::vector<std::string> data_str;
        
        std::map<double, double> set_double;
        std::map<std::string, double> set_string;
        bool isDataDouble;
        void forcastData_double();
        void forcastData_str();
        void restoreData_double();
        void restoreData_str();
    public:
        DisperseDataForcast(const std::vector<double> &data);
        DisperseDataForcast(const std::vector<std::string> &data);
        DisperseDataForcast(const std::vector<double> &data, const DisperseDataForcastArgSet set);
        std::vector<double> getData_double();
        std::vector<std::string> getData_string();
        DisperseDataForcastArgSet getArgSet();
    };
    
}
#endif // DATAFORCAST_H
