/* -*- Mode: C++; tab-width: 2; indent-tabs-mode: nil; c-basic-offset: 2 -*-
 *
 * The contents of this file are subject to the Netscape Public
 * License Version 1.1 (the "License"); you may not use this file
 * except in compliance with the License. You may obtain a copy of
 * the License at http://www.mozilla.org/NPL/
 *
 * Software distributed under the License is distributed on an "AS
 * IS" basis, WITHOUT WARRANTY OF ANY KIND, either express or
 * implied. See the License for the specific language governing
 * rights and limitations under the License.
 *
 * The Original Code is mozilla.org code.
 *
 * The Initial Developer of the Original Code is Netscape
 * Communications Corporation.  Portions created by Netscape are
 * Copyright (C) 1998 Netscape Communications Corporation. All
 * Rights Reserved.
 *
 * Contributor(s): 
 *   Roger B. Sidje <rbs@maths.uq.edu.au>
 *
 * This Original Code has been modified by Roger B. Sidje.
 * Modifications made by Roger B. Sidje described herein are
 * Copyright (C) 2000 The University Of Queensland.
 *
 * Modifications to Mozilla code or documentation
 * identified per MPL Section 3.3
 *
 * Date            Modified by     Description of modification
 * 08/March/2000   RBS.            Support for Mathematical fonts.
 */

#include "nsUnicodeToTeXCMSYt1.h"

//----------------------------------------------------------------------
// Global functions and data [declaration]

static PRUint16 g_ufMappingTable[] = {
#include "texcmsy-t1.uf"
};

static PRInt16 g_ufShiftTable[] =  {
  0, u1ByteCharset ,
  ShiftCell(0,0,0,0,0,0,0,0)
};

//----------------------------------------------------------------------
// Class nsUnicodeToTeXCMSYt1 [implementation]

nsUnicodeToTeXCMSYt1::nsUnicodeToTeXCMSYt1() 
: nsTableEncoderSupport((uShiftTable*) &g_ufShiftTable, 
                        (uMappingTable*) &g_ufMappingTable)
{
}

nsresult nsUnicodeToTeXCMSYt1::CreateInstance(nsISupports ** aResult) 
{
  *aResult = (nsIUnicodeEncoder*) new nsUnicodeToTeXCMSYt1();
  return (*aResult == NULL)? NS_ERROR_OUT_OF_MEMORY : NS_OK;
}

//----------------------------------------------------------------------
// Subclassing of nsTableEncoderSupport class [implementation]

NS_IMETHODIMP nsUnicodeToTeXCMSYt1::GetMaxLength(const PRUnichar * aSrc, 
                                              PRInt32 aSrcLength,
                                              PRInt32 * aDestLength)
{
  *aDestLength = aSrcLength;
  return NS_OK_UENC_EXACTLENGTH;
}
