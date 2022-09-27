# Numerical Library of Mathematics Algorithm
## Overview 概况
这是一个C++实现的简单的数学库，集合了基础的矩阵运算、方程求解、 插值拟合、数值微积分、微分方程求解、画图等操作。
## Development Environment 开发环境
C++14 gcc9.2.0
## Usage 使用方法
本数学库采用header only模式（即所有的数学库都仅有.h格式的文件而没有.cpp格式的文件）。故使用时，只需要在源文件直接#include相应库即可。

上述所说的数学库中所有的.h格式的头文件在lib文件夹里。

如果使用gcc，请至少使用gcc 6.1版本。gcc下编译命令为
```
g++ -std=c++14 main.cpp
```
src文件夹里的各.cpp格式的源文件提供了用户如何调用数学库中各函数的示例，可供参考。也可参考doc文件夹里参考文档，但此为之前版本的参考文档，头文件名与命名空间均发生了变化，因此可能不再适用。

如果对性能有所要求，强烈建议编译时开启优化选项（例如，gcc下开起-Ofast优化；msvc下使用release模式）。
## Algorithms Used 所用算法
对于下面列出的各种功能，均使用多种算法予以实现，下面列出的算法只是其中一种算法（往往是相应功能调用时的默认算法）。

### 核心库 core.h 命名空间 cor
无文件依赖
* 提供基础支持

### 快速傅里叶变换库 FFT.h 命名空间 fft
依赖核心库
* 提供快速傅里叶变换及快速数论变换支持

### 数论库 numbertheory.h 命名空间 nbt
依赖快速傅里叶变换库
* 最大公因数 —— 辗转相除法
* 素数计数 —— 欧拉筛
* 素性测试 —— Miller-Rabin算法
* 找整数的一个因子 —— Polland-Rho算法

### 高精度库 highprecision.h 命名空间 hpc
依赖快速傅里叶变换库
* 大整数乘法 —— 快速数论变换
* 高精度除法 —— 牛顿迭代法

### 多项式库 polynomial.h 命名空间 ply
依赖快速傅里叶变换库
* 多项式乘法 —— 快速傅里叶变换
* 多项式求值 —— 秦九韶算法

### 线性代数库 linearalgebra.h 命名空间 lag
依赖核心库
* QR分解 —— 修正的Gram-Schmidt正交化
* 特征值 —— QR算法
* 线性方程组求解 —— LUP分解

### 数值库 numerical.h 命名空间 nmr
依赖多项式库与线性代数库
* 求导数 —— 中心差商法
* 代数方程(组)求解 —— 牛顿迭代法
* 插值 —— 分段线性插值
* 带导数插值 —— 分段两点三次埃尔米特插值
* 拟合 —— 最小二乘法
* 函数逼近 —— 最小二乘法
* 定积分 —— Romberg算法

### 常微分方程库 ODE.h 命名空间 ode
依赖数值库
* 常微分方程(组)求解 —— 预测-校正的Milne-Hamming公式

### 优化库 optimization.h 命名空间 opt
依赖线性代数库
* 无约束优化 —— BFGS方法
* 约束优化 —— 增广拉格朗日函数法

### 概率论库 probability.h 命名空间 prb
依赖数值库
* 提供随机变量及其分布的基础操作

### 绘图库 plot.h 命名空间 plt
依赖线性代数库
* 提供函数作图支持

### 总库 mathalgorithm.h 命名空间 mal
依赖上述所有头文件
* include上述所有数学库

## Change Log 更新日志
目前已发布的最新版本是v0.7.5，详见releases
* v0.7.5 修复大整数乘法的错误并加速，加入大整数除法、取模、平方根等操作，加入素数计数、素性测试、质因数分解等数论相关的内容，
加入众多无约束优化与约束优化算法，重组头文件

下述更早的历史版本详见旧仓库[numerical library](https://github.com/lambdacdm/numerical-library)的releases
* v0.7.4 删除多线程矩阵乘法，加入分治法LU分解，加入修正的Gram-Schmidt的QR分解，加入解线性方程组的QR分解法，
修改“改进的欧拉法”的调用名称
* v0.7.3 加入QR分解与求特征值
* v0.7.2 加入常微分方程组求解与代数方程组求解
* v0.7.1 首个发布的版本

当前正在进行的工作（重要）：
* 完善大整数质因数分解 （预计v0.8.0实现）
* 加入随机生成大整数 （预计v0.8.0实现）
* 加入随机生成服从正态分布的随机变量 （预计v0.8.0实现）
* 更改矩阵存储方式为一维数组 （预计v0.8.1实现）
* 完善图像绘制 （预计v0.8.1实现）
* 完善错误警告信息提示 （预计v0.8.1实现）

今后将要进行的工作：
* 加入SVD分解 （预计v0.8.2实现）
* 完善特征值、特征向量求解系统 （预计v0.8.2实现）
* 优化现有的QR分解算法 （预计v0.8.2实现）
* 完善求范数、求条件数等功能
* 完善最小二乘法求解系统
* 加入新的求解常微分方程（组）的方法

## License 许可声明
本仓库采用 GPL-3.0 license 许可。

一个例外是，本仓库中那些属于旧仓库[numerical library](https://github.com/lambdacdm/numerical-library)的代码部分不受任何许可要求。
