/***************************
@Author: Chunel
@Contact: chunel@foxmail.com
@File: MyConnParam.h
@Time: 2021/10/4 11:58 上午
@Desc: 
***************************/

#ifndef CGRAPH_MYCONNPARAM_H
#define CGRAPH_MYCONNPARAM_H

#include "../../src/CGraph.h"

struct MyConnParam : public GAspectParam {
    /**
     * 必须实现 clone 函数，将外部参数，转入切面内部
     * @param param
     */
    void clone(GAspectParamPtr param) override {
        if (nullptr == param) {
            return;    // 异常判断，理论不可能出现此情况
        }

        auto* ptr = dynamic_cast<MyConnParam *>(param);    // 将传入的参数进行强转，并且赋值到本地
        ip = ptr->ip;
        port = ptr->port;
    }

    std::string ip {"0.0.0.0" };
    short port { 0 };
};

#endif //CGRAPH_MYCONNPARAM_H
