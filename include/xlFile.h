#ifndef _XL_FILE_H
#define _XL_FILE_H

#include "dolphin.h"
#include "xlFileGCN.h"

typedef enum XlFileTokenType {
    XLFTT_NONE = -1,
    XLFTT_LABEL = 0,
    XLFTT_NUMBER = 1,
    XLFTT_STRING = 2,
    XLFTT_SYMBOL = 3,
    XLFTT_LAST_ = 4,
} XlFileTokenType;

#if VERSION == 3 // PZLP01
s32 xlFileGetSize(s32* pnSize, char* szFileName);
#endif

s32 xlFileGetLine(tXL_FILE* pFile, char* acLine, s32 nSizeLine);
s32 xlTokenGetInteger(char* acToken, s32* pnValue);
s32 xlFileSkipLine(tXL_FILE* pFile);
s32 xlFileGetToken(tXL_FILE* pFile, XlFileTokenType* peType, char* acToken, s32 nSizeToken);
s32 xlFileMatchToken(tXL_FILE* pFile, XlFileTokenType eType, char* acToken, s32 nSizeToken, char* szText);
s32 xlFileGetLineSave(tXL_FILE* pFile, tXL_SAVE* pSave);

#endif
