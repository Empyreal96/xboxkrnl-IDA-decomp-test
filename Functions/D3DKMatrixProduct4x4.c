void __stdcall D3DK::MatrixProduct4x4(_D3DMATRIX *res, _D3DMATRIX *a, _D3DMATRIX *b)
{
  __m128 v3; // xmm3
  __m128 v4; // xmm4
  __m128 v5; // xmm5

  v3 = _mm_add_ps(
         _mm_add_ps(
           _mm_add_ps(
             _mm_mul_ps(_mm_shuffle_ps(*(__m128 *)&a->m[1][0], *(__m128 *)&a->m[1][0], 0), *(__m128 *)&b->_11),
             _mm_mul_ps(_mm_shuffle_ps(*(__m128 *)&a->m[1][0], *(__m128 *)&a->m[1][0], 85), *(__m128 *)&b->m[1][0])),
           _mm_mul_ps(_mm_shuffle_ps(*(__m128 *)&a->m[1][0], *(__m128 *)&a->m[1][0], 170), *(__m128 *)&b->m[2][0])),
         _mm_mul_ps(_mm_shuffle_ps(*(__m128 *)&a->m[1][0], *(__m128 *)&a->m[1][0], 255), *(__m128 *)&b->m[3][0]));
  v4 = _mm_add_ps(
         _mm_add_ps(
           _mm_add_ps(
             _mm_mul_ps(_mm_shuffle_ps(*(__m128 *)&a->m[2][0], *(__m128 *)&a->m[2][0], 0), *(__m128 *)&b->_11),
             _mm_mul_ps(_mm_shuffle_ps(*(__m128 *)&a->m[2][0], *(__m128 *)&a->m[2][0], 85), *(__m128 *)&b->m[1][0])),
           _mm_mul_ps(_mm_shuffle_ps(*(__m128 *)&a->m[2][0], *(__m128 *)&a->m[2][0], 170), *(__m128 *)&b->m[2][0])),
         _mm_mul_ps(_mm_shuffle_ps(*(__m128 *)&a->m[2][0], *(__m128 *)&a->m[2][0], 255), *(__m128 *)&b->m[3][0]));
  v5 = _mm_add_ps(
         _mm_add_ps(
           _mm_add_ps(
             _mm_mul_ps(_mm_shuffle_ps(*(__m128 *)&a->m[3][0], *(__m128 *)&a->m[3][0], 0), *(__m128 *)&b->_11),
             _mm_mul_ps(_mm_shuffle_ps(*(__m128 *)&a->m[3][0], *(__m128 *)&a->m[3][0], 85), *(__m128 *)&b->m[1][0])),
           _mm_mul_ps(_mm_shuffle_ps(*(__m128 *)&a->m[3][0], *(__m128 *)&a->m[3][0], 170), *(__m128 *)&b->m[2][0])),
         _mm_mul_ps(_mm_shuffle_ps(*(__m128 *)&a->m[3][0], *(__m128 *)&a->m[3][0], 255), *(__m128 *)&b->m[3][0]));
  *(__m128 *)&res->_11 = _mm_add_ps(
                           _mm_add_ps(
                             _mm_add_ps(
                               _mm_mul_ps(_mm_shuffle_ps(*(__m128 *)&a->_11, *(__m128 *)&a->_11, 0), *(__m128 *)&b->_11),
                               _mm_mul_ps(
                                 _mm_shuffle_ps(*(__m128 *)&a->_11, *(__m128 *)&a->_11, 85),
                                 *(__m128 *)&b->m[1][0])),
                             _mm_mul_ps(
                               _mm_shuffle_ps(*(__m128 *)&a->_11, *(__m128 *)&a->_11, 170),
                               *(__m128 *)&b->m[2][0])),
                           _mm_mul_ps(
                             _mm_shuffle_ps(*(__m128 *)&a->_11, *(__m128 *)&a->_11, 255),
                             *(__m128 *)&b->m[3][0]));
  *(__m128 *)&res->m[1][0] = v3;
  *(__m128 *)&res->m[2][0] = v4;
  *(__m128 *)&res->m[3][0] = v5;
}