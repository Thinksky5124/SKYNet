/**
 * @file baseOption.h
 * @brief 
 * @author Thinksky5124 (Thinksky5124@outlook.com)
 * @version 1.0
 * @date 2021-03-18
 * 
 * @copyright Copyright (c) {2020}  
 * 
 * @par 修改日志:
 * <table>
 * <tr><th>Date       <th>Version <th>Author  <th>Description
 * <tr><td>2021-03-18 <td>1.0     <td>Thyssen Wen     <td>第一次创建
 * </table>
 */

#ifndef BASEOPTION_H
#define BASEOPTION_H

#include <armadillo>

namespace SKYImage
{
    class baseOption
    {
    private:

    public:
        baseOption(arma::mat value ,arma::mat dvalue );
        ~baseOption();

        // overload option for autograd
        baseOption operator + (const baseOption &x) const;
        baseOption operator - (const baseOption &x) const;
        baseOption operator * (const baseOption &x) const;
        baseOption operator / (const baseOption &x) const;
        friend baseOption sin(const baseOption &x);
        friend baseOption cos(const baseOption &x);
        arma::mat value;
        arma::mat dvalue;
    };
}


#endif