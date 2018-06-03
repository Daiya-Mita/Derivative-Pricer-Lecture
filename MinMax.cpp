#include "MinMax.hpp"
 
//  最大値を返す
int MinMax::max(int n1,int n2){
    if (n1 > n2){
        return n1;
    }
    return n2;
}
//  最小値を返す
int MinMax::min(int n1,int n2){
    return -max(-n1, -n2);
}