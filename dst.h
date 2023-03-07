/*
 * vim:et:sw=2:syntax=cpp
 *
 * Copyright (c) 2023 Nikita (sh1r4s3) Ermakov <sh1r4s3@mail.si-head.nl>
 * SPDX-License-Identifier: MIT
 */
#ifndef BOOPA_DOOPA
#define BOOPA_DOOPA

#include <iostream>
#include <memory>
#include <TChain.h>
#include <TFile.h>
#include <TClonesArray.h>

class teletubbies: public TObject {
  ClassDef(teletubbies, 666);
  int mTinkyWinky {0xdead};
  int mDipsy {1982};
  int mLaaLaa {0xbeef};
  int mPo {0xfeed};
  public:
    int tinkyWinky() { return mTinkyWinky; }
    int dipsy() { return mDipsy; }
    int laaLaa() { return mLaaLaa; }
    int po() { return mPo; }
};

class dst {
  public:
    enum class IO {
      read,
      write
    };

    dst(const std::string path, IO io);
    ~dst();
    void generate();
  private:
    std::unique_ptr<TFile> mFile;
    std::unique_ptr<TTree> mTree;
    TClonesArray *mEvents {nullptr};
    IO mIO;
    int mN {0};
};

#endif
