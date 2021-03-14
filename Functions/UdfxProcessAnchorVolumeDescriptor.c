int __userpurge UdfxProcessAnchorVolumeDescriptor@<eax>(int a1@<edx>, int a2@<ecx>, int a3@<esi>, _UDF_VOLUME_EXTENSION *VolumeExtension, EXTENTAD *MainVolumeDescriptorSequenceExtent)
{
  int *v5; // eax
  int *v6; // esi
  int v8; // ebx

  v5 = ExAllocatePoolWithTag(a1, a2, a3, 0x800u, 0x76417855u);
  v6 = v5;
  if ( !v5 )
    return -1073741670;
  v8 = UdfxReadPhysicalSector(VolumeExtension, 0x100u, v5);
  if ( v8 >= 0 )
  {
    if ( UdfxVerifyDescriptor((DESTAG *)v6, 0x200u, 2u, 0x100u) )
    {
      MainVolumeDescriptorSequenceExtent->Len = v6[4];
      MainVolumeDescriptorSequenceExtent->Lsn = v6[5];
      v8 = 0;
    }
    else
    {
      DbgPrint((int *)0x100, "UDFX: anchor volume descriptor not valid\n");
      v8 = -1073741774;
    }
  }
  ExFreePool(v6);
  return v8;
}