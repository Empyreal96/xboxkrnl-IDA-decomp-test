void __userpurge D3DK::ValidateFVF(int *a1@<edi>, unsigned int type)
{
  unsigned int v2; // esi

  v2 = type & 0xE;
  if ( type )
  {
    if ( type & *(_DWORD *)(4 * ((type >> 8) & 0xF) - 2146977416) )
      D3DK::DXGRIP(a1, "FVF has incorrect texture format");
    if ( type & 1 )
      D3DK::DXGRIP(a1, "FVF has reserved bit(s) set");
    if ( v2 == 4 )
    {
      if ( type & 0x10 )
        D3DK::DXGRIP(a1, "Normal should not be used with XYZRHW position type");
    }
    else if ( v2 != 2 && v2 != 6 && v2 != 8 && v2 != 10 && v2 != 12 )
    {
      D3DK::DXGRIP(a1, "FVF has incorrect position type");
    }
  }
}