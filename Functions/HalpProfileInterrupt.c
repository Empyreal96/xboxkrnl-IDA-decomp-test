int __usercall HalpProfileInterrupt@<eax>(int a1@<eax>, int a2@<edx>, int a3@<ecx>)
{
  unsigned int v3; // ebx
  unsigned __int8 v4; // al
  unsigned __int8 i; // al
  int v7; // [esp+0h] [ebp-3Ch]
  int v8; // [esp+4h] [ebp-38h]
  int v9; // [esp+8h] [ebp-34h]
  int v10; // [esp+Ch] [ebp-30h]
  int v11; // [esp+18h] [ebp-24h]
  int v12; // [esp+1Ch] [ebp-20h]
  int v13; // [esp+20h] [ebp-1Ch]
  unsigned int v14; // [esp+24h] [ebp-18h]
  int v15; // [esp+34h] [ebp-8h]
  int retaddr; // [esp+3Ch] [ebp+0h]

  v13 = a1;
  v12 = a3;
  v11 = a2;
  v3 = KiPCR;
  KiPCR = -1;
  v14 = v3;
  v10 = a2;
  v9 = -1160049408;
  v7 = v15;
  v8 = retaddr;
  ((void (__fastcall *)(signed int, signed int))HalBeginProfileInterrupt)(8, 26);
  HalpAcquireCmosSpinLock();
  __outbyte(0x70u, 0xCu);
  v4 = __inbyte(0x71u);
  __outbyte(0x70u, 0xCu);
  for ( i = __inbyte(0x71u); (i & 0x80u) != 0; i = __inbyte(0x71u) )
    __outbyte(0x70u, 0xCu);
  HalpReleaseCmosSpinLock();
  _enable();
  if ( KiDbgProfInt )
    ((void (__stdcall *)(int *))KiDbgProfInt)(&v7);
  _disable();
  return HalEndSystemInterrupt(0);
}