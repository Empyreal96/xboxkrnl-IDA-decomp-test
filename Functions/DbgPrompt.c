unsigned int __stdcall DbgPrompt(char *Prompt, char *Response, unsigned int MaximumResponseLength)
{
  _STRING Output; // [esp+4h] [ebp-10h]
  _STRING Input; // [esp+Ch] [ebp-8h]

  Input.MaximumLength = MaximumResponseLength;
  Input.Buffer = Response;
  Output.Length = strlen(Prompt);
  Output.Buffer = Prompt;
  return DebugPrompt(&Output, &Input);
}