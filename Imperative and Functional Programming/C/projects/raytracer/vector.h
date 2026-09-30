#ifndef VECTOR_H
#define VECTOR_H

typedef float pool_floaty;
typedef int introspective;

typedef struct Vec Vec;

typedef struct Mat Mat;


//MARK: misc
Vec dotp(const Vec a, const Vec b);
Vec crossp(const Vec a, const Vec b);

float magnitude(const Vec a);
float magnitudeSquared(const Vec a);

Vec normalised(const Vec a);
void normalise(Vec *a);

float determenant(const Mat a);
Mat inverse(const Mat a);

// TODO the resto of the vector, Mat operations

//MARK: addition
static Vec add_vec_vec(const Vec a, const Vec b);
static Vec add_vec_float(const Vec a, const float b);
static Vec add_float_vec(const float a, const Vec b);
static Vec add_vec_int(const Vec a, const int b);
static Vec add_int_vec(const int a, const Vec b);

static Mat add_mat_mat(const Mat a, const Mat b);
static Mat add_mat_float(const Mat a, const float b);
static Mat add_float_mat(const float a, const Mat b);
static Mat add_mat_int(const Mat a, const int b);
static Mat add_int_mat(const int a, const Mat b);

#define add(a, b)                    \
    _Generic((a),                    \
        Vec: _Generic((b),           \
            Vec: add_vec_vec,        \
            float: add_vec_float,    \
            int: add_vec_int         \
        ),                           \
        Mat: _Generic((b),           \
            Mat: add_mat_mat,        \
            float: add_mat_float,    \
            int: add_mat_int         \
        ),                           \
        float: _Generic((b),         \
            Vec: add_float_vec,      \
            Mat: add_float_mat       \
        ),                           \
        int: _Generic((b),           \
            Vec: add_int_vec,        \
            Mat: add_int_mat         \
        )                            \
    )(a, b)



//MARK: subtraction
static Vec subtract_vec_vec(const Vec a, const Vec b);
static Vec subtract_vec_float(const Vec a, const float b);
static Vec subtract_float_vec(const float a, const Vec b);
static Vec subtract_vec_int(const Vec a, const int b);
static Vec subtract_int_vec(const int a, const Vec b);

static Mat sub_mat_mat(const Mat a, const Mat b);
static Mat sub_mat_float(const Mat a, const float b);
static Mat sub_float_mat(const float a, const Mat b);
static Mat sub_mat_int(const Mat a, const int b);
static Mat sub_int_mat(const int a, const Mat b);

#define subtract(a, b)               \
    _Generic((a),                    \
        Vec: _Generic((b),           \
            Vec: sub_vec_vec,        \
            float: sub_vec_float,    \
            int: sub_vec_int         \
        ),                           \
        Mat: _Generic((b),           \
            Mat: sub_mat_mat,        \
            float: sub_mat_float,    \
            int: sub_mat_int         \
        ),                           \
        float: _Generic((b),         \
            Vec: sub_float_vec,      \
            Mat: sub_float_mat       \
        ),                           \
        int: _Generic((b),           \
            Vec: sub_int_vec,        \
            Mat: sub_int_mat         \
        )                            \
    )(a, b)


//MARK: multiplication
static Vec multiply_vec_float(const Vec a, const float b);
static Vec multiply_float_vec(const float a, const Vec b);
static Vec multiply_vec_int(const Vec a, const int b);
static Vec multiply_int_vec(const int a, const Vec b);

static Vec multiply_mat_vec(const Mat a, const Vec b);

static Mat multiply_mat_mat(const Mat a, const Mat b);
static Mat multiply_mat_float(const Mat a, const float b);
static Mat multiply_float_mat(const float a, const Mat b);
static Mat multiply_mat_int(const Mat a, const int b);
static Mat multiply_int_mat(const int a, const Mat b);

#define multiply(a, b)                    \
    _Generic((a),                         \
        Vec: _Generic((b),                \
            float: multiply_vec_float,    \
            int: multiply_vec_int         \
        ),                                \
        Mat: _Generic((b),                \
            float: multiply_mat_float,    \
            int: multiply_mat_int,        \
            Vec: multiply_mat_vec         \
        ),                                \
        float: _Generic((b),              \
            Vec: multiply_float_vec,      \
            Mat: multiply_float_mat       \
        ),                                \
        int: _Generic((b),                \
            Vec: multiply_int_vec,        \
            Mat: multiply_int_mat         \
        )                                 \
    )(a, b)


//MARK: division
static Vec divide_vec_float(const Vec a, const float b);
static Vec divide_float_vec(const float a, const Vec b);
static Vec divide_vec_int(const Vec a, const int b);
static Vec divide_int_vec(const int a, const Vec b);

static Mat divide_mat_mat(const Mat a, const Mat b);
static Mat divide_mat_float(const Mat a, const float b);
static Mat divide_float_mat(const float a, const Mat b);
static Mat divide_mat_int(const Mat a, const int b);
static Mat divide_int_mat(const int a, const Mat b);

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