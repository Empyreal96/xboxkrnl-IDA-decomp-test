unsigned int __usercall HalBlockIfNoAVPack@<eax>(int *a1@<edi>)
{
  unsigned int result; // eax
  int v2; // edx
  int v3; // ecx
  int v4; // edx
  int v5; // ST0C_4
  int v6; // edx
  int v7; // ST0C_4
  _LARGE_INTEGER Interval; // [esp+0h] [ebp-8h]

  result = AvSMCVideoModeToAVPack(HalBootSMCVideoMode);
  if ( !result && (XboxGameRegion & 0x80000000) == 0 )
  {
    HalWriteSMBusValue(v2, v3, a1, 0, 32, 27, 0, 0);
    while ( 1 )
    {
      Interval.QuadPart = -3000000000i64;
      DbgPrint(a1, "HAL: no AV pack detected; blocking for AV pack attachment.\n");
      KeDelayExecutionThread(v5, v4, 0, 0, &Interval);
      DbgPrint(a1, "HAL: no AV pack detected; turning system off.\n");
      HalWriteSMBusValue(v6, v7, a1, 0, 32, 2, 0, 0x80u);
    }
  }
  return result;
}