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
  int q = 10;
  while (((int)((std::abs(frac) - std::abs((int)frac)) * q) -
          ((std::abs(frac) - std::abs((int)frac)) * q)) != 0) {
    q *= 10;
  }
  numerator = (std::abs(frac) - std::abs((int)frac)) * q;
  denominator = q;
  FullPiece = (int)frac;
  Unturned = new char[1];
}
Drob::Drob(int full){
  numerator = full;
  denominator = 1;
  FullPiece = 0;
  Unturned = new char[1];
}

Drob::Drob(const char *unturn) {
  numerator = 0;
  denominator = 1;
  FullPiece = 0;
  Unturned = new char[std::strlen(unturn) + 1];
  std::strcpy(Unturned, unturn);
  ChangeDrob();
}

Drob::Drob(Drob &alpha) {
  numerator = alpha.numerator;
  denominator = alpha.denominator;
  Unturned = new char[std::strlen(alpha.Unturned) + 1];
  std::strcpy(Unturned, alpha.Unturned);
  FullPiece = alpha.FullPiece;
}

int Drob::GetNumerator() { return numerator; }

int Drob::GetDenominator() { return denominator; }

int Drob::GetFull() { return FullPiece; }

bool Drob::GetFlag() { return errorFlag; }

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
  if (Unturned[schet - 1] == ',') {
    int q = 1;
    for (int i = std::strlen(Unturned) - 1; i > schet - 1; --i) {
      tempNum += convert(Unturned, i) * q;
      q *= 10;
    }
    tempDen = q;
  } else {
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
  }
  while (tempNum >= tempDen) {
    tempNum -= tempDen;
    FullPiece += 1;
  }
  if ( FullPiece != 0) {
    FullPiece *= MinusCheck;
    numerator = tempNum;
    denominator = tempDen;
  } else {
    numerator = tempNum * MinusCheck;
    denominator = tempDen;
  }
}

void Drob::ConvertDrob() {
  int Minus = 1;
  if (numerator < 0) {
    Minus *= -1;
    numerator *= -1;
  }
  while (numerator >= denominator && FullPiece>=0) {
    FullPiece = FullPiece + 1;
    numerator = numerator - denominator;
  }
  while(numerator >= denominator && FullPiece<0) {
    FullPiece = FullPiece - 1;
    numerator = numerator - denominator;
  }
  for (int i = 2; i < std::sqrt(denominator); ++i) {
    while (numerator % i == 0 && denominator % i == 0) {
      numerator /= i;
      denominator /= i;
    }
  }
  numerator *= Minus;
  if ((FullPiece != 0 && numerator < 0) || FullPiece != 0 && numerator == 0 && Minus <0) {
    FullPiece *= Minus;
    numerator *= Minus;
  }
}

Drob &Drob::operator=(const Drob &alpha) {
  numerator = alpha.numerator;
  denominator = alpha.denominator;
  FullPiece = alpha.FullPiece;
  delete[] Unturned;
  Unturned = new char[std::strlen(alpha.Unturned) + 1];
  std::strcpy(Unturned, alpha.Unturned);
  return *this;
}

Drob &operator+=(Drob &alpha, Drob &betta) {
  if (alpha.FullPiece == 0 and betta.FullPiece == 0) {
    if (alpha.denominator != betta.denominator) {
      alpha.numerator = alpha.numerator * betta.denominator +
                        betta.numerator * alpha.denominator;
      alpha.denominator *= betta.denominator;
    } else {
      alpha.numerator += betta.numerator;
    }
  } else if (alpha.numerator != 0 && betta.numerator != 0) {
    alpha.numerator = (alpha.numerator + std::abs(alpha.FullPiece) * alpha.denominator)*(alpha.FullPiece/ std::abs(alpha.FullPiece));
    betta.numerator = (betta.numerator + std::abs(betta.FullPiece) * betta.denominator)*(betta.FullPiece/ std::abs(betta.FullPiece));
    alpha.FullPiece = 0;
    if (alpha.denominator != betta.denominator) {
      alpha.numerator = alpha.numerator * betta.denominator +
                        betta.numerator * alpha.denominator;
      alpha.denominator = alpha.denominator * betta.denominator;
    } else {
      alpha.numerator = alpha.numerator + betta.numerator;
    }
  } else {
    if (alpha.numerator == 0) {
      alpha.FullPiece += betta.FullPiece;
      alpha.numerator = betta.numerator;
      alpha.denominator = betta.denominator;
    } else {
      if(betta.FullPiece>=0) {
        alpha.FullPiece += betta.FullPiece;
      } else {
        alpha.FullPiece-=betta.FullPiece;
      }
    }
  }
  while (alpha.numerator >= alpha.denominator) {
    alpha.FullPiece = alpha.FullPiece + 1;
    alpha.numerator = alpha.numerator - alpha.denominator;
  }
  return alpha;
}

Drob &operator+(Drob alpha, Drob betta) { return alpha += betta; }

Drob &operator-=(Drob &alpha, double betta) {
  int FullTemp = -(int)betta;
  int NumTemp = 0;
  int q = 1;
  while ((((int)((std::abs(betta) - std::abs((int)betta)) * q)) -
          ((std::abs(betta) - std::abs((int)betta)) * q)) != 0) {
    q *= 10;
  }
  int DenTemp = q;
  NumTemp = (std::abs(betta) - (int)std::abs(betta)) * q;
  if (alpha.FullPiece * betta <= 0) {
    if (alpha.denominator != DenTemp) {
      alpha.numerator = (alpha.numerator * DenTemp + std::abs(alpha.denominator*DenTemp*alpha.FullPiece)) - (NumTemp * alpha.denominator + std::abs(alpha.denominator*DenTemp*FullTemp));
      alpha.denominator = alpha.denominator * DenTemp;
      if( alpha.FullPiece<0) {
        alpha.numerator*=-1;
      }
      alpha.FullPiece = 0;
      alpha.ConvertDrob();
    } else {
      alpha.numerator = alpha.numerator - (NumTemp+ DenTemp*FullTemp);
    }
  } else {
    FullTemp*=-1;
    if (alpha.denominator != DenTemp) {
      alpha.numerator = alpha.numerator * DenTemp + NumTemp * alpha.denominator;
      alpha.denominator = alpha.denominator * DenTemp;
      alpha.FullPiece += FullTemp;
    } else {
      alpha.numerator = alpha.numerator + NumTemp;
      alpha.FullPiece += FullTemp;
    }
  }
  return alpha;
}

Drob &operator+=(Drob &alpha, double betta) {
  if (betta < 0 || alpha.FullPiece < 0) {
    alpha -= betta;
    return alpha;
  }
  int MinusCheck = 1;
  int FullTemp = (int)betta;
  if (betta < 0) {
    MinusCheck *= -1;
  }
  int NumTemp = 0;
  int q = 1;
  while ((((int)((std::abs(betta) - std::abs((int)betta)) * q)) -
          ((std::abs(betta) - std::abs((int)betta)) * q)) != 0) {
    q *= 10;
  }
  int DenTemp = q;
  NumTemp = (std::abs(betta) - (int)std::abs(betta)) * q;
  if (alpha.denominator != DenTemp) {
    alpha.numerator =
        std::abs(alpha.numerator * DenTemp + (NumTemp * alpha.denominator));
    alpha.denominator = alpha.denominator * DenTemp;
    if (alpha.FullPiece == 0) {
      alpha.numerator *= MinusCheck;
    }
    alpha.FullPiece += std::abs((int)betta);
  } else {
    alpha.numerator = std::abs(alpha.numerator + NumTemp);
    if (alpha.FullPiece == 0) {
      alpha.numerator *= MinusCheck;
    }
    alpha.FullPiece += (int)betta;
  }
  return alpha;
}

Drob &operator+(Drob alpha, double betta) { return alpha += betta; }

Drob &operator+=(double betta, Drob &alpha) {
  std::cout << "endl" << std::endl;
  if (alpha.FullPiece * betta < 0) {
    alpha -= betta;
    return alpha;
  }
  int MinusCheck = 1;
  int FullTemp = (int)betta;
  if (betta < 0) {
    MinusCheck *= -1;
  }
  int NumTemp = 0;
  int q = 1;
  while ((((int)((std::abs(betta) - std::abs((int)betta)) * q)) -
          ((std::abs(betta) - std::abs((int)betta)) * q)) != 0) {
    q *= 10;
  }
  int DenTemp = q;
  NumTemp = (std::abs(betta) - (int)std::abs(betta)) * q * MinusCheck;
  if (alpha.denominator != DenTemp) {
    alpha.numerator = alpha.numerator * DenTemp + NumTemp * alpha.denominator;
    alpha.denominator = alpha.denominator * DenTemp;
    if (alpha.FullPiece == 0) {
      alpha.numerator *= MinusCheck;
    }
    alpha.FullPiece += std::abs((int)betta);
  } else {
    alpha.numerator = alpha.numerator + NumTemp;
    if (alpha.FullPiece == 0) {
      alpha.numerator *= MinusCheck;
    }
    alpha.FullPiece += (int)betta;
  }
  while (alpha.numerator >= alpha.denominator) {
    alpha.FullPiece = alpha.FullPiece + 1;
    alpha.numerator = alpha.numerator - alpha.denominator;
  }
  return alpha;
}

Drob &operator+(double betta, Drob alpha) { return alpha += betta; }

std::ostream &operator<<(std::ostream &out, Drob &alpha) {
  alpha.ConvertDrob();
  if (alpha.FullPiece == 0 && alpha.numerator != 0) {
    std::cout << alpha.numerator << '/' << alpha.denominator;
  } else if (alpha.numerator != 0) {
    std::cout << alpha.FullPiece << " " << alpha.numerator << '/'
              << alpha.denominator;
  } else {
    std::cout << alpha.FullPiece;
  }
  return out;
}
std::istream &operator>>(std::istream &in, Drob &alpha) {
  char betta[100];
  in.ignore();
  in.getline(betta, 100);
  int i = 0;
  bool Flag = false;
  for(int i=0; i<strlen(betta);++i) {
    if(betta[i] =='/' || betta[i] == ',') {
      Flag =true;
    }
  }
  if(!Flag && (atoi(betta)!= 0 || (betta[0]=='0' && !betta[1])) && atoi(betta)!=-1 && strlen(betta) < 10) {
    std::cout<<atoi(betta);
    alpha.FullPiece = atoi(betta);
    return in;
  }
  Flag = false;
  while(!isspace(betta[i])) {
    if(betta[i] != '0' && betta[i] != '-') {
      Flag = true;
    }
    i++;
  }
  if(Flag) {
    if (atof(betta) == 0 && ((betta[0] != '0' && betta[1] != '/') && (betta[0] != '-' && betta[1] != 0 && betta[2]!= '/'))) {
      alpha.errorFlag = true;
      std::cout << "Введены некорректные данные" << std::endl;
      return in;
    }
  }
  bool SlashCheck = true;
  for(int i = 0; i<strlen(betta);++i) {
    if ((betta[i] == '/' || betta[i] ==',') && betta[i+1]) {
      SlashCheck = false;
    }
    if(i>0 && betta[i-1] == '/' && betta[i] == '0' && !betta[i+1]) {
      SlashCheck = true;
    }
  }
  if (SlashCheck) {
    std::cout << "Введены некорректные данные" <<std::endl;
    alpha.errorFlag = true;
    return in;
  }
  int schet = 0;
  for(int i=0; i<strlen(betta);++i) {
    if(betta[i] = '/' || betta[i] == ',') {
      schet = i+1;
      break;
    }
  }
  if(strlen(betta)-schet > 10) {
    std::cout << "Введены некорректные данные" <<std::endl;
    alpha.errorFlag = true;
    return in;
  }
  alpha.SetUnturned(betta);
  alpha.ChangeDrob();
  return in;
}
