void __usercall LogoRenderer::destroy(LogoRenderer *this@<ecx>, int *a2@<edi>)
{
  LogoRenderer *v2; // esi

  v2 = this;
  D3DResource_Release(a2, (D3DResource *)&this->pLipVB->Common);
  D3DResource_Release(a2, (D3DResource *)&v2->pLipTex->Common);
  D3DResource_Release(a2, (D3DResource *)&v2->pSurfaceVB->Common);
  D3DResource_Release(a2, (D3DResource *)&v2->pSurfaceTex->Common);
  D3DResource_Release(a2, (D3DResource *)&v2->pSurfaceTopVB->Common);
  D3DResource_Release(a2, (D3DResource *)&v2->pSurfaceTopTex->Common);
  D3DResource_Release(a2, (D3DResource *)&v2->pInteriorVB->Common);
  D3DResource_Release(a2, (D3DResource *)&v2->pText_VB->Common);
  D3DResource_Release(a2, (D3DResource *)&v2->pSlashTM_VB->Common);
  D3DResource_Release(a2, (D3DResource *)&v2->pTextTM_VB->Common);
  D3DResource_Release(a2, (D3DResource *)&v2->pTMTex->Common);
  D3DResource_Release(a2, (D3DResource *)&v2->pSlashTexture->Common);
  MemFree(v2->indices_xboxlogolip_0);
  MemFree(v2->verts_xboxlogolip_0);
  MemFree(v2->indices_xboxlogosurface_0);
  MemFree(v2->verts_xboxlogosurface_0);
  MemFree(v2->indices_xboxlogosurfacetop_0);
  MemFree(v2->verts_xboxlogosurfacetop_0);
  MemFree(v2->indices_xboxlogointerior_0);
  MemFree(v2->verts_xboxlogointerior_0);
  MemFree(v2->indices_tm_wordmark_0);
  MemFree(v2->verts_tm_wordmark_0);
  MemFree(v2->indices_tm_slash_0);
  MemFree(v2->verts_tm_slash_0);
  MemFree(v2->indices_text_0);
  MemFree(v2->verts_text_0);
  D3DDevice_DeleteVertexShader(v2->dwInteriorVShader);
  D3DDevice_DeletePixelShader(v2->dwInteriorPShader);
}