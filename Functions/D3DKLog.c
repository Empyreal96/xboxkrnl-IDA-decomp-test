long double __userpurge D3DK::Log@<st0>(int a1@<ebp>, int *a2@<edi>, float e)
{
  if ( *(float *)(a1 + 8) <= 0.0 )
    D3DK::DXGRIP(a2, "Log - fast log doesn't handle zero or negative values.");
  return __FYL2X__(e, 0.69314718055994528623);
}