int __stdcall XepVerifyImageHeaderEncryptedDigest(char LoadingDashboard, char **ReturnedPublicKeyData)
{
  unsigned int v2; // eax
  int v3; // edx
  int v4; // ecx
  int *v5; // edi
  bool v7; // bl
  char HeaderDigest[20]; // [esp+8h] [ebp-14h]

  *ReturnedPublicKeyData = XePublicKeyData;
  v2 = XCCalcKeyLen(XePublicKeyData);
  v5 = ExAllocatePoolWithTag(v3, v4, (int)XePublicKeyData, 2 * v2, 0x73576558u);
  if ( !v5 )
    return -1073741670;
  XCCalcDigest((char *)0x10104, MEMORY[0x10108] - 260, HeaderDigest);
  v7 = XCVerifyDigest((char *)0x10004, XePublicKeyData, (char *)v5, HeaderDigest);
  ExFreePool(v5);
  return v7 != 0 ? 0 : -1073741424;
}