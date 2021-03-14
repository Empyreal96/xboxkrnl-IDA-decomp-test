void __usercall CMcpxGPDspManager::Initialize(CMcpxGPDspManager *this@<ecx>, int *a2@<edi>, int a3@<edx>, int a4@<esi>)
{
  CMcpxDspImage *v4; // eax
  int v5; // edx
  int v6; // ecx
  CMcpxDspScratchDma *v7; // eax
  unsigned int v8; // ST08_4
  _SGEHEAPRUNMARKER *v9; // eax
  CMcpxDspScratchDma *v10; // [esp+0h] [ebp-18h]
  CMcpxDspImage *v11; // [esp+4h] [ebp-14h]
  CMcpxGPDspManager *thisa; // [esp+8h] [ebp-10h]
  CMcpxDspScratchDma *v13; // [esp+Ch] [ebp-Ch]
  CList<_SGEHEAPRUNMARKER> *v14; // [esp+10h] [ebp-8h]

  thisa = this;
  v14 = (CList<_SGEHEAPRUNMARKER> *)CMcpxAPU::operator new(a3, (int)this, a4, 8u);
  if ( v14 )
  {
    CMcpxDspImage::CMcpxDspImage(v14);
    v11 = v4;
  }
  else
  {
    v11 = 0;
  }
  thisa->m_pDspImage = v11;
  CMcpxDspImage::Initialize(thisa->m_pDspImage);
  v13 = (CMcpxDspScratchDma *)CMcpxAPU::operator new(v5, v6, a4, 0x28u);
  if ( v13 )
  {
    CMcpxDspScratchDma::CMcpxDspScratchDma(v13, thisa->m_pApu, 1);
    v10 = v7;
  }
  else
  {
    v10 = 0;
  }
  thisa->m_pScratchDma = v10;
  CMcpxDspScratchDma::Initialize(thisa->m_pScratchDma, a2, 0x204u);
  if ( thisa->m_pScratchDma )
  {
    v8 = CMcpxDspImage::GetLoaderSize(thisa->m_pDspImage);
    v9 = CList<_SGEHEAPRUNMARKER>::GetListHead((CList<_SGEHEAPRUNMARKER> *)thisa->m_pDspImage);
    CMcpxDspScratchDma::Copy(thisa->m_pScratchDma, 0, v9, v8);
  }
}