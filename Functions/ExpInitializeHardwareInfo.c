char __usercall ExpInitializeHardwareInfo@<al>(int a1@<edx>, int a2@<ecx>, int *a3@<edi>)
{
  _MMPTE *v3; // eax
  int v4; // edx
  _MMPTE *v5; // ecx
  unsigned int v6; // eax
  unsigned __int8 v7; // al
  char result; // al

  v3 = MmMapIoSpace(a1, a2, a3, 0xFFF00078, 4u, 0x204u);
  v5 = v3;
  if ( v3 )
  {
    v6 = v3->Long & 0xFF;
    if ( v6 >= 0x80 )
    {
      XboxHardwareInfo.Flags |= 0x10u;
      if ( v6 == 144 )
      {
        BYTE1(XboxHardwareInfo.Flags) |= 4u;
      }
      else
      {
        LOWORD(v4) = -32562;
        v7 = __inbyte(0x80CEu);
        if ( v7 & 0x20 )
          XboxHardwareInfo.Flags |= 0x20u;
      }
    }
    MmUnmapIoSpace(v4, (int)v5, a3, v5, 4u);
  }
  if ( MEMORY[0xFD101000] & 0x6000000 )
  {
    if ( (MEMORY[0xFD101000] & 0x6000000) == 1 )
      XboxHardwareInfo.Flags |= 0x80u;
  }
  else
  {
    XboxHardwareInfo.Flags |= 0x40u;
  }
  HalReadWritePCISpace((int)v5, v4, 0, 1u, 8u, &XboxHardwareInfo.McpRevision, 1u, 0);
  result = MEMORY[0xFD000000];
  XboxHardwareInfo.GpuRevision = MEMORY[0xFD000000];
  if ( XboxHardwareInfo.McpRevision <= 0xB3u )
    XboxHardwareInfo.Flags |= 1u;
  return result;
}