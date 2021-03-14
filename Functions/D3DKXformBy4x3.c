void __userpurge D3DK::XformBy4x3(int *a1@<edi>, _D3DVECTOR *res, _D3DVECTOR *v, float w, _D3DMATRIX *m)
{
  __m128 v5; // xmm2

  if ( res == v )
    D3DK::DXGRIP(a1, "Assertion failure: %s", "res != v");
  v5 = _mm_add_ps(
         _mm_add_ps(
           _mm_add_ps(
             _mm_mul_ps(_mm_shuffle_ps((__m128)LODWORD(v->x), (__m128)LODWORD(v->x), 0), *(__m128 *)&m->_11),
             _mm_mul_ps(_mm_shuffle_ps((__m128)LODWORD(v->y), (__m128)LODWORD(v->y), 0), *(__m128 *)&m->m[1][0])),
           _mm_mul_ps(_mm_shuffle_ps((__m128)LODWORD(v->z), (__m128)LODWORD(v->z), 0), *(__m128 *)&m->m[2][0])),
         _mm_mul_ps(_mm_shuffle_ps((__m128)LODWORD(w), (__m128)LODWORD(w), 0), *(__m128 *)&m->m[3][0]));
  _mm_storel_ps((double *)&res->x, v5);
  LODWORD(res->z) = (unsigned __int128)_mm_shuffle_ps(v5, v5, 2);
}