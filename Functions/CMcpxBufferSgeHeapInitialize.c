int __userpurge CMcpxBufferSgeHeap::Initialize@<eax>(CMcpxBufferSgeHeap *this@<ecx>, int a2@<esi>, unsigned __int16 wElementCount)
{
  return CHeap<_SGEHEAPRUNMARKER>::Initialize((CHeap<_SGEHEAPRUNMARKER> *)&this->vfptr, a2, wElementCount);
}