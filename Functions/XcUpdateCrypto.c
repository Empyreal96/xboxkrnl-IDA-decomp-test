void __stdcall XcUpdateCrypto(CRYPTO_VECTOR *pNewVector, CRYPTO_VECTOR *pROMVector)
{
  if ( pNewVector->pXcSHAInit )
    updatedCryptoVector.pXcSHAInit = pNewVector->pXcSHAInit;
  if ( pNewVector->pXcSHAUpdate )
    updatedCryptoVector.pXcSHAUpdate = pNewVector->pXcSHAUpdate;
  if ( pNewVector->pXcSHAFinal )
    updatedCryptoVector.pXcSHAFinal = pNewVector->pXcSHAFinal;
  if ( pNewVector->pXcRC4Key )
    updatedCryptoVector.pXcRC4Key = pNewVector->pXcRC4Key;
  if ( pNewVector->pXcRC4Crypt )
    updatedCryptoVector.pXcRC4Crypt = pNewVector->pXcRC4Crypt;
  if ( pNewVector->pXcHMAC )
    updatedCryptoVector.pXcHMAC = pNewVector->pXcHMAC;
  if ( pNewVector->pXcPKEncPublic )
    updatedCryptoVector.pXcPKEncPublic = pNewVector->pXcPKEncPublic;
  if ( pNewVector->pXcPKDecPrivate )
    updatedCryptoVector.pXcPKDecPrivate = pNewVector->pXcPKDecPrivate;
  if ( pNewVector->pXcPKGetKeyLen )
    updatedCryptoVector.pXcPKGetKeyLen = pNewVector->pXcPKGetKeyLen;
  if ( pNewVector->pXcVerifyPKCS1Signature )
    updatedCryptoVector.pXcVerifyPKCS1Signature = pNewVector->pXcVerifyPKCS1Signature;
  if ( pNewVector->pXcModExp )
    updatedCryptoVector.pXcModExp = pNewVector->pXcModExp;
  if ( pNewVector->pXcDESKeyParity )
    updatedCryptoVector.pXcDESKeyParity = pNewVector->pXcDESKeyParity;
  if ( pNewVector->pXcKeyTable )
    updatedCryptoVector.pXcKeyTable = pNewVector->pXcKeyTable;
  if ( pNewVector->pXcBlockCrypt )
    updatedCryptoVector.pXcBlockCrypt = pNewVector->pXcBlockCrypt;
  if ( pNewVector->pXcBlockCryptCBC )
    updatedCryptoVector.pXcBlockCryptCBC = pNewVector->pXcBlockCryptCBC;
  if ( pNewVector->pXcCryptService )
    updatedCryptoVector.pXcCryptService = pNewVector->pXcCryptService;
  if ( pROMVector )
    qmemcpy(pROMVector, &originalCryptoVector, sizeof(CRYPTO_VECTOR));
}