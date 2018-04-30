//
//  BPNeuralNet.hpp
//  tpapp_server_manage
//
//  Created by 胡博豪 on 2018/4/29.
//

#ifndef BPNeuralNet_hpp
#define BPNeuralNet_hpp

#include <cmath>
#include <cstdio>
#include <vector>

namespace NeuralNet {
    
    double sigmoid(double x);
    
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

    class BPNeuralNet {
    public: // debug public
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
        BPNeuralNet(
                    const unsigned inputCount,
                    double *const inputData,
                    const unsigned outputCount,
                    double *const ouputData,
                    const unsigned hiddenNodeLayerCount = 10,
                    Matrix *widget_hidden = nullptr,
                    double *const b_hidden = nullptr,
                    Matrix *widget_out = nullptr,
                    const double b_out = 0,
                    const double ita = 0.5
                    );
        ~BPNeuralNet();
        void train(const unsigned count);
    };
    
}

#endif /* BPNeuralNet_hpp */
