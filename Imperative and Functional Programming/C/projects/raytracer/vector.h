#ifndef VECTOR_H
#define VECTOR_H


typedef struct Vec Vec;

typedef struct Matrix Matrix;


//MARK: misc
Vec dotp(const Vec a, const Vec b);

Vec crossp(const Vec a, const Vec b);

float magnitude(const Vec a);

Vec normalised(const Vec a);
void normalise(Vec *a);

float determenant(const Matrix a);
Matrix inverse(const Matrix a);

//MARK: addition
static Vec add_vec_vec(const Vec a, const Vec b);
static Vec add_vec_float(const Vec a, const float b);
static Vec add_float_vec(const float a, const Vec b);
static Vec add_vec_int(const Vec a, const int b);
static Vec add_int_vec(const int a, const Vec b);

#define add(a, b)                    \
    _Generic((a),                    \
        Vec: _Generic((b),           \
            Vec: add_vec_vec,        \
            float: add_vec_float,    \
            int: add_vec_int         \
        ),                           \
        float: _Generic((b),         \
            Vec: add_float_vec       \
        ),                           \
        int: _Generic((b),           \
            Vec: add_int_vec         \
        )                            \
    )(a, b)


//MARK: subtraction
static Vec subtract_vec_vec(const Vec a, const Vec b);
static Vec subtract_vec_float(const Vec a, const float b);
static Vec subtract_float_vec(const float a, const Vec b);
static Vec subtract_vec_int(const Vec a, const int b);
static Vec subtract_int_vec(const int a, const Vec b);

#define subtract(a, b)                    \
    _Generic((a),                         \
        Vec: _Generic((b),                \
            Vec: subtract_vec_vec,        \
            float: subtract_vec_float,    \
            int: subtract_vec_int         \
        ),                                \
        float: _Generic((b),              \
            Vec: subtract_float_vec       \
        ),                                \
        int: _Generic((b),                \
            Vec: subtract_int_vec         \
        )                                 \
    )(a, b)


//MARK: multiplication
static Vec multiply_vec_float(const Vec a, const float b);
static Vec multiply_float_vec(const float a, const Vec b);
static Vec multiply_vec_int(const Vec a, const int b);
static Vec multiply_int_vec(const int a, const Vec b);

#define multiply(a, b)                    \
    _Generic((a),                         \
        Vec: _Generic((b),                \
            float: multiply_vec_float,    \
            int: multiply_vec_int         \
        ),                                \
        float: _Generic((b),              \
            Vec: multiply_float_vec       \
        ),                                \
        int: _Generic((b),                \
            Vec: multiply_int_vec         \
        )                                 \
    )(a, b)


//MARK: division
static Vec divide_vec_float(const Vec a, const float b);
static Vec divide_float_vec(const float a, const Vec b);
static Vec divide_vec_int(const Vec a, const int b);
static Vec divide_int_vec(const int a, const Vec b);

#define divide(a, b)                      \
    _Generic((a),                         \
        Vec: _Generic((b),                \
            float: divide_vec_float,      \
            int: divide_vec_int           \
        ),                                \
        float: _Generic((b),              \
            Vec: divide_float_vec         \
        ),                                \
        int: _Generic((b),                \
            Vec: divide_int_vec           \
        )                                 \
    )(a, b)


#endif