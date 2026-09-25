#include <iostream>
#include <iomanip>
#include <cmath>

#include "work.h"

using namespace std;

int main()
{
    // 输入三维点坐标
    double pw[3];
    cout << "请输入三维点坐标 x y z" << endl;
    cin >> pw[0] >> pw[1] >> pw[2];


    // 输入平移向量
    double t[3];
    cout << "请输入平移向量 tx ty tz" << endl;
    cin >> t[0] >> t[1] >> t[2];


    // 输入相机内参
    double fx, fy, cx, cy;
    cout << "请输入相机内参 fx fy cx cy" << endl;
    cin >> fx >> fy >> cx >> cy;


    // 输入旋转矩阵
    double r[3][3];
    cout << "请输入3x3旋转矩阵R（每行3个数字）"<< endl;
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            cin >> r[i][j];
        }
    }


    // 输入实际观测点
    double uo, vo;
    cout << "请输入实际观测点像素坐标 uo vo"<< endl;
    cin >> uo >> vo;

    //设置结果变量初始值
    double pc[3] = {0.0, 0.0, 0.0};
    double u = 0.0;
    double v = 0.0;
    double error = 0.0;

    bool ok = work(
        pw,
        r,
        t,

        fx,
        fy,
        cx,
        cy,

        uo,
        vo,

        pc,
        u,
        v,
        error
    );

    if(!ok)    //此时函数返回false
    {
        cerr << "计算失败：深度非正！"<< endl;

        return 1;
    }

    // 输出计算结果

    cout << fixed << setprecision(4);


    cout << "二维像素坐标为：("<< u << ", "<< v << ")" << endl;

    cout << "重投影误差 = "<< error << " 像素" << endl;

    return 0;
}


