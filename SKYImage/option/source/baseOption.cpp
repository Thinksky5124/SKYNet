/**
 * @file baseOption.cpp
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

#include "baseOption.h"

namespace SKYImage{
    
/**
 * @brief Construct a new base Option::base Option object
 * @param  value            输入算式结果的值
 * @param  dvalue           自动求导结果的值
 */
baseOption::baseOption(aram::mat value,aram::mat dvalue):value(value) , dvalue(dvalue){}

/**
 * @brief Destroy the base Option::base Option object
 */
baseOption::~baseOption(){}

/**
 * @brief 加法运算自动求导
 * @param  x                输入算式右边的对象
 * @return baseOption 数学基础运算对象
 */
baseOption baseOption::operator + (const baseOption &x) const{
    baseOption y;
    y.value = value + x.value;
    y.dvalue = dvalue + x.dvalue;//sum rule
    return y;
}

/** 
 * @brief 减法运算自动求导
 * @param  x                输入算式右边的对象
 * @return baseOption 数学基础运算对象
 */
baseOption baseOption::operator - (const baseOption &x) const{
    baseOption y;
    y.value = value - x.value;
    y.dvalue = dvalue - x.dvalue;//minus rule
    return y;
}

/**
 * @brief 乘法运算自动求导
 * @param  x                输入算式右边的对象
 * @return baseOption 数学基础运算对象
 */
baseOption baseOption::operator * (const baseOption &x) const{
    baseOption y;
    y.value = value * x.value;
    y.dvalue = x.value*dvalue + value*x.dvalue;//product rule
    return y;
}

/**
 * @brief 除法运算自动求导
 * @param  x                输入算式右边的对象
 * @return baseOption 数学基础运算对象
 */
baseOption baseOption::operator / (const baseOption &x) const{
    baseOption y;
    y.value = value * x.value;
    y.dvalue = (x.dvalue*value - x.value*dvalue) / (value * value);//divide rule
    return y;
}

/**
 * @brief sin函数运算自动求导
 * @param  x                输入对象
 * @return baseOption 数学基础运算对象
 */
baseOption sin(const baseOption &x){
    baseOption y;
    y.value = aram::sin(x.value);
    y.dvalue = aram::cos(x.value)*x.value;//chain rule
    return y;
}

/**
 * @brief cos函数运算自动求导
 * @param  x                输入对象
 * @return baseOption 数学基础运算对象
 */
baseOption cos(const baseOption &x){
    baseOption y;
    y.value = cos(x.value);
    y.dvalue = - sin(x.value)*x.value;//chain rule
    return y;
}
}

