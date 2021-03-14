bool __stdcall UdfxVerifyDescriptor(DESTAG *Descriptor, unsigned int DescriptorSize, unsigned __int16 Ident, unsigned int LogicalSectorNumber)
{
  return Descriptor->Version == 2 && Descriptor->Ident == Ident && Descriptor->Lbn == LogicalSectorNumber;
}