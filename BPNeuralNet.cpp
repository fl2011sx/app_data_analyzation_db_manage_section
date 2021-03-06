//
//  basic_BPNeuralNet.cpp
//  tpapp_server_manage
//
//  Created by 胡博豪 on 2018/4/29.
//

#include "BPNeuralNet.hpp"
#include <ctime>
#include "dataforcast.hpp"

using NeuralNet::Matrix;

double NeuralNet::sigmoid(double x) {
    return 1 / (1 + std::exp(-x));
}

Matrix::Matrix(const int x, const int y): x(x), y(y) {
    std::srand(std::time(nullptr));
    data = new double *[x];
    for (int i = 0; i < x; i++) {
        data[i] = new double[y];
        for (int j = 0; j < y; j++) {
            // 生成-1到1之间的随机数
            double rand = (std::rand() % 20000000 - 10000000) / 10000000.0;
            data[i][j] = rand;
        }
    }
}

Matrix::Matrix(const int x, const int y, void *arr): Matrix(x, y) {
    for (int i = 0; i < x; i++) {
        for (int j = 0; j < y; j++) {
            data[i][j] = *((double *)arr + i * y + j);
        }
    }
}

void Matrix::show() const {
    printf(" ");
    for (int i = 0; i < y; i++) {
        printf("%9d", i);
    }
    printf("\n");
    for (int i = 0; i < x; i++) {
        printf("%2d ", i);
        for (int j = 0; j < y; j++) {
            printf("%8.7lf ", data[i][j]);
        }
        printf("\n");
    }
}

double *Matrix::operator [](unsigned i) {
    return data[i];
}

using NeuralNet::basic_BPNeuralNet;

basic_BPNeuralNet::basic_BPNeuralNet(
                         const unsigned inputCount,
                         double *const inputData,
                         const unsigned outputCount,
                         double *const ouputData,
                         const unsigned hiddenNodeLayerCount,
                         Matrix *widget_hidden,
                         double *const b_hidden,
                         Matrix *widget_out,
                         const double b_out,
                         const double ita
                         )
:inputNode(new double[inputCount]),
outputNode(new double[outputCount]),
hiddenNode(new double *[hiddenNodeLayerCount]),
inputData(new double[inputCount]),
outputData(new double[outputCount]),
inputCount(inputCount),
outputCount(outputCount),
hiddenNodeLayerCount(hiddenNodeLayerCount),
widget_hidden((Matrix *)operator new(sizeof(Matrix) * hiddenNodeLayerCount)),
widget_out(widget_out ? *widget_out : Matrix(inputCount, outputCount)),
b_hidden(new double[hiddenNodeLayerCount]),
b_out(b_out),
ita(ita),
delta_out(new double[outputCount]),
delta_hidden(new double *[hiddenNodeLayerCount])
{
    if (inputData) {
        for (unsigned i = 0; i < inputCount; i++) {
            this -> inputData[i] = inputData[i];
        }
    }
    if (ouputData) {
        for (unsigned i = 0; i < outputCount; i++) {
            this -> outputData[i] = ouputData[i];
        }
    }
    for (unsigned i = 0; i < hiddenNodeLayerCount; i++) {
        this -> hiddenNode[i] = new double[inputCount];
    }
    
    if (!b_hidden) {
        for (unsigned i = 0; i < hiddenNodeLayerCount; i++) {
            this -> b_hidden[i] = 0;
        }
    } else {
        for (unsigned i = 0; i < hiddenNodeLayerCount; i++) {
            this -> b_hidden[i] = b_hidden[i];
        }
    }
    
    // 初始化隐藏层权重矩阵
    if (!widget_hidden) {
        for (unsigned i = 0; i < hiddenNodeLayerCount; i++) {
            // 初始时所有权重都为随机数
            new (this -> widget_hidden + i) Matrix(inputCount, inputCount);
        }
    } else {
        for (unsigned i = 0; i < hiddenNodeLayerCount; i++) {
            new (this -> widget_hidden + i) Matrix(widget_hidden[i]);
        }
    }
    
    // 初始化隐藏层delta数组
    for (unsigned i = 0; i < hiddenNodeLayerCount; i++) {
        delta_hidden[i] = new double[inputCount];
    }
}

void basic_BPNeuralNet::calNode(const unsigned lay_num, const unsigned num) {
    double sum = 0;
    for (unsigned i = 0; i < inputCount; i++) {
        if (lay_num == 0) {
            // 首层节点的前层即为输入节点
            // net(h1) = ΣI(i)*w(i)
            sum += inputNode[i] * widget_hidden[0][i][num];
        } else {
            // 前一个节点的输出值为f(net值)
            // 这里的f取sigmoid
            // net(hk) = ΣO(hk-1)*w(i) = Σf(net(hk-1))*w(i)
            sum += sigmoid(hiddenNode[lay_num - 1][i]) * widget_hidden[lay_num][i][num];
        }
    }
    hiddenNode[lay_num][num] = sum + b_hidden[lay_num];
}

void basic_BPNeuralNet::calOutNode(const unsigned int num) {
    double sum = 0;
    for (unsigned i = 0; i < inputCount; i++) {
        sum += sigmoid(hiddenNode[hiddenNodeLayerCount - 1][i]) * widget_out[i][num];
    }
    outputNode[num] = sum + b_out;
}

double basic_BPNeuralNet::err_whole() {
    double sum = 0;
    for (unsigned i = 0; i < outputCount; i++) {
        sum += err_one(i);
    }
    return sum;
}

double basic_BPNeuralNet::err_one(const unsigned int num) {
    // outputData -> target
    // f(outputNode) -> out
    return 0.5 * std::pow(outputData[num] - sigmoid(outputNode[num]), 2);
}

void basic_BPNeuralNet::refreshWidgetOut() {
    for (unsigned i = 0; i < outputCount; i++) {
        claDeltaOut(i);
    }
    for (unsigned i = 0; i < inputCount; i++) {
        for (unsigned j = 0; j < outputCount; j++) {
            refershWidgetOut_one(i, j);
        }
    }
}

void basic_BPNeuralNet::refershWidgetOut_one(const unsigned prenum, const unsigned num) {
    // ∂E/∂w = (∂E/∂o) * (∂o/∂no) * (∂no/∂w) = δ * (∂no/∂w)
    // ∂no/∂w = op
    double rd_no_w = sigmoid(hiddenNode[hiddenNodeLayerCount - 1][prenum]);
    double rd_E_w = rd_no_w * delta_out[num];
    // w+ = w - η * (∂E/∂w)
    widget_out[prenum][num] -= ita * rd_E_w;
}

void basic_BPNeuralNet::claDeltaOut(const unsigned num) {
    // ∂E/∂o = -(tar - o)
    double rd_E_o = sigmoid(outputNode[num]) - outputData[num];
    // ∂o/∂no = f'(no) = sigmoid'(no) = o(1-o)
    double rd_o_no = sigmoid(outputNode[num]) * (1 - sigmoid(outputNode[num]));
    // δ = (∂E/∂o) * (∂o/∂no)
    double rd_E_no = rd_E_o * rd_o_no;
    delta_out[num] = rd_E_no;
}

void basic_BPNeuralNet::refreshWidgetHidden() {
    for (int i = hiddenNodeLayerCount - 1; i >= 0; i--) {
        for (unsigned j = 0; j < inputCount; j++) {
            calDeltaHidden(i, j);
        }
    }
    for (int l = hiddenNodeLayerCount - 1; l >= 0; l--) {
        for (unsigned i = 0; i < inputCount; i++) {
            for (unsigned j = 0; j < inputCount; j++) {
                refreshWidgetHidden_one(l, i, j);
            }
        }
    }
}

void basic_BPNeuralNet::refreshWidgetHidden_one(const unsigned int lay_num, const unsigned int pre_num, const unsigned int num) {
    // ∂E/∂w = δ * (∂no/∂w)
    // no = Σ(wi * np) + b
    // ∂no/∂w = np
    double rd_no_w = 0;
    if (lay_num != 0) {
        rd_no_w = sigmoid(hiddenNode[lay_num - 1][pre_num]);
    } else {
        rd_no_w = sigmoid(inputNode[pre_num]);
    }
    // ∂E/∂w = δ * (∂no/∂w)
    double rd_E_w = delta_hidden[lay_num][num] * rd_no_w;
    // w+ = w - η * (∂E/∂w)
    widget_hidden[lay_num][pre_num][num] -= ita * rd_E_w;
}

void basic_BPNeuralNet::calDeltaHidden(const unsigned int lay_num, const unsigned int num) {
    // δ = ∂E/∂o * ∂o/∂no
    // ∂E/∂o = Σ(∂Ei/∂o) = Σwaδa
    // 如果是最后一层
    double sigma_w_d = 0;
    if (lay_num == hiddenNodeLayerCount - 1) {
        double sum = 0;
        for (unsigned i = 0; i < inputCount; i++) {
            sum += widget_hidden[lay_num][num][i] * delta_out[i];
        }
        sigma_w_d = sum;
    } else { // 中间层
        double sum = 0;
        for (unsigned i = 0; i < inputCount; i++) {
            sum += widget_hidden[lay_num][num][i] * delta_hidden[lay_num + 1][i];
        }
        sigma_w_d = sum;
    }
    // ∂o/∂no = o·(1 - o)
    double rd_o_no = sigmoid(hiddenNode[lay_num][num]) * (1 - sigmoid(hiddenNode[lay_num][num]));
    // δ = ∂E/∂o * ∂o/∂no
    delta_hidden[lay_num][num] = sigma_w_d * rd_o_no;
}

void basic_BPNeuralNet::initInputNode() {
    // 初始化input节点
    for (unsigned i = 0; i < inputCount; i++) {
        inputNode[i] = inputData[i];
    }
}

void basic_BPNeuralNet::calHiddenNode() {
    // 隐藏层节点值的计算
    for (unsigned i = 0; i < hiddenNodeLayerCount; i++) {
        for (unsigned j = 0; j < inputCount; j++) {
            calNode(i, j); // 计算第i层第j个隐藏节点的值
        }
    }
}

void basic_BPNeuralNet::calOutputNode() {
    // 输出层节点值的计算
    for (unsigned i = 0; i < outputCount; i++) {
        calOutNode(i);
    }
}

void basic_BPNeuralNet::train_once() {
    // 初始化输入节点
    initInputNode();
    // 隐藏层节点值的计算
    calHiddenNode();
    // 输出层节点值的计算
    calOutputNode();
    // 输出节点权值更新
    refreshWidgetOut();
    // 隐藏节点权值更新
    refreshWidgetHidden();
}

void basic_BPNeuralNet::train(const unsigned int count) {
    for (unsigned i = 0; i < count; i++) {
        train_once();
    }
}

basic_BPNeuralNet::~basic_BPNeuralNet() {
    delete [] inputNode;
    delete [] outputNode;
    delete [] inputData;
    delete [] outputData;
    for (unsigned i = 0; i < hiddenNodeLayerCount; i++) {
        delete [] hiddenNode[i];
    }
    delete [] hiddenNode;
    
    for (unsigned i = 0; i < hiddenNodeLayerCount; i++) {
        widget_hidden[i].~Matrix();
    }
    operator delete(widget_hidden);
}

void basic_BPNeuralNet::setIOData(double *const input, double *const output) {
    for (unsigned i = 0; i < inputCount; i++) {
        inputData[i] = input[i];
    }
    for (unsigned i = 0; i < outputCount; i++) {
        outputData[i] = output[i];
    }
}

unsigned basic_BPNeuralNet::inputDataCount() const {
    return inputCount;
}

unsigned basic_BPNeuralNet::outputDataCount() const {
    return outputCount;
}

void basic_BPNeuralNet::forcastData(const double *const input, double *const ouput) {
    for (unsigned i = 0; i < inputCount; i++) {
        inputData[i] = input[i];
    }
    initInputNode();
    calHiddenNode();
    calOutputNode();
    for (unsigned i = 0; i < outputCount; i++) {
        ouput[i] = sigmoid(outputNode[i]);
    }
}

using NeuralNet::BPNeuralNet;

BPNeuralNet::BPNeuralNet(const unsigned inputCount, const unsigned outputCount, const unsigned hiddenNodeLayerCount): net(basic_BPNeuralNet(inputCount, nullptr, outputCount, nullptr, hiddenNodeLayerCount)), inputCount(inputCount), outputCount(outputCount) {
    
}

bool BPNeuralNet::addIOData(const std::vector<double> &inputData, const std::vector<double> &outputData) {
    if (inputData.size() != inputCount) {return false;}
    if (outputData.size() != outputCount) {return false;}
    for (std::vector<double>::const_iterator iter = inputData.begin(); iter != inputData.end(); iter++) {
        if (*iter < 0 || *iter > 1) {return false;}
    }
    for (std::vector<double>::const_iterator iter = outputData.begin(); iter != outputData.end(); iter++) {
        if (*iter < 0 || *iter > 1) {return false;}
    }
    data.insert(std::make_pair(inputData, outputData));
    return true;
}

bool BPNeuralNet::train(const unsigned int times) {
    if (data.empty()) {return false;}
    for (unsigned time = 0; time < times; time++) {
        for (std::map<std::vector<double>, std::vector<double>>::iterator iter = data.begin(); iter != data.end(); iter++) {
            double *inputdata = new double[inputCount];
            double *outputdata = new double[outputCount];
            for (unsigned i = 0; i < iter -> first.size(); i++) {
                inputdata[i] = iter -> first.at(i);
            }
            for (unsigned i = 0; i < iter -> second.size(); i++) {
                outputdata[i] = iter -> second.at(i);
            }
            net.setIOData(inputdata, outputdata);
            net.train(1);
            delete [] inputdata;
            delete [] outputdata;
        }
    }
    return true;
}

std::vector<double> BPNeuralNet::forecastData(const std::vector<double> &input) {
    double *ouputData = new double[outputCount];
    double *inputData = new double[inputCount];
    for (unsigned i = 0; i < input.size(); i++) {
        inputData[i] = input.at(i);
    }
    
    net.forcastData(inputData, ouputData);
    std::vector<double> ouput(ouputData, ouputData + outputCount);
    delete [] ouputData;
    delete [] inputData;
    return ouput;
}
