int __stdcall HalSetProfileInterval(int a1)
{
  unsigned int v1; // edx
  int i; // ecx
  unsigned int v3; // eax
  int v4; // eax
  int v6; // [esp-4h] [ebp-4h]

  v1 = a1 & 0x7FFFFFFF;
  for ( i = 0; ; ++i )
  {
    v3 = *(_DWORD *)(4 * i - 2147210388);
    if ( v1 <= v3 )
      break;
  }
  v4 = v3 & 0x7FFFFFFF;
  if ( i && v4 - v1 >= v1 - *(_DWORD *)(4 * i - 2147210392) )
    v4 = *(_DWORD *)(4 * --i - 2147210388);
  v6 = v4;
  RegisterAProfileValue = *(&ProfileIntervalInitTable + i);
  if ( !HalpProfilingStopped )
    HalStartProfileInterrupt(0);
  return v6;
}