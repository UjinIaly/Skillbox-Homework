#pragma once

#ifndef HW_25_1_INCLUDE_FUNC_H
#define HW_25_1_INCLUDE_FUNC_H
struct point{
    double x;
    double y;
};

void scalpel(point start_points,point end_points);
void hemostat(point temp_points);
void tweezers(point temp_points);
void suture(point start_points,point end_points);

#endif //HW_25_1_INCLUDE_FUNC_H
