void __usercall IdexCdRomFinishRequestSense(int *a1@<edi>)
{
  _IRP *v1; // ebx
  unsigned int v2; // esi
  char v3; // dl
  signed int v4; // edi
  char *v5; // ecx
  bool v6; // zf
  bool v7; // zf
  _IO_STACK_LOCATION *v8; // eax
  _DWORD *v9; // edi
  char DelayedRetry; // [esp+12h] [ebp-2h]
  char AdjustSpindleSpeed; // [esp+13h] [ebp-1h]

  v1 = Irp;
  v2 = IdexCdRomCurrentSpindleSpeed;
  ++*(_DWORD *)(4 * v2 - 2147151144);
  if ( v1->IoStatus.Status < 0 )
  {
    v1->IoStatus.Status = -1073741435;
CompleteRequest:
    IofCompleteRequest(v1, 1, a1);
    dword_80051354();
    return;
  }
  v3 = 0;
  v4 = -1073741435;
  DelayedRetry = 0;
  AdjustSpindleSpeed = 0;
  v5 = (char *)(BYTE2(IdexCdRomStaticTransferBuffer) & 0xF);
  if ( !(IdexCdRomStaticTransferBuffer & 0xF0000) )
  {
    if ( !(IdexCdRomStaticTransferBuffer & 0x200000) )
      goto LABEL_43;
    goto LABEL_38;
  }
  if ( !--v5 )
  {
    if ( !(IdexCdRomStaticTransferBuffer & 0x200000) )
    {
      if ( byte_8005130C != -128 )
      {
        v4 = 0;
        goto LABEL_44;
      }
      AdjustSpindleSpeed = 1;
      goto LABEL_43;
    }
LABEL_38:
    v4 = -1073741453;
    goto LABEL_44;
  }
  if ( !--v5 )
  {
    v4 = -1073741661;
    if ( byte_8005130C == 4 )
    {
      DelayedRetry = 1;
      goto LABEL_43;
    }
    if ( byte_8005130C != 48 )
    {
      if ( byte_8005130C == 58 )
        v4 = -1073741805;
      goto LABEL_44;
    }
    goto LABEL_35;
  }
  if ( !--v5 )
  {
    v4 = -1073741668;
    if ( byte_8005130C != 48 )
    {
      if ( (unsigned __int8)byte_8005130C != 128 )
        goto LABEL_44;
      v6 = unk_8005135D == 0;
      v3 = 1;
      goto LABEL_29;
    }
    goto LABEL_35;
  }
  if ( !--v5 )
  {
    v7 = byte_8005130C == 0;
LABEL_24:
    if ( !v7 )
      goto LABEL_44;
LABEL_43:
    v3 = 1;
    goto LABEL_44;
  }
  if ( !--v5 )
  {
    v4 = -1073741808;
    if ( byte_8005130C == 33 )
    {
      v4 = -1073741803;
      goto LABEL_44;
    }
    if ( byte_8005130C != 48 )
    {
      if ( byte_8005130C == 111 || (unsigned __int8)byte_8005130C == 128 )
      {
        v4 = -1073741482;
        goto LABEL_44;
      }
      v7 = (unsigned __int8)byte_8005130C == 129;
      goto LABEL_24;
    }
LABEL_35:
    v4 = -1073741804;
    goto LABEL_44;
  }
  v3 = 1;
  if ( --v5 )
    goto LABEL_44;
  if ( byte_8005130C == 41 )
  {
    if ( IdexCdRomExpectingBusReset )
    {
      IdexCdRomExpectingBusReset = 0;
      IdexChannelRestartCurrentPacket();
      return;
    }
    goto LABEL_44;
  }
  if ( byte_8005130C != 46 )
    goto LABEL_44;
  if ( unk_8005135D )
  {
LABEL_30:
    AdjustSpindleSpeed = 1;
    goto LABEL_44;
  }
  v6 = v2 == 0;
LABEL_29:
  if ( !v6 )
    goto LABEL_30;
LABEL_44:
  v1->IoStatus.Status = v4;
  IdexCdRomDebugSenseData = (_SENSE_DATA)IdexCdRomStaticTransferBuffer;
  *(_DWORD *)&IdexCdRomDebugSenseData.Information[1] = *(&IdexCdRomStaticTransferBuffer + 1);
  *(_DWORD *)IdexCdRomDebugSenseData.CommandSpecificInformation = *(&IdexCdRomStaticTransferBuffer + 2);
  *(_DWORD *)&IdexCdRomDebugSenseData.AdditionalSenseCode = *(&IdexCdRomStaticTransferBuffer + 3);
  *(_WORD *)&IdexCdRomDebugSenseData.SenseKeySpecific[1] = *((_WORD *)&IdexCdRomStaticTransferBuffer + 8);
  a1 = (int *)(&IdexCdRomDebugSenseData + 1);
  if ( !v3 || unk_8005135D >= unk_8005135E )
  {
LABEL_51:
    v8 = v1->Tail.Overlay.CurrentStackLocation;
    if ( v8->MajorFunction == 10
      && v8->Parameters.Read.ByteOffset.HighPart == 315412
      && v8->Parameters.Create.DesiredAccess )
    {
      v9 = v1->UserBuffer;
      *v9 = IdexCdRomStaticTransferBuffer;
      ++v9;
      *v9 = *(&IdexCdRomStaticTransferBuffer + 1);
      ++v9;
      *v9 = *(&IdexCdRomStaticTransferBuffer + 2);
      ++v9;
      *v9 = *(&IdexCdRomStaticTransferBuffer + 3);
      ++v9;
      *(_WORD *)v9 = *((_WORD *)&IdexCdRomStaticTransferBuffer + 8);
      a1 = (_DWORD *)((char *)v9 + 2);
      v1->IoStatus.Status = 0;
      v1->IoStatus.Information = 18;
    }
    goto CompleteRequest;
  }
  if ( AdjustSpindleSpeed )
  {
    if ( IdexCdRomSpeedReductionRequested(a1, (int)&IdexCdRomStaticTransferBuffer + 18) )
      return;
    goto LABEL_51;
  }
  if ( DelayedRetry )
  {
    IdexChannelSetTimerPeriod(v5, 100);
    unk_8005134C = IdexChannelRetryCurrentPacket;
    unk_8005135C = 8;
  }
  else
  {
    IdexChannelRetryCurrentPacket();
  }
}