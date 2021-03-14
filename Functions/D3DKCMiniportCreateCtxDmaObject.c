int __thiscall D3DK::CMiniport::CreateCtxDmaObject(D3DK::CMiniport *this, unsigned int Dma, unsigned int ClassNum, void *Base, unsigned int Limit, D3DK::CMiniport::OBJECTINFO *Object)
{
  D3DK::CMiniport *v6; // ebx
  signed int v7; // edi
  unsigned int v8; // esi
  unsigned int v9; // ebx
  int v10; // edi
  char *v11; // eax
  signed int v13; // [esp-4h] [ebp-1Ch]
  char *RegisterBase; // [esp+Ch] [ebp-Ch]
  void *Address; // [esp+10h] [ebp-8h]
  unsigned int AddressSpace; // [esp+14h] [ebp-4h]

  v6 = this;
  v7 = 0;
  RegisterBase = (char *)this->m_RegisterBase;
  Address = 0;
  AddressSpace = 0;
  D3DK::CMiniport::GetAddressInfo(this, 0, Base, &Address, &AddressSpace, 0);
  if ( AddressSpace != 2 && AddressSpace != 3 && AddressSpace != 1 )
    D3DK::DXGRIP(
      0,
      "Assertion failure: %s",
      "(AddressSpace == ADDR_FBMEM || AddressSpace == ADDR_AGPMEM) || AddressSpace == ADDR_SYSMEM");
  v8 = (unsigned int)Address | 3;
  v9 = D3DK::CMiniport::ReserveInstMem(v6, 1u);
  switch ( ClassNum )
  {
    case 2u:
      v13 = 2;
      break;
    case 3u:
      v13 = 3;
      break;
    case 0x3Du:
      v13 = 61;
      break;
    default:
      D3DK::DXGRIP(0, "Invalid class specified for DMA context");
      goto LABEL_13;
  }
  v7 = v13;
LABEL_13:
  v10 = ((_DWORD)Address << 20) | 0x3000 | v7;
  if ( AddressSpace != 2 )
  {
    if ( AddressSpace == 3 )
    {
      v10 |= 0x30000u;
    }
    else if ( AddressSpace == 1 )
    {
      v10 |= 0x20000u;
    }
  }
  v11 = &RegisterBase[16 * v9];
  *((_DWORD *)v11 + 1835010) = v8;
  *((_DWORD *)v11 + 1835011) = v8;
  *(_DWORD *)&RegisterBase[16 * (v9 + 458752)] = v10 | 0x8000;
  *((_DWORD *)v11 + 1835009) = Limit;
  Object->Handle = 0;
  *(_DWORD *)&Object->SubChannel = 0;
  Object->ClassNum = 0;
  Object->Instance = 0;
  Object->Engine = 0;
  Object->Handle = Dma;
  Object->ClassNum = ClassNum;
  Object->Instance = v9;
  return 1;
}