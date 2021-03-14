void __stdcall D3DK::CHECK(D3DCubeTexture *p, char *func)
{
  if ( !p )
    D3DK::DXGRIP((int *)func, "%s - Null THIS pointer.", func);
  if ( (p->Common & 0x70000) != 0x40000 || !(p->Format & 4) )
    D3DK::DXGRIP((int *)func, "%s - This points to the wrong type of object.", func);
  if ( p->Data & 0x7F )
    D3DK::DXGRIP((int *)func, "%s - Bad data alignment.", func);
}