#ifndef REPROJECTION_H
#define REPROJECTION_H

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
);

#endif