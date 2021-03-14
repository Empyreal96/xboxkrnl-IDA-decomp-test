void __stdcall DbgUnLoadImageSymbols(_STRING *FileName, void *ImageBase, unsigned int ProcessId)
{
  _KD_SYMBOLS_INFO SymbolInfo; // [esp+0h] [ebp-10h]

  SymbolInfo.CheckSum = 0;
  SymbolInfo.SizeOfImage = 0;
  SymbolInfo.BaseOfDll = ImageBase;
  SymbolInfo.ProcessId = ProcessId;
  DebugUnLoadImageSymbols(FileName, &SymbolInfo);
}