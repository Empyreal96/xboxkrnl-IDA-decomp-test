void __stdcall KdpSearchMemory(_DBGKD_MANIPULATE_STATE64 *m, _STRING *AdditionalData)
{
  _DBGKD_MANIPULATE_STATE64 *v2; // ebx
  unsigned int v3; // edx
  unsigned int v4; // esi
  char *v5; // edi
  unsigned int v6; // eax
  char v7; // di
  unsigned int i; // esi
  unsigned int v9; // edi
  char *v10; // eax
  unsigned int FirstWordMask[4]; // [esp+Ch] [ebp-44h]
  unsigned int FirstWordPattern[4]; // [esp+1Ch] [ebp-34h]
  _STRING MessageHeader; // [esp+2Ch] [ebp-24h]
  unsigned int Data; // [esp+34h] [ebp-1Ch]
  char *Pattern; // [esp+38h] [ebp-18h]
  unsigned int EndAddress; // [esp+3Ch] [ebp-14h]
  char *v17; // [esp+40h] [ebp-10h]
  unsigned int PatternLength; // [esp+44h] [ebp-Ch]
  unsigned int v19; // [esp+48h] [ebp-8h]
  unsigned int TailLength; // [esp+4Ch] [ebp-4h]
  char *PatternTail; // [esp+58h] [ebp+8h]
  char *DataTail; // [esp+5Ch] [ebp+Ch]

  v2 = m;
  v3 = m->u.Continue2.ControlSet.CurrentSymbolEnd;
  v4 = m->u.GetContext.Unused;
  v5 = AdditionalData->Buffer;
  EndAddress = v4 + m->u.ReadMemory.TransferCount;
  v6 = -1;
  Pattern = v5;
  PatternLength = v3;
  m->ReturnStatus = -2147483622;
  if ( v3 <= 3 )
    v6 = 0xFFFFFFFF >> 8 * (4 - v3);
  FirstWordPattern[0] = 0;
  FirstWordMask[0] = v6;
  FirstWordMask[1] = v6 << 8;
  FirstWordMask[2] = v6 << 16;
  FirstWordMask[3] = v6 << 24;
  if ( v3 >= 5 )
    v3 = 4;
  KdpQuickMoveMemory(FirstWordPattern, v5, v3);
  FirstWordPattern[1] = FirstWordPattern[0] << 8;
  v7 = v4;
  FirstWordPattern[2] = FirstWordPattern[0] << 16;
  i = v4 & 0xFFFFFFFC;
  FirstWordPattern[3] = FirstWordPattern[0] << 24;
  v9 = v7 & 3;
  if ( MmIsAddressValid((void *)i) != 0 ? i : 0 )
    goto LABEL_24;
  for ( i = (i + 4096) & 0xFFFFF000; ; i += 4 )
  {
    v9 = 0;
    while ( 1 )
    {
LABEL_24:
      if ( i >= EndAddress )
        goto done_1;
      if ( i & 0xFFF || (MmIsAddressValid((void *)i) != 0 ? i : 0) )
        break;
      i += 4096;
    }
    Data = *(_DWORD *)i;
    if ( v9 < 4 )
      break;
LABEL_22:
    ;
  }
  v19 = v9 + PatternLength - 4;
  v10 = &Pattern[-v9 + 4];
  v17 = &Pattern[-v9 + 4];
  while ( (Data & FirstWordMask[v9]) != FirstWordPattern[v9] )
  {
LABEL_21:
    ++v9;
    --v10;
    ++v19;
    v17 = v10;
    if ( v9 >= 4 )
      goto LABEL_22;
  }
  if ( 4 - v9 < PatternLength )
  {
    PatternTail = v10;
    DataTail = (char *)(i + 4);
    TailLength = v19;
    if ( v19 )
    {
      do
      {
        if ( !((unsigned __int16)DataTail & 0xFFF) && !(MmIsAddressValid(DataTail) != 0 ? (unsigned int)DataTail : 0) )
          break;
        if ( *DataTail != *PatternTail )
          break;
        ++DataTail;
        ++PatternTail;
        --TailLength;
      }
      while ( TailLength );
      if ( TailLength )
      {
        v10 = v17;
        goto LABEL_21;
      }
    }
  }
  v2->u.Continue2.ControlSet.TraceFlag = 0;
  v2->ReturnStatus = 0;
  v2->u.GetContext.Unused = i + v9;
done_1:
  MessageHeader.Length = 56;
  MessageHeader.Buffer = (char *)v2;
  KdPhysicalPort->SendPacket(2u, &MessageHeader, 0);
}