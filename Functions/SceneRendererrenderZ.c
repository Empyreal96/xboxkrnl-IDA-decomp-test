void __thiscall SceneRenderer::renderZ(SceneRenderer *this)
{
  SceneRenderer *v1; // esi
  signed int v2; // edi
  PrimitiveSet *v3; // ecx

  v1 = this;
  v2 = 0;
  do
  {
    if ( v1->bUseLoDetail )
      v3 = v1->pSetLoDet[v2];
    else
      v3 = v1->pSetHiDet[v2];
    PrimitiveSet::renderZ(v3);
    ++v2;
  }
  while ( v2 < 6 );
}