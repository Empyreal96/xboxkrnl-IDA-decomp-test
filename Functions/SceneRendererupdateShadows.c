void __thiscall SceneRenderer::updateShadows(SceneRenderer *this)
{
  Camera cam; // [esp+Ch] [ebp-180h]
  SceneRenderer *v2; // [esp+188h] [ebp-4h]

  v2 = this;
  qmemcpy(&cam, &dword_8010BDA8, sizeof(cam));
  SceneRenderer::updateSBuffer(this, 0);
  SceneRenderer::updateSBuffer(v2, 1);
  qmemcpy(&dword_8010BDA8, &cam, sizeof(dword_8010BDA8));
}