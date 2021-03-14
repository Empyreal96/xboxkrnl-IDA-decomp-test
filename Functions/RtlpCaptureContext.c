_DWORD *__userpurge RtlpCaptureContext@<eax>(_DWORD *a1@<ebp>, int a2)
{
  unsigned int v2; // et0
  _DWORD *result; // eax

  *(_DWORD *)(a2 + 540) = 0;
  *(_DWORD *)(a2 + 536) = 0;
  *(_DWORD *)(a2 + 532) = 0;
  *(_DWORD *)(a2 + 528) = 0;
  *(_DWORD *)(a2 + 524) = 0;
  *(_DWORD *)(a2 + 520) = 0;
  *(_WORD *)(a2 + 552) = __CS__;
  *(_WORD *)(a2 + 564) = __SS__;
  v2 = __readeflags();
  *(_DWORD *)(a2 + 556) = v2;
  *(_DWORD *)(a2 + 548) = a1[1];
  *(_DWORD *)(a2 + 544) = *a1;
  result = a1 + 2;
  *(_DWORD *)(a2 + 560) = a1 + 2;
  return result;
}