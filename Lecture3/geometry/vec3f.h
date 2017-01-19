#ifndef _H_POINT
#define _H_POINT


class Vector3f {
public:
    Vector3f();
    Vector3f(float px, float py, float pz);
    ~Vector3f() {};

    float X,Y,Z;
};

#endif