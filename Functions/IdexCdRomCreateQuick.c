_DEVICE_OBJECT *__usercall IdexCdRomCreateQuick@<eax>(int *a1@<edi>)
{
  int *v1; // eax
  int *v2; // eax
  int v3; // edx
  int v4; // ecx
  _DEVICE_OBJECT *result; // eax
  int v6; // esi
  _DVDX2_AUTHENTICATION Authentication; // [esp+8h] [ebp-20h]
  _DEVICE_OBJECT *CdRomDeviceObject; // [esp+24h] [ebp-4h]

  v1 = IoCreateDevice(
         a1,
         (int)&IdexCdRomDeviceName,
         &IdexCdRomDriverObject,
         0,
         &IdexCdRomDeviceName,
         2u,
         0,
         &CdRomDeviceObject);
  if ( (signed int)v1 < 0 )
    IdexBugCheckWorker(0x10FEAu, (unsigned int)v1);
  v2 = IoCreateSymbolicLink(a1, (int)&IdexCdRomDeviceName, &IdexCdRomDosDevicesName, &IdexCdRomDeviceName);
  if ( (signed int)v2 < 0 )
    IdexBugCheckWorker(0x10FF4u, (unsigned int)v2);
  CdRomDeviceObject->Flags |= 0x44u;
  CdRomDeviceObject->AlignmentRequirement = 1;
  CdRomDeviceObject->SectorSize = 2048;
  CdRomDeviceObject->Flags &= 0xFFFFFFEF;
  result = CdRomDeviceObject;
  IdexCdRomDeviceObject = CdRomDeviceObject;
  if ( KeHasQuickBooted && IdexCdRomDVDX2Authenticated )
  {
    IdexCdRomDVDX2Authenticated = 0;
    v6 = 0;
    while ( 1 )
    {
      result = (_DEVICE_OBJECT *)IdexCdRomRequestDVDX2AuthenticationPage(v4, v3, &Authentication);
      if ( (signed int)result >= 0
        && Authentication.AuthenticationPage.PartitionArea
        && Authentication.AuthenticationPage.Authentication )
      {
        break;
      }
      if ( (unsigned int)++v6 >= 5 )
        goto LABEL_14;
    }
    IdexCdRomDVDX2Authenticated = 1;
LABEL_14:
    if ( !IdexCdRomDVDX2Authenticated )
      result = (_DEVICE_OBJECT *)DbgPrint(a1, "IDEX: failed to reverify DVD-X2 media.\n");
  }
  return result;
}