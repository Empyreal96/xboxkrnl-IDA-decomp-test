void __stdcall nosound(char chan)
{
  if ( (unsigned __int8)chan < (unsigned __int8)max_tracks )
    (*(void (__stdcall **)(char))(4 * (unsigned __int8)chan - 2146390184))(chan);
}