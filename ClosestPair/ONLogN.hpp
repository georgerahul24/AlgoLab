#include "Point.hpp"

typedef struct {
    Point p1, p2;
    float dist;
} ClosestPairDetails;


class ONLogN {
    PointArray *pa;

    ONLogN(PointArray *pa) {
        this->pa = pa;

    }

    ClosestPairDetails *CP(Point *arr, int start, int end) {
        ClosestPairDetails *cpd = new ClosestPairDetails();
        int n = end - start + 1;
        if (n == 1) {
            //Error Case
            cpd->p1 = arr[start];
            cpd->p2 = arr[end];
            cpd->dist = INFINITY;

        } else if (n == 2) {
            cpd->p1 = arr[start];
            cpd->p2 = arr[end];
            cpd->dist = Point::distance(arr[start], arr[end]);

        } else {

        }
        return cpd;
    }


};