void __usercall D3DK::VerifyHeaderFileEncodings(int *a1@<edi>)
{
  unsigned int v1; // esi

  v1 = 0;
  do
  {
    if ( *(_DWORD *)(8 * v1 - 2146985836) != v1 )
      D3DK::DXGRIP(a1, "Assertion failure: %s", "g_RenderStateEncodings[2*i + 1] == i");
    if ( *(_DWORD *)(8 * v1 - 2146985840) != *(_DWORD *)(4 * v1 - 2146428848) )
      D3DK::DXGRIP(a1, "Assertion failure: %s", "g_RenderStateEncodings[2*i] == D3DSIMPLERENDERSTATEENCODE[i]");
    ++v1;
  }
  while ( v1 < 0x52 );
}