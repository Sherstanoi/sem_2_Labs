#include "Lab_3.hpp"

Drob::Drob() {
  numerator = 0;
  denominator = 1;
  FullPiece = 0;
  Unturned = new char[1];
}
Drob::Drob(int num, int den) {
  numerator = num;
  denominator = den;
  FullPiece = 0;
  Unturned = new char[1];
}
Drob::Drob(double frac) {
  numerator = 0;
  denominator = 1;
  FullPiece = frac;
  Unturned = new char[1];
}

Drob::Drob(const char *unturn) {
  numerator = 0;
  denominator = 1;
  FullPiece = 0;
  Unturned = new char[std::strlen(unturn)+1];
  std::strcpy(Unturned, unturn);
}

Drob::Drob(Drob& alpha) {
  numerator = alpha.numerator;
  denominator = alpha.denominator;
  Unturned = new char[std::strlen(alpha.Unturned)+1];
  std::strcpy(Unturned,alpha.Unturned);
  FullPiece = alpha.FullPiece;
}

int Drob::GetNumerator() {
  return numerator;
}

int Drob::GetDenominator() {
  return denominator;
}

int Drob::GetFull() {
  return FullPiece;
}

void Drob::SetNumerator(int newNum) {
  numerator = newNum;
  return;
}

void Drob::SetDenominator(int NewDen) {
  denominator = NewDen;
  return;
}

void Drob::SetFull(int NewFull) {
  FullPiece = NewFull;
  return;
}

void Drob::SetUnturned(const char *betta) {
  delete[] Unturned;
  Unturned = new char[std::strlen(betta)];
  strcpy(Unturned, betta);
}
void Drob::SetDrob(int num, int den) {}

int convert(char *alpha, int mesto) {
  char chisla[9] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
  char bukvi[9] = {'1', '2', '3', '4', '5', '6', '7', '8', '9'};
  for (int i = 0; i < 9; ++i) {
    if (alpha[mesto] == bukvi[i]) {
      return chisla[i];
    }
  }
  return 0;
}

void Drob::ChangeDrob() {
  int tempNum = 0;
  int tempDen = 0;
  bool Flag = true;
  bool Flag1 = true;
  int schet = 0;
  int schetVnutri = 0;
  int MinusCheck = 1;
  if (Unturned[0] == '-') {
    MinusCheck = -1;
    schet += 1;
    schetVnutri += 1;
  }
  for (int i = 0; i < strlen(Unturned); ++i) {
    const char a = ' ';
    if (isspace(Unturned[i]) or Unturned[i] == ',') {
      schet = i + 1;
      while (Flag1) {
        FullPiece = FullPiece * 10 + convert(Unturned, schetVnutri);
        schetVnutri += 1;
        if (isspace(Unturned[schetVnutri]) or Unturned[schetVnutri] == ',') {
          Flag1 = false;
        }
      }
      break;
    }
  }
  while (Flag) {
    if (Unturned[schet] != '/') {
      tempNum = tempNum * 10 + convert(Unturned, schet);
      ++schet;
    } else {
      Flag = false;
    }
  }
  Flag = true;
  schet = std::strlen(Unturned) - 1;
  int q = 1;
  while (Flag) {
    if (Unturned[schet] != '/') {
      tempDen = tempDen + convert(Unturned, schet) * q;
      --schet;
    } else {
      Flag = false;
    }
    q *= 10;
  }
  while (tempNum >= tempDen) {
    tempNum -= tempDen;
    FullPiece += 1;
  }
  numerator = tempNum * MinusCheck;
  denominator = tempDen;
}

Drob &Drob::operator=(const Drob &alpha) {
    numerator = alpha.numerator;
    denominator = alpha.denominator;
    FullPiece = alpha.FullPiece;
    delete[] Unturned;
    Unturned = new char[std::strlen(alpha.Unturned)+1];
    std::strcpy(Unturned,alpha.Unturned);
    return *this;
}

Drob& operator+=(Drob& alpha, Drob& betta) {
    if(alpha.FullPiece == 0 and betta.FullPiece == 0) {
        if (alpha.denominator != betta.denominator) {
            alpha.numerator = alpha.numerator * betta.denominator + betta.numerator * alpha.denominator;
            alpha.denominator *= betta.denominator;
        } else{
            alpha.numerator += betta.numerator;
        }
    } else if(alpha.numerator != 0 && betta.numerator != 0){
        alpha.numerator = alpha.numerator + alpha.FullPiece * alpha.denominator;
        betta.numerator = betta.numerator + betta.FullPiece * betta.denominator;
        if (alpha.denominator != betta.denominator) {
            alpha.numerator = alpha.numerator * betta.denominator + betta.numerator * alpha.denominator;
            alpha.denominator = alpha.denominator * betta.denominator;
        } else{
            alpha.numerator = alpha.numerator + betta.numerator;
        }
    } else {
      if(alpha.numerator == 0) {
        alpha.FullPiece += betta.FullPiece;
        alpha.numerator = betta.numerator;
        alpha.denominator = betta.denominator;
      } else {
        alpha.FullPiece += betta.FullPiece;
      }
    }
    while(alpha.numerator >= alpha.denominator) {
        alpha.FullPiece = alpha.FullPiece + 1;
        alpha.numerator = alpha.numerator - alpha.denominator;
    }
  return alpha;
}

Drob &operator+(Drob alpha, Drob betta) {
    return alpha+=betta;
}

Drob &operator+=(Drob &alpha, double betta) {
  int FullTemp = (int)betta;
  int DenTemp = 100;
  int NumTemp = 0;
  int q = 1;
  while(NumTemp != (betta- (int)betta)) {
    NumTemp = (betta- (int)betta)*q;
  }
  if (alpha.denominator != DenTemp) {
    alpha.numerator = alpha.numerator * DenTemp + NumTemp * alpha.denominator;
    alpha.denominator = alpha.denominator * DenTemp;
} else{
    alpha.numerator = alpha.numerator + NumTemp;
}
  return alpha;
}

Drob &operator+(Drob alpha, double betta) {
    return alpha+=betta;
}

Drob &operator+=(double betta, Drob &alpha) {
  int FullTemp = (int)betta;
  int DenTemp = 100;
  int NumTemp = 0;
  int q = 1;
  while(NumTemp != (betta- (int)betta)) {
    NumTemp = (betta- (int)betta)*q;
  }
  if (alpha.denominator != DenTemp) {
    alpha.numerator = alpha.numerator * DenTemp + NumTemp * alpha.denominator;
    alpha.denominator = alpha.denominator * DenTemp;
} else{
    alpha.numerator = alpha.numerator + NumTemp;
}
  return alpha;
    return alpha;
}

Drob &operator+(double betta, Drob alpha) {
    return alpha+=betta;
}

std::ostream &operator<<(std::ostream &out, const Drob &alpha) {
  if (alpha.FullPiece == 0 && alpha.numerator != 0) {
    std::cout << alpha.numerator << '/' << alpha.denominator;
  } else if(alpha.numerator != 0){
    std::cout << alpha.FullPiece << " " << alpha.numerator << '/'
              << alpha.denominator;
  } else {
    std::cout<<alpha.FullPiece;
  }
  return out;
}
std::istream &operator>>(std::istream &in, Drob &alpha) {
  char betta[100];
  in.ignore();
  in.getline(betta, 100);
  alpha.SetUnturned(betta);
  alpha.ChangeDrob();
  return in;
}

void ChangeDrob() {}
