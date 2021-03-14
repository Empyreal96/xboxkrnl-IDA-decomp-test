void __userpurge D3DK::CMiniport::SetVideoMode(D3DK::CMiniport *this@<ecx>, int *a2@<edi>, unsigned int Width, unsigned int Height, unsigned int Refresh, unsigned int Flags, _D3DFORMAT Format, unsigned int PresentationInterval, unsigned int Pitch)
{
  D3DK::CMiniport *v9; // ebx
  D3DK::DISPLAYMODE *v10; // eax
  D3DK::DISPLAYMODE *v11; // esi
  unsigned int v12; // eax
  int *v13; // edi
  unsigned int v14; // ecx
  unsigned int v15; // ecx
  unsigned int v16; // ecx
  unsigned int AvPack; // [esp+Ch] [ebp-18h]
  int AvHDTVModes; // [esp+10h] [ebp-14h]
  unsigned int SystemAvInfo; // [esp+14h] [ebp-10h]
  int AvRefresh; // [esp+18h] [ebp-Ch]
  unsigned int AvField; // [esp+1Ch] [ebp-8h]
  D3DK::DISPLAYMODE *pMode; // [esp+20h] [ebp-4h]
  unsigned int DisplayMode; // [esp+34h] [ebp+10h]
  unsigned int Formata; // [esp+3Ch] [ebp+18h]

  v9 = this;
  Formata = D3DK::MapToLinearD3DFORMAT(Format);
  D3DK::VideoBitsPerPixelOfD3DFORMAT(Formata);
  v10 = D3DK::GetTableForCurrentAvInfo(a2);
  v11 = v10;
  pMode = v10;
  v12 = D3DK::CMiniport::GetDisplayCapabilities();
  AvHDTVModes = 0;
  SystemAvInfo = v12;
  AvRefresh = v12 & 0xC00000;
  v12 = (unsigned __int8)v12;
  v13 = (int *)(v11->AvInfo & 0xFF);
  AvPack = (unsigned __int8)v12;
  AvField = Flags & 0x60;
  if ( (Flags & 0x80u) != 0 )
    AvField = Flags & 0x40;
  if ( (unsigned __int8)v12 == 4 )
    AvHDTVModes = SystemAvInfo & 0xE0000;
  if ( Refresh )
  {
    if ( Refresh == 50 )
    {
      AvRefresh = 0x800000;
    }
    else if ( Refresh == 60 )
    {
      AvRefresh = 0x400000;
    }
    else
    {
      D3DK::DXGRIP(v13, "SetVideoMode - Bad refresh rate.");
      v12 = AvPack;
    }
  }
  DisplayMode = 0;
  if ( v12 )
  {
    while ( 1 )
    {
      v15 = pMode->AvInfo;
      if ( (int *)(pMode->AvInfo & 0xFF) != v13 )
        break;
      if ( (v12 != 4 || v15 & AvHDTVModes || !(v15 & 0xE0000))
        && pMode->Width == Width
        && pMode->Height == Height
        && !(((unsigned __int8)~(Flags >> 4) ^ (unsigned __int8)~(v15 >> 16)) & 1)
        && !(((unsigned __int8)~(Flags >> 7) ^ (unsigned __int8)~(pMode->AvInfo >> 24)) & 1)
        && !(((unsigned __int8)~(Flags >> 8) ^ (unsigned __int8)~(pMode->AvInfo >> 25)) & 1) )
      {
        v14 = pMode->AvInfo;
        if ( pMode->AvInfo & AvRefresh )
        {
          if ( !AvField || AvField & 0x20 && v14 & 0x200000 || AvField & 0x40 && !(v14 & 0x200000) )
          {
            DisplayMode = pMode->DisplayMode;
            if ( pMode->DisplayMode )
            {
              if ( !(SystemAvInfo & AvRefresh) )
              {
                D3DK::DXGRIP(v13, "SetVideoMode - Current AV setup does not support the requested refresh rate.");
                v12 = AvPack;
              }
              if ( (v12 != 4 || !(pMode->AvInfo & 0x60000)) && Flags & 0x10 && !(SystemAvInfo & 0x10000) )
                D3DK::DXGRIP(v13, "SetVideoMode - Current system does not support widescreen mode.");
            }
            break;
          }
        }
      }
      ++pMode;
    }
  }
  v16 = v9->m_GammaCurrentIndex;
  v9->m_DisplayMode = DisplayMode;
  v9->m_Format = Formata;
  v9->m_PresentationInterval = PresentationInterval;
  v9->m_SurfacePitch = Pitch;
  v9->m_GammaUpdated[v16] = 1;
  v9->m_CurrentAvInfo = pMode->AvInfo;
  v9->m_FirstFlip = 1;
}