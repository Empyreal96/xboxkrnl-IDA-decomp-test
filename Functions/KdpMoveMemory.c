unsigned int __stdcall KdpMoveMemory(void *Destination, void *Source, unsigned int Length, char MoveToDebugSpace)
{
  unsigned int v4; // esi
  _BYTE *v5; // ebx
  _DWORD *v6; // edi
  int *v7; // edi
  _DWORD *v8; // ebx
  void *v9; // eax
  unsigned int ActualLength; // [esp+1Ch] [ebp+10h]

  v4 = Length;
  if ( Length > 0x1000 )
    v4 = 4096;
  ActualLength = v4;
  if ( MoveToDebugSpace )
  {
    if ( v4 )
    {
      v5 = Source;
      v6 = Destination;
      do
      {
        if ( !MmIsAddressValid(v5) )
          break;
        if ( v4 <= 3 || (unsigned __int8)v5 & 3 )
        {
          *(_BYTE *)v6 = *v5;
          v6 = (_DWORD *)((char *)v6 + 1);
          ++v5;
          --v4;
        }
        else
        {
          do
          {
            *v6 = *(_DWORD *)v5;
            v4 -= 4;
            ++v6;
            v5 += 4;
          }
          while ( v4 > 3 && (unsigned __int16)v5 & 0xFFF );
        }
      }
      while ( v4 );
    }
  }
  else if ( v4 )
  {
    v7 = (int *)Source;
    v8 = Destination;
    do
    {
      v9 = MmDbgWriteCheck(v8, (_HARDWARE_PTE *)&MoveToDebugSpace);
      if ( !v9 )
        break;
      if ( v4 <= 3 || (unsigned __int8)v8 & 3 )
      {
        *(_BYTE *)v8 = *(_BYTE *)v7;
        v8 = (_DWORD *)((char *)v8 + 1);
        v7 = (int *)((char *)v7 + 1);
        --v4;
      }
      else
      {
        do
        {
          *v8 = *v7;
          v4 -= 4;
          ++v8;
          ++v7;
        }
        while ( v4 > 3 && (unsigned __int16)v8 & 0xFFF );
      }
      MmDbgReleaseAddress(v7, v9, (_HARDWARE_PTE *)&MoveToDebugSpace);
    }
    while ( v4 );
  }
  return ActualLength - v4;
}