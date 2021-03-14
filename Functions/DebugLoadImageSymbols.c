void __stdcall DebugLoadImageSymbols(_STRING *FileName, _KD_SYMBOLS_INFO *SymbolInfo)
{
  __asm { int     2Dh; Windows NT - debugging services: eax = type }
  __debugbreak();
}