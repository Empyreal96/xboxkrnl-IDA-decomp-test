int *__userpurge NtQueryFullAttributesFile@<eax>(int *a1@<edi>, int a2@<esi>, _OBJECT_ATTRIBUTES *ObjectAttributes, _FILE_NETWORK_OPEN_INFORMATION *FileInformation)
{
  int v4; // edx
  int v5; // ST10_4
  int *result; // eax
  _DUMMY_FILE_OBJECT localFileObject; // [esp+0h] [ebp-A4h]
  _OPEN_PACKET openPacket; // [esp+60h] [ebp-44h]
  void *handle; // [esp+A0h] [ebp-4h]

  if ( (unsigned __int8)dword_8004C5D0 > 1u )
  {
    DbgPrint(a1, "EX: Pageable code called at IRQL %d\n", (unsigned __int8)dword_8004C5D0);
    RtlAssert(v4, v5, a1, a2, "FALSE", "d:\\xbox-apr03\\private\\ntos\\io\\misc.c", 0x12Cu, 0);
  }
  memset(&openPacket, 0, sizeof(openPacket));
  openPacket.LocalFileObject = &localFileObject;
  openPacket.NetworkInformation = FileInformation;
  openPacket.Type = 8;
  openPacket.Size = 64;
  openPacket.ShareAccess = 7;
  openPacket.Disposition = 1;
  openPacket.QueryOnly = 1;
  openPacket.DesiredAccess = 128;
  result = ObOpenObjectByName(ObjectAttributes, &IoFileObjectType, &openPacket, &handle);
  if ( openPacket.ParseCheck == -1096154543 )
    result = (int *)openPacket.FinalStatus;
  return result;
}