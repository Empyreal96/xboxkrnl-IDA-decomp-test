int __userpurge UdfxRecognizeVolume@<eax>(int a1@<edx>, int a2@<ecx>, int a3@<esi>, _UDF_VOLUME_EXTENSION *VolumeExtension)
{
  int *v4; // esi
  _UDF_VOLUME_EXTENSION *v6; // eax
  int v7; // eax
  int v8; // edx
  int *v9; // edi
  signed int v10; // ecx
  _BYTE *v11; // esi
  bool v12; // zf
  int v13; // eax
  int v14; // ecx
  char v15; // al
  VSD_GENERIC *VolumeStructureDescriptor; // [esp+8h] [ebp-18h]
  unsigned int v17; // [esp+Ch] [ebp-14h]
  _VSD_IDENT_LOOKUP_TABLE *v18; // [esp+10h] [ebp-10h]
  int status; // [esp+14h] [ebp-Ch]
  unsigned int PhysicalSectorNumber; // [esp+18h] [ebp-8h]
  char FoundBEA; // [esp+1Fh] [ebp-1h]

  v4 = ExAllocatePoolWithTag(a1, a2, a3, 0x800u, 0x73567855u);
  VolumeStructureDescriptor = (VSD_GENERIC *)v4;
  if ( !v4 )
    return -1073741670;
  v6 = VolumeExtension;
  PhysicalSectorNumber = 16;
  FoundBEA = 0;
  if ( VolumeExtension->PhysicalSectorCount <= 0x10 )
  {
LABEL_27:
    status = -1073741489;
  }
  else
  {
    while ( 1 )
    {
      status = UdfxReadPhysicalSector(v6, PhysicalSectorNumber, v4);
      if ( status < 0 )
        break;
      status = -1073741489;
      v7 = 0;
      v8 = (int)v4 + 1;
      v18 = UdfxVsdIdentLookupTable;
      v17 = 0;
      while ( 1 )
      {
        v9 = (int *)v18;
        v10 = 5;
        v11 = (_BYTE *)v8;
        v12 = 1;
        do
        {
          if ( !v10 )
            break;
          v12 = *v11++ == *(_BYTE *)v9;
          v9 = (int *)((char *)v9 + 1);
          --v10;
        }
        while ( v12 );
        if ( v12 )
          break;
        v17 += 6;
        ++v18;
        ++v7;
        if ( v17 >= 0x36 )
          goto LABEL_11;
      }
      v13 = 3 * v7;
      v14 = *(unsigned __int8 *)(2 * v13 - 2147384419);
      if ( !*(_BYTE *)(2 * v13 - 2147384419) )
      {
LABEL_11:
        DbgPrint(v9, "UDFX: unknown VSD identifier\n");
        v4 = (int *)&VolumeStructureDescriptor->Type;
        break;
      }
      v4 = (int *)&VolumeStructureDescriptor->Type;
      v15 = VolumeStructureDescriptor->Type;
      if ( VolumeStructureDescriptor->Type )
      {
        if ( (unsigned __int8)v15 >= 3u && v15 != -1 )
          goto LABEL_40;
        if ( FoundBEA )
        {
          DbgPrint(v9, "UDFX: found unexpected descriptors after BEA01\n");
          break;
        }
        if ( v14 != 3 && v14 != 4 )
        {
LABEL_40:
          DbgPrint(v9, "UDFX: unknown VSD type\n");
          break;
        }
      }
      else
      {
        switch ( v14 )
        {
          case 1:
            if ( FoundBEA )
            {
              DbgPrint(v9, "UDFX: found multiple BEA01 descriptors\n");
              goto LABEL_37;
            }
            if ( VolumeStructureDescriptor->Version != 1 )
            {
              DbgPrint(v9, "UDFX: found BEA01 descriptor with unknown version\n");
              goto LABEL_37;
            }
            FoundBEA = 1;
            break;
          case 8:
            if ( FoundBEA )
            {
              if ( VolumeStructureDescriptor->Version == 1 )
                status = 0;
              else
                DbgPrint(v9, "UDFX: found NSR02 descriptor with unknown version\n");
            }
            else
            {
              DbgPrint(v9, "UDFX: found NSR02 descriptor without BEA01 descriptor\n");
            }
            goto LABEL_37;
          case 2:
            goto LABEL_37;
        }
      }
      ++PhysicalSectorNumber;
      v6 = VolumeExtension;
      if ( PhysicalSectorNumber >= VolumeExtension->PhysicalSectorCount )
        goto LABEL_27;
    }
  }
LABEL_37:
  ExFreePool(v4);
  return status;
}