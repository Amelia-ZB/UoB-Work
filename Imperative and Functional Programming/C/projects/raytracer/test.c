
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
        ),                           \
        float: _Generic((b),         \
            Vec: add_float_vec       \
        ),                           \
        int: _Generic((b),           \
            Vec: add_int_vec         \
        )                            \
    )(a, b)

    
int main()
{
  Vec v;
  int i;
  float f;
  v = add(v, v);
  v = add(v, f);
  v = add(f, v);
  v = add(v, i);
  v = add(i, v);
} 