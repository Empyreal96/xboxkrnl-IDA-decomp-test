bool __usercall ObInitSystem@<al>(int a1@<esi>)
{
  int *v1; // edi
  _OBJECT_DIRECTORY *v2; // ecx
  bool result; // al
  _OBJECT_DIRECTORY *v4; // ecx
  _OBJECT_DIRECTORY *v5; // ecx

  *(_QWORD *)&ObpObjectHandleTable = -4294967296i64;
  *((_QWORD *)&ObpObjectHandleTable + 1) = 0i64;
  memset(ObpDosDevicesDriveLetterMap, 0, sizeof(ObpDosDevicesDriveLetterMap));
  v1 = (int *)&ObpDosDevicesDriveLetterMap[26];
  if ( ObpCreatePermanentDirectoryObject(0, (int *)&ObpDosDevicesDriveLetterMap[26], a1, 0, &ObpRootDirectoryObject)
    && ObpCreatePermanentDirectoryObject(v2, v1, a1, &ObpDosDevicesString, &ObpDosDevicesDirectoryObject)
    && ObpCreatePermanentDirectoryObject(v4, v1, a1, &ObpIoDevicesString, &ObpIoDevicesDirectoryObject) )
  {
    result = ObpCreatePermanentDirectoryObject(
               v5,
               v1,
               a1,
               &ObpWin32NamedObjectsString,
               &ObpWin32NamedObjectsDirectoryObject) != 0;
  }
  else
  {
    result = 0;
  }
  return result;
}