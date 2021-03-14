void __stdcall AvSendTVEncoderOption(void *RegisterBase, unsigned int Option, unsigned int Param, unsigned int *Result)
{
  _BYTE *v4; // edx
  int v5; // esi
  char v6; // bl
  unsigned int v7; // edi
  unsigned int v8; // ecx
  char *v9; // esi
  int *v10; // edi
  unsigned int v11; // ST0C_4
  int v12; // edx
  int v13; // ecx
  int v14; // esi
  int *v15; // edi
  unsigned int v16; // esi
  int v17; // edx
  int v18; // ST0C_4
  int v19; // edx
  int v20; // ecx
  int *v21; // edi
  char *v22; // esi
  int *v23; // edi
  int v24; // esi
  unsigned int v25; // ST0C_4
  int v26; // edx
  int v27; // ecx
  int *v28; // edi
  signed int v29; // esi
  char v30; // al
  int v31; // esi
  unsigned int *v32; // esi
  bool v33; // zf
  unsigned __int16 v34; // cx
  int v35; // esi
  char v36; // al
  char v37; // al
  unsigned int *v38; // esi
  int v39; // edx
  int v40; // ecx
  int v41; // edx
  int v42; // ecx
  int v43; // edx
  int v44; // ecx
  int v45; // edx
  int v46; // ecx
  int v47; // edx
  int v48; // ecx
  int v49; // edx
  int v50; // ecx
  unsigned int *v51; // esi
  int *v52; // edi
  int v53; // edx
  int v54; // ecx
  int *v55; // edi
  int v56; // esi
  unsigned int v57; // eax
  int v58; // eax
  unsigned int *v59; // eax
  int v60; // esi
  unsigned int *v61; // eax
  signed int v62; // edx
  signed int v63; // ecx
  signed int v64; // ecx
  const unsigned int *v65; // ecx
  int *v66; // edi
  unsigned int v67; // ecx
  int v68; // ecx
  int v69; // edx
  int v70; // ecx
  int *v71; // edi
  int v72; // esi
  char v73; // al
  int v74; // esi
  unsigned int v75; // ecx
  int v76; // eax
  char *v77; // esi
  int *v78; // edi
  char *v79; // esi
  char *v80; // ebx
  unsigned __int8 v81; // al
  signed int v82; // [esp-8h] [ebp-1Ch]
  signed int v83; // [esp-8h] [ebp-1Ch]
  signed int v84; // [esp-4h] [ebp-18h]
  unsigned int v85; // [esp-4h] [ebp-18h]
  int v86; // [esp-4h] [ebp-18h]
  signed int v87; // [esp-4h] [ebp-18h]
  unsigned int v88; // [esp+10h] [ebp-4h]

  v4 = RegisterBase;
  v5 = AvpCurrentMode;
  v6 = 0;
  v7 = AvpCurrentMode & 0x7F;
  v8 = AvpCurrentMode & 0xC0000000;
  v88 = AvpCurrentMode & 0x7F;
  if ( !RegisterBase )
  {
    RegisterBase = (void *)-50331648;
    v4 = (_BYTE *)-50331648;
  }
  switch ( Option )
  {
    case 1u:
      v16 = Param;
      AvpSetMacrovisionMode(v8, (int)v4, v4, Param);
      AvpMacrovisionMode = v16;
      return;
    case 2u:
      if ( !v8 )
      {
        if ( TVEncoderSMBusID == -44 )
        {
          v7 = AvpDump;
          AvpDump = 0;
          HalReadSMBusValue((int)v4, (int)&Param, (int *)v7, 178, 212, 178, 1, &Param);
          v18 = (unsigned __int16)Param | 0xC000;
          Param = (unsigned __int16)Param | 0xC000;
          AvpDump = 0;
          HalWriteSMBusValue(v19, v20, (int *)v7, 178, TVEncoderSMBusID, 178, 1, v18);
          AvpDump = v7;
          if ( v7 )
          {
            v85 = Param;
            goto LABEL_24;
          }
        }
        else if ( TVEncoderSMBusID == -118 )
        {
          v21 = (int *)AvpDump;
          AvpDump = 0;
          HalReadSMBusValue((int)v4, (unsigned __int8)TVEncoderSMBusID, v21, 196, 138, 196, 0, &Param);
          AvpDump = (unsigned int)v21;
          SMB_WR(v21, 196, RegisterBase, 196, Param | 0x38);
          v22 = (char *)(4 * v88 - 2147379288);
          v23 = (int *)(v22 + 4);
          if ( v22 < v22 + 4 )
          {
            do
            {
              SMB_WR(v23, (int)v22, RegisterBase, v22[-4 * v88], *v22);
              ++v22;
            }
            while ( v22 < (char *)v23 );
          }
        }
        else
        {
          v24 = AvpDump;
          AvpDump = 0;
          HalWriteSMBusValue((int)v4, (unsigned __int8)TVEncoderSMBusID, (int *)v7, v24, TVEncoderSMBusID, 9, 1, 7u);
          AvpDump = v24;
          if ( v24 )
          {
            v85 = 7;
            goto LABEL_40;
          }
        }
      }
      return;
    case 3u:
      if ( !v8 )
      {
        if ( TVEncoderSMBusID == -44 )
        {
          v7 = AvpDump;
          AvpDump = 0;
          HalReadSMBusValue((int)v4, (int)&Param, (int *)v7, 178, 212, 178, 1, &Param);
          v25 = Param & 0x3FFF;
          Param &= 0x3FFFu;
          AvpDump = 0;
          HalWriteSMBusValue(v26, v27, (int *)v7, 178, TVEncoderSMBusID, 178, 1, v25);
          AvpDump = v7;
          if ( v7 )
          {
            v85 = Param;
LABEL_24:
            v83 = 178;
            goto LABEL_143;
          }
        }
        else
        {
          if ( TVEncoderSMBusID == -118 )
          {
            v28 = (int *)AvpDump;
            v29 = 196;
            AvpDump = 0;
            HalReadSMBusValue((int)v4, (unsigned __int8)TVEncoderSMBusID, v28, 196, 138, 196, 0, &Param);
            v30 = Param & 0xCF;
            goto LABEL_37;
          }
          v31 = AvpDump;
          AvpDump = 0;
          HalWriteSMBusValue((int)v4, (unsigned __int8)TVEncoderSMBusID, (int *)v7, v31, TVEncoderSMBusID, 9, 1, 0);
          AvpDump = v31;
          if ( v31 )
          {
            v85 = 0;
LABEL_40:
            v83 = 9;
            goto LABEL_143;
          }
        }
      }
      return;
    case 4u:
      if ( v8 )
        return;
      v32 = Result;
      if ( TVEncoderSMBusID != -44 )
      {
        if ( TVEncoderSMBusID == -118 )
        {
          v36 = *((_BYTE *)Result + 2);
          if ( Param & 1 )
          {
            SMB_WR((int *)v7, (int)Result, v4, 192, v36);
            SMB_WR((int *)v7, (int)v32, RegisterBase, 194, *(_BYTE *)v32);
          }
          else
          {
            SMB_WR((int *)v7, (int)Result, v4, 188, v36);
            SMB_WR((int *)v7, (int)v32, RegisterBase, 190, *(_BYTE *)v32);
          }
          return;
        }
        v7 = 1;
        RegisterBase = (void *)(*(_BYTE *)Result & 0x7F);
        v37 = *((_BYTE *)Result + 2);
        v38 = (unsigned int *)AvpDump;
        AvpDump = 0;
        Result = v38;
        v33 = (Param & 1) == 0;
        v86 = v37 & 0x7F;
        Param = v37 & 0x7F;
        if ( v33 )
        {
          HalWriteSMBusValue(
            (int)v4,
            (unsigned __int8)TVEncoderSMBusID,
            (int *)1,
            (int)v38,
            TVEncoderSMBusID,
            10,
            1,
            v86);
          AvpDump = (unsigned int)v38;
          v9 = "TV%04X = %04X\n";
          if ( Result )
            DbgPrint((int *)1, "TV%04X = %04X\n", 10, Param);
          Param = AvpDump;
          AvpDump = 0;
          HalWriteSMBusValue(v45, v46, (int *)1, (int)"TV%04X = %04X\n", TVEncoderSMBusID, 11, 1, 4u);
          AvpDump = Param;
          if ( Param )
            DbgPrint((int *)1, "TV%04X = %04X\n", 11, 4);
          Result = (unsigned int *)AvpDump;
          Param = (unsigned __int16)RegisterBase;
          AvpDump = 0;
          HalWriteSMBusValue(
            v47,
            v48,
            (int *)1,
            (int)"TV%04X = %04X\n",
            TVEncoderSMBusID,
            10,
            1,
            (unsigned __int16)RegisterBase);
          AvpDump = (unsigned int)Result;
          if ( Result )
            DbgPrint((int *)1, "TV%04X = %04X\n", 10, Param);
          Param = AvpDump;
          AvpDump = 0;
          HalWriteSMBusValue(v49, v50, (int *)1, (int)"TV%04X = %04X\n", TVEncoderSMBusID, 11, 1, 8u);
          AvpDump = Param;
          if ( !Param )
            return;
          v84 = 8;
        }
        else
        {
          HalWriteSMBusValue(
            (int)v4,
            (unsigned __int8)TVEncoderSMBusID,
            (int *)1,
            (int)v38,
            TVEncoderSMBusID,
            10,
            1,
            v86);
          AvpDump = (unsigned int)v38;
          v9 = "TV%04X = %04X\n";
          if ( Result )
            DbgPrint((int *)1, "TV%04X = %04X\n", 10, Param);
          Param = AvpDump;
          AvpDump = 0;
          HalWriteSMBusValue(v39, v40, (int *)1, (int)"TV%04X = %04X\n", TVEncoderSMBusID, 11, 1, 1u);
          AvpDump = Param;
          if ( Param )
            DbgPrint((int *)1, "TV%04X = %04X\n", 11, 1);
          Result = (unsigned int *)AvpDump;
          Param = (unsigned __int16)RegisterBase;
          AvpDump = 0;
          HalWriteSMBusValue(
            v41,
            v42,
            (int *)1,
            (int)"TV%04X = %04X\n",
            TVEncoderSMBusID,
            10,
            1,
            (unsigned __int16)RegisterBase);
          AvpDump = (unsigned int)Result;
          if ( Result )
            DbgPrint((int *)1, "TV%04X = %04X\n", 10, Param);
          Param = AvpDump;
          AvpDump = 0;
          HalWriteSMBusValue(v43, v44, (int *)1, (int)"TV%04X = %04X\n", TVEncoderSMBusID, 11, 1, 2u);
          AvpDump = Param;
          if ( !Param )
            return;
          v84 = 2;
        }
        v82 = 11;
        goto LABEL_70;
      }
      HIBYTE(v34) = *((_BYTE *)Result + 2);
      v33 = (Param & 1) == 0;
      LOBYTE(v34) = *(_BYTE *)Result;
      v35 = AvpDump;
      AvpDump = 0;
      Param = v34;
      if ( v33 )
        v7 = 176;
      else
        v7 = 174;
      HalWriteSMBusValue((int)v4, v34, (int *)v7, v35, 212, v7, 1, v34);
      AvpDump = v35;
      if ( v35 )
      {
        v85 = Param;
        goto LABEL_142;
      }
      return;
    case 5u:
      if ( v8 )
        goto $L28668;
      if ( TVEncoderSMBusID == -44 )
      {
        v51 = Result;
        *Result = 0;
        v52 = (int *)AvpDump;
        AvpDump = 0;
        HalReadSMBusValue((int)v4, 0, v52, (int)v51, TVEncoderSMBusID, 174, 1, &Param);
        AvpDump = (unsigned int)v52;
        if ( (_WORD)Param )
          *v51 |= 1u;
        v55 = (int *)AvpDump;
        AvpDump = 0;
        HalReadSMBusValue(v53, v54, v55, (int)v51, TVEncoderSMBusID, 176, 1, &Param);
        AvpDump = (unsigned int)v55;
        if ( (_WORD)Param )
          *v51 |= 2u;
      }
      else
      {
        v56 = AvpDump;
        AvpDump = 0;
        if ( TVEncoderSMBusID == -118 )
        {
          HalReadSMBusValue((int)v4, 0, (int *)v7, v56, 138, 2, 0, &Param);
          v57 = (unsigned int)(unsigned __int8)Param >> 2;
        }
        else
        {
          HalReadSMBusValue((int)v4, (int)&Param, (int *)v7, v56, TVEncoderSMBusID, 20, 1, &Param);
          LOBYTE(v57) = ~(_BYTE)Param;
        }
        AvpDump = v56;
        v58 = v57 & 3;
LABEL_81:
        *Result = v58;
      }
      return;
    case 6u:
      v58 = AvpQueryAvCapabilities();
      AvpCapabilities = v58;
      goto LABEL_81;
    case 9u:
      v4[787396] = 1;
      v9 = "%08X = %08X\n";
      if ( AvpDump )
      {
        DbgPrint((int *)v7, "%08X = %08X\n", 787396, 1);
        v4 = RegisterBase;
      }
      if ( !Param )
      {
        v4[787397] = 1;
        if ( AvpDump )
          DbgPrint((int *)v7, "%08X = %08X\n", 787397, 1);
        LOBYTE(v8) = TVEncoderSMBusID;
        if ( TVEncoderSMBusID == -44 )
        {
          v10 = (int *)AvpDump;
          AvpDump = 0;
          HalReadSMBusValue((int)v4, (int)&Param, v10, 160, 212, 160, 1, &Param);
          v11 = Param & 0xFFF0;
          Param &= 0xFFF0u;
          AvpDump = 0;
          HalWriteSMBusValue(v12, v13, v10, 160, TVEncoderSMBusID, 160, 1, v11);
          AvpDump = (unsigned int)v10;
          if ( v10 )
            DbgPrint(v10, "TV%04X = %04X\n", 160, Param);
        }
        else if ( TVEncoderSMBusID == -32 )
        {
          v14 = AvpDump;
          AvpDump = 0;
          v15 = (int *)(HIBYTE(AvpCurrentMode) & 0xF);
          HalWriteSMBusValue((int)v4, v8, v15, v14, 224, 4, 1, (unsigned int)v15);
          AvpDump = v14;
          if ( v14 )
            DbgPrint(v15, "TV%04X = %04X\n", 4, v15);
        }
        __outbyte(0x80D3u, 4u);
        return;
      }
      v4[787397] = 33;
      if ( !AvpDump )
        return;
      v84 = 33;
      v82 = 787397;
      goto LABEL_70;
    case 0xAu:
      AvpCommitMacrovisionMode((int)v4, v8, (const char *)AvpCurrentMode, v4, Param);
      AvpSetWSSBits(v17, (int *)v7, v5, RegisterBase);
      return;
    case 0xBu:
      if ( TVEncoderSMBusID == -44 )
      {
        if ( Param )
        {
          if ( Param <= 0 || Param > 2 )
            LOBYTE(Result) = 16;
          else
            LOBYTE(Result) = 13;
        }
        else
        {
          LOBYTE(Result) = 0;
        }
        SMB_WR((int *)v7, AvpCurrentMode, v4, 38, (char)Result);
        SMB_WR((int *)v7, v5, RegisterBase, 39, 0);
        return;
      }
      if ( TVEncoderSMBusID != -32 )
      {
        if ( Param )
        {
          switch ( Param )
          {
            case 1u:
              LOBYTE(Result) = 1;
              break;
            case 2u:
              LOBYTE(Result) = 2;
              break;
            case 3u:
              LOBYTE(Result) = 3;
              break;
            default:
              LOBYTE(Result) = 0;
              break;
          }
          v71 = (int *)AvpDump;
          AvpDump = 0;
          HalReadSMBusValue((int)v4, (int)&Option, v71, 200, TVEncoderSMBusID, 200, 0, &Option);
          AvpDump = (unsigned int)v71;
          SMB_WR(v71, 200, RegisterBase, 200, (unsigned __int8)Result | 8 * (_BYTE)Result | Option & 0x80);
          if ( Param == 5 )
            v6 = -128;
          SMB_WR(v71, 200, RegisterBase, 52, v6);
        }
        else
        {
          v28 = (int *)AvpDump;
          v29 = 200;
          AvpDump = 0;
          HalReadSMBusValue((int)v4, (int)&Param, v28, 200, TVEncoderSMBusID, 200, 0, &Param);
          v30 = Param | 0x40;
LABEL_37:
          AvpDump = (unsigned int)v28;
          SMB_WR(v28, v29, RegisterBase, v29, v30);
        }
        return;
      }
      if ( v8 == 0x80000000 )
        return;
      v60 = AvpDump;
      AvpDump = 0;
      HalReadSMBusValue((int)v4, v8, (int *)1, v60, 224, 96, 1, (unsigned int *)&RegisterBase);
      v61 = (unsigned int *)v60;
      v62 = 1;
      if ( ((unsigned int)RegisterBase & 0xC00000) != 0x800000 )
        v62 = 0;
      if ( Param )
      {
        if ( Param != 1 )
        {
          if ( Param != 2 )
          {
            if ( Param == 3 )
            {
              if ( v62 )
              {
                v87 = 3;
LABEL_107:
                v63 = v87;
                goto LABEL_110;
              }
            }
            else if ( v62 )
            {
              v87 = 4;
              goto LABEL_107;
            }
LABEL_106:
            v87 = 2;
            goto LABEL_107;
          }
          if ( v62 )
            goto LABEL_106;
        }
        v63 = 1;
      }
      else
      {
        v63 = 0;
      }
LABEL_110:
      v64 = v63;
      if ( v62 )
        v65 = XCalibur_RSM53Regs[v64];
      else
        v65 = XCalibur_RSMRegs[v64];
      Param = (unsigned int)v65;
      v66 = 0;
      v9 = "TV%04X = %04X\n";
      do
      {
        v67 = *(_DWORD *)(Param + 4 * (_DWORD)v66);
        LOBYTE(v62) = XCalibur_RSMRegAddr[(_DWORD)v66];
        Result = v61;
        LOBYTE(RegisterBase) = v62;
        Option = v67;
        AvpDump = 0;
        HalWriteSMBusValue(v62, v67, v66, (int)"TV%04X = %04X\n", TVEncoderSMBusID, v62, 1, v67);
        v61 = Result;
        AvpDump = (unsigned int)Result;
        if ( Result )
        {
          DbgPrint(v66, "TV%04X = %04X\n", (unsigned __int8)RegisterBase, Option);
          v61 = (unsigned int *)AvpDump;
        }
        v66 = (int *)((char *)v66 + 1);
      }
      while ( (unsigned int)v66 < 7 );
      if ( AvpCurrentMode & 0x20000000 )
      {
        RegisterBase = v61;
        AvpDump = 0;
        HalReadSMBusValue(v62, v68, v66, (int)"TV%04X = %04X\n", TVEncoderSMBusID, 96, 1, &Param);
        v7 = Param & 0xFEFFFFFF;
        AvpDump = 0;
        HalWriteSMBusValue(
          v69,
          v70,
          (int *)(Param & 0xFEFFFFFF),
          (int)"TV%04X = %04X\n",
          TVEncoderSMBusID,
          96,
          1,
          Param & 0xFEFFFFFF);
        AvpDump = (unsigned int)RegisterBase;
        if ( RegisterBase )
        {
          v84 = v7;
          v82 = 96;
LABEL_70:
          DbgPrint((int *)v7, v9, v82, v84);
        }
      }
      return;
    case 0xCu:
      AvpCurrentMode = 0;
      return;
    case 0xDu:
      *Result = AvpCurrentMode;
      return;
    case 0xEu:
      LOBYTE(v4) = TVEncoderSMBusID;
      if ( TVEncoderSMBusID == -118 )
      {
        v72 = AvpDump;
        AvpDump = 0;
        HalReadSMBusValue((int)v4, v8, (int *)0x96, v72, 138, 150, 0, (unsigned int *)&Result);
        v73 = (unsigned __int8)Result & 0xF;
        AvpDump = v72;
        LOBYTE(Result) = (unsigned __int8)Result & 0xF;
        if ( Param )
          LOBYTE(Result) = v73 | 0x10;
        SMB_WR((int *)0x96, v72, RegisterBase, 150, (char)Result);
      }
      else if ( TVEncoderSMBusID == -44 )
      {
        v74 = AvpDump;
        v75 = (unsigned __int16)(Param != 0 ? 82 : 238);
        v7 = 194;
        AvpDump = 0;
        Param = (unsigned __int16)(Param != 0 ? 82 : 238);
        HalWriteSMBusValue((int)v4, v75, (int *)0xC2, v74, 212, 194, 1, v75);
        AvpDump = v74;
        if ( v74 )
        {
          v85 = Param;
LABEL_142:
          v83 = v7;
LABEL_143:
          DbgPrint((int *)v7, "TV%04X = %04X\n", v83, v85);
        }
      }
      else
      {
        AvpLumaFilter = Param;
        if ( AvpCurrentMode )
        {
          if ( v8 == 0x80000000 )
          {
            if ( XboxGameRegion == 2 )
              v76 = (unsigned __int8)HDTVJapanTable[v7];
            else
              v76 = (unsigned __int8)HDTVTable[v7];
          }
          else if ( XboxGameRegion == 2 )
          {
            v76 = (unsigned __int8)SDTVJapanTable[v7];
          }
          else
          {
            v76 = (unsigned __int8)SDTVTable[v7];
          }
          v77 = &AV_TABLE_TVREGISTERS_DATA[v76 * AvpTableRowSize[1]];
          v78 = (int *)&v77[AvpTableRowSize[1]];
          v79 = v77 + 24;
          v80 = AV_TABLE_TVREGISTERS_DATA + 24;
          while ( v79 < (char *)v78 )
          {
            SMB_WR(v78, (int)v79, RegisterBase, *v80, *v79);
            ++v79;
            ++v80;
          }
        }
      }
      return;
    case 0xFu:
      v81 = __inbyte(0x80C0u);
      v58 = ~(unsigned __int8)((Option - 1) >> 5) & 1;
      goto LABEL_81;
    case 0x10u:
      if ( TVEncoderSMBusID == -44 )
      {
        *Result = 1;
      }
      else
      {
        v59 = Result;
        if ( TVEncoderSMBusID == -32 )
          *Result = 2;
        else
LABEL_83:
          *v59 = 0;
      }
      return;
    case 0x11u:
$L28668:
      v59 = Result;
      goto LABEL_83;
    case 0x12u:
      AvpCGMS = Param;
      goto LABEL_165;
    case 0x13u:
      v5 = AvpCurrentMode & 0xEFFFFFFF;
      AvpCurrentMode &= 0xEFFFFFFF;
      if ( Param )
      {
        v5 |= 0x10000000u;
        AvpCurrentMode = v5;
      }
LABEL_165:
      AvpSetWSSBits((int)v4, (int *)v7, v5, v4);
      return;
    default:
      return;
  }
}