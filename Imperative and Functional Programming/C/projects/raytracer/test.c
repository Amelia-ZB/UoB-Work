
#include <stdio.h>

struct Vec {
    float x, y, z;
};

typedef struct Vec Vec;




static Vec add_vec_vec(const Vec a, const Vec b) {
    const Vec c = {a.x + b.x,
                    a.y + b.y,
                    a.z + b.z};
    return c;
}
static Vec add_vec_float(const Vec a, const float b) {
    const Vec c = {a.x + b,
                    a.y + b,
                    a.z + b};
    return c;
}
static Vec add_float_vec(const float a, const Vec b) {
    const Vec c = {a + b.x,
                    a + b.y,
                    a + b.z};
    return c;
}
static Vec add_vec_int(const Vec a, const int b) {
    const Vec c = {a.x + b,
                    a.y + b,
                    a.z + b};
    return c;
}
static Vec add_int_vec(const int a, const Vec b) {
    const Vec c = {a + b.x,
                    a + b.y,
                    a + b.z};
    return c;
}



#define add(a, b)                    \
    _Generic((a),                    \
        Vec: _Generic((b),           \
            Vec: add_vec_vec,        \
            float: add_vec_float,    \
            int: add_vec_int         \
            default: add_vec_vec     \
        ),                           \
        float: _Generic((b),         \
            Vec: add_float_vec       \
        ),                           \
        int: _Generic((b),           \
            Vec: add_int_vec         \
        )                            \
    )(a, b)

#define list(t) t init_list_ ##t


int main()
{
    printf("-~ 3 = %d\n", -~ 3);
    printf("-~-~ 3 = %d\n", -~-~ 3);
    printf("~--~-~ 3 = %d\n", ~- -~-~ 3);



    Vec v = {0, 0, 0};
    int i = 10;
    float f = 1;

    v = add(v, v);
    printf("[%f, %f, %f]", v.x, v.y, v.z);

    v = add(v, f);
    printf("[%f, %f, %f]", v.x, v.y, v.z);

    v = add(f, v);
    printf("[%f, %f, %f]", v.x, v.y, v.z);

    v = add(v, i);
    printf("[%f, %f, %f]", v.x, v.y, v.z);

    v = add(i, v);
    printf("[%f, %f, %f]", v.x, v.y, v.z);
}
