//===-- tsan_symbolize.h ----------------------------------------*- C++ -*-===//
//
//                     The LLVM Compiler Infrastructure
//
// This file is distributed under the University of Illinois Open Source
// License. See LICENSE.TXT for details.
//
//===----------------------------------------------------------------------===//
//
// This file is a part of ThreadSanitizer (TSan), a race detector.
//
//===----------------------------------------------------------------------===//
#ifndef TSAN_SYMBOLIZE_H
#define TSAN_SYMBOLIZE_H

#include "tsan_defs.h"
#include "tsan_report.h"

namespace __tsan {

void EnterSymbolizer();
void ExitSymbolizer();
SymbolizedStack *SymbolizeCode(uptr addr);
ReportLocation *SymbolizeData(uptr addr);
void SymbolizeFlush();

ReportStack *NewReportStackEntry(uptr addr);

SANITIZER_INTERFACE_ATTRIBUTE void SetTsanSymbolizeCallback(bool (*callback)(uptr pc, char *func_buf, uptr func_siz,
                               char *file_buf, uptr file_siz, int *line,
                               int *col));

}  // namespace __tsan

#endif  // TSAN_SYMBOLIZE_H
