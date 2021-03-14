int __thiscall D3DK::CMiniport::CreateGrObject(D3DK::CMiniport *this, unsigned int Handle, unsigned int ClassNum, D3DK::CMiniport::OBJECTINFO *Object)
{
  signed int v4; // edi
  D3DK::CMiniport *v5; // esi
  unsigned int v6; // eax
  unsigned int v7; // ebx
  int *v8; // edi

  v4 = 0;
  v5 = this;
  if ( ClassNum != 48 && ClassNum != 57 && ClassNum != 98 )
  {
    if ( ClassNum == 151 )
    {
      v6 = 816;
      v4 = 1;
      goto LABEL_9;
    }
    if ( ClassNum != 159 )
    {
      D3DK::DXGRIP(0, "MP: CreateGrObject invalid class number");
      v6 = ClassNum;
      goto LABEL_9;
    }
  }
  v6 = 16;
LABEL_9:
  v7 = D3DK::CMiniport::ReserveInstMem(v5, v6 >> 4);
  if ( v4 )
  {
    v8 = &v5->m_HalInfo.FifoChID;
    if ( v5->m_HalInfo.GrCurrentObjects3d[v5->m_HalInfo.FifoChID] )
      D3DK::DXGRIP(v8, "Assertion failure: %s", "m_HalInfo.GrCurrentObjects3d[m_HalInfo.FifoChID] == 0");
    v5->m_HalInfo.GrCurrentObjects3d[*v8] = v7;
    D3DK::CMiniport::HalGrInit3d(v5);
  }
  D3DK::CMiniport::HalGrInitObjectContext(v5, v7, ClassNum);
  Object->Handle = 0;
  *(_DWORD *)&Object->SubChannel = 0;
  Object->ClassNum = 0;
  Object->Instance = 0;
  Object->Handle = Handle;
  Object->ClassNum = ClassNum;
  Object->Instance = v7;
  Object->Engine = 1;
  D3DK::CMiniport::BindToChannel(v5, Object);
  return 1;
}