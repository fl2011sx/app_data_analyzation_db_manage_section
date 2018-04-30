//
//  BPNeuralNet.hpp
//  tpapp_server_manage
//
//  Created by 胡博豪 on 2018/4/29.
//

#ifndef basic_BPNeuralNet_hpp
#define basic_BPNeuralNet_hpp

#include <cmath>
#include <cstdio>
#include <vector>
#include <map>

namespace NeuralNet {
    double sigmoid(double x);
}

namespace NeuralNet {
    
    class Matrix {
    public:
        double **data;
        int x, y;
        // 默认成员是随机数
        Matrix(const int x, const int y);
        Matrix(const int x, const int y, void *arr);
        void show() const;
        double *operator [](unsigned i);
    };

    class basic_BPNeuralNet {
        double *inputNode;
        double *outputNode;
        double **hiddenNode;
        
        double *inputData;
        double *outputData;
        
        unsigned inputCount;
        unsigned outputCount;
        unsigned hiddenNodeLayerCount;
        
        // 隐藏层和之前节点连接的权重矩阵，行数代表前一层，列数代表本层
        Matrix *widget_hidden;
        // 输出层与最后一层隐藏层之间的权重矩阵
        Matrix widget_out;
        // 隐藏层的偏移值b
        double *b_hidden;
        // 输出层的偏移值b
        double b_out;
        // 学习速率η
        double ita;
        // 输出层的δ值
        double *delta_out;
        // 隐藏层的δ值
        double **delta_hidden;
        
    private: // 内部创建逻辑
        // 初始化input节点
        void initInputNode();
        // 隐藏节点值计算
        void calHiddenNode();
        // 输出节点值计算
        void calOutputNode();
        // 一次训练
        void train_once();
        // 计算隐藏层某一节点的值
        void calNode(const unsigned lay_num, const unsigned num);
        // 计算输出层某一节点的值
        void calOutNode(const unsigned num);
        // 计算总误差
        double err_whole();
        // 计算某个输出的误差
        double err_one(const unsigned num);
        // 输出层权值更新
        void refreshWidgetOut();
        // 某一个输出层权值更新
        void refershWidgetOut_one(const unsigned pre_num, const unsigned num);
        // 计算输出层的δ值
        void claDeltaOut(const unsigned num);
        // 隐藏层的权值更新
        void refreshWidgetHidden();
        // 某一个隐藏层权值更新
        void refreshWidgetHidden_one(const unsigned lay_num, const unsigned pre_num, const unsigned num);
        // 计算某一隐藏层的δ值
        void calDeltaHidden(const unsigned lay_num, const unsigned num);
    public:
        basic_BPNeuralNet(
                    const unsigned inputCount,
                    double *const inputData,
                    const unsigned outputCount,
                    double *const ouputData,
                    const unsigned hiddenNodeLayerCount = 5,
                    Matrix *widget_hidden = nullptr,
                    double *const b_hidden = nullptr,
                    Matrix *widget_out = nullptr,
                    const double b_out = 0,
                    const double ita = 0.5
                    );
        ~basic_BPNeuralNet();
        void train(const unsigned count);
        unsigned inputDataCount() const;
        unsigned outputDataCount() const;
        void setIOData(double *const input, double *const output);
        void forcastData(const double *const input, double *const ouput);
    };
}

namespace NeuralNet {
    //********************
    // 类名：BPNeuralNet
    // 所属命名空间：NeuralNet
    // 类介绍：用于建立一个BP人工神经网络
    class BPNeuralNet {
        basic_BPNeuralNet net;
        std::map<std::vector<double>, std::vector<double>> data;
        unsigned inputCount;
        unsigned outputCount;
        
    public:
        BPNeuralNet(
                    // 输入变量的个数
                    const unsigned inputCount,
                    // 输出变量的个数
                    const unsigned outputCount,
                    // 隐藏层的层数（隐藏层越多，所需要训练的次数就越多，相对地预测就会越准确，但速度就会越慢）
                    const unsigned hiddenNodeLayerCount = 5
                    );
        
        //********************
        // 函数名：addIOData
        // 函数作用：添加一组输入和输出
        // 参数个数：2
        // 参数1：一组输入数据，vector<double>类型，个数必须为当前对象构造时传入的输入变量个数，数据限定为[0,1]之间的实数
        // 参数2：参数1所对应的一组输出数据，vector<double>类型，个数必须为当前对象构造时传入的输出变量个数，数据限定为[0,1]之间的实数
        // 返回值：如果输入的数据有误（例如元素个数不符或数据超出范围）则会返回false，正常情况返回true
        bool addIOData(const std::vector<double> &inputData, const std::vector<double> &outputData);
        
        //********************
        // 函数名：train
        // 函数作用：在数据准备好后进行若干次训练
        // 参数个数：1
        // 参数1：需要训练的次数
        // 返回值：如果没有准备好输入和输出数据，测会返回false，正常情况返回true
        bool train(const unsigned times);
        
        //********************
        // 函数名：forecastData
        // 函数作用：预测一组数据
        // 参数个数：1
        // 参数1：待预测的数据，vector<double>类型，个数必须为当前对象构造时传入的输入变量个数，数据限定为[0,1]之间的实数
        // 返回值：返回预测后的数据，vector<double>类型，个数为当前对象构造时传入的输出变量个数
        std::vector<double> forecastData(const std::vector<double> &input);
    };
    
}

#endif /* basic_BPNeuralNet_hpp */
