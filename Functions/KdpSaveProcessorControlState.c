unsigned __int32 __stdcall KdpSaveProcessorControlState(_DWORD *a1)
{
  unsigned __int32 v2; // eax
  unsigned __int32 v3; // eax
  unsigned __int32 v4; // eax
  unsigned __int32 v5; // eax
  unsigned __int32 v6; // eax
  unsigned __int32 v7; // eax
  unsigned __int32 v8; // eax
  unsigned __int32 v9; // eax
  unsigned __int32 v10; // eax
  unsigned __int32 result; // eax

  _EDX = a1;
  v2 = __readcr0();
  a1[179] = v2;
  v3 = __readcr2();
  a1[180] = v3;
  v4 = __readcr3();
  a1[181] = v4;
  v5 = __readcr4();
  a1[182] = v5;
  v6 = __readdr(0);
  a1[183] = v6;
  v7 = __readdr(1u);
  a1[184] = v7;
  v8 = __readdr(2u);
  a1[185] = v8;
  v9 = __readdr(3u);
  a1[186] = v9;
  v10 = __readdr(6u);
  a1[187] = v10;
  result = __readdr(7u);
  __writedr(7u, 0);
  a1[188] = result;
  __sgdt((char *)a1 + 758);
  __sidt((char *)a1 + 766);
  __asm
  {
    str     word ptr [edx+304h]
    sldt    word ptr [edx+306h]
  }
  return result;
}