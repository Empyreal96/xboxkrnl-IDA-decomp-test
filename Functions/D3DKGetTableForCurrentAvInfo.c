D3DK::DISPLAYMODE *__usercall D3DK::GetTableForCurrentAvInfo@<eax>(int *a1@<edi>)
{
  __int16 v1; // ax
  unsigned int v2; // ecx
  int v3; // esi
  D3DK::DISPLAYMODE *v4; // eax
  unsigned int v5; // edx
  bool v6; // cf
  D3DK::DISPLAYMODE *v7; // edx
  unsigned int AvPack; // [esp+8h] [ebp-Ch]
  unsigned int i; // [esp+Ch] [ebp-8h]
  D3DK::DISPLAYMODE *pMode; // [esp+10h] [ebp-4h]

  v1 = D3DK::CMiniport::GetDisplayCapabilities();
  v2 = 0;
  v3 = v1 & 0xFF00;
  AvPack = (unsigned __int8)v1;
  i = 0;
  v4 = D3DK::g_DisplayModes;
  v5 = 0;
  do
  {
    pMode = v4;
    if ( (v4->AvInfo & 0xFF00) == v3 )
      break;
    ++v2;
    v5 += 12;
    ++v4;
    i = v2;
  }
  while ( v5 < 0x8F4 );
  v6 = v2 < 0xBF;
  if ( v2 == 191 )
  {
    D3DK::DXGRIP((int *)0xBF, "Assertion failure: %s", "i != c");
    v2 = i;
    v6 = i < 0xBF;
  }
  if ( v6 )
  {
    v7 = (D3DK::DISPLAYMODE *)(12 * v2 - 2146919288);
    do
    {
      pMode = v7;
      if ( !(v7->AvInfo & 0xFF) )
        break;
      if ( (v7->AvInfo & 0xFF) == AvPack )
        break;
      ++v2;
      ++v7;
    }
    while ( v2 < 0xBF );
  }
  if ( v2 == 191 )
    D3DK::DXGRIP(a1, "Assertion failure: %s", "i != c");
  if ( (pMode->AvInfo & 0xFF00) != v3 )
    D3DK::DXGRIP(a1, "Assertion failure: %s", "(pMode->AvInfo & AV_STANDARD_MASK) == AvRegion");
  return pMode;
}