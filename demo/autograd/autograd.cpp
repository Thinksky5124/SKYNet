/*
 * @Author: Thyssen Wen
 * @Date: 2021-03-18 22:46:09
 * @LastEditors: Thyssen Wen
 * @LastEditTime: 2021-03-23 22:07:43
 * @Description: 测试自动微分功能
 * @FilePath: /SKYNet/demo/autograd/autograd.cpp
 */
#include "baseOption.h"
#include "iostream"
#include "vector"
#include <armadillo>

int main(){
    static const double PI = 3.1415926;
    
    Eigen::ArrayXXf a = Eigen::ArrayXXf::Zero(1,1);
    a << PI;
    Eigen::ArrayXXf da = Eigen::ArrayXXf::Zero(1,1);
    da << 1;
    Eigen::ArrayXXf b = Eigen::ArrayXXf::Zero(1,1);
    a << 2;
    Eigen::ArrayXXf db = Eigen::ArrayXXf::Zero(1,1);
    da << 0;
    Eigen::ArrayXXf c = Eigen::ArrayXXf::Zero(1,1);
    a << 1;
    Eigen::ArrayXXf dc = Eigen::ArrayXXf::Zero(1,1);
    da << 0;

    std::vector<SKYImage::baseOption> x;
    x.emplace_back(a,da);
    x.emplace_back(b,db);
    x.emplace_back(c,dc);

    SKYImage::baseOption y1 = cos(x[0]);
    SKYImage::baseOption y2 = sin(x[0]);
    SKYImage::baseOption y3 = x[1]*y1;
    SKYImage::baseOption y4 = x[2]*y2;
    SKYImage::baseOption y5 = x[1]*y2;
    SKYImage::baseOption y6 = x[2]*y1;

    SKYImage::baseOption z1 = y3 + y4;
    SKYImage::baseOption z2 = y6 - y5;

    std::cout << "x = [" << std::endl << x[0].value << "," << x[1].value << ","
        << x[2].value << "]" << std::endl;
    std::cout << "z = [" << z1.value << "," << z2.value << "]" << std::endl;
    std::cout << "[dz1/dx0, dz2/dx0] = [" << z1.dvalue << "," << z2.dvalue << "]" << std::endl;
    
    
}