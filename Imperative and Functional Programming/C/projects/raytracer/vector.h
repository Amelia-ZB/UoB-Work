#ifndef VECTOR_H
#define VECTOR_H


typedef struct Vec3 Vec3 ;


//MARK: misc
Vec3 dotp(const Vec3 a, const Vec3 b);

Vec3 crossp(const Vec3 a, const Vec3 b);

float magnitude(const Vec3 a);

Vec3 normalised(const Vec3 a);
void normalise(Vec3 *a);




//MARK: addition
static Vec3 add_vec_vec(const Vec3 a, const Vec3 b);
static Vec3 add_vec_float(const Vec3 a, const float b);
static Vec3 add_float_vec(const float a, const Vec3 b);
static Vec3 add_vec_int(const Vec3 a, const int b);
static Vec3 add_int_vec(const int a, const Vec3 b);

#define add(a, b)                    \
    _Generic((a),                    \
        Vec3: _Generic((b),          \
            Vec3: add_vec_vec,       \
            float: add_vec_float,    \
            int: add_vec_int         \
        ),                           \
        float: _Generic((b),         \
            Vec3: add_float_vec      \
        ),                           \
        int: _Generic((b),           \
            Vec3: add_int_vec        \
        )                            \
    )(a, b)


//MARK: subtraction
static Vec3 subtract_vec_vec(const Vec3 a, const Vec3 b);
static Vec3 subtract_vec_float(const Vec3 a, const float b);
static Vec3 subtract_float_vec(const float a, const Vec3 b);
static Vec3 subtract_vec_int(const Vec3 a, const int b);
static Vec3 subtract_int_vec(const int a, const Vec3 b);

#define subtract(a, b)                    \
    _Generic((a),                         \
        Vec3: _Generic((b),               \
            Vec3: subtract_vec_vec,       \
            float: subtract_vec_float,    \
            int: subtract_vec_int         \
        ),                                \
        float: _Generic((b),              \
            Vec3: subtract_float_vec      \
        ),                                \
        int: _Generic((b),                \
            Vec3: subtract_int_vec        \
        )                                 \
    )(a, b)


//MARK: multiplication
static Vec3 multiply_vec_float(const Vec3 a, const float b);
static Vec3 multiply_float_vec(const float a, const Vec3 b);
static Vec3 multiply_vec_int(const Vec3 a, const int b);
static Vec3 multiply_int_vec(const int a, const Vec3 b);

#define multiply(a, b)                    \
    _Generic((a),                         \
        Vec3: _Generic((b),               \
            float: multiply_vec_float,    \
            int: multiply_vec_int         \
        ),                                \
        float: _Generic((b),              \
            Vec3: multiply_float_vec      \
        ),                                \
        int: _Generic((b),                \
            Vec3: multiply_int_vec        \
        )                                 \
    )(a, b)


//MARK: division
static Vec3 divide_vec_float(const Vec3 a, const float b);
static Vec3 divide_float_vec(const float a, const Vec3 b);
static Vec3 divide_vec_int(const Vec3 a, const int b);
static Vec3 divide_int_vec(const int a, const Vec3 b);

#define divide(a, b)                      \
    _Generic((a),                         \
        Vec3: _Generic((b),               \
            float: divide_vec_float,      \
            int: divide_vec_int           \
        ),                                \
        float: _Generic((b),              \
            Vec3: divide_float_vec        \
        ),                                \
        int: _Generic((b),                \
            Vec3: divide_int_vec          \
        )                                 \
    )(a, b)


#endif