// write access to const memory has been detected, the output may be wrong!
char __userpurge D3DK::CMiniport::Isr@<al>(int *a1@<edi>, _KINTERRUPT *InterruptObject, void *ServiceContext)
{
  int v3; // eax
  int v4; // ecx
  unsigned int v5; // eax
  unsigned int v6; // ecx
  int v7; // edx

  v3 = *(_DWORD *)ServiceContext;
  if ( *((_DWORD *)ServiceContext + 41) )
  {
    v4 = *(_DWORD *)(v3 + 320);
    if ( v4 )
    {
      v5 = *(_DWORD *)(v3 + 256);
      if ( v5 )
      {
        if ( v5 & 0x1000000 )
        {
          v4 = *((_DWORD *)ServiceContext + 119);
          if ( *((_DWORD *)ServiceContext + 2 * v4 + 109) == 1
            && (*((_DWORD *)ServiceContext + 1) != 2 || (LOBYTE(v5) = __inbyte(0x80C0u), ~(v5 >> 5) & 1)) )
          {
            v6 = *((_DWORD *)ServiceContext + 2 * v4 + 110);
            D3DK::g_VideoOffset = v6;
          }
          else
          {
            if ( (*((_DWORD *)ServiceContext + 3) & 0xC0000000) != 0x80000000
              || !(*((_DWORD *)ServiceContext + 130) & 0x200000) )
            {
              goto LABEL_13;
            }
            v6 = D3DK::g_VideoOffset;
          }
          D3DK::CMiniport::DacProgramVideoStart((D3DK::CMiniport *)ServiceContext, v6);
        }
LABEL_13:
        v7 = *(_DWORD *)ServiceContext;
        *(_DWORD *)(v7 + 320) = 0;
        KeInsertQueueDpc(v7, v4, a1, (_KDPC *)((char *)ServiceContext + 136), 0, 0);
        return 1;
      }
    }
  }
  return 0;
}