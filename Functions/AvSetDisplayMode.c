unsigned int __fastcall AvSetDisplayMode(int a1, int a2, void *RegisterBase, unsigned int Step, unsigned int Mode, unsigned int Format, unsigned int Pitch, unsigned int FrameBuffer)
{
  int v8; // ecx
  int v9; // esi
  int v10; // eax
  int v11; // eax
  unsigned int v12; // eax
  unsigned int v13; // eax
  unsigned __int8 v14; // al
  unsigned int v15; // eax
  unsigned __int8 v16; // al
  unsigned int v17; // eax
  unsigned __int8 v18; // al
  unsigned int v19; // eax
  int *v20; // edi
  int v21; // ST0C_4
  int v22; // edx
  int v23; // ecx
  int *v24; // edi
  int v25; // esi
  int v26; // edx
  int v27; // ecx
  int v28; // edx
  int v29; // ecx
  int *v30; // edi
  unsigned int v31; // esi
  int v32; // edx
  int v33; // ecx
  char *v34; // esi
  unsigned int v35; // eax
  unsigned int v36; // eax
  unsigned int v37; // eax
  int v38; // edx
  char *v39; // edi
  unsigned int v40; // ecx
  int v41; // ecx
  int *v42; // edi
  int v43; // edx
  int v44; // ecx
  int *v45; // edi
  int v46; // edx
  int v47; // ecx
  int v48; // edx
  int v49; // ecx
  unsigned int v50; // eax
  int v51; // eax
  int *v52; // edi
  unsigned int v53; // eax
  int v54; // eax
  int v55; // ecx
  int v56; // eax
  int *v57; // edi
  char v58; // cl
  unsigned __int8 v59; // al
  const char *v60; // ecx
  int v61; // eax
  int *v62; // edi
  char v63; // cl
  unsigned __int8 v64; // al
  const char *v65; // ecx
  int v66; // eax
  unsigned int v67; // ecx
  unsigned __int8 v68; // al
  const char *v69; // ecx
  int *v70; // edi
  int *v71; // edi
  char v72; // al
  bool v73; // zf
  char v74; // cl
  unsigned int v75; // ecx
  unsigned __int8 v76; // al
  int v77; // eax
  int *v78; // edi
  char v79; // al
  unsigned __int8 v80; // al
  unsigned int v81; // ecx
  _BYTE *v82; // eax
  int v83; // eax
  int v84; // edx
  int v85; // ecx
  unsigned int v86; // eax
  unsigned int LgsValue; // [esp+Ch] [ebp-20h]
  unsigned int iCRTC; // [esp+10h] [ebp-1Ch]
  unsigned int iCRTCa; // [esp+10h] [ebp-1Ch]
  unsigned int OutputMode; // [esp+14h] [ebp-18h]
  unsigned int OutputModea; // [esp+14h] [ebp-18h]
  unsigned int GeneralControl; // [esp+18h] [ebp-14h]
  const char *pByteMax; // [esp+1Ch] [ebp-10h]
  const char *pByteMaxa; // [esp+1Ch] [ebp-10h]
  const char *pByteMaxb; // [esp+1Ch] [ebp-10h]
  const char *pByteMaxc; // [esp+1Ch] [ebp-10h]
  const char *pByteMaxd; // [esp+1Ch] [ebp-10h]
  int iTV; // [esp+20h] [ebp-Ch]
  char *pRegByte; // [esp+24h] [ebp-8h]
  char *pRegBytea; // [esp+24h] [ebp-8h]
  char *pRegByteb; // [esp+24h] [ebp-8h]
  const char *pRegBytec; // [esp+24h] [ebp-8h]
  unsigned __int8 DACs; // [esp+2Bh] [ebp-1h]
  unsigned int iRxd; // [esp+34h] [ebp+8h]
  unsigned int iRxe; // [esp+34h] [ebp+8h]
  unsigned int iRx; // [esp+34h] [ebp+8h]
  unsigned int iRxa; // [esp+34h] [ebp+8h]
  unsigned int iRxb; // [esp+34h] [ebp+8h]
  unsigned int iRxc; // [esp+34h] [ebp+8h]
  unsigned __int8 iRx_3; // [esp+37h] [ebp+Bh]

  v8 = Mode;
  if ( !Mode )
  {
    v8 = 251724033;
    Mode = 251724033;
  }
  v9 = v8 & 0xC0000000;
  v10 = v8 & 0x7F;
  OutputMode = v8 & 0xC0000000;
  iCRTC = BYTE1(v8);
  iTV = v8 & 0x7F;
  if ( TVEncoderSMBusID != -32 )
    goto LABEL_16;
  if ( v10 == 1 && BYTE1(v8) == 7 )
  {
    if ( v9 != 0x80000000 )
      goto LABEL_12;
    v10 = 4;
  }
  if ( v9 != 0x80000000 )
  {
LABEL_12:
    if ( XboxGameRegion == 2 )
      v11 = (unsigned __int8)SDTVJapanTable[v10];
    else
      v11 = (unsigned __int8)SDTVTable[v10];
    goto LABEL_15;
  }
  if ( XboxGameRegion == 2 )
    v11 = (unsigned __int8)HDTVJapanTable[v10];
  else
    v11 = (unsigned __int8)HDTVTable[v10];
LABEL_15:
  iTV = v11;
LABEL_16:
  DACs = HIBYTE(v8) & 0xF;
  switch ( Format )
  {
    case 0x10u:
      goto LABEL_220;
    case 0x11u:
      GeneralControl = 1052720;
      HIBYTE(Format) = 2;
      goto LABEL_25;
    case 0x12u:
      goto LABEL_21;
    case 0x1Cu:
LABEL_220:
      HIBYTE(Format) = 2;
      goto LABEL_24;
  }
  if ( Format != 30 )
    goto LABEL_25;
LABEL_21:
  HIBYTE(Format) = 3;
LABEL_24:
  GeneralControl = 1048624;
LABEL_25:
  Pitch >>= 3;
  if ( AvpCurrentMode == v8 )
  {
    if ( Step )
      RtlAssert(a2, v8, (int *)BYTE1(v8), v9, "Step == 0", "d:\\xbox-apr03\\private\\ntos\\av\\modeset.c", 0xCFu, 0);
    *((_DWORD *)RegisterBase + 1704320) = GeneralControl;
    if ( AvpDump )
      DbgPrint((int *)"%08X = %08X\n", "%08X = %08X\n", 6817280, GeneralControl);
    v12 = AvpDump;
    AvpDump = 0;
    *((_BYTE *)RegisterBase + 6296532) = 31;
    Step = v12;
    if ( AvpDump )
      DbgPrint((int *)"%08X = %08X\n", "%08X = %08X\n", 6296532, 31);
    *((_BYTE *)RegisterBase + 6296533) = 87;
    if ( AvpDump )
      DbgPrint((int *)"%08X = %08X\n", "%08X = %08X\n", 6296533, 87);
    AvpDump = Step;
    if ( Step )
      DbgPrint((int *)"%08X = %08X\n", "CR%02X = %02X\n", 31, 87);
    v13 = AvpDump;
    AvpDump = 0;
    *((_BYTE *)RegisterBase + 6296532) = 19;
    Step = v13;
    if ( AvpDump )
      DbgPrint((int *)"%08X = %08X\n", "%08X = %08X\n", 6296532, 19);
    v14 = Pitch;
    *((_BYTE *)RegisterBase + 6296533) = Pitch;
    if ( AvpDump )
      DbgPrint((int *)"%08X = %08X\n", "%08X = %08X\n", 6296533, v14);
    AvpDump = Step;
    if ( Step )
      DbgPrint((int *)"%08X = %08X\n", "CR%02X = %02X\n", 19, (unsigned __int8)Pitch);
    HIBYTE(Pitch) = (Pitch >> 3) & 0xE0;
    v15 = AvpDump;
    AvpDump = 0;
    *((_BYTE *)RegisterBase + 6296532) = 25;
    Step = v15;
    if ( AvpDump )
      DbgPrint((int *)"%08X = %08X\n", "%08X = %08X\n", 6296532, 25);
    v16 = HIBYTE(Pitch);
    *((_BYTE *)RegisterBase + 6296533) = HIBYTE(Pitch);
    if ( AvpDump )
      DbgPrint((int *)"%08X = %08X\n", "%08X = %08X\n", 6296533, v16);
    AvpDump = Step;
    if ( Step )
      DbgPrint((int *)"%08X = %08X\n", "CR%02X = %02X\n", 25, HIBYTE(Pitch));
    HIBYTE(Pitch) = HIBYTE(Format) | 0x80;
    v17 = AvpDump;
    AvpDump = 0;
    *((_BYTE *)RegisterBase + 6296532) = 40;
    Step = v17;
    if ( AvpDump )
      DbgPrint((int *)"%08X = %08X\n", "%08X = %08X\n", 6296532, 40);
    v18 = HIBYTE(Pitch);
    *((_BYTE *)RegisterBase + 6296533) = HIBYTE(Pitch);
    if ( AvpDump )
      DbgPrint((int *)"%08X = %08X\n", "%08X = %08X\n", 6296533, v18);
    AvpDump = Step;
    if ( Step )
      DbgPrint((int *)"%08X = %08X\n", "CR%02X = %02X\n", 40, HIBYTE(Pitch));
    v19 = FrameBuffer;
    *((_DWORD *)RegisterBase + 1573376) = FrameBuffer;
    if ( AvpDump )
      DbgPrint((int *)"%08X = %08X\n", "%08X = %08X\n", 6293504, v19);
    AvSendTVEncoderOption(RegisterBase, 0xBu, 5u, 0);
    AvSendTVEncoderOption(RegisterBase, 0xEu, 0, 0);
    AvpCurrentMode = Mode;
    return 0;
  }
  if ( Step )
  {
    RtlAssert(a2, v8, (int *)BYTE1(v8), v9, "Step == 0", "d:\\xbox-apr03\\private\\ntos\\av\\modeset.c", 0xFAu, 0);
    v8 = Mode;
  }
  AvpCurrentMode = v8;
  if ( TVEncoderSMBusID == -44 )
  {
    v20 = (int *)AvpDump;
    v9 = 160;
    AvpDump = 0;
    HalReadSMBusValue(a2, v8, v20, 160, 212, 160, 1, &Step);
    v21 = (unsigned __int16)Step | 0xF;
    Step = (unsigned __int16)Step | 0xF;
    AvpDump = 0;
    HalWriteSMBusValue(v22, v23, v20, 160, TVEncoderSMBusID, 160, 1, v21);
    AvpDump = (unsigned int)v20;
    if ( v20 )
      DbgPrint(v20, "TV%04X = %04X\n", 160, Step);
  }
  if ( TVEncoderSMBusID == -32 )
  {
    v24 = (int *)AvpDump;
    AvpDump = 0;
    HalReadSMBusValue(a2, v8, v24, v9, 224, 4, 1, &Step);
    v25 = Step | 0xF;
    AvpDump = 0;
    HalWriteSMBusValue(v26, v27, v24, Step | 0xF, TVEncoderSMBusID, 4, 1, Step | 0xF);
    AvpDump = (unsigned int)v24;
    if ( v24 )
      DbgPrint(v24, "TV%04X = %04X\n", 4, v25);
    v30 = (int *)AvpDump;
    AvpDump = 0;
    HalReadSMBusValue(v28, v29, v30, v25, TVEncoderSMBusID, 0, 1, &Step);
    v31 = Step & 0xFFFFFFFD;
    AvpDump = 0;
    HalWriteSMBusValue(v32, v33, v30, Step & 0xFFFFFFFD, TVEncoderSMBusID, 0, 1, Step & 0xFFFFFFFD);
    AvpDump = (unsigned int)v30;
    if ( v30 )
      DbgPrint(v30, "TV%04X = %04X\n", 0, v31);
  }
  v34 = (char *)RegisterBase;
  __outbyte(0x80D3u, 5u);
  do
    LgsValue = *((_DWORD *)RegisterBase + 1704360);
  while ( ((unsigned __int8)~(_BYTE)LgsValue ^ (unsigned __int8)~(*((_DWORD *)RegisterBase + 1704360) >> 4)) & 1 );
  v35 = AvpDump;
  AvpDump = 0;
  *((_BYTE *)RegisterBase + 6296532) = 31;
  Step = v35;
  if ( AvpDump )
    DbgPrint((int *)"%08X = %08X\n", "%08X = %08X\n", 6296532, 31);
  *((_BYTE *)RegisterBase + 6296533) = 87;
  if ( AvpDump )
    DbgPrint((int *)"%08X = %08X\n", "%08X = %08X\n", 6296533, 87);
  AvpDump = Step;
  if ( Step )
    DbgPrint((int *)"%08X = %08X\n", "CR%02X = %02X\n", 31, 87);
  v36 = AvpDump;
  AvpDump = 0;
  *((_BYTE *)RegisterBase + 6296532) = 33;
  Step = v36;
  if ( AvpDump )
    DbgPrint((int *)"%08X = %08X\n", "%08X = %08X\n", 6296532, 33);
  *((_BYTE *)RegisterBase + 6296533) = -1;
  if ( AvpDump )
    DbgPrint((int *)"%08X = %08X\n", "%08X = %08X\n", 6296533, 255);
  AvpDump = Step;
  if ( Step )
    DbgPrint((int *)"%08X = %08X\n", "CR%02X = %02X\n", 33, 255);
  v37 = AvpDump;
  AvpDump = 0;
  *((_BYTE *)RegisterBase + 6296532) = 40;
  Step = v37;
  if ( AvpDump )
    DbgPrint((int *)"%08X = %08X\n", "%08X = %08X\n", 6296532, 40);
  *((_BYTE *)RegisterBase + 6296533) = 0;
  if ( AvpDump )
    DbgPrint((int *)"%08X = %08X\n", "%08X = %08X\n", 6296533, 0);
  AvpDump = Step;
  if ( Step )
    DbgPrint((int *)"%08X = %08X\n", "CR%02X = %02X\n", 40, 0);
  *((_DWORD *)RegisterBase + 1704480) = 554832145;
  if ( AvpDump )
    DbgPrint((int *)"%08X = %08X\n", "%08X = %08X\n", 6817920, 554832145);
  if ( TVEncoderSMBusID == -118 )
  {
    SMB_WR((int *)0xBA, (int)RegisterBase, RegisterBase, 186, 128);
    SMB_WR((int *)0xBA, (int)RegisterBase, RegisterBase, 186, 63);
    SMB_WR((int *)0xBA, (int)RegisterBase, RegisterBase, 108, 70);
  }
  KeStallExecutionProcessor(1u);
  if ( TVEncoderSMBusID == -118 )
    SMB_WR((int *)0xBA, (int)RegisterBase, RegisterBase, 108, 198);
  if ( OutputMode == 0x80000000 )
  {
    if ( TVEncoderSMBusID != -32 )
    {
      v39 = &AV_TABLE_HDTVREGISTERS_DATA[iTV * AvpTableRowSize[2]];
      v40 = (unsigned int)&v39[AvpTableRowSize[2]];
      pByteMax = &v39[AvpTableRowSize[2]];
      pRegByte = AV_TABLE_HDTVREGISTERS_DATA;
      if ( (unsigned int)v39 < v40 )
      {
        do
        {
          SMB_WR((int *)v39, (int)RegisterBase, RegisterBase, *pRegByte, *v39);
          ++v39;
          ++pRegByte;
        }
        while ( v39 < pByteMax );
      }
      goto LABEL_115;
    }
  }
  else if ( TVEncoderSMBusID != -32 )
  {
    v41 = *AvpTableRowSize;
    v42 = (int *)&AV_TABLE_COMMONTVREGISTERS_DATA[v41];
    pByteMaxa = &AV_TABLE_COMMONTVREGISTERS_DATA[v41 + v41];
    pRegBytea = AV_TABLE_COMMONTVREGISTERS_DATA;
    if ( &AV_TABLE_COMMONTVREGISTERS_DATA[v41] < pByteMaxa )
    {
      do
      {
        SMB_WR(v42, (int)RegisterBase, RegisterBase, *pRegBytea, *(_BYTE *)v42);
        v42 = (int *)((char *)v42 + 1);
        ++pRegBytea;
      }
      while ( v42 < (int *)pByteMaxa );
    }
  }
  v39 = &AV_TABLE_TVREGISTERS_DATA[iTV * AvpTableRowSize[1]];
  v40 = (unsigned int)&v39[AvpTableRowSize[1]];
  pByteMaxb = &v39[AvpTableRowSize[1]];
  pRegByteb = AV_TABLE_TVREGISTERS_DATA;
  if ( (unsigned int)v39 < v40 )
  {
    do
    {
      SMB_WR((int *)v39, (int)RegisterBase, RegisterBase, *pRegByteb, *v39);
      ++v39;
      ++pRegByteb;
    }
    while ( v39 < pByteMaxb );
  }
  if ( XboxGameRegion == 2 && (iTV == 13 || iTV == 14 || iTV == 18) )
  {
    if ( TVEncoderSMBusID == -32 )
    {
      iRxd = AvpDump;
      AvpDump = 0;
      HalReadSMBusValue(v38, v40, (int *)v39, (int)v34, 224, 1, 1, &Step);
      v39 = (char *)(Step & 0xFFFF7FFF);
      AvpDump = 0;
      HalWriteSMBusValue(v43, v44, (int *)(Step & 0xFFFF7FFF), (int)v34, TVEncoderSMBusID, 1, 1, Step & 0xFFFF7FFF);
      AvpDump = iRxd;
      if ( iRxd )
        DbgPrint((int *)v39, "TV%04X = %04X\n", 1, v39);
    }
    else if ( TVEncoderSMBusID == -44 )
    {
      v39 = (char *)316;
      Step = AvpDump;
      AvpDump = 0;
      HalWriteSMBusValue(v38, v40, (int *)0x13C, (int)RegisterBase, 212, 78, 1, 0x13Cu);
      AvpDump = Step;
      if ( Step )
        DbgPrint((int *)0x13C, "TV%04X = %04X\n", 78, 316);
    }
    else
    {
      SMB_WR((int *)v39, (int)RegisterBase, RegisterBase, 162, 8);
      SMB_WR((int *)v39, (int)RegisterBase, RegisterBase, 164, 240);
      SMB_WR((int *)v39, (int)RegisterBase, RegisterBase, 172, 154);
    }
  }
LABEL_115:
  pByteMaxc = (const char *)(Mode & 0x20000000);
  if ( Mode & 0x20000000 )
    AvpEnableSCART(v38, v40, (int)v34, v34, iTV);
  if ( TVEncoderSMBusID == -32 )
  {
    if ( OutputMode == 0x80000000 )
    {
      v39 = (char *)AvpDump;
      AvpDump = 0;
      HalWriteSMBusValue(v38, v40, (int *)v39, (int)v34, 224, 7, 1, 0);
      AvpDump = (unsigned int)v39;
      if ( !v39 )
        goto LABEL_122;
      DbgPrint((int *)v39, "TV%04X = %04X\n", 7, 0);
    }
    if ( !OutputMode )
    {
LABEL_124:
      iRxe = AvpDump;
      AvpDump = 0;
      HalReadSMBusValue(v38, v40, (int *)v39, (int)v34, TVEncoderSMBusID, 0, 1, &Step);
      v45 = (int *)(Step | 2);
      AvpDump = 0;
      HalWriteSMBusValue(v46, v47, (int *)(Step | 2), (int)v34, TVEncoderSMBusID, 0, 1, Step | 2);
      AvpDump = iRxe;
      if ( iRxe )
        DbgPrint(v45, "TV%04X = %04X\n", 0, v45);
      WriteMVReg(v49, v48, v34, 15, 0);
      goto LABEL_127;
    }
LABEL_122:
    v39 = (char *)AvpDump;
    AvpDump = 0;
    HalWriteSMBusValue(v38, v40, (int *)v39, (int)v34, TVEncoderSMBusID, 9, 1, 0);
    AvpDump = (unsigned int)v39;
    if ( v39 )
      DbgPrint((int *)v39, "TV%04X = %04X\n", 9, 0);
    goto LABEL_124;
  }
LABEL_127:
  __outbyte(0x80D6u, (Mode >> 28) & 1 | 4);
  __outbyte(0x80D8u, 4u);
  v50 = AvpDump;
  AvpDump = 0;
  Step = v50;
  v51 = *((_DWORD *)v34 + 1704259) | 0x10020000;
  *((_DWORD *)v34 + 1704259) = v51;
  if ( AvpDump )
    DbgPrint((int *)0x10020000, "%08X = %08X\n", 6817036, v51);
  AvpDump = Step;
  if ( Step )
    DbgPrint((int *)0x10020000, "%08X = %08X (read modify write)\n", 6817036, 268566528);
  v34[787395] = 1;
  if ( AvpDump )
    DbgPrint((int *)0x10020000, "%08X = %08X\n", 787395, 1);
  v34[787394] = -29;
  if ( AvpDump )
    DbgPrint((int *)0x10020000, "%08X = %08X\n", 787394, 227);
  *((_DWORD *)v34 + 1704320) = GeneralControl;
  if ( AvpDump )
    DbgPrint((int *)0x10020000, "%08X = %08X\n", 6817280, GeneralControl);
  v52 = (int *)&AV_TABLE_DACREGISTERS_DATA[BYTE2(Mode) * AvpTableRowSize[5]];
  v53 = (unsigned int)&v52[(unsigned int)AvpTableRowSize[5] >> 2];
  iRx = (unsigned int)&v52[(unsigned int)AvpTableRowSize[5] >> 2];
  Step = (unsigned int)AV_TABLE_DACREGISTERS_DATA;
  if ( (unsigned int)v52 < v53 )
  {
    do
    {
      v54 = *v52;
      v55 = *(_DWORD *)Step;
      *(_DWORD *)&v34[*(_DWORD *)Step] = *v52;
      if ( AvpDump )
        DbgPrint(v52, "%08X = %08X\n", v55, v54);
      Step += 4;
      ++v52;
    }
    while ( (unsigned int)v52 < iRx );
  }
  if ( pByteMaxc )
  {
    *((_DWORD *)v34 + 1704332) = 0;
    if ( AvpDump )
      DbgPrint(v52, "%08X = %08X\n", 6817328, 0);
    *((_DWORD *)v34 + 1704497) = 0;
    if ( AvpDump )
      DbgPrint(v52, "%08X = %08X\n", 6817988, 0);
    *((_DWORD *)v34 + 1704467) = 0;
    if ( AvpDump )
      DbgPrint(v52, "%08X = %08X\n", 6817868, 0);
  }
  v56 = 0;
  iRxa = 0;
  do
  {
    v57 = (int *)AvpDump;
    v58 = AvpSRXRegisters[v56];
    AvpDump = 0;
    v34[787396] = v56;
    HIBYTE(Step) = v58;
    if ( AvpDump )
      DbgPrint(v57, "%08X = %08X\n", 787396, (unsigned __int8)iRxa);
    v59 = HIBYTE(Step);
    v34[787397] = HIBYTE(Step);
    if ( AvpDump )
      DbgPrint(v57, "%08X = %08X\n", 787397, v59);
    AvpDump = (unsigned int)v57;
    if ( v57 )
      DbgPrint(v57, "SR%02X = %02X\n", (unsigned __int8)iRxa, HIBYTE(Step));
    v56 = iRxa + 1;
    v60 = &AvpSRXRegisters[iRxa++ + 1];
  }
  while ( v60 < byte_80019821 );
  v61 = 0;
  iRxb = 0;
  do
  {
    v62 = (int *)AvpDump;
    v63 = AvpGRXRegisters[v61];
    AvpDump = 0;
    v34[787406] = v61;
    HIBYTE(Step) = v63;
    if ( AvpDump )
      DbgPrint(v62, "%08X = %08X\n", 787406, (unsigned __int8)iRxb);
    v64 = HIBYTE(Step);
    v34[787407] = HIBYTE(Step);
    if ( AvpDump )
      DbgPrint(v62, "%08X = %08X\n", 787407, v64);
    AvpDump = (unsigned int)v62;
    if ( v62 )
      DbgPrint(v62, "GR%02X = %02X\n", (unsigned __int8)iRxb, HIBYTE(Step));
    v61 = iRxb + 1;
    v65 = &AvpGRXRegisters[iRxb++ + 1];
  }
  while ( v65 < byte_80019819 );
  v66 = 0;
  iRxc = 0;
  do
  {
    HIBYTE(Step) = AvpARXRegisters[v66];
    v67 = AvpDump;
    AvpDump = 0;
    v34[6296512] = v66;
    OutputModea = v67;
    if ( AvpDump )
      DbgPrint((int *)0x6013C0, "%08X = %08X\n", 6296512, (unsigned __int8)iRxc);
    v68 = HIBYTE(Step);
    v34[6296512] = HIBYTE(Step);
    if ( AvpDump )
      DbgPrint((int *)0x6013C0, "%08X = %08X\n", 6296512, v68);
    AvpDump = OutputModea;
    if ( OutputModea )
      DbgPrint((int *)0x6013C0, "AR%02X = %02X\n", (unsigned __int8)iRxc, HIBYTE(Step));
    v66 = iRxc + 1;
    v69 = &AvpARXRegisters[iRxc++ + 1];
  }
  while ( v69 < byte_8001980D );
  v34[6296512] = 32;
  if ( AvpDump )
    DbgPrint((int *)0x6013C0, "%08X = %08X\n", 6296512, 32);
  v70 = (int *)AvpDump;
  AvpDump = 0;
  v34[6296532] = 17;
  if ( AvpDump )
    DbgPrint(v70, "%08X = %08X\n", 6296532, 17);
  v34[6296533] = 0;
  if ( AvpDump )
    DbgPrint(v70, "%08X = %08X\n", 6296533, 0);
  AvpDump = (unsigned int)v70;
  if ( v70 )
    DbgPrint(v70, "CR%02X = %02X\n", 17, 0);
  v71 = (int *)&AV_TABLE_CRTCREGISTERS_DATA[iCRTC * AvpTableRowSize[6]];
  pByteMaxd = (char *)v71 + AvpTableRowSize[6];
  pRegBytec = AV_TABLE_CRTCREGISTERS_DATA;
  if ( v71 < (int *)((char *)v71 + AvpTableRowSize[6]) )
  {
    do
    {
      v72 = *pRegBytec;
      v73 = *pRegBytec == 19;
      iRx_3 = *pRegBytec;
      HIBYTE(Step) = *(_BYTE *)v71;
      if ( v73 )
      {
        HIBYTE(Step) = Pitch;
      }
      else
      {
        if ( v72 == 25 )
        {
          v74 = (Pitch >> 3) & 0xE0;
LABEL_187:
          HIBYTE(Step) |= v74;
          goto LABEL_188;
        }
        if ( v72 == 37 )
        {
          v74 = (Pitch >> 6) & 0x20;
          goto LABEL_187;
        }
      }
LABEL_188:
      v75 = AvpDump;
      AvpDump = 0;
      v34[6296532] = v72;
      iCRTCa = v75;
      if ( AvpDump )
        DbgPrint(v71, "%08X = %08X\n", 6296532, iRx_3);
      v76 = HIBYTE(Step);
      v34[6296533] = HIBYTE(Step);
      if ( AvpDump )
        DbgPrint(v71, "%08X = %08X\n", 6296533, v76);
      AvpDump = iCRTCa;
      if ( iCRTCa )
        DbgPrint(v71, "CR%02X = %02X\n", iRx_3, HIBYTE(Step));
      v71 = (int *)((char *)v71 + 1);
      ++pRegBytec;
    }
    while ( v71 < (int *)pByteMaxd );
  }
  v77 = ~(_BYTE)LgsValue & 1;
  *((_DWORD *)v34 + 1704360) = v77;
  if ( AvpDump )
    DbgPrint(v71, "%08X = %08X\n", 6817440, v77);
  v78 = (int *)AvpDump;
  AvpDump = 0;
  v79 = HIBYTE(Format) | 0x80;
  v34[6296532] = 40;
  HIBYTE(Pitch) = v79;
  if ( AvpDump )
    DbgPrint(v78, "%08X = %08X\n", 6296532, 40);
  v80 = HIBYTE(Pitch);
  v34[6296533] = HIBYTE(Pitch);
  if ( AvpDump )
    DbgPrint(v78, "%08X = %08X\n", 6296533, v80);
  AvpDump = (unsigned int)v78;
  if ( v78 )
    DbgPrint(v78, "CR%02X = %02X\n", 40, HIBYTE(Pitch));
  v81 = 0;
  v82 = v34 + 6296538;
  do
  {
    while ( *v82 & 8 )
      ;
    while ( !(*v82 & 8) )
      ;
    ++v81;
  }
  while ( v81 < 3 );
  v83 = *(_DWORD *)(4 * BYTE2(Mode) - 2147172064);
  *((_DWORD *)v34 + 1704480) = v83;
  if ( AvpDump )
    DbgPrint(v78, "%08X = %08X\n", 6817920, v83);
  KeStallExecutionProcessor(1u);
  if ( TVEncoderSMBusID == -118 )
  {
    v78 = (int *)AvpDump;
    AvpDump = 0;
    HalReadSMBusValue(v84, v85, v78, (int)v34, 138, 108, 0, &Pitch);
    AvpDump = (unsigned int)v78;
    SMB_WR(v78, (int)v34, v34, 108, Pitch | 0x80);
    SMB_WR(v78, (int)v34, v34, 186, DACs | 0x20);
  }
  if ( TVEncoderSMBusID == -32 )
  {
    v78 = (int *)AvpDump;
    AvpDump = 0;
    HalWriteSMBusValue(v84, v85, v78, (int)v34, 224, 4, 1, DACs);
    AvpDump = (unsigned int)v78;
    if ( v78 )
      DbgPrint(v78, "TV%04X = %04X\n", 4, DACs);
  }
  v86 = FrameBuffer;
  *((_DWORD *)v34 + 1573376) = FrameBuffer;
  if ( AvpDump )
    DbgPrint(v78, "%08X = %08X\n", 6293504, v86);
  AvpSetWSSBits(v84, v78, (int)v34, v34);
  return 0;
}