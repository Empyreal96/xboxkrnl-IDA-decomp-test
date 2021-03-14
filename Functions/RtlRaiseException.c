void __userpurge __noreturn RtlRaiseException(int a1@<eax>, int a2@<edx>, int a3@<ecx>, int a4, char a5)
{
  unsigned int v5; // et0
  int v6; // [esp+20h] [ebp-244h]
  int v7; // [esp+234h] [ebp-30h]
  int v8; // [esp+238h] [ebp-2Ch]
  int v9; // [esp+23Ch] [ebp-28h]
  int v10; // [esp+240h] [ebp-24h]
  int v11; // [esp+244h] [ebp-20h]
  __int16 v12; // [esp+248h] [ebp-1Ch]
  unsigned int v13; // [esp+24Ch] [ebp-18h]
  char *v14; // [esp+250h] [ebp-14h]
  __int16 v15; // [esp+254h] [ebp-10h]
  unsigned int v16; // [esp+260h] [ebp-4h]
  int vars0; // [esp+264h] [ebp+0h]
  int retaddr; // [esp+268h] [ebp+4h]

  v5 = __readeflags();
  v16 = v5;
  v9 = a1;
  v8 = a3;
  *(_DWORD *)(a4 + 12) = retaddr;
  v11 = retaddr;
  v7 = a2;
  v14 = &a5;
  v10 = vars0;
  v13 = v16;
  v12 = __CS__;
  v15 = __SS__;
  v6 = 65543;
  ZwRaiseException(a4, (unsigned int)&v6, 1);
}