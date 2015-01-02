// Copyright 2012-2014 UX Productivity Pty Ltd
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
// http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

#ifndef DocFormats_DFPlatform_h
#define DocFormats_DFPlatform_h

#include <stddef.h>

typedef struct DFDirEntryList DFDirEntryList;

struct DFDirEntryList {
    char *name;
    DFDirEntryList *next;
};

int DFMkdirIfAbsent(const char *path, char **errmsg);
int DFAddDirContents(const char *absPath, const char *relPath, int recursive, DFDirEntryList ***list, char **errmsg);
int DFGetImageDimensions(const void *data, size_t len, const char *ext,
                         unsigned int *width, unsigned int *height, char **errmsg);

#define DF_ONCE_INIT 0
typedef int DFOnce;
typedef void (*DFOnceFunction)(void);
void DFInitOnce(DFOnce *once, DFOnceFunction fun);

// Zip functions
typedef struct {
        void *handle;
        int   zipFlag;
        int   zipFirst;
        } DFextZipHandle;
typedef DFextZipHandle * DFextZipHandleP;

DFextZipHandleP DFextZipOpen(const char *zipFilename, int doUnzip);
int             DFextZipClose(DFextZipHandleP zipHandle);

int             DFextZipOpenNextFile(DFextZipHandleP zipHandle, char *entryName, const int maxName);
int             DFextZipAppendNewFile(DFextZipHandleP zipHandle, const char *entryName);
int             DFextZipCloseFile(DFextZipHandleP zipHandle);

int DFextZipReadCurrentFile(DFextZipHandleP zipHandle, char *buf, const int maxLen);
int DFextZipWriteCurrentFile(DFextZipHandleP zipHandle, char *buf, const int len);
#endif
