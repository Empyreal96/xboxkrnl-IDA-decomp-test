int __userpurge CMcpxAPU::CreateBuffer@<eax>(CMcpxAPU *this@<ecx>, int *a2@<edi>, int a3@<esi>, int a4@<edx>, CDirectSoundBufferSettings *pSettings, VADBUFFEREVENTSINK *EventSink, void *pvEventContext, CMcpxBuffer **ppBuffer)
{
  CMcpxBuffer *v8; // eax
  CMcpxBuffer *v10; // [esp+0h] [ebp-14h]
  CMcpxAPU *thisa; // [esp+4h] [ebp-10h]
  CMcpxBuffer *v12; // [esp+8h] [ebp-Ch]
  signed int hr; // [esp+Ch] [ebp-8h]
  CMcpxBuffer *pBuffer; // [esp+10h] [ebp-4h]

  thisa = this;
  v12 = (CMcpxBuffer *)CMcpxAPU::operator new(a4, (int)this, a3, 0x230u);
  if ( v12 )
  {
    CMcpxBuffer::CMcpxBuffer(v12, thisa);
    v10 = v8;
  }
  else
  {
    v10 = 0;
  }
  pBuffer = v10;
  hr = v10 != 0 ? 0 : 0x8007000E;
  if ( hr >= 0 )
    hr = CMcpxBuffer::Initialize(pBuffer, a2, a3, pSettings, EventSink, pvEventContext);
  if ( hr < 0 )
    __Release((CDirectSoundBufferSettings **)&pBuffer);
  else
    *ppBuffer = pBuffer;
  return hr;
}