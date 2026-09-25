
#include "work.h"
#include <cmath>

using namespace std;

bool work(
    const double pw[3],
    const double r[3][3],
    const double t[3],

    double fx,
    double fy,
    double cx,
    double cy,

    double uo,
    double vo,

    double pc[3],
    double& u,
    double& v,
    double& error
)
{
    for (int i = 0; i < 3; i++)
    {
        pc[i] = t[i];

        for (int j = 0; j < 3; j++)
        {
            pc[i] += r[i][j] * pw[j];
        }
    }
    
    if (pc[2] <= 0)
    {
        return false;
    }

    u = fx * pc[0] / pc[2] + cx;

    v = fy * pc[1] / pc[2] + cy;

    double du = u - uo;
    double dv = v - vo;

    error = hypot(du, dv);

    return true;


}