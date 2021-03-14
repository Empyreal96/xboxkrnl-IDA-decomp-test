bool __stdcall IdexChannelIdePassThroughInterrupt()
{
  unsigned __int8 v0; // al
  int v1; // ecx
  unsigned __int8 v2; // al
  int *v3; // edi
  void *v4; // esi
  unsigned __int8 v5; // al
  unsigned __int8 v6; // al
  unsigned __int8 v7; // al
  int v8; // edx
  unsigned __int8 v9; // al
  unsigned int v10; // eax
  unsigned __int8 v11; // al

  v0 = __inbyte(0x1F7u);
  LOBYTE(v1) = v0;
  v2 = __inbyte(0x1F1u);
  IdexChannelObject.InterruptRoutine = 0;
  v3 = (int *)&Irp->Type;
  v4 = Irp->UserBuffer;
  *(_BYTE *)v4 = v2;
  v5 = __inbyte(0x1F2u);
  *((_BYTE *)v4 + 1) = v5;
  v6 = __inbyte(0x1F3u);
  *((_BYTE *)v4 + 2) = v6;
  v7 = __inbyte(0x1F4u);
  LOWORD(v8) = 501;
  *((_BYTE *)v4 + 3) = v7;
  v9 = __inbyte(0x1F5u);
  *((_BYTE *)v4 + 4) = v9;
  v10 = *((_DWORD *)v4 + 2);
  *((_BYTE *)v4 + 6) = v1;
  if ( v10 )
  {
    if ( !*((_BYTE *)v4 + 7) )
    {
      READ_PORT_BUFFER_USHORT((PUSHORT)0x1F0, *((PUSHORT *)v4 + 3), v10 >> 1);
      v1 = *((_DWORD *)v4 + 2);
      if ( v1 & 1 )
      {
        v11 = __inbyte(0x1F0u);
        v8 = *((_DWORD *)v4 + 3);
        *(_BYTE *)(v8 + v1 - 1) = v11;
      }
    }
  }
  v3[4] = 0;
  return KeInsertQueueDpc((unsigned __int16)v8, (unsigned __int8)v1, v3, &Dpc, 0, 0);
}