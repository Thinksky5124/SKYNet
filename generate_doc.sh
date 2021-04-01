###
 # @Author: Thyssen Wen
 # @Date: 2021-03-10 23:05:30
 # @LastEditors: Thyssen Wen
 # @LastEditTime: 2021-03-14 18:34:34
 # @Description: 生成doxygen脚本
 # @FilePath: /SKYNet/generate_doc.sh
### 

# 安装doxygen
# sudo apt-get install doxygen

# 使用Doxygen命令生成配置模板文件
# doxygen -g doc.dot

# 生成html文档
doxygen doxygen.dot
