void __userpurge RtlCaptureContext(int a1@<eax>, int a2@<edx>, int a3@<ecx>, int a4@<edi>, int a5@<esi>, _DWORD *a6)
{
  int v6; // [esp+0h] [ebp-4h]

  a6[135] = a1;
  a6[134] = a3;
  a6[133] = a2;
  a6[132] = v6;
  a6[131] = a5;
  a6[130] = a4;
  JUMPOUT(&RtlpCaptureCommon);
}