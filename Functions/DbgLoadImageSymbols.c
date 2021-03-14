void __stdcall DbgLoadImageSymbols(_STRING *FileName, void *ImageBase, unsigned int ProcessId)
{
  _IMAGE_NT_HEADERS *v3; // eax
  _KD_SYMBOLS_INFO SymbolInfo; // [esp+0h] [ebp-10h]

  SymbolInfo.BaseOfDll = ImageBase;
  SymbolInfo.ProcessId = ProcessId;
  v3 = RtlImageNtHeader(ImageBase);
  if ( v3 )
  {
    SymbolInfo.CheckSum = v3->OptionalHeader.CheckSum;
    SymbolInfo.SizeOfImage = v3->OptionalHeader.SizeOfImage;
  }
  else
  {
    SymbolInfo.SizeOfImage = 0;
    SymbolInfo.CheckSum = 0;
  }
  DebugLoadImageSymbols(FileName, &SymbolInfo);
}