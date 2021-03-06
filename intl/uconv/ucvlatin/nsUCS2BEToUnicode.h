/* -*- Mode: C++; tab-width: 2; indent-tabs-mode: nil; c-basic-offset: 2 -*- */
/* This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/. */

#ifndef nsUCS2BEToUnicode_h___
#define nsUCS2BEToUnicode_h___

#include "nsISupports.h"
#include "nsUCSupport.h"

// internal base class
class nsUTF16ToUnicodeBase : public nsBasicDecoderSupport
{
protected:
  // ctor accessible only by child classes
  nsUTF16ToUnicodeBase() { Reset();}

public: 
  //--------------------------------------------------------------------
  // Subclassing of nsDecoderSupport class [declaration]

  NS_IMETHOD GetMaxLength(const char * aSrc, int32_t aSrcLength, 
      int32_t * aDestLength);
  NS_IMETHOD Reset();

protected:
  uint8_t mState;
  // to store an odd byte left over between runs
  uint8_t mOddByte;
  // to store an odd high surrogate left over between runs
  PRUnichar mOddHighSurrogate;
  // to store an odd low surrogate left over between runs
  PRUnichar mOddLowSurrogate;
};

// UTF-16 big endian
class nsUTF16BEToUnicode : public nsUTF16ToUnicodeBase
{
public:

  NS_IMETHOD Convert(const char * aSrc, int32_t * aSrcLength,
      PRUnichar * aDest, int32_t * aDestLength); 
};

// UTF-16 little endian
class nsUTF16LEToUnicode : public nsUTF16ToUnicodeBase
{
public:

  NS_IMETHOD Convert(const char * aSrc, int32_t * aSrcLength,
      PRUnichar * aDest, int32_t * aDestLength); 
};

// UTF-16 with BOM
class nsUTF16ToUnicode : public nsUTF16ToUnicodeBase
{
public:

  nsUTF16ToUnicode() { Reset();}
  NS_IMETHOD Convert(const char * aSrc, int32_t * aSrcLength,
      PRUnichar * aDest, int32_t * aDestLength); 

  NS_IMETHOD Reset();

private:

  enum Endian {kUnknown, kBigEndian, kLittleEndian};
  Endian  mEndian; 
  bool    mFoundBOM;
};

#endif /* nsUCS2BEToUnicode_h___ */
