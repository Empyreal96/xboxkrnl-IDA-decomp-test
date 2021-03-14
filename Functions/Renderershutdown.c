// write access to const memory has been detected, the output may be wrong!
void __thiscall Renderer::shutdown(Renderer *this)
{
  if ( this->pD3DDev8 )
  {
    D3DDevice_Release();
    gpd3dDev = 0;
  }
}