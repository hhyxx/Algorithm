
// 将浮点数映射成-1，0，1的符号
int dblcmp(double d){
    if(fabs(d) < eps)
        return 0;
    return (d > 0)?1:-1;
}


