void __stdcall D3DK::CleanPrivateData(void *p)
{
  D3DK::PrivateDataNode *v1; // esi
  D3DK::PrivateDataNode **v2; // edi

  v1 = g_pPrivateData;
  v2 = &g_pPrivateData;
  while ( v1 )
  {
    if ( v1->pObject == p )
    {
      *v2 = v1->pNext;
      if ( v1->flags & 1 )
        v1->pUnknown->vfptr->Release(v1->pUnknown);
      D3DK::MemFree(v1);
      v1 = *v2;
    }
    else
    {
      v2 = &v1->pNext;
      v1 = v1->pNext;
    }
  }
}