void __fastcall LogoRenderer::decompressData(LogoRenderer *this, int a2)
{
  LogoRenderer *v2; // esi
  int v3; // edx
  int v4; // edx
  int v5; // edx
  int v6; // edx
  int v7; // edx
  int v8; // edx
  int v9; // edx
  int v10; // edx
  int v11; // edx
  int v12; // edx
  int v13; // edx
  int v14; // edx
  int v15; // edx

  v2 = this;
  this->indices_xboxlogolip_0 = LogoRenderer::decompressIndexData(a2, (int)this, (int)this, indices_xboxlogolip_0C, 336);
  v2->verts_xboxlogolip_0 = LogoRenderer::decompressPosTexData(
                              (int)v2,
                              v3,
                              verts_xboxlogolip_0C,
                              210,
                              0.0098759998,
                              161.71536,
                              0.000058000001,
                              0.94766098);
  v2->indices_xboxlogosurface_0 = LogoRenderer::decompressIndexData(
                                    v4,
                                    (int)v2,
                                    (int)v2,
                                    indices_xboxlogosurface_0C,
                                    225);
  v2->verts_xboxlogosurface_0 = LogoRenderer::decompressPosTexData(
                                  (int)v2,
                                  v5,
                                  verts_xboxlogosurface_0C,
                                  77,
                                  0.0098759998,
                                  161.71536,
                                  0.000058000001,
                                  0.94766098);
  v2->indices_xboxlogosurfacetop_0 = LogoRenderer::decompressIndexData(
                                       v6,
                                       (int)v2,
                                       (int)v2,
                                       indices_xboxlogosurfacetop_0C,
                                       105);
  v2->verts_xboxlogosurfacetop_0 = LogoRenderer::decompressPosTexData(
                                     (int)v2,
                                     v7,
                                     verts_xboxlogosurfacetop_0C,
                                     34,
                                     0.0098759998,
                                     161.71536,
                                     0.000058000001,
                                     0.94766098);
  v2->indices_xboxlogointerior_0 = LogoRenderer::decompressIndexData(
                                     v8,
                                     (int)v2,
                                     (int)v2,
                                     indices_xboxlogointerior_0C,
                                     1008);
  v2->verts_xboxlogointerior_0 = LogoRenderer::decompressPosTexData(
                                   (int)v2,
                                   v9,
                                   verts_xboxlogointerior_0C,
                                   501,
                                   0.0098759998,
                                   161.71536,
                                   0.000058000001,
                                   0.94766098);
  v2->indices_tm_slash_0 = LogoRenderer::decompressIndexData(v10, (int)v2, (int)v2, indices_tm_slash_0C, 6);
  v2->verts_tm_slash_0 = LogoRenderer::decompressPosTexData(
                           (int)v2,
                           v11,
                           verts_tm_slash_0C,
                           4,
                           0.0098759998,
                           161.71536,
                           0.000058000001,
                           0.94766098);
  v2->indices_tm_wordmark_0 = LogoRenderer::decompressIndexData(v12, (int)v2, (int)v2, indices_tm_wordmark_0C, 6);
  v2->verts_tm_wordmark_0 = LogoRenderer::decompressPosTexData(
                              (int)v2,
                              v13,
                              verts_tm_wordmark_0C,
                              4,
                              0.0098759998,
                              161.71536,
                              0.000058000001,
                              0.94766098);
  v2->indices_text_0 = LogoRenderer::decompressIndexData(v14, (int)v2, (int)v2, indices_text_0C, 462);
  v2->verts_text_0 = LogoRenderer::decompressPosData((int)v2, v15, verts_text_0C, 156, 0.002508, 41.065369);
}