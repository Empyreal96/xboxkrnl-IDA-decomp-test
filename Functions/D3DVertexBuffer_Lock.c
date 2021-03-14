// write access to const memory has been detected, the output may be wrong!
void __userpurge D3DVertexBuffer_Lock(int *a1@<edi>, D3DVertexBuffer *pBuffer, unsigned int OffsetToLock, unsigned int SizeToLock, char **ppbData, unsigned int Flags)
{
  int *v6; // ST0C_4
  int *v7; // edi

  ++D3DK::g_PerfCounters.m_APICounters[209];
  if ( !pBuffer )
    D3DK::DXGRIP(a1, "%s - Null THIS pointer.", "D3DVertexBuffer_Lock");
  if ( pBuffer->Common & 0x70000 )
    D3DK::DXGRIP(a1, "%s - This points to the wrong type of object.", "D3DVertexBuffer_Lock");
  if ( pBuffer->Data & 3 )
    D3DK::DXGRIP(a1, "%s - Bad data alignment.", "D3DVertexBuffer_Lock");
  if ( OffsetToLock && !SizeToLock )
    D3DK::DXGRIP(a1, "LockBuffer - Unable to lock zero bytes.");
  if ( !(Flags & 0x10) )
  {
    v6 = a1;
    v7 = (int *)XMETAL_StartPush(a1, &D3DK::g_pDevice->m_Pusher);
    XMETAL_Push1f(v7, (unsigned int *)v7, 0x1710u, 0.0);
    XMETAL_EndPush(v7 + 2, &D3DK::g_pDevice->m_Pusher, (unsigned int *)v7 + 2);
    a1 = v6;
  }
  if ( !(Flags & 0xA0) )
    D3DK::BlockOnResource((D3DResource *)&pBuffer->Common);
  *ppbData = &D3DK::GetDataFromResource(a1, (D3DResource *)&pBuffer->Common)[OffsetToLock];
}