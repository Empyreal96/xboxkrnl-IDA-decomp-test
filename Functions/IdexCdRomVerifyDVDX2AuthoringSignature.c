int __stdcall IdexCdRomVerifyDVDX2AuthoringSignature(_DVDX2_CONTROL_DATA *ControlData)
{
  unsigned int v2; // eax
  int v3; // edx
  int v4; // ecx
  int *v5; // edi
  bool v6; // bl
  char AuthoringDigest[20]; // [esp+Ch] [ebp-14h]

  XCCalcDigest((char *)&ControlData->LayerDescriptor, 0x4CBu, AuthoringDigest);
  if ( memcmp(AuthoringDigest, ControlData->AuthoringHash, 0x14u) )
    return -1073741482;
  v2 = XCCalcKeyLen(XePublicKeyData);
  v5 = ExAllocatePoolWithTag(v3, v4, (int)XePublicKeyData, 2 * v2, 0x73577849u);
  if ( !v5 )
    return -1073741670;
  v6 = XCVerifyDigest(ControlData->AuthoringSignature, XePublicKeyData, (char *)v5, AuthoringDigest);
  ExFreePool(v5);
  return v6 != 0 ? 0 : -1073741482;
}