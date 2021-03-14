char __userpurge UdfxProcessPrimaryVolumeDescriptor@<al>(int *a1@<edi>, NSR_PVD *PrimaryVolumeDescriptor)
{
  signed int v2; // ecx
  bool v3; // zf
  int *v4; // edi
  CHARSPEC *v5; // esi
  CHARSPEC *v6; // esi
  signed int v7; // ecx
  bool v8; // zf

  if ( PrimaryVolumeDescriptor->VolSetSeq <= 1u )
  {
    if ( PrimaryVolumeDescriptor->CharSetList != 1 || PrimaryVolumeDescriptor->CharSetListMax != 1 )
    {
      DbgPrint(a1, "UDFX: invalid primary volume descriptor (line %d)\n", 616);
    }
    else
    {
      v2 = 16;
      v3 = 1;
      v4 = (int *)&UdfxCS0Identifier;
      v5 = &PrimaryVolumeDescriptor->CharsetDesc;
      do
      {
        if ( !v2 )
          break;
        v3 = *(_DWORD *)&v5->Type == *v4;
        v5 = (CHARSPEC *)((char *)v5 + 4);
        ++v4;
        --v2;
      }
      while ( v3 );
      if ( v3 )
      {
        v6 = &PrimaryVolumeDescriptor->CharsetExplan;
        v7 = 16;
        v4 = (int *)&UdfxCS0Identifier;
        v8 = 1;
        do
        {
          if ( !v7 )
            break;
          v8 = *(_DWORD *)&v6->Type == *v4;
          v6 = (CHARSPEC *)((char *)v6 + 4);
          ++v4;
          --v7;
        }
        while ( v8 );
        if ( v8 )
          return 1;
      }
      DbgPrint(v4, "UDFX: invalid primary volume descriptor (line %d)\n", 628);
    }
  }
  else
  {
    DbgPrint(a1, "UDFX: invalid primary volume descriptor (line %d)\n", 606);
  }
  return 0;
}